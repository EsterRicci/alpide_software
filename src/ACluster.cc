#include "ACluster.hh"
#include "AHit.hh"

#include <vector>
#include <iostream>

ACluster::ACluster(){

}

void ACluster::AddHit(AHit newhit){

  clusterhits.push_back(newhit);
  return;

}

AHit ACluster::GetHit(int hitID){
  AHit result;
  if(hitID<clusterhits.size()) result=clusterhits.at(hitID);
  else std::cout<<"Warning! The size of the cluster is "<<clusterhits.size()<<". Returning a null hit!";
  return result;


}

int ACluster::GetClusterSize(){
  return clusterhits.size();

}

void ACluster::Dump(){
  int size=clusterhits.size();
  std::cout<<"*******************************"<<std::endl;
  std::cout<< "Cluster Size = "<<size <<std::endl;
  for(int ih;ih<size;++ih)  
    std::cout<< "x= "<< clusterhits.at(ih).GetX() <<" y= "<< clusterhits.at(ih).GetY()<<std::endl;
  std::cout<<"*******************************"<<std::endl;
  return;
}
