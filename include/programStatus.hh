#ifndef					__PROGRAM_STATUS_HH__

#define					__PROGRAM_STATUS_HH__

#include				<lapin.h>
#include				<iostream>
#include				<vector>

#include				"fileManager.hh"

namespace				ef
{
  class					ProgramStatus
  {
  public:
    ProgramStatus();
    virtual ~ProgramStatus();

    void				getLogs(std::vector<std::string> &	logs);
    void				addLog(const char		*	newLog);
    void				addLog(std::string const	&	newLog);
  protected:
    bool				isRunning;
  private:
    FileManager				logFile;
  };
}

#endif	//				__PROGRAM_STATUS_HH__
