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
    transferPacketFile(download, pair);
  if (currentDownload.find(download.request.hashFile) != currentDownload.end())
    proceedDownload(download, pair);
}
