// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 18:11:42 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::proceedDownload(s_download const &	download,
								contact const &	pair)
{
  Bitfield		bitPart(filesFind[download.request.hashFile].nbPart);
  std::string	msg;

  msg = "Receive data part : " + std::to_string(download.request.nPart);
  addLog(msg);
  currentDownload[download.request.hashFile].status.seek(0, FileManager::SeekFlags::BEG);
  bitPart.Unserialize(currentDownload[download.request.hashFile].status.getStream());
  if (download.request.nPart < filesFind[download.request.hashFile].nbPart && bitPart[download.request.nPart] == false)
    {
      addLog("Writing new data recieved !");
      currentDownload[download.request.hashFile].file.seek(2048 * download.request.nPart, FileManager::SeekFlags::BEG);
      currentDownload[download.request.hashFile].file.write((char *)download.part, download.sizePart);
      bitPart[download.request.nPart] = true;
      currentDownload[download.request.hashFile].status.seek(0, FileManager::SeekFlags::BEG);
      bitPart.Serialize(currentDownload[download.request.hashFile].status.getStream());
      currentDownload[download.request.hashFile].lastUpdate = (size_t)time(NULL);
    }
  if (getStatus(download.request.hashFile) != 100)
    return;
  endDownload(download);
}
