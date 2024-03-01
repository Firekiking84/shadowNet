#include		"social.hh"

void			ef::Social::addPair(contact			newPair)
{
  if (newPair.ip.size() == 0 || newPair.label.size() == 0 || newPair.port == 0)
    return; // log
  newAddr(newPair);
  pairs[newPair.label] = newPair;
}

void			ef::Social::addPair(std::string const	&	ip,
					    std::string const	&	label,
					    int const			_port)
{
  contact		newPair;

  newPair.label = label;
  newPair.ip = ip;
  newPair.port = _port;
  addPair(newPair);
}
