#include		"gui.hh"

void			ef::Gui::addButton(std::string const		&divName,
					   t_bunny_position		pos,
					   t_bunny_size			size,
					   t_bunny_color		*col,
					   int				nbCol,
					   std::function<void()>	trigger)
{
  if (divs.find(divName) != divs.end())
    divs[divName].addButton(pos, size, col, nbCol, trigger);
  else
    throw(std::runtime_error("The div does not exist, cannot create a button"));
}
