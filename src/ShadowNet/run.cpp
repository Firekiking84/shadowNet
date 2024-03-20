// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:25 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

void			ef::ShadowNet::run()
{
  int			fd;

  while (isRunning)
    {
      fd = can(ef::NetworkUDP::Mode::READ, -1, 1000); // check 1s
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
