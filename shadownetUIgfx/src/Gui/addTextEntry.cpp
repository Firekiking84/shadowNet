#include		"gui.hh"

void			ef::Gui::addTextEntry(std::string const			&divName,
					      t_bunny_position			_pos,
					      int				_nbCharMax,
					      int				_nbLinesMax,
					      int				_sizeLetter,
					      t_bunny_color			_bg,
					      t_bunny_color			_colLetter,
					      std::function<void(std::string const	&)>	_output)
{
  if (divs.find(divName) != divs.end())
    divs[divName].addTextEntry(_pos, _nbCharMax, _nbLinesMax, _sizeLetter, _bg, _colLetter, _output);
  else
    throw(std::runtime_error("The div does not exist, cannot create a text entry"));
}
