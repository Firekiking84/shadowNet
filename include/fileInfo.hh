#ifndef		__FILE_INFO_HH__

#define		__FILE_INFO_HH__

struct		fileInfoName
{
  std::string	filename;
  std::string	description;
  uint64_t	sizeFile;
  uint32_t	nbPart;
};

struct		fileInfoPair
{
  std::map<std::string, contact>	pairs;
  std::string	filename; //optional // à voir
  std::string	description;
  uint64_t	sizeFile;
  uint32_t	nbPart;
  size_t	lastUpdate;
};

#endif	//	__FILE_INFO_HH__
