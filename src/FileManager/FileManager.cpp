// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:00:09 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"fileManager.hh"

ef::FileManager::FileManager()
    : stream(),
      fileName(),
      fileSize(-1)
{
  stream.exceptions(std::ifstream::failbit);
}

ef::FileManager::FileManager(std::string _fileName,
                             OpenFlags flags)
    : stream(),
      fileName(_fileName),
      fileSize(-1)
{
    open(fileName, flags);
}

ef::FileManager::~FileManager()
{
  if (isOpen())
    close();
}

