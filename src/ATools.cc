#include "AEvent.hh"
#include "ACluster.hh"
#include "AHit.hh"

#include <vector>
#include <cmath>
#include <string>
#include <fstream>


std::vector<ACluster> FillClusters(std::vector<AHit> input){
  std::vector<AHit> buffer=input;
  std::vector<ACluster> result;
 
  ACluster cluster;
  std::vector<AHit> far[CLUSTERMAXNUM+1];
  cluster.AddHit(buffer.at(0));
    
  int sizeofbuffer=buffer.size();
  for(int ihit=1;ihit<sizeofbuffer;++ihit){
    double distance=sqrt((buffer.at(0).GetX()-buffer.at(ihit).GetX())*(buffer.at(0).GetX()-buffer.at(ihit).GetX())+(buffer.at(0).GetY()-buffer.at(ihit).GetY())*(buffer.at(0).GetY()-buffer.at(ihit).GetY()));
   
      
    if(distance<HITMAXDIST){
      cluster.AddHit(buffer.at(ihit));
   
    }
    else far[0].push_back(buffer.at(ihit));
      
      
   
  }
  result.push_back(cluster);
     
  int i=0;
  while(i<CLUSTERMAXNUM && far[i].size()>0){
    ++i;
    ACluster cl;
       
    int sizeoffar=far[i-1].size();
    for(int ihit=1;ihit<sizeoffar;++ihit){
      double distance=sqrt((far[i-1].at(0).GetX()-far[i-1].at(ihit).GetX())*(far[i-1].at(0).GetX()-far[i-1].at(ihit).GetX())+(far[i-1].at(0).GetY()-far[i-1].at(ihit).GetY())*(far[i-1].at(0).GetY()-far[i-1].at(ihit).GetY()));
   
       
      if(distance<HITMAXDIST){
	cl.AddHit(far[i-1].at(ihit));
	
      }
      else far[i].push_back(far[i-1].at(ihit));
      
    }
       
    result.push_back(cl);
       
  }
        
  return result;

}

std::vector<AEvent> CollectDataFromFile(std::string filename){

  std::vector<AEvent> result;  
  std::ifstream inputfile(filename,std::ifstream::in);
  int trig=0;
  int trig_id=0;
  int x=0;
  int y=0;
  inputfile>>trig_id;
  trig=trig_id;
  while(!inputfile.eof()){
   
    AEvent inEvent;
    //if(trig==0) trig=trig_id;
    inEvent.SetTriggerID(trig_id);
    std::vector<AHit> hits;
    while(trig==trig_id && !inputfile.eof()){
      AHit inHit;
      inputfile>>x>>y;
      inHit.SetX(x);
      inHit.SetY(y);
      
      hits.push_back(inHit);
      inputfile>>trig_id;
    }
    
    inEvent.SetClusters(FillClusters(hits));
    result.push_back(inEvent);
    trig=trig_id;
    //std::cout<<"Trigger index: "<<trig_id<<" x: "<<x<<" y: "<<y<<std::endl;
  }


  return result;
}
