import setupSUSY
from libFrameworkSUSY import *
from onelepton.utils import getDeadECALList

#MuHad_May10ReReco_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_May10ReReco_v1_filteredEventsBE_cfi.py")
#MuHad_May10ReReco_deadecal_ps._quiet_set("Accept", False)
#MuHad_May10ReReco_Cut_BE = EventSelector(MuHad_May10ReReco_deadecal_ps.ps())

#MuHad_May10ReReco_TP_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_May10ReReco_v1_filteredEventsTP_cfi.py")
#MuHad_May10ReReco_TP_deadecal_ps._quiet_set("Accept", False)
#MuHad_May10ReReco_Cut_TP = EventSelector(MuHad_May10ReReco_TP_deadecal_ps.ps())

#MuHad_Prompt_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_PromptReco_v4_filteredEventsBE_cfi.py")
#MuHad_Prompt_deadecal_ps._quiet_set("Accept", False)
#MuHad_Prompt_Cut_BE = EventSelector(MuHad_Prompt_deadecal_ps.ps())

#MuHad_Prompt_TP_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_PromptReco_v4_filteredEventsTP_cfi.py")
#MuHad_Prompt_TP_deadecal_ps._quiet_set("Accept", False)
#MuHad_Prompt_Cut_TP = EventSelector(MuHad_Prompt_TP_deadecal_ps.ps())

MuHad_Prompt6_TP_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_Prompt_v6_filteredEventsTP_cfi.py")
MuHad_Prompt6_TP_deadecal_ps._quiet_set("Accept", False)
MuHad_Prompt6_Cut_TP = EventSelector(MuHad_Prompt6_TP_deadecal_ps.ps())

MuHad_Prompt6_BE_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_Prompt_v6_filteredEventsBE_cfi.py")
MuHad_Prompt6_BE_deadecal_ps._quiet_set("Accept", False)
MuHad_Prompt6_Cut_BE = EventSelector(MuHad_Prompt6_BE_deadecal_ps.ps())

#MuHad_Aug5ReReco_v1_TP_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_Aug5ReReco_v1_filteredEventsTP_cfi.py")
#MuHad_Aug5ReReco_v1_TP_deadecal_ps._quiet_set("Accept", False)
#MuHad_Aug5ReReco_v1_Cut_TP = EventSelector(MuHad_Aug5ReReco_v1_TP_deadecal_ps.ps())

#MuHad_Aug5ReReco_v1_BE_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_Aug5ReReco_v1_filteredEventsBE_cfi.py")
#MuHad_Aug5ReReco_v1_BE_deadecal_ps._quiet_set("Accept", False)
#MuHad_Aug5ReReco_v1_Cut_BE = EventSelector(MuHad_Aug5ReReco_v1_BE_deadecal_ps.ps())

# run B still missing 

ElHad_May10ReReco_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_May10ReReco_filteredEventsBE_cfi.py")
ElHad_May10ReReco_deadecal_ps._quiet_set("Accept", False)
ElHad_May10ReReco_Cut_BE = EventSelector(ElHad_May10ReReco_deadecal_ps.ps())

ElHad_May10ReReco_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_May10ReReco_filteredEventsTP_cfi.py")
ElHad_May10ReReco_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_May10ReReco_Cut_TP = EventSelector(ElHad_May10ReReco_TP_deadecal_ps.ps())

ElHad_Prompt_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_Prompt_v4_filteredEventsBE_cfi.py")
ElHad_Prompt_deadecal_ps._quiet_set("Accept", False)
ElHad_Prompt_Cut_BE = EventSelector(ElHad_Prompt_deadecal_ps.ps())

ElHad_Prompt_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_Prompt_v4_filteredEventsTP_cfi.py")
ElHad_Prompt_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_Prompt_Cut_TP = EventSelector(ElHad_Prompt_TP_deadecal_ps.ps())

ElHad_Aug5ReReco_v1_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_Aug5ReReco_v1_filteredEventsBE_cfi.py")
ElHad_Aug5ReReco_v1_deadecal_ps._quiet_set("Accept", False)
ElHad_Aug5ReReco_v1_Cut_BE = EventSelector(ElHad_Aug5ReReco_v1_deadecal_ps.ps())

ElHad_Aug5ReReco_v1_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_Aug5ReReco_v1_filteredEventsTP_cfi.py")
ElHad_Aug5ReReco_v1_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_Aug5ReReco_v1_Cut_TP = EventSelector(ElHad_Aug5ReReco_v1_TP_deadecal_ps.ps())

ElHad_Prompt_v6_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_Prompt_v6_filteredEventsBE_cfi.py")
ElHad_Prompt_v6_deadecal_ps._quiet_set("Accept", False)
ElHad_Prompt_v6_Cut_BE = EventSelector(ElHad_Prompt_v6_deadecal_ps.ps())

ElHad_Prompt_v6_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_Prompt_v6_filteredEventsTP_cfi.py")
ElHad_Prompt_v6_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_Prompt_v6_Cut_TP = EventSelector(ElHad_Prompt_v6_TP_deadecal_ps.ps())

ElHad_PromptB_v1_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011B_Prompt_v1_filteredEventsBE_cfi.py")
ElHad_PromptB_v1_deadecal_ps._quiet_set("Accept", False)
ElHad_PromptB_v1_Cut_BE = EventSelector(ElHad_PromptB_v1_deadecal_ps.ps())

ElHad_PromptB_v1_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011B_Prompt_v1_filteredEventsTP_cfi.py")
ElHad_PromptB_v1_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_PromptB_v1_Cut_TP = EventSelector(ElHad_PromptB_v1_TP_deadecal_ps.ps())
