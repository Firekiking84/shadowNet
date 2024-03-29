#include		"div.hh"

void			ef::Div::textEvent(t_bunny_text_event	_text)
{
  size_t		i;

  for (i = 0; i < textEntries.size(); i += 1)
    textEntries[i].textEvent(_text);
}
