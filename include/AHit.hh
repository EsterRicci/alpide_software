#ifndef _AHIT_
#define _AHIT_ 1

class AHit{
public:
  AHit();
  AHit(int xin,int yin);
  int GetX();
  int GetY();
  void SetX(int xin);
  void SetY(int yin);

private:
  int x;
  int y;


};



#endif
