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

void			ef::FileRequestManager::sendDownloadRequest(uint64_t			hashFile,
								    std::string const		&destName)
{
  if (currentDownload.find(hashFile) != currentDownload.end())
    {
      sendUser("This file is already downloading !");
      return; // log Already downloading
    }
  Packet		data;
  size_t		divSize;
  size_t		i;
  std::map<std::string, contact>::iterator	it;

  data.type = DL_REQUEST;
  data.dlRequest.nDiv = filesFind[hashFile].pairs.size();
  data.dlRequest.hashFile = hashFile;
  divSize = filesFind[hashFile].nbPart / data.dlRequest.nDiv;
  i = 0;
  for (it = filesFind[hashFile].pairs.begin();
       it != filesFind[hashFile].pairs.end();
       ++it)
    {
      data.dlRequest.nPart = i * divSize;
      sendPacket(data, it->second);
      i += 1;
    }
  std::string		str;
  Bitfield		bitPart(filesFind[hashFile].nbPart);
  size_t		remainSize;

  str = destName + ".status";
  currentDownload[hashFile].status.open(str, ef::FileManager::OpenFlags::ReadWrite);
  bitPart.Serialize(currentDownload[hashFile].status.getStream());
  str.clear();
  for (i = 0; i < 2048; i += 1)
    str.push_back('\0');
  currentDownload[hashFile].file.open(destName, ef::FileManager::OpenFlags::Wronly);
  remainSize = filesFind[hashFile].sizeFile;
  while (remainSize > 0)
    {
      if (remainSize < 2048)
	{
	  currentDownload[hashFile].file.write(str.c_str(), remainSize);
	  remainSize = 0;
	}
      else
	{
	  currentDownload[hashFile].file.write(str.c_str(), str.size());
	  remainSize -= str.size();
	}
    }
  currentDownload[hashFile].lastUpdate = (size_t)time(NULL);
  sendUser("The downloading has been successfully launched !");
}

void			ef::FileRequestManager::sendDownloadRequest(std::string const	&	filename,
								    std::string const	&	destName)
{
  std::map<uint64_t, fileInfoPair>::iterator	it;

  for (it = filesFind.begin(); it != filesFind.end(); ++it)
    {
      if (it->second.filename == filename)
	return(sendDownloadRequest(it->first, destName));
    }
  sendUser("No pair has the file you requested !");
  return; // log no pair has the file need searching before
}
