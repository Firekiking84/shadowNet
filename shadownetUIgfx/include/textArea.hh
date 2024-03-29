#ifndef			__TEXT_AREA_HH__

#define			__TEXT_AREA_HH__

#include		"draw.hh"

#include		<lapin.h>

namespace		ef
{
  class			TextArea
  {
  public:
    TextArea(t_bunny_position	_pos,
	     t_bunny_pixelarray	*_px,
	     int		_sizeLetter,
	     t_bunny_color	*_bg,
	     t_bunny_color	_colLetter,
	     std::string const	&_text);
    TextArea(t_bunny_position	_pos,
	     t_bunny_position	_posEnd,
	     t_bunny_pixelarray	*_px,
	     t_bunny_size	_sizeLetter,
	     int		_nbCharMax,
	     int		_nbLinesMax,
	     t_bunny_color	*_bg,
	     t_bunny_color	_colLetter,
	     std::string const	&_text);
    TextArea(TextArea const	&other);
    ~TextArea();

    void		draw();
  private:
    t_bunny_position	pos;
    t_bunny_position	posEnd;
    int			nbCharMax;
    int			nbLinesMax;
    t_bunny_size	sizeLetter;
    t_bunny_pixelarray	*px;
    t_bunny_pixelarray	*font;
    t_bunny_color	*bg;
    t_bunny_color	colLetter;
    std::string		text;
    size_t		sizeTextDisplay;

    void		getAreaSizes();
  };
}

#endif	//	__TEXT_AREA_HH__
