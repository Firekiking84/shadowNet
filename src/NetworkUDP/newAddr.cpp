// EFRITS
// project:     Talk
// created on:  07/11/2023 13:42:49
// 1st author:  keryan.houssin - keryan.houssin@gagarine.efrits.fr
// description: Set the struct addr to _contact

#include		"networkUDP.hh"

#include		<cstring>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>

void			ef::NetworkUDP::newAddr(contact		&	_contact)
{
  memset(&_contact.addr, 0, sizeof(_contact.addr));
  _contact.addr.sin_family = AF_INET;
  _contact.addr.sin_port = htons(_contact.port);
  _contact.addr.sin_addr.s_addr = inet_addr(_contact.ip.c_str());
  _contact.sAddr = *(reinterpret_cast<struct sockaddr *>(&_contact.addr));
}
