#include		"gui.hh"

#include		<iostream>

void			ef::Gui::download(uint64_t		hashFile)
{
  std::string		request;

  request = "download " + std::to_string(hashFile);
  network.sendSoft(request);
  std::cout << "Send : " << request << std::endl;
}
