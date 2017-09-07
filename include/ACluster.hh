#ifndef _ACLUSTER_
#define _ACLUSTER_ 1

#include <vector>
#include "AHit.hh"

const int HITMAXDIST=60;

class ACluster{
public:
  ACluster();
  void AddHit(AHit newhit);
  AHit  GetHit(int hitID);
  int GetClusterSize();
  void Dump();

private:
  std::vector<AHit> clusterhits;




};




#endif
