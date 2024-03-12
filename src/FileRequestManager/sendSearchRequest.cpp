// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:04:17 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"
#include		<cstring>

void			ef::FileRequestManager::sendSearchRequest(std::string const	&filename,
								  std::map<std::string, std::string> const	&excludeList,
								  int			nbRedirect,
								  int			limit)
{
  if (myPendingRequest.find(filename) == myPendingRequest.end())
    {
      Packet		data;
      std::string	userMsg;

      data.findRequest.type = FIND_REQUEST;
      data.findRequest.nbRedirection = nbRedirect + 1;
      if (limit == -2)
	data.findRequest.limitRedirection = limitRedirection;
      else
	data.findRequest.limitRedirection = limit;
      memcpy(data.findRequest.name, filename.c_str(), filename.size());
      sendPacket(data, pairs, excludeList);
      myPendingRequest[filename] = (size_t)time(NULL);
      userMsg = "Request successfully send with a limit of redirection of " + data.findRequest.limitRedirection;
      sendUser(userMsg);
    }
  else
    sendUser("You have already send a request for this file !");
}

void			ef::FileRequestManager::sendSearchRequest(std::string const	&filename,
								  std::vector<contact> const	&excludeList,
								  int			nbRedirect,
								  int			limit)
{
  std::map<std::string, std::string>	excludeMap;
  size_t		i;

  for (i = 0; i < excludeList.size(); i += 1)
    excludeMap[excludeList[i].label] = excludeList[i].label;
  sendSearchRequest(filename, excludeMap, nbRedirect, limit);
}

void			ef::FileRequestManager::sendSearchRequest(std::string const	&filename,
								  contact const		&excludeContact,
								  int			nbRedirect,
								  int			limit)
{
  std::map<std::string, std::string>	excludeList;

  excludeList[excludeContact.label] = excludeContact.label;
  sendSearchRequest(filename, excludeList, nbRedirect, limit);
}

void			ef::FileRequestManager::sendSearchRequest(std::string const	&filename,
								  int			nbRedirect,
								  int			limit)
{
  std::vector<contact>	excludeList;

  sendSearchRequest(filename, excludeList, nbRedirect, limit);
}
