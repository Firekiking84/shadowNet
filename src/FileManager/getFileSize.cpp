// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:00:03 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"fileManager.hh"

size_t ef::FileManager::getFileSize()
{
  size_t	total;
  size_t	previousPos;

  previousPos = getPosition();
  seek(0, SeekFlags::END);
  total = getPosition();
  seek(previousPos, SeekFlags::BEG);
  return(total);
    // int total = 0;
    // std::array<char, 1024> tab;
    // int lu = 1;

    // while (lu != 0)
    // {
    //     stream.read(&tab[0], 1024);
    //     lu = stream.gcount();
    //     total += lu;
    // }
    // seek(0);
    // return total;
}


