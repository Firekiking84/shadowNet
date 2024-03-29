#include		"draw.hh"

int  			ef::get_value(int		a,
				      int		b,
				      double	ratio)
{
  return(ratio * (b - a) + a);
}
