#include "AEvent.hh"
#include "ACluster.hh"
#include "AHit.hh"

#include <vector>

std::vector<ACluster> FillClusters(std::vector<AHit> input);
std::vector<AEvent> CollectDataFromFile(std::string filename);

