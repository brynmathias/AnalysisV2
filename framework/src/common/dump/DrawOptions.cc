/*! \file DrawOptions.cc
 * \brief Source code for the DrawOptions class.
 */
#include "DrawOptions.hh"

DrawOptions::DrawOptions(TString dataSet_)
{
  if(dataSet_ == "lm1")
   {
     reweight=1;
     color=2;
     linewidth=2;
     linestyle=1;
     drawOpt="";
     search= -1;
     LegendText="LM1 SUSY";
   }
  if (dataSet_ == "GM1g")
   {
     reweight=1;
     color=213;
     linewidth=2;
     linestyle=1;
     drawOpt="";
     search= -1;
     LegendText="GM1g GMSB SUSY";
   }
  else if(dataSet_ == "gumbo")
   {
     reweight=1;
     color=3;
     linewidth=2;
     linestyle=1;
     drawOpt="";
     search=-1;
     LegendText="QCD";
   }
  else if(dataSet_ == "znunu")
   {
     reweight=1;
     color=7;
     linewidth=2;
     linestyle=1;
     drawOpt="";
     search=-1;
 LegendText="Z#rightarrow#nu#nu";

   }
  else if(dataSet_ == "tt")
   {
     reweight=1;
     color=4;
     linewidth=2;
     linestyle=1;
     drawOpt="";
     search=-1;
     LegendText="tt";

   }
   else if(dataSet_ == "Signal And Background")
   {
     reweight=1;
     color=2;
     linewidth=2;
     linestyle=21;
     drawOpt="";
     search=-1;
     LegendText="";

   }
   else if(dataSet_ == "Background Only")
   {
     reweight=1;
     color=4;
     linewidth=2;
     linestyle=22;
     drawOpt="";
     search=-1; LegendText="";
   }
  else
   {
     reweight=1;
     color=8;
     linewidth=2;
     linestyle=1;
     drawOpt="";
     search=-1; LegendText="";
   }
}

