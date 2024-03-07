#include "fileManager.hh"

void ef::FileManager::seek(size_t	pos,
			   SeekFlags	flags)
{
  do
    {
      stream.clear();
      if (flags == SeekFlags::END)
	stream.seekg(pos, std::ios_base::end);
      else if (flags == SeekFlags::CUR)
	stream.seekg(pos, std::ios_base::cur);
      else
	stream.seekg(pos, std::ios_base::beg);
    }
  while (stream.fail());
}

