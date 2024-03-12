// EFRITS
// project:     Talk
// created on:  07/11/2023 13:41:39
// 1st author:  keryan.houssin - keryan.houssin@gagarine.efrits.fr
// description: Constructor and destructor of the class NetworkUDP

#include		"networkUDP.hh"

#include		<unistd.h>
#include		<iostream>

ef::NetworkUDP::NetworkUDP(std::string const	&	_cnf_name)
  : User(_cnf_name)
  , isConnected(false)
{
  struct sockaddr_in	sockaddr;
  int			status;

  pfd[EXTERNAL].fd = socket(AF_INET, SOCK_DGRAM, 0);
  pfd[EXTERNAL].events = POLLIN | POLLOUT;
  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(externalPort);
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  status = bind(pfd[EXTERNAL].fd, reinterpret_cast<struct sockaddr *>(&sockaddr), sizeof(sockaddr));
  if (status == -1)
    throw (std::runtime_error("Bind error"));

  pfd[INTERNAL].fd = socket(AF_INET, SOCK_DGRAM, 0);
  pfd[INTERNAL].events = POLLIN | POLLOUT;
  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(internalPort);
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  status = bind(pfd[INTERNAL].fd, reinterpret_cast<struct sockaddr *>(&sockaddr), sizeof(sockaddr));
  if (status == -1)
    {
      perror("Bind : ");
      throw (std::runtime_error("BindError"));
    }
}

ef::NetworkUDP::~NetworkUDP()
{
  close(pfd[INTERNAL].fd);
  close(pfd[EXTERNAL].fd);
}
