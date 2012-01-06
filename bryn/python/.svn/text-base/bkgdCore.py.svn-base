from libFrameworkSUSY import *
from libHadronic import *
import types
import time
from optparse import OptionParser
import sys
import copy


class BkgdAnalysis:
    def __init__(self,name):
        self.ParseOptions()
        print "Initialising Analysis: %s" % name
	self.name=name
        self.man=BkgdManager()

    def ParseOptions(self):
        parser = OptionParser()
        parser.add_option("-t","--time",action="store_true",default=False)
        parser.add_option("-i","--ignore-version" ,action="store_true",default=False)
        (self.options, self.args) = parser.parse_args()
       
  
    def Run(self,event_config,samples):
        self.man.Run(event_config.ps(), samples.ps() )
       
                

