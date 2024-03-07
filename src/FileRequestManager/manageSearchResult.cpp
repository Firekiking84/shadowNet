// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:10:17 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"fileRequestManager.hh"

//	t e s t \0
//	0 1 2 3 4
// size 5
//

void		ef::FileRequestManager::manageSearchResult(s_findAnswer const	&	answer,
							   contact const	&	pair)
{
  Packet	data;
  size_t	i;
  std::vector<std::string>	keywords;
  std::string	filename;

  if (answer.answer == 0)
    {
      if (filesFind.find(answer.hashFile) != filesFind.end())
	{
	  filesFind[answer.hashFile].pairs.erase(pair.label);
	  if (filesFind[answer.hashFile].pairs.count() == 0)
	    {
	      filesFind.erase(answer.hashFile);
	      if (pendingDLRequest.find(answer.hashFile) == pendingDLRequest.end())
		pendingDLRequest.erase(answer.hashFile);
	    }
	}
    }
  else
    {
      for (i = 0; i < 2048 && answer.description[i] != '\0'; i += 1)
	filename.push_back(answer.description[i]);
      filename.push_back('\0');
      getKeyWords(filename, keywords);
      for (i = 0; i < keywords.size(); i += 1)
	{
	  if (pendingSearchRequest.find(keywords[i]) != pendingSearchRequest.end())
	    {
	      data.findAnswer = answer;
	      sendPacket(data, pendingSearchRequest[answer.hashFile], pair);
	      pendingSearchRequest.erase(answer.hashFile);
	    }
	}
      if (filesFind.find(answer.hashFile) == filesFind.end())
	{
	  fileInfoPair	fileInfo;
	  std::string	description;

	  description = answer.description; // attention \0
	  description = description.substr(filename.size());
	  fileInfo.owners[pair.label] = pair;
	  fileInfo.filename = filename;
	  fileInfo.description = description;
	  fileInfo.nbPart = answer.answer;
	  fileInfo.lastUpdate = reinterpret_cast<size_t>(time(NULL));
	  filesFind[answer.hashFile] = fileInfo;
	}
      else
	{
	  filesFind[answer.hashFile].owners[pair.label] = pair;
	  filesFind[answer.hashFile].lastUpdate = reinterpret_cast<size_t>(time(NULL));
	}
    }
}
