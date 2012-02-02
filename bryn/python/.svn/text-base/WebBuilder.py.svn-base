
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise


def GetHist(DataSetName,col,norm,Legend):
    a = Root.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
    b = a.Get(DirKeys[dir].GetTitle()) #open the directory in the root file
    Hist = b.Get(hist) # get your histogram by name
    if Legend != 0:
      leg.AddEntry(Hist,Legend,"LP") # add a legend entry
    Hist.SetLineWidth(3)
    Hist.SetLineColor(col) #set colour
    if norm != 0:
       Hist.Scale(intlumi/100.) #if not data normilse to the data by lumi, MC is by default weighted to 100pb-1, if you have changed this change here!
    return Hist


def HistogramMaxY(H):
   Nbins = H.GetNbinsX()
   Entries = [H.GetBinContent(i) for i in range(1,Nbins+1)]
   return max(Entries)

def HistogramMinX(H):
  Nbins = H.GetNbinsX()
  for x in range(0,Nbins):
    if H.GetBinContent(x) != 0:
      return H.GetBinLowEdge(x-2)
  return 0

def HistogramMaxX(H):
  Nbins = H.GetNbinsX()
  BackItr = range(0,Nbins)
  BackItr.reverse()
  for x in BackItr :
    if H.GetBinContent(x) != 0:
      return H.GetBinLowEdge(x+1)



def Systematics(H1,H2,H3):
  Standard = H1.Clone()
  UpperError = H2.Clone()
  LowerError = H3.Clone()
  for bin in range(1,Standard.GetNbinsX()):
    StandardUpper = math.sqrt((Standard.GetBinError(bin))**2 + ((UpperError.GetBinContent(bin) - LowerError.GetBinContent(bin))/2)**2)
    Standard.SetBinError(bin, StandardUpper)
  return Standard


def PassingCutNumbers(Hist, name ,lowerBound):
  lowbin = Hist.FindBin(lowerBound)
  errorVal = Root.Double(0)
  passingCut = Hist.IntegralAndError(lowbin, Hist.GetNbinsX(), errorVal)
  textLine = "Sample = " + DirKeys[dir].GetTitle() + " " + str(Hist.GetName()) + " " + name +  " , Number passing cut of " + str(lowerBound) +" is "+ " \t " + str(passingCut) + " +/- "  + str(errorVal) + "\n"
  CutNumbers.write(textLine)



def RatioPlot(Data,BackGround):
  """docstring for RatioPlot"""
  bottom = BackGround.Clone()
  top = Data.Clone()
  top.GetYaxis().SetTitle("data / sim")
  top.Divide(bottom)

  # top.SetTitleSize(0.1, "XYZ");
  # top.SetTitleOffset(0.55, "X");
  # top.SetTitleOffset(0.3, "Y");
  # top.SetLabelSize(0.06,"XY")

  # top.SetTitleXOffset(0.9);
  # top.SetTitleYOffset(0.9);
  top.GetXaxis().SetRangeUser(MinX,MaxX)
  top.GetYaxis().SetRangeUser(0.,2.0)
  return top

def UnityLine (Data):
  """docstring for RatioPlot"""
  top = Data.Clone()  #Draw a line though the perfectly matching point
  unity = Root.TBox(top.GetXaxis().GetBinLowEdge(top.GetXaxis().GetFirst()), 0.89,MaxX, 1.11);
  unity.SetLineWidth(2);
  unity.SetLineColor(2);
  unity.SetFillColor(2);
  unity.SetFillStyle(3002)
  unity.Draw();
  return unity
  pass



def Header(intLumi):
  """docstring for Header"""
  header = '''
  <html>
  <head>
    <title> ''' "RA1 Plots using " +str(intLumi) + "pb of data" + '''


  <style type =\"text/css">
  body {
      margin:0;
      padding:0;
      border:0;
      outline:0;
      font-size:100%;
      vertical-align:baseline;
      background:#FFFFCC;
  }

  body {
      line-height:1;
  }

  article,aside,details,figcaption,figure,
  footer,header,hgroup,menu,nav,section {
    display:block;
  }

  nav ul {
      list-style:none;
  }

  blockquote, q {
      quotes:none;
  }

  blockquote:before, blockquote:after,
  q:before, q:after {
      content:'';
      content:none;
  }

  a {
      margin:0;
      padding:0;
      font-size:100%;
      vertical-align:baseline;
      background:transparent;
  }

  /* change colours to suit your needs */
  ins {
      background-color:#ff9;
      color:#000;
      text-decoration:none;
  }

  /* change colours to suit your needs */
  mark {
      background-color:#ff9;
      color:#000;
      font-style:italic;
      font-weight:bold;
  }

  del {
      text-decoration: line-through;
  }

  abbr[title], dfn[title] {
      border-bottom:1px dotted;
      cursor:help;
  }

   table {
   display: table;
   border-collapse: separate;
   border-spacing: 2px;
   border-color: gray; }

  /* change border colour to suit your needs */
  hr {
      display:block;
      height:1px;
      border:0;
      border-top:1px solid #cccccc;
      margin:1em 0;
      padding:0;
  }

  input, select {
      vertical-align:middle;
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

    </head>
  <!-- Page navigation menu -->
  <body>
  <CENTER>
  <h1>Comparison of Basic quantities for N=2 and N>=3 Jets</h1>
  <P>Data = JetMetTau ''' + str(intLumi) + ''', contact email bryn.mathias AT cern DOT ch</P>'''
  return header

  pass



def BegSec(SectionTitle):
  """docstring for table"""
  start = '''

  <h1> '''+SectionTitle+''' <a href="javascript:;" onClick="toggle(\''''+SectionTitle+ '''\');">Collapse/Expand</a>
  <div id="'''+SectionTitle+'''">\n
<table border="1" bordercolor="#000000" style="background-color:#FFFFCC" width="800" cellpadding="3" cellspacing="3"> \n
  <p> \n

  </a>
    <tr>
      <td>DiJet</td>
      <td> >=3 Jet</td>
    </tr>'''
  return start
  pass

def EndSec():
  """docstring for EndTable"""
  end = ''' </p>

  </table>
</div>'''
  return end
  pass

def Footer():
  """docstring for Footer"""
  footer = '''
    </CENTER>
    </body>
    </html>'''
  return footer
  pass

def newPlot(hist):
  """docstring for newColumn"""
  Column = "<td>" + hist + "</td>"
  return Column
  pass

def HyperLink(hist):
  """docstring for HyperLink"""
  link = "<td><a href=" + hist + '.pdf><img src=\"'+  hist + '.pdf\" width=\"400\" height=\"400\" /></a>'+ "</td> \n"
  return link
  pass





def PlotRow(a,b):
  """docstring for PlotRow"""

  row ="<tr>"  + newPlot(a) + newPlot(b) + "</tr>" + '\n' + "<tr>" + HyperLink(a) + HyperLink(b) + "</tr> </div> \n"
  return row
  pass

