#include		"shadowNet.hh"

void			ef::ShadowNet::run()
{
  int			fd;

  while (isRunning)
    {
      fd = can(ef::NetworkUDP::Mode::READ, -1, 60000); // check 1 min
      if (pfd[EXTERNAL].fd == fd)
	manageExternalInput();
      else if (pfd[INTERNAL].fd == fd)
	manageInternalInput();
      else if (fd != -3) // -3 == timeout
	{
	  perror("Erreur Run : ");
	  throw(std::runtime_error("Error while listening !"));
	}
      refreshFiles();
      timeToDie();
    }
}
