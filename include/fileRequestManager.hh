#ifndef		__FILE_REQUEST_MANAGER_HH__

#define		__FILE_REQUEST_MANAGER_HH__

#include	"social.hh"
#include	<ctime>

namespace	ef
{
  class		FileRequestManager : public Social
  {
  public:
    FileRequestManager(std::string const	&_cnf_name);
    virtual ~FileRequestManager();

    void	sendSearchRequest(std::string const	&filename);
    void        manageSearchRequest(s_findRequest const	&request);
    void	manageSearchResult(s_findAnswer const	&answer);
    void	sendDownloadRequest(std::string const	&filename);
    void	manageDLRequest(s_downloadRequest const	&request);
    void	manageDownload(s_download const		&answer);
    void	forgetFile(std::string const		&filename);
    void        getStatus(std::string const		&filename);
    void	refreshFiles();

  private:
    std::time_t					lastRefresh;
    std::map<uint64_t, std::string>		filesPossessed;
    // key = hashFilename; value = filename

    std::map<uint64_t, std::vector<contact>>	filesFind;
    // key = hashFileName; value = pair who has the file

    std::map<uint64_t, std::vector<contact>>	pendingSearchRequest;
    // key = hashFilename; value = Pair who want the file
  };
}

#endif //	__FILE_REQUEST_MANAGER_HH__
