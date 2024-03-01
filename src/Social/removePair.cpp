#include		"social.hh"

void			ef::Social::removePair(std::string const	&	label)
{
  pairs.erase(label);
}
