void copy_histos()
{

 TFile *datafile1 = new TFile("wplusjets_madgraph_7TeVConceptTest7to10.root");  
 TFile *datafile2 = new TFile("7to10_WJets_madgraph_6.root"); 
 TFile *outputfile = TFile::Open("output.root", "RECREATE");

 TH1D* hist1 = (TH1D*)datafile1->Get("MC_7to10/MC_WPtMuonAcc");
 TH1D* hist2 = (TH1D*)datafile2->Get("MC_7to10/MC_WPtMuonAcc");

 hist1->Write();
 hist2->Write();

 outputfile->Write();
 outputfile->Close();
}
