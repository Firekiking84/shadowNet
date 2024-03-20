// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:53 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileManager.hh"

void ef::FileManager::open(std::string const &	_fileName,
                           OpenFlags flags)
{
  fileName = _fileName;
  stream.clear();
  if (stream.is_open())
    stream.close();
  if (flags == OpenFlags::Rdonly)
    stream.open(&fileName[0], stream.in);
  else if (flags == OpenFlags::Wronly)
    stream.open(&fileName[0], stream.out | stream.trunc);
  else if (flags == OpenFlags::WronlyAppend)
    stream.open(&fileName[0], stream.out | stream.app);
  else if (flags == OpenFlags::ReadWrite)
    {
      stream.open(&fileName[0], stream.in | stream.out | stream.trunc);
      /*if (stream.is_open())
	std::cout << "yes!\n";
        else
        std::cout << "NOOOOOOO!\n";*/
    }
  else if (flags == OpenFlags::ReadWriteAppend)
    stream.open(&fileName[0], stream.in | stream.out | stream.app);
  if  (!stream.is_open())
    std::cerr << "Cannot open this file" << std::endl;
}
