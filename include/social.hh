#ifndef		__SOCIAL_HH__

#define		__SOCIAL_HH__

#include	"networkUDP.hh"


namespace	ef
{
  class		Social : public NetworkUDP
  {
  public:
    Social(std::string const	&		_cnf_name);
    virtual ~Social();

    void	addPair(std::string const	&ip,
			std::string const	&label,
			int const		_port);
    void	addPair(contact			newPair);
    void	removePair(std::string const	&label);
    bool	isAPair(contact			&stranger) const;
    
  protected:
    std::map<std::string, contact>		pairs;
  private:
    void	loadPairs();
    void	savePairs();
  };
}

#endif	  //	__SOCIAL_HH__
