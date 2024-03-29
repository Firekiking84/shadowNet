#include		"gui.hh"
#include		"shadownetUIgfx.hh"

t_bunny_response	ef::Gui::realEventResponse(t_bunny_event const	&event)
{
  std::map<std::string, Div>::iterator	it;

  if (event.type == BET_KEY_PRESSED)
    {
      if (event.key.sym == BKS_ESCAPE && !event.key.alt && !event.key.control && !event.key.shift)
	return(EXIT_ON_SUCCESS);
      else
	for (it = divs.begin(); it != divs.end(); ++it)
	  it->second.keyEvent(event.key);
    }
  else if (event.type == BET_MOUSE_MOVED)
    for (it = divs.begin(); it != divs.end(); ++it)
      it->second.mouseMoveEvent(event.mouse_moved);
  else if (event.type == BET_MOUSE_BUTTON_PRESSED)
    for (it = divs.begin(); it != divs.end(); ++it)
      it->second.mouseClickEvent(event.mouse_button, false);
  else if (event.type == BET_MOUSE_BUTTON_RELEASED)
    for (it = divs.begin(); it != divs.end(); ++it)
      it->second.mouseClickEvent(event.mouse_button, true);
  else if (event.type == BET_TEXT_ENTERED)
    for (it = divs.begin(); it != divs.end(); ++it)
      it->second.textEvent(event.text);
  return(GO_ON);
}

t_bunny_response		ef::Gui::eventResponse(t_bunny_event const	*event,
						       void			*_data)
{
  struct s_data			*data = static_cast<struct s_data*>(_data);
  ef::Gui			*gui = static_cast<ef::Gui*>(data->gui);

  return (gui->realEventResponse(*event));
}

