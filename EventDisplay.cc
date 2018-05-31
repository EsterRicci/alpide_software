#include "AQLTools.hh"

#include <string>

int main(int argc, char** argv){
  if(argc==3){
  int ev=std::stoi(argv[2]);
  SingleEventDisplay(argv[1],ev);
  }
  else if(argc==2){
    ShowMultiClusterEvents(argv[1]);
  }
  return 0;
}
