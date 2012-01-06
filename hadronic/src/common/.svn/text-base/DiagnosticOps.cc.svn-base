/*! \file DiagnosticTools.cc
 * \brief File containing the implementation of the hadronic diagnostic tools.
 */
#include "DiagnosticOps.hh"

namespace Operation {
	PFDiagnosticSlideMaker::PFDiagnosticSlideMaker(
		const Utils::ParameterSet& ps,
		const Utils::ParameterSet & priJetCorrPs,
		const Utils::ParameterSet & terJetCorrPs
	)
		:
	priJetCorrectionsPs_(priJetCorrPs),
	priLowEta_(priJetCorrPs.Get<std::vector<double> >("EtaLow") ),
  priHighEta_(priJetCorrPs.Get<std::vector<double> >("EtaHi") ),
  priCorrFactor_(priJetCorrPs.Get<std::vector<double> >("Correction") ),
	terJetCorrectionsPs_(terJetCorrPs),
	terLowEta_(terJetCorrPs.Get<std::vector<double> >("EtaLow") ),
  terHighEta_(terJetCorrPs.Get<std::vector<double> >("EtaHi") ),
  terCorrFactor_(terJetCorrPs.Get<std::vector<double> >("Correction") )
	{
		textFileName_ = ps.Get<std::string>("LatexFilename");
		triggers_ = ps.Get<std::vector<std::string> >("Triggers");
//		caloJetCorrectionsPs_ = caloCorrPs;
	}

	PFDiagnosticSlideMaker::~PFDiagnosticSlideMaker() {
    std::ofstream ostrm(textFileName_.c_str(),fstream::app);
    ostrm << slidesEnd();
	}

  void PFDiagnosticSlideMaker::Start(Event::Data& ev) { 
    std::ofstream ostrm(textFileName_.c_str(),fstream::trunc);
    ostrm << slidesStart();
  } //initDir(ev.OutputFile(),folderName_.c_str()); BookHistos(); }
  
  void PFDiagnosticSlideMaker::BookHistos() {;} // hg_c_ = new TH1D("count","",1,0.,1.); hg_c_->Sumw2(); }

  bool PFDiagnosticSlideMaker::Process(Event::Data& ev) {
    std::ofstream ostrm(textFileName_.c_str(),fstream::app);
    //ostrm<<ev.RunNumber()<<", "<<ev.LumiSection()<<", "<<ev.EventNumber()<<std::endl;
		ostrm
		<<"\\frame{\n"
		<<"\t\\frametitle{Run "<<ev.RunNumber()<<", LS "<<ev.LumiSection()<<", Num "<<ev.EventNumber()<<"}\n";
		//
		//triggers
		ostrm
		<<"\t Triggers: ";
		//get the triggers
    std::vector<std::string>::const_iterator it = triggers_.begin();
    for (; it!=triggers_.end(); ++it) {
      //find the trigger entry in the hlt map
      std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
      //find the trigger prescale value in the hlt_prescale map
      std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(*it);
      //
      //now check that the trigger is present AND that it is prescaled
      if (
           (trig!=ev.hlt()->end()                && trig->second)          //(trigger present AND triggered)
           &&                                                              //AND
           (prescale!=ev.hlt_prescaled()->end()  && prescale->second == 1) //(trigger present AND unprescaled)
         )
      {
				std::string trigger(trig->first);
				//std::cerr << "Initial trigger string = " << trigger << std::endl;
				//replace _ with \_ for latex...
				std::size_t unscpos = 0;
				std::vector<size_t> positions;
				while (unscpos!=string::npos) {
					if (unscpos==0) unscpos = trigger.find("_");
					else						unscpos = trigger.find("_",unscpos+1);
					if (unscpos!=string::npos) {
						positions.push_back(unscpos);
						//std::cerr << "!!!! underscore found at " << unscpos << std::endl;
					}
				}//end of while loop
				//now replace _ with \_
				std::vector<size_t>::reverse_iterator posit = positions.rbegin();
				for (;posit!=positions.rend();++posit) {
					//std::cerr << "!!!! current position = " << *posit << std::endl;
					trigger.replace(*posit, 1, "\\_");
				}
				//std::cerr << "New string is " << trigger << std::endl;
				ostrm << "\\code{"<<trigger << "} ";
      }
    }//end of loop over triggers provided in the operation parameter set "Triggers" vector.
		ostrm<<"\n\n";
		//
		//ic5 uncorrected jet calculations
		double jetPt_ = 20.; //hard-coded...
    double ht = 0.;
		double htj = 0.; //!< With jets passing threshold
    std::vector<Event::Jet>::const_iterator j2it = ev.JD_SecJets().begin();
    for (; j2it!=ev.JD_SecJets().end(); ++j2it) {
        //if (verb_) std::cout<<j2it->Pt()<<" ";
				ht += j2it->Et();
        if (j2it->Et()>jetPt_) htj += j2it->Et(); //trigger HLT uses ET of jets?
    }
		ostrm.precision(4);
		ostrm.width(6);
		ostrm
		<< "\t\\code{IC5U} jets: "
		<< "$H_T^{\\textrm{all}} = "<<ht<<"\\, \\GeV$, "
		<< "$H_T^{p_T>"<<jetPt_<<"\\, \\GeV} = "<<htj<<"\\, \\GeV$, ";
		ostrm.precision(3); ostrm.width(4);
		ostrm
		<< "(" << 100.*htj/ht<<"\\, \\%) "
		<< "\n"; 
		
		
		//
		ostrm
		<<"\t\\begin{columns}\n"
		<<"\t\t\\column{.45\\textwidth}\n";
		//
		//calo jets
		ostrm
		<<"\t\t\\begin{block}{AK5 Calo Jets}\n"
		<<"\t\t\\begin{tiny}\n"
		<<"\t\t\t\\begin{tabular}{r.......c}\n"
		<<"\t\t\t\\multicolumn{1}{c}{Index} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{$E_T$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{Cor} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{$\\eta$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{$\\phi$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{EMF} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{fHPD} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{N90} &\n" //&\n"
		//<<"\t\t\t\\multicolumn{1}{c}{fRBX}\n"
		<<"\t\t\t\\multicolumn{1}{c}{CC} "
		<<"\\\\\n";
		//loop over calo jets
		UInt_t numj1 = ev.jetP4()->size();
		UInt_t idx1 = 0;
		ostrm.precision(4); ostrm.width(4);
		if (numj1>0) {
			std::vector<const Event::Jet*>::const_iterator iJ=ev.CC().Jets.begin();
			for (;idx1<numj1;idx1++, ++iJ) {
				ostrm << "\t\t\t " << idx1 << " & ";
				ostrm << std::fixed << std::setprecision(1) << ev.jetP4()->at(idx1).Et() << " & ";
				//std::cerr << "jetP4.Et() = "<<ev.jetP4()->at(idx1).Et() << ", JD_Jets().Et() = " << ev.JD_Jets()[idx1].Et();
				//get the correction factor...
				double e = ev.jetP4()->at(idx1).Et();
				double eta = ev.jetP4()->at(idx1).Eta();
				double corr = 0.;
    		for(unsigned int i = 0; i < priLowEta_.size(); i++) { if(eta >= priLowEta_[i] && eta <= priHighEta_[i]) corr = priCorrFactor_[i]; }
				//std::cerr << " corr factor = " << corr << " corrected Et = " << e*corr;
				//if (*iJ) std::cerr << " CC Et = "<< (*iJ)->Et();
				//std::cerr << std::endl;
				ostrm << std::fixed << std::setprecision(1) << e*corr << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.jetP4()->at(idx1).Eta() << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.jetP4()->at(idx1).Phi() << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.jetFEm()->at(idx1) << " & ";
				double fHPD = ev.jetJetIDFHPD()->at(idx1);
				ostrm << std::fixed << std::setprecision(2) << (fHPD < 0. || fHPD > 1000. ? 0.00 : fHPD) << " & ";
				ostrm << ev.jetJetIDN90Hits()->at(idx1) << " & "; //& ";
				//ostrm << std::fixed << std::setprecision(2) << ev.jetJetIDFRBX()->at(idx1)
				ostrm << " "<< (*iJ ? "1" : "0") <<" ";
				ostrm << "\\\\ \n";
				//ostrm << " & " << std::fixed << std::setprecision(2) << e*corr << " & & & & &  \\\\\n";
			}//end of loop over primary jets
		}//end of numj1 > 0 check
//      0 & 20.0 & 1.5 & 1.32 & 0.65 & 0.3218438 & 4 & 0.27634 \\;
		ostrm
		<<"\t\t\t\\end{tabular}\n"
		<<"\t\t\\end{tiny}\n"
		<<"\t\t\\end{block}\n";
		//
		// PF jets
		ostrm
		<<"\t\t\\column{.45\\textwidth}\n"
		<<"\t\t\\begin{exampleblock}{AK5 PF Jets}\n"
		<<"\t\t\t\\begin{tiny}\n"
		<<"\t\t\t\\begin{tabular}{r..........}\n"
		<<"\t\t\t\\multicolumn{1}{c}{Index} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{$E_T$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{Cor} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{$\\eta$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{$\\phi$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{Fe$^0$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{Fe$^+$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{Fh$^0$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{Fh$^+$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{N$^0$} &\n"
		<<"\t\t\t\\multicolumn{1}{c}{N$^+$} \\\\\n";
		UInt_t numj3 = ev.terjetP4()->size();
		UInt_t idx3 = 0;
		ostrm.precision(4); ostrm.width(4);
		if (numj3>0) {
			for (;idx3<numj3;idx3++) {
				ostrm << "\t\t\t " << idx3 << " & ";
				double e = ev.terjetP4()->at(idx3).Et();
				ostrm << std::fixed << std::setprecision(1) << e << " & ";
				double eta = ev.terjetP4()->at(idx3).Eta();
				double corr = 0.;
    		for(unsigned int i = 0; i < terLowEta_.size(); i++) { if(eta >= terLowEta_[i] && eta <= terHighEta_[i]) corr = terCorrFactor_[i]; }
				ostrm << std::fixed << std::setprecision(1) << e*corr << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.terjetP4()->at(idx3).Eta() << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.terjetP4()->at(idx3).Phi() << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.terjetEMFneutral()->at(idx3) << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.terjetEMFcharged()->at(idx3) << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.terjetFneutralHad()->at(idx3) << " & ";
				ostrm << std::fixed << std::setprecision(2) << ev.terjetFchargedHad()->at(idx3) << " & ";
				ostrm << ev.terjetNneutral()->at(idx3) << " & "; //& ";
				ostrm << ev.terjetNcharged()->at(idx3) << " "; //& ";
				//ostrm << std::fixed << std::setprecision(2) << ev.jetJetIDFRBX()->at(idx1)
				ostrm << "\\\\ \n";
			}//end of loop over primary jets
		}//end of numj1 > 0 check
//      0 & 20.0 & 1.5 & 1.32 & 0.65 & 0.3218438 & 4 & 0.3 & 0.2 & 0.27634 \\;
		ostrm
		<<"\t\t\t\\end{tabular}\n"
		<<"\t\t\\end{tiny}\n"
		<<"\t\t\\end{exampleblock}\n"
		<<"\t\\end{columns}\n"
		<<"}\%end of frame\n";
    ostrm.close();
    return true;
  }
  
  std::ostream& PFDiagnosticSlideMaker::Description(std::ostream& ostrm) {ostrm << "PFDiagnosticSlideMaker ("<<textFileName_<<") ";  return ostrm;}

	std::string PFDiagnosticSlideMaker::slidesStart() {
		std::stringstream mytext("");
		mytext
		<<"\\documentclass[hyperref={pdfpagelabels=false},9pt,table]{beamer}\n"
		<<"\\let\\Tiny=\\tiny\n"
		<<"\\usepackage{beamerthemesplit}\n"
		<<"\\beamertemplatenavigationsymbolsempty\n"
		<<"\\usetheme{Madrid}\n"
		<<"\\usepackage{geometry}\n"
		<<"\\geometry{a5paper,landscape}\n"
		<<"\\usepackage{dcolumn}\n"
		<<"\\usepackage{color}\n"
		<<"\n"
		<<"\\usepackage{verbatim}\n"
		<<"\\usepackage{amsmath}\n"
		//<<"\\newcommand{\\code}[1]{\\textcolor[rgb]{0,.8,0}{\\texttt{#1}}}\n"
		<<"\\newcommand{\\code}[1]{\\texttt{#1}}\n"
		<<"\\renewcommand\\mathfamilydefault{\\rmdefault} \% ditto for math\n"
		<<"\\newcommand{\\GeV}{\\textrm{GeV}}\n"
		<<"\\renewcommand{\\arraystretch}{1.2}\n"
		<<"\\newcolumntype{.}{D{.}{.}{2}}\n"
//\usepackage{cancel}
//
		<<"\\title[PF Diagnostics]{PF Diagnostics}\n"
		<<"\\author{SUSY Team}\n"
		<<"\\institute{ICF}\n"
//
//%tables
//\newcommand{\MHT}{\cancel{H}_{T}}
//\newcommand{\MET}{\cancel{E}_{T}}

		<<"\\begin{document}\n\n";

		return mytext.str();
	}

	std::string PFDiagnosticSlideMaker::slidesEnd() {
		std::stringstream mytext("");
		mytext
		<< "\\end{document}";
		return mytext.str();
	}
	

}//end of Operation

