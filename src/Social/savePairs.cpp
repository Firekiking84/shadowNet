// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:57:36 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"social.hh"

void			ef::Social::savePairs()
{
  std::map<std::string, contact>::iterator	it;
  size_t		i;

  bunny_delete_node(cnf, "pairs");
  i = 0;
  for (it = pairs.begin(); it != pairs.end(); ++it)
    {
      bunny_configuration_setf_string(cnf, it->second.label.c_str(), "pairs[%ld].label", i);
      bunny_configuration_setf_string(cnf, it->second.ip.c_str(), "pairs[%ld].ip", i);
      bunny_configuration_setf_int(cnf, it->second.port, "pairs[%ld].port", i);
      i += 1;
    }
}
