#include "AHit.hh"
#include "ACluster.hh"
#include "AEvent.hh"
#include "ATools.hh"
#include "AGraphicTools.hh"
#include "AAnalysis.hh"

#include <iostream>
#include <string>
#include <fstream>

#include "TCanvas.h"
#include "TH1.h"
#include "TStyle.h"

int main(int argc, char **argv){
  if(argc!=3){
    std::cout<<"Please type ./ClusterSize <inputlist> <outname>"<<std::endl;
    return 0;
  }
  else {
  
    //ClusterAnalysisEnergy(argv[1],argv[2]);
    ClusterAnalysisEdep(argv[1],argv[2]);
    return 1;
  }
}

