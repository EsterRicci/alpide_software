#include "AEvent.hh"
#include "ACluster.hh"
#include "AHit.hh"
#include "AMask.hh"

#include <vector>
#include <string>

std::vector<ACluster> FillClusters(std::vector<AHit> input);
std::vector<AEvent> CollectDataFromFile(std::string filename,AMask mymask);
AMask CreateMask(std::string inputfile,int trignum);

