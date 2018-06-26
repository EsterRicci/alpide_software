#include "AEvent.hh"
#include "ACluster.hh"

#include <vector>
#include <iostream>

AEvent::AEvent(){
  trig_id=-999;
  timestamp=-9999;
}

AEvent::AEvent(int trigger, long int time,std::vector<ACluster> cl){
  trig_id=trigger;
  timestamp=time;
  clusters=cl;

}

void AEvent::SetTriggerID(int trigger){
  trig_id=trigger;
  return;

}

int AEvent::GetTriggerID(){
  return trig_id;

}

void AEvent::SetTimeStamp(long int time){
  timestamp=time;
  return;
}

long int AEvent::GetTimeStamp(){
  return timestamp;
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

int AEvent::GetEventSize(){
  int result=0;
  int eventsize=clusters.size();
  for(int iev=0;iev<eventsize;++iev){
    result+=clusters.at(iev).GetClusterSize();

    }

  return result;
}

void AEvent::Dump(){
  int clusternumber=clusters.size();
  std::cout<<"***************************************"<<std::endl
	   <<"The trigger id of the event is "<<trig_id<<std::endl
	   <<"The event contains "<<clusternumber<<" clusters"<<std::endl;
  for(int icl=0;icl<clusternumber;++icl){
    clusters.at(icl).Dump();

  }
  return;

}
