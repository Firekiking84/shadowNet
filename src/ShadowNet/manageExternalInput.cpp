#include		"shadowNet.hh"

void			ef::ShadowNet::manageExternalInput()
{
  struct ::sockaddr_in	addr;
  Packet		data;

  if (recvPacket(pfd[EXTERNAL].fd, addr, data) == -1)
    return; // log

  contact		pair;

  pair.ip = inet_ntoa(addr.sin_addr);
  pair.port = ntohs(addr.sin_port);
  if (!isAPair(pair))
    return;
  if (data.type == FIND_REQUEST)
    manageSearchRequest(data.findRequest, pair);
  else if (data.type == FIND_ANSWER)
    manageSearchResult(data.findAnswer, pair);
  else if (data.type == DL_REQUEST || data.type == DL_UNIQUE_REQUEST)
    manageDLRequest(data.dlRequest, pair);
  else if (data.type == DL_FILE)
    manageDownload(data.download, pair);
  else if (data.type == PING)
    {
      Packet		newPacket;

      newPacket.type = PONG;
      sendPacket(newPacket, pair);
    }
  else if (data.type == PONG)
    {
      std::string	msg;

      msg = "Your pair " + pair.label + " is connected !";
      sendUser(msg);
    }
}
