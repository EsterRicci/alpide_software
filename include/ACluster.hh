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
  int GetXMean();
  int GetYMean();

  double GetSigmaX();
  double GetSigmaY();
  double GetSigmaPi4();
  double GetSigma3Pi4();

private:
  std::vector<AHit> clusterhits;




};




#endif
