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
    {
      contact		stranger;
      std::string       msgUser;

      sendUser("Adding Pair...");
      getParameters(buffer, stranger.label, stranger.ip, stranger.port);
      addPair(stranger);
    }
  else if (buffer.compare(0, 12, "removefriend") == 0) // 12 = strlen("removefriend")
    {
      std::string	label;

      sendUser("Removing Pair...");
      getParameters(buffer, label);
      removePair(label);
    }
  else if (buffer.compare(0, 11, "requestfile") == 0) // 11 = strlen("requestfile")
    {
      std::string	filename;
      std::string	msgUser;

      getParameters(buffer, filename);
      msgUser = "Send request of the file '" + filename + "' on your network";
      sendUser(msgUser);
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
      std::string	destName;

      getParameters(buffer, filename, destName);
      sendDownloadRequest(filename, destName);
    }
  else if (buffer.compare(0, 6, "status") == 0) // 6 = strlen("status")
    {
      std::string	filename;

      getParameters(buffer, filename);
      getStatus(filename);
    }
  else if (buffer.compare(0, 4, "logs") == 0) // 4 = strlen("logs")
    sendUser(getLog());
  else if (buffer.compare(0, 4, "ping") == 0) // 4 = strlen("ping")
    {
      Packet		newPacket;
      std::string	userMsg;

      newPacket.type = PING;
      userMsg = "Ping to your " + std::to_string(pairs.size()) + " pair(s)";
      sendUser(userMsg);
      sendPacket(newPacket, pairs);
    }
}
