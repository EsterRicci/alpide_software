#ifndef _AGRAPHICTOOLS_
#define _AGRAPHICTOOLS_

#include "AEvent.hh"

#include <vector>
#include <string>

#include "TCanvas.h"
#include "TH2.h"
#include "TH1.h"

const int XPIXEL=1048;
const int YPIXEL=512;

TH2I* FullMap(std::vector<AEvent> input,std::string filename);
TCanvas* SingleEvent(AEvent input);
TH1I* ClusterSizeHisto(std::vector<AEvent> input,std::string inputname);
TCanvas* ClusterSizePlot(std::vector<AEvent> input,std::string inputname);
TH1I* EntriesPerPixel(TH2I* map,int ntrig);
TCanvas* ClusterSizeDistribution(std::vector<double> x,std::vector<double> y,std::vector<double> y_err,std::string title);
//Debug Tools
TH1I* EventSizeDistribution(std::vector<AEvent> input,std::string inputname);
TH2I* MapEventSized(std::vector<AEvent> input, int size,std::string inputname);

#endif
