import setupSUSY
from icf.core import PSet
from icf.config import defaultConfig
import wpol.electron_id as electron_id

loose_id = PSet(
    Cuts = electron_id.eff_95,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,
    SupressErrors = True
)

tight_id = PSet(
    Cuts = electron_id.eff_70,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,
    SupressErrors = True
)

ewpol_conf=defaultConfig.copy()
ewpol_conf.Common.Jets.PtCut = 30.0
ewpol_conf.Common.Jets.EtaCut = 5.0
ewpol_conf.Common.Muons.EtaCut = 2.1
ewpol_conf.Common.Muons.PtCut = 15.0
ewpol_conf.Common.Muons.TrkIsoCut = -1.
ewpol_conf.Common.Muons.CombIsoCut = 0.1
ewpol_conf.Common.Electrons.PtCut = 15.0
ewpol_conf.Common.Electrons.EtaCut = 2.4

# These are turned off anyhow
ewpol_conf.Common.Electrons.TrkIsoCut = -1.
ewpol_conf.Common.Electrons.CombIsoCut = 0.1
ewpol_conf.Common.Electrons.TightID = True
ewpol_conf.Common.ApplyXCleaning=False
ewpol_conf.Common.Electrons.ApplyID=False

ewpol_conf.Common.Photons.EtCut = 25.0
ewpol_conf.Common.Photons.EtaCut = 2.5
ewpol_conf.Common.Photons.TrkIsoCut = 9.
ewpol_conf.Common.Photons.EcalIsoCut = 99999.
ewpol_conf.Common.Photons.HcalIsoCut = 99999.
#ewpol_conf.Common.Photons.AllIsoCut = 0.2
ewpol_conf.Common.Photons.IDReq = 3

ewpol_conf.Ntuple.Jets.Prefix = "ak5Jet"
