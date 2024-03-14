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
  currentDownload[hashFile].status.readFile(status);
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
  std::vector<std::string>	keywords;

  getKeyWords(filename, keywords);
  it = filesFind.begin();
  for (getFile(keywords, it); it != filesFind.end(); getFile(keywords, ++it))
    {
      userMsg = "filename : " + it->second.filename;
      sendUser(userMsg);
      userMsg = "description : " + it->second.description;
      sendUser(userMsg);
      userMsg = "Available on " + std::to_string(it->second.pairs.size()) + " path(s)\n";
      sendUser(userMsg);
      if (currentDownload.find(it->first) != currentDownload.end())
	{
	  userMsg = "Download progress " + std::to_string(getStatus(it->first)) + "%"; // log and notify user !
	  sendUser(userMsg);
	}
    }
  size_t			i;
  size_t			nbRequest;

  nbRequest = 0;
  for (i = 0; i < keywords.size(); i += 1)
    if (pendingSearchRequest.find(keywords[i]) == pendingSearchRequest.end())
      nbRequest += 1;
  userMsg = filename + " is part of " + std::to_string(nbRequest) + " request(s) !";
  sendUser(userMsg);
}
