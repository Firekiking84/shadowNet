#include		"fileManager.hh"

bool			ef::FileManager::isOpen()
{
  return(stream.is_open());
}
