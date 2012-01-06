void overlaytemplates(void) {

  gROOT->SetStyle("Plain");
  bool write = true;
  TFile *Output = new TFile("LP_templates38_littlePUvsfullPU_WJetsZ2Fall10_Madgraph_RECO2.root","RECREATE");
  TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_newJetColl.root");
  //TFile * file1 = TFile::Open("results/RecoRoutines_W-selection_WJetsMGZ238PU.root");
  TFile * file1 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_newJetColl_10pcrelpfmetsmear.root");

  TString basepath = "RECO_PolPlots_50toinf/";

  TString tempflav[3] = {"_LH", "_RH", "_LO"};
  TString charge[2] = {"Plus", "Minus"};

  int rbin=25;

  bool plotTemplates = false;
  
  TCanvas * templates[6] = {makeCanvas("pLP_LH"),makeCanvas("pLP_RH"),makeCanvas("pLP_LO"),makeCanvas("mLP_LH"),makeCanvas("mLP_RH"),makeCanvas("mLP_LO")};
  TCanvas * templateratios[6] = {makeCanvas("pLP_LHr"),makeCanvas("pLP_RHr"),makeCanvas("pLP_LOr"),makeCanvas("mLP_LHr"),makeCanvas("mLP_RHr"),makeCanvas("mLP_LOr")};
  
  TCanvas * histos[4] = {makeCanvas("pLP"), makeCanvas("mLP"), makeCanvas("pMET"), makeCanvas("mMET")};
  TCanvas * histosratio[4] = {makeCanvas("pLPr"), makeCanvas("mLPr"), makeCanvas("pMETr"), makeCanvas("mMETr")};
  TString histosname[4] = {"RECO_ICVarPFPlus", "RECO_ICVarPFMinus", "RECO_pfMETPlus", "RECO_pfMETMinus"};
  double xrangemin[4] = {-0.5, -0.5, 0.0, 0.0};
  double xrangemax[4] = {1.5, 1.5, 150.0, 150.0};

  if(plotTemplates) {
    for(unsigned int i=0; i<2; i++) {
      for(unsigned int j=0; j<3; j++) {
	
	int index = (i*3) + j;
	
	TH1F * pLP_LH_lpu = (TH1F*)file0->Get(basepath+"RECO_ICVarPF"+charge[i]+tempflav[j]);
	TH1F * pLP_LH_fpu = (TH1F*)file1->Get(basepath+"RECO_ICVarPF"+charge[i]+tempflav[j]+"_vw");
	
	pLP_LH_lpu->Rebin(rbin);
	pLP_LH_fpu->Rebin(rbin);
	
	templates[index]->cd();
	pLP_LH_lpu->SetLineColor(kRed);
	pLP_LH_lpu->GetXaxis()->SetRangeUser(-0.5,1.5);
	pLP_LH_lpu->DrawCopy();
	pLP_LH_fpu->DrawCopy("same");
	
	templateratios[index]->cd();
	pLP_LH_fpu->GetXaxis()->SetRangeUser(0.0,1.3);
	pLP_LH_fpu->GetYaxis()->SetRangeUser(0.9,1.1);
	pLP_LH_fpu->GetYaxis()->SetTitle("Ratio Full:Little PU");
	pLP_LH_fpu->Divide(pLP_LH_lpu);
	pLP_LH_fpu->DrawCopy();
      }
    }
  }

  for(unsigned int m=0; m<4; m++) {
    TH1F * hist1 = (TH1F*)file0->Get(basepath+histosname[m]);
    TH1F * hist2 = (TH1F*)file1->Get(basepath+histosname[m]);
	
    hist1->Rebin(rbin);
    hist2->Rebin(rbin);
	
    histos[m]->cd();
    hist1->SetLineColor(kRed);
    hist1->GetXaxis()->SetRangeUser(xrangemin[m],xrangemax[m]);
    hist1->DrawCopy();
    hist2->DrawCopy("same");
	
    histosratio[m]->cd();
    if(m==0 || m==1) hist2->GetXaxis()->SetRangeUser(0.0,1.3);
    hist2->GetYaxis()->SetRangeUser(0.9,1.1);
    hist2->GetYaxis()->SetTitle("Ratio Full:Little PU");
    hist2->Divide(hist1);
    hist2->DrawCopy();
  }
  
  if(write) {
    Output->cd();
    if(plotTemplates) {
      for(unsigned int k=0; k<5; k++) {
	templates[k]->Write();
	templateratios[k]->Write();
      }
    }
    for(unsigned int n=0;n<4;n++) {
      histos[n]->Write();
      histosratio[n]->Write();
    }
    Output->Close();
  }
  
  file1->Close();
  file0->Close();
  return;
}

TCanvas * makeCanvas(TString & name) {
  TCanvas * c1 = new TCanvas(name, name, 600, 620);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.06);
  c1->SetTopMargin(0.04);
  c1->SetBottomMargin(0.16);
  return c1;
}

