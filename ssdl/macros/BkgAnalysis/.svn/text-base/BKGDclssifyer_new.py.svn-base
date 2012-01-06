import sys
from math import sqrt

f1 = open(sys.argv[1], 'r')#reco file input
f2 = open(sys.argv[2], 'r')#gen file input
#out = open(sys.argv[3], 'w')#output file
#print sys.argv



def get_event(f, pos):
	event1 = []

	for i in range(0,4): #for the reco events, 1 is leptons, 2 Jets, 3 Common Jets
		event1.append([])
	
	f.seek(pos)
	line = f.readline()
	if line.find("===")!=-1:

       		event_num = line[line.find("(")+1:line.find(")=")] #strip the event number out
		counter = 0                                        #reset counter for every new event
		for i in range(0,4):
			event1[i]=[]                               #marks the end of the event so we clear the reco_event


	while True:



		pos_new=f.tell()
		line = f.readline()

		if line.find("--")!=-1:
			counter += 1  #counts different particle types
		if line.find(":")>=1:
			data = line[line.find(":")+1:]  #get the interesting data
			data1 = data.split()  #split it up between white (default) spaces
		       		
			data2 = []

			for d in data1:		#convert the str to floats in this loop	
				data2.append(float(d))

			event1[counter].append(data2)
		       	event1[0] = float(event_num)
		

		if(line.find("===")!=-1):
			return (event1, pos_new)
		        
		if not line:
			return (event1, None)		

		        



#non common jets (in reco_ev jets are in [2], common jets in [3] function
def non_common_jets(r_ev):
	num_jets = int(r_ev[2][0][0])
	num_nc_jets = num_jets - len(r_ev[3])
	nc_jets=[]

	for jets in range(num_jets):  #this entry stores number of jets
		jet_eta = r_ev[2][jets+1][1]
		jet_phi = r_ev[2][jets+1][2]
		test = False
		for com_jets in range(len(reco_ev[3])):
			com_jet_eta = r_ev[3][com_jets][1]
			com_jet_phi = r_ev[3][com_jets][2]

			if com_jet_eta == jet_eta and com_jet_phi == jet_phi:
				
				test = True
				break
		
		if test==False:
		       	nc_jets.append(r_ev[2][jets+1])

       	return nc_jets ##list of [[pt, eta, phi], [pt, eta, phi]...] for the non common jets


def closest_gen_lep(rec_lepton, gen):
	num_gen_leps = int(gen[1][0][0])
	if num_gen_leps == 0:
		return None
	Delta = 10.0
	for l in range (num_gen_leps):
		delta_eta = sqrt((rec_lepton[3]-gen[1][l+1][3])*(rec_lepton[3]-gen[1][l+1][3]))
		delta_phi = sqrt((rec_lepton[4]-gen[1][l+1][4])*(rec_lepton[4]-gen[1][l+1][4]))

		delta = delta_eta+delta_phi
	
		if (delta < Delta):
			Delta = delta
			(match, closness) = (gen[1][l+1], delta)

		

	return ("lep", match, closness)

			

def closest_nc_jet(rec_lepton, jet):
	num_nc_jets = len(jet)
	if num_nc_jets == 0:
		return None
	Delta = 10.0
	for l in range (num_nc_jets):
		delta_eta = sqrt((rec_lepton[3]-jet[l][1])*(rec_lepton[3]-jet[l][1]))
		delta_phi = sqrt((rec_lepton[4]-jet[l][2])*(rec_lepton[4]-jet[l][2]))

		delta = delta_eta+delta_phi
	#	print delta
		if (delta < Delta):
			Delta = delta
			(match, closness) = (jet[l], delta)

		

	return ("jet", match, closness	)


def closest_tau_jet(rec_lepton, gen_event):

	num_tau_jets = int(gen_event[2][0][2])

	Delta = 10.0
	if num_tau_jets == 0:
		return None
	for l in range (num_tau_jets):
		delta_eta = sqrt((rec_lepton[3]-gen_event[2][l+1][3])*(rec_lepton[3]-gen_event[2][l+1][3]))
		delta_phi = sqrt((rec_lepton[4]-gen_event[2][l+1][4])*(rec_lepton[4]-gen_event[2][l+1][4]))

		delta = delta_eta+delta_phi
	
		if (delta < Delta):
			Delta = delta
			(match, closness) = (gen_event[2][l+1], delta)

		

	return ("tjet", match, closness	)

def charge_check(reco_lep, best_match):
	reco_charge = reco_lep[1]
	if best_match is None:
		return None
	if best_match[0] == "jet":
		return None
	if best_match[0] == "lep":
		if reco_charge*best_match[1][1]<0:
			charge = True
		else:
			charge = False
	if best_match[0] == "tjet":
		if reco_charge*best_match[1][1]<0:
			charge = True
		else: 
			charge = False
	
	return charge

def iso_check(best_lepton):
	iso = False
	if best_lepton is None:
		return iso
	if best_lepton[0] == "jet":
		return iso
	if (best_lepton[0] == "lep" or best_lepton[0] == "tjet"):
		if best_lepton[1][0]==1.0:
			iso = True

	return iso
		
		
			




gen_pos = reco_pos = 0
infile = True
tot_events=A0=A1=A2=B0=B1=C=X=0 ##some counters
A0 = [0, 0, 0, 0, 0, 0]
A1 = [0, 0, 0, 0, 0, 0]
A2 = [0, 0, 0, 0, 0, 0]
B0 = [0, 0, 0, 0, 0, 0]
B1 = [0, 0, 0, 0, 0, 0]
C = [0, 0, 0, 0, 0, 0]
D = [0,0,0,0,0,0]
X= [0,0,0,0,0,0]
event_number = 0
#for i in range(2):
while infile:
	(gen_ev, gen_pos) = get_event(f2, gen_pos)
	(reco_ev, reco_pos) = get_event(f1, reco_pos)

	tot_events += 1
	if gen_pos is None:
		infile = False
		f1.close()
		f2.close()
		print "===================END OF FILE REACHED===================="


	print reco_ev[0] #prints event number


#[1] index is lepton for gen and reco
	tot_reco_leps = reco_ev[1][0][0]
	
#some gen stuff, num of gen leps and iso leps
	tot_iso_leps = gen_ev[1][0][1]  
	num_gen_leps = gen_ev[1][0][0]

	
	non_com_jets = non_common_jets(reco_ev)

#LEPTON ANALYSIS
##leptons have [id, charge, pt, eta, phi] structure
	first_lepton = reco_ev[1][1]
	second_lepton = reco_ev[1][2]

	t1_1lep = closest_gen_lep(first_lepton, gen_ev)
	t2_1lep = closest_nc_jet(first_lepton, non_com_jets)
	t3_1lep = closest_tau_jet(first_lepton, gen_ev)

	

	t1_2lep = closest_gen_lep(second_lepton, gen_ev)
	t2_2lep = closest_nc_jet(second_lepton, non_com_jets)
	t3_2lep = closest_tau_jet(second_lepton, gen_ev)


	lep1_matches = [t1_1lep,t2_1lep, t3_1lep]
	lep2_matches = [t1_2lep, t2_2lep, t3_2lep]

	for i in range (3):
		k = len(lep1_matches)
		for i in range (k):
			if lep1_matches[i] == None:
				lep1_matches.pop(i)
				lep2_matches.pop(i)
				break

	if len(lep1_matches)==0:
		lep1_best = None
	if len(lep2_matches)==0:
		lep1_best = None
	else:
		lep1_best = lep1_matches[0]
		lep2_best = lep2_matches[0]
		for i in range(len(lep1_matches)):
			if lep1_matches[i][2]<lep1_best[2]:
				lep1_best = lep1_matches[i]
			if lep2_matches[i][2]<lep2_best[2]:
				lep2_best = lep2_matches[i]


		if lep1_best[2] > 0.5:
			lep1_best = None
		if lep2_best[2] > 0.5:
			lep2_best = None

#CHECK CHARGE CORRESPONDANCE

	lep1_charge = charge_check(first_lepton, lep1_best)
	lep2_charge = charge_check(second_lepton, lep2_best)

#CHECK ISO of match
	
	iso1 = iso_check(lep1_best)
	iso2 = iso_check(lep2_best)


#subcategorisation - this indicates what the reco particle is and what it was reconstructed from

	first_reco_lep =int(reco_ev[1][1][0])
	second_reco_lep =int(reco_ev[1][2][0])

	if first_reco_lep == 1:
		print "=========================HERE IS A RECO ELECTRON============================="
	if second_reco_lep == 1:
		print "=========================HERE IS A RECO ELECTRON============================="

	reco_pair = str(first_reco_lep)+str(second_reco_lep)

	
	#use same def for FS type as used in analysis code (0-ee, 1-mm, 2-tt, 3-em, 4-et, 5-mt)
	if reco_pair == '11':
		FStype = 0
	if reco_pair == '22':
		FStype = 1
	if reco_pair == '33':
		FStype = 2
	if reco_pair == '21' or reco_pair == '12':
		FStype = 3
	if reco_pair == '31' or reco_pair == '13':
		FStype = 4
	if reco_pair == '23' or reco_pair == '32':
		FStype = 5

#	print FStype




	if lep1_best is None: 
		if lep2_best is not None:
			if lep2_best[0] == 'tjet':
				best_match_pair = '(?' +','+str(lep2_best[1][1])+')'
			if lep2_best[0] == 'lep':
			       	best_match_pair = '(?' +','+str(lep2_best[1][1])+')'
			if lep2_best[0] == 'jet':
				best_match_pair = '(?, jet)'
		if lep2_best is None:
			best_match_pair =  '(?,?)'
	if lep1_best!=None:
		if lep1_best[0]=='lep':
			if lep2_best is not None:
			
				if lep2_best[0] == 'lep':
					best_match_pair ='('+ str(int(lep1_best[1][1]))+','+str(int(lep2_best[1][1]))+')'
				if lep2_best[0] == 'tjet':
					best_match_pair = '(' +str(int(lep1_best[1][1]))+','+str(int(lep2_best[1][1]))+')'
				if lep2_best[0] == 'jet':
					best_match_pair = '(' +str(int(lep1_best[1][1]))+', jet)'
			if lep2_best is None:
				best_match_pair =  '(' +str(int(lep1_best[1][1]))+', ?)'

		if lep1_best[0]=='tjet':
			if lep2_best is not None:
			
				if lep2_best[0] == 'tjet':
					best_match_pair = '('+ str(int(lep1_best[1][0]))+','+str(int(lep2_best[1][1]))+')'
				if  lep2_best[0] == 'lep':
					best_match_pair='(' +str(int(lep1_best[1][0]))+','+str(int(lep2_best[1][1]))+')'
				if lep2_best[0] == 'jet':
					best_match_pair = '(' +str(int(lep1_best[1][0]))+', jet)'
			if lep2_best is None:		
				best_match_pair =  '(' +str(int(lep1_best[1][0]))+', ?)'

		if lep1_best[0]=='jet':
			if lep2_best is not  None:
			
				if lep2_best[0] == 'tjet':
					best_match_pair = '(jet' +','+str(int(lep2_best[1][0]))+')'
				if lep2_best[0] == 'lep':
					best_match_pair = '(jet' +','+str(int(lep2_best[1][1]))+')'
				if lep2_best[0] == 'jet':
					best_match_pair = '(jet, jet)'
			if lep2_best is None:
				best_match_pair =  '(jet,?)'
	


#CATEGORIES
#A0: 0 gen iso lep + 2 fakes (or no associated particles)
#A1: 0 gen iso + 1 fake + 1 gen non iso
#A2: 0 gen iso + 2 gen non iso
#B0: 1 gen iso + 1 fake
#B1: 1 gen iso + 1 gen non iso
#C: 2 gen iso + at least one wrong charge
#X: non pure SSDL

	if (tot_reco_leps != 2.0):  #category X checker
		category = "X"
		print category
		X[FStype]+=1
	

	elif(lep1_best is None and lep2_best is None):
		category = "X"+reco_pair+best_match_pair
		print category
		X[FStype]+=1
	

	elif(lep1_best is None):
	#	if reco_ev[0]==109.0:
		#	print "================NO LEP1==================="
		#print lep2_best
		if(lep2_best[0]=="jet"):
			category = "A0"+reco_pair+best_match_pair
			print category
			A0[FStype]+=1
		

		elif ((lep2_best[0]=="lep" or lep2_best[0]=="tjet") and iso2 == False):
			
			category = "A1"+reco_pair+best_match_pair
			print category
			A1[FStype]+=1
	

		elif((lep2_best[0]=="lep" or lep2_best[0] == "tjet")and iso2 == True):
			category = "B0"+reco_pair+best_match_pair
			print category
			B0[FStype]+=1
		

	elif(lep1_best[0]=="jet"):
		if lep2_best is None:
			category = "A0"+reco_pair+best_match_pair
			print category
			A0[FStype]+=1
		
		elif lep2_best[0] == "jet":
			category = "A0"+reco_pair+best_match_pair
			print category
			A0[FStype]+=1
		       			
		elif((lep2_best[0]=="lep" or lep2_best[0] == "tjet")and iso2 == True):
			category = "B0"+reco_pair+best_match_pair
			print category
			B0[FStype]+=1
			
		elif((lep2_best[0]=="lep" or lep2_best[0] == "tjet")and iso2 == False):
			category = "A1"+reco_pair+best_match_pair
			print category
			A1[FStype]+=1
			


	elif(lep1_best[0]=="lep" or lep1_best[0] == "tjet") and iso1 == False:
	
		if lep2_best is None:
			category = "A1"+reco_pair+best_match_pair
			print category
			A1[FStype]+=1
			
		elif lep2_best[0] == "jet":
		       	category ="A1"+reco_pair+best_match_pair
	       		print category
       			A1[FStype]+=1
		

		elif (lep2_best[0]=="lep" or lep2_best[0]=="tjet"):
			if iso2 == False:
				category = "A2"+reco_pair+best_match_pair
				print category
				A2[FStype]+=1

			elif iso2 == True:
				category = "B1"+reco_pair+best_match_pair
				B1[FStype]+=1
				print category

	elif(lep1_best[0] == "lep" or lep1_best[0] == "tjet") and iso1 == True:

		if lep2_best is None:
			category = "B0" +reco_pair+best_match_pair
			print category
			B0[FStype]+=1
		
		elif lep2_best[0]=="jet":
			category = "B0"+reco_pair+best_match_pair
			print category
			B0[FStype]+=1
		
		elif (lep2_best[0]=="lep" or lep2_best[0]=="tjet"):
			if iso2 == False:
				category = "B1" +reco_pair+best_match_pair
				print category
				B1[FStype]+=1
			
			elif iso2==True:
				if (lep1_charge==False or lep2_charge==False):
					category = "C"+reco_pair+best_match_pair
					print category
					C[FStype]+=1
				elif(lep1_charge==False and lep2_charge==False):
					category = "C"+reco_pair+best_match_pair
					print category
					C[FStype]+=1

				elif(lep1_charge==True and lep2_charge==True):
					category = "D"+reco_pair+best_match_pair
				#	print lep1_best
				#	print lep2_best
				#	print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
					print category
					D[FStype]+=1

				



		   

print tot_events
tot = 0
for i in range (6):
	print  i, " Type A0:",A0[i]," Type A1:",A1[i]," Type A2:",A2[i]," Type B0:",B0[i]," Type B1:",B1[i]," Type C:",C[i]," Type D:", D[i]," Type X:",X[i]
	tot += A0[i] + A1[i] + A2[i] +B0[i] + B1[i] + C[i] +D[i]+ X[i]

print tot

