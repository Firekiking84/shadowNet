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

  for (it = filesFind.begin(); it != filesFind.end(); ++it)
    if (it->second.filename == filename)
      filesFind.erase(it);
}
