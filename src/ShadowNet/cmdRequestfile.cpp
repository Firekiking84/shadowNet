// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:15:10 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"shadowNet.hh"

void		ef::ShadowNet::cmdRequestfile(std::string const	&	 buffer)
{
  std::string	filename;
  std::string	msgUser;

  getParameters(buffer, filename);
  if (filename.size() > 0)
    {
      msgUser = "Send request of the file '" + filename + "' on your network";
      sendUser(msgUser);
      sendSearchRequest(filename);
    }
  else
    sendUser("Missing argument : requestfile [filename]");
}
