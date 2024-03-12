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

void			ef::FileRequestManager::manageDownload(s_download const	&	download,
							       contact const	&	pair)
{
  if (pendingDLRequest.find(download.request.hashFile) != pendingDLRequest.end())
    {
      size_t		i;

      addLog("Transfering data to pair researching it !");
      for (i = 0; i < pendingDLRequest[download.request.hashFile].size(); i += 1)
	{
	  if (download.request.nPart <= pendingDLRequest[download.request.hashFile][i].lastPart && // à voir pour le =
	      download.request.nPart >= pendingDLRequest[download.request.hashFile][i].request.nPart)
	    {
	      Packet  data;

	      data.download = download;
	      sendPacket(data, pendingDLRequest[download.request.hashFile][i].pair);
	      pendingDLRequest[download.request.hashFile][i].time = (size_t)time(NULL);
	    }
	}
    }
  else if (currentDownload.find(download.request.hashFile) != currentDownload.end())
    {
      std::string	status;

      currentDownload[download.request.hashFile].status.seek(download.request.nPart, FileManager::SeekFlags::BEG);
      currentDownload[download.request.hashFile].status.read(status, 1);
      if (status[download.request.nPart] == '0')
	{
	  addLog("Writing new data recieved !");
	  currentDownload[download.request.hashFile].file.seek(2048 * download.request.nPart, FileManager::SeekFlags::BEG);
	  currentDownload[download.request.hashFile].file.write((char *)download.part, download.sizePart);
	  currentDownload[download.request.hashFile].status.seek(download.request.nPart, FileManager::SeekFlags::BEG);
	  currentDownload[download.request.hashFile].status.write("1", 1);
	  currentDownload[download.request.hashFile].lastUpdate = (size_t)time(NULL);
	}
      if (getStatus(download.request.hashFile) != 100)
	return;
      std::filesystem::path	statusFile(currentDownload[download.request.hashFile].file.getFilename());
      currentDownload.erase(download.request.hashFile);
      std::filesystem::remove(statusFile);
      addLog("A downloading has been successfully completed");
    }
}