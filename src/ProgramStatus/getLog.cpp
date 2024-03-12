#include		"programStatus.hh"

std::string		ef::ProgramStatus::getLog()
{
  std::string		logs;

  logFile.close();
  logFile.open("logs.txt", FileManager::OpenFlags::Rdonly);
  logs = logFile.readFile();
  logFile.close();
  logFile.open("logs.txt", FileManager::OpenFlags::Wronly);
  return(logs);
}
