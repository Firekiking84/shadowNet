// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:33 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileManager.hh"
#include		<cstdio>

ssize_t			ef::FileManager::write(char const	*	content,
					       size_t			len)
{
  if (stream.is_open())
    {
      try
	{
	  stream.clear();
	  stream.write(content, len);
	}
      catch (const std::ios_base::failure & fail)
	{
	  perror("Write ");
	  std::cerr << fail.what() << std::endl;
	  len = 0;
	}
      return(len);
    }
  return(-1);
}
