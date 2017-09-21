#ifndef _AEVENT_
#define _AEVENT_ 1

#include "ACluster.hh"
#include <vector>

const int CLUSTERMAXNUM=10;

class AEvent{
public:
  AEvent();
  AEvent(int trigger,std::vector<ACluster> cl);
  void SetTriggerID(int trigger);
  int GetTriggerID();
  std::vector<ACluster> GetClusters();
  void SetClusters(std::vector<ACluster> input);
  void AddCluster(ACluster cluster);
  ACluster GetCluster(int clusterID);
  int GetClusterNumber();
  int GetEventSize();
  void Dump();

private:
  int trig_id;
  std::vector<ACluster> clusters;


};


#endif
