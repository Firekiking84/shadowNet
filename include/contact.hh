// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:20 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Header File of the struct contact. Struct managing the data of a
// contact

#ifndef			__CONTACT_HH__

#define			__CONTACT_HH__

#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<string>

namespace ef
{
  struct		contact
  {
    std::string		label;
    std::string		ip;
    int			port;
    struct sockaddr_in	addr;
    struct sockaddr	sAddr;

    contact();
    contact(contact const	&	other);
    ~contact();
    contact	&	operator=(contact const					&	other);
  };

  bool				operator==(contact const			&	a,
					   contact const			&	b);
}

#endif // __CONTACT_HH__
