#include		"textEntry.hh"

void			ef::TextEntry::keyEvent(t_bunny_key_event	key)
{
  if (focus && !key.alt && !key.control && !key.shift && !key.system)
    {
      if (key.sym == BKS_RETURN)
	{
	  output(text);
	  text.clear();
	}
      else if (key.sym == BKS_BACKSPACE && text.size() > 0)
	text.pop_back();
    }
}
