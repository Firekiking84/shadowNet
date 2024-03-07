// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:14:20 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

int			ef::FileRequestManager::getStatus(uint64_t		hashFile,
							  std::string	&	status)
{
  size_t		i;
  size_t		nbAchieve;

  nbAchieve = 0;
  status = currentDownload[hashFile].file.readFile();
  for (i = 0; i < status.size(); i += 1)
    if (status[i] == '1')
      nbAchieve += 1;
  return(nbAchieve * 100 / status.size());
}

int			ef::FileRequestManager::getStatus(uint64_t		hashFile)
{
  std::string		status;

  return(getStatus(hashFile, status));
}

void			ef::FileRequestManager::getStatus(std::string const	&filename)
{
  std::map<uint64_t, fileInfoPair>::iterator	it;

  for (it = filesFind.begin(); it != filesFind.end() && it->seconds.filename != filename; ++it);
  if (it == filesFind.end())
    return; // Log erreur no filename found
  getStatus(it->second.hashFile); // log and notify user !
 }
