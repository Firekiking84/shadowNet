#include		"div.hh"

void			ef::Div::draw()
{
  size_t		i;

  if (bg != nullptr)
    drawRectangle(px, pos, posEnd, *bg);
  for (i = 0; i < buttons.size(); i += 1)
    buttons[i].draw();
}
