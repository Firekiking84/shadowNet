#include		"textEntry.hh"

void			ef::TextEntry::textEvent(t_bunny_text_event		_text)
{
  if (focus)
    {
      uint8_t		byte;
      uint8_t		check;

      byte = _text.unicode & 0xFF;
      check = byte >> 7;
      if (!check & 0b1 && byte >= 32 && byte <= 126)
	text.push_back((char)_text.unicode);
    }
}
