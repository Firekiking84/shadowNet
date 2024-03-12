#include		"shadowNet.hh"

void			ef::ShadowNet::manageExternalInput()
{
  struct ::sockaddr_in	addr;
  Packet		data;

  if (recvPacket(pfd[EXTERNAL].fd, addr, data) == -1)
    return;
  contact		pair;
  std::string		newLog;

  pair.ip = inet_ntoa(addr.sin_addr);
  pair.port = ntohs(addr.sin_port);
  if (!isAPair(pair))
    {
      addLog("Message receive by an unknown pair. Rejected !");
      return;
    }
  if (data.type == FIND_REQUEST)
    {
      newLog = "Manage a request of ";
      newLog += ((const char *)data.findRequest.name);
      newLog += " ask by " + pair.label;
      addLog(newLog);
      manageSearchRequest(data.findRequest, pair);
    }
  else if (data.type == FIND_ANSWER)
    {
      newLog = "Manage of search result send by " + pair.label;
      addLog(newLog);
      manageSearchResult(data.findAnswer, pair);
    }
  else if (data.type == DL_REQUEST || data.type == DL_UNIQUE_REQUEST)
    {
      newLog = "Manage download request send by " + pair.label;
      addLog(newLog);
      manageDLRequest(data.dlRequest, pair);
    }
  else if (data.type == DL_FILE)
    {
      newLog = "Manage file transfering send by " + pair.label;
      addLog(newLog);
      manageDownload(data.download, pair);
    }
  else if (data.type == PING)
    {
      Packet		newPacket;

      newLog = pair.label + " has send a ping !";
      addLog(newLog);
      newPacket.type = PONG;
      sendPacket(newPacket, pair);
    }
  else if (data.type == PONG)
    {
      newLog = pair.label + " has answered ping command !";
      addLog(newLog);
    }
}
