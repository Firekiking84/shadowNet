#include		"textEntry.hh"

ef::TextEntry::TextEntry(t_bunny_position			_pos,
			 int					_nbCharMax,
			 int					_nbLinesMax,
			 int					_sizeLetters,
			 t_bunny_pixelarray			*_px,
			 t_bunny_color				_bg,
			 t_bunny_color				_colLetter,
			 std::function<void(const char *)>	_output)
  : pos(_pos)
  , nbCharMax(_nbCharMax)
  , nbLinesMax(_nbLinesMax)
  , px(_px)
  , bg(_bg)
  , colLetter(_colLetter)
  , output(_output)
  , focus(false)
  , pullIn(false)
  , sizeTextDisplay(nbCharMax * nbLinesMax)
{
  sizeLetter.y = _sizeLetters;
  sizeLetter.x = sizeLetter.y * 10 / 14;
  posEnd.x = pos.x + (sizeLetter.x * nbCharMax);
  posEnd.y = pos.y + ((sizeLetter.y + 2) * nbLinesMax);
  font = bunny_load_pixelarray("font.bmp");
  font->clipable.clip_width = sizeLetter.x;
  font->clipable.clip_height = sizeLetter.y;
  font->clipable.clip_x_position = 0;
  font->clipable.clip_y_position = 0;
}

ef::TextEntry::TextEntry(TextEntry const			&other)
  : pos(other.pos)
  , posEnd(other.posEnd)
  , nbCharMax(other.nbCharMax)
  , nbLinesMax(other.nbLinesMax)
  , sizeLetter(other.sizeLetter)
  , px(other.px)
  , bg(other.bg)
  , colLetter(other.colLetter)
  , output(other.output)
  , focus(false)
  , pullIn(false)
  , text(other.text)
  , sizeTextDisplay(other.sizeTextDisplay)
{
  font = bunny_load_pixelarray("font.bmp");
  font->clipable.clip_width = sizeLetter.x;
  font->clipable.clip_height = sizeLetter.y;
  font->clipable.clip_x_position = 0;
  font->clipable.clip_y_position = 0;
}

ef::TextEntry::~TextEntry()
{
}
