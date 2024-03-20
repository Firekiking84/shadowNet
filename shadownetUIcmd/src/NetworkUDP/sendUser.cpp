// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:30 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Send the message enter by the User

#include			"networkUDP.hh"

#include			<iostream>

void				ef::NetworkUDP::sendUser(std::string const		&	msg)
{
  if (can(Mode::WRITE, pfd[1].fd, 10000) == pfd[1].fd)
    std::cout << msg << std::flush;
}
