#include "mSuGraPlottingOps.hh"
#include "NLOTools.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "GenMatrixBin.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include <sstream>
#include <string>
#include <iomanip>

#include <strstream>
#include <iostream>
#include <fstream>


#include "JetData.hh"
#include "CommonOps.hh"


using namespace Operation;


SMPlottingOps::SMPlottingOps(const Utils::ParameterSet & ps) :
    dirName_( ps.Get<std::string>("DirectoryName"))
{}


SMPlottingOps::~SMPlottingOps(){}

void SMPlottingOps::Start(Event::Data & ev){
  initDir(ev.OutputFile(), dirName_.c_str());
  BookHistos();
}

void SMPlottingOps::BookHistos(){
  SMHist= new TH1D("SM_Events",";;events",1,0,2);
  SMHist->Sumw2();
  SMHist_noweight = new TH1D("SM_Events_noweight", ";;events", 1, 0, 2);
}

bool SMPlottingOps::Process(Event::Data & ev){
  Double_t weight = ev.GetEventWeight();
  SMHist->Fill(1,weight);
  SMHist_noweight->Fill(1);
  return true;
}

std::ostream & SMPlottingOps::Description(std::ostream & ostrm){
  ostrm << "mSUGRA Standard Model Plotting Op"; return ostrm;
}

//----------------------------------------------------------------------
mSuGraPlottingOps::mSuGraPlottingOps(  const Utils::ParameterSet& ps ) :
dirName_( ps.Get<std::string>("DirectoryName")),
  xBins_(ps.Get<int>("xBins")),
  xLow_(ps.Get<double>("xLow")),
  xHigh_(ps.Get<double>("xHigh")),
  yBins_(ps.Get<int>("yBins")),
  yLow_(ps.Get<double>("yLow")),
  yHigh_(ps.Get<double>("yHigh")),
  zBins_(ps.Get<int>("zBins")),
  zLow_(ps.Get<double>("zLow")),
  zHigh_(ps.Get<double>("zHigh")),
  verbose_(ps.Get<bool>("verbose")),
  M0_ (ps.Get<std::vector<double> >("NLO.M0")),
  M12_(ps.Get<std::vector<double> >("NLO.M12")),
  NG_ (ps.Get<std::vector<double> >("NLO.ng")),
  NS_ (ps.Get<std::vector<double> >("NLO.ns")),
  NN_ (ps.Get<std::vector<double> >("NLO.nn")),
  LL_ (ps.Get<std::vector<double> >("NLO.ll")),
  SB_ (ps.Get<std::vector<double> >("NLO.sb")),
  SS_ (ps.Get<std::vector<double> >("NLO.ss")),
  TB_ (ps.Get<std::vector<double> >("NLO.tb")),
  BB_ (ps.Get<std::vector<double> >("NLO.bb")),
  GG_ (ps.Get<std::vector<double> >("NLO.gg")),
  SG_ (ps.Get<std::vector<double> >("NLO.sg")),
  SM_(ps.Contains("SM") ? ps.Get<bool>("SM") : false)

{
  // std::map< std::pair<int, int>, std::vector<double> > M0_M12_NLO_;
  for(size_t i = 0; i < M0_.size(); ++i)
  {
    std::vector<double> nloVec;
    nloVec.clear();
    nloVec.push_back(NG_[i]);
    nloVec.push_back(NS_[i]);
    nloVec.push_back(NN_[i]);
    nloVec.push_back(LL_[i]);
    nloVec.push_back(SB_[i]);
    nloVec.push_back(SS_[i]);
    nloVec.push_back(TB_[i]);
    nloVec.push_back(BB_[i]);
    nloVec.push_back(GG_[i]);
    nloVec.push_back(SG_[i]);
    M0_M12_NLO_.insert( make_pair(make_pair(int(M0_[i]), int(M12_[i]) ) , nloVec ));
  }
}


mSuGraPlottingOps::~mSuGraPlottingOps(){}

//
void mSuGraPlottingOps::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

//
void mSuGraPlottingOps::BookHistos() {
  BookHistArray( H_M0_M12_mChi,
                 "m0_m12_mChi",
                 ";m0;m12;mChi;",
                 xBins_,xLow_,xHigh_, //m0
                 yBins_,yLow_,yHigh_, //m12
                 zBins_,zLow_,zHigh_, //mChi
                 1,0,1,false);

    BookHistArray( H_M0_M12_mChi_noweight,
                   "m0_m12_mChi_noweight",
                   ";m0;m12;mChi;",
                   xBins_,xLow_,xHigh_, //m0
                   yBins_,yLow_,yHigh_, //m12
                   zBins_,zLow_,zHigh_, //mChi
                   1,0,1,false);

    BookHistArray( H_M0_M12_sb,
                   "m0_m12_sb",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_sb_noweight,
                   "m0_m12_sb_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ss,
                   "m0_m12_ss",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ss_noweight,
                   "m0_m12_ss_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_sg,
                   "m0_m12_sg",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_sg_noweight,
                   "m0_m12_sg_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_gg,
                   "m0_m12_gg",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_gg_noweight,
                   "m0_m12_gg_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );


    BookHistArray( H_M0_M12_ll,
                   "m0_m12_ll",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ll_noweight,
                   "m0_m12_ll_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_nn,
                   "m0_m12_nn",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_nn_noweight,
                   "m0_m12_nn_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ng,
                   "m0_m12_ng",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ng_noweight,
                   "m0_m12_ng_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ns,
                   "m0_m12_ns",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_ns_noweight,
                   "m0_m12_ns_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );


    BookHistArray( H_M0_M12_bb,
                   "m0_m12_bb",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_bb_noweight,
                   "m0_m12_bb_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_tb,
                   "m0_m12_tb",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );

    BookHistArray( H_M0_M12_tb_noweight,
                   "m0_m12_tb_noweight",
                   ";m0;m12",
                   xBins_,xLow_,xHigh_,//m0
                   yBins_,yLow_,yHigh_,//m12
                   1, 0, 1,false );
}




bool mSuGraPlottingOps::Process( Event::Data& ev ) {
  // Event weight
  Double_t weight = ev.GetEventWeight();
  NLO::SUSYProcess process;

  double M0 = 0.;
  double M12 = 0.;
  double MChi = 0.;

  if(ev.M0.enabled()){
    M0 = ev.M0();
  }
  if(ev.MG.enabled()){
    M0 = ev.MG();
  }
  if(ev.M12.enabled()){
    M12 = ev.M12();
  }
  if(ev.MLSP.enabled()){
    M12 = ev.MLSP();
  }
  if(ev.MChi.enabled()){
    MChi = ev.MChi();
  }

  //NLO stuff: for the calculation of the NLO cross-section the processes are filled separately
  if(verbose_){
    std::cout << "The following branches are enabled/disabled\n" <<
        "M0" << ev.M0.enabled() << "\n" <<
        "MG" << ev.MG.enabled() << "\n" <<
        "M12" << ev.M12.enabled() << "\n" <<
        "MLSP" << ev.MLSP.enabled() << "\n" <<
        "MChi" << ev.MChi.enabled() << "\n";
  }
  //    if(ev.M0.enabled() || ev.M12.enabled()){
  H_M0_M12_mChi[0]->Fill(M0,M12,MChi,weight);
  H_M0_M12_mChi_noweight[0]->Fill(M0,M12,MChi,1);
      //    }
  if((ev.M0.enabled() || ev.MG.enabled())){

    process = NLO::GetProcess(ev);

    Double_t NLOcrosssection = 0.; // if we dont find a NLO x section, fill with zero - this will help with debugging
    if(verbose_ )cout << " Leading order XC is " << weight << endl;
    std::map<std::pair<int,int> , std::vector<double> >::const_iterator nloXsec = M0_M12_NLO_.find(make_pair(int(M0),int(M12)));
    if(nloXsec != M0_M12_NLO_.end() && nloXsec->second.size() > process) {
      NLOcrosssection = nloXsec->second[process]; //if no valid kFactorFile has been given simply fill LO eventweight
      if(verbose_ )cout << " Event Weight is now set to xsection = " << nloXsec->second[process] << endl;
      }


    if(verbose_ == true)cout << " m0 " << M0 << " m12 " << M12 << " nlocross " << NLOcrosssection << endl;
    switch(process){
      case NLO::nn: H_M0_M12_nn[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_nn_noweight[0]->Fill(M0,M12,1); break;
      case NLO::ns: H_M0_M12_ns[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_ns_noweight[0]->Fill(M0,M12,1); break;
      case NLO::ng: H_M0_M12_ng[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_ng_noweight[0]->Fill(M0,M12,1); break;
      case NLO::ss: H_M0_M12_ss[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_ss_noweight[0]->Fill(M0,M12,1); break;
      case NLO::ll: H_M0_M12_ll[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_ll_noweight[0]->Fill(M0,M12,1); break;
      case NLO::sb: H_M0_M12_sb[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_sb_noweight[0]->Fill(M0,M12,1); break;
      case NLO::tb: H_M0_M12_tb[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_tb_noweight[0]->Fill(M0,M12,1); break;
      case NLO::gg: H_M0_M12_gg[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_gg_noweight[0]->Fill(M0,M12,1); break;
      case NLO::bb: H_M0_M12_bb[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_bb_noweight[0]->Fill(M0,M12,1); break;
      case NLO::sg: H_M0_M12_sg[0]->Fill(M0,M12,NLOcrosssection); H_M0_M12_sg_noweight[0]->Fill(M0,M12,1); break;
      case NLO::NotFound: cout << " DID NOT FIND A SUBPROCESS " << endl; break;
    }

  }
  return true;
}


//
std::ostream& mSuGraPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "mSuGra scan 2d Plots ";
  return ostrm;
}
