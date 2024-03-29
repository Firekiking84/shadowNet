#include		"gui.hh"

#include		<iostream>

void			ef::Gui::startResearch(std::string const		&search)
{
  std::string		request;

  request = "requestfile " + search;
  network.sendSoft(request);
  searchResult.clear();
  std::cout << "Send : " << request << std::endl;
}
