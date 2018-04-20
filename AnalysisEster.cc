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
  if(argc==5){
    BiasEffect(argv[1],argv[2],argv[3],argv[4]);
    return 1;
  }
  else if (argc==6){
  
    //StrobeEffect(argv[1],argv[2]);
    BiasEffectEdep(argv[1],argv[2],argv[3],argv[4],argv[5]);
    return 1;
  }
  else {
    std::cout<<"Use: ./AnalysisEster <inputlist> <inputlist2> <inputlist3> <outname>"<<std::endl;
    std::cout<<"Use: ./AnalysisEster <inputlist> <inputlist2> <inputlist3> <simulation file> <outname>"<<std::endl;

    return 1;

  }
}

