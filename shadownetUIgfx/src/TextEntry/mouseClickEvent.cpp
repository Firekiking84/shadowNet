#include		"textEntry.hh"

void			ef::TextEntry::mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
						       bool				isReleased)
{
  if (inBox(mouseButton.x, mouseButton.y) && mouseButton.button == BMB_LEFT)
    {
      if (pullIn && isReleased)
	{
	  modeCol = HOVER;
	  pullIn = false;
	  focus = true;
	}
      else if (!pullIn && !isReleased)
	{
	  modeCol = PULL;
	  pullIn = true;
	}
    }
  else if (!isReleased && mouseButton.button == BMB_LEFT)
    focus = false;
}
