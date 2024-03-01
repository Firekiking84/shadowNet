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
  struct pollfd			tmp_pfd;

  if (mode == Mode::WRITE)
    tmp_pfd.events = POLLOUT;
  else if (mode == Mode::READ)
    tmp_pfd.events = POLLIN;
  else
    tmp_pfd.events = POLLIN | POLLOUT;
  if (target == -1)
    return(testAllTarget(tmp_pfd, timeout));
  return(testOneTarget(tmp_pfd, target, timeout));
}
