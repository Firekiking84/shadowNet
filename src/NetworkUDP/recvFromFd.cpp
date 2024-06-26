// EFRITS
// project:     Talk
// created on:  07/11/2023 13:46:08
// 1st author:  keryan.houssin - keryan.houssin@gagarine.efrits.fr
// description: Use Recvfrom until there is nothing more to read

#include			"networkUDP.hh"

#include			<stdio.h>
#include			<iostream>

ssize_t				ef::NetworkUDP::recvFromFd(int				fd,
							   struct sockaddr_in	&	addr,
							   std::string		&	buffer,
							   size_t		&	sizeBuffer)
{
  ssize_t			sizeRcv;
  size_t			index;
  socklen_t			addrlen;
  ssize_t			sizePiece;
  bool				canRead;

  index = 0;
  sizeRcv = 0;
  sizePiece = sizeBuffer;
  canRead = true;
  while (canRead)
    {
      canRead = false;
      addrlen = sizeof(addr);
      sizeRcv = recvfrom(fd, &buffer[index], sizePiece, 0, reinterpret_cast<struct sockaddr *>(&addr), &addrlen);
      if (sizeRcv == -1)
	{
	  std::cerr << "Erreur de Recvfrom" << std::endl;
	  perror("Erreur : ");
	  return(-1);
	}
      else if (sizeRcv > 0)
	{
	  index += sizeRcv;
	  if (sizeRcv != sizePiece)
	    buffer.resize(index);
	  else if (can(ef::NetworkUDP::Mode::READ, fd))
	    {
	      canRead = true;
	      sizeBuffer += sizePiece;
	      buffer.resize(sizePiece);
	    }
	}
    }
  return(buffer.size());
}
