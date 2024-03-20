// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:10:49 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::manageSearchRequest(s_findRequest const	&request,
								    contact const	&pair)
{
  std::vector<std::string>	keywords;
  std::map<std::string, std::string>	excludeList;
  size_t		i;
  size_t		j;

  excludeList[pair.label] = pair.label;
  getKeyWords((char *)request.name, keywords);
  for (i = 0; i < keywords.size(); i += 1)
    {
      if (pendingSearchRequest.find(keywords[i]) != pendingSearchRequest.end())
	{
	  for (j = 0; j < pendingSearchRequest[keywords[i]].size(); j += 1)
	    {
	      std::string	pairLabel;

	      pairLabel = pendingSearchRequest[keywords[i]][j].label;
	      if (excludeList.find(pairLabel) != excludeList.end())
		excludeList[pairLabel] = pairLabel;
	    }
	}
    }
  isFilePossessed(request, pair, keywords);
  if (request.nbRedirection < request.limitRedirection)
    {
      std::string		filename;
      Packet			data;

      filename = (char *)request.name;
      isFileFind(request, pair, keywords);
      data.findRequest = request;
      data.findRequest.nbRedirection += 1;
      sendPacket(data, pairs, excludeList);
    }
  for (i = 0; i < keywords.size(); i += 1)
    pendingSearchRequest[keywords[i]].push_back(pair); // Warning, Could create an error if does not exist
}
