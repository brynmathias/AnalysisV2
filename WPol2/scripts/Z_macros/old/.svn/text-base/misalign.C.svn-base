#include "TObject.h"

void misalign(double muptcutmin=45, double muptcutmax=400, int nbins=10, bool realdata=1){


TGraphErrors *graphp = new TGraphErrors();
TGraphErrors *graphm = new TGraphErrors();
TGraphErrors *graphp1 = new TGraphErrors();
TGraphErrors *graphm1 = new TGraphErrors();
TGraphErrors *graphp2 = new TGraphErrors();
TGraphErrors *graphm2 = new TGraphErrors();

graphp->SetTitle("RECO_0pcscale_MpPhivsrecobosonM_hrdMp");
graphm->SetTitle("RECO_0pcscale_MmPhivsrecobosonM_hrdMp");
graphp1->SetTitle("RECO_0pcscale_MpPhivsrecobosonM_hrdMp");
graphm1->SetTitle("RECO_0pcscale_MmPhivsrecobosonM_hrdMp");
graphp2->SetTitle("RECO_0pcscale_MpPhivsrecobosonM_hrdMp");
graphm2->SetTitle("RECO_0pcscale_MmPhivsrecobosonM_hrdMp");

TList *listp = new TList();
TList *listm = new TList();
TList *listp1 = new TList();
TList *listm1 = new TList();
TList *listp2 = new TList();
TList *listm2 = new TList();
for(int i=0;i<nbins;i++){
  listp->Add(fitmacro(muptcutmin,muptcutmax,i,nbins,+1,realdata,0));
 listm->Add(fitmacro(muptcutmin,muptcutmax,i,nbins,-1,realdata,0));
 listp1->Add(fitmacro(muptcutmin,muptcutmax,i,nbins,+1,realdata,1));
 listm1->Add(fitmacro(muptcutmin,muptcutmax,i,nbins,-1,realdata,1));
 listp2->Add(fitmacro(muptcutmin,muptcutmax,i,nbins,+1,realdata,2));
 listm2->Add(fitmacro(muptcutmin,muptcutmax,i,nbins,-1,realdata,2));

}
tgemerger(graphp,listp);
tgemerger(graphm,listm);
tgemerger(graphp1,listp1);
tgemerger(graphm1,listm1);
tgemerger(graphp2,listp2);
tgemerger(graphm2,listm2);

graphp->SetLineWidth(3);
graphp->SetLineColor(kRed);
graphp->SetMarkerStyle(20);
graphp->SetMarkerSize(0.7);
graphp->SetMarkerColor(kRed);
graphp1->SetLineStyle(7);
graphp1->SetLineWidth(6);
graphp1->SetLineColor(kBlack);
graphp2->SetLineStyle(7);
graphp2->SetLineWidth(4);
graphp2->SetLineColor(kGreen+1);

graphm->SetLineWidth(3);
graphm->SetLineColor(kBlue);
graphm->SetMarkerStyle(20);
graphm->SetMarkerSize(0.7);
graphm->SetMarkerColor(kBlue);
graphm1->SetLineStyle(7);
graphm1->SetLineWidth(6);
graphm1->SetLineColor(kBlack);
graphm2->SetLineStyle(7);
graphm2->SetLineWidth(4);
graphm2->SetLineColor(kGreen+1);

TF1 *sinp = new TF1("sinp","[0]+[1]*TMath::Sin([2]*x+[3])",-3.14,3.14);
sinp->SetParLimits(0,90,92);
sinp->SetParameters(0,91.2);
sinp->SetParLimits(1,0.1,2);
sinp->SetParameters(1,1);
sinp->SetParLimits(2,0.1,2);
sinp->SetParameters(2,0.9);
sinp->SetParLimits(4,-3.14,5);
sinp->SetParameters(3,-1);
sinp->SetLineColor(kRed);

TF1 *sinm = new TF1("sinm","[0]+[1]*TMath::Sin([2]*x+[3])",-3.14,3.14);
sinm->SetParLimits(0,90,92);
sinm->SetParameters(0,91.2);
sinm->SetParLimits(1,0.1,2);
sinm->SetParameters(1,1);
sinm->SetParLimits(2,0.1,2);
sinm->SetParameters(2,0.9);
sinm->SetParLimits(3,-3.14,5);
sinm->SetParameters(3,-1);
sinm->SetLineColor(kBlue);

graphp->Fit(sinp,"","",-3.14,3.14);
graphm->Fit(sinm,"","",-3.14,3.14);

gStyle->SetOptFit(1);

TCanvas *canv1 = new TCanvas();
canv1->Divide(3,1);
canv1->cd(1);
graphp->Draw("AP");
 graphp1->Draw("P");
 graphp2->Draw("P");
canv1->cd(2);
graphm->Draw("AP");
graphm1->Draw("P");
graphm2->Draw("P");
canv1->cd(3);
graphp->Draw("AP");
graphm->Draw("P");


};

void tgemerger(TGraphErrors *graph, TCollection* li){

TIter next(li);
TObject *o;

	while (o = next()) {
		TGraphErrors *g = dynamic_cast<TGraphErrors*> (o);
		if (!g) return -1;
		Double_t x, y, dx, dy;
		for (Int_t i = 0 ; i < g->GetN(); i++) {
		g->GetPoint(i, x, y);
		dx=g->GetErrorX(i);
		dy=g->GetErrorY(i);
		graph->SetPoint(graph->GetN(), x, y);
		graph->SetPointError(graph->GetN()-1,dx,dy);
		}
	}

return graph->GetN();

};

TGraphErrors* fitmacro(double muptcutmin, double muptcutmax, int bin, int nbins, int charge, bool dataset, int correction){

double lumiscale=0;
if (dataset==0) lumiscale=0.36;
if (dataset==1) lumiscale=1;

TFile *data;
if (dataset==0) data=new TFile("./RecoRoutines_Z-selection_zjets_madgraph_skim100pb.root","read");
if (dataset==1) data=new TFile("./RecoRoutines_Z-selection_data36pb.root","read");


TString dir="MuPtScale0toinf/";

 TString strcorr("");
 if(correction!=0) strcorr+="PhiDep";
 strcorr+=correction;

 TString plottitle="RECO_";
  if (charge>0) plottitle=plottitle+strcorr+"pcscale_MpPhivsMpPTvsrecobosonM_hrdMp";
  else plottitle=plottitle+strcorr+"pcscale_MmPhivsMmPTvsrecobosonM_hrdMm";

cout<<(dir+plottitle).Data()<<endl;

TH3F *corrplot;
  corrplot = (TH3F*)data->Get((dir+plottitle).Data());

double xmin=-3.14+6.28*((double)bin/nbins);
double xmax=xmin+6.28/nbins;
double ymin=muptcutmin;
double ymax=muptcutmax;

  int bin0 = corrplot->GetXaxis()->FindBin(xmin);
  int bin1 = corrplot->GetXaxis()->FindBin(xmax);
  int bin2 = corrplot->GetYaxis()->FindBin(ymin);
  int bin3 = corrplot->GetYaxis()->FindBin(ymax);

 TH1D *hist = corrplot->ProjectionZ("_pz",bin0,bin1,bin2,bin3);
  hist->Scale(lumiscale);


 gSystem->Load("libRooFit");
  using namespace RooFit;
 
RooRealVar Zmass("Zmass","Z RECO mass (GeV)",81.2,101.2);
  RooDataHist datahist("datahist","datahist",Zmass,Import(*hist));
  RooBinning tbins(81.2,101.2);
  tbins.addUniform(20,81.2,101.2);
 RooRealVar mean("mean","mean",91.2,81.2,101.2);
  RooRealVar sigma("sigma","sigma",3,0,30);
  RooRealVar width("width","width",2.49,2.49,2.49);
  RooVoigtian voigt("voigt","voigt",Zmass,mean,width,sigma);
  RooFitResult *r = voigt.fitTo(datahist,Save(),SumW2Error(kFALSE));


const TMatrixDSym& cov = r->covarianceMatrix();

TGraphErrors *out = new TGraphErrors();

out->SetPoint(0,(xmin+xmax)/2,mean.getVal());
out->SetPointError(0,(xmax-xmin)/2,sqrt(cov[0][0]));

return out;

};
