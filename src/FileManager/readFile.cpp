#include "fileManager.hh"
#include <vector>

std::string ef::FileManager::readFile()
{
    std::string str = "";
    std::vector<char> tab;

    if (stream.is_open())
    {
      seek(0, SeekFlags::BEG);
      tab.resize(getFileSize());
      stream.read(&tab[0], tab.size());
      str.append(&tab[0], tab.size());
    }
    return str;
}


