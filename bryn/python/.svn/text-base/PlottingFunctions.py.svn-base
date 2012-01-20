
import errno

import ROOT as r
import math
from time import strftime
import os, commands

def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise





def HistogramMaxY(H):
   Nbins = H.GetNbinsX()
   Entries = [H.GetBinContent(i) for i in range(1,Nbins+1)]
   return max(Entries)

def HistogramMinX(H):
  Nbins = H.GetNbinsX()
  for x in range(0,Nbins):
    if H.GetBinContent(x) != 0:
      return H.GetBinLowEdge(x+1)
  return 0

def HistogramMaxX(H):
  Nbins = H.GetNbinsX()
  BackItr = range(0,Nbins)
  BackItr.reverse()
  for x in BackItr :
    if H.GetBinContent(x) != 0:
      return H.GetBinLowEdge(x+1)



def Systematics(H1,H2,H3,Smeared,outType):
  if outType == "TGraph":   Standard = r.TGraphAsymmErrors(H1)
  if outType == "TH1":  Standard = H1.Clone()
  UpperError = H2.Clone()
  LowerError = H3.Clone()
  SmearDown = 0.
  SmearUp = 0.
  up = 0.
  down = 0.
  for bin in range(1,H1.GetNbinsX()+1):
    if H1.GetBinContent(bin)-Smeared.GetBinContent(bin) < 0.:
      SmearDown = 0.
      SmearUp = (H1.GetBinContent(bin)-Smeared.GetBinContent(bin))**2
      # print H1.GetBinCenter(bin),H1.GetBinContent(bin), SmearUp
    if H1.GetBinContent(bin)-Smeared.GetBinContent(bin) > 0.:
      SmearDown =(H1.GetBinContent(bin)-Smeared.GetBinContent(bin))**2# 0.
      SmearUp = 0.

    if H1.GetBinContent(bin) - LowerError.GetBinContent(bin) > 0.:
      down = (H1.GetBinContent(bin) - LowerError.GetBinContent(bin))**2

    if H1.GetBinContent(bin) - LowerError.GetBinContent(bin) < 0.:
      up   = (H1.GetBinContent(bin) - LowerError.GetBinContent(bin))**2

    if UpperError.GetBinContent(bin)-H1.GetBinContent(bin) > 0.:
      up   = (UpperError.GetBinContent(bin)-H1.GetBinContent(bin))**2

    if UpperError.GetBinContent(bin)-H1.GetBinContent(bin) < 0.:
      down = (UpperError.GetBinContent(bin)-H1.GetBinContent(bin))**2

    if outType == "TGraph":
      Standard.SetPointError(bin-1, H1.GetBinWidth(bin)/2, H1.GetBinWidth(bin)/2,math.sqrt((H1.GetBinError(bin))**2 + down + SmearDown), math.sqrt((H1.GetBinError(bin))**2 + up + SmearUp))
    if outType == "TH1": Standard.SetBinError(bin, math.sqrt((Standard.GetBinError(bin))**2 + ((UpperError.GetBinContent(bin) - LowerError.GetBinContent(bin))/2)**2 + SmearUp) )
  return Standard
  # return True

def SystematicsSmear(H1,H2):
  """docstring for Systematics"""
  Standard = H1.Clone()
  Smeared = H2.Clone()
  for bin in range(1,Standard.GetNbinsX()+1):
    StandardUpper = math.sqrt((Standard.GetBinError(bin))**2 + (Standard.GetBinContent(bin)-Smeared.GetBinContent(bin))**2)
    # print  "Bin",Standard.GetBinCenter(bin),Standard.GetBinContent(bin),"bin error" ,Standard.GetBinError(bin)
    Standard.SetBinError(bin, StandardUpper)
  return Standard
  pass


# <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
#         "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
# <html xmlns="http://www.w3.org/1999/xhtml">

def Header(intLumi,fromFile):
  """docstring for Header"""
  header = '''

  <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
    <?xml version="1.0"?>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<title> ''' "RA1 Plots using " +str(intLumi) + "pb of data. ResutsDir was" + fromFile + ''' </title>  </head>
<META HTTP-EQUIV="Pragma" CONTENT="no-cache">

    <style type="text/css" >

/* css Zen Garden default style v1.02 */
/* css released under Creative Commons License - http://creativecommons.org/licenses/by-nc-sa/1.0/  */

/* This file based on 'Tranquille' by Dave Shea */
/* You may use this file as a foundation for any new work, but you may find it easier to start from scratch. */
/* Not all elements are defined in this file, so you'll most likely want to refer to the xhtml as well. */

/* Your images should be linked as if the CSS file sits in the same folder as the images. ie. no paths. */

    .black_overlay{
      display: none;
      position: relative;
      width: 100%;
      height: 100%;
      background-color: black;
      -moz-opacity: 0.8;
      opacity:.80;
      filter: alpha(opacity=80);
    }
    .white_content {
      display: none;
      position: relative;
      height: 75%;
      padding: 16px;
      border: 16px solid orange;
      background-color: white;
      overflow: auto;
    }


/* basic elements */
html {
  margin: 0;
  padding: 0;
  }
body {
  font: 75% georgia, sans-serif;
  line-height: 1.88889;
  color: #555753;
  background: #fff url(blossoms.jpg) no-repeat bottom right;
  margin: 0;
  padding: 0;
  }
p {
  margin-top: 0;
  text-align: justify;
  }
h3 {
  font: italic normal 1.4em georgia, sans-serif;
  letter-spacing: 1px;
  margin-bottom: 0;
  color: #7D775C;
  }
a:link {
  font-weight: bold;
  text-decoration: none;
  color: #B7A5DF;
  }
a:visited {
  font-weight: bold;
  text-decoration: none;
  color: #D4CDDC;
  }
a:hover, a:active {
  text-decoration: underline;
  color: #9685BA;
  }
acronym {
  border-bottom: none;
  }


/* specific divs */
#container {
  background: url(zen-bg.jpg) no-repeat top left;
  padding: 0 10px 0 10px;
  margin: 0;
  position: relative;
  }

#intro {
  min-width: 470px;
  }

/* using an image to replace text in an h1. This trick courtesy Douglas Bowman, http://www.stopdesign.com/articles/css/replace-text/ */
#pageHeader h1 {
  background: transparent url(h1.gif) no-repeat top left;
  margin-top: 10px;
  width: 219px;
  height: 87px;
  float: left;
  }
#pageHeader h1 span {
  display:none
  }
#pageHeader h2 {
  background: transparent url(h2.gif) no-repeat top left;
  margin-top: 58px;
  margin-bottom: 40px;
  width: 200px;
  height: 18px;
  float: right;
  }
#pageHeader h2 span {
  display:none
  }
#pageHeader {
  padding-top: 20px;
}

#quickSummary {
  clear:both;
  margin: 20px 20px 20px 10px;
  width: 160px;
  float: left;
  }
#quickSummary p {
  font: italic 10pt/22pt georgia;
  text-align:center;
  }

#table{
border-collapse:collapse;
 }
#table,th, td {
 border: 1px solid black;
 }
#preamble {
  clear: right;
  padding: 0px 10px 0 10px;
  }
#supportingText {
  padding-left: 10px;
  margin-bottom: 40px;
  }

#footer {
  text-align: center;
  }
#footer a:link, #footer a:visited {
  margin-right: 20px;
  }

#linkList {
  margin-left: 10px;
  position: absolute;
  top: 0;
  right: 0;
  }
#linkList2 {
  font: 10px verdana, sans-serif;
  background: transparent url(paper-bg.jpg) top left repeat-y;
  padding: 10px;
  margin-top: 150px;
  width: 130px;
  }
#linkList h3.select {
  background: transparent url(h3.gif) no-repeat top left;
  margin: 10px 0 5px 0;
  width: 97px;
  height: 16px;
  }
#linkList h3.select span {
  display:none
  }
#linkList h3.favorites {
  background: transparent url(h4.gif) no-repeat top left;
  margin: 25px 0 5px 0;
  width: 60px;
  height: 18px;
  }
#linkList h3.favorites span {
  display:none
  }
#linkList h3.archives {
  background: transparent url(h5.gif) no-repeat top left;
  margin: 25px 0 5px 0;
  width:57px;
  height: 14px;
  }
#linkList h3.archives span {
  display:none
  }
#linkList h3.resources {
  background: transparent url(h6.gif) no-repeat top left;
  margin: 25px 0 5px 0;
  width:63px;
  height: 10px;
  }
#linkList h3.resources span {
  display:none
  }


#linkList ul {
  margin: 0;
  padding: 0;
  }
#linkList li {
  line-height: 2.5ex;
  background: transparent url(cr1.gif) no-repeat top center;
  display: block;
  padding-top: 5px;
  margin-bottom: 5px;
  list-style-type: none;
  }
#linkList li a:link {
  color: #988F5E;
  }
#linkList li a:visited {
  color: #B3AE94;
  }


#extraDiv1 {
  background: transparent url(cr2.gif) top left no-repeat;
  position: absolute;
  top: 40px;
  right: 0;
  width: 148px;
  height: 110px;
  }
.accesskey {
  text-decoration: underline;
  }
 </style>

  <script type="text/JavaScript">
  <!-- Chief...
  function toggle(d)
  {
    var o=document.getElementById(d);
    o.style.display=(o.style.display=='none')?'block':'none';
  }
  -->
  </script>

  <!-- Page navigation menu -->
  <body>
  <CENTER>


  <h1>Comparison of Basic quantities for N=2, N>=3 &amp; N>=2 Jets </h1>
<h2>Data = JetMetTau ''' + str(intLumi) + " ResultsDir was:"+fromFile+''', contact email bryn.mathias AT cern DOT ch </h2>'''
  return header

  pass



def BegSec(SectionTitle):
  """docstring for table"""
  start = '''
  <h1> '''+SectionTitle+''' </h1> \n
  '''+ \
  "<div id=\"container\">  \n"
  return start
  pass

def EndSec():
  """docstring for EndTable"""
  end = '''
  </div>'''
  return end
  pass

def Footer():
  """docstring for Footer"""
  footer = '''
    </CENTER>
    </body>
    </hmtl>
'''
  return footer
  pass

def newPlot(hist):
  """docstring for newColumn"""
  # Column = "<td>" + hist + "</td>"
  # return Column


  text = '\n <a class="gallery slidea" href="'+hist+'.pdf" alt= \"' + hist +'\" /> \n' + \
          '<span> \n' + \
        '<img src= "./'+hist+'.png" alt="'+hist+'" title="'+hist+'" width=\"30%\"  /> \n'   + \
        ''' </span> \n'''
  return text
  pass

def HyperLink(hist):
  """docstring for HyperLink"""
  # link = "<td><a href=" + hist + '.png><img src=\"'+  hist + '.png\" width=\"400\" height=\"400\" /></a>'+ "</td> \n"
  link = ""
  return link
  pass





def PlotRow(a,b,c):
  """docstring for PlotRow"""
  # row =   newPlot(a) + newPlot(b) + newPlot(c) + "</tr>" + '\n'
  row = newPlot(a) + newPlot(b) + newPlot(c)
  return row
  pass

