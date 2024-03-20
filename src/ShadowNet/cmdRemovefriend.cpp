// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:17:43 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"shadowNet.hh"

void		ef::ShadowNet::cmdRemovefriend(std::string const &	buffer)
{
  std::string	label;

  sendUser("Removing Pair...");
  getParameters(buffer, label);
  if (label.size() > 0)
    removePair(label);
  else
    sendUser("Missing argument : removefriend [label]");
}
