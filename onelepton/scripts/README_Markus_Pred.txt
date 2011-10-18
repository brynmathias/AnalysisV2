To run the prediction, run first:

muon_base_(twojets).py
for the data and MC.
The output should be stored in /results in both cases.
than 
cd /results
source hadd.C
(it could well happen that due to other MC used the hadding fails, just have a look at hadd.C and change things APART of the name of the files that are added, like data.root ...)
If the hadding worked do:

cd ..
root -l cutFlow.C

The prediction+statistical uncertainties and event yield will be on your screen.
