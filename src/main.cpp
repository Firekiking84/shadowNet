#include		"shadowNet.hh"

int			main(int	ac,
			     char	**av)
{
  std::string		conf_name;

  if (ac < 2)
    {
      t_bunny_configuration	*cnf;

      conf_name = "default.dab";
      cnf = bunny_new_configuration();

      bunny_configuration_setf_int(cnf, 57005, "externalPort");
      bunny_configuration_setf_int(cnf, 48879, "internalPort");
      bunny_configuration_setf_int(cnf, 15, "limitRedirection");
      bunny_save_configuration(BC_DABSIC, conf_name.c_str(), cnf);
    }
  else
    conf_name = av[1];

  ef::ShadowNet		shadow(conf_name);
}
