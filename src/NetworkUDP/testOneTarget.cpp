// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:28 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Call poll to test only one fd

#include		"networkUDP.hh"

int			ef::NetworkUDP::testOneTarget(struct pollfd	&	tmp_pfd,
						      int			target,
						      int			timeout)
{
  int				status;

  status = poll(&pfd[target], 1, 0);
  if (status == 0)
    return(-3);
  else if (status == -1)
    return(-1);
  else if (pfd[target].revents & tmp_pfd.events)
    return(pfd[target].fd);
  return(-1);
}
