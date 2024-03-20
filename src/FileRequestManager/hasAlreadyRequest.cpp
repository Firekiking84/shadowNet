// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:21 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

bool			ef::FileRequestManager::hasAlreadyRequest(s_downloadRequest const	&	request,
								  contact const			&	pair)
{
  if (pendingDLRequest.find(request.hashFile) == pendingDLRequest.end())
    return(false);
  size_t		i;

  for (i = 0; i < pendingDLRequest[request.hashFile].size(); i += 1)
    {
      if (pendingDLRequest[request.hashFile][i].pair.label == pair.label &&
	  pendingDLRequest[request.hashFile][i].request.nPart == request.nPart &&
	  pendingDLRequest[request.hashFile][i].request.nDiv == request.nDiv)
	{
	  return(true);
	}
    }
  return(false);
}
