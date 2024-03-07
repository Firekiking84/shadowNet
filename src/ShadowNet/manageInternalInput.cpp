#include		"shadowNet.hh"

void			ef::ShadowNet::manageInternalInput()
{
  std::string		buffer;
  size_t		sizeBuffer;
  struct ::sockaddr_in	addr;

  sizeBuffer = 50;
  buffer.resize(sizeBuffer);
  recvFromFd(pfd[INTERNAL].fd, addr, buffer, sizeBuffer);
  if (buffer == "quit" || buffer == "exit")
    isRunning = false;
  else if (buffer.compare(0, 9, "addfriend") == 0) // 9 = strlen("addfriend")
    {
      contact		stranger;

      getParameters(buffer, stranger.label, stranger.ip, stranger.port);
      addPair(stranger);
    }
  else if (buffer.compare(0, 12, "removefriend") == 0) // 12 = strlen("removefriend")
    {
      std::string	label;

      getParameters(buffer, label);
      removePair(label);
    }
  else if (buffer.compare(0, 11, "requestfile") == 0) // 11 = strlen("requestfile")
    {
      std::string	filename;

      getParameters(buffer, filename);
      sendSearchRequest(filename);
    }
  else if (buffer.compare(0, 10, "forgetfile") == 0) // 10 = strlen("forgetfile")
    {
      std::string	filename;

      getParameters(buffer, filename);
      forgetFile(filename);
    }
  else if (buffer.compare(0, 8, "download") == 0) // 8 = strlen("download")
    {
      std::string	filename;

      getParameters(buffer, filename);
      sendDownloadRequest(filename);
    }
  else if (buffer.compare(0, 6, "status") == 0) // 6 = strlen("status")
    {
      std::string	filename;

      getParameters(buffer, filename);
      getStatus(filename);
    }
  else if (buffer.compare(0, 4, "logs") == 0) // 4 = strlen("logs")
    printLog();
  else if (buffer.compare(0, 4, "ping") == 0) // 4 = strlen("ping")
    {
      Packet		newPacket;

      newPacket.type = PING;
      sendPacket(newPacket, pairs);
    }
}
