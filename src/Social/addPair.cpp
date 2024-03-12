#include		"social.hh"

void			ef::Social::addPair(contact			newPair)
{
  if (newPair.ip.size() == 0 || newPair.label.size() == 0 || newPair.port == 0)
    {
      sendUser("Wrong format of the command : addfriend [label] [ip] [port]");
      return; // log error format
    }
  if (pairs.find(newPair.label) != pairs.end())
    {
      sendUser("The label already exist");
      return; // log label already exist
    }
  newAddr(newPair);
  pairs[newPair.label] = newPair;
  std::string		msgUser;

  msgUser = newPair.label + " has been added to your pair !";
  sendUser(msgUser);
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
