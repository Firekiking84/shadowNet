#ifndef		__DRAW_HH__

#define		__DRAW_HH__

#include	<lapin.h>

namespace	ef
{
  void		setPixel(t_bunny_pixelarray		*px,
			 t_bunny_position		pos,
			 t_bunny_color			col);
  void		drawRectangle(t_bunny_pixelarray	*px,
			      t_bunny_position		posStart,
			      t_bunny_position		posEnd,
			      t_bunny_color		col);
}

#endif	//	__DRAW_HH__
