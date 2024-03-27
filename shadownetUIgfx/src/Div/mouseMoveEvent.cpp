#include		"div.hh"

void			ef::Div::mouseMoveEvent(t_bunny_mouse_move_event	mouseMoved)
{
  if (mouseMoved.x >= pos.x && mouseMoved.x < posEnd.x &&
      mouseMoved.y >= pos.y && mouseMoved.y < posEnd.y)
    {
      size_t		i;

      lastWasIn = true;
      for (i = 0; i < buttons.size(); i += 1)
	buttons[i].mouseMoveEvent(mouseMoved);
    }
  else if (lastWasIn)
    {
      size_t		i;

      lastWasIn = false;
      for (i = 0; i < buttons.size(); i += 1)
	buttons[i].reset();
    }
}
