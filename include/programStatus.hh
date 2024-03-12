#ifndef					__PROGRAM_STATUS_HH__

#define					__PROGRAM_STATUS_HH__

#include				<lapin.h>
#include				<iostream>

#include				"fileManager.hh"

namespace				ef
{
  class					ProgramStatus
  {
  public:
    ProgramStatus();
    virtual ~ProgramStatus();

    std::string				getLog();
    void				addLog(const char		*	newLog);
    void				addLog(std::string const	&	newLog);
  protected:
    bool				isRunning;
  private:
    FileManager				logFile;
  };
}

#endif	//				__PROGRAM_STATUS_HH__
