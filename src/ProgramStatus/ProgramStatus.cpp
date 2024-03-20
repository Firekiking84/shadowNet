// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:47 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

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
