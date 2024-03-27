#include		"gui.hh"

void			ef::Gui::draw()
{
  std::map<std::string, Div>::iterator	it;

  for (it = divs.begin(); it != divs.end(); ++it)
    it->second.draw();
}
