#!/usr/bin/env python

# SUSYv2 configuration script
# alex.sparrow@cern.ch
import sys
import os

# prompt user for input string
def my_input(prompt,default):
  val=raw_input("%s (default='%s'):" % (prompt,default))
  if(val.lstrip().rstrip()==""):
    return default
  else:
    return val

# prompt user to overwrite file
def prompt_file_overwrite(path):
  if os.path.exists(path):
    print "File %s exists. Do you want to overwrite (default n)" % path
    return (raw_input("y/n:").lstrip().rstrip()=="y")
  return True

def prompt(install,var,name):
  if var in install:
    if(install[var][0]):
      val=my_input("Please enter '%s'" %name,install[var][1])
    else:
      val=install[var][1]
  else:
    val=""
  return val

# SLC4 64 bit installation defaults
slc4_64={"name":"SLC4 - 64 bit",
   "platform" : (False,"linux"),
   "root_sys" : (True,"/afs/cern.ch/sw/lcg/app/releases/ROOT/5.26.00/slc4_amd64_gcc34/root"),
   "root_sys_inc" : (False,"$(ROOTSYS)/include"),
   "root_sys_lib" : (False,"$(ROOTSYS)/lib"),
   "root_sys_bin" : (False,"$(ROOTSYS)/bin"),
   "python_inc" : (False,"/usr/include/python2.3"),
   "python_lib" : (False,"-lpython2.3"),
   "boost_python_lib" : (False,"-lboost_python"),
   "root_extra_libs" : (False,"-lMathCore -lMathMore -lGenVector"),
   "link_search_extra" : (False,""),
   "incdir_extra" : (False,""),
   "ld_path_extra" : (False,""),
   "python_env" : (False,""),
}

# SLC4 32 bit - just change name and ROOT version
slc4_32=slc4_64.copy()
slc4_32["name"]="SLC4 - 32 bit"
slc4_32["root_sys"]=(True,"/afs/cern.ch/sw/lcg/app/releases/ROOT/5.26.00/slc4_ia32_gcc34/root")


# SLC5 64 bit - just need to change Python and root
slc5_64=slc4_64.copy()
slc5_64["name"]="SLC5 - 64 bit"
slc5_64["root_sys"]=(True,"/afs/cern.ch/sw/lcg/app/releases/ROOT/5.27.04/x86_64-slc5-gcc43-dbg/root")
slc5_64["python_inc"]=(False,"/usr/include/python2.4")
slc5_64["python_lib"]=(False,"-lpython2.4")
slc5_64["root_extra_libs"]=(True,"-lMathCore -lMathMore -lGenVector -lRooFit -lRooStats")

# Linux other install - default for ubuntu 9.10
linux_other={"name":"Ubuntu 9.10",
       "platform":(False,"linux"),
       "root_sys" : (False,""),
       "root_sys_inc" : (True,"/usr/include/root"),
       "root_sys_lib" : (True,"/usr/lib/"),
       "root_sys_bin" : (True,"/usr/bin"),
       "python_inc" : (True,"/usr/include/python2.6"),
       "python_lib" : (True,"-lpython2.6"),
       "boost_python_lib" : (True,"-lboost_python-mt"),
       "root_extra_libs" : (True,"-lMathCore -lMathMore"),
       "link_search_extra" : (False,""),
       "incdir_extra" : (False,""),
       "ld_path_extra" : (False,""),
       "python_env" : (False,""),
       }

# Mac OS X Snow Leopard
macosx={"name":"Mac OS X 10.6 - 64 bit",
  "platform":(False,"__APPLE__"),
  "root_sys" : (False,"/opt/root_5_25"),
  "root_sys_inc" : (False,"$(ROOTSYS)/include"),
  "root_sys_lib" : (False,"$(ROOTSYS)/lib"),
  "root_sys_bin" : (False,"$(ROOTSYS)/bin"),
  "python_inc" : (True,"/System/Library/Frameworks/Python.Framework/Versions/2.6/include/python2.6"),
  "python_lib" : (True,"-lpython2.6"),
  "boost_python_lib" : (True,"-lboost_python-mt"),
  "root_extra_libs" : (False,"-lMathCore -lMathMore -lGenVector"),
  "link_search_extra": (True,"-L/opt/local/lib"),
  "incdir_extra" : (True,"-I/opt/local/include"),
  "ld_path_extra" : (False,""),
  "python_env" : (False,"")
}

# Mac OS X Lion
macosxLion={"name":"Mac OS X 10.7 - 64 bit",
  "platform":(False,"__APPLE__"),
  "root_sys" : (False,"/opt/root"),
  "root_sys_inc" : (False,"$(ROOTSYS)/include"),
  "root_sys_lib" : (False,"$(ROOTSYS)/lib"),
  "root_sys_bin" : (False,"$(ROOTSYS)/bin"),
  "python_inc" : (True,"/System/Library/Frameworks/Python.Framework/Versions/2.7/include/python2.7"),
  "python_lib" : (True,"-lpython2.7"),
  "boost_python_lib" : (True,"-lboost_python-mt"),
  "root_extra_libs" : (False,"-lMathCore -lMathMore -lGenVector"),
  "link_search_extra": (True,"-L/opt/local/lib"),
  "incdir_extra" : (True,"-I/opt/local/include"),
  "ld_path_extra" : (False,""),
  "python_env" : (False,"")
}

# SLC4 64 bit installation defaults
iclx={"name":"IC LX",
      "platform" : (False,"linux"),
      "root_sys" : (True,"/vols/sl5_exp_software/cms/slc5_ia32_gcc434/lcg/root/5.22.00d-cms39/"),
      "root_sys_inc" : (False,"$(ROOTSYS)/include"),
      "root_sys_lib" : (False,"$(ROOTSYS)/lib"),
      "root_sys_bin" : (False,"$(ROOTSYS)/bin"),
      "python_inc" : (False,"/usr/include/python2.4"),
      "python_lib" : (False,"-lpython2.6"),
      "boost_python_lib" : (False,"-lboost_python"),
      "root_extra_libs" : (False,"-lMathCore -lMathMore -lGenVector"),
      "link_search_extra" : (False,"-L/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/boost/1.44.0-cms/lib/ -L/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/python/2.6.4-cms12/lib/"),
      "incdir_extra" : (False,"-I/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/boost/1.44.0-cms/include/ -I/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/python/2.6.4-cms12/include/"),
      "ld_path_extra" :
(False,"/vols/grid/glite/ui/current/globus/lib/:/vols/cms/grid/dcap:/vols/grid/glite/ui/current/d-cache/dcap/lib:/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/libungif/4.1.4-cms/lib/:/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/libjpg/8b/lib:/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/python/2.6.4-cms12/lib/:/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/boost/1.44.0-cms/lib/:/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/gcc/4.3.4/lib/"),
      "python_env" : (False,"/vols/sl5_exp_software/cms/slc5_ia32_gcc434/external/python/2.6.4-cms12/bin/")
      }

iclx_root_527={"name":"IC LX (64bit ROOT 5.27)",
      "platform" : (False,"linux"),
      "root_sys" : (True,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/"),
      "root_sys_inc" : (False,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/include/"),
      "root_sys_lib" : (False,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/lib/"),
      "root_sys_bin" : (False,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/bin/"),
      "python_inc" : (False,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6/"),
      "python_lib" : (False,"-lpython2.6"),
      "boost_python_lib" : (False,"-lboost_python"),
      "root_extra_libs" : (False,"-lMathCore -lMathMore -lGenVector"),
      "link_search_extra" : (False,"-L/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/lib -L/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/lib"),
      "incdir_extra" : (False,"-I/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6 -I/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/include"),
      "ld_path_extra" :
(False,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/libjpg/8b/lib:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/lib:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/lib:/vols/grid/ui/3.2.5-0/d-cache/dcap/lib64:/vols/grid/ui/3.2.5-0/d-cache/dcap/lib:/vols/grid/ui/3.2.5-0/glite/lib:/vols/grid/ui/3.2.5-0/glite/lib64:/vols/grid/ui/3.2.5-0/globus/lib:/vols/grid/ui/3.2.5-0/lcg/lib:/vols/grid/ui/3.2.5-0/lcg/lib64:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/gcc/4.3.4/lib64:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/xrootd/5.28.00d/lib"),
      "python_env" : (False,"/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/bin"),
      }

bristol_root_527={"name":"Bristol (64bit ROOT 5.27)",
      "platform" : (False,"linux"),
      "root_sys" : (True,"/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/"),
      "root_sys_inc" : (False,"/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/include/"),
      "root_sys_lib" : (False,"/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/lib/"),
      "root_sys_bin" : (False,"/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/bin/"),
      "python_inc" : (False,"/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6/"),
      "python_lib" : (False,"-lpython2.6"),
      "boost_python_lib" : (False,"-lboost_python"),
      "root_extra_libs" : (False,"-lMathCore -lMathMore -lGenVector"),
      "link_search_extra" : (False,"-L/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/lib -L/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/lib"),
      "incdir_extra" : (False,"-I/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6 -I/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/include"),
      "ld_path_extra" :
(False,"/cms/slc5_amd64_gcc434/external/libjpg/8b/lib:/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/lib:/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/lib:/opt/g/ui/3.2.7-0/d-cache/dcap/lib64:/opt/g/ui/3.2.7-0/d-cache/dcap/lib:/opt/g/ui/3.2.7-0/glite/lib:/opt/g/ui/3.2.7-0/glite/lib64:/opt/g/ui/3.2.7-0/globus/lib:/opt/g/ui/3.2.7-0/lcg/lib:/opt/g/ui/3.2.7-0/lcg/lib64:/cms/slc5_amd64_gcc434/external/gcc/4.3.4/lib64:/cms/slc5_amd64_gcc434/external/xrootd/5.28.00d/lib"),
      "python_env" : (False,"/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/bin"),
      }
ubuntu_1004={"name":"Ubuntu 10.04",
             "platform":(False,"linux"),
             "root_sys" : (False,""),
             "root_sys_inc" : (True,"/usr/include/root"),
             "root_sys_lib" : (True,"/usr/lib/"),
             "root_sys_bin" : (True,"/usr/bin"),
             "python_inc" : (True,"/usr/include/python2.6"),
             "python_lib" : (True,"-lpython2.6"),
             "boost_python_lib" : (True,"-lboost_python"),
             "root_extra_libs" : (True,"-lMathCore -lMathMore"),
             "link_search_extra" : (False,""),
             "incdir_extra" : (False,""),
             "ld_path_extra" : (False,""),
             "python_env" : (False,""),
       }

linux_custom={"name":"Linux Generic (With Custom ROOTSYS)",
        "platform":(False,"linux"),
        "root_sys" : (True,""),
        "root_sys_inc" : (False,"$(ROOTSYS)/include"),
        "root_sys_lib" : (False,"$(ROOTSYS)/lib"),
        "root_sys_bin" : (False,"$(ROOTSYS)/bin"),
        "python_inc" : (True,"/usr/include/python2.6"),
        "python_lib" : (True,"-lpython2.6"),
        "boost_python_lib" : (True,"-lboost_python"),
        "root_extra_libs" : (True,"-lMathCore -lMathMore -lGenVector"),
        "link_search_extra" : (False,""),
        "incdir_extra" : (False,""),
        "ld_path_extra" : (False,""),
        "python_env" : (False,""),
        }

inst_types=[iclx_root_527, iclx, bristol_root_527,slc4_32, slc4_64, slc5_64,linux_other,macosx,macosxLion,ubuntu_1004, linux_custom]

print "Please enter path to the directory containing the SUSY code."
base_dir=my_input("Code directory",sys.path[0])

print "Please choose installation type."
idx=0
for inst in inst_types:
  print "[%d] %s" % (idx,inst["name"])
  idx+=1
"Please enter number 0-%d (default is [%d] %s)" % (idx+1,0,inst_types[0])

inst_type=my_input("Installation type","0")
try:
  inst_int=int(inst_type.lstrip().rstrip())
  install=inst_types[inst_int]
except:
  print "Invalid Selection"
  sys.exit(1)

print "Starting Installation: %s" % install["name"]
platform=prompt(install,"platform","Platform Type")
root_sys=prompt(install,"root_sys","ROOT Path")
root_sys_inc=prompt(install,"root_sys_inc","ROOT Include Path")
root_sys_lib=prompt(install,"root_sys_lib","ROOT Library Path")
root_sys_bin=prompt(install,"root_sys_bin","ROOT Binary Path")
python_inc=prompt(install,"python_inc","Python Include Path")
python_lib=prompt(install,"python_lib","Python Library Name")
boost_python_lib=prompt(install,"boost_python_lib","BOOST Python Library Name")
root_extra_libs=prompt(install,"root_extra_libs","ROOT Extra Libraries")
link_search_extra=prompt(install,"link_search_extra","Extra Link Search Command")
incdir_extra=prompt(install,"incdir_extra","Extra Include Search Command")
ld_path_extra=prompt(install,"ld_path_extra","Python Library Path")
python_env=prompt(install,"python_env","Python Executable Environment")

f=open(base_dir+"/tools/config_template/setup.sh","r")
setup_sh=f.read()
setup_sh=setup_sh.replace("TMP_BASE_DIR",base_dir.replace(os.environ.get('HOME'),"$HOME"))
setup_sh=setup_sh.replace("TMP_ROOT_SYS",root_sys)
setup_sh=setup_sh.replace("TMP_LD_PATH_EXTRA",ld_path_extra)
if python_env:
  setup_sh=setup_sh.replace("TMP_PYTHON_ENV", 'export PATH=%s:$PATH'%python_env)
else:
  setup_sh=setup_sh.replace('TMP_PYTHON_ENV', '')


# On Mac we need to use DYLD_LIBRARY_PATH instead of LD_LIBRARY_PATH
if(platform=="__APPLE__"):
  setup_sh=setup_sh.replace("TMP_LDPATH_VAR","DYLD_LIBRARY_PATH")
elif(platform=="linux"):
  setup_sh=setup_sh.replace("TMP_LDPATH_VAR","LD_LIBRARY_PATH")

if prompt_file_overwrite(base_dir+"/setup.sh"):
  print "Writing file: %s" % base_dir+"/setup.sh"
  f=open(base_dir+"/setup.sh","w")
  f.write(setup_sh)
f=open(base_dir+"/tools/config_template/setup.csh","r")
setup_csh=f.read()
setup_csh=setup_csh.replace("TMP_BASE_DIR",base_dir.replace(os.environ.get('HOME'),"$HOME"))
setup_csh=setup_csh.replace("TMP_ROOT_SYS",root_sys)
setup_csh=setup_csh.replace("TMP_LD_PATH_EXTRA",ld_path_extra)
if prompt_file_overwrite(base_dir+"/setup.csh"):
  print "Writing file: %s" % base_dir+"/setup.csh"
  f=open(base_dir+"/setup.csh","w")
  f.write(setup_csh)
f=open(base_dir+"/tools/config_template/config.inc","r")
config_inc=f.read()
config_inc=config_inc.replace("TMP_ROOTSYS_INC",root_sys_inc)
config_inc=config_inc.replace("TMP_ROOTSYS_LIB",root_sys_lib)
config_inc=config_inc.replace("TMP_ROOTSYS_BIN",root_sys_bin)
config_inc=config_inc.replace("TMP_PYTHON_INC",python_inc)
config_inc=config_inc.replace("TMP_PYTHON_LIB",python_lib)
config_inc=config_inc.replace("TMP_BOOST_PYTHON_LIB",boost_python_lib)
config_inc=config_inc.replace("TMP_ROOT_EXTRA_LIBS",root_extra_libs)
config_inc=config_inc.replace("TMP_INCDIR_EXTRA",incdir_extra)
config_inc=config_inc.replace("TMP_PLATFORM",platform)
config_inc=config_inc.replace("TMP_LINK_SEARCH_EXTRA",link_search_extra)
if prompt_file_overwrite(base_dir+"/config.inc"):
  print "Writing file: %s" % base_dir+"/config.inc"
  f=open(base_dir+"/config.inc","w")
  f.write(config_inc)
