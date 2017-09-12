#include "ATools.hh"

#include <fstream>
#include <iostream>

int main(int argc,char **argv){
  if(argc!=3){
    std::cout<<"Please type: ./CreateMask <inputfile> <outputfile>"<<std::endl;
    return 0;
  }
  else{
  AMask test=CreateMask(argv[1],100000);
  test.Dump();
  test.Write(argv[2]);

  return 1;
  }
}
