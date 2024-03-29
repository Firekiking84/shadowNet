// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:29 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Call poll to test all the fd contains in the board pollfd struct

#include		"networkUDP.hh"

#include		<iostream>

int			ef::NetworkUDP::testAllTarget(int			timeout)
{
  int			status;

  status = poll(pfd, 1, timeout);
  if (status == -1)
    {
      std::cerr << "Poll Error !" << std::endl;
      return(-2);
    }
  else if (status == 0)
    return(-3);
  if (pfd[0].revents & pfd[0].events)
    return(pfd[0].fd);
  return(-1);
}
