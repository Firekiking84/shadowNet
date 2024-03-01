#include		"social.hh"

void			ef::Social::loadPairs()
{
  if (!hasConf)
    return;
  char const	*	tmp;
  size_t		i;
  bool			status;

  i = 0;
  status = bunny_configuration_getf_string(cnf, &tmp, "pairs[%ld].label", i);
  while (status == true)
    {
      contact		pair;

      pair.label = tmp;
      if (bunny_configuration_getf_string(cnf, &tmp, "pairs[%ld].ip", i))
	{
	  pair.ip = tmp;
	  if (bunny_configuration_getf_int(cnf, &pair.port, "pairs[%ld].port", i))
	    {
	      newAddr(pair);
	      pairs[pair.label] = pair;
	    }
	}
      i += 1;
      status = bunny_configuration_getf_string(cnf, &tmp, "pairs[%ld].label", i);
    }
}
