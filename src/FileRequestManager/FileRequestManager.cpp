// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:20:42 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"fileRequestManager.hh"

ef::FileRequestManager::FileRequestManager(std::string const	&_cnf_name)
  : Social(_cnf_name)
  , lastRefresh(0)
{
  refreshFiles();
}

ef::FileRequestManager::~FileRequestManager()
{

}
