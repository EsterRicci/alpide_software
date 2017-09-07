#include "AEvent.hh"
#include "ACluster.hh"

#include <vector>
#include <iostream>

AEvent::AEvent(){
  trig_id=-999;

}

AEvent::AEvent(int trigger, std::vector<ACluster> cl){
  trig_id=trigger;
  clusters=cl;

}

void AEvent::SetTriggerID(int trigger){
  trig_id=trigger;
  return;

}

int AEvent::GetTriggerID(){
  return trig_id;

}

std::vector<ACluster> AEvent::GetClusters(){
  return clusters;

}

void AEvent::SetClusters(std::vector<ACluster> input){
  clusters=input;
  return;


}
void AEvent::AddCluster(ACluster newcluster){
  clusters.push_back(newcluster);
  return;
}

ACluster AEvent::GetCluster(int clusterID){
  ACluster result;
  if(clusterID<clusters.size()) result=clusters.at(clusterID);
  else   std::cout<<"Warning! The size of the event is "<<clusters.size()<<". Returning a null cluster!";
  return result;

}

int AEvent::GetClusterNumber(){
  return clusters.size();


}
