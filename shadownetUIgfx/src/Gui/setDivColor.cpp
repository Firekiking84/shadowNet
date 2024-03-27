#include		"gui.hh"

void			ef::Gui::setDivColor(std::string const		&divName,
					     t_bunny_color		*col)
{
  divs[divName].setColor(col);
}
