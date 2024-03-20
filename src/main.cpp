// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 17:00:21 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

int			main(int	ac,
			     char	**av)
{
  std::string		conf_name;

  if (ac >= 2)
    {
      std::filesystem::path	conf(av[1]);

      if (std::filesystem::exists(av[1]))
	conf_name = av[1];
    }
  if (conf_name.size() == 0)
    {
      std::cout << "Loading default configuration !" << std::endl;
      t_bunny_configuration	*cnf;

      conf_name = "default.dab";
      cnf = bunny_new_configuration();
      bunny_configuration_setf_int(cnf, 57005, "externalPort");
      bunny_configuration_setf_int(cnf, 48879, "internalPort");
      bunny_configuration_setf_int(cnf, 15, "limitRedirection");
      bunny_save_configuration(BC_DABSIC, conf_name.c_str(), cnf);
    }

  ef::ShadowNet		shadow(conf_name);
}
