#include "AGraphicTools.hh"
#include "AEvent.hh"

#include <vector>
#include <string>
#include <iostream>

#include "TCanvas.h"
#include "TH2.h"
#include "TH1.h"

TH2I* FullMap(std::vector<AEvent> input){
  //TCanvas* result=new TCanvas();
  TH2I *map=new TH2I("full_map","full_map;column;row",XPIXEL,0,XPIXEL,YPIXEL,0,YPIXEL);

  int size=input.size();
  for(int iev=0;iev<size;++iev){
    int ev_size=input.at(iev).GetClusterNumber();
    for(int icl=0;icl<ev_size;++icl){
      int cl_size=input.at(iev).GetCluster(icl).GetClusterSize();
      for(int ihit=0;ihit<cl_size;++ihit){
	map->Fill(input.at(iev).GetCluster(icl).GetHit(ihit).GetX(),input.at(iev).GetCluster(icl).GetHit(ihit).GetY());
      }
    }
  }
  //map->Draw("zcol");
  //return result;
  return map;
}


TCanvas* SingleEvent(AEvent input){
  TCanvas* result=new TCanvas();
  TH2I *map=new TH2I("Event",Form("Event_%d;column;row",input.GetTriggerID()),XPIXEL,0,XPIXEL,YPIXEL,0,YPIXEL);

  int ev_size=input.GetClusterNumber();
  for(int icl=0;icl<ev_size;++icl){
    int cl_size=input.GetCluster(icl).GetClusterSize();
    for(int ihit=0;ihit<cl_size;++ihit)
      map->Fill(input.GetCluster(icl).GetHit(ihit).GetX(),input.GetCluster(icl).GetHit(ihit).GetY());
  }
  map->Draw("zcol");
  return result;
}


TCanvas* ClusterSizePlot(std::vector<AEvent> input,std::string inputname){
  TCanvas *result=new TCanvas();
  std::string histoname=inputname.substr(inputname.find("/"),inputname.size());
  histoname.erase(histoname.end()-4,histoname.end());
  histoname.erase(histoname.begin(),histoname.begin()+1);
  histoname.append("_clustersize");
  //std::cout<<histoname<<std::endl;
  TH1I* clustersize=new TH1I(histoname.c_str(),"Cluster Size;cluster size;entries",20,0,20);
  int inputsize=input.size();
  for(int iev=0;iev<inputsize;++iev){
    int cl_num=input.at(iev).GetClusterNumber();
    for(int icl=0;icl<cl_num;++icl){
      clustersize->Fill(input.at(iev).GetCluster(icl).GetClusterSize());
    }
  }
  clustersize->Draw();
  //inputname.erase(inputname.begin(),inputname.begin+17);
  std::cout<<inputname<<"\t"<<clustersize->GetMean()<<std::endl;
  return result;


}

