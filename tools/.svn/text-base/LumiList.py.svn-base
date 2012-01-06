#!/usr/bin/env python

import json
import re

class LumiList(object):
    """
    Deal with lists of lumis in several different forms:
    Compact list:
        {
        '1': [[1, 33], [35, 35], [37, 47], [49, 75], [77, 130], [133, 136]],
        '2':[[1,45],[50,80]]
        }
        where the first key is the run number, subsequent pairs are
        ranges of lumis within that run that are desired
    Runs and lumis:
        {
        '1': [1,2,3,4,6,7,8,9,10],
        '2': [1,4,5,20]
        }
        where the first key is the run number and the list is a list of
        individual lumi sections
    Run  lumi pairs:
        [[1,1], [1,2],[1,4], [2,1], [2,5], [1,10]]
        where each pair in the list is an individual run&lumi
    CMSSW representation:
        '1:1-1:33,1:35,1:37-1:47,2:1-2:45,2:50-2:80'
        The string used by CMSSW in lumisToProcess or lumisToSkip
        is a subset of the compactList example above
    """


    def __init__(self, filename = None, lumis = None, runsAndLumis = None, runs = None, compactList = None):
        """
        Constructor takes filename (JSON), a list of run/lumi pairs,
        or a dict with run #'s as the keys and a list of lumis as the values, or just a list of runs
        """
        self.compactList = {}
        if filename:
            self.filename = filename
            jsonFile = open(self.filename,'r')
            self.compactList = json.load(jsonFile)
        elif lumis:
            runsAndLumis = {}
            for (run, lumi) in lumis:
                run = str(run)
                if not runsAndLumis.has_key(run):
                    runsAndLumis[run] = []
                runsAndLumis[run].append(lumi)

        if runsAndLumis:
            for run in runsAndLumis.keys():
                runString = str(run)
                lastLumi = -1000
                lumiList = runsAndLumis[run]
                if lumiList:
                    self.compactList[runString] = []
                    for lumi in sorted(lumiList):
                        if lumi == lastLumi:
                            pass # Skip duplicates
                        elif lumi != lastLumi + 1: # Break in lumi sequence
                            self.compactList[runString].append([lumi, lumi])
                        else:
                            nRange =  len(self.compactList[runString])
                            self.compactList[runString][nRange-1][1] = lumi
                        lastLumi = lumi
        if runs:
            for run in runs:
                runString = str(run)
                self.compactList[runString] = [[1, 0xFFFFFFF]]

        if compactList:
            for run in compactList.keys():
                runString = str(run)
                if compactList[run]:
                    self.compactList[runString] = compactList[run]


    def __sub__(self, other): # Things from self not in other
        result = {}
        for run in sorted(self.compactList.keys()):
            alumis = sorted(self.compactList[run])
            blumis = sorted(other.compactList.get(run, []))
            alist = []                    # verified part
            for alumi in alumis:
                tmplist = [alumi[0], alumi[1]] # may be part
                for blumi in blumis:
                    if blumi[0] <= tmplist[0] and blumi[1] >= tmplist[1]: # blumi has all of alumi
                        tmplist = []
                        break # blumi is has all of alumi
                    if blumi[0] > tmplist[0] and blumi[1] < tmplist[1]: # blumi is part of alumi
                        alist.append([tmplist[0], blumi[0]-1])
                        tmplist = [blumi[1]+1, tmplist[1]]
                    elif blumi[0] <= tmplist[0] and blumi[1] < tmplist[1] and blumi[1]>=tmplist[0]: # overlaps start
                        tmplist = [blumi[1]+1, tmplist[1]]
                    elif blumi[0] > tmplist[0] and blumi[1] >= tmplist[1] and blumi[0]<=tmplist[1]: # overlaps end
                        alist.append([tmplist[0], blumi[0]-1])
                        tmplist = []
                        break
                if tmplist:
                    alist.append(tmplist)
            result[run] = alist

        return LumiList(compactList = result)


    def __and__(self, other): # Things in both
        result = {}
        aruns = set(self.compactList.keys())
        bruns = set(other.compactList.keys())
        for run in aruns & bruns:
            lumiList = []                    # List for this run
            unique = []                    # List for this run
            for alumi in self.compactList[run]:
                for blumi in other.compactList[run]:
                    if blumi[0] <= alumi[0] and blumi[1] >= alumi[1]: # blumi has all of alumi
                        lumiList.append(alumi)
                    if blumi[0] > alumi[0] and blumi[1] < alumi[1]: # blumi is part of alumi
                        lumiList.append(blumi)
                    elif blumi[0] <= alumi[0] and blumi[1] < alumi[1] and blumi[1] >= alumi[0]: # overlaps start
                        lumiList.append([alumi[0], blumi[1]])
                    elif blumi[0] > alumi[0] and blumi[1] >= alumi[1] and blumi[0] <= alumi[1]: # overlaps end
                        lumiList.append([blumi[0], alumi[1]])


            if lumiList:
                unique = [lumiList[0]]
            for pair in lumiList[1:]:
                if pair[0] == unique[-1][1]+1:
                    unique[-1][1] = pair[1]
                else:
                    unique.append(pair)

            result[run] = unique
        return LumiList(compactList = result)


    def __or__(self, other):
        result = {}
        aruns = self.compactList.keys()
        bruns = other.compactList.keys()
        runs = set(aruns + bruns)
        for run in runs:
            overlap = sorted(self.compactList.get(run, []) + other.compactList.get(run, []))
            unique = [overlap[0]]
            for pair in overlap[1:]:
                if pair[0] >= unique[-1][0] and pair[0] <= unique[-1][1]+1 and pair[1] > unique[-1][1]:
                    unique[-1][1] = pair[1]
                elif pair[0] > unique[-1][1]:
                    unique.append(pair)
            result[run] = unique
        return LumiList(compactList = result)


    def __add__(self, other):
        # + is the same as |
        return self|other

    def __len__(self):
        '''Returns number of runs in list'''
        return len(self.compactList)

    def filterLumis(self, lumiList):
        """
        Return a list of lumis that are in compactList.
        lumilist is of the simple form
        [(run1,lumi1),(run1,lumi2),(run2,lumi1)]
        """
        filteredList = []
        for (run, lumi) in lumiList:
            runsInLumi = self.compactList.get(str(run), [[0, -1]])
            for (first, last) in runsInLumi:
                if lumi >= first and lumi <= last:
                    filteredList.append((run, lumi))
                    break
        return filteredList


    def __str__ (self):
        doubleBracketRE = re.compile (r']],')
        return doubleBracketRE.sub (']],\n',
                                    json.dumps (self.compactList,
                                                sort_keys=True))

    def getCompactList(self):
        """
        Return the compact list representation
        """
        return self.compactList


    def getLumis(self):
        """
        Return the list of pairs representation
        """
        theList = []
        runs = self.compactList.keys()
        runs.sort(key=int)
        for run in runs:
            lumis = self.compactList[run]
            for lumiPair in sorted(lumis):
                for lumi in range(lumiPair[0], lumiPair[1]+1):
                    theList.append((int(run), lumi))

        return theList


    def getRuns(self):
        '''
        return the sorted list of runs contained
        '''
        return sorted (self.compactList.keys())


    def getCMSSWString(self):
        """
        Turn compactList into a list of the format
        R1:L1,R2:L2-R2:L3 which is acceptable to CMSSW LumiBlockRange variable
        """

        parts = []
        runs = self.compactList.keys()
        runs.sort(key=int)
        for run in runs:
            lumis = self.compactList[run]
            for lumiPair in sorted(lumis):
                if lumiPair[0] == lumiPair[1]:
                    parts.append("%s:%s" % (run, lumiPair[0]))
                else:
                    parts.append("%s:%s-%s:%s" %
                                 (run, lumiPair[0], run, lumiPair[1]))

        output = ','.join(parts)
        return output

    def writeJSON(self, fileName):
        """
        Write out a JSON file representation of the object
        """
        jsonFile = open(fileName,'w')
        jsonFile.write("%s\n" % self)
        jsonFile.close()


    def removeRuns (self, runList):
        '''
        removes runs from runList from collection
        '''
        for run in runList:
            run = str(run)
            if self.compactList.has_key (run):
                del self.compactList[run]


    def contains (self, run, lumiSection = None):
        '''
        returns true if the run, lumi section passed in is contained
        in this lumiList.  Input can be either:
        - a single tuple of (run, lumi),
        - separate run and lumi numbers
        - a single run number (returns true if any lumi sections exist)
        '''
        if lumiSection is None:
            # if this is an integer or a string, see if the run exists
            if isinstance (run, int) or isinstance (run, str):
                return self.compactList.has_key( str(run) )
            # if we're here, then run better be a tuple or list
            try:
                lumiSection = run[1]
                run         = run[0]
            except:
                raise RuntimeError, "Improper format for run '%s'" % run
        lumiRangeList = self.compactList.get( str(run) )
        if not lumiRangeList:
            # the run isn't there, so no need to look any further
            return False
        for lumiRange in lumiRangeList:
            # we want to make this as found if either the lumiSection
            # is inside the range OR if the lumi section is greater
            # than or equal to the lower bound of the lumi range and
            # the upper bound is 0 (which means extends to the end of
            # the run)
            if lumiRange[0] <= lumiSection and \
               (0 == lumiRange[1] or lumiSection <= lumiRange[1]):
                # got it
                return True
        return False


    def __contains__ (self, runTuple):
        return self.contains (runTuple)
    
# Test JSON file

#{"1": [[1, 33], [35, 35], [37, 47]], "2": [[49, 75], [77, 130], [133, 136]]}

if __name__ == '__main__':
    #############################################
    ## Load and save command line history when ##
    ## running interactively.                  ##
    #############################################
    import os, readline
    import atexit
    historyPath = os.path.expanduser("~/.pyhistory")


    def save_history(historyPath=historyPath):
        import readline
        readline.write_history_file(historyPath)
        if os.path.exists(historyPath):
            readline.read_history_file(historyPath)


    atexit.register(save_history)
    readline.parse_and_bind("set show-all-if-ambiguous on")
    readline.parse_and_bind("tab: complete")
    if os.path.exists (historyPath) :
        readline.read_history_file(historyPath)
        readline.set_history_length(-1)

