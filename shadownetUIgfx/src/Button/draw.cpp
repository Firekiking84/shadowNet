#include		"button.hh"

void			ef::Button::draw()
{
  drawRectangle(px, pos, posEnd, col[modeCol]);
}
