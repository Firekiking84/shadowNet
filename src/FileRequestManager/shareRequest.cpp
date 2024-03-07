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

void			ef::FileRequestManager::shareRequest(s_dowloadRequest const	&	request,
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
	sendPacket(data, fileFind[request.hashFile].pairs.end(), pair); //end because the most recent
      else
	sendPacket(data, fileFind[request.hashFile].pairs, pair);
    }
  else
    {
      divSize = filesFind[hashFile].nbPart / request.nDiv;
      data.dlRequest = request;
      data.dlRequest.nDiv = request.nDiv * filesFind[request.hashFile].pairs.count();
      i = 0;
      for (it = fileFind[request.hashFile].pairs.begin();
	   it != fileFind[request.hashFile].pairs.end();
	   ++ it)
	{
	  data.dlRequest.nPart = request.nPart + (divSize * i);
	  i += 1;
	  sendPacket(data, it->second, pair);
	}
    }
}
