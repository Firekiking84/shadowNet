// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:38 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "fileManager.hh"

ssize_t ef::FileManager::readLine(char *tab,
				  unsigned int tabSize)
{
    if (stream.is_open())
    {
      try
	{
	  stream.getline(tab, tabSize);
	}
      catch (const std::ios_base::failure & fail)
	{
	  stream.clear();
	  return(-1);
	}
      return(stream.gcount());
    }
    return -1;
}


