#include		"fileManager.hh"

#include		<cstdio>
#include		<cerrno>

ssize_t			ef::FileManager::read(char	*	content,
					      size_t		size)
{
  if (stream.is_open())
    {
      try
	{
	  stream.clear();
	  stream.read(content, size);
	}
      catch (const std::ios_base::failure & fail)
	{
	  // perror("Read ");
	  // std::cerr << errno << std::endl;
	  // std::cerr << fail.what() << std::endl;
	  return(0);
	}
      return(stream.gcount());
    }
  return(-1);
}

ssize_t			ef::FileManager::read(std::string	&	content,
					      size_t			size)
{
  if (stream.is_open())
    {
      try
	{
	  stream.clear();
	  stream.read(content.data(), size);
	}
      catch (const std::ios_base::failure & fail)
	{
	return(0);
	}
      return(stream.gcount());
    }
  return(-1);
}
