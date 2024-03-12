// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:09:58 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"
#include		<filesystem>

void			ef::FileRequestManager::refreshFiles()
{
  if (!hasShareDir)
    return;
  std::time_t		curTime;

  curTime = std::time(nullptr);
  if ((curTime - lastRefresh) < 60)
    return;
  lastRefresh = curTime;
  uint64_t		hashFile;
  std::string		filename;
  const std::filesystem::path sharePath(shareDir);
  filesPossessed.clear();

  for (std::filesystem::recursive_directory_iterator dir_entry = std::filesystem::recursive_directory_iterator{sharePath};
       dir_entry != std::filesystem::recursive_directory_iterator();
       ++dir_entry)
    {
      if (!std::filesystem::is_directory(*dir_entry))
	{
	  uint32_t		sizeFile;

	  filename = dir_entry->path();
	  FileManager		File(filename, FileManager::OpenFlags::Rdonly);

	  hashFile = std::hash<std::string>{}(File.readFile());
	  File.close();
	  sizeFile = std::filesystem::file_size(dir_entry->path());
	  filesPossessed[hashFile].filename = filename;
	  filesPossessed[hashFile].sizeFile = sizeFile;
	  if (sizeFile > 2048)
	    {
	      filesPossessed[hashFile].nbPart = sizeFile / 2048;
	      if (sizeFile % 2048 != 0)
		filesPossessed[hashFile].nbPart += 1;
	    }
	  else
	    filesPossessed[hashFile].nbPart = 1;
	  removeExtension(filename);
	  filename += ".sdwn";
	  if (std::filesystem::exists(filename))
	    {
	      File.open(filename, FileManager::OpenFlags::Rdonly);
	      filesPossessed[hashFile].description = File.readFile();
	      File.close();
	    }
	  else
	    filesPossessed[hashFile].description = "None";
	}
    }
}
