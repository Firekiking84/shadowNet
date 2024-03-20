// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:00:14 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"contact.hh"

ef::contact	&	ef::contact::operator=(ef::contact const	&	other)
{
  label = other.label;
  ip = other.ip;
  port = other.port;
  addr = other.addr;
  sAddr = other.sAddr;
  return(*this);
}

bool			operator==(ef::contact const	&	a,
				   ef::contact const	&	b)
{
  if (a.ip == b.ip && a.port == b.port)
    return(true);
  else
    return(false);
}
