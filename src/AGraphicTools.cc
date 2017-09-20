#include "AGraphicTools.hh"
#include "AEvent.hh"

#include <vector>
#include <string>
#include <iostream>

#include "TCanvas.h"
#include "TH2.h"
#include "TH1.h"
#include "TGraphErrors.h"
//#include "TString.h"

TH2I* FullMap(std::vector<AEvent> input,std::string filename){
  //TCanvas* result=new TCanvas();
  std::size_t found = filename.find_last_of("/");
  std::string histoname=filename.substr(found+1,filename.size());
  histoname.erase(histoname.end()-4,histoname.end());
  histoname.append("_fullmap");
  TH2I *map=new TH2I(histoname.c_str(),"full_map;column;row",XPIXEL,0,XPIXEL,YPIXEL,0,YPIXEL);

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
  TH2I *map=new TH2I("Event",/*Form("Event_%d;column;row",input.GetTriggerID())*/";column;row",XPIXEL,0,XPIXEL,YPIXEL,0,YPIXEL);

  int ev_size=input.GetClusterNumber();
  for(int icl=0;icl<ev_size;++icl){
    int cl_size=input.GetCluster(icl).GetClusterSize();
    for(int ihit=0;ihit<cl_size;++ihit)
      map->Fill(input.GetCluster(icl).GetHit(ihit).GetX(),input.GetCluster(icl).GetHit(ihit).GetY());
  }
  map->Draw("zcol");
  return result;
}

TH1I* ClusterSizeHisto(std::vector <AEvent> input, std::string inputname){
  std::size_t found = inputname.find_last_of("/");
  std::string histoname=inputname.substr(found+1,inputname.size());
  histoname.erase(histoname.end()-4,histoname.end());
  // histoname.erase(histoname.begin(),histoname.begin()+1);
  histoname.append("_clustersize");
  
  TH1I* result=new TH1I(histoname.c_str(),"Cluster Size;cluster size;entries",20,0,20);
  int inputsize=input.size();
  for(int iev=0;iev<inputsize;++iev){
    int cl_num=input.at(iev).GetClusterNumber();
    for(int icl=0;icl<cl_num;++icl){
      result->Fill(input.at(iev).GetCluster(icl).GetClusterSize());
    }
  }
  return result;
}


TCanvas* ClusterSizePlot(std::vector<AEvent> input,std::string inputname){
  TCanvas *result=new TCanvas();
  TH1I* clustersize=ClusterSizeHisto(input,inputname);
  clustersize->Draw();
  //inputname.erase(inputname.begin(),inputname.begin+17);
  std::cout<<inputname<<"\t"<<clustersize->GetMean()<<std::endl;
  return result;


}


TH1I* EntriesPerPixel(TH2I* map,int ntrig){
  TH1I* result=new TH1I("hits_dist","Hits distributions;hit number;pixel number",50,0,50);

  for(int ix=0;ix<XPIXEL;++ix){
    for(int iy=0;iy<YPIXEL;++iy){
      int pixelvalue=map->GetBinContent(ix,iy);
      if(pixelvalue>0)result->Fill(pixelvalue);
    }
    
  }

  return result;
}


TCanvas* ClusterSizeDistribution(std::vector<double> x,std::vector<double> y,std::vector<double> y_err,std::string title){
  TCanvas* result=new TCanvas();
  if(x.size()==y.size() && y.size()==y_err.size()){
    int sizeofgraph=x.size();

    TGraphErrors* plot=new TGraphErrors(sizeofgraph);
    for(int ip=0;ip<sizeofgraph;++ip){
      plot->SetPoint(ip,x.at(ip),y.at(ip));
      plot->SetPointError(ip,0,y_err.at(ip));

    }
    plot->SetTitle(title.c_str());
    plot->SetMarkerStyle(22);
    plot->Draw("AP");
  }
  else std::cout<<"ERROR! Vectors must have the same length!"<<std::endl;
  return result;
}

TH1I* EventSizeDistribution(std::vector<AEvent> input,std::string inputname){
  std::size_t found = inputname.find_last_of("/");
  std::string histoname=inputname.substr(found+1,inputname.size());
  histoname.erase(histoname.end()-4,histoname.end());
  // histoname.erase(histoname.begin(),histoname.begin()+1);
  histoname.append("_eventsize");

  TH1I* result=new TH1I(histoname.c_str(),"Event size;event size;entries",50,0,50);

  int runsize=input.size();
  for(int ir=0;ir<runsize;++ir){
    result->Fill(input.at(ir).GetEventSize());
  }
  return result;

}

TH2I* MapEventSized(std::vector<AEvent> input, int size,std::string inputname){
  
  std::size_t found = inputname.find_last_of("/");
  std::string histoname=inputname.substr(found+1,inputname.size());
  histoname.erase(histoname.end()-4,histoname.end());
  // histoname.erase(histoname.begin(),histoname.begin()+1);
  histoname.append("_size");
  
  TH2I* result=new TH2I(histoname.c_str(),/*Form("Events with size %d;column;row",size)*/";column;row",XPIXEL+2,0,XPIXEL,YPIXEL+2,0,YPIXEL);
  int runsize=input.size();
  for(int ir=0;ir<runsize;++ir){
    
    if(input.at(ir).GetEventSize()==size){
      int clnum=input.at(ir).GetClusterNumber();
      for(int icl=0;icl<clnum;++icl){
	int clsize=input.at(ir).GetCluster(icl).GetClusterSize();
	for(int ih=0;ih<clsize;++ih){
	  result->Fill(input.at(ir).GetCluster(icl).GetHit(ih).GetX()+1,input.at(ir).GetCluster(icl).GetHit(ih).GetY()+1);
	}
      }

    }
    
  }
	      
  return result;
}
