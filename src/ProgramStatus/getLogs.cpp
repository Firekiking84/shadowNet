// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:49 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"programStatus.hh"

void    		ef::ProgramStatus::getLogs(std::vector<std::string>	&	logs)
{
  std::string		log;
  ssize_t		sizeRcv;
  ssize_t		maxLogSize;

  maxLogSize = 2048;
  logFile.close();
  logFile.open("logs.txt", FileManager::OpenFlags::Rdonly);
  sizeRcv = maxLogSize;
  while (sizeRcv == maxLogSize)
    {
      log.clear();
      sizeRcv = logFile.read(log, maxLogSize);
      logs.push_back(log);
    }
  logFile.close();
  logFile.open("logs.txt", FileManager::OpenFlags::Wronly);
}
