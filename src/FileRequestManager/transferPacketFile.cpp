// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 18:05:32 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::transferPacketFile(s_download const &	download,
								   contact const &	pair)
{
  size_t		i;
  std::string	msg;

  msg = "Transfering packet n°" + std::to_string(download.request.nPart);
  addLog(msg);
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
