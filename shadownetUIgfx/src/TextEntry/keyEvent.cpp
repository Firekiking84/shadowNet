#include		"textEntry.hh"

void			ef::TextEntry::keyEvent(t_bunny_key_event	key)
{
  if (focus && !key.alt && !key.control && !key.shift && !key.system)
    {
      if (key == BKS_RETURN)
	output(text.c_str());
      else if (key == BKS_BACKSPACE && text.size() > 0)
	text.pop_back();
    }
}
