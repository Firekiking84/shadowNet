// EFRITS
// project:     Talk
// created on:  2023-11-03 - 12:28 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Header File of User's class. Class managing User data

#ifndef					__USER_HH__

#define					__USER_HH__

#include				"programStatus.hh"

namespace ef
{
  class					User : public	ProgramStatus
  {
  public:
    User(std::string const		&_cnf_name);
    virtual ~User();

    void				invalidConf();
    void				openConf();
    void				saveConf();
    void				resetConf() const;
  protected:
    int					externalPort;
    int					internalPort;
    bool				hasConf;
    t_bunny_configuration	*	cnf;
    std::string				confName;
    bool				hasShareDir;
    std::string				shareDir;
      private:
  };
}

#endif // __USER_HH__
