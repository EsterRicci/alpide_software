#include "AMask.hh"
#include "AHit.hh"
#include "AEvent.hh"
#include "ATools.hh"

#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>


AMask::AMask(){


}
AMask::AMask(std::vector<AHit> failingPixel){

  fail=failingPixel;
}

std::vector<AHit> AMask::GetFailingPixel(){

  return fail;

}

void AMask::SetFailingPixel(std::vector<AHit> failingPixel){

  fail=failingPixel;
  return;

}

int AMask::GetFailingPixelNumber(){

  return fail.size();
}

void AMask::Dump(){

  int size=fail.size();
  std::cout<<"**************************************"<<std::endl
	   <<"# of failing pixels= "<<size<<std::endl;
  
  if(size>0){
    std::cout<<"A list of the failinf pixels follows:"<<std::endl;
    for(int ip=0;ip<size;++ip)
      std::cout<<"X = "<<fail.at(ip).GetX()<<"\t Y = "<<fail.at(ip).GetY()<<std::endl;

  }
  std::cout<<"**************************************"<<std::endl;
  return;
}


void AMask::Write(std::string outputfile){

  std::ofstream out(outputfile);
  int size=fail.size();
  for(int ih=0;ih<size;++ih){
    out<< fail.at(ih).GetX() <<"\t"<< fail.at(ih).GetY()<<std::endl;
    }
  return;
}

AMask AMask::Read(std::string inputfile){
  std::vector<AHit> pixels;
  std::ifstream in(inputfile);
  int x=0;
  int y=0;
  
  while(!in.eof()){
    in>>x>>y;
    AHit px(x,y);
    pixels.push_back(px);
  }
  AMask result(pixels);  

  return result;
}
