// EFRITS
// project:     efDecryptor
// created on:  2023-10-25 - 16:09 +0200
// AuthorS:  thomas.barbe - Keryan.Houssin
// description: FileManager header

#ifndef			__FILEMANAGER_HH__
#define			__FILEMANAGER_HH__

#include		<string>
#include		<array>
#include		<fstream>
#include		<memory>

#include		<iostream>

namespace		ef
{
  class			FileManager
  {
   public:

    enum class		OpenFlags
      {
	Rdonly,
	Wronly,
	WronlyAppend,
	ReadWrite,
	//CreateReadWrite,
	ReadWriteAppend
      };

    enum class		SeekFlags
      {
	BEG,
	CUR,
	END
      };

    FileManager();
    FileManager(std::string	_fileName,
		OpenFlags	flags);
    ~FileManager();
    void		open(std::string const	&	_fileName,
			     OpenFlags			flags);
    void		close();
    template<typename T>
    int		read(T			&	tab);

    ssize_t		readLine(char		*	tab,
				 unsigned int		tabSize);
    int			readLine(char		*	tab,
				 unsigned int		tabSize,
				 char			delim);
    template<typename T>
    int		write(T			&	tab);

    ssize_t		write(char const	*	content,
			      size_t			len);
    ssize_t		read(char		*	content,
			     size_t			size);
    ssize_t		read(std::string	&	content,
			     size_t			size);
    void		seek(size_t 			pos,
			     SeekFlags			flag);
    size_t		getPosition();
    size_t		getFileSize();
    std::string		readFile();
    bool		isOpen();
    char const		*getFilename();

  private:
    std::fstream	stream;
    //std::ifstream instream;
    //std::ofstream outstream;
    std::string		fileName;
    int			fileSize;
  };
}; // !ef

#endif // __FILEMANAGER_HH__

