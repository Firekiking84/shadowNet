// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:16:33 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::getFile(std::vector<std::string> const			&keywordsA,
							std::map<uint64_t, fileInfoName>::iterator	&it) const
{
 std::vector<std::string>	keywordsB;

  for (; it != filesPossessed.end(); ++it)
    {
      getKeyWords(it->second.filename, keywordsB);
      if (compareKeywords(keywordsA, keywordsB))
	return;
    }
}

void			ef::FileRequestManager::getFile(std::string const	&word,
							std::map<uint64_t, fileInfoName>::iterator	&it) const
{
  std::vector<std::string>	keywordsA;

  getKeyWords(word, keywordsA);
  getFile(keywordsA, it);
}

void			ef::FileRequestManager::getFile(char const	*word,
							std::map<uint64_t, fileInfoName>::iterator	&it) const
{
  std::string		strWord;

  strWord = word;
  getFile(strWord, it);
}

void			ef::FileRequestManager::getFile(std::vector<std::string> const			&keywordsA,
							std::map<uint64_t, fileInfoPair>::iterator	&it) const
{
  std::vector<std::string>	keywordsB;

  for (; it != filesFind.end(); ++it)
    {
      getKeyWords(it->second.filename, keywordsB);
      if (compareKeywords(keywordsA, keywordsB))
	return;
    }
}

void			ef::FileRequestManager::getFile(std::string const	&word,
							std::map<uint64_t, fileInfoPair>::iterator	&it) const
{
  std::vector<std::string>	keywordsA;

  getKeyWords(word, keywordsA);
  getFile(keywordsA, it);
}

void			ef::FileRequestManager::getFile(char const	*word,
							std::map<uint64_t, fileInfoPair>::iterator	&it) const
{
  std::string		strWord;

  strWord = word;
  getFile(strWord, it);
}

