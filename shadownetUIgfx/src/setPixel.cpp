#include		"draw.hh"

void			ef::setPixel(t_bunny_pixelarray	*px,
				     t_bunny_position	pos,
				     t_bunny_color	col)
{
  unsigned int		*tab;
  int			npos;

  tab = (unsigned int *)px->pixels;
  npos = pos.y * px->clipable.buffer.width + pos.x;
  if (col.argb[ALPHA_CMP] != 255)
    {
      t_bunny_color	oldCol;
      double		ratio;

      oldCol.full = tab[npos];
      ratio = get_ratio(0, 255, col.argb[ALPHA_CMP]);
      col.argb[RED_CMP] = oldCol.argb[RED_CMP] * (1 - ratio) + col.argb[RED_CMP] * ratio;
      col.argb[BLUE_CMP] = oldCol.argb[BLUE_CMP] * (1 - ratio) + col.argb[BLUE_CMP] * ratio;
      col.argb[GREEN_CMP] = oldCol.argb[GREEN_CMP] * (1 - ratio) + col.argb[GREEN_CMP] * ratio;
    }
  tab[npos] = col.full;
}
