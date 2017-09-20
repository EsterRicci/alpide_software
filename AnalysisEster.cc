#include "AHit.hh"
#include "ACluster.hh"
#include "AEvent.hh"
#include "ATools.hh"
#include "AGraphicTools.hh"

#include <iostream>
#include <string>
#include <fstream>

#include "TCanvas.h"
#include "TH1.h"
#include "TStyle.h"

int main(int argc, char **argv){
  if(argc!=3){
    std::cout<<"Please type ./AnalysisEster <inputlist> <outname>"<<std::endl;
    return 0;
  }
  else {

    gStyle->SetPalette(1);
    std::ifstream inlist(argv[1]);
    std::string file,mask;
    int Ebeam;
    std::vector<double> clsz;
    std::vector<double> clsz_err;
    std::vector<double> energy;
    //Temporary mask
    AHit px1(1,84);
    AHit px2(807,29);

    std::vector<AHit> fail;
    fail.push_back(px1);
    fail.push_back(px2);
    AMask inmask(fail);
    inmask.Dump();
    std::string controlfile=argv[2];
    controlfile.append("_control.pdf");
    std::string controlfilein=controlfile;
    controlfilein.append("[");
    std::string controlfileout=controlfile;
    controlfileout.append("]");
    /*  
    TCanvas* can=new TCanvas();
    can->Print(controlfilein.c_str(),"pdf");
    */
    while(!inlist.eof()){
      inlist>>file>>Ebeam>>mask;   
      /*
      AMask inmask;
      inmask.Read(mask);
      //test read mask
      inmask.Dump();
      */
      std::vector<AEvent> test=CollectDataFromFile(file,inmask);
      std::cout<<"Events Collected!"<<std::endl;
      /*
      TH1I* clustersize=ClusterSizeHisto(test,file);
      
      double clsize=clustersize->GetMean();
      double clsize_err=clustersize->GetRMS();
      clsz.push_back(clsize);
      clsz_err.push_back(clsize_err);
      energy.push_back(Ebeam);

      std::cout<<"Run: "<<file<<" Energy: "<<Ebeam<<" Clustersize: "<<clsize<<std::endl;

      
      TH2I* map=FullMap(test,file);
      TH1I* entriesdist=EntriesPerPixel(map,100000);
      TH1I* eventsize=EventSizeDistribution(test,file);
      //TH2I* size1events=MapEventSized(test,1,file);
      */
      /*
      map->Draw("zcol");
      can->Print(controlfile.c_str(),"pdf");
      */
      /*
      //can->SetLogy();
      entriesdist->Draw();
      can->Print(controlfile.c_str(),"pdf");
      eventsize->Draw();
      can->Print(controlfile.c_str(),"pdf");
      clustersize->Draw();
      can->Print(controlfile.c_str(),"pdf");
      */
      /*
      size1events->Draw("zcol");
      can->Print(controlfile.c_str(),"pdf");
      */
    }
    /*
    can->Print(controlfileout.c_str(),"pdf");
    std::string fileout=argv[2];
    fileout.append(".pdf");
    TCanvas* can2=new TCanvas();
    can2=ClusterSizeDistribution(energy,clsz,clsz_err,"Cluster Size at different energies;E [MeV]; Cluster Size");
    can2->Print(fileout.c_str(),"pdf");
    */
    return 1;
  }
}

