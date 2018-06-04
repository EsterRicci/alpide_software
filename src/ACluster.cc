#include "ACluster.hh"
#include "AHit.hh"

#include <vector>
#include <iostream>
#include <cmath>

ACluster::ACluster(){

}

void ACluster::AddHit(AHit newhit){

  clusterhits.push_back(newhit);
  return;

}

AHit ACluster::GetHit(int hitID){
  AHit result;
  if(hitID<clusterhits.size()) result=clusterhits.at(hitID);
  else std::cout<<"Warning! The size of the cluster is "<<clusterhits.size()<<". Returning a null hit!";
  return result;


}

int ACluster::GetClusterSize(){
  return clusterhits.size();

}

void ACluster::Dump(){
  int size=clusterhits.size();
  std::cout<<"*******************************"<<std::endl;
  std::cout<< "Cluster Size = "<<size <<std::endl;
  for(int ih;ih<size;++ih)  
    std::cout<< "x= "<< clusterhits.at(ih).GetX() <<" y= "<< clusterhits.at(ih).GetY()<<std::endl;
  std::cout<<"*******************************"<<std::endl;
  return;
}

int ACluster::GetXMean(){
  int xmean=0;
  for(int ih=0;ih<clusterhits.size();++ih){
    xmean+=clusterhits.at(ih).GetX();
  }
  xmean/=clusterhits.size();
  return xmean;
}

int ACluster::GetYMean(){
  int ymean=0;
  for(int ih=0;ih<clusterhits.size();++ih){
    ymean+=clusterhits.at(ih).GetY();
  }
  ymean/=clusterhits.size();
  return ymean;
}

double ACluster::GetSigmaX(){
  double sigmax=0;
  double xmean=0;
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    xmean+=clusterhits.at(ihit).GetX();
  }
  xmean/=clusterhits.size();
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    sigmax+=(clusterhits.at(ihit).GetX()-xmean)*(clusterhits.at(ihit).GetX()-xmean);
  }
  sigmax/=(clusterhits.size()-1);
  sigmax=sqrt(sigmax);
  return sigmax;

}

double ACluster::GetSigmaY(){
  double sigmay=0;
  double ymean=0;
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    ymean+=clusterhits.at(ihit).GetY();
  }
  ymean/=clusterhits.size();
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    sigmay+=(clusterhits.at(ihit).GetY()-ymean)*(clusterhits.at(ihit).GetY()-ymean);
  }
  sigmay/=(clusterhits.size()-1);
  sigmay=sqrt(sigmay);
  return sigmay;

}

double ACluster::GetSigmaPi4(){
  double sigmapi4=0;
  double ymean=0;
  double xmean=0;
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    xmean+=clusterhits.at(ihit).GetX();
    ymean+=clusterhits.at(ihit).GetY();
  }
  xmean/=clusterhits.size();
  ymean/=clusterhits.size();
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    sigmapi4+=(clusterhits.at(ihit).GetY()+clusterhits.at(ihit).GetX()-(ymean+xmean))*(clusterhits.at(ihit).GetY()+clusterhits.at(ihit).GetX()-(ymean+xmean));
  }
  sigmapi4/=(clusterhits.size()-1);
  sigmapi4=sqrt(sigmapi4);
  return sigmapi4;

}

double ACluster::GetSigma3Pi4(){
  double sigma3pi4=0;
  double ymean=0;
  double xmean=0;
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    xmean+=clusterhits.at(ihit).GetX();
    ymean+=clusterhits.at(ihit).GetY();
  }
  xmean/=clusterhits.size();
  ymean/=clusterhits.size();
  for(int ihit=0;ihit<clusterhits.size();++ihit){
    sigma3pi4+=(clusterhits.at(ihit).GetY()-clusterhits.at(ihit).GetX()-(ymean-xmean))*(clusterhits.at(ihit).GetY()-clusterhits.at(ihit).GetX()-(ymean-xmean));
  }
  sigma3pi4/=(clusterhits.size()-1);
  sigma3pi4=sqrt(sigma3pi4);
  return sigma3pi4;

}
