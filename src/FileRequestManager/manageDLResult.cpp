// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:11:13 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::manageDLResult(s_download const	&	download,
							       contact const	&	pair)
{
  if (pendingDLRequest.find(download.request.hashFile) != pendingDLRequest.end())
    {
      size_t		i;

      for (i = 0; i < pendingDLRequest[download.request.hashFile].size(); i += 1)
	{
	  if (download.request.nPart <= pendingDLRequest[download.request.hashFile][i].lastPart && // à voir pour le =
	      download.request.nPart >= pendingDLRequest[download.request.hashFile][i].request.nPart)
	    {
	      Packet  data;

	      data.download = download;
	      sendPaket(data, pendingDLRequest[download.request.hashFile][i].pair);
	      pendingDLRequest[download.request.hashFile][i].time = reinterpret_cast<size_t>(time(NULL));
	    }
	}
    }
  else if (currentDownload.find(download.request.hashFile) != currentDownload.end())
    {
      currentDownload[download.request.hashFile].file.seek(2048 * download.request.nPart, FileManager::SeekFlags::BEG);
      currentDownload[download.request.hashFile].file.write(download.part, download.sizePart);
      currentDownload[download.request.hashFile].file.seek(download.request.nPart, FileManager::SeekFlags::BEG);
      currentDownload[download.request.hashFile].file.write("1", 1);
      currentDownload[download.request.hashFile].lastUpdate = reinterpret_cast<size_t>(time(NULL));
      if (getStatus(download.request.hashFile) != 100)
	return;
      std::filesystem::path	statusFile(currentDownload[download.request.hashFile].file.getFilename);
      currentDownload.erase(download.request.hashFile);
      std::filesystem::remove(statusFile);
      // log and tell user end of download
    }
}
