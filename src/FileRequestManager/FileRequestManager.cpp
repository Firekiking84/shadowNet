#include	"fileRequestManager.hh"

ef::FileRequestManager::FileRequestManager(std::string const	&_cnf_name)
  : Social(_cnf_name)
  , lastRefresh(0)
{
  refreshFiles();
}

ef::FileRequestManager::~FileRequestManager()
{

}
