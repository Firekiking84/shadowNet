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

void			ef::FileRequestManager::manageDLRequest(s_dowloadRequest const	&	request,
								contact const		&	pair)
{
  if (filesPossessed.find(request.hashFile) != filesPossessed.end())
    sendFile(request, pair);
  else if (filesFind.find(request.hashFile) != filesFind.end())
    {
      if (pendingDLRequest.find(request.hashFile) == pendingDLRequest.end())
	{
	  pendingDLRequest[request.hashFile].pair = pair;
	  pendingDLRequest[request.hashFile].request = request;
	  if (request.type == DL_UNIQUE_REQUEST)
	    pendingDLRequest[request.hashFile].lastPart = request.nPart + 1;
	  else
	    pendingDLRequest[request.hashFile].lastPart = request.nPart + (filesFind[hashFile].nbPart / request.nDiv);
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
    }
}
