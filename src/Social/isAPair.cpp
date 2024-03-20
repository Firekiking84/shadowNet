// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:00 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"social.hh"

bool			ef::Social::isAPair(contact	&	stranger) const
{
  std::map<std::string, contact>::const_iterator	it;

  for (it = pairs.begin(); it != pairs.end(); ++it)
    {
      contact		pair;

      pair = it->second;
      if (pair.ip == stranger.ip && pair.port == stranger.port)
	{
	  stranger = pair;
	  return(true);
	}
    }
  return(false);
}
