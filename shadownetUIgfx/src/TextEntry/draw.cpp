#include		"textEntry.hh"

void			ef::TextEntry::draw()
{
  size_t		start;
  t_bunny_position	drawPos;
  int			nLine;
  int			nChar;

  drawRectangle(px, pos, posEnd, bg);
  if (text.size() < sizeTextDisplay)
    start = 0;
  else
    start = text.size() - sizeTextDisplay;
  nLine = 0;
  nChar = 0;
  for (i = start; i < text.size(); i += 1)
    {
      drawPos.x = pos.x + (nChar * sizeLetter.x);
      drawPos.y = pos.y + (nLine * sizeLetter.y);
      font->clipable.clip_x_position = (text[i] - ' ') * sizeLetter.x;
      blit(px, font, drawPos);
      nChar += 1;
      if (nChar > nbCharMax)
	{
	  nChar = 0;
	  nLine += 1;
	}
    }
}
