// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:57:10 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"user.hh"

ef::User::User(std::string const	&	_cnf_name)
  : ProgramStatus()
  , hasConf(false)
  , cnf(nullptr)
  , confName(_cnf_name)
  , hasShareDir(false)
  , shareDir()
{
  openConf();
}

ef::User::~User()
{
  saveConf();
  if (hasConf)
    bunny_delete_configuration(cnf);
}
