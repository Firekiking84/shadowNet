#ifndef				__DATA_STRUCT_HH__

#define				__DATA_STRUCT_HH__

namespace			ef
{
  enum				requestType
    {
      FIND_REQUEST = 0,
      FIND_ANSWER,
      DL_REQUEST,
      DL_FILE,
      PING,
      PONG
    };

  struct			s_findRequest
  {
    requestType			type;
    uint8_t			nbRedirection;
    uint64_t			hashName;
  };

  struct			s_findAnswer
  {
    requestType			type;
    uint8_t			answer; //0 = not find, 1 = find
    uint64_t			hashName;
  };

  struct			s_downloadRequest
  {
    requestType			type;
    uint16_t			nTronçon;
    uint64_t			hashName;
  };

  struct			s_download
  {
    s_downloadRequest		request;
    uint64_t			hashName;
    uint32_t			sizePart;
    uint8_t			part[2048];
  };

  union				Packet
  {
    requestType			type;
    s_findRequest		findRequest;
    s_findAnswer		findAnswer;
    s_downloadRequest		dlRequest;
    s_download			download;
  };

}

#endif //	__DATA_STRUCT_HH__
