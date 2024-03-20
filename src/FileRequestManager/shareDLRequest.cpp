// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:10 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::shareDLRequest(uint64_t	hashFile)
{
  Packet		data;
  size_t		divSize;
  size_t		i;
  std::map<std::string, contact>::iterator	it;

  data.type = DL_REQUEST;
  data.dlRequest.nDiv = filesFind[hashFile].pairs.size();
  data.dlRequest.hashFile = hashFile;
  divSize = filesFind[hashFile].nbPart / data.dlRequest.nDiv;
  i = 0;
  for (it = filesFind[hashFile].pairs.begin();
       it != filesFind[hashFile].pairs.end();
       ++it)
    {
      data.dlRequest.nPart = i * divSize;
      sendPacket(data, it->second);
      i += 1;
    }
}
