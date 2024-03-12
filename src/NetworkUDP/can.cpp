// EFRITS
// project:     talk
// created on:  2023-10-17 - 15:13 +0200
// 1st author:  keryan.houssin - keryan.houssin
// description: return -2 on error,
//              -1 if cannot do the mode enter,
//              return fd if can

#include			<iostream>
#include			"networkUDP.hh"

int 				ef::NetworkUDP::can(Mode		mode,
						    int			target,
						    int			timeout)
{
  if (target == -1)
    {
      int				i;

      for (i = 0; i < 2; i += 1)
	{
	  if (mode == Mode::WRITE)
	    pfd[i].events = POLLOUT;
	  else if (mode == Mode::READ)
	    pfd[i].events = POLLIN;
	  else
	    pfd[i].events = POLLIN | POLLOUT;
	}
      return(testAllTarget(timeout));
    }
  if (mode == Mode::WRITE)
    pfd[target].events = POLLOUT;
  else if (mode == Mode::READ)
    pfd[target].events = POLLIN;
  else
    pfd[target].events = POLLIN | POLLOUT;
  return(testOneTarget(target, timeout));
}
