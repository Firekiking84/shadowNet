#include	"draw.hh"

double		ef::get_ratio(int		a,
			      int		b,
			      int		x)
{
  return((double)(x - a) / (b - a));
}
