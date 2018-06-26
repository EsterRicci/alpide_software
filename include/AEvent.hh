#ifndef _AEVENT_
#define _AEVENT_ 1

#include "ACluster.hh"
#include <vector>

const int CLUSTERMAXNUM=100;

class AEvent{
public:
  AEvent();
  AEvent(int trigger,long int time,std::vector<ACluster> cl);
  void SetTriggerID(int trigger);
  int GetTriggerID();
  void SetTimeStamp(long int time);
  long int GetTimeStamp();
  std::vector<ACluster> GetClusters();
  void SetClusters(std::vector<ACluster> input);
  void AddCluster(ACluster cluster);
  ACluster GetCluster(int clusterID);
  int GetClusterNumber();
  int GetEventSize();
  void Dump();

private:
  int trig_id;
  long int timestamp;
  std::vector<ACluster> clusters;


};


#endif
