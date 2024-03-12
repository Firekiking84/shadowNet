// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:13:12 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::isFileFind(s_findRequest const	&request,
							   contact const	&pair,
							   std::vector<std::string> const	&	keywords)
{
  std::map<uint64_t, fileInfoPair>::iterator	itFind;

  itFind = filesFind.begin();
  for (getFile(keywords, itFind); itFind != filesFind.end(); getFile(keywords, ++itFind))
    {
      Packet		data;
      s_findAnswer	answer;
      std::string	description;
      size_t		i;

      answer.type = FIND_ANSWER;
      answer.answer = itFind->second.nbPart;
      answer.sizeFile = itFind->second.sizeFile;
      answer.hashFile = itFind->first;
      description = itFind->second.filename + '\0' + itFind->second.description;
      if (description.size() > 2048)
	description.resize(2048);
      memcpy(answer.description, description.c_str(), description.size());
      for (i = description.size(); i < 2048; i += 1)
	answer.description[i] = '\0';
      data.findAnswer = answer;
      sendPacket(data, pair);
    }
}
