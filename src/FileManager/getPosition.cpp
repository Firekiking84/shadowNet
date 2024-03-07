#include		"fileManager.hh"

size_t			ef::FileManager::getPosition()
{
  return(stream.tellg());
}
