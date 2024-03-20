// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:04:00 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::shareRequest(s_downloadRequest const	&	request,
							     contact const		&	pair,
							     bool				isBroadcast)
{
  Packet		data;
  size_t		divSize;
  size_t		i;
  std::map<std::string, contact>::iterator	it;

  if (request.type == DL_UNIQUE_REQUEST)
    {
      data.dlRequest = request;
      if (!isBroadcast)
	sendPacket(data, filesFind[request.hashFile].pairs.rbegin()->second, pair); //end because the most recent
      else
	sendPacket(data, filesFind[request.hashFile].pairs, pair);
    }
  else
    {
      data.dlRequest = request;
      data.dlRequest.nDiv *= filesFind[request.hashFile].pairs.size();
      divSize = filesFind[request.hashFile].nbPart / request.nDiv;
      i = 0;
      for (it = filesFind[request.hashFile].pairs.begin();
	   it != filesFind[request.hashFile].pairs.end();
	   ++ it)
	{
	  data.dlRequest.nPart = request.nPart + (divSize * i);
	  i += 1;
	  sendPacket(data, it->second, pair);
	}
    }
}
