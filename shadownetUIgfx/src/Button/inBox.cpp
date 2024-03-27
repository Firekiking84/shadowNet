#include		"button.hh"

bool			ef::Button::inBox(int	x,
					  int	y)
{
  if (x >= pos.x && x <= posEnd.x &&
      y >= pos.y && y <= posEnd.y)
    return(true);
  return(false);
}
