// EFRITS
// project:     Talk
// created on:  07/11/2023 22:37:18
// 1st author:  keryan.houssin - keryan.houssin@aldrin.efrits.fr
// description: Reset the struct t_bunny_configuration

#include		"user.hh"

void			ef::User::resetConf() const
 {
  bunny_delete_node(cnf, "pairs");
  bunny_delete_node(cnf, "limitIndirection");
  bunny_delete_node(cnf, "shareDir");
  bunny_delete_node(cnf, "externalPort");
  bunny_delete_node(cnf, "internalPort");
}
