#include		"fileRequestManager.hh"

void			ef::FileRequestManager::refreshFiles()
{
  std::time_t		curTime;

  curTime = std::time(nullptr);
  if ((curTime - lastRefresh) < 60)
    return;
  lastRefresh = curTime;
}
