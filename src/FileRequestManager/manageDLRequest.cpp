// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:11:27 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::manageDLRequest(s_downloadRequest const	&	request,
								contact const		&	pair)
{
  if (filesPossessed.find(request.hashFile) != filesPossessed.end())
    sendFile(request, pair);
  else if (filesFind.find(request.hashFile) != filesFind.end())
    {
      addLog("Transfering request to pair's file owner");
      if (!hasAlreadyRequest(request, pair))
	{
	  s_request	newRequest;

	  newRequest.pair = pair;
	  newRequest.request = request;
	  if (request.type == DL_UNIQUE_REQUEST)
	    newRequest.lastPart = request.nPart + 1;
	  else
	    newRequest.lastPart = request.nPart + (filesFind[request.hashFile].nbPart / request.nDiv);
	  pendingDLRequest[request.hashFile].push_back(newRequest);
	  shareRequest(request, pair);
	}
      else
	shareRequest(request, pair, true);
    }
  else
    {
      Packet		data;

      data.findAnswer.type = FIND_ANSWER;
      data.findAnswer.answer = 0;
      data.findAnswer.sizeFile = 0;
      data.findAnswer.hashFile = request.hashFile;
      sendPacket(data, pair);
      addLog("The file is no longer available, send negative answer !");
    }
}
