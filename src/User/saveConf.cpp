// EFRITS
// project:     Talk
// created on:  07/11/2023 22:37:43
// 1st author:  keryan.houssin - keryan.houssin@aldrin.efrits.fr
// description: Write the conf in a file

#include		"user.hh"

#include		<iostream>

void			ef::User::saveConf()
{
  bunny_save_configuration(BC_DABSIC, confName.c_str(), cnf);
}
