#include		"shadowNet.hh"

void			ef::ShadowNet::run()
{
  int			fd;

  while (isRunning)
    {
      fd = can(ef::NetworkUDP::Mode::READ, -1, 60000); // check 1 min
      if (fd == 0)
	manageExternalInput();
      else if (fd == 1)
	manageInternalInput();
      else if (fd != -3) // -3 == timeout
	throw(std::runtime_error("Error while listening !"));
      refreshFiles();
      timeToDie();
    }
}
