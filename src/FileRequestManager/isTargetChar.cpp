#include		"fileRequestManager.hh"

bool			ef::FileRequestManager::isTargetChar(const char	*	targets,
							     char		testedChar,
							     bool		isNullTarget) const
{
  int			i;

  for (i = 0; targets[i] != '\0'; i += 1)
    if (targets[i] == testedChar)
      return(true);
  if (isNullTarget && testedChar == '\0')
    return(true);
  return(false);
}
