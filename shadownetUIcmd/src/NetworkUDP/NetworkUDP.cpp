// EFRITS
// project:     Talk
// created on:  07/11/2023 13:41:39
// 1st author:  keryan.houssin - keryan.houssin@gagarine.efrits.fr
// description: Constructor and destructor of the class NetworkUDP

#include		"networkUDP.hh"

#include		<unistd.h>
#include		<iostream>

ef::NetworkUDP::NetworkUDP(int			port,
			   std::string const	&ipSoft,
			   int			portSoft)
{
  struct sockaddr_in	sockaddr;
  int			status;

  pfd[0].fd = 0;
  pfd[1].fd = 1;
  pfd[2].fd = socket(AF_INET, SOCK_DGRAM, 0);
  pfd[2].events = POLLIN | POLLOUT;
  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(port);
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  status = bind(pfd[2].fd, reinterpret_cast<struct sockaddr *>(&sockaddr), sizeof(sockaddr));
  if (status == -1)
    throw (std::runtime_error("Bind error"));
  software.ip = ipSoft;
  software.port = portSoft;
  memset(&software.addr, 0, sizeof(software.addr));
  software.addr.sin_family = AF_INET;
  software.addr.sin_port = htons(software.port);
  software.addr.sin_addr.s_addr = inet_addr(software.ip.c_str());
  software.sAddr = *(reinterpret_cast<struct sockaddr *>(&software.addr));
}

ef::NetworkUDP::~NetworkUDP()
{
  close(pfd[2].fd);
}
