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
  void		blit(t_bunny_pixelarray			*target,
		     const t_bunny_pixelarray		*src,
		     const t_bunny_position		*pos,
		     t_bunny_color			*forcedCol = nullptr);
  double	get_ratio(int				a,
			  int				b,
			  int				x);
  int		get_value(int				a,
			  int				b,
			  double			ratio);
  int		get_npos(int				width,
			 t_bunny_position		pos);

  struct		t_blit
  {
    t_bunny_position	shift;
    t_bunny_position	src_pos;
    t_bunny_position	target_pos;
    t_bunny_position	final_pos;
    t_bunny_position	clip;
    int			src_limit;
    int			target_limit;
    t_bunny_position	size_dest;
    bool		is_x_reverse;
    bool		is_y_reverse;
  };
}

#endif	//	__DRAW_HH__
