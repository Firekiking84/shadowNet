
// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:06:53 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::sendFile(s_downloadRequest const	&	request,
							 contact const			&	pair)
{
  FileManager	file(filesPossessed[request.hashFile].filename,
		     FileManager::OpenFlags::Rdonly);
  size_t		nbToRead;
  size_t		i;
  Packet		data;
  std::string		newLog;
  ssize_t		sizePart;

  newLog = "Send file data to " + pair.label;
  addLog(newLog);
  file.seek(request.nPart * 2048, FileManager::SeekFlags::BEG);
  if (request.type == DL_UNIQUE_REQUEST)
    nbToRead = 1;
  else
    nbToRead = filesPossessed[request.hashFile].nbPart / request.nDiv;
  data.download.request = request; // a vérifier si ça marche
  data.download.request.type = DL_FILE;
  sizePart = 1;
  for (i = 0; i < nbToRead && sizePart > 0; i += 1)
    {
      sizePart = file.read((char *)data.download.part, 2048);
      if (sizePart != -1)
	{
	  data.download.sizePart = sizePart;
	  sendPacket(data, pair);
	  //	  usleep(100);
	}
      data.download.request.nPart += 1;
    }
  if (request.type != DL_UNIQUE_REQUEST && (file.getFileSize() - file.getPosition()) < 2048)
    {
      ssize_t		sizePart;

      sizePart = file.read((char *)data.download.part, 2048);
      if (sizePart != -1)
	{
	  data.download.sizePart = sizePart;
	  sendPacket(data, pair);
	}
    }
  file.close();
}
