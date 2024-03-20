// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:21:01 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"shadowNet.hh"

void		ef::ShadowNet::cmdAddfriend(std::string const &	buffer)
{
  contact		stranger;
  std::string       msgUser;

  sendUser("Adding Pair...");
  getParameters(buffer, stranger.label, stranger.ip, stranger.port);
  if (stranger.label.size() > 0 && stranger.ip.size() > 0 && stranger.port > 0)
    addPair(stranger);
  else
    sendUser("Missing argument(s) : addfriend [label] [ip] [port]");
}
