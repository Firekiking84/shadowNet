// EFRITS
// project:     Talk
// created on:  07/11/2023 13:46:08
// 1st author:  keryan.houssin - keryan.houssin@gagarine.efrits.fr
// description: Use Recvfrom until there is nothing more to read

#include			"networkUDP.hh"

#include			<stdio.h>
#include			<iostream>

ssize_t				ef::NetworkUDP::recvFromSoft(std::string		&	buffer)
{
  ssize_t			sizeRcv;
  size_t			maxRead;
  socklen_t			addrlen;

  maxRead = 2048;
  buffer.resize(maxRead);
  addrlen = sizeof(software.addr);
  sizeRcv = recvfrom(pfd[2].fd, buffer.data(), maxRead, 0, &software.sAddr, &addrlen);
  if (sizeRcv == -1)
    {
      std::cerr << "Erreur de Recvfrom" << std::endl;
      perror("Erreur : ");
      return(-1);
    }
  return(sizeRcv);
}
