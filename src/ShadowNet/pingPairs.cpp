// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:03:39 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"shadowNet.hh"

void		ef::ShadowNet::pingPairs()
{
  Packet		newPacket;
  std::string	userMsg;

  newPacket.type = PING;
  userMsg = "Ping to your " + std::to_string(pairs.size()) + " pair(s)";
  sendUser(userMsg);
  sendPacket(newPacket, pairs);
}
