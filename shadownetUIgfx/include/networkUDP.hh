// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:18 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Header File of NetworkUDP. Class managing the network part of
// the program

#ifndef			__NETWORK_UDP_HH__

#define			__NETWORK_UDP_HH__

#include		"contact.hh"

#include		<poll.h>
#include		<vector>
#include		<cstring>
#include		<map>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>

namespace ef
{
  class		NetworkUDP
  {
  public:
    enum class		Mode
      {
	WRITE,
	READ,
	READ_WRITE
      };

    NetworkUDP(int			port,
	       std::string const	&ipSoft,
	       int			portSoft);
    ~NetworkUDP();
    int 		can(Mode						mode,
			    int							target = -1,
			    int							timeout = -1);
    bool		readFd(std::string				&	buffer,
			       size_t						sizeBuffer,
			       int						fd);
    ssize_t		recvFromSoft(std::string			&	buffer);
    void		sendSoft(std::string const			&	msg);
    void		sendUser(std::string const			&	msg);

  protected:
    contact		software;
    struct pollfd	pfd[1];
  private:
    int			testAllTarget(int					timeout);
    int			testOneTarget(int					target,
				      int					timeout);
  };
}

#endif //		__NETWORK_UDP_HH__
