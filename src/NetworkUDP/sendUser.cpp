// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:30 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Send the message enter by the User

#include			"networkUDP.hh"

#include			<iostream>

void				ef::NetworkUDP::sendUser(std::string const		&	msg)
{
  std::string			finalString;

  if (msg[msg.size() - 1] != '\n')
    finalString = msg + '\n';
  else
    finalString = msg;
  if (can(Mode::WRITE, INTERNAL, 10000) == pfd[INTERNAL].fd)
    sendto(pfd[INTERNAL].fd, finalString.c_str(), finalString.size(), 0, &user.sAddr, sizeof(user.addr));
}

void				ef::NetworkUDP::sendUser(char const			*	msg)
{
  std::string			strMsg;

  strMsg = msg;
  sendUser(strMsg);
}
