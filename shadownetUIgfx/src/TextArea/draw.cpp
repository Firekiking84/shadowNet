#include		"textArea.hh"

void			ef::TextArea::draw()
{
  size_t		start;
  size_t		i;
  t_bunny_position	drawPos;
  int			nLine;
  int			nChar;

  if (bg != nullptr)
    drawRectangle(px, pos, posEnd, *bg);
  if (text.size() <= sizeTextDisplay)
    start = 0;
  else
    start = text.size() - sizeTextDisplay;
  nLine = 0;
  nChar = 0;
  for (i = start; i < text.size(); i += 1)
    {
      if (text[i] != '\n')
	{
	  drawPos.x = pos.x + 1 + (nChar * sizeLetter.x);
	  drawPos.y = pos.y + 1 + (nLine * sizeLetter.y);
	  font->clipable.clip_x_position = text[i] * sizeLetter.x;
	  blit(px, font, &drawPos, &colLetter);
	}
      nChar += 1;
      if (nChar >=  nbCharMax)
	{
	  nChar = 0;
	  nLine += 1;
	}
    }
}
