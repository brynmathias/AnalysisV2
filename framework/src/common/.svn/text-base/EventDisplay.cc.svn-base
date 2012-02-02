#include "EventDisplay.hh"
#include "TDirectory.h"
#include "EventData.hh"
#include "TPad.h"
#include "TEllipse.h"
#include "TLatex.h"
#include "TArrow.h"
#include "TStyle.h"
#include "Jet.hh"
#include "Lepton.hh"
#include "Photon.hh"
#include "AlphaT.hh"

namespace Operation {

  EventDisplay::EventDisplay(const std::string & folderName, const std::string & flag) : mFolderName(folderName) {
    flag_ = flag;
  }

  void EventDisplay::initDir(TDirectory* aFileOut, const char* folderName) {
    aFileOut->cd();
    TDirectory * mydir = aFileOut->mkdir(folderName, folderName);
    mydir->cd();
  }

  void EventDisplay::Start(Event::Data& ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetCanvasColor(kWhite);
    gStyle->SetPadBorderMode(0);
    gStyle->SetPadColor(0);
    TCanvas *c = new TCanvas("canvas", "Event Display", 720, 720);
    c_ = c;
    TPad *titlePad = new TPad("", "", 0.01, 0.95, 0.99, 0.99);
    titlePad->SetNumber(1);
    titlePad->Draw();
    TPad *rPhiHistPad = new TPad("", "", 0.01, 0.45, 0.50, 0.95);
    rPhiHistPad->SetNumber(2);
    rPhiHistPad->Draw();
    TPad *etaPhiPad = new TPad("", "", 0.50, 0.45, 0.99, 0.95);
    etaPhiPad->SetNumber(3);
    etaPhiPad->Draw();
    TPad *etaPhiHistPad = new TPad("", "", 0.525, 0.55, 0.975, 0.85);
    etaPhiHistPad->SetNumber(4);
    etaPhiHistPad->Draw();
    TPad *metPad = new TPad("", "", 0.01, 0.32, 0.50, 0.45);
    metPad->SetNumber(5);
    metPad->Draw();
    TPad *calojetPad = new TPad("", "", 0.01, 0.19, 0.50, 0.32);
    calojetPad->SetNumber(6);
    calojetPad->Draw();
    TPad *pfjetPad = new TPad("", "", 0.01, 0.06, 0.50, 0.19);
    pfjetPad->SetNumber(7);
    pfjetPad->Draw();
    TPad *photonPad = new TPad("", "", 0.50, 0.32, 0.99, 0.45);
    photonPad->SetNumber(8);
    photonPad->Draw();
    TPad *electronPad = new TPad("", "", 0.50, 0.19, 0.99, 0.32);
    electronPad->SetNumber(9);
    electronPad->Draw();
    TPad *muonPad = new TPad("", "", 0.50, 0.06, 0.99, 0.19);
    muonPad->SetNumber(10);
    muonPad->Draw();
    c_->cd(2);
    TEllipse *circle = new TEllipse(0.5, 0.5, 0.3);
    TLatex *rphititle = new TLatex(0.1, 0.9, "[r, #phi] view"); 
    TLatex *rphikey = new TLatex(0.15, 0.75, "R = 200 GeV"); 
    circle->Draw();
    rphititle->Draw();
    rphikey->SetTextSize(0.03);
    rphikey->Draw();
    c_->cd(3);
    TLatex *etaphititle = new TLatex(0.1, 0.9, "[#eta, #phi] view"); 
    etaphititle->SetNDC();
    etaphititle->Draw();
    c_->cd(4);
    TH2D *eb = new TH2D("", ";#eta;#phi", 72, -3., 3., 72, -180., 180.);
    eb_ = eb;
    eb_->SetStats(kFALSE);
    eb_->Draw("COL");
    TLine *ebmaxplus = new TLine(1.479, -180., 1.479, 180.);
    TLine *ebmaxminus = new TLine(-1.479, -180., -1.479, 180.);
    /*
    int FEDs [] = {611, 612, 619, 620, 623, 626, 630, 630, 630, 633, 636, 636, 639, 640, 640};
    int TTs [] = {13, 28, 43, 60, 16, 17, 19, 20, 21, 14, 42, 50, 68, 31, 32};
    for (int i = 0; i < 15; i++)
    {
      int k = FEDs[i] > 627 ? 1 : -1; // +1 for EB+, -1 for EB-
      int xbin = ( ((FEDs[i] - 610) % 18)*4 + k*(2 - ((TTs[i] - 1) % 4)) + 72 ) % 72 + 1;
      int ybin = k*int((TTs[i]-1)/4) + 17 + (k+1)/2;
      std::cout << "xbin = " << xbin << "; ybin = " << ybin << std::endl;
      double x = xbin*5. - 2.5;
      double y = (ybin - 17)*5. - 2.5;
      //eb_->Fill(x, y, 1);
    }
    */
    ebmaxplus->Draw();
    ebmaxminus->Draw();
    c_->Update();
  }

  bool EventDisplay::Process(Event::Data& ev) {

    std::cout << "Run Number = " << ev.RunNumber() << "; Lumi Section = " << ev.LumiSection() << "; Event Number = " << ev.EventNumber() << std::endl;
    // Fill EB histogram with TP of dead TTs
    eb_->Reset();
    for (std::vector<PolarLorentzV>::const_iterator p4 = ev.ecalDeadTowerTrigPrimP4()->begin(); p4 != ev.ecalDeadTowerTrigPrimP4()->end(); ++p4)
    //Event::Element<std::vector<PolarLorentzV>*, NtupleData> ecalDeadTowerTrigPrimP4;
    //Event::Element<std::vector<unsigned>*,NtupleData> ecalDeadTowerMaxStatus;
    //for (ev.ecalDeadTowerTrigPrimP4())
    {
      //if (p4->pt() > 1.)
      //{
        double phi = p4->phi();
        double eta = p4->eta();
        double x = phi*180/acos(-1);
        double y = 2.*atan(exp(-eta))*180/acos(-1);
        //eb_->SetBinContent(xbin, ybin, 1);
        eb_->Fill(x, y, 1.);
        //eb_->SetBinContent(xbin, ybin, p4->pt());
      //}
      if (p4->pt() > 20.)
      {
        //eb_->SetBinContent(xbin, ybin, 2);
        eb_->Fill(x, y, 1.);
      }
    }
    c_->Update();

    char name[50];
    char pngname[50];
    sprintf(name, "EventDisplay_%d_%d_%d", ev.RunNumber(), ev.LumiSection(), ev.EventNumber());
    sprintf(pngname, "EventDisplay_%d_%d_%d.png", ev.RunNumber(), ev.LumiSection(), ev.EventNumber());
    c_->SetName(name);
    c_->cd(1);
    char tit[99];
    sprintf(tit, "Run Number = %d; Lumi Section = %d; Event Number = %d", ev.RunNumber(), ev.LumiSection(), ev.EventNumber());
    TLatex title = TLatex(0.01, 0.50, tit);
    title.SetTextSize(0.5);
    title.Draw();
    c_->Update();

    gStyle->SetTextSize(0.12);
    char infos[40][200];
    int ix = 0;
    c_->cd(5);
    TLatex eventinfo[4];
    eventinfo[0].SetText(0.01, 0.9, "Event Variables");
    eventinfo[0].Draw();
    eventinfo[1].SetText(0.01, 0.8, "pfMET    HT    MHT    #Delta#phi*    #alpha_{T}");
    eventinfo[1].Draw();
    eventinfo[2].SetText(0.01, 0.7, "-----------------------------------------------");
    eventinfo[2].Draw();
    sprintf(infos[ix], "%.2f    %.2f    %.2f    %.2f    %.2f", ev.PFMET().pt(), ev.CommonHT(), ev.CommonMHT().pt(), ev.JetMinBiasDPhi(), ev.CommonAlphaT());
    eventinfo[3].SetText(0.01, 0.6, infos[ix]);
    ix++;
    eventinfo[3].Draw();
    c_->Update();
    c_->cd(6);
    TLatex calojetinfo[8];
    calojetinfo[0].SetText(0.01, 0.9, "AK5 Calo Jets");
    calojetinfo[0].Draw();
    calojetinfo[1].SetText(0.01, 0.8, "p_{T}    #eta    #phi    EMF    N90    corr");
    calojetinfo[1].Draw();
    calojetinfo[2].SetText(0.01, 0.7, "-------------------------------------------");
    calojetinfo[2].Draw();
    c_->Update();
    c_->cd(7);
    TLatex pfjetinfo[8];
    pfjetinfo[0].SetText(0.01, 0.9, "AK5 PF Jets");
    pfjetinfo[0].Draw();
    pfjetinfo[1].SetText(0.01, 0.8, "p_{T}    #eta    #phi    EMF    N90    corr");
    pfjetinfo[1].Draw();
    pfjetinfo[2].SetText(0.01, 0.7, "-------------------------------------------");
    pfjetinfo[2].Draw();
    c_->Update();
    c_->cd(8);
    TLatex photoninfo[8];
    photoninfo[0].SetText(0.01, 0.9, "Photons");
    photoninfo[0].Draw();
    photoninfo[1].SetText(0.01, 0.8, "p_{T}    #eta    #phi    ecalIso    hcalIso    trackIso    #sigma_{i#etai#eta}    H/E    r9    hasPixelSeed");
    photoninfo[1].Draw();
    photoninfo[2].SetText(0.01, 0.7, "-----------------------------------------------------------------------------------------------------------");
    photoninfo[2].Draw();
    c_->Update();
    c_->cd(9);
    TLatex electroninfo[8];
    electroninfo[0].SetText(0.01, 0.9, "Electrons");
    electroninfo[0].Draw();
    electroninfo[1].SetText(0.01, 0.8, "p_{T}    #eta    #phi    ecalIso    hcalIso    trackIso    #sigma_{i#etai#eta}    #Delta#eta    #Delta#phi");
    electroninfo[1].Draw();
    electroninfo[2].SetText(0.01, 0.7, "--------------------------------------------------------------------------------");
    electroninfo[2].Draw();
    c_->Update();
    c_->cd(10);
    TLatex muoninfo[8];
    muoninfo[0].SetText(0.01, 0.9, "Muons");
    muoninfo[0].Draw();
    muoninfo[1].SetText(0.01, 0.8, "p_{T}    #eta    #phi");
    muoninfo[1].Draw();
    muoninfo[2].SetText(0.01, 0.7, "---------------------");
    muoninfo[2].Draw();
    c_->Update();
    TArrow arrows[50];
    TEllipse ellipses[50];
    int iobj = 0;
    Double_t info_position = 0.6;

    // MET
    c_->cd(2);
    arrows[iobj] = TArrow(0.5, 0.5, 0.5+(0.3*ev.PFMET().pt()/200.)*cos(ev.PFMET().phi()), 0.5+(0.3*ev.PFMET().pt()/200.)*sin(ev.PFMET().phi()), 0.02, "|>");
    arrows[iobj].SetLineWidth(3);
    arrows[iobj].SetLineColor(7);
    arrows[iobj].SetFillColor(7);
    c_->cd(4);
    ellipses[iobj] = TEllipse(0., ev.PFMET().phi()*180./acos(-1), 2.*(acos(-1)/180)*(50./72), 2.);
    ellipses[iobj].SetLineColor(7);
    ellipses[iobj].SetLineWidth(2);
    ellipses[iobj].SetFillStyle(1);
    c_->cd(5);
    iobj++;

    // JETS
    int ijet = 0;
    for (std::vector<Event::Jet>::const_iterator jet = ev.JD_Jets().begin(); jet != ev.JD_Jets().end(); ++jet)
    {
      if (jet->pt() > 10. && ijet < 7)
      {
        c_->cd(2);
        arrows[iobj] = TArrow(0.5, 0.5, 0.5+(0.3*jet->pt()/200.)*cos(jet->phi()), 0.5+(0.3*jet->pt()/200.)*sin(jet->phi()), 0.02, "|>");
        arrows[iobj].SetLineWidth(3);
        arrows[iobj].SetLineColor(kRed-9);
        arrows[iobj].SetFillColor(kRed-9);
        c_->cd(4);
        ellipses[iobj] = TEllipse(jet->eta(), jet->phi()*180./acos(-1), 20.*(acos(-1)/180)*(50./72), 20.);
        ellipses[iobj].SetLineColor(kRed-9);
        ellipses[iobj].SetLineWidth(1);
        ellipses[iobj].SetFillStyle(0);
        c_->cd(6);
        //sprintf(infos[ix], "%.2f    %.2f    %.2f    %.2f    %.2f", jet->pt(), jet->eta(), jet->phi(), jet->GetEmFrac(), ev.BranchName->at(jet->GetIndex()), ev.BranchName->at(jet->GetIndex()));
        sprintf(infos[ix], "%.2f    %.2f    %.2f", jet->pt(), jet->eta(), jet->phi());
        calojetinfo[ijet+3].SetText(0.01, info_position, infos[ix]);
        ix++;
        calojetinfo[ijet+3].Draw();
        info_position -= 0.1;
        iobj++;
        ijet++;
      }
    }

    for (std::vector<Event::Jet const *>::const_iterator jet = ev.JD_CommonJets().accepted.begin(); jet != ev.JD_CommonJets().accepted.end(); ++jet)
    {
      c_->cd(2);
      arrows[iobj] = TArrow(0.5, 0.5, 0.5+(0.3*(*jet)->pt()/200.)*cos((*jet)->phi()), 0.5+(0.3*(*jet)->pt()/200.)*sin((*jet)->phi()), 0.02, "|>");
      arrows[iobj].SetLineWidth(3);
      arrows[iobj].SetLineColor(kRed);
      arrows[iobj].SetFillColor(kRed);
      c_->cd(4);
      ellipses[iobj] = TEllipse((*jet)->eta(), (*jet)->phi()*180./acos(-1), 20.*(acos(-1)/180)*(50./72), 20.);
      ellipses[iobj].SetLineColor(kRed);
      ellipses[iobj].SetLineWidth(1);
      ellipses[iobj].SetFillStyle(0);
      iobj++;
    }

    // ELECTRONS
    int ielec = 0;
    info_position = 0.6;
    for (std::vector<Event::Lepton>::const_iterator elec = ev.LD_Electrons().begin(); elec != ev.LD_Electrons().end(); ++elec)
    {
      if (elec->pt() > 10. && ielec < 7)
      {
        c_->cd(2);
        arrows[iobj] = TArrow(0.5, 0.5, 0.5+(0.3*elec->pt()/200.)*cos(elec->phi()), 0.5+(0.3*elec->pt()/200.)*sin(elec->phi()), 0.02, "|>");
        arrows[iobj].SetLineWidth(3);
        arrows[iobj].SetLineColor(kBlue);
        arrows[iobj].SetFillColor(kBlue);
        c_->cd(4);
        ellipses[iobj] = TEllipse(elec->eta(), elec->phi()*180./acos(-1), 5.*(acos(-1)/180)*(50./72), 5.);
        ellipses[iobj].SetLineColor(kBlue);
        ellipses[iobj].SetLineWidth(1);
        ellipses[iobj].SetFillStyle(0);
        c_->cd(9);
        sprintf(infos[ix], "%.2f    %.2f    %.2f", elec->pt(), elec->eta(), elec->phi());
        electroninfo[ielec+3].SetText(0.01, info_position, infos[ix]);
        ix++;
        electroninfo[ielec+3].Draw();
        info_position -= 0.1;
        iobj++;
        ielec++;
      }
    }

    // MUONS
    int imuon = 0;
    info_position = 0.6;
    for (std::vector<Event::Lepton>::const_iterator muon = ev.LD_Muons().begin(); muon != ev.LD_Muons().end(); ++muon)
    {
      if (muon->pt() > 10. && imuon < 7)
      {
        c_->cd(2);
        arrows[iobj] = TArrow(0.5, 0.5, 0.5+(0.3*muon->pt()/200.)*cos(muon->phi()), 0.5+(0.3*muon->pt()/200.)*sin(muon->phi()), 0.02, "|>");
        arrows[iobj].SetLineWidth(3);
        arrows[iobj].SetLineColor(kPink+4);
        arrows[iobj].SetFillColor(kPink+4);
        c_->cd(4);
        ellipses[iobj] = TEllipse(muon->eta(), muon->phi()*180./acos(-1), 5.*(acos(-1)/180.)*(50./72), 5.);
        ellipses[iobj].SetLineColor(kPink+4);
        ellipses[iobj].SetLineWidth(1);
        ellipses[iobj].SetFillStyle(0);
        c_->cd(10);
        sprintf(infos[ix], "%.2f    %.2f    %.2f", muon->pt(), muon->eta(), muon->phi());
        muoninfo[imuon+3].SetText(0.01, info_position, infos[ix]);
        ix++;
        muoninfo[imuon+3].Draw();
        info_position -= 0.1;
        iobj++;
        imuon++;
      }
    }

    // PHOTONS
    int iphoton = 0;
    info_position = 0.6;
    for (std::vector<Event::Photon>::const_iterator photon = ev.PD_Photons().begin(); photon != ev.PD_Photons().end(); ++photon)
    {
      if (photon->pt() > 10. && iphoton < 7)
      {
        c_->cd(2);
        arrows[iobj] = TArrow(0.5, 0.5, 0.5+(0.3*photon->pt()/200.)*cos(photon->phi()), 0.5+(0.3*photon->pt()/200.)*sin(photon->phi()), 0.02, "|>");
        arrows[iobj].SetLineWidth(3);
        arrows[iobj].SetLineColor(kGreen);
        arrows[iobj].SetFillColor(kGreen);
        c_->cd(4);
        ellipses[iobj] = TEllipse(photon->eta(), photon->phi()*180./acos(-1), 5.*(acos(-1)/180.)*(50./72), 3.6);
        ellipses[iobj].SetLineColor(kGreen);
        ellipses[iobj].SetLineWidth(1);
        ellipses[iobj].SetFillStyle(0);
        c_->cd(8);
        sprintf(infos[ix], "%.2f    %.2f    %.2f    %.2f    %.2f    %.2f    %.2f    %.2f    %.2f    %d", photon->pt(), photon->eta(), photon->phi(), photon->ecalRecHitSumEtConeDR04(), photon->hcalTowerSumEtConeDR04(), photon->trkSumPtHollowConeDR04(), photon->sigmaIetaIeta(), photon->hadronicOverEm(), photon->r9(), photon->hasPixelSeed());
        photoninfo[iphoton+3].SetText(0.01, info_position, infos[ix]);
        ix++;
        photoninfo[iphoton+3].Draw();
        info_position -= 0.1;
        iobj++;
        iphoton++;
      }
    }

    int nobjs = iobj;
    for(int i = 0; i < nobjs; i++)//std::vector<TArrow>::iterator o = objects.begin(); o != objects.end(); ++o)
    {
      c_->cd(2);
      arrows[i].Draw();
      c_->cd(4);
      ellipses[i].Draw();
    }
    /*
    for (int i=0; i<8; i++) {
      std::cout << i << std::endl;
      c_->cd(5);
      //eventinfo[i].Dump();
      if (eventinfo[i].GetName() != "") eventinfo[i].Draw();
      std::cout << eventinfo[i].GetName() << std::endl;
      std::cout << "Event info done." << std::endl;
      c_->cd(6);
      //calojetinfo[i].Dump();
      if (calojetinfo[i].GetName() != "") calojetinfo[i].Draw();
      std::cout << calojetinfo[i].GetName() << std::endl;
      std::cout << "Calo jet info done." << std::endl;
      c_->cd(7);
      if (pfjetinfo[i].GetName() != "") pfjetinfo[i].Draw();
      std::cout << pfjetinfo[i].GetName() << std::endl;
      std::cout << "pf jet info done." << std::endl;
      c_->cd(8);
      //photoninfo[i].Dump();
      if (photoninfo[i].GetName() != "") photoninfo[i].Draw();
      std::cout << photoninfo[i].GetName() << std::endl;
      std::cout << "photon info done." << std::endl;
      c_->cd(9);
      if (electroninfo[i].GetName() != "") electroninfo[i].Draw();
      std::cout << electroninfo[i].GetName() << std::endl;
      std::cout << "electron info done." << std::endl;
      c_->cd(10);
      if (muoninfo[i].GetName() != "") muoninfo[i].Draw();
      std::cout << muoninfo[i].GetName() << std::endl;
      std::cout << "muon info done." << std::endl;
    }
    */
    c_->SaveAs(pngname);
    c_->Clone(name);
    c_->Write();

    return true;
  }

  std::ostream& EventDisplay::Description(std::ostream &ostrm) {
    ostrm << "Draw Events ";
    return ostrm;
  }

}
