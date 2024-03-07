#ifndef		__DL_INFO_HH__

#define		__DL_INFO_HH__

#include	"fileManager.hh"

namespace	ef
{
  struct	DLInfo
  {
    FileManager	status;
    FileManager	file;
    size_t	lastUpdate;
  };
}

#endif	//	__DL_INFO_HH__
