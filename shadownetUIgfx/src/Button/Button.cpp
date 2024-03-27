#include		"button.hh"

ef::Button::Button(t_bunny_position		_pos,
		   t_bunny_size			_size,
		   t_bunny_pixelarray		*_px,
		   t_bunny_color		*_col,
		   int				nbCol,
		   std::function<void()>	_trigger)
  : px(_px)
  , modeCol(DEFAULT)
  , pos(_pos)
  , trigger(_trigger)
  , pullIn(false)
  , mouseInBox(false)
{
  posEnd.x = _size.x + pos.x;
  posEnd.y = _size.y + pos.y;
  if (nbCol == 0 || _col == nullptr)
    {
      col[0].full = BLACK;
      col[1] = col[0];
      col[2] = col[1];
    }
  else if (nbCol == 1)
    {
      col[0] = _col[0];
      col[1] = col[0];
      col[2] = col[1];
    }
  else if (nbCol == 2)
    {
      col[0] = _col[0];
      col[1] = _col[1];
      col[2] = col[1];
    }
  else if (nbCol == 3)
    {
      col[0] = _col[0];
      col[1] = _col[1];
      col[2] = _col[2];
    }
}

ef::Button::~Button()
{
}
