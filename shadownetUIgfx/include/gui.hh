#ifndef			__GUI_HH__

#define			__GUI_HH__

#include		"div.hh"

#include		<map>

namespace		ef
{
  class			Gui
  {
  public:
    Gui(t_bunny_pixelarray	*_px);
    ~Gui();

    void		draw();
    void		addDiv(std::string const		&name,
			       t_bunny_position			pos,
			       t_bunny_size			size,
			       t_bunny_color			*bg);
    void		setDivColor(std::string const		&divName,
				    t_bunny_color		*col);
    void		rmDiv(std::string const			&divName);
    void		addButton(std::string const		&divName,
				  t_bunny_position		pos,
				  t_bunny_size			size,
				  t_bunny_color			*col,
				  int				nbCol,
				  std::function<void()>		trigger);
  private:
    t_bunny_pixelarray		*px;
    std::map<std::string, Div>	divs;
    t_bunny_position const	*mousePos;

    t_bunny_response		realEventResponse(t_bunny_event const	&event);
    static t_bunny_response	eventResponse(t_bunny_event const	*event,
					      void			*data);
  };
}


#endif	//		__GUI_HH__
