// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:52 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"programStatus.hh"

void			ef::ProgramStatus::addLog(char const		*	newLog)
{
  std::string		newStrLog;

  newStrLog = newLog;
  addLog(newStrLog);
}

void			ef::ProgramStatus::addLog(std::string const	&	newLog)
{
  std::string		beautyLog;

  beautyLog = newLog + '\n';
  logFile.write(beautyLog.c_str(), beautyLog.size());
}
