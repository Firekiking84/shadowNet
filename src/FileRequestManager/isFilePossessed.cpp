// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:12:14 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::isFilePossessed(s_findRequest const	&request,
								contact const		&pair,
								std::vector<std::string> const	&keywords)
{
  std::map<uint64_t, fileInfoName>::iterator	file;

  file = filesPossessed.begin();
  for (getFile(keywords, file); file != filesPossessed.end(); getFile(keywords, ++file))
    {
      Packet		data;
      s_findAnswer	answer;
      std::string	description;
      size_t		i;

      answer.type = FIND_ANSWER;
      answer.answer = file->second.nbPart;
      answer.sizeFile = file->second.sizeFile;
      answer.hashFile = file->first;
      description = file->second.filename + '\0' + file->second.description;
      if (description.size() > 2048)
	description.resize(2048);
      memcpy(answer.description, description.c_str(), description.size());
      for (i = description.size(); i < 2048; i += 1)
	answer.description[i] = '\0';
      data.findAnswer = answer;
      sendPacket(data, pair);
    }
}
