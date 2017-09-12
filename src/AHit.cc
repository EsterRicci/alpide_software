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

bool AHit::operator == (const AHit& hit) const{
  bool result = (x==hit.x && y==hit.y);
  return result;

}

AHit& AHit::operator=(const AHit& other){
  if(&other == this)
    return *this;
  this->x=other.x;
  this->y=other.y;
  return *this;
}
