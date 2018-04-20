#ifndef _AGRAPHICTOOLS_
#define _AGRAPHICTOOLS_

#include "AEvent.hh"

#include <vector>
#include <string>

#include "TCanvas.h"
#include "TH2.h"
#include "TH1.h"
#include "TGraph.h"
#include "TGraphErrors.h"

const int XPIXEL=1048;
const int YPIXEL=512;

TH2I* FullMap(std::vector<AEvent> input,std::string filename);
TCanvas* SingleEvent(AEvent input);
TH1I* ClusterSizeHisto(std::vector<AEvent> input,std::string inputname);
TCanvas* ClusterSizePlot(std::vector<AEvent> input,std::string inputname);
TH1I* EntriesPerPixel(TH2I* map,int ntrig);
TGraphErrors* ClusterSizePlot(std::vector<double> x,std::vector<double> y,std::vector<double> y_err,std::string title);
TGraphErrors* ClusterSizePlot(std::vector<double> x,std::vector<double> y,std::vector<double> x_err,std::vector<double> y_err,std::string title);
TCanvas* ClusterSizeDistribution(std::vector<double> x,std::vector<double> y,std::vector<double> y_err,std::string title,bool logx=false);
TCanvas* ClusterSizeDistribution(std::vector<double> x,std::vector<double> y,std::vector<double> x_err,std::vector<double> y_err,std::string title,bool logx=false);
TCanvas* ResolutionDistribution(std::vector<double> x,std::vector<double> y,std::vector<double> y_err,std::string title);
TCanvas* EventNumberDistribution(std::vector<int> x, std::vector<int> y,const char* title,bool logx=false,bool logy=false);
TGraph *EventNumber(std::vector<int> x, std::vector<int> y,const char* title);
//Debug Tools
TH1I* EventSizeDistribution(std::vector<AEvent> input,std::string inputname);
TH2I* MapEventSized(std::vector<AEvent> input, int size,std::string inputname);

#endif
