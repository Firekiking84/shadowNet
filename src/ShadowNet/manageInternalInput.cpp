// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:29 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

void			ef::ShadowNet::manageInternalInput()
{
  std::string		buffer;
  size_t		sizeBuffer;
  struct ::sockaddr_in	addr;

  sizeBuffer = 50;
  buffer.resize(sizeBuffer);
  recvFromFd(pfd[INTERNAL].fd, addr, buffer, sizeBuffer);
  user.ip = inet_ntoa(addr.sin_addr);
  user.port = ntohs(addr.sin_port);
  user.addr = addr;
  user.sAddr = *(reinterpret_cast<struct ::sockaddr *>(&user.addr));
  if (buffer.compare(0, 4, "quit") == 0 || buffer.compare(0, 4, "exit") == 0)
    isRunning = false;
  else if (buffer.compare(0, 9, "addfriend") == 0) // 9 = strlen("addfriend")
    cmdAddfriend(buffer);
  else if (buffer.compare(0, 12, "removefriend") == 0) // 12 = strlen("removefriend")
    cmdRemovefriend(buffer);
  else if (buffer.compare(0, 11, "requestfile") == 0) // 11 = strlen("requestfile")
    cmdRequestfile(buffer);
  else if (buffer.compare(0, 10, "forgetfile") == 0) // 10 = strlen("forgetfile")
    cmdForgetfile(buffer);
  else if (buffer.compare(0, 8, "download") == 0) // 8 = strlen("download")
    cmdDownloadFilename(buffer);
  else if (buffer.compare(0, 6, "status") == 0) // 6 = strlen("status")
    cmdStatus(buffer);
  else if (buffer.compare(0, 4, "logs") == 0) // 4 = strlen("logs")
    sendLogs();
  else if (buffer.compare(0, 4, "ping") == 0) // 4 = strlen("ping")
    pingPairs();
  else if (buffer.compare(0, 5, "check") == 0) // 5 = strlen("check")
    sendUser("Connected !");
  else
    sendAvailableCMD();
}
