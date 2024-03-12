// EFRITS
// project:     Talk
// created on:  2023-11-03 - 13:18 +0100
// 1st author:  keryan.houssin - keryan.houssin
// description: Header File of NetworkUDP. Class managing the network part of
// the program

#ifndef			__NETWORK_UDP_HH__

#define			__NETWORK_UDP_HH__

#include		"contact.hh"
#include		"user.hh"
#include		"packet.hh"

#include		<poll.h>
#include		<vector>
#include		<map>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>

namespace ef
{
  class		NetworkUDP : public	User
  {
  public:
    enum class		Mode
      {
	WRITE,
	READ,
	READ_WRITE
      };

    enum		pfdRole
      {
	EXTERNAL = 0,
	INTERNAL
      };

    NetworkUDP(std::string const	&_cnf_name);
    ~NetworkUDP();
    int 		can(Mode						mode,
			    int							target = -1,
			    int							timeout = -1);
    void		newAddr(contact					&	_contact) const;
    bool		readFd(std::string				&	buffer,
			       int						sizeBuffer,
			       int						fd);
    ssize_t		recvPacket(int						fd,
				   struct ::sockaddr_in			&	addr,
				   Packet				&	data);
    ssize_t		recvFromFd(int						fd,
				   struct ::sockaddr_in			&	addr,
				   std::string				&	buffer,
				   size_t				&	sizeBuffer);
    void		sendUser(std::string const			&	msg);
    void		sendUser(char const				*	msg);
    void		sendPacket(Packet const				&	data,
				   std::map<std::string, contact> const	&	contactList,
				   std::map<std::string, std::string> const	&excludeList);
    void		sendPacket(Packet const				&	data,
				   std::map<std::string, contact> const	&	contactList,
				   std::vector<contact> const		&	excludeList);
    void		sendPacket(Packet const				&	data,
				   std::map<std::string, contact> const	&	contactList,
				   contact const			&	excludeContact);
    void		sendPacket(Packet const				&	data,
				   std::map<std::string, contact> const	&	contactList);
    void		sendPacket(Packet const				&	data,
				   std::vector<contact> const		&	contactList,
				   std::map<std::string, std::string> const &	excludeList);
    void		sendPacket(Packet const				&	data,
				   std::vector<contact> const		&	contactList,
				   std::vector<contact> const		&	excludeList);
    void		sendPacket(Packet const				&	data,
				   std::vector<contact> const		&	contactList,
				   contact const			&	excludeContact);
    void		sendPacket(Packet const				&	data,
				   std::vector<contact> const		&	contactList);
    void		sendPacket(Packet const				&       data,
				   contact const			&	pair,
				   contact const			&	excludeContact);
    void		sendPacket(Packet const				&	data,
				   contact const			&	contact);
  protected:
    contact		user;
    bool		isConnected;
    struct pollfd	pfd[2];
  private:
    int			testAllTarget(int					timeout);
    int			testOneTarget(int					target,
				      int					timeout);
  };
}

#endif //		__NETWORK_UDP_HH__
