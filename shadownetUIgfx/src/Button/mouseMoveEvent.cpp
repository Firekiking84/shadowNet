#include		"button.hh"

void			ef::Button::mouseMoveEvent(t_bunny_mouse_move_event	mouseMoved)
{
  if (inBox(mouseMoved.x, mouseMoved.y))
    {
      if (!pullIn)
	modeCol = HOVER;
      else
	modeCol = PULL;
      mouseInBox = true;
    }
  else
    {
      mouseInBox = false;
      pullIn = false;
      modeCol = DEFAULT;
    }
}
