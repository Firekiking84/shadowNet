#include		"gui.hh"

void			ef::Gui::addDiv(std::string const		&name,
					t_bunny_position		pos,
					t_bunny_size			size,
					t_bunny_color			*bg)
{
  int			width;
  int			height;
  t_bunny_position	posEnd;

  width = px->clipable.buffer.width;
  height = px->clipable.buffer.height;
  posEnd.x = pos.x + size.x;
  posEnd.y = pos.y + size.y;
  if (pos.x >= width || pos.y >= height)
    throw(std::runtime_error("Cannot create a div outside the pixelarray !"));
  if (pos.x < 0)
    {
      size.x += pos.x; //	pos.x is negative so it's a substraction
      pos.x = 0;
    }
  if (pos.y < 0)
    {
      size.y += pos.y; //	pos.y is negative so it's a substraction
      pos.y = 0;
    }
  if (posEnd.x > width)
    size.x -= posEnd.x - width - 1;
  if (posEnd.y > height)
    size.y -= posEnd.y - height - 1;
  if (size.x <= 0 || size.y <= 0)
    throw(std::runtime_error("Wrong size or position outside the div, cannot create div !"));
  divs.emplace(std::make_pair(std::string(name), Div(px, pos, size, bg)));
}
