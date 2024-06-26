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
    transferDLRequest(request, pair);
  else
    answerNoFileFound(request, pair);
}
