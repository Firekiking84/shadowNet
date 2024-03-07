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
      else if (data.type == DL_REQUEST || data.type == DL_UNIQUE_REQUEST)
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
						   std::map<std::string, contact> const	&	contactList,
						   std::map<std::string, std::string> const	&excludeContact)
{
  std::map<std::string, contact>::const_iterator	it;

  for (it = contactList.begin();
       it != contactList.end() && excludeContact.find(it->second.label) != excludeContact.end();
       ++it)
    {
      sendPacket(data, it->second, excludeList);
    }
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::map<std::string, contact> const	&	contactList,
						   std::map<std::string, std::string> const	&excludeContact)
{
  size_t		i;
  std::map<std::string, std::string>	excludeMap;

  for (i = 0; i < excludeList.size(); i += 1)
    excludeMap[excludeList[i].label] = excludeList[i].label;
  sendPacket(data, contactList, excludeMap);
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::map<std::string, contact> const &	contactList,
						   contact const		&	excludeContact)
{
  std::map<std::string, std::string>	excludeList;

  excludeList[excludeContact.label] = excludeContact.label;
  sendPacket(data, contactList, excludeList);
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::map<std::string, contact> const	&	contactList)
{
  std::map<std::string, std::string>	excludeList;

  sendPacket(data, contactList, excludeList);
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::vector<contact> const	&	contactList,
						   std::map<std::string, std::string> const	&	excludeList)
{
  size_t		i;

  for (i = 0;
       i < contactList.size() && excludeList.find(contactList[i].label) != excludeList.end();
       i += 1)
    {
      sendPacket(data, contactList[i], excludeList);
    }
}


void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::vector<contact> const	&	contactList,
						   std::vector<contact> const	&	excludeList)
{
  size_t		i;
  std::map<std::string, std::string>	excludeMap;

  for (i = 0; i < excludeList.size(); i += 1)
    excludeMap[excludeList[i].label] = excludeList[i].label;
  sendPacket(data, contactList, excludeMap);
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::vector<contact> const	&	contactList,
						   contact const		&	excludeContact)
{
  std::map<std::string, std::string>	excludeList;

  excludeList[excludeContact.label] = excludeContact.label;
  sendPacket(data, contactList, excludeList);
}

void			ef::NetworkUDP::sendPacket(Packet const			&	data,
						   std::vector<contact> const	&	contactList)
{
  std::map<std::string, std::string>	excludeList;

  sendPacket(data, contactList, excludeList);
}
