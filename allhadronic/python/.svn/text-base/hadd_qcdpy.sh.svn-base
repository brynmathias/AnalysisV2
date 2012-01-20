DIR=.

SHORT="TEST"
NAME=${SHORT}"_QCD_Pt_"

hadd ${NAME}15to30.root ${NAME}15to30*.root &
hadd ${NAME}30to50.root ${NAME}30to50*.root &
hadd ${NAME}50to80.root ${NAME}50to80*.root &
hadd ${NAME}80to120.root ${NAME}80to120*.root &
hadd ${NAME}120to170.root ${NAME}120to*.root &
hadd ${NAME}170to300.root ${NAME}170to*.root &
hadd ${NAME}300to470.root ${NAME}300to470*.root &
hadd ${NAME}470to600.root ${NAME}470to600*.root &
hadd ${NAME}600to800.root ${NAME}600to800*.root &
hadd ${NAME}800to1000.root ${NAME}800to1000*.root &
hadd ${NAME}1000to1400.root ${NAME}1000to1400*.root &
hadd ${NAME}1400to1800.root ${NAME}1400to1800*.root &
hadd ${NAME}1800.root ${NAME}1800*.root &

hadd ${SHORT}__qcdpy.root ${NAME}15to30.root ${NAME}30to50.root ${NAME}50to80.root ${NAME}80to120.root ${NAME}120to170.root ${NAME}170to300.root ${NAME}300to470.root ${NAME}470to600.root ${NAME}600to800.root ${NAME}800to1000.root ${NAME}1000to1400.root ${NAME}1400to1800.root ${NAME}1800.root &

