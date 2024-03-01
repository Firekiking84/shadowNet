// EFRITS
// project:     Talk
// created on:  07/11/2023 13:45:12
// 1st author:  keryan.houssin - keryan.houssin@gagarine.efrits.fr
// description: read the fd until there is nothing more to read

#include			"networkUDP.hh"

#include			<unistd.h>
#include			<iostream>
#include			<stdio.h>

bool				ef::NetworkUDP::readFd(std::string	&	buffer,
						       int			sizeBuffer,
						       int			fd)
{
  ssize_t			sizeRead;
  ssize_t			sizePiece;
  size_t			index;
  bool				canRead;

  sizePiece = sizeBuffer;
  index = 0;
  sizeRead = 0;
  canRead = true;
  while (canRead)
    {
      canRead = false;
      sizeRead = read(fd, &buffer[index], sizePiece);
      if (sizeRead == -1)
	{
	  std::cerr << "Erreur de read !" << std::endl;
	  perror("Erreur ReadFd: ");
	  return(false);
	}
      else if (sizeRead > 0)
	{
	  index += sizeRead;
	  if (sizeRead != sizePiece)
	    {
	      buffer.resize(index - 1);
	      return(true);
	    }
	  else if (can(Mode::READ, fd) != -1)
	    {
	      canRead = true;
	      sizeBuffer += sizePiece;
	      buffer.resize(sizeBuffer);
	    }
	}
      else
	{
	  buffer = "/back";
	  return(true);
	}
    }
  if (sizeRead == 0)
    return(false);
  return(true);
}
