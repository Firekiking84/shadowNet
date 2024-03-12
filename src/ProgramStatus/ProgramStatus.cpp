#include		"programStatus.hh"

ef::ProgramStatus::ProgramStatus()
  : isRunning(true)
  , logFile("logs.txt", FileManager::OpenFlags::Wronly)
{
}

ef::ProgramStatus::~ProgramStatus()
{
  if (logFile.isOpen())
    logFile.close();
}
