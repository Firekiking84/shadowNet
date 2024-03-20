#ifndef		__FILE_INFO_HH__

#define		__FILE_INFO_HH__

#include	"contact.hh"

#include	<map>
#include	<string>

namespace	ef
{
  struct		fileInfoName
  {
    std::string	filename;
    std::string	description;
    uint64_t	sizeFile = 0;
    uint32_t	nbPart = 0;
  };

  struct		fileInfoPair
  {
    std::map<std::string, contact>	pairs;
    std::string	filename;
    std::string	description;
    uint64_t	sizeFile = 0;
    uint32_t	nbPart = 0;
    size_t	lastUpdate = 0;
  };
}

#endif	//	__FILE_INFO_HH__
