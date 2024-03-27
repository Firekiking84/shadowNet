// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:06:37 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef		__FILE_REQUEST_MANAGER_HH__

#define		__FILE_REQUEST_MANAGER_HH__

#include	"social.hh"
#include	"fileManager.hh"
#include	"fileInfo.hh"
#include	"bitfield.hpp"
#include	"DLInfo.hh"
#include	"request.hh"

#include	<ctime>
#include	<filesystem>
#include	<bitset>

namespace	ef
{
  class		FileRequestManager : public Social
  {
  public:
    FileRequestManager(std::string const			&_cnf_name);
    virtual ~FileRequestManager();

    void	sendSearchRequest(std::string const		&filename,
				  std::map<std::string, std::string> const	&excludeList,
				  int				nbRedirect = -1,
				  int				limit = -2);
    void	sendSearchRequest(std::string const		&filename,
				  std::vector<contact> const	&excludeList,
				  int				nbRedirect = -1,
				  int				limit = -2);
    void	sendSearchRequest(std::string const		&filename,
				  contact const			&excludeContact,
				  int				limit = -2,
				  int				nbRedirect = -1);
    void	sendSearchRequest(std::string const		&filename,
				  int				nbRedirect = -1,
				  int				limit = -2);
    //limit = -1 : no limit; limit = -2 = user conf limit

    void        manageSearchRequest(s_findRequest const		&request,
				    contact const		&pair);
    void	manageSearchResult(s_findAnswer const		&answer,
				   contact const		&pair);
    void	createDownloadRequest(uint64_t			hashFile,
				      std::string const		&destName);
    void	createDownloadRequest(std::string const		&filename,
				      std::string const		&destName);
    void	manageDLRequest(s_downloadRequest const		&request,
				contact const			&pair);
    void	manageDownload(s_download const			&answer,
			       contact const		&pair);
    void	forgetFile(std::string const			&filename);
    int		getStatus(uint64_t				hashFile,
			  std::string				&status);
    int		getStatus(uint64_t				hashFile);
    void        getStatus(std::string const			&filename);
    void	refreshFiles();

  protected:
    void	timeToDie();

  private:
    std::time_t					lastRefresh;
    std::map<uint64_t, fileInfoName>		filesPossessed;
    // key = hashFile; value = filename

    std::map<uint64_t, fileInfoPair>		filesFind;
    // key = hashFile; value = pair who has the file

    std::map<std::string, std::vector<contact>>	pendingSearchRequest;
    // key = keyword, value = pair who search it

    std::map<uint64_t, std::vector<s_request>>	pendingDLRequest;
    // key = hashFile, value = requests

    std::map<std::string, size_t>		myPendingRequest;
    // key = filename; value = time Request was send

    std::map<uint64_t, DLInfo>			currentDownload;
    // key = hashFile; value = FD receive status & file

    void	extractDescription(std::string			&dest,
				   const char			*description);
    bool	isTargetChar(const char				*targets,
			     char				testedChar,
			     bool				isNullTarget = true) const;
    void	getKeyWords(std::string const			&word,
			    std::vector<std::string>		&keywords) const;
    void	getKeyWords(char const				*word,
			    std::vector<std::string>		&keywords) const;
    void	getFile(std::vector<std::string> const				&keywordsA,
			std::map<uint64_t, fileInfoName>::iterator		&it) const;
    void	getFile(std::string const					&word,
			std::map<uint64_t, fileInfoName>::iterator		&it) const;
    void       	getFile(char const						*word,
			std::map<uint64_t, fileInfoName>::iterator		&it) const;
    void	getFile(std::vector<std::string> const				&keywordsA,
			std::map<uint64_t, fileInfoPair>::iterator		&it) const;
    void	getFile(std::string const					&word,
			std::map<uint64_t, fileInfoPair>::iterator		&it) const;
    void       	getFile(char const						*word,
			std::map<uint64_t, fileInfoPair>::iterator		&it) const;


    bool	compareKeywords(std::vector<std::string> const	&a,
				std::vector<std::string> const	&b) const;
    void	removeExtension(std::string			&str) const;
    void	sendFile(s_downloadRequest const		&	request,
			 contact const				&	pair);
    void	shareRequest(s_downloadRequest const		&	request,
			     contact const			&	pair,
			     bool					isBroadcast = false);
    void	isFilePossessed(s_findRequest const		&	request,
				contact const			&	pair,
				std::vector<std::string> const	&	keywords);
    void        isFileFind(s_findRequest const			&	request,
			   contact const			&	pair,
			   std::vector<std::string> const	&	keywords);
    bool	hasAlreadyRequest(s_downloadRequest const	&	request,
				  contact const			&	pair);
    void	shareDLRequest(uint64_t					hashFile);
    void	answerNoFileFound(s_downloadRequest const	&	request,
				  contact const			&	pair);
    void	transferDLRequest(s_downloadRequest const	&	request,
				  contact const			&	pair);
    void	transferPacketFile(s_download const		&	download,
				   contact const		&	pair);
    void	endDownload(s_download const			&	download);
    void	proceedDownload(s_download const		&	download,
				contact const			&	pair);
  };
}

#endif //	__FILE_REQUEST_MANAGER_HH__
