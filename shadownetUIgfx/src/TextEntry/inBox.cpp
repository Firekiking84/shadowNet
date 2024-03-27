#include		"textEntry.hh"

bool			ef::TextEntry::inBox(int	x,
					     int	y) const
{
  if (x >= pos.x && x <= posEnd.x &&
      y >= pos.y && y <= posEnd.y)
    return(true);
  return(false);
}
