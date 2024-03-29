#include		"div.hh"

void			ef::Div::addTextArea(t_bunny_position		_pos,
					     int			_sizeLetter,
					     t_bunny_color		*_bg,
					     t_bunny_color		_colLetter,
					     std::string const		&_text)
{
  if (_pos.x > posEnd.x || _pos.y > posEnd.y)
    throw(std::runtime_error("Cannot draw TextArea outside the div !"));
  if (_sizeLetter <= 0)
    throw(std::runtime_error("Wrong parameter for the textArea sizeLetter!"));

  int			nbCharMax;
  int			nbLinesMax;
  t_bunny_size		sizeLetter;
  t_bunny_position	_posEnd;

  sizeLetter.y = _sizeLetter;
  sizeLetter.x = sizeLetter.y * 10 / 14;
  getTextAreaSizes(nbCharMax, nbLinesMax, _text);
  _posEnd.x = _pos.x + (sizeLetter.x * nbCharMax);
  _posEnd.y = _pos.y + ((sizeLetter.y + 2) * nbLinesMax);
  if (_pos.x < pos.x)
    {
      nbCharMax -= divideSup(pos.x - _pos.x, sizeLetter.x);
      _pos.x = pos.x;
    }
  if (_pos.y < pos.y)
    {
      nbLinesMax -= divideSup(pos.y - _pos.y, sizeLetter.y);
      _pos.y = pos.y;
    }
  if (_posEnd.x > posEnd.x)
    {
      int		substraction;

      substraction = divideSup(_posEnd.x - posEnd.x, sizeLetter.x);
      nbLinesMax = divideSup(substraction, nbCharMax);
      nbCharMax -= substraction;
      _posEnd.x = posEnd.x;
    }
  if (_posEnd.y > posEnd.y)
    {
      nbLinesMax -= divideSup(_posEnd.y - posEnd.y, sizeLetter.y);
      _posEnd.y = posEnd.y;
    }
  if (nbLinesMax <= 0 || nbCharMax <= 0)
    throw(std::runtime_error("Cannot draw a textArea outside the div"));
  textAreas.emplace_back(_pos, _posEnd, px, sizeLetter, nbCharMax, nbLinesMax, _bg, _colLetter, _text);
}
