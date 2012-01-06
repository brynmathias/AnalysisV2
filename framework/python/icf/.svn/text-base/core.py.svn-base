from libFrameworkSUSY import *
import types
import time
from optparse import OptionParser
import sys
import copy

import os
import os.path
import time
header_eq="="*50
header_dash="-"*50

# Needed since any() is new in Python 2.5
def my_any(iterable):
    for element in iterable:
        if element:
            return True
    return False

# Shamelessly ripped from supy
def dictionariesToGenerate() :
    return [
        ("pair<string,bool>", "string"),
        ("map<std::string,bool>", "string;map"),
        ("pair<string,string>", "string"),
        ("map<std::string,string>", "string;map"),
        #("std::vector<std::pair<int,std::string> >", "vector;pair;string"),
        ("ROOT::Math::Cartesian3D<float>", "Math/Point3D.h"),
        ("ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<float>,ROOT::Math::DefaultCoordinateSystemTag>", "Math/Vector3D.h"),
        ("vector<ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<float>,ROOT::Math::DefaultCoordinateSystemTag> >", "vector;Math/Vector3D.h"),
        ("ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<float>,ROOT::Math::DefaultCoordinateSystemTag>", "Math/Point3D.h"),
        ("vector<ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<float>,ROOT::Math::DefaultCoordinateSystemTag> >", "vector;Math/Point3D.h"),
        #ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > etc. is addressed in linkdef.cxx
        ("vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > >", "vector;Math/LorentzVector.h"),
        ("ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >", "Math/LorentzVector.h"),
        ("ROOT::Math::PtEtaPhiM4D<float>", "Math/LorentzVector.h"),
        ]

def generateDictionaries(inList) :
    import ROOT as r
    print "Building ROOT dictionaries. Please wait..."
    if getattr(r.gInterpreter, "GenerateDictionary", None) is None:
        print "Loading ROOT"
        r.gROOT.LoadMacro("%s/lib/linkdef_old.cxx+" % os.environ["SUSY_WORKING_SW_DIR"])
    else:
        old_dir = os.getcwd()
        os.chdir("%s/lib/" % os.environ["SUSY_WORKING_SW_DIR"])
        r.gSystem.SetIncludePath("%s -I%s/lib/" % (r.gSystem.GetIncludePath(), os.environ["SUSY_WORKING_SW_DIR"]))
        for item in inList :
            r.gInterpreter.GenerateDictionary(*item)
        os.chdir(old_dir)

def color(s, n):
    return "\033[%dm%s\033[0m" % (n,s)

def susyDir():
    import os
    try:
        return os.environ["SUSY_WORKING_SW_DIR"]
    except:
        print "SUSY environment doesn't seem to be present. Please source setup.sh"
        raise

class PSet(object):
    _dict={}
    def __init__(self,**kwargs):
        self._dict={}
        for key in kwargs:
            if kwargs[key] is not None:
                self._dict[key]=kwargs[key]

    def __setattr__(self,name,value):
        if not name.startswith("_"):
           if not name in self._dict:
               sys.stderr.write(header_eq+"\n")
               sys.stderr.write("WARNING: Binding variable in PSet ('%s') that is not in base definition.\n" % name)
               sys.stderr.write("Note that this may well be an error in your script!\n")
               sys.stderr.write(header_eq+"\n")
           self._dict[name]=value
        else:
            self.__dict__[name]=value

    def _quiet_set(self,name,value):
        self._dict[name]=value

    def __getattr__(self,name):
        if name in self._dict:
            return self._dict[name]
        else:
            raise AttributeError

    def __contains__(self,item):
        return (item in self._dict)

    def _flatten(self):
        flat={}
        for (key,val) in self._dict.iteritems():
            if val.__class__.__name__== PSet.__name__:
                for (k,v) in val._flatten().iteritems():
                    flat[key+"."+k]=v
            else:
                flat[key]=val
        return flat

    def ps(self):
        pset=ParameterSet()
        for (k,v) in self._flatten().iteritems():
            if v.__class__.__name__=="float":
                pset.AddDouble(k,v)
            elif v.__class__.__name__=="int":
                pset.AddInt(k,v)
            elif v.__class__.__name__=="str":
                pset.AddString(k,v)
            elif v.__class__.__name__=="bool":
                pset.AddBool(k,v)
            elif getattr(v, '__iter__', False):
                # Iterable type
                if not my_any([isinstance(v,t) for t in types.vector_types]):
                    try:
                        v=types.iterable_to_icf_type(v)
                    except TypeError,e:
                        print "Variable %s : %s" % (k,e)
                        raise e
                func = None
                for t in types.vector_types:
                    if isinstance(v, t):
                        func = getattr(pset, "Add%s" % t.__name__[4:], None)
                        if func: break
                if func: func(k, v)
                else: raise Exception("Cannot find C++ convertor function for iterable '%s' (type '%s')" % v.__class__.__name__)
            else: print "ERROR"
        return pset

    def print_out(self):
        for (k,v) in  self._flatten().iteritems():
            print "%s = %s" % (k,v)

    def copy(self):
        return copy.deepcopy(self)


class Analysis:
    def job_splitter(self,r,f_per_job):#this will take the run_info (from get_params) and split this into n jobs (based on files per job) for batch submission
        json_job={"jobs":[]}
        j=0
        samp=-1
        json_job["analyses"] = []

        for run_info in r:
            json_job["analyses"].append({"name": run_info["name"], "results_dir": run_info["results_dir"]})
            for s in run_info['samples']:
                samp+=1
                start_ind=0
                #we sometimes have an array, sometimes a string. This checks for that (only array is splitable atm).
                if (f_per_job!=-1 and not isinstance(s['File'],basestring)):
# this checks that the number of files is divisible by number of jobs (used to be
# len(F)/fpj>0 AND len(F)%fpj==0...but you only need the second)

                    if len(s['File'])%f_per_job==0:
                        ran=(len(s['File'])/f_per_job)
                    else: #else need an extra bin to catch overflow
                        ran=(len(s['File'])/f_per_job)+1

                    for k in range (ran):
                        json_job['jobs'].append([])
                    for i in range(-1,len(s['File'])-1,f_per_job):
                        start_ind=i+1
                        if i+f_per_job<len(s['File']):
                            end_ind=i+f_per_job#end index simply i+files per job
                        else:
                            end_ind=len(s['File'])-1#until we hit the end and catch the remainder (in overflow bin)
                        json_job['jobs'][j].append(run_info['name'])
                        json_job['jobs'][j].append(samp)
                        json_job['jobs'][j].append(start_ind)
                        json_job['jobs'][j].append(end_ind)
                        j+=1#append all this shit and move counter +1


                else:#if the files is simply a string we append it and move counter +1
                    json_job['jobs'].append([])
                    start_ind=0
                    if not isinstance(s['File'],basestring):
                        end_ind=len(s['File'])-1
                    else:
                        end_ind=0
                    json_job['jobs'][j].append(run_info['name'])
                    json_job['jobs'][j].append(samp)
                    json_job['jobs'][j].append(start_ind)
                    json_job['jobs'][j].append(end_ind)
                    j+=1


        return json_job

    def get_params(self, anal_params):
        r=[]
        for line in anal_params[0].split('\n'):
            if line.find('INFO: ')!=-1:
                try:
                    import json
                    p=(line.strip('INFO: '))
                    runinfo=json.loads(p)#this is all the bs that you need to run the analysis
                    r.append(runinfo)
                except ImportError:
                    print "subprocess module not available in this noob version of Python. Please email guido@python.org"

        return r

    def colourise(self, s):
        cols = {"WAITING":93, "RUNNING":94, "COMPLETE":92}
        return cols.get(s, 0)

    def ParseJobOutputState(self, fname):
        if os.path.getsize(fname) > 20000000: return "-"
        with open(fname) as f:
            chain_lines = [l for l in f if l.find("[CHAIN]") >= 0]
            if len(chain_lines) > 1:
                return chain_lines[-2][8:-1]
            else:
                return ""

    def ParseJobErrorState(self, fname):
        if os.path.getsize(fname) > 20000000: status[4] = "-"
        error_strs = [("Failed to create a control line","DCACHE"),
                      ("Failed open file in the dCache", "MISSING_FILE"),
                      ("segmentation violation", "SEGV")]

        err_state = []
        find_error = lambda err_str, l : l.find(err_str) >= 0
        with open(fname) as f:
            err_state = set([err_type for l in f for (err_str, err_type) in error_strs if find_error(err_str, l)])
        return " , ".join(err_state)


    def pprint(self, *args):
        s = []
        for a in args:
            tmp = ("{0:<"+str(a[1])+"}").format(a[0])
            if len(str(a[0])) and len(a) > 2 and a[2] > 0:
                tmp = color(tmp, a[2])
            s.append(tmp)
        return " ".join(s)


    def batch_status(self, dir_name):
        import glob
        try:
            n = int(dir_name)
            jobdirs = glob.glob("__susyJob__%s*" % self.jobName())
            jobdirs.sort()
            if len(jobdirs) == 0:
                print "No job directories found"
                sys.exit(1)
            dir_name = jobdirs[-n]
            print "Job directory chosen by age: %s" % dir_name
        except ValueError:
            pass
        j = None
        print "1337 Mode: %s" % dir_name
        running = waiting = complete = 0
        try:
            import json
            j = json.load(open(dir_name+"/job.json","r"))
        except ImportError:
            print "json not available in this noob version of Python. Please email guido@python.org"
            sys.exit(1)
        print "-"*80
        for a in j["analyses"]:
            print "Analysis: {0:<20} Results Dir: {1:<20}".format(a["name"], a["results_dir"])
        flist = os.listdir("%s/status/" % dir_name)
        jlist = []
        for f in flist:
            try: jlist.append(int(f))
            except: pass
        jlist.sort()
        headers = ["Job", "State",  "JOB_ID", "TASK_ID", "Log", "Error(s)"]
        widths = [5, 15, 10, 10, 20, 20]
        if not self.options.terse:
            print "-"*80
            print self.pprint(*zip(headers, widths))
            print "-"*80
        for n in jlist:
            status = open("%s/status/%d" % (dir_name, n)).read().split()
            if len(status) != 3:
                continue
            try:
                (status[1], status[2]) = (int(status[1]), int(status[2]))
            except:
                status[1] = status[2] = -1
            status.extend(["",""])
            if not (status[1] == -1 or status[2] == -1):
                max_fsize = 20000000 # Maximum file size to read
                output_fname = "%s/output/%s.o%d.%d" % (dir_name, j["script"], status[1], status[2])
                status[3] = self.ParseJobOutputState(output_fname)
                error_fname = "%s/output/%s.e%d.%d" % (dir_name, j["script"], status[1], status[2])
                status[4] =  self.ParseJobErrorState(error_fname)
            if status[0] == "RUNNING": running += 1
            elif status[0] == "WAITING": waiting += 1
            elif status[0] == "COMPLETE": complete+=1
            if not self.options.terse:
                fields = zip([n]+status, widths)
                fields[1] = (fields[1][0], fields[1][1], self.colourise(status[0]))
                fields[5] = (fields[5][0], fields[5][1], 31)
                print self.pprint(*fields)
        print "-"*80
        print "Summary"
        print "-"*80
        print "{0:<20} : {1:<5}".format(color("WAITING", self.colourise("WAITING")), waiting)
        print "{0:<20} : {1:<5}".format(color("RUNNING", self.colourise("RUNNING")), running)
        print "{0:<20} : {1:<5}".format(color("COMPLETE", self.colourise("COMPLETE")), complete)

        sys.exit(0)


    def jobName(self):
        job_name = sys.argv[0]
        if job_name[0:2] == "./":
            job_name = job_name[2:]
        return job_name

    def batch(self):
        import shutil
        try:
            import subprocess
        except ImportError:
            print "subprocess module not available in this noob version of Python. Please email guido@python.org"
        if sys.argv[0][0] == ".": proc_name = sys.argv[0]
        else: proc_name = "./%s" % sys.argv[0]
        args=[proc_name, '-l']
        p=subprocess.Popen(args,
                           stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)
        info=p.communicate()
        params=self.get_params(info)
        #needs to be plugged into Alex's method to feed this json file back to analysis.py
        jobs = self.job_splitter(params,self.options.files_per_job)
        job_name = self.jobName()
	dir_name = "__susyJob__%s_%s" % (job_name, time.strftime("%Y%m%d_%H_%M_%S"))
        os.mkdir(dir_name)
        os.mkdir(dir_name+"/output")
        os.mkdir(dir_name+"/status")
        jobs["script"] = sys.argv[0]
        try:
            import json
            json.dump(jobs, open(dir_name+"/job.json","w"), True, indent=2)
        except ImportError:
            print "json not available in this noob version of Python. Please email guido@python.org"
            sys.exit(1)
        for idx in range(len(jobs["jobs"])):
            with open("%s/status/%d" % (dir_name, idx+1), "w") as f:
                f.write(self.GetStatusString("WAITING"))
	susy_working_dir = os.environ["SUSY_WORKING_SW_DIR"]
        script_dir = os.getcwd()
	script_name = sys.argv[0]
        script_str = "#!/bin/sh\nsource %s/setup.sh\ncd %s\n%s -j %s -J ${SGE_TASK_ID} -S %s"
	open(dir_name+"/job.sh","w").write(script_str %(susy_working_dir,
                                                        script_dir,
                                                        script_name,
                                                        dir_name+"/job.json",
                                                        dir_name+"/status/${SGE_TASK_ID}"
                                                        )
                                           )
	queue=self.options.queue_select
        print "Submitting %d jobs" % len(jobs["jobs"])
        p = subprocess.Popen(["qsub",
                              "-q", queue,
                              "-t", "%d-%d:1" % (1, len(jobs["jobs"])),
                              "-o", "%s/%s/output/" % (script_dir, dir_name),
                              "-e", "%s/%s/output/" % (script_dir, dir_name),
                              "-N", job_name,
                              dir_name+"/job.sh"])
        if p.wait() == 0:
            print "%d jobs submitted successfuly" % len(jobs["jobs"])
        else:
            print "Cleaning up output directory: %s" % dir_name
            shutil.rmtree(dir_name)
            print "Failed to submit. Quitting."
            sys.exit(1)
        print  "Job directory: %s" % dir_name
        sys.exit(0)

    def __init__(self,name):
        self.ParseOptions()
        if self.options.leet_mode:
            self.batch_status(self.options.leet_mode)
        generateDictionaries(dictionariesToGenerate())
        if self.options.batch:
            self.batch()

        print "Initialising Analysis: %s" % name
	self.name=name
        self.man=Manager()

    def __iadd__(self,other):
        if getattr(other, '__iter__', False):
            for o in other:
                self.man.Add(o)
        else:
            self.man.Add(other)
        return self

    def AddUserVar(self,name,var):
        self.man.AddUserVar(name,var)

    def AddJetFilter(self,order,jfilter):
        self.man.AddJetFilter(order,jfilter)

    def AddMuonFilter(self,order,mfilter):
        self.man.AddMuonFilter(order,mfilter)

    def AddElectronFilter(self,order,efilter):
        self.man.AddElectronFilter(order,efilter)

    #TW added - 23/10/2010
    def AddPhotonFilter(self,order,gammafilter):
        self.man.AddPhotonFilter(order,gammafilter)

    def AddTauFilter(self,order,efilter):
        self.man.AddTauFilter(order,efilter)

    def AddMETFilter(self, order, mfilter):
	self.man.AddMETFilter(order, mfilter)

    def AddWeightFilter(self, order, wfilter):
        self.man.AddWeightFilter(order, wfilter)

    def ParseOptions(self):
         parser = OptionParser()
         parser.add_option("-t","--time",action="store_true",default=False, help='Time the analysis code')
         parser.add_option("-i","--ignore-version" ,action="store_true",default=False, help='Ignore ntuple version mismatch')
         parser.add_option("-s","--ignore-unknown-sample-params",action="store_true",default=False, help='Ignore unrecognised sample parameters')
         parser.add_option("-f","--force",action="store_true",default=False, help='Force')
         parser.add_option("-d","--directory",action="store",type="string",default=None, help='Produce output directory')
         parser.add_option("-l", "--list", action="store_true", default=False, help='Produce JSON listing')
         parser.add_option("-j", "--job-file", action="store", type="string", default=None, help = 'JSON job file (for batch use)')
         parser.add_option("-J", "--job-id", action="store", type="int", default=None, help='Job ID to run within JSON job file')
         parser.add_option("-b", "--batch",action="store_true", default=False, help='Run batch mode')
         parser.add_option("-n",type="int",default=-1,dest='files_per_job',help='Specify the number of files per jobs when running batch mode')
	 parser.add_option("-q",type="string",default="hepshort.q",dest='queue_select',help='Specify which que your job should submit to: hepshort.q, hepmedium.q or heplong.q')
         parser.add_option("-r", "--run-nfiles-only", type="int", metavar = "NFILES",
                           default = -1, dest = "run_nfiles_only",
                           help="Run on the first N of the files only (useful for quick tests).")
         parser.add_option("-S", "--status-file", action="store", type="string", default = None, help = "Status file (for batch use)")
         parser.add_option("-L", "--leet-mode", action="store", type="string", default=None, help = "Activate 1337 mode", metavar="JOB_DIR")
         parser.add_option("-T", "--terse", action="store_true", default=False, help = "Terse mode")
         (self.options, self.args) = parser.parse_args()
         if self.options.files_per_job!=-1 and not self.options.batch:
             parser.error("You must specify batch mode (-b)!")
	 if self.options.job_id is None and self.options.job_file is not None:
	     parser.error("Did not specify job index (-J)")

    def CheckDirExists(self,results_dir):
	 if self.options.directory is not None:
	    if not os.path.exists(results_dir+"/"+self.options.directory):
               print "Directory '%s' does not exist. Would you like to create?" % self.options.directory
               if raw_input("y/n")=="y":
	            os.mkdir(results_dir+"/"+self.options.directory)
	       else:
	            raise NameError("Directory %s does not exist. Quitting" % results_dir+"/"+self.options.directory)
	 else:
	    if not os.path.exists(results_dir) and not self.options.force:
               raise NameError("Can't find results dir: %s . Please create or rerun with -f." % results_dir)

    def GetOutputFileName(self, results_dir, sample):
	self.CheckDirExists(results_dir)
        name = ""
	if self.options.directory is not None:
	    name = results_dir+"/"+self.options.directory+"/"+self.name+"_"+sample.Name
	else:
	    name = results_dir+"/"+self.name+"_"+sample.Name
        if self.options.job_id is not None:
            name += "_%d" % self.options.job_id
        return name

    def ProcessSample(self,results_dir,sample,strict):
        s=sample.copy()
        if not "Name" in s:
            raise NameError("Sample has no property: Name")
        if not "File" in s:
            raise NameError("Sample '%s' has no property: File" % s.Name)
        if not "FirstEntry" in s:
            s._quiet_set("FirstEntry",0)
        if not "LastEntry" in s:
            s._quiet_set("LastEntry",0)
        if not "LogFile" in s:
            s._quiet_set("LogFile", self.GetOutputFileName(results_dir,s)+".log")
        if not "JsonFile" in s:
            s._quiet_set("JsonFile", self.GetOutputFileName(results_dir,s)+".json")
        if not "OutputFile" in s:
            s._quiet_set("OutputFile", self.GetOutputFileName(results_dir,s)+".root")
        if not "Reweight" in s:
            s._quiet_set("Reweight",-1.)
        if not "Weight" in s:
            s._quiet_set("Weight",-1.)
        if not "CrossSection" in s:
            s._quiet_set("CrossSection",1.)

        for (k,v) in s._dict.iteritems():
            if not k in ["Name", "File", "FirstEntry", "LastEntry", "Format",
                         "LogFile", "JsonFile", "OutputFile", "Reweight", "Weight", "CrossSection","Weights", "Events"]:
                if strict:
                    raise NameError("Unrecognised parameter in sample PSet: %s" % k)
                else:
                    print "WARNING: Unrecognised parameter in sample PSet: %s" % k

        if self.options.run_nfiles_only != -1:
            if not getattr(s.File, "__iter__", False):
                raise ValueError("--run-nfiles-only : Not in chain mode")
            else:
                s.File = s.File[0:1]

        if getattr(s.File, '__iter__', False):
            s._quiet_set("FileList",s.File)
            s._quiet_set("File","")

        if "Format" in s:
            # C++ cant handle tuples
            s._quiet_set("NtupleFormat",s.Format[0])
            s._quiet_set("NtupleVersion",s.Format[1])
            del s._dict["Format"]
        return s

    def CheckSampleVersion(self,sample):
        if not "Format" in sample:
            raise NameError("Sample '%s' has no property: Format. Please add." % s.Name)
        else:
            if (not sample.Format.__class__.__name__=="tuple" or
                not len(sample.Format)==2 or
                not sample.Format[0].__class__.__name__=="str" or
                not sample.Format[1].__class__.__name__=="int"):
                raise TypeError("Invalid Format specifier for sample '%s'" % sample.Name)
        code_format=(self.man.GetNtupleFormat(),self.man.GetNtupleVersion())
        if not sample.Format==code_format:
            print "WARNING: Ntuple version mismatch."
            print "Sample '%s' version (%sv%d) != code (%sv%d)"% (
                sample.Name,sample.Format[0],sample.Format[1],
                code_format[0],code_format[1])
            if not self.options.ignore_version:
                    print "Bailing out due to sample version mismatch."
                    print "If you run this script -i it will ignore this error."
                    print "You may need to recompile in _ICF_ or _ICF2_ mode or change the PSet definition."
                    sys.exit(1)

    def ListInfo(self, results_dir, samples):
        try:
            import json
            json_dict = {"name": self.name, "results_dir": results_dir}
            json_dict["samples"] = []
            for s in samples:
                sdict = s._dict.copy()
                if "Weights" in sdict:
                    sdict["Weights"] = sdict["Weights"]._dict
                if isinstance(sdict["File"], basestring) and "*" in sdict["File"]:
                    import glob
                    sdict["File"] = glob.glob(sdict["File"])
                elif "*" in sdict["File"]:
                    import glob
                    for idx, f in enumerate(sdict["File"]):
                        sdict["File"][idx:idx]=glob.glob(sdict["File"])
                json_dict["samples"].append(sdict)
            return json.dumps(json_dict, True)
        except ImportError:
            print "JSON module not available in this noob version of Python"
            sys.exit()

    def CheckConfig(self, conf):
        if conf.Ntuple.Muons.Suffix==conf.Ntuple.SecMuons.Suffix and conf.Ntuple.Muons.Prefix==conf.Ntuple.SecMuons.Prefix:
            print "Primary and Secondary Muon collections must be different"
            print "Please correct conf.Ntuple.SecMuons.Suffix or conf.Ntuple.SecMuons.Prefix"
            sys.exit()
        if conf.Ntuple.Jets.Suffix==conf.Ntuple.SecJets.Suffix and conf.Ntuple.Jets.Prefix==conf.Ntuple.SecJets.Prefix:
            print "Primary and Secondary Jet collections must be different"
            print "Secondary jet collection is defaulted to AK5 PF2PAT jets"
            print "Please correct conf.Ntuple.SecJets.Suffix or conf.Ntuple.SecJets.Prefix"
            sys.exit()
        if conf.Ntuple.SecJets.Suffix==conf.Ntuple.TerJets.Suffix and  conf.Ntuple.Jets.Prefix==conf.Ntuple.TerJets.Prefix:
            print "Secondary and Tertiary Jet collections must be different"
            print "Secondary jet collection is defaulted to AK5 PF2PAT jets"
            print "Tertiary jet collection is defaulted to AK5 PF jets"
            print "Please correct conf.Ntuple.SecJets.Suffix or conf.Ntuple.SecJets.Prefix"
            sys.exit()
        if conf.Ntuple.Jets.Suffix==conf.Ntuple.TerJets.Suffix and  conf.Ntuple.Jets.Prefix==conf.Ntuple.TerJets.Prefix:
            print "Jets and Tertiary Jet collections must be different"
            print "Tertiary jet collection is defaulted to AK5 PF jets"
            print "Please correct conf.Ntuple.SecJets.Suffix or conf.Ntuple.SecJets.Prefix"
            sys.exit()

    def GetStatusString(self, state):
        if "SGE_TASK_ID" in os.environ and "JOB_ID" in os.environ:
            job_no = os.environ["JOB_ID"]
            task_id = os.environ["SGE_TASK_ID"]
        else:
            job_no = "UNKNOWN"
            task_id = "UNKNOWN"
        return "{0:<15} {1:<15} {2:<15}\n".format(state, job_no, task_id)

    def Run(self,results_dir,event_config,samples):
        if self.options.job_file is not None:
            print "Batch running mode"
            import json
            if not os.path.exists(self.options.job_file):
                raise ValueError("Job file '%s' doesn't exist" % self.options.job_file)
            job = json.load(open(self.options.job_file))["jobs"][self.options.job_id-1]
            if self.name != job[0]:
                return
            samples = [samples[job[1]]]
            if getattr(samples[0].File,'__iter__',False):
                samples[0].File = samples[0].File[job[2]:job[3]+1]
	    print samples[0].File
        for sample in samples:
            self.CheckSampleVersion(sample)
        self.samples=[self.ProcessSample(results_dir,s,
                                         not self.options.ignore_unknown_sample_params)
                      for s in samples]
        if self.options.list:
            print "INFO: %s" % self.ListInfo(results_dir, samples)
            return
        # Check samples list for duplicate names
        u = {}
        for s in samples:
            u[s.Name] = 1
        if len(u.keys()) != len(samples):
            raise ValueError("You have samples with duplicate names in your analysis. Please correct.")
        print header_eq
        print "Running Analysis: %s" % (self.name)
        print header_eq
        print "On %d sample(s):" % len(self.samples)
        for sample in self.samples:
            print "\t%s\t\t%.2fpb " % (sample.Name,sample.CrossSection)
        print header_eq

        for sample in self.samples:
            if self.options.time:
                print "Timing Enabled"
                startTime=time.time()
            self.CheckConfig(event_config)
            if self.options.status_file is not None:
                with open(self.options.status_file, 'w') as f:
                    f.write(self.GetStatusString("RUNNING"))
            self.man.Run(event_config.ps(), sample.ps() )
            if self.options.status_file is not None:
                with open(self.options.status_file, 'w') as f:
                    f.write(self.GetStatusString("COMPLETE"))
            if self.options.time:
                print "Time taken: %.2fs" % (time.time() - startTime)



