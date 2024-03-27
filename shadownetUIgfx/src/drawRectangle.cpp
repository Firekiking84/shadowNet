#include		"draw.hh"

void			ef::drawRectangle(t_bunny_pixelarray	*px,
					  t_bunny_position	posStart,
					  t_bunny_position	posEnd,
					  t_bunny_color		col)
{
  t_bunny_position	drawPos;

  for (drawPos.y = posStart.y; drawPos.y < posEnd.y; drawPos.y += 1)
    for (drawPos.x = posStart.x; drawPos.x < posEnd.x; drawPos.x += 1)
      setPixel(px, drawPos, col);
}
