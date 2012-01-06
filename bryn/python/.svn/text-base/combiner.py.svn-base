import ROOT as r

# class Combiner(object):
#   """Adds histograms in subdirectories of a root file outputting them to a new root file"""
#   def __init__(self, RootFile):
#     super(Combiner, self).__init__()
#     self.arg = arg
#     self.RootFile = RF
#

def Combiner(RootFile):
  """docstring for Combiner"""
  f = r.TFile.Open(RootFile,"UPDATE")
  f.GetListOfKeys()
  for i in range(0,len(f.GetListOfKeys())):
    file1 = (f.GetListOfKeys())[i].GetTitle()
    # print file1
    for j in range(0,len(f.GetListOfKeys())):
      file2 = (f.GetListOfKeys())[j].GetTitle()
      if file1 == file2[1:]:
        # print "Adding histograms in",  file1, "&", file2
        # print "making a directory to contain the added histograms", file1+"Combined"
        newFile = file1+"combined"
        f.mkdir(newFile)
        f.Get(newFile).cd()
        HistKeys = [ (((f.GetListOfKeys())[i].ReadObj()).GetListOfKeys())]
        HistNames = [ [k.GetName() for k in D] for D in HistKeys]

        for hist in HistNames[0]:
          Hnew= (f.Get(file1+"/"+hist)).Clone()
          if str(type(Hnew)) == "<class 'combiner.TCanvas'>" : continue
          # print type(Hnew)

          # Hnew.Add((f.Get(file1+"/"+hist)),1)
          Hnew.Add(f.Get(file2+"/"+hist),1)
          # print "added histograms ", hist
          Hnew.Write()
  # f.Write()
  f.Close()
  print "\n"+ "\n"+ "\n"+ "----------------------------------------" +"\n"+ "Finished addeding histograms in file", RootFile + "\n" + "----------------------------------------" +"\n "
  pass

