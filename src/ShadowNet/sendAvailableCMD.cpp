// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:09:42 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

void			ef::ShadowNet::sendAvailableCMD()
{
  sendUser("Available command : ");
  sendUser(" - addfriend [label] [ip] [port]");
  sendUser(" - removefriend [label]");
  sendUser(" - requestfile [filename]");
  sendUser(" - forgetfile [filename]");
  sendUser(" - download [path/hash] [destName]");
  sendUser(" - status [filename]");
  sendUser(" - logs");
  sendUser(" - ping");
  sendUser(" - check");
}
