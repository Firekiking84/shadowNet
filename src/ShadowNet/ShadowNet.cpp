#include		"shadowNet.hh"

ef::ShadowNet::ShadowNet(std::string const	&	_cnf_name)
  : FileRequestManager(_cnf_name)
{
  run();
}

ef::ShadowNet::~ShadowNet()
{
}
