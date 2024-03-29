#include		"gui.hh"
#include		<iostream>

void			ef::Gui::addFriend(std::string const		&newPair)
{
  std::string		request;

  request = "addfriend " + newPair;
  network.sendSoft(request);
  std::cout << "send : " << request << std::endl;
}
