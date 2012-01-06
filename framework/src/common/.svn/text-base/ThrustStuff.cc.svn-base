#include "EventData.hh"
#include "ThrustStuff.hh"
#include <Math/VectorUtil.h>
#include <Math/LorentzVector.h>
#include "Jet.hh"

//ThrustStuff::ThrustStuff(const std::vector<TLorentzVector> & objects){
ThrustStuffVar::ThrustStuffVar(const Event::Data & ev) :
    Compute::Variable<ThrustStuff,ThrustStuffVar >(ev) {}

void ThrustStuffVar::_Update() const
{
  mData = ThrustStuff( mEv.CommonObjects() );
}

ThrustStuff::ThrustStuff()
{}

ThrustStuff::ThrustStuff(const std::vector<LorentzV> & objects){
  float HTtest;
  float max = 0;
  float angle=0;
  float anglemax=0; // phi angle of thrust axis
  HTFmax=0;// the Ht in direction of thrust axis
  HTFmin=0;
  MHTFmax=0;
  MHTFmin=0;

  //  LorentzV MHT(0,0,0,0);
  for(float i =0 ;i < 100;i++) // 100 axis are tried, the one with the highest projected Et is taken as thrust axis
    {
      angle=i*0.0314;
      float MHTmax=0;
      float MHTmin=0;
      float  HTmin=0 ;
      float  HTmax=0;
      //for (std::vector<TLorentzVector>::const_iterator gj = objects.begin(); gj != objects.end(); ++gj) {
      for (std::vector<LorentzV>::const_iterator gj = objects.begin(); gj != objects.end(); ++gj) {
	HTtest = HTtest + (*gj).Pt();
	HTmax =HTmax+ fabs(cos( angle-(*gj).Phi() ))*(*gj).Pt();
	MHTmax =MHTmax  + cos( angle-(*gj).Phi() )*(*gj).Pt();
	HTmin = HTmin+ fabs(sin(angle-(*gj).Phi()))*(*gj).Pt();
	MHTmin = MHTmin + sin(angle-(*gj).Phi())*(*gj).Pt();
      }// end of loop over good jets

      if (HTmax>max) {anglemax=angle;max=HTmax;HTFmax=HTmax;HTFmin=HTmin; MHTFmax=MHTmax;MHTFmin= MHTmin; }

      HTmax=0;
      HTmin=0;
      HTtest=0;
    }

  ThrustDirection = LorentzV(cos(anglemax),sin(anglemax),0,1);

  //  float MHTmax = fabs(cos(ROOT::Math::VectorUtil::DeltaPhi(MHT,ThrustDirection))*MHT);
  //  float MHTmin = sqrt(MHT*MHT-MHTmax*MHTmax);

  //  if(ThrustDirection.Phi()!=anglemax)  cout << "ThrustStuff ARRG: ThrustDirection.Phi()!=anglemax "<<  ThrustDirection.Phi() << " = "<<anglemax<<" "<< anglemax- ThrustDirection.Phi() <<" " << anglemax+ThrustDirection.Phi() <<endl;

  // TLorentzVector vec1(0,0,0,0);
  // TLorentzVector vec2(0,0,0,0);
  // TLorentzVector vec3(0,0,0,0);

  LorentzV vec1(0,0,0,0);
  LorentzV vec2(0,0,0,0);
  LorentzV vec3(0,0,0,0);

  HTjet2=0;
  HTjet1=0;
  float dPhiMin =1000;
  float smalest=0;
  int aCounter =0;
  int x = 0;
  int y = 0;


  //  for (std::vector<TLorentzVector>::const_iterator gj = objects.begin(); gj != objects.end(); ++gj) {
  for (std::vector<LorentzV>::const_iterator gj = objects.begin(); gj != objects.end(); ++gj) {
    //  if(dPhiMin>CalcDPhi(anglemax,(*gj).Phi())) old code
    if(dPhiMin>fabs(ROOT::Math::VectorUtil::DeltaPhi(*gj,ThrustDirection)))

      {
	dPhiMin = fabs(ROOT::Math::VectorUtil::DeltaPhi(*gj,ThrustDirection));
	smalest = dPhiMin;
    }

    if(fabs(ROOT::Math::VectorUtil::DeltaPhi(*gj,ThrustDirection))<TMath::Pi()/2.)
      {
	vec3 = vec3+(*gj);
       	HTjet1+=(*gj).Pt();
	vec1 = vec1+(*gj);
	//	p1[0]+=(*gj).Px();
	//	p1[1]+=(*gj).Py();
	x++;
      }
    else
      {
	vec3 = vec3+(*gj);
      	HTjet2+=(*gj).Pt();
	vec2 = vec2+(*gj);
	//	p2[0]+=(*gj).Px();
	//	p2[1]+=(*gj).Py();
	y ++;
      }
    aCounter++;
  }
  Pjet1 = vec1;
  Pjet2 = vec2;
  if((HTjet2*HTjet2)-(vec2.Pt()*vec2.Pt())>0)  MTjet2=sqrt((HTjet2*HTjet2)-(vec2.Pt()*vec2.Pt()));
  else  MTjet2=0;
  if((HTjet1*HTjet1)-(vec1.Pt()*vec1.Pt())>0) MTjet1=sqrt((HTjet1*HTjet1)-(vec1.Pt()*vec1.Pt()));
  else  MTjet1=0;


  pjetDphi=fabs(ROOT::Math::VectorUtil::DeltaPhi(vec2,vec1));
  if(vec2.Pt()==0||vec1 .Pt()==0)pjetDphi = 0;

;
}

//ThrustStuff::~ThrustStuff(){;}
