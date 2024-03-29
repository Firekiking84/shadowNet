#ifndef		__DIV_HH__

#define		__DIV_HH__

#include	"button.hh"
#include	"textArea.hh"
#include	"textEntry.hh"
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
	t_bunny_color		*_bg);
    Div(Div const		&other);
    ~Div();

    void	draw();
    void	setColor(t_bunny_color	*col);
    void	addButton(t_bunny_position			_pos,
			  t_bunny_size				_size,
			  t_bunny_color				*col,
			  int					nbCol,
			  std::function<void()>			trigger);
    void	addTextEntry(t_bunny_position			_pos,
			     int				_nbCharMax,
			     int				_nbLinesMax,
			     int				_sizeLetter,
			     t_bunny_color			_bg,
			     t_bunny_color			_colLetter,
			     std::function<void(std::string const &)>	_output);
    void	addTextArea(t_bunny_position			_pos,
			    int					_sizeLetter,
			    t_bunny_color			*_bg,
			    t_bunny_color			_colLetter,
			    std::string const			&_text);
    void	mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
				bool				isReleased);
    void	mouseMoveEvent(t_bunny_mouse_move_event		mouseMoved);
    void        keyEvent(t_bunny_key_event			key);
    void	textEvent(t_bunny_text_event			_text);
    Div const	&operator=(Div const				&other);
  private:
    t_bunny_pixelarray		*px;
    t_bunny_position		pos;
    t_bunny_position		posEnd;
    t_bunny_color		*bg;
    std::vector<Button>		buttons;
    std::vector<TextEntry>	textEntries;
    std::vector<TextArea>	textAreas;
    bool			lastWasIn;

    int				divideSup(int		num,
					  int		factor) const;
    void			getTextAreaSizes(int			&nbCharMax,
						 int			&nbLinesMax,
						 std::string const	&text) const;
  };
}

#endif	//	__DIV_HH__
