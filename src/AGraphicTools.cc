#include "AGraphicTools.hh"
#include "AEvent.hh"

#include <vector>

#include "TCanvas.h"
#include "TH2.h"

TCanvas* FullMap(std::vector<AEvent> input){
  TCanvas* result=new TCanvas();
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
  map->Draw("zcol");
  return result;
}
