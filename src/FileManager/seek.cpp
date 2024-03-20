// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:35 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "fileManager.hh"

void ef::FileManager::seek(size_t	pos,
			   SeekFlags	flags)
{
  stream.clear();
  if (flags == SeekFlags::END)
    stream.seekg(pos, std::ios_base::end);
  else if (flags == SeekFlags::CUR)
    stream.seekg(pos, std::ios_base::cur);
  else
    stream.seekg(pos, std::ios_base::beg);
}

