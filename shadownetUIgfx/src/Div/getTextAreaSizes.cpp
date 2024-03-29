#include		"div.hh"

void			ef::Div::getTextAreaSizes(int			&nbCharMax,
						  int			&nbLinesMax,
						  std::string const	&text) const
{
  size_t		i;
  int			nbChar;

  nbChar = 0;
  nbCharMax = 0;
  nbLinesMax = 1;
  for (i = 0; i < text.size(); i += 1)
    {
      if (text[i] == '\n')
	{
	  nbLinesMax += 1;
	  if (nbChar > nbCharMax)
	    nbCharMax = nbChar;
	  nbChar = 0;
	}
      else
	nbChar += 1;
    }
  if (nbChar > nbCharMax)
    nbCharMax = nbChar;

}
