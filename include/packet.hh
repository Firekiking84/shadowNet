#ifndef				__DATA_STRUCT_HH__

#define				__DATA_STRUCT_HH__

namespace			ef
{
  enum				requestType
    {
      FIND_REQUEST = 0,
      FIND_ANSWER,
      DL_REQUEST,
      DL_UNIQUE_REQUEST,
      DL_FILE,
      PING,
      PONG
    };

  struct			s_findRequest
  {
    requestType			type;
    uint8_t			nbRedirection;
    uint8_t			limitRedirection;
    uint8_t			name[2048];
  };

  struct			s_findAnswer
  {
    requestType			type;
    uint32_t			answer; // 0 = not find, n = n tronçon
    uint32_t			sizeFile;
    uint64_t			hashFile;
    uint8_t			description[2048];
  };

  struct			s_downloadRequest
  {
    requestType			type;
    uint32_t			nPart;
    uint32_t			nDiv;
    uint64_t			hashFile;
  };

  struct			s_download
  {
    s_downloadRequest		request;
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
