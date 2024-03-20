// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:57:22 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"user.hh"

void			ef::User::openConf()
{
  if (hasConf)
    {
      bunny_delete_configuration(cnf);
      cnf = nullptr;
    }
  cnf = bunny_open_configuration(confName.c_str(), NULL);
  hasConf = true;
  if (!cnf)
    {
      hasConf = false;
      return; // put log
    }
  if (bunny_configuration_getf_int(cnf, &limitRedirection, "limitRedirection") == false)
    throw(std::runtime_error("Error missing argument in configuration file : No redirection limit"));
  if (bunny_configuration_getf_int(cnf, &externalPort, "externalPort") == false)
    throw(std::runtime_error("Error missing argument in configuration file : No External Port"));
  if (bunny_configuration_getf_int(cnf, &internalPort, "internalPort") == false)
    throw(std::runtime_error("Error missing argument in configuration file : No Internal Port"));
  char const	*tmp;

  if (bunny_configuration_getf_string(cnf, &tmp, "shareDir") == true)
    {
      hasShareDir = true;
      shareDir = tmp;
    }
}

