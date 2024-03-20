// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:58:44 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"shadowNet.hh"

void			ef::ShadowNet::getParameters(std::string const	&	buffer,
						     std::string	&	str1) const
{
  size_t		i;

  str1.clear();
  for (i = 0; i < buffer.size() && buffer[i] != ' ' && buffer[i] != '\0'; i += 1);
  for (i += 1; i < buffer.size() && buffer[i] != ' ' && buffer[i] != '\0'; i += 1)
    str1.push_back(buffer[i]);
}

void			ef::ShadowNet::getParameters(std::string const	&	buffer,
						     std::string	&	str1,
						     std::string	&	str2) const
{
  size_t		i;

  for (i = 0; i < buffer.size() && buffer[i] != ' '; i += 1);
  for (i += 1; i < buffer.size() && buffer[i] != ' '; i += 1)
    str1.push_back(buffer[i]);
  for (i += 1; i < buffer.size() && buffer[i] != ' '; i += 1)
    str2.push_back(buffer[i]);
}

void			ef::ShadowNet::getParameters(std::string const	&	buffer,
						     uint64_t		&	opt1,
						     std::string	&	opt2,
						     std::string	&	str2) const
{
  size_t			i;
  bool				isOpt1;

  isOpt1 = true;
  for (i = 0; i < buffer.size() && buffer[i] != ' '; i += 1);
  for (i += 1; i < buffer.size() && buffer[i] !=  ' '; i += 1)
    {
      opt2.push_back(buffer[i]);
      if (isOpt1)
	{
	  if (buffer[i] < '0' || buffer[i] > '9')
	    isOpt1 = false;
	  else
	    {
	      opt1 += buffer[i] - '0';
	      if ((i + 1) < buffer.size() && buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
		opt1 *= 10;
	    }
	}
    }
  for(i += 1; i < buffer.size() && buffer[i] != ' ' && buffer[i] != '\0'; i += 1)
    str2.push_back(buffer[i]);
  if (isOpt1)
    opt2.clear();
  else
    opt1 = 0;
}

void			ef::ShadowNet::getParameters(std::string const	&	buffer,
						     std::string	&	str1,
						     std::string	&	str2,
						     int		&	digit) const
{
  size_t		i;

  str1.clear();
  str2.clear();
  digit = 0;
  for (i = 0; i < buffer.size() && buffer[i] != ' ' && buffer[i] != '\0'; i += 1);
  for(i += 1; i < buffer.size() && buffer[i] != ' ' && buffer[i] != '\0'; i += 1)
    str1.push_back(buffer[i]);
  for (i += 1; i < buffer.size() && buffer[i] != ' ' && buffer[i] != '\0'; i += 1)
    str2.push_back(buffer[i]);
  for (i += 1; i < buffer.size() && buffer[i] >= '0' && buffer[i] <= '9'; i += 1)
    {
      digit += buffer[i] - '0';
      if ((i + 1) < buffer.size() && buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
	digit *= 10;
    }
}
