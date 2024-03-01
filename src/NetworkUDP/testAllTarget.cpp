// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:29 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Call poll to test all the fd contains in the board pollfd struct

#include		"networkUDP.hh"

#include		<iostream>

int			ef::NetworkUDP::testAllTarget(struct pollfd	&	tmp_pfd,
						      int			timeout)
{
  int			i;
  int			status;

  for (i = 0; i < 2; i += 1)
    pfd[i].events = tmp_pfd.events;
  status = poll(pfd, 2, timeout);
  if (status == -1)
    {
      std::cerr << "Poll Error !" << std::endl;
      return(-2);
    }
  else if (status == 0)
    return(-3);
  for (i = 0; i < 2 && !(pfd[i].revents & tmp_pfd.events); i += 1);
  return(pfd[i].fd);
}
