#ifndef			__GUI_HH__

#define			__GUI_HH__

#include		"div.hh"
#include		"networkUDP.hh"

#include		<map>

namespace		ef
{
  class			Gui
  {
  public:
    Gui(t_bunny_pixelarray	*_px,
	int			portUI,
	std::string const	&ip,
	int			portSoft);
    ~Gui();

    void		listen();
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
    void	        addTextEntry(std::string const		&divName,
				     t_bunny_position		_pos,
				     int			_nbCharMax,
				     int			_nbLinesMax,
				     int			_sizeLetter,
				     t_bunny_color		_bg,
				     t_bunny_color		_colLetter,
				     std::function<void(std::string const &)>	_output);
    void		addTextArea(std::string const		&divName,
				    t_bunny_position		_pos,
				    int				_sizeLetter,
				    t_bunny_color		*_bg,
				    t_bunny_color		_colLetter,
				    std::string const		&_text);
    void		startResearch(std::string const		&search);
    void		addFriend(std::string const		&newPair);
    void		rmFriend(std::string const		&label);
    void		download(uint64_t			hashFile);

  private:
    NetworkUDP			network;
    t_bunny_pixelarray		*px;
    std::map<std::string, Div>	divs;
    std::vector<s_searchResult>	searchResult;

    t_bunny_response		realEventResponse(t_bunny_event const	&event);
    static t_bunny_response	eventResponse(t_bunny_event const	*event,
					      void			*data);
  };
}


#endif	//		__GUI_HH__
