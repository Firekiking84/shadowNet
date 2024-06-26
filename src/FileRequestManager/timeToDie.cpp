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
  size_t					i;

  now = (size_t)time(NULL);
  for (it = filesFind.begin(); it != filesFind.end();)
    {
      if ((now - it->second.lastUpdate) > 600)
	it = filesFind.erase(it);
      else
	++it;
    }
  std::map<uint64_t, std::vector<s_request>>::iterator	dlIt;
  std::vector<s_request>::iterator			reqIt;

  for (dlIt = pendingDLRequest.begin(); dlIt != pendingDLRequest.end();)
    {
      for (reqIt = dlIt->second.begin(); reqIt != dlIt->second.end();)
	{
	  if ((now - reqIt->time) > 60)
	    reqIt = dlIt->second.erase(reqIt);
	  else
	    ++reqIt;
	}
      if (dlIt->second.size() == 0)
	dlIt = pendingDLRequest.erase(dlIt);
      else
	++dlIt;
    }

  std::map<std::string, size_t>::iterator	myIt;

  for (myIt = myPendingRequest.begin(); myIt != myPendingRequest.end();)
    {
      if ((now - myIt->second) > 30)
	myIt = myPendingRequest.erase(myIt);
      else
	++myIt;
    }

  std::map<uint64_t, DLInfo>::iterator		curIt;
  std::string					status;

  for (curIt = currentDownload.begin(); curIt != currentDownload.end();)
    {
      if (filesFind.find(curIt->first) == filesFind.end()) // No one can share the file anymore
	{
	  curIt = currentDownload.erase(curIt);
	  // log end of download
	}
      else if ((now - curIt->second.lastUpdate) > 1)
	{
	  Packet				data;
	  Bitfield				bitPart(filesFind[curIt->first].nbPart);

	  currentDownload[curIt->first].status.seek(0, FileManager::SeekFlags::BEG);
	  bitPart.Unserialize(currentDownload[curIt->first].status.getStream());
	  data.dlRequest.hashFile = curIt->first;
	  if (getStatus(curIt->first) < 20)
	    shareDLRequest(curIt->first);
	  else
	    {
	      std::map<std::string, contact>::iterator	pairIt;

	      pairIt = filesFind[curIt->first].pairs.begin();
	      data.dlRequest.type = DL_UNIQUE_REQUEST;
	      data.dlRequest.nDiv = 1;
	      for (i = 0; i < filesFind[curIt->first].nbPart; i += 1)
		{
		  if (bitPart[i] == false)
		    {
		      data.dlRequest.nPart = i;
		      sendPacket(data, pairIt->second);
		      ++pairIt;
		      if (pairIt == filesFind[curIt->first].pairs.end())
			pairIt = filesFind[curIt->first].pairs.begin();
		    }
		}
	    }
	  ++curIt;
	}
      else
	++curIt;
    }
}
