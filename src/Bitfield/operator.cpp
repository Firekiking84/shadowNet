#include			"bitfield.hpp"

std::ostream			&operator<<(std::ostream	&os,
					    const ef::Bitfield	&bf)
{
  bf.Print(os);
  return (os);
}
