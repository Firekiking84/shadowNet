#ifndef		__DIV_HH__

#define		__DIV_HH__

#include	"button.hh"
#include	"draw.hh"

#include	<lapin.h>

namespace	ef
{
  class		Div
  {
  public:
    Div();
    Div(t_bunny_pixelarray	*_px,
	t_bunny_position	_pos,
	t_bunny_size		_size,
	t_bunny_color		*_bg,
	t_bunny_position const	*_mousePos);
    Div(Div const		&other);
    ~Div();

    void	draw();
    void	setColor(t_bunny_color	*col);
    void	addButton(t_bunny_position			_pos,
			  t_bunny_size				_size,
			  t_bunny_color				*col,
			  int					nbCol,
			  std::function<void()>			trigger);
    void	mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
				bool				isReleased);
    void	mouseMoveEvent(t_bunny_mouse_move_event		mouseMoved);
    Div const	&operator=(Div const				&other);
  private:
    t_bunny_pixelarray		*px;
    t_bunny_position		pos;
    t_bunny_position		posEnd;
    t_bunny_color		*bg;
    t_bunny_position const	*mousePos;
    std::vector<Button>		buttons;
    bool			lastWasIn;
  };
}

#endif	//	__DIV_HH__
