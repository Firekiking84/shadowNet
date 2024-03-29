#include		"div.hh"

void			ef::Div::addTextEntry(t_bunny_position			_pos,
					      int				_nbCharMax,
					      int				_nbLinesMax,
					      int				_sizeLetter,
					      t_bunny_color			_bg,
					      t_bunny_color			_colLetter,
					      std::function<void(std::string const	&)>	_output)
{
  if (_pos.x > posEnd.x || _pos.y > posEnd.y)
    throw(std::runtime_error("Cannot draw textEntry outside the div !"));
  if (_nbCharMax <= 0 || _nbLinesMax <= 0 || _sizeLetter <= 0)
    throw(std::runtime_error("Wrong parameter for the textEntry sizes !"));
  t_bunny_position	_posEnd;
  t_bunny_size		sizeLetter;

  sizeLetter.y = _sizeLetter;
  sizeLetter.x = sizeLetter.y * 10 / 14;
  _posEnd.x = _pos.x + 2 + (sizeLetter.x * _nbCharMax);
  _posEnd.y = _pos.y + ((sizeLetter.y + 2) * _nbLinesMax);
  if (_pos.x < pos.x)
    {
      _nbCharMax -= divideSup(pos.x - _pos.x, sizeLetter.x);
      _pos.x = pos.x;
    }
  if (_pos.y < pos.y)
    {
      _nbLinesMax -= divideSup(pos.y - _pos.y, sizeLetter.y);
      _pos.y = pos.y;
    }
  if (_posEnd.x > posEnd.x)
    {
      _nbCharMax -= divideSup(_posEnd.x - posEnd.x, sizeLetter.x);
      _posEnd.x = posEnd.x;
    }
  if (_posEnd.y > posEnd.y)
    {
      _nbLinesMax -= divideSup(_posEnd.y - posEnd.y, sizeLetter.y);
      _posEnd.y = posEnd.y;
    }
  if (_nbLinesMax <= 0 || _nbCharMax <= 0)
    throw(std::runtime_error("Cannot draw a textEntry outside the div"));
  textEntries.emplace_back(_pos, _posEnd, sizeLetter, _nbCharMax, _nbLinesMax, px, _bg, _colLetter, _output);
}
