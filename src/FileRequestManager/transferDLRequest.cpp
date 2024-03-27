// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:58:45 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

void			ef::FileRequestManager::transferDLRequest(s_downloadRequest const	&	request,
								  contact const			&	pair)
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
      newRequest.time = (size_t)time(NULL);
      pendingDLRequest[request.hashFile].push_back(newRequest);
      shareRequest(request, pair);
    }
  else
    shareRequest(request, pair, true);
}
