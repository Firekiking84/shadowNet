#include			"networkUDP.hh"

#include			<stdio.h>
#include			<iostream>

ssize_t				ef::NetworkUDP::recvPacket(int				fd,
							   struct sockaddr_in	&	addr,
							   Packet		&	data)
{
  ssize_t			sizeRcv;
  socklen_t			addrlen;

  sizeRcv = 0;
  addrlen = sizeof(addr);
  sizeRcv = recvfrom(fd, &data, sizeof(data), 0, reinterpret_cast<struct sockaddr *>(&addr), &addrlen);
  if (sizeRcv == -1)
    {
      std::cerr << "Erreur de Recvfrom" << std::endl;
      perror("Erreur : ");
      return(-1);
    }
  return(sizeRcv);
}
