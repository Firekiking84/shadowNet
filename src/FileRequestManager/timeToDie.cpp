// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/03/2024 17:03:28 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"fileRequestManager.hh"

void			ef::FileRequestManager::timeToDie()
{
  std::map<uint64_t, fileInfoPair>::iterator	it;
  size_t		now;

  now = reinterpret_cast<size_t>(time(NULL));
  for (it = filesFind.begin(); it != filesFind.end(); ++it)
    {
      if ((now - it->second.lastUptdate) > 600)
	filesFind.erase(it);
    }
  std::map<uint64_t, s_request>::iterator	dlIt;

  for (dlIt = pendingDLRequest.begin(); dlIt != pendingDLRequest.end(); ++dlIt)
    {
      if ((now - dlIt->second.time) > 60)
	pendingDLRequest.erase(dlIt);
    }

  std::map<std::string, size_t>::iterator	myIt;

  for (myIt = myPendingRequest.begin(); myIt != myPendingRequest.end(); ++myIt)
    {
      if ((now - myIt->second) > 30)
	myPendingRequest.erase(myIt);
    }

  std::map<uint64_t, DLInfo>::iterator		curIt;
  std::string					status;
  size_t					i;

  for (curIt = currentDownload.begin(); curIt != currentDownload.end(); ++curIt)
    {
      if (filesFind.find(curIt->first) == filesFind.end()) // No one can share the file anymore
	{
	  currentDownload.erase(curIt);
	  // log end of download
	}
      else if ((now - curIt->second.lastUpdate) > 30)
	{
	  Packet				data;
	  std::map<std::string, contact>::iterator	pairIt;

	  pairIt = filesFind[curIt->first].pairs.begin();
	  data.type = DL_UNIQUE_REQUEST;
	  data.nDiv = 0;
	  data.hashFile = curIt->first;
	  getStatus(curIt->first, status);
	  for (i = 0; i < status.size(); i += 1)
	    {
	      if (status[i] == 0)
		{
		  data.nPart = i;
		  sendPacket(data, pairIt->second);
		  ++pairIt;
		}
	    }
	}
    }
}
