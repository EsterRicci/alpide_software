#include "AAnalysis.hh"
#include "AHit.hh"
#include "AMask.hh"
#include "AGraphicTools.hh"
#include "ATools.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TStyle.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TFile.h"
#include "TTree.h"
void ClusterAnalysisEnergy(const char* filelist, const char* outputname){


  gStyle->SetPalette(1);
  std::ifstream inlist(filelist);
  std::string file,mask;
  int Ebeam;
  std::vector<double> clsz;
  std::vector<double> clsz_err;
  std::vector<double> energy;

  //*********************Temporary Mask*****************//
  AHit px1(1,84);
  AHit px2(807,29);
  std::vector<AHit> fail;
  fail.push_back(px1);
  fail.push_back(px2);
  AMask inmask(fail);
  inmask.Dump();

  //****************************************************//

  std::string controlfile=outputname;
  controlfile.append("_control.pdf");
  std::string controlfilein=controlfile;
  controlfilein.append("[");
  std::string controlfileout=controlfile;
  controlfileout.append("]");
      
  TCanvas* can=new TCanvas();
  can->Print(controlfilein.c_str(),"pdf");
    
  while(!inlist.eof()){
    inlist>>file>>Ebeam>>mask;   
    /*
      AMask inmask;
      inmask.Read(mask);
      //test read mask
      inmask.Dump();
    */
    std::cout<<"Collecting Events from file"<<std::endl;
    std::vector<AEvent> test=CollectDataFromFile(file,inmask);
    std::cout<<"Events Collected!"<<std::endl;
      
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
    TH2I* size1events=MapEventSized(test,1,file);
      
      
    map->Draw("zcol");
    can->Print(controlfile.c_str(),"pdf");
    size1events->Draw("zcol");
    can->Print(controlfile.c_str(),"pdf");
            
       
    //can->SetLogy();
    entriesdist->Draw();
    can->Print(controlfile.c_str(),"pdf");
    eventsize->Draw();
    can->Print(controlfile.c_str(),"pdf");
    clustersize->Draw();
    can->Print(controlfile.c_str(),"pdf");
      

  }
    
  can->Print(controlfileout.c_str(),"pdf");
  std::string fileout=outputname;
  fileout.append(".pdf");
    
 
  std::string fileoutin=fileout;
  fileoutin.append("[");
  std::string fileoutout=fileout;
  fileoutout.append("]");


  TCanvas* can2=new TCanvas();
  can2->Print(fileoutin.c_str());
  //  ClusterSizeDistribution(energy,clsz,clsz_err,"Cluster Size;Energy [MeV]; Cluster Size")->Print(fileout.c_str());
  //ResolutionDistribution(energy,clsz,clsz_err,"Cluster Size resolution;E [MeV]; Resolution")->Print(fileout.c_str());
  can2->Print(fileoutout.c_str(),"pdf");

  return;
} 

void ClusterAnalysisEdep(const char* filein, const char* outputname){
  //readout of simulation output root file
  std::ifstream file_summary(filein);


  std::string filelist;
  std::string rootfile;
  file_summary>>rootfile>>filelist;

  gStyle->SetPalette(1);
  std::ifstream inlist(filelist);
  std::string file,mask;
  int Ebeam;
  std::vector<double> clsz;
  std::vector<double> clsz_err;
  std::vector<double> energy;

  //*********************Temporary Mask*****************//                                                                                                              
  AHit px1(1,84);
  AHit px2(807,29);
  std::vector<AHit> fail;
  fail.push_back(px1);
  fail.push_back(px2);
  AMask inmask(fail);
  inmask.Dump();

  //****************************************************//                                                                                                              

  std::string controlfile=outputname;
  controlfile.append("_control.pdf");
  std::string controlfilein=controlfile;
  controlfilein.append("[");
  std::string controlfileout=controlfile;
  controlfileout.append("]");

  TCanvas* can=new TCanvas();
  can->Print(controlfilein.c_str(),"pdf");

  while(!inlist.eof()){
  inlist>>file>>Ebeam>>mask;
  /*                                                                                                                                                                  
      AMask inmask;                                                                                                                                                     
      inmask.Read(mask);                                                                                                                                                
      //test read mask                                                                                                                                                  
      inmask.Dump();                                                                                                                                                    
  */
  std::cout<<"Collecting Events from file"<<std::endl;
  std::vector<AEvent> test=CollectDataFromFile(file,inmask);
  std::cout<<"Events Collected!"<<std::endl;

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
  TH2I* size1events=MapEventSized(test,1,file);


  map->Draw("zcol");
  can->Print(controlfile.c_str(),"pdf");
  size1events->Draw("zcol");
  can->Print(controlfile.c_str(),"pdf");


  //can->SetLogy();                                                                                                                                                   
  entriesdist->Draw();
  can->Print(controlfile.c_str(),"pdf");
  eventsize->Draw();
  can->Print(controlfile.c_str(),"pdf");
  clustersize->Draw();
  can->Print(controlfile.c_str(),"pdf");


}
can->Print(controlfileout.c_str(),"pdf");

 TFile* sim_file=new TFile(rootfile.c_str());
 TTree* T=(TTree*)sim_file->Get("T");

 double Edep;
 double Ein;
 int nentries=T->GetEntries();

 T->SetBranchAddress("Ein",&Ein);
 T->SetBranchAddress("ALPIDE_Edep",&Edep);

 // To be improved...
 double E_beam[4]={15.,35.,70.,228.};
 TH1D* E_dep_hist[4];

 for(int iEn=0;iEn<4;++iEn){
   E_dep_hist[iEn]=new TH1D(Form("Edep_%fMeV",E_beam[iEn]),Form("Edep_%fMeV;E [MeV];counts",E_beam[iEn]),100,0.,5.);
 }
 for(int iE=0;iE<nentries;++iE){
   T->GetEntry(iE);
   for(int iEn=0;iEn<4;++iEn){
     if(Ein==E_beam[iEn])E_dep_hist[iEn]->Fill(Edep);
   }

 }
 double Edep_mean[4];
 double Edep_RMS[4];

 for(int iEn=0;iEn<4;++iEn){
   Edep_mean[iEn]=E_dep_hist[iEn]->GetMean();
   Edep_RMS[iEn]=E_dep_hist[iEn]->GetRMS();

 }

 std::vector<double> Edep_vec,Edep_RMS_vec;
 for(int iV=0;iV<energy.size();++iV){
   for(int iEn=0;iEn<4;++iEn){
     if(energy.at(iV)==E_beam[iEn]){
       Edep_vec.push_back(Edep_mean[iEn]);
       Edep_RMS_vec.push_back(Edep_RMS[iEn]);
     }
   }
 }
 std::string fileout=outputname;
 fileout.append(".pdf");


std::string fileoutin=fileout;
fileoutin.append("[");
std::string fileoutout=fileout;
fileoutout.append("]");


TCanvas* can2=new TCanvas();
can2->Print(fileoutin.c_str());
 ClusterSizeDistribution(Edep_vec,clsz,Edep_RMS_vec,clsz_err,"Cluster Size;Energy deposited [MeV]; Cluster Size")->Print(fileout.c_str());                                                  
//ResolutionDistribution(energy,clsz,clsz_err,"Cluster Size resolution;E [MeV]; Resolution")->Print(fileout.c_str());                                                 
can2->Print(fileoutout.c_str(),"pdf");


  return;
}


void StrobeEffect(const char *filelist, const char* outputname){
  //I want the number of events in each file (is the most intersting data I found using clustersize control plots


  gStyle->SetPalette(1);
  std::ifstream inlist(filelist);
  std::string file,mask;
  int stb;
  std::vector<int> events;
  
  std::vector<int> strobe;

  //*********************Temporary Mask*****************//                                                                                        
  AHit px1(1,84);
  AHit px2(807,29);
  std::vector<AHit> fail;
  fail.push_back(px1);
  fail.push_back(px2);
  AMask inmask(fail);
  inmask.Dump();

  //****************************************************//                                                                                        
  while(!inlist.eof()){
    inlist>>file>>stb>>mask;
    /*                                                                                                                                            
      AMask inmask;                                                                                                                               
      inmask.Read(mask);                                                                                                                          
      //test read mask                                                                                                                            
      inmask.Dump();                                                                                                                              
    */
    
    std::vector<AEvent> test=CollectDataFromFile(file,inmask);
    events.push_back(test.size());
    strobe.push_back(stb);


  }

  std::string outfile=outputname;
  outfile.append(".pdf");

  TCanvas* can=EventNumberDistribution(strobe,events,"# of events for different strobe;strobe [clock cycles];events");
  can->Print(outfile.c_str(),"pdf");
  return;
}

void BiasEffect(const char* list1,const char* list2, const char* list3,const char* outname){
  TGraphErrors* biasgraph[3];

  std::ifstream in0bias(list1);
  std::ifstream in3bias(list2);
  std::ifstream in6bias(list3);

  std::string file,mask;
  int Ebeam;
  std::vector<AEvent> inputEv[3];
  //*********************Temporary Mask*****************//                                                                                                               
  AHit px1(1,84);
  AHit px2(807,29);
  std::vector<AHit> fail;
  fail.push_back(px1);
  fail.push_back(px2);
  AMask inmask(fail);
  inmask.Dump();

  //****************************************************//      

  std::vector<double> clsz[3];
  std::vector<double> clsz_err[3];
  std::vector<double> energy[3];
  while(!in0bias.eof()){
    in0bias>>file>>Ebeam>>mask;
    inputEv[0]=CollectDataFromFile(file,inmask);

    TH1I* clustersize=ClusterSizeHisto(inputEv[0],file);
    double clsize=clustersize->GetMean();
    double clsize_err=clustersize->GetRMS();
    clsz[0].push_back(clsize);
    clsz_err[0].push_back(clsize_err);
    energy[0].push_back(Ebeam);

  }
  
  while(!in3bias.eof()){
    in3bias>>file>>Ebeam>>mask;
    inputEv[1]=CollectDataFromFile(file,inmask);
 
    TH1I* clustersize=ClusterSizeHisto(inputEv[1],file);
    double clsize=clustersize->GetMean();
    double clsize_err=clustersize->GetRMS();
    clsz[1].push_back(clsize);
    clsz_err[1].push_back(clsize_err);
    energy[1].push_back(Ebeam);
  }
  
  while(!in6bias.eof()){
    in6bias>>file>>Ebeam>>mask;
    inputEv[2]=CollectDataFromFile(file,inmask);
    TH1I* clustersize=ClusterSizeHisto(inputEv[2],file);

    double clsize=clustersize->GetMean();
    double clsize_err=clustersize->GetRMS();
    clsz[2].push_back(clsize);
    clsz_err[2].push_back(clsize_err); 
    energy[2].push_back(Ebeam);
  }
  
  
  TCanvas *can=new TCanvas();

  TH1* bg=can->DrawFrame( 0,0,240,15);
  bg->SetTitle("; Energy [MeV];Cluster Size");
  can->Update();
  TLegend* leg=new TLegend(0.6,0.7 ,0.9,0.9);
  for(int iBias=0;iBias<3 ;++iBias){
    int bias;
    if(iBias==0) bias=0;
    else if(iBias==1) bias=3;
    else if(iBias==2) bias=6;
    biasgraph[iBias]=ClusterSizePlot(energy[iBias],clsz[iBias],clsz_err[iBias],"test");
    biasgraph[iBias]->Draw("P same");
    biasgraph[iBias]->SetMarkerColor(iBias+1);
    biasgraph[iBias]->SetMarkerStyle(22);
    if(bias==0)leg->AddEntry(biasgraph[iBias],Form("%d V Back Bias",bias),"p");
    else leg->AddEntry(biasgraph[iBias],Form("- %d V Back Bias",bias),"p");
  }
  leg->Draw("same");
  std::string outfile=outname;
  outfile.append(".pdf");
  can->Print(outfile.c_str(),"pdf");
  return;
}


void BiasEffectEdep(const char* list1,const char* list2, const char* list3,const char* simulation, const char* outname){
  TGraphErrors* biasgraph[3];

  std::ifstream in0bias(list1);
  std::ifstream in3bias(list2);
  std::ifstream in6bias(list3);

  std::string file,mask;
  int Ebeam;
  std::vector<AEvent> inputEv[3];
  //*********************Temporary Mask*****************//                                                                                                             \
                                                                                                                                                                        
  AHit px1(1,84);
  AHit px2(807,29);
  std::vector<AHit> fail;
  fail.push_back(px1);
  fail.push_back(px2);
  AMask inmask(fail);
  inmask.Dump();

  //****************************************************//                                                                                                              

  std::vector<double> clsz[3];
  std::vector<double> clsz_err[3];
  std::vector<double> energy[3];
  while(!in0bias.eof()){
    in0bias>>file>>Ebeam>>mask;
    inputEv[0]=CollectDataFromFile(file,inmask);

    TH1I* clustersize=ClusterSizeHisto(inputEv[0],file);
    double clsize=clustersize->GetMean();
    double clsize_err=clustersize->GetRMS();
    clsz[0].push_back(clsize);
    clsz_err[0].push_back(clsize_err);
    energy[0].push_back(Ebeam);

  }

  while(!in3bias.eof()){
    in3bias>>file>>Ebeam>>mask;
    inputEv[1]=CollectDataFromFile(file,inmask);

    TH1I* clustersize=ClusterSizeHisto(inputEv[1],file);
    double clsize=clustersize->GetMean();
    double clsize_err=clustersize->GetRMS();
    clsz[1].push_back(clsize);
    clsz_err[1].push_back(clsize_err);
    energy[1].push_back(Ebeam);
  }

  while(!in6bias.eof()){
    in6bias>>file>>Ebeam>>mask;
    inputEv[2]=CollectDataFromFile(file,inmask);
    TH1I* clustersize=ClusterSizeHisto(inputEv[2],file);

    double clsize=clustersize->GetMean();
    double clsize_err=clustersize->GetRMS();
    clsz[2].push_back(clsize);
    clsz_err[2].push_back(clsize_err);
    energy[2].push_back(Ebeam);
  }

  TFile* sim_file=new TFile(simulation);
  TTree* T=(TTree*)sim_file->Get("T");

  double Edep;
  double Ein;
  int nentries=T->GetEntries();

  T->SetBranchAddress("Ein",&Ein);
  T->SetBranchAddress("ALPIDE_Edep",&Edep);

  // To be improved...                                                                                                                                                   
  double E_beam[4]={15.,35.,70.,228.};
  TH1D* E_dep_hist[4];

  for(int iEn=0;iEn<4;++iEn){
    E_dep_hist[iEn]=new TH1D(Form("Edep_%fMeV",E_beam[iEn]),Form("Edep_%fMeV;E [MeV];counts",E_beam[iEn]),100,0.,5.);
  }
  for(int iE=0;iE<nentries;++iE){
    T->GetEntry(iE);
    for(int iEn=0;iEn<4;++iEn){
      if(Ein==E_beam[iEn])E_dep_hist[iEn]->Fill(Edep);
    }

  }
  double Edep_mean[4];
  double Edep_RMS[4];

  for(int iEn=0;iEn<4;++iEn){
    Edep_mean[iEn]=E_dep_hist[iEn]->GetMean();
    Edep_RMS[iEn]=E_dep_hist[iEn]->GetRMS();

  }

  std::vector<double> Edep_vec[3],Edep_RMS_vec[3];
  for(int iBias=0;iBias<3;++iBias){
    for(int iV=0;iV<energy[iBias].size();++iV){
      for(int iEn=0;iEn<4;++iEn){
	if(energy[iBias].at(iV)==E_beam[iEn]){
	  Edep_vec[iBias].push_back(Edep_mean[iEn]);
	  Edep_RMS_vec[iBias].push_back(Edep_RMS[iEn]);
	}
      }
    }
  }

  TCanvas *can=new TCanvas();

  TH1* bg=can->DrawFrame( 0,0,2.4,15);
  bg->SetTitle("; Energy Deposited [MeV];Cluster Size");
  can->Update();
  TLegend* leg=new TLegend(0.6,0.1 ,0.9,0.25);
  for(int iBias=0;iBias<3 ;++iBias){
    int bias;
    if(iBias==0) bias=0;
    else if(iBias==1) bias=3;
    else if(iBias==2) bias=6;
    biasgraph[iBias]=ClusterSizePlot(Edep_vec[iBias],clsz[iBias],Edep_RMS_vec[iBias],clsz_err[iBias],"test");
    biasgraph[iBias]->Draw("P same");
    biasgraph[iBias]->SetMarkerColor(iBias+1);
    biasgraph[iBias]->SetMarkerStyle(22);
    if(bias==0)leg->AddEntry(biasgraph[iBias],Form("%d V Back Bias",bias),"p");
    else leg->AddEntry(biasgraph[iBias],Form("- %d V Back Bias",bias),"p");
  }
  leg->Draw("same");
  std::string outfile=outname;
  outfile.append(".pdf");
  can->Print(outfile.c_str(),"pdf");
  return;
}
