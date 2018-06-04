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
  else if(argc==4){
    int startev=std::stoi(argv[2]);
    int stopev=std::stoi(argv[3]);
    DisplayEventsInAInterval(argv[1],startev,stopev);
  }
  return 0;
}
