#include		"gui.hh"

void			ef::Gui::addTextArea(std::string const			&divName,
					     t_bunny_position			_pos,
					     int				_sizeLetter,
					     t_bunny_color			*_bg,
					     t_bunny_color			_colLetter,
					     std::string const			&_text)
{
  if (divs.find(divName) != divs.end())
    divs[divName].addTextArea(_pos, _sizeLetter, _bg, _colLetter, _text);
  else
    throw(std::runtime_error("The div does not exist, cannot create a text area"));
}
