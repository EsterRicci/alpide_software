#include "AHit.hh"



AHit::AHit(int xin,int yin)
{
  x=xin;
  y=yin;
}
AHit::AHit(){
  x=-9999;
  y=-9999;

}

int AHit::GetX(){

  return x;
}

int AHit::GetY(){

  return y;
}

void AHit::SetX(int xin){

  x=xin;
  return;

}

void AHit::SetY(int yin){

  y=yin;
  return;

}
