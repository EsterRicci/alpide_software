#ifndef __AANALYSIS__
#define __ANALYSIS__ 1

void ClusterAnalysisEnergy(const char *filelist, const char* outputname);
void ClusterAnalysisEdep(const char* filelist, const char* outputname);
void StrobeEffect(const char *filelist, const char* outputname);
void BiasEffect(const char* list1,const char* list2, const char* list3,const char* outname);
void BiasEffectEdep(const char* list1,const char* list2, const char* list3,const char* simulation, const char* outname);

#endif
