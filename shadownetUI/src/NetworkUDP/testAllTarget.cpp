// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:29 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Call poll to test all the fd contains in the board pollfd struct

#include		"networkUDP.hh"

#include		<iostream>

int			ef::NetworkUDP::testAllTarget(int			timeout)
{
  int			i;
  int			status;

  status = poll(pfd, 3, timeout);
  if (status == -1)
    {
      std::cerr << "Poll Error !" << std::endl;
      return(-2);
    }
  else if (status == 0)
    return(-3);
  for (i = 0; i < 3 && !(pfd[i].revents & pfd[i].events); i += 1);
  return(pfd[i].fd);
}
