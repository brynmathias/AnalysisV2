{
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  //CONFIGURATION
  //LEPTON CUT

  vector<TString> lepcuts;
  lepcuts.push_back("2");
  lepcuts.push_back("5");
  lepcuts.push_back("10");
  lepcuts.push_back("15");
  //  lepcuts.push_back("20");
//  lepcuts.push_back("30");
  int reb=5;
  TCanvas *c5= new TCanvas("c5","",0,0,700,700);

  //  c5->Divide(1,lepcuts.size());
  c5->Divide(1,2);
  for (int iii=0; iii<lepcuts.size(); iii++){
    TLegend *l5_2 = new TLegend(0.65,0.7,0.9,0.9);

    TLegend *l5_1 = new TLegend(0.65,0.7,0.9,0.9);


    cout<<"a1"<<endl;
 
    //FILE TO READ
    TString fileqcd="QCD.root";
    TString fileall="all.root";
    TFile *_file0 = TFile::Open(fileqcd);
    TFile *_file1 = TFile::Open(fileall);
    //    TFile *_file2 = TFile::Open("TopSusy_qcd100To250.root");
    //    TFile *_file2 = TFile::Open("TopSusy_qcd250To500.root");
    TFile *_file2 = TFile::Open("TopSusy_qcd500To1000.root");
    //    TFile *_file2 = TFile::Open("TopSusy_qcd1000ToInf.root");
    //DIRECTORIES
    TString StandElSel      =  "singleElectron"+lepcuts[iii];
    TString LooseElSel      =  "singleElectronIsoLoose"+lepcuts[iii];
    TString LowMet          =  "singleElectronNjet"+lepcuts[iii];   
    TString title = "Pt > "+lepcuts[iii]+" GeV"; 
    TString file = "tkshape"+lepcuts[iii]+".gif";
    //REBINNING

    cout<<"a2"<<endl; 

 
    //FIT FUNCTIONS
     float maxx=25.0;
     float minn=5.0;
     TF1 *f1 = new TF1("f1","[0]*exp([1]*x)",0.0,maxx);
     f1->SetLineColor(2);
     f1->SetParLimits(0,0.1,0.3);
     TF1 *f2 = new TF1("f2","[0]*exp([1]*x)",minn,maxx); 
     f2->SetLineColor(2);
     TF1 *f3 = new TF1("f3","[0]*exp([1]*x)",0.0,maxx); 
     f3->SetLineColor(4);
     f3->SetLineStyle(7);

    cout<<"a3"<<endl; 

    c5->cd(1);
    _file0->cd(LooseElSel);
    h_el_tkisol_0->Rebin(reb);
    h_el_tkisol_0->SetMarkerStyle(21);
    h_el_tkisol_0->SetMarkerColor(4);
    h_el_tkisol_0->SetLineColor(4); 
    TH1D *ciccio= h_el_tkisol_0->Clone();
    TH1D CC(*ciccio);
    ciccio->Delete();
    float HHscale_fac=1./h_el_tkisol_0->Integral();    
    h_el_tkisol_0->SetTitle(title);
    h_el_tkisol_0->GetXaxis()->SetTitle("Tk Isolation (GeV) ");
    h_el_tkisol_0->GetYaxis()->SetTitle("dN/N");
    h_el_tkisol_0->Scale(HHscale_fac);
    h_el_tkisol_0->SetMinimum(0.);
    h_el_tkisol_0->SetMaximum(.6);
 
    l5_2->AddEntry( h_el_tkisol_0,"QCD (Event Selection)","p");
    h_el_tkisol_0->Draw();
    
    cout<<"a4"<<endl;

    _file0->cd(LowMet);
    h_el_tkisol_0->Rebin(reb);
    float scale_fac=1./h_el_tkisol_0->Integral();
    h_el_tkisol_0->Scale(scale_fac);
    h_el_tkisol_0->SetMarkerStyle(26);
    h_el_tkisol_0->SetMarkerColor(4);
    h_el_tkisol_0->SetLineColor(4);
    l5_2->AddEntry( h_el_tkisol_0,"QCD (Anti-Event Selection)","p");
    h_el_tkisol_0->Draw("same");     

    _file1->cd(LowMet);
    h_el_tkisol_0->Rebin(reb);
    float scale_fac=1./h_el_tkisol_0->Integral();
    h_el_tkisol_0->Scale(scale_fac);
    h_el_tkisol_0->SetMarkerStyle(26);
    h_el_tkisol_0->SetMarkerColor(2);
    h_el_tkisol_0->SetLineColor(2);
    l5_2->AddEntry( h_el_tkisol_0,"All (Anti-Event Selection)","p");
    h_el_tkisol_0->Draw("same");  
    h_el_tkisol_0->Fit("f1","R","same");
    l5_2->AddEntry(f1,"A*exp(-Bx)  0.0<x<25","l");
    l5_2->Draw();


    c5->cd(2);

    _file1->cd();
    _file1->cd(LooseElSel);
    h_el_tkisol_0->Rebin(reb);
    h_el_tkisol_0->GetXaxis()->SetTitle("Tk Isolation (GeV)");
    h_el_tkisol_0->GetYaxis()->SetTitle("Event");
    h_el_tkisol_0->SetMarkerStyle(21);
    h_el_tkisol_0->SetMarkerColor(2);
    h_el_tkisol_0->SetLineColor(2);
    l5_1->AddEntry( h_el_tkisol_0,"All (Event Selection)","p");
    h_el_tkisol_0->Draw();
    f2->FixParameter(1,f1->GetParameter(1));
    h_el_tkisol_0->Fit("f2","R","same");
    
    f3->FixParameter(1,f1->GetParameter(1));
    _file0->cd(LooseElSel);
    f3->FixParameter(0,f2->GetParameter(0));
    CC->Draw("same");
    f3->Draw("same");
    f2->Draw("same");
    l5_1->AddEntry( h_el_tkisol_0,"QCD (Event Selection)","p"); 
    l5_1->AddEntry(f2,"A'*exp(-Bx)  5<x<25","l");
    l5_1->AddEntry(f3,"Propagation","l");
    float extrapol= 
      (f2->GetParameter(0)/(f1->GetParameter(1) *h_el_tkisol_0->GetBinWidth(1)))*
      (1-exp(-3*f1->GetParameter(1)));
    
    _file0->cd(StandElSel);
    float eee=h_el_tkisol_0->Integral();
    cout<<"EXTRAPOLATED "<<extrapol<<" EXPECTED "<<eee<<endl;
    l5_1->Draw();
    c5->GetPad(2)->SetLogy();
    c5->SaveAs(file);
  }
}
