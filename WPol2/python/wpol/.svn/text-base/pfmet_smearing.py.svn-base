from icf.core import PSet

# Define the pfmet smearing parameters to filter on
pfmet_smearing = PSet(
    scale = True, #if scale is set to true, the PT is multiplied by the value. If scale is set to false, the PT is smeared by a gaus of (mean,sigma) = (originalPT, value*PT)
    value = 1.0,
    doMHT = True
)

pfmet_smearres = PSet(
    smear = 0.10 #the fraction by which the relative smearing will take place
)

pfmet_smearres_PU = PSet(
    smear = 4.1 #the amount to smear pfMET in quadrature to take into account the different num_vertices and how MET resolution varies with it
)

# Define the pfmet systematic uncertainty parameters (from the JECUnc parameters)
pfmet_jecunc = PSet(
    jecuncfile = "", #the location of the JECUncertainty txt file
    lepton = "Muon", #either Muon or Electron
    pfjetthresh = 10.0, #the jet threshold to consider for the JEC Uncertainties
    unclusteredshift = 0.05, #the percentage/100 to shift the unclustered energy by
    shiftup = True #whether or not to apply the shift upwards (True) or downwards (False)
)
