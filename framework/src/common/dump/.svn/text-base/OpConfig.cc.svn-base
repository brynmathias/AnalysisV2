/*! \file OpConfig.cc
 * \brief Source code for the operation configuration class.
 */

#include "OpConfig.hh"

namespace Operation {

    OpConfig::OpConfig(const char * opconfigfilename) {
        // Initialise the control cards
        Cards = ControlCards::Instance();

        // Add your own control cards and default values here...

        // Tom Whyntie's Control Cards
        //----------------------------- 
        // NONE=>No MC info print, ENDCHAIN=> print only the end chain particles,
        // CHAIN=>Display the decay chains, FULL=>Print all particles.
        Cards->AddCardString("MC_PrintOption", "NONE");

        // MC particle basic properties plots
        Cards->AddCardInt("MC_MCPlots_1_Num", 0);
        Cards->AddCardInt("MC_MCPlots_1_ID", 0);
        Cards->AddCardString("MC_MCPlots_1_Folder", "MyPlots");
        Cards->AddCardInt("MC_MCPlots_1_Anti", 0);
        
        // PDG ID Filter Cut
        Cards->AddCardInt("MC_PDGIDFilter_1_ID", 0);
        Cards->AddCardString("MC_PDGIDFilter_1_Comp", ">=");
        Cards->AddCardInt("MC_PDGIDFilter_1_Num", 0);
        Cards->AddCardInt("MC_PDGIDFilter_1_Anti", 0);
        Cards->AddCardInt("MC_PDGIDFilter_1_Mother", 0);
        Cards->AddCardInt("MC_PDGIDFilter_1_AntiMother", 0);

        // MC Photon analysis cut
        Cards->AddCardInt("MC_MCPhoton_1_Num", 2);

        // COMMON OBJECTS
        //----------------
        // Search Matrix configuration
        Cards->AddCardInt("Com_SearchMat_1_jetmax", 10);
        Cards->AddCardInt("Com_SearchMat_1_lepmax", 10);
        Cards->AddCardInt("Com_SearchMat_1_phomax", 4);
        // Perform Cross Cleaner checks
        Cards->AddCardInt("Check_BadMuonInJet", 0);
        Cards->AddCardInt("Check_BadEliInJet", 0);
        Cards->AddCardInt("Check_BadJetccJet", 0);
        Cards->AddCardInt("Check_DeadOverlap", 0);
        // Perform odd object checks?
        Cards->AddCardInt("Com_OddElectrons", 0);
        Cards->AddCardInt("Com_OddMuons", 0);
        Cards->AddCardInt("Com_OddJets", 0);
        Cards->AddCardInt("Com_OddPhotons", 0);

        Cards->AddCardDouble("GdPho_HT_Cut_GeV", 100.);
        Cards->AddCardDouble("GdPho_AlphaT_Cut", 0.55);
        //==================================================

        // Henning's Control Cards
        //        Cards->AddCardInt("nTriggers",0);
        Cards->AddCardInt("TriggerCut",10);
        
        //        vector<double> triggervec;
        //        Cards->AddCardVector("TriggerVec",triggervec);

        Cards->AddCardString("NLepComp","==");
        Cards->AddCardInt("NLep",0);
        Cards->AddCardString("NMuComp","==");
        Cards->AddCardInt("NMu",0);
        Cards->AddCardString("NPhComp","==");
        Cards->AddCardInt("NPh",0);

        Cards->AddCardString("NJetComp",">");
        Cards->AddCardInt("NJet",1);
        
        Cards->AddCardDouble("2ndJetEtCut",100.);
        Cards->AddCardDouble("1stJetEtaCut",2.5);

        Cards->AddCardDouble("HTCut",350.);
        Cards->AddCardDouble("AlphaTCut",0.55);




        // Read in the values from the op config file
        Cards->readKeys(opconfigfilename);
    }

    OpConfig::~OpConfig() {}

} // ~Operation
