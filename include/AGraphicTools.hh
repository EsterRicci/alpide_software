#ifndef _AGRAPHICTOOLS_
#define _AGRAPHICTOOLS_

#include "AEvent.hh"

#include <vector>
#include <string>

#include "TCanvas.h"
#include "TH2.h"

const int XPIXEL=1048;
const int YPIXEL=512;

TH2I* FullMap(std::vector<AEvent> input);
TCanvas* SingleEvent(AEvent input);
TCanvas* ClusterSizePlot(std::vector<AEvent> input,std::string inputname);

#endif
