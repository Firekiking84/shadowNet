// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:11:23 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"shadowNet.hh"

void		ef::ShadowNet::cmdDownloadFilename(std::string const &	buffer)
{
  std::string	filename;
  std::string	destName;
  uint64_t		hashFile;

  getParameters(buffer, hashFile, filename, destName);
  if (filename.size() > 0 && destName.size() > 0)
    createDownloadRequest(filename, destName);
  else if (hashFile > 0 && destName.size() > 0)
    createDownloadRequest(hashFile, destName);
  else
    sendUser("Missing argument : download [path/hash] [destName]");
}
