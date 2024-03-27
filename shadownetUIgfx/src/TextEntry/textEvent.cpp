#include		"textEntry.hh"

void			ef::TextEntry::textEvent(t_bunny_text_event		_text)
{
  if (focus)
    text.push_back((char)_text.unicode);
}
