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

  file.seek(2048 * request.nPart, FileManager::SeekFlags::BEG);
  if (request.type == DL_UNIQUE_REQUEST)
    nbToRead = 1;
  else
    nbToRead = filesPossessed[request.hashFile].nbPart / request.nDiv;
  data.download.request = request; // a vérifier si ça marche
  data.download.request.type = DL_FILE;
  for (i = 0; i < nbToRead; i += 1)
    {
      data.download.sizePart = file.read(data.dowload.part, 2048);
      if (data.download.sizePart != -1)
	sendPacket(data, pair);
      data.download.request.nPart += 1;
    }
  if (request.type != DL_UNIQUE_REQUEST && (file.getFileSize() - file.getPosition()) < 2048)
    {
      data.download.sizePart = file.read(data.dowload.part, 2048);
      if (data.download.sizePart != -1)
	sendPacket(data, pair);
    }
  file.close();
}
