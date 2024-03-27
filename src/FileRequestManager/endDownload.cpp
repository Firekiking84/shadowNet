// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 18:14:26 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::endDownload(s_download const	&	download)
{
  std::filesystem::path	statusFile(currentDownload[download.request.hashFile].status.getFilename());

  currentDownload[download.request.hashFile].status.close();
  currentDownload[download.request.hashFile].file.close();
  currentDownload.erase(download.request.hashFile);
  std::filesystem::remove(statusFile);
  addLog("A downloading has been successfully completed");
}
