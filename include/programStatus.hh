#ifndef					__PROGRAM_STATUS_HH__

#define					__PROGRAM_STATUS_HH__

#include				<lapin.h>
#include				<iostream>

namespace				ef
{
  class					ProgramStatus
  {
  public:
    ProgramStatus();
    virtual ~ProgramStatus();

    void				printLog();
  protected:
    bool				isRunning;
  private:
    
  };
}

#endif	//				__PROGRAM_STATUS_HH__
