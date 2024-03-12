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
  std::string		userMsg;

  for (it = filesFind.begin(); it != filesFind.end() && it->second.filename != filename; ++it);
  if (it != filesFind.end())
    {
      userMsg = it->second.pairs.size() + " different paths has been find toward your requested file !";
      sendUser(userMsg);
      if (currentDownload.find(it->first) != currentDownload.end())
	{
	  userMsg = "Download progress " + std::to_string(getStatus(it->first)) + "%"; // log and notify user !
	  sendUser(userMsg);
	}
    }
  else
    {
      sendUser("The files has not been find in your pair"); // Log erreur no filename found
      std::vector<std::string>	keywords;
      size_t			i;
      size_t			nbRequest;

      nbRequest = 0;
      getKeyWords(filename, keywords);
      for (i = 0; i < keywords.size(); i += 1)
	if (pendingSearchRequest.find(keywords[i]) == pendingSearchRequest.end())
	  nbRequest += 1;
      userMsg = filename + " is part of " + std::to_string(nbRequest) + " request(s) !";
    }
 }
