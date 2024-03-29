#include	"div.hh"

int		ef::Div::divideSup(int	num,
				   int	factor) const
{
  int		result;

  result = num / factor;
  if ((num % factor) != 0)
    result += 1;
  return(result);
}
