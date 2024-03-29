// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:30 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Send the message enter by the User

#include			"networkUDP.hh"

#include			<iostream>

void				ef::NetworkUDP::sendSoft(std::string const		&	msg)
{
  if (can(Mode::WRITE, 0, 100) == pfd[0].fd)
    sendto(pfd[0].fd, msg.c_str(), msg.size(), 0, &software.sAddr, sizeof(software.sAddr));
}
