// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:20:05 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"fileRequestManager.hh"

void		ef::FileRequestManager::forgetFile(std::string const	&filename)
{
  myPendingRequest.erase(filename);
  std::map<uint64_t, fileInfoPair>::iterator	it;

  for (it = filesFind.begin(); it != filesFind.end();)
    {
      if (it->second.filename == filename)
	it = filesFind.erase(it);
      else
	++it;
    }
  std::string	userMsg;

  userMsg = "The file " + filename + " has been forgot !";
  sendUser(userMsg);
}
