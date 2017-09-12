#ifndef _AMASK_
#define _AMASK_ 1

#include "AHit.hh"

#include <vector>
#include <string>

class AMask{
public:
  AMask();
  AMask(std::vector <AHit> failingPixel);
  std::vector<AHit> GetFailingPixel();
  void SetFailingPixel(std::vector<AHit> failinfPixel);
  int GetFailingPixelNumber();
  void Dump();
  //Mask tools
  void Write(std::string outputfile);
  AMask Read(std::string inputfile);
  
private:
  std::vector<AHit> fail;



};


#endif
