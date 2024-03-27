#include		"div.hh"

void			ef::Div::addButton(t_bunny_position		_pos,
					   t_bunny_size			_size,
					   t_bunny_color		*col,
					   int				nbCol,
					   std::function<void()>	trigger)
{
  t_bunny_position	_posEnd;

  _posEnd.x = _pos.x + _size.x;
  _posEnd.y = _pos.y + _size.y;
  if (_pos.x > posEnd.x || _pos.y > posEnd.y)
    throw (std::runtime_error("Cannot create a button outside the div"));
  if (_pos.x < pos.x)
    {
      _size.x -= pos.x - _pos.x;
      _pos.x = pos.x;
    }
  if (_pos.y < pos.y)
    {
      _size.y -= pos.y - _pos.y;
      _pos.y = pos.y;
    }
  if (_posEnd.x > posEnd.x)
      _size.x -= _posEnd.x - posEnd.x - 1;
  if (_posEnd.y > posEnd.y)
      _size.y -= _posEnd.y - posEnd.y - 1;
  if (_size.x <= 0 || _size.y <= 0)
    throw (std::runtime_error("Cannot create a button outside the div or wrong side"));
  buttons.emplace_back(_pos, _size, px, col, nbCol, trigger);
}
