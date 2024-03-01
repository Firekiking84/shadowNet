// EFRITS
// project:     Talk
// created on:  07/11/2023 22:35:59
// 1st author:  keryan.houssin - keryan.houssin@aldrin.efrits.fr
// description: Set the conf to an invalid status

#include		"user.hh"

void			ef::User::invalidConf()
{
  hasConf = false;
  bunny_delete_configuration(cnf);
  cnf = nullptr;
}
