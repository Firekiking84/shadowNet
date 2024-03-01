#ifndef				__SHADOW_NET_HH__

#define				__SHADOW_NET_HH__

#include			"fileRequestManager.hh"

namespace			ef
{
  class				ShadowNet : public FileRequestManager
  {
  public:
    ShadowNet(std::string const	&_cnf_name);
    ~ShadowNet();
    
  private:
    void			run();
    void			manageExternalInput();
    void			manageInternalInput();
    void			getParameters(std::string const	&	buffer,
					      std::string	&	str1,
					      std::string	&	str2,
					      int		&	digit) const;
    void			getParameters(std::string const	&	buffer,
					      std::string	&	str1) const;
  };
}

#endif //			__SHADOW_NET_HH__
