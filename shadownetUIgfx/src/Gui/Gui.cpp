#include		"gui.hh"

ef::Gui::Gui(t_bunny_pixelarray	*_px,
	     int		portUI,
	     std::string const	&ip,
	     int		portSoft)
  : network(portUI, ip, portSoft)
  , px(_px)
{
  bunny_set_event_response(eventResponse);
}

ef::Gui::~Gui()
{
}
