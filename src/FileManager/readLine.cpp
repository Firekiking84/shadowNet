#include "fileManager.hh"

ssize_t ef::FileManager::readLine(char *tab,
				  unsigned int tabSize)
{
    if (stream.is_open())
    {
      try
	{
	  stream.getline(tab, tabSize);
	}
      catch (const std::ios_base::failure & fail)
	{
	  stream.clear();
	  return(-1);
	}
      return(stream.gcount());
    }
    return -1;
}


