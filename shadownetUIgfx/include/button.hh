#ifndef				__BUTTON_HH__

#define				__BUTTON_HH__

#include			"draw.hh"

#include			<lapin.h>
#include			<functional>

namespace			ef
{
  class				Button
  {
  public:
    Button(t_bunny_position					_pos,
	   t_bunny_size						_size,
	   t_bunny_pixelarray					*_px,
	   t_bunny_color					*_col,
	   int							nbCol,
	   std::function<void()>				_trigger);
    ~Button();
    void			draw();
    void			mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
						bool				isReleased);
    void			mouseMoveEvent(t_bunny_mouse_move_event		mouseMoved);
    void			reset();
  private:
    enum			e_colButton
      {
	DEFAULT = 0,
	HOVER,
	PULL
      };
    t_bunny_pixelarray		*px;
    t_bunny_color		col[3];
    int				modeCol;
    t_bunny_position		pos;
    t_bunny_position		posEnd;
    std::function<void()>	trigger;
    bool			pullIn;
    bool			mouseInBox;

    bool			inBox(int			x,
				      int			y);
  };
}

#endif	//			__BUTTON_HH__
