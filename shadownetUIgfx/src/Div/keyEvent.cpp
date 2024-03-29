#include		"div.hh"

void			ef::Div::keyEvent(t_bunny_key_event	key)
{
  size_t		i;

  for (i = 0; i < textEntries.size(); i += 1)
    textEntries[i].keyEvent(key);
}
