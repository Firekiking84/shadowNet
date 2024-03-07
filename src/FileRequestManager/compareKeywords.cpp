// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:21:07 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

bool			ef::FileRequestManager::compareKeywords(std::vector<std::string> const	&a,
								std::vector<std::string> const	&b) const
{
  size_t		iA;
  size_t		iB;

  for (iA = 0; iA < a.size(); iA += 1)
    {
      for (iB = 0; iB < b.size(); iB += 1)
	{
	  if (a[iA] == b[iB])
	    return(true);
	}
    }
  return(false);
}
