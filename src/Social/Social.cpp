#include		"social.hh"

ef::Social::Social(std::string const	&	_cnf_name)
  : NetworkUDP(_cnf_name)
{
  loadPairs();
}

ef::Social::~Social()
{
  savePairs();
}
