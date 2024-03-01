#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include		"networkUDP.hh"

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   contact const		&	pair)
{
  if (can(Mode::WRITE, pfd[EXTERNAL].fd))
    {
      if (data.type == FIND_REQUEST)
	{
	  sendto(pfd[EXTERNAL].fd, &data.findRequest, sizeof(data.findRequest), 0,
		 &pair.sAddr, sizeof(pair.sAddr));
	}
      else if (data.type == FIND_ANSWER)
	{
	  sendto(pfd[EXTERNAL].fd, &data.findAnswer, sizeof(data.findAnswer), 0,
		 &pair.sAddr, sizeof(pair.sAddr));
	}
      else if (data.type == DL_REQUEST)
	{
	  sendto(pfd[EXTERNAL].fd, &data.dlRequest, sizeof(data.dlRequest), 0,
		 &pair.sAddr, sizeof(pair.sAddr));
	}
      else if (data.type == DL_FILE)
	{
	  sendto(pfd[EXTERNAL].fd, &data.download, sizeof(data.download), 0,
		 &pair.sAddr, sizeof(pair.sAddr));
	}
      else if (data.type == PING || data.type == PONG)
	{
	  sendto(pfd[EXTERNAL].fd, &data.type, sizeof(data.type), 0,
		 &pair.sAddr, sizeof(pair.sAddr));
	}
    }
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::map<std::string, contact> const	&	contactList)
{
  std::map<std::string, contact>::const_iterator	it;

  for (it = contactList.begin(); it != contactList.end(); ++it)
      sendPacket(data, it->second);
}
