#include		"fileRequestManager.hh"

void			ef::FileRequestManager::extractDescription(std::string	&	dest,
								   const char	*	description)
{
  int			i;

  for (i = 0; description[i] != '\0'; i += 1);
  dest = &description[i + 1];
}
