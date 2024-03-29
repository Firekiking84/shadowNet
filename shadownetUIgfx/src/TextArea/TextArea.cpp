#include		"textArea.hh"

ef::TextArea::TextArea(t_bunny_position		_pos,
		       t_bunny_pixelarray	*_px,
		       int			_sizeLetter,
		       t_bunny_color		*_bg,
		       t_bunny_color		_colLetter,
		       std::string const	&_text)
  : pos(_pos)
  , px(_px)
  , bg(_bg)
  , colLetter(_colLetter)
  , text(_text)
{
  sizeLetter.y = _sizeLetter;
  sizeLetter.x = sizeLetter.y * 10 / 14;
  getAreaSizes();
  sizeTextDisplay = nbCharMax * nbLinesMax;
  posEnd.x = pos.x + (sizeLetter.x * nbCharMax);
  posEnd.y = pos.y + ((sizeLetter.y + 2) * nbLinesMax);
  font = bunny_load_pixelarray("font.png");
  font->clipable.clip_width = sizeLetter.x;
  font->clipable.clip_height = sizeLetter.y;
  font->clipable.clip_x_position = 0;
  font->clipable.clip_y_position = 0;
}

ef::TextArea::TextArea(t_bunny_position		_pos,
		       t_bunny_position		_posEnd,
		       t_bunny_pixelarray       *_px,
		       t_bunny_size		_sizeLetter,
		       int			_nbCharMax,
		       int			_nbLinesMax,
		       t_bunny_color		*_bg,
		       t_bunny_color		_colLetter,
		       std::string const	&_text)
  : pos(_pos)
  , posEnd(_posEnd)
  , nbCharMax(_nbCharMax)
  , nbLinesMax(_nbLinesMax)
  , sizeLetter(_sizeLetter)
  , px(_px)
  , bg(_bg)
  , colLetter(_colLetter)
  , text(_text)
  , sizeTextDisplay(_nbCharMax * _nbLinesMax)
{
  font = bunny_load_pixelarray("font.png");
  font->clipable.clip_width = sizeLetter.x;
  font->clipable.clip_height = sizeLetter.y;
  font->clipable.clip_x_position = 0;
  font->clipable.clip_y_position = 0;
}

ef::TextArea::TextArea(TextArea const		&other)
  : pos(other.pos)
  , posEnd(other.posEnd)
  , nbCharMax(other.nbCharMax)
  , nbLinesMax(other.nbLinesMax)
  , sizeLetter(other.sizeLetter)
  , px(other.px)
  , bg(other.bg)
  , colLetter(other.colLetter)
  , text(other.text)
  , sizeTextDisplay(other.sizeTextDisplay)
{
  font = bunny_load_pixelarray("font.png");
  font->clipable.clip_width = sizeLetter.x;
  font->clipable.clip_height = sizeLetter.y;
  font->clipable.clip_x_position = 0;
  font->clipable.clip_y_position = 0;
}

ef::TextArea::~TextArea()
{
  bunny_delete_clipable(&font->clipable);
}
