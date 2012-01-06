
import subprocess
import os
import shutil
 
 
def SSdilep1(dataset,outfile,events,outdir,config,xsection):
	subprocess.call([ "/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/exe/susydilep", dataset, outfile,str(events),outdir,config, str(xsection)])

def SSdilep2(dataset,outfile,events,outdir,config):
	subprocess.call( ["/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/exe/susydilep", dataset, outfile,str(events),outdir,config])

def produce(Data_list):
	for name in Data_list.keys():

		if not os.path.isdir("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/NT4_Output/" + name + "/"):
			os.mkdir("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/NT4_Output/" + name + "/")
		
		output_dir = "/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/NT4_Output/" + name
		(ntuple, xsection) = Data_list[name]
	
		SSdilep1(ntuple,name,nevents,output_dir,config_file, xsection)
		
def BKGDStudy(Data_list):
	for name in Data_list.keys():
		
		if not os.path.isdir("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/" + name + "/"):
			os.mkdir("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/" + name + "/")
		output_dir = "/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/" + name
		(ntuple, xsection) = Data_list[name]
		if os.path.exists("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/Gen_BKGD_log.txt"):#checking if the Gen file exists is sufficient to also check that the reco file exists
			os.remove("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/Gen_BKGD_log.txt")#since they are both neccessarily created together in DiLepSelectionOps.cc
			os.remove("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/reco_BKGD_log.txt")
		SSdilep1(ntuple,name,nevents,output_dir,config_file, xsection)
		if os.path.exists("/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/Gen_BKGD_log.txt"):	#see comment above
			Gen_BKGD_log = "/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/Gen_BKGD_log.txt"
			reco_BKGD_log = "/afs/cern.ch/user/a/arlogb/CMSSW_2_2_9/v4_susyntupla/BKGD_tests/reco_BKGD_log.txt"
		
			(gen_bkgd_log, ext)=os.path.splitext(Gen_BKGD_log)
			(reco_bkgd_log, ext)=os.path.splitext(reco_BKGD_log)
			os.rename(Gen_BKGD_log, gen_bkgd_log +"_" + name + ".txt")
			os.rename(reco_BKGD_log, reco_bkgd_log + "_" + name + ".txt")
			GEN_LOG = gen_bkgd_log +"_" + name + ".txt"
			RECO_LOG = reco_bkgd_log + "_" + name + ".txt" 
			shutil.move(GEN_LOG, output_dir)
			shutil.move(RECO_LOG, output_dir)

castor_root="/castor/cern.ch/cms/store/cmscaf/physics/data/PAT/CSA08-ntuples/NtupleNT4/"
castor_root_Pioppi_NT5="/castor/cern.ch/user/p/pioppi/susy/NT5/"
castor_root_Arlo_NT5="/castor/cern.ch/user/a/arlogb/susy/samples/V5/QCD/Madgraph/"
nevents = -1

config_file = "SSDilepton.txt"



#NT5----includes filter efficiency in the xsection for pythia this is pt > xxx
BB={
	"BB100_250" : (castor_root_Pioppi_NT5 +	"BB100to250/BB100to250_NT5.root", 126000),
	"BB250_500" : (castor_root_Pioppi_NT5 + "BB250to500/BB250to500_NT5.root",2250),
	"BB500_1000": (castor_root_Pioppi_NT5 + "BB500to1000/BB500to1000_NT5.root",70),
	"BB1000_inf": (castor_root_Pioppi_NT5 + "BB1000toInf/BB1000toInf_NT5.root", 1.95)
	}

pythiaQCD={
	
	"pythia3000" : (castor_root_Pioppi_NT5 + "pythia3000/pythia3000_NT5.root", 0.0000086008),
	"pythia2200" : (castor_root_Pioppi_NT5 + "pythia2200/pythia2200_NT5.root", 0.0014207778),
	"pythia1400" : (castor_root_Pioppi_NT5 + "pythia1400/pythia1400_NT5.root", 0.1720187189),
	"pythia800" : (castor_root_Pioppi_NT5 + "pythia800/pythia800_NT5.root", 11.9419745),
	"pythia470" : (castor_root_Pioppi_NT5 + "pythia470/pythia470_NT5.root", 315.5131272),
	"pythia300" : (castor_root_Pioppi_NT5 + "pythia300/pythia300_NT5.root", 3664.608301),
	"pythia170" : (castor_root_Pioppi_NT5 + "pythia170/pythia170_NT5.root", 62562.87713)
	}

MadgraphQCD={

	"Madgraph1000_inf" : (castor_root_Arlo_NT5 + "QCD1000toInf.root", 74)
#	"Madgraph250_500" : (/castor/cern.ch/user/t/trommers/PATV5/QCD_250_500_PATV5.root
	}

BKGDStudy(MadgraphQCD)
#BKGDStudy(pythiaQCD)

##NT4 QCD DiJet Pythia
#QCD={
# "QCD120_170" : (castor_root + "QCDDiJetPt120to170_NT4.root", 255987),
# "QCD170_230" : (castor_root + "QCDDiJetPt170to230_NT4.root" , 48325 ), 
# "QCD230_300" : (castor_root + "QCDDiJetPt230to300_NT4.root",  10623.2 ),
# "QCD300_380" : (castor_root + "QCDDiJetPt300to380_NT4.root",  2634.94),
# "QCD380_470" : (castor_root + "QCDDiJetPt380to470_NT4.root",  722.099),
# "QCD470_600" : (castor_root + "QCDDiJetPt470to600_NT4.root",  240.983),
# "QCD600_800" : (castor_root + "QCDDiJetPt600to800_NT4.root", 62.4923 ),
#  "QCD800_1000" :(castor_root + "QCDDiJetPt800to1000_NT4.root",9.42062 ),
#  "QCD1000_1400"  : (castor_root + "QCDDiJetPt1000to1400_NT4.root",2.34357 ),
#  "QCD1400_1800"  : (castor_root + "QCDDiJetPt1400to1800_NT4.root", 0.1568550),
#  "QCD1800_2200"  : (castor_root + "QCDDiJetPt1800to2200_NT4.root", 0.013811),
# "QCD2200_2600" : (castor_root + "QCDDiJetPt2200to2600_NT4.root", 0.00129608),
# "QCD2600_3000"  : (castor_root + "QCDDiJetPt2600to3000_NT4.root", 0.00011404), SAMPLE DOESN'T EXIST ATM
# "QCD3000_3500"  : (castor_root + "QCDDiJetPt3000to3500_NT4.root", 0.0000084318 )}#,
# "QCD3500_inf"  : (castor_root + "QCDDiJetPt3500toInf_NT4.root", 0.00000018146 )}
#QCD EMenriched

# QCD_EM = {"QCD_EMenriched_Pt20to30" : ("/castor/cern.ch/user/w/weinberg/susy/V4/QCD_EMenriched_Pt20to30/QCD_EMenriched_Pt20to30.root", 400000000),
#  "QCD_EMenriched_Pt30to80" : ("/castor/cern.ch/user/w/weinberg/susy/V4/QCD_EMenriched_Pt30to80/QCD_EMenriched_Pt30to80.root ", 100000000),
#  "QCD_EMenriched_Pt80to170" : ("/castor/cern.ch/user/w/weinberg/susy/V4/QCD_EMenriched_Pt80to170/QCD_EMenriched_Pt80to170.root ", 1900000)}

 
 
 #Vector Boson samples
# Vect_boso = {"Wjets" : (castor_root + "Wjets.root", 40000),
#  "Zjets" : (castor_root + "Zjets.root", 3700),
# #  "ttjets" : (castor_root + "ttjets.root ", 317)#,
#  "WW" : (castor_root + "WW_NT4.root", 44.8),
#  "ZZ" : (castor_root + "ZZ_NT4.root", 7.1),
#  "WZ" : (castor_root + "WZ_NT4.root", 17.6)}



#lm0_nt4="/castor/cern.ch/user/p/pioppi/susy/V5_NT4/LM0_V5_NT4.root"





# samples=[]
# samples["string"] = ("QCD120_170",config_file,255987)
# samples.append((QCD120_170,config_file,255987))
# samples.append((QCD170_230,config_file,48325))
# samples.append((QCD230_300,config_file,10623.2))
# samples.append((QCD300_380,config_file,2634.94)
# samples.append((QCD380_470,"LM2","Config_LM2.txt"))
# samples.append((QCD470_600,"LM3","Config_LM3.txt"))
# samples.append((QCD600_800,"LM4","Config_LM4.txt"))
# samples.append((QCD800_1000,"LM5","Config_LM5.txt"))
# samples.append((QCD1000_1400,"LM7","Config_LM7.txt"))
# samples.append((QCD1400_1800,"LM8","Config_LM8.txt"))
# samples.append((QCD1800_2200,"LM10","Config_LM10.txt"))
# samples.append((QCD2200_2600,"LM11","Config_LM11.txt"))
# samples.append((QCD2600_3000,"LM6","Config_LM6.txt"))
# samples.append((QCD3000_3500,"LM9","Config_LM9.txt"))
# samples.append((QCD3500_inf,"ttjets","Config_TTJets.txt"))
# samples.append((castor_root+wjets,"wjets","Config_WJets.txt"))
# samples.append((lm0_new,"LM0new","Config_LM0.txt"))
# samples.append((lm1_new,"LM1new","Config_LM1.txt"))
# samples.append((tt_new,"TTnew","Config_TTJets.txt"))
# samples.append((lm9_new,"LM9new","Config_LM9.txt"))
# samples.append((z_new,"Znew","Config_ZJets.txt"))
# samples.append((w_new,"WJetsnew","Config_WJets.txt"))


#produce(QCD)
#BKGDStudy(QCD)
#BKGDStudy(QCD_EM)
#BKGDStudy(Vect_boso)

# for name in QCD.keys():

	# output_dir = name
	# if not os.path.isdir("./NT4_Output/" + name + "/"):
		# os.mkdir("./NT4_Output/" + name + "/")
		#print "./NT4_Output/" + name + "/" 	
	# output_dir = "./NT4_Output/" + name
	# (ntuple, xsection) = QCD[name]
	
	# SSdilep1(ntuple,name,nevents,output_dir,config_file, xsection)

# for name in QCD_EM.keys():

	# if not os.path.isdir("./NT4_Output/" + name + "/"):
		# os.mkdir("./NT4_Output/" + name + "/")
		#print "./NT4_Output/" + output_dir + "/" 	
	# output_dir = "./NT4_Output/" + name
	# ntuple = QCD_EM[name]
	
	# SSdilep2(ntuple,name,nevents,output_dir,config_file)
