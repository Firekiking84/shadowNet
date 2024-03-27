// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:52:14 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	       "fileRequestManager.hh"

void			ef::FileRequestManager::answerNoFileFound(s_downloadRequest const	&	request,
								  contact const			&	pair)
{
  Packet		data;

  data.findAnswer.type = FIND_ANSWER;
  data.findAnswer.answer = 0;
  data.findAnswer.sizeFile = 0;
  data.findAnswer.hashFile = request.hashFile;
  sendPacket(data, pair);
  addLog("The file is no longer available, send negative answer !");
}
