#include		"div.hh"

ef::Div::Div(t_bunny_pixelarray		*_px,
	     t_bunny_position		_pos,
	     t_bunny_position		_size,
	     t_bunny_color		*_bg)
  : px(_px)
  , pos(_pos)
  , bg(_bg)
  , lastWasIn(false)
{
  posEnd.x = pos.x + _size.x;
  posEnd.y = pos.y + _size.y;
}

ef::Div::Div()
{
  throw(std::runtime_error("This constructor must not be used !"));
}

ef::Div::Div(Div const			&other)
  : px(other.px)
  , pos(other.pos)
  , posEnd(other.posEnd)
  , bg(other.bg)
  , buttons(other.buttons)
  , lastWasIn(other.lastWasIn)
{
}

ef::Div::~Div()
{
}
