// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:07:58 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::sendDownloadRequest(uint64_t			hashFile)
{
  if (filesFind.find(hashFile) == filesFind.end())
    return; // log No pair has this file
  if (currentDownload.find(hashFile) != currentDownload.end())
    return; // log Already downloading
  Packet		data;
  size_t		divSize;
  size_t		i;
  std::map<std::string, contact>::iterator	it;

  data.type = DL_REQUEST;
  data.nDiv = filesFind[hashFile].pairs.count();
  divSize = filesFind[hashFile].nbPart / data.nDiv;
  i = 0;
  for (it = filesFind[hashFile].pairs.begin();
       it != filesFind[hashFile].pairs.end();
       ++it)
    {
      data.nPart = i * divSize;
      sendPacket(data, it->second);
      i += 1;
    }
  std::string		str;

  str = filesFind[hashFile].filename + ".status";
  currentDownload[hashFile].status.open(str, ef::FileManager::OpenFlags::ReadWrite);
  str.clear();
  for (i = 0; i < filesFind[hashFile].nbPart; i += 1)
    str.push_back('0');
  currentDownload[hashFile].status.write(str.c_str(), str.size());
  currentDownload[hashFile].file.open(filesFind[hashFile].filename, ef::FileManager::OpenFlags::Wronly);
  for (; i < 2048; i += 1)
    str.push_back('0');
  for (i = 0; i < filesFind[hashFile].nbPart; i += 1)
    {
      if (i == filesFind[hashFile].nbPart - 1)
	currentDownload[hashFile].file.write(str.c_str, filesFind[hashFile].sizeFile % 2048);
      else
	currentDownload[hashFile].file.write(str.c_str, 2048);
    }
  currentDownload[hashFile].lastUpdate = reinterpret_cast<size_t>(time(NULL));
}

void			ef::FileRequestManager::sendDownloadRequest(std::string const	&	filename)
{
  std::map<uint64_t, fileInfoPair>::iterator	it;

  for (it = filesFind.begin(); it != filesFind.end(); ++it)
    {
      if (it->second.filename == filename)
	return(sendDownloadRequest(it->first));
    }
  return; // log no pair has the file need searching before
}
