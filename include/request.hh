#ifndef			__REQUEST_HH__

#define			__REQUEST_HH__

#include		"packet.hh"

namespace		ef
{
  struct		s_request
  {
    contact		pair;
    s_downloadRequest	request;
    size_t		lastPart;
    size_t		time;
  };
}

#endif	//		__REQUEST_HH__
