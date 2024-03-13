#include		"networkUDP.hh"

#include		<string>
#include		<iostream>
#include		<stdexcept>

int		        main(int		ac,
			     char		**av)
{
  if (ac < 4)
    {
      std::cerr << "Not enough argument. Port is missing" << std::endl;
      std::cerr << "Pattern : ./shadownetUI [portUI] [ipSoftware] [portSoftware]" << std::endl;
      return(-1);
    }
  std::string	        tmpStr;
  int			portUI;
  int			portSoft;
  std::string		ip;
  tmpStr = av[1];
  portUI = stoi(tmpStr);
  ip = av[2];
  tmpStr = av[3];
  portSoft = stoi(tmpStr);

  ef::NetworkUDP		network(portUI, ip, portSoft);
  bool			isRunning;
  int			fd;
  std::string		buffer;
  size_t		sizeBuffer;

  sizeBuffer = 100;
  isRunning = true;
  while (isRunning)
    {
      buffer.clear();
      buffer.resize(sizeBuffer);
      fd = network.can(ef::NetworkUDP::Mode::READ, -1, 60000);
      if (fd == 0)
	{
	  network.readFd(buffer, sizeBuffer, 0);
	  if (buffer.compare(0, 4, "exit") == 0)
	    isRunning = false;
	  else
	    {
	      if (buffer.compare(0, 8, "shutdown") == 0)
		buffer = "exit";
	      network.sendSoft(buffer);
	    }
	}
      else if (fd != -1 && fd != -3)
	{
	  network.recvFromSoft(buffer, sizeBuffer);
	  network.sendUser(buffer);
	}
      else if (fd == -1)
	throw(std::runtime_error("Error while listening !"));
    }
}
