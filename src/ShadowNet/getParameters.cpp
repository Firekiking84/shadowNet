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
      digit += buffer[i] + '0';
      if ((i + 1) < buffer.size() && buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
	digit *= 10;
    }
}
