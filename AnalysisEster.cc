#include "AHit.hh"
#include "ACluster.hh"
#include "AEvent.hh"
#include "ATools.hh"
#include "AGraphicTools.hh"

#include <iostream>
#include <string>

#include "TCanvas.h"

int main(int argc, char **argv){

  std::vector<AEvent> test=CollectDataFromFile(argv[1]);

  TCanvas* can=FullMap(test);
  can->Print("test.pdf","pdf");

  return 1;

}

