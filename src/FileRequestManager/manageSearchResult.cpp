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
	  addLog("One pair has lose a file !");
	  if (filesFind[answer.hashFile].pairs.size() == 0)
	    {
	      filesFind.erase(answer.hashFile);
	      addLog("The file has been definitely lose on your network !");
	      if (pendingDLRequest.find(answer.hashFile) == pendingDLRequest.end())
		{
		  addLog("Cancelling pending download requests !");
		  data.findAnswer = answer;
		  for (i = 0; i < pendingDLRequest[answer.hashFile].size(); i += 1)
		    sendPacket(data, pendingDLRequest[answer.hashFile][i].pair);
		  pendingDLRequest.erase(answer.hashFile);
		}
	      if (currentDownload.find(answer.hashFile) != currentDownload.end())
	      {
		addLog("Cancelling download !");
		currentDownload.erase(answer.hashFile);
	      }
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
	      addLog("Send search results to concerned pairs");
	      data.findAnswer = answer;
	      sendPacket(data, pendingSearchRequest[keywords[i]], pair);
	      pendingSearchRequest.erase(keywords[i]);
	    }
	}
      if (filesFind.find(answer.hashFile) == filesFind.end())
	{
	  fileInfoPair	fileInfo;
	  std::string	description;

	  extractDescription(description, (char *)answer.description);
	  fileInfo.pairs[pair.label] = pair;
	  fileInfo.filename = filename;
	  fileInfo.description = description;
	  fileInfo.nbPart = answer.answer;
	  fileInfo.lastUpdate = (size_t)time(NULL);
	  filesFind[answer.hashFile] = fileInfo;
	  description = filename + " has been find on your network !";
	  addLog(description);
	}
      else
	{
	  std::string	newLog;

	  filesFind[answer.hashFile].pairs[pair.label] = pair;
	  filesFind[answer.hashFile].lastUpdate = (size_t)time(NULL);
	  newLog = "Another pair has find : " + filesFind[answer.hashFile].filename;
	  addLog(newLog);
	}
    }
}
