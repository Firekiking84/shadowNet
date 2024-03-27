#include		"button.hh"

void			ef::Button::mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
						    bool			isReleased)
{
  if (mouseInBox && mouseButton.button == BMB_LEFT)
    {
      if (pullIn && isReleased)
	{
	  modeCol = HOVER;
	  pullIn = false;
	  trigger();
	}
      else if (!pullIn && !isReleased)
	{
	  modeCol = PULL;
	  pullIn = true;
	}
    }
}
