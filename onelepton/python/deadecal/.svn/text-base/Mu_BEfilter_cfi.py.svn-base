import FWCore.ParameterSet.Config as cms

def loadSequence(process, path):

	process.load(path+'.MuHad_Run2011A_Aug5ReReco_v1_filteredEventsBE_cfi')
	process.load(path+'.MuHad_Run2011A_May10ReReco_filteredEventsBE_cfi')
	process.load(path+'.MuHad_Run2011A_Prompt_v4_filteredEventsBE_cfi')
	process.load(path+'.MuHad_Run2011A_Prompt_v6_filteredEventsBE_cfi')
	process.load(path+'.MuHad_Run2011B_Prompt_v1_filteredEventsBE_cfi')

	process.Mu_BEfilterSequence=cms.Sequence(
	  process.veto_MuHad_Run2011A_Aug5ReReco_v1_filteredEventsBE*
	  process.veto_MuHad_Run2011A_May10ReReco_filteredEventsBE*
	  process.veto_MuHad_Run2011A_Prompt_v4_filteredEventsBE*
	  process.veto_MuHad_Run2011A_Prompt_v6_filteredEventsBE*
	  process.veto_MuHad_Run2011B_Prompt_v1_filteredEventsBE
	)