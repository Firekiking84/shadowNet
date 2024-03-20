// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:44 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "fileManager.hh"
#include <vector>

void	 ef::FileManager::readFile(std::string &	dest)
{
  if (stream.is_open())
    {
      seek(0, SeekFlags::BEG);
      dest.resize(getFileSize());
      try {
	stream.read(dest.data(), dest.size());
      } catch (std::exception &e) {
	std::cout << e.what() << std::endl;
      }
    }
}


