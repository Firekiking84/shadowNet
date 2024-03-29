#include		"div.hh"

void			ef::Div::mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
						 bool				isReleased)
{
  if (mouseButton.x >= pos.x && mouseButton.x <= posEnd.x &&
      mouseButton.y >= pos.y && mouseButton.y <= posEnd.y)
    {
      size_t		i;

      for (i = 0; i < buttons.size(); i += 1)
	buttons[i].mouseClickEvent(mouseButton, isReleased);
      for (i = 0; i < textEntries.size(); i += 1)
	textEntries[i].mouseClickEvent(mouseButton, isReleased);
    }
}
