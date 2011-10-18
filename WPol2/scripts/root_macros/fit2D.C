void fit2D(void) {
  ofstream ai_params("ai_params_wjetsfall2010z2_50toinf.txt");
  ai_params << "jAiFitParameters AiParams;" << std::endl;
  ai_params << "std::vector<std::vector<jAiFitParameters> > PtYweights(3, std::vector<jAiFitParameters>(7));" << std::endl;

  //in this file, we compare three methods of extracting the Ai in the helicity frame
  //1. a 2D fit in the [cos(theta*), phi*] plane
  //2. two 1D fits of cos(theta*) and phi* independently (no A1 value)
  //3. the moment method
  TFile *file0 = TFile::Open("results/WeightingRoutines/WeightingRoutines_WJets_madgraph_Fall2010Z2.root");
  bool verbose = true;

  for(unsigned int i=0; i<3; i++) {
    for(unsigned int j=0; j<7; j++) {
      std::ostringstream YB;
      std::ostringstream PB;
      YB << j;
      PB << i;
      TString foldername = "MC_WPlots_P" + PB.str() + "Y" + YB.str();

      TH2D * pCosTheta_Phi = (TH2D*)file0->Get(foldername + "/MC_PhiStar_vs_CosThetaStar_Plus");
      TH2D * mCosTheta_Phi = (TH2D*)file0->Get(foldername + "/MC_PhiStar_vs_CosThetaStar_Minus");
      TH1D * pCosTheta = (TH1D*)file0->Get(foldername + "/MC_CosThetaStar1Plus");
      TH1D * mCosTheta = (TH1D*)file0->Get(foldername + "/MC_CosThetaStar1Minus");
      TH1D * pPhi = (TH1D*)file0->Get(foldername + "/MC_PhiStar1Plus");
      TH1D * mPhi = (TH1D*)file0->Get(foldername + "/MC_PhiStar1Minus");

      TString HistPA0 = foldername + "/MC_HWPlusA0Numerator";
      TString HistPA1 = foldername + "/MC_HWPlusA1Numerator";
      TString HistPA2 = foldername + "/MC_HWPlusA2Numerator";
      TString HistPA3 = foldername + "/MC_HWPlusA3Numerator";
      TString HistPA4 = foldername + "/MC_HWPlusA4Numerator";
      TString HistPD = foldername + "/MC_HWPlusAiDenominator";

      TString HistMA0 = foldername + "/MC_HWMinusA0Numerator";
      TString HistMA1 = foldername + "/MC_HWMinusA1Numerator";
      TString HistMA2 = foldername + "/MC_HWMinusA2Numerator";
      TString HistMA3 = foldername + "/MC_HWMinusA3Numerator";
      TString HistMA4 = foldername + "/MC_HWMinusA4Numerator";
      TString HistMD = foldername + "/MC_HWMinusAiDenominator";

      TH1D *hPA0 = (TH1D*)file0->Get(HistPA0);
      TH1D *hPA1 = (TH1D*)file0->Get(HistPA1);
      TH1D *hPA2 = (TH1D*)file0->Get(HistPA2);
      TH1D *hPA3 = (TH1D*)file0->Get(HistPA3);
      TH1D *hPA4 = (TH1D*)file0->Get(HistPA4);
      TH1D *hPD = (TH1D*)file0->Get(HistPD);

      TH1D *hMA0 = (TH1D*)file0->Get(HistMA0);
      TH1D *hMA1 = (TH1D*)file0->Get(HistMA1);
      TH1D *hMA2 = (TH1D*)file0->Get(HistMA2);
      TH1D *hMA3 = (TH1D*)file0->Get(HistMA3);
      TH1D *hMA4 = (TH1D*)file0->Get(HistMA4);
      TH1D *hMD = (TH1D*)file0->Get(HistMD);

      pCosTheta_Phi->RebinX(10);
      pCosTheta_Phi->RebinY(10);
      //pCosTheta_Phi->DrawCopy("col");

      mCosTheta_Phi->RebinX(10);
      mCosTheta_Phi->RebinY(10);

      TF2 *f2 = new TF2("f2","[0]*((1.0+(x*x)) + 0.5*[1]*(1.0 - (3.0*x*x)) + [2]*2.0*x*TMath::Sqrt(1.0 - (x*x))*TMath::Cos(y) + 0.5*[3]*(1.0 - (x*x))*TMath::Cos(2.0*y) + [4]*TMath::Sqrt(1.0 - (x*x))*TMath::Cos(y) + [5]*x  )",-1.00, 1.00, -3.10,3.10);

      pCosTheta_Phi->Fit("f2", "QR");//R specifies to fit within the range specified in the TF1 function, Q specifies quiet
      double pA02D = f2->GetParameter(1);
      double pA12D = f2->GetParameter(2);
      double pA22D = f2->GetParameter(3);
      double pA32D = f2->GetParameter(4);
      double pA42D = f2->GetParameter(5);
      //f2->DrawCopy("cont1 same");

      mCosTheta_Phi->Fit("f2", "QR");
      double mA02D = f2->GetParameter(1);
      double mA12D = f2->GetParameter(2);
      double mA22D = f2->GetParameter(3);
      double mA32D = f2->GetParameter(4);
      double mA42D = f2->GetParameter(5);

      TF1 * fphi = new TF1("fphi","[2]*( 1.0 + ((3.0*TMath::Pi()/16.0)*[1]*TMath::Cos(x)) + (([0]/4.0)*TMath::Cos(2.0*x)) )",-3.10,3.10);
      TF1 * fcostheta = new TF1("fcostheta","[2]*( (1.0+(0.5*[0])) + [1]*x + ((1.0-(1.5*[0]))*(x*x)))",-1.00,1.00);

      pPhi->Fit("fphi", "QR");
      double pA21D = fphi->GetParameter(0);
      double pA31D = fphi->GetParameter(1);

      mPhi->Fit("fphi", "QR");
      double mA21D = fphi->GetParameter(0);
      double mA31D = fphi->GetParameter(1);

      pCosTheta->Fit("fcostheta", "QR");
      double pA01D = fcostheta->GetParameter(0);
      double pA41D = fcostheta->GetParameter(1);

      mCosTheta->Fit("fcostheta", "QR");
      double mA01D = fcostheta->GetParameter(0);
      double mA41D = fcostheta->GetParameter(1);

      if(verbose) {
	cout << "(Moment Method, 2D Method, 1D Method) for all Ai" << endl;
	cout << "Plus: " << endl;
	cout << "pA0 = (" << (2.0/3.0) + ((20.0/3.0)*hPA0->Integral() / hPD->Integral()) << ", " << pA02D << ", " << pA01D << ")" << endl;
	cout << "pA1 = (" << 5.0* hPA1->Integral() / hPD->Integral() << ", " << pA12D << ")" << endl;
	cout << "pA2 = (" << 10.0* hPA2->Integral() / hPD->Integral() << ", " << pA22D << ", " << pA21D << ")" << endl;
	cout << "pA3 = (" << 4.0* hPA3->Integral() / hPD->Integral() << ", " << pA32D << ", " << pA31D << ")" << endl;
	cout << "pA4 = (" << 4.0* hPA4->Integral() / hPD->Integral() << ", " << pA42D << ", " << pA41D << ")" << endl;
	cout << "Minus: " << endl;  
	cout << "mA0 = (" << (2.0/3.0) + ((20.0/3.0)*hMA0->Integral() / hMD->Integral()) << ", " << mA02D << ", " << mA01D << ")" << endl;
	cout << "mA1 = (" << 5.0* hMA1->Integral() / hMD->Integral() << ", " << mA12D << ")" << endl;
	cout << "mA2 = (" << 10.0* hMA2->Integral() / hMD->Integral() << ", " << mA22D << ", " << mA21D << ")" << endl;
	cout << "mA3 = (" << 4.0* hMA3->Integral() / hMD->Integral() << ", " << mA32D << ", " << mA31D << ")" << endl;
	cout << "mA4 = (" << 4.0* hMA4->Integral() / hMD->Integral() << ", " << mA42D << ", " << mA41D << ")" << endl;
      }
      
      ai_params << "AiParams.pA0 = " << (2.0/3.0) + ((20.0/3.0)*hPA0->Integral() / hPD->Integral()) << ";" << endl;
      ai_params << "AiParams.pA1 = " << 5.0* hPA1->Integral() / hPD->Integral() << ";" << endl;
      ai_params << "AiParams.pA2 = " << 10.0* hPA2->Integral() / hPD->Integral() << ";" << endl;
      ai_params << "AiParams.pA3 = " << 4.0* hPA3->Integral() / hPD->Integral() << ";" << endl;
      ai_params << "AiParams.pA4 = " << 4.0* hPA4->Integral() / hPD->Integral() << ";" << endl;
      ai_params << "AiParams.mA0 = " << (2.0/3.0) + ((20.0/3.0)*hMA0->Integral() / hMD->Integral()) << ";" << endl;
      ai_params << "AiParams.mA1 = " << 5.0* hMA1->Integral() / hMD->Integral() << ";" << endl;
      ai_params << "AiParams.mA2 = " << 10.0* hMA2->Integral() / hMD->Integral() << ";" << endl;
      ai_params << "AiParams.mA3 = " << 4.0* hMA3->Integral() / hMD->Integral() << ";" << endl;
      ai_params << "AiParams.mA4 = " << 4.0* hMA4->Integral() / hMD->Integral() << ";" << endl;

      ai_params << "PtYweights.at(" << i << ").at(" << j << ") = AiParams;" << endl;
    }
  }
  ai_params.close();
  return;
  //the below is to compare bin content to the result of the integral fit
  //NOTE: THE INTEGRAL OF THE CROSS-SECTION IS CALCULATED BELOW! MAY BE USEFUL
  
  //numbers for minus charge
  double N = 27.6529;
  double A0 = 0.4022;//0.4054;
  double A1 = -0.09739;//-0.0985;
  double A2 = 0.3091;//0.3050;
  double A3 = 0.0064;//0.00660;
  double A4 = 0.5301;//0.5268;

  double tb = 0.1; //cos theta* bin width
  double pb = 0.1; //phi* bin width

  double tbin = -1.0; //cos theta* bin
  double pbin = -3.0; //phi* bin

  TH1D * jadtemp = new TH1D("jadtemp", ";;", 1000, -5.0, 5.0);

  for(tbin = -1.0; tbin < 0.9; tbin+=tb) {
    for(pbin = -3.1; pbin < 3.1; pbin+=pb) {

      double part1 = pb * (tb + (1.0 / 3.0)*((tbin+tb)*(tbin+tb)*(tbin+tb) - tbin*tbin*tbin));
      double part2 = pb * (tb - ((tbin+tb)*(tbin+tb)*(tbin+tb) - tbin*tbin*tbin));
      double part3 = (TMath::Sin(pbin + pb) - TMath::Sin(pbin)) * (-2.0/3.0)*((TMath::Sqrt(1.0 - (tbin+tb)*(tbin+tb))*(1.0 - (tbin+tb)*(tbin+tb))) - (TMath::Sqrt(1.0 - (tbin*tbin))*(1.0 - (tbin*tbin))));
      double part4 = (0.5 * (TMath::Sin(2.0*(pbin + pb)) - TMath::Sin(2.0*pbin)) * (tb - (1.0 / 3.0)*((tbin+tb)*(tbin+tb)*(tbin+tb) - tbin*tbin*tbin)));
      double part5a = (TMath::Sin(pbin + pb) - TMath::Sin(pbin));
      double part5b = 0.5*((tbin+tb)*TMath::Sqrt(1.0 - (tbin+tb)*(tbin+tb)) - tbin*TMath::Sqrt(1.0 - (tbin*tbin)));
      double part5c = (0.5 * (TMath::ASin(tbin+tb) - TMath::ASin(tbin)));
      double part5 = part5a * (part5b + part5c);
      double part6 = pb * (0.5 * (((tbin+tb) * (tbin+tb)) - (tbin*tbin)) );

      //cout << "Part 1 = " << part1 << endl;
      //cout << "Part 2 = " << part2 << endl;
      //cout << "Part 3 = " << part3 << endl;
      //cout << "Part 4 = " << part4 << endl;
      //cout << "Part 5 = " << part5 << endl;
      //cout << "Part 5a = " << part5a << endl;
      //cout << "Part 5b = " << part5b << endl;
      //cout << "Part 5c = " << part5c << endl;
      //cout << "Part 6 = " << part6 << endl;

      double BinContent = N*( part1 + (0.5*A0*part2) + (A1*part3) + (0.5*A2*part4) + (A3*part5) + (A4*part6) );
      double TrueBinContent = mCosTheta_Phi->GetBinContent(mCosTheta_Phi->FindBin(tbin, pbin));
      
      //cout << "Integral over bin is: " << BinContent << endl;
      //cout << "True Bin Content is: " << TrueBinContent << endl;
      //cout << "(tbin, pbin) = (" << tbin << ", " << pbin << ")" << endl; 

      double relativediff = (TrueBinContent - BinContent) / TrueBinContent;
      jadtemp->Fill(relativediff);
    }
  }

  jadtemp->Draw();
  return;
}
