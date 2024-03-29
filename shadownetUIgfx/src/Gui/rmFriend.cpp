#include		"gui.hh"
#include		<iostream>

void			ef::Gui::rmFriend(std::string const		&label)
{
  std::string		request;

  request = "removefriend " + label;
  network.sendSoft(request);
  std::cout << "Send : " << request << std::endl;
}
