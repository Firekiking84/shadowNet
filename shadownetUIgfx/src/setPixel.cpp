#include		"draw.hh"

void			ef::setPixel(t_bunny_pixelarray	*px,
				     t_bunny_position	pos,
				     t_bunny_color	col)
{
  unsigned int		*tab;
  int			npos;

  tab = (unsigned int *)px->pixels;
  npos = pos.y * px->clipable.buffer.width + pos.x;
  tab[npos] = col.full;
}
