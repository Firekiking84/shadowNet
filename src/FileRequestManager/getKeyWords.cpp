// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:16:09 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::getKeyWords(std::string const			&word,
							    std::vector<std::string>		&keywords) const
{
  size_t			i;
  std::string			keyword;

  keywords.clear();
  for (i = 0; i < word.size() && word[i] != '\0'; i += 1)
    {
      if ((word[i] == ' ' || word[i] == '\0') && keyword.size() > 0)
	{
	  keywords.push_back(keyword);
	  keyword.clear();
	}
      else if (word[i] != ' ' && word[i] != '\0')
	keyword.push_back(word[i]);
    }
}

void			ef::FileRequestManager::getKeyWords(char const			*word,
							    std::vector<std::string>	&keywords) const
{
  std::string		strWord;

  strWord = word;
  getKeyWord(strWord, keywords);
}
