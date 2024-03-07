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

      data.findRequest.type = FIND_REQUEST;
      data.findRequest.nbRedirection = nbRedirect + 1;
      if (limit == -2)
	data.findRequest.limitRedirection = limitRedirection;
      else
	data.findRequest.limitRedirection = limit;
      memcpy(data.filename, filename.c_str(), filename.size());
      sendPacket(data, pairs, excludeList);
      myPendingRequest[filename] = reinterpret_cast<size_t>(time(NULL));
    }
  else
    {
    // do log
    }
}

void			ef::FileRequestManager::sendSearchRequest(std::string const	&filename,
								  contact const		&excludeContact,
								  int			nbRedirect,
								  int			limit)
{
  std::map<std::string, std::string>	excludeList;

  excludeList[excludeContact.label] = excludeContact.label;
  sendSearchRequest(filename, nbRedirect, limit, excludeList);
}

void			ef::FileRequestManager::sendSearchRequest(std::string const	&filename,
								  int			nbRedirect,
								  int			limit)
{
  std::vector<contact>	excludeList;

  sendSearchRequest(filename, nbRedirect, limit, excludeList);
}
