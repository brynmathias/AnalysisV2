#!/usr/bin/env python

# jadd: like hadd, but for log files (JSON)
#
# usage: ./jadd.py out.log in_1.log in_2.log
# or   : ./jadd.py out.log in_*
#
# Robin Nandi, 30 October 2010

import os
import sys
import json
import math

def Check(test_dict, dict, i, res):
  if i == 0:
    res = res and test_dict.keys() == [u'Cut Flow', u'Number of Events Processed', u'Dataset Configuration', u'Dataset', u'Weighting', u'Configuration']
    if "Configuration" in dict.keys() and "Configuration" in test_dict.keys():
      res = res and test_dict["Configuration"] == dict["Configuration"]
    if "Weighting" in dict.keys() and "Weighting" in test_dict.keys():
      res = res and test_dict["Weighting"] == dict["Weighting"]
  if type(test_dict) == type({}) and type(dict) == type({}):
    res = res and test_dict.keys() == dict.keys()
    for key in dict.keys():
      res = res and Check(test_dict[key], dict[key], i+1, res)
  return res

def Add(test_dict, dict, i):
  if i == 0:
    if type(dict["Dataset"]) == type([]):
      dict["Dataset"] = list(set(dict["Dataset"]).union(set(test_dict["Dataset"])))
    else:
      if dict["Dataset"] != test_dict["Dataset"]: 
        dict["Dataset"] = [dict["Dataset"], test_dict["Dataset"]]
    for key in dict["Dataset Configuration"].keys():
      if type(dict["Dataset Configuration"][key]) == type([]):
        if type(test_dict["Dataset Configuration"][key]) == type([]):
          for element in test_dict["Dataset Configuration"][key]:
            if element not in dict["Dataset Configuration"][key]:
              dict["Dataset Configuration"][key].append(element)
        else:
          if test_dict["Dataset Configuration"] not in dict["Dataset Configuration"][key]:
            dict["Dataset Configuration"][key].append(test_dict["Dataset Configuration"][key])
      else:
        dict["Dataset Configuration"][key] = list(set([dict["Dataset Configuration"][key], test_dict["Dataset Configuration"][key]]))
        #dict["Dataset Configuration"][key] = [dict["Dataset Configuration"][key], test_dict["Dataset Configuration"][key]]
        #print dict["Dataset Configuration"][key]
    dict["Number of Events Processed"] = dict["Number of Events Processed"] + test_dict["Number of Events Processed"]
  if type(test_dict) == type({}) and type(dict) == type({}):
    keys = dict.keys()
    keys.sort()
    for key in keys:
      if key == "efficiency":
        if dict["T"] + dict["F"] == 0:
          dict[key] = 0
        else:
          dict[key] = dict["T"]/(dict["T"] + dict["F"])
      if key == "T" or key == "F":
        dict[key] = dict[key] + test_dict[key]
      if key == "eT" or key == "eF":
        dict[key] = math.sqrt(dict[key]*dict[key] + test_dict[key]*test_dict[key])
      dict[key] = Add(test_dict[key], dict[key], i+1)
  return dict 

def Indent(n_indents, indent_size):
  indent = ""
  for i in range(n_indents*indent_size):
   indent = indent+" "
  return indent

def Sort(list):
  sorted_list = []
  order = ["Dataset", "Configuration", "Dataset Configuration", "Weighting", "Number of Events Processed", "Cut Flow", "Tree Name", "efficiency", "T", "eT", "F", "eF"]
  for item in order:
    if item in list:
      sorted_list.append(item)
  for item in list:
    if item not in order:
      sorted_list.append(item)
  return sorted_list

def Print(dict, file, indent, i):
  if type(dict) == type({}):
    file.write(Indent(i, indent)+"{\n")
    keys = dict.keys()
    keys.sort() # sort keys alphabetically
    keys = Sort(keys) # override alphabetic sorting for Cut Flow
    for key in keys:
      if key == keys[-1]:
        end = "\n"
      else:
        end = ",\n"
      if type(dict[key]) == type({}):
        file.write(Indent(i+1, indent)+"\""+key+"\" : \n")
      elif type(dict[key]) == type(u''):
        file.write(Indent(i+1, indent)+"\""+key+"\" : \""+str(dict[key])+"\""+end)
      else:
        file.write(Indent(i+1, indent)+"\""+key+"\" : "+str(dict[key])+end)
      Print(dict[key], file, indent, i+1)
    file.write(Indent(i, indent)+"}\n")

in_file_names = []
if len(sys.argv) > 3:
  for arg in [ sys.argv[i+2] for i in range(len(sys.argv)-2) ]:
    if arg in os.listdir("."):
      in_file_names.append(arg)
    else:
      print "Error: File "+arg+" not found."
      sys.exit(0)
else:
  print "Error: Too few arguments."
  print "Usage: ./jadd.py out.log in_1.log in_2.log"
  print "or   : ./jadd.py out.log in_*"
  sys.exit(1)
out_file_name = sys.argv[1]

out_file = open(out_file_name, "w")
in_file_1 = open(in_file_names.pop(0), "r")
dict_1 = json.load(in_file_1)
# Check that files are compatible and, if so, add them.
for in_file_name in in_file_names:
  in_file = open(in_file_name, "r") 
  dict = json.load(in_file)
  if Check(dict, dict_1, 0, True):
    dict_1 = Add(dict, dict_1, 0)
  else:
    print "Error: Files incompatible."
    sys.exit(2) 

#out_file.write(json.dumps(dict_1, sort_keys=False, indent=2))
Print(dict_1, out_file, 2, 0)
