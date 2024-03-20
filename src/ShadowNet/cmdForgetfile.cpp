// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:13:43 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

void			ef::ShadowNet::cmdForgetfile(std::string const	&	buffer)
{
  std::string	filename;

  getParameters(buffer, filename);
  if (filename.size() > 0)
    forgetFile(filename);
  else
    sendUser("Missing argument : forgetfile [filename]");
}
