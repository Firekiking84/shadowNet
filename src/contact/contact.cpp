#include		"contact.hh"
#include		<cstring>

ef::contact::contact()
  : label()
  , ip()
  , port(0)
{
  memset(&addr, 0, sizeof(addr));
  memset(&sAddr, 0, sizeof(sAddr));
}

ef::contact::contact(contact const	&	other)
  : label(other.label)
  , ip(other.ip)
  , port(other.port)
  , addr(other.addr)
  , sAddr(other.sAddr)
{
}

ef::contact::~contact()
{
}
