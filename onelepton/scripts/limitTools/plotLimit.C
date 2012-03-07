#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct myStruct
{
  char chr;
  int m0;
  int m12;
  double cls;

};

//   std::istream & operator>>(std::istream &is, myStruct &my)
// {

//   if (std::getline(is, my.chr))
//     return is >> my.m0 >> my.m12 >> my.cls;

// }

void plotLimit(TString ifile="cls_explimit_median_ht750.txt") {

  TH2D *h = new TH2D("h","",200,0.,2000.,80,0.,800.);
  TH2D *h0 = new TH2D("h0","",200,0.,2000.,80,0.,800.);

  std::ifstream file(ifile);
  std::string line;

  double num[3];

  while (std::getline(file, line))
    {
      istringstream ss(line);
      double d;

      int i=0;
      while (ss >> d) {
	num[i]=d;
	//	std::cout << d << std::endl;
	i++;
      }
      //std::cout << num[0] << "\t" << num[1] << "\t" << num[2] << std::endl;

      // Fill in the 2D Histogram
      double res;
      res=( (num[2]<0.05 && num[2]>0) ? 1. : 0. );
      //  std::cout << num[0] << "\t" << num[1] << "\t" << res << std::endl;
      h->Fill(num[0],num[1],res);

      double res0;
      res0=( (num[2]==0) ? 2. : 0. );
      h->Fill(num[0],num[1],res0);

    }

  gStyle->SetPalette(1);

  TCanvas *c = new TCanvas("c","");
  gPad->SetGridx(); gPad->SetGridy();
  h->SetStats(kFALSE);
  h->Draw("COLZ"); //  h->SetMarkerColor(1);
  //  h0->Draw("SAMECOL"); h0->SetMarkerColor(2); //h0->SetMarkerSize(1.0);
  h->SetTitle(";m_{0};m_{1/2}");
}
