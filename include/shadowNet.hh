// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:28:31 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef		__SHADOW_NET_HH__

#define		__SHADOW_NET_HH__

#include	"fileRequestManager.hh"

namespace	ef
{
  class		ShadowNet : public FileRequestManager
  {
  public:
    ShadowNet(std::string const	&_cnf_name);
    ~ShadowNet();

  private:
    void	run();
    void	manageExternalInput();
    void	manageInternalInput();
    void	getParameters(std::string const	&	buffer,
			      std::string	&	str1,
			      std::string	&	str2,
			      int		&	digit) const;
    void	getParameters(std::string const	&	buffer,
			      std::string	&	str1) const;
    void	getParameters(std::string const	&	buffer,
			      uint64_t		&	opt1,
			      std::string	&	opt2,
			      std::string	&	str2) const;
    void	getParameters(std::string const &	buffer,
			      std::string	&	str1,
			      std::string	&	str2) const;
    void	sendLogs();
    void	sendAvailableCMD();
    void	cmdStatus(std::string const	&	buffer);
    void	cmdRequestfile(std::string const &	buffer);
    void	cmdRemovefriend(std::string const &	buffer);
    void	cmdForgetfile(std::string const	&	buffer);
    void	cmdDownloadFilename(std::string const &	buffer);
    void	cmdAddfriend(std::string const	&	buffer);
    void	pingPairs();
  };
}

#endif //			__SHADOW_NET_HH__

