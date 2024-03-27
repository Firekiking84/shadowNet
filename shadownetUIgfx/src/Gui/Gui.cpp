#include		"gui.hh"

ef::Gui::Gui(t_bunny_pixelarray	*_px)
  : px(_px)
{
  bunny_set_event_response(eventResponse);
}

ef::Gui::~Gui()
{
}
