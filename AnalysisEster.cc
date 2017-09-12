#include "AHit.hh"
#include "ACluster.hh"
#include "AEvent.hh"
#include "ATools.hh"
#include "AGraphicTools.hh"

#include <iostream>
#include <string>

#include "TCanvas.h"

int main(int argc, char **argv){
  if(argc!=3){
    std::cout<<"Please type ./AnalysisEster <inputfile> <inputmask>"<<std::endl;
    return 0;
  }
  else {
  AMask inmask;
  inmask.Read(argv[2]);
  //test read mask
  inmask.Dump();
  std::vector<AEvent> test=CollectDataFromFile(argv[1],inmask);

  TCanvas* can=ClusterSizePlot(test,argv[1]);
  can->Print("test.pdf","pdf");

  return 1;
  }
}

