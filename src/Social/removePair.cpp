#include		"social.hh"

void			ef::Social::removePair(std::string const	&	label)
{
  std::string		msgUser;

  pairs.erase(label);
  msgUser = label + " has been removed from your pairs";
}
