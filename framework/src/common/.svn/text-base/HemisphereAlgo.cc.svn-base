#include "HemisphereAlgo.hh"

using namespace std;
using std::vector;

// -----------------------------------------------------------------------------
//
HemisphereAlgo::HemisphereAlgo( const std::vector<LorentzV>& componentPtr_,
				const int seed_method, 
				const int hemisphere_association_method )
  : Object(componentPtr_), 
    Object_Group(), 
    Axis1(), 
    Axis2(), 
    seed_meth(seed_method), 
    hemi_meth(hemisphere_association_method), 
    status(0) 
{
  for(int i = 0; i < (int) Object.size(); i++){
    Object_Noseed.push_back(0);
  }
}   
   
// -----------------------------------------------------------------------------
//
vector<float> HemisphereAlgo::getAxis1(){
  if (status != 1){this->reconstruct();}   
  return Axis1;
}   

// -----------------------------------------------------------------------------
//
vector<float> HemisphereAlgo::getAxis2(){
  if (status != 1){this->reconstruct();}  
  return Axis2;
}

// -----------------------------------------------------------------------------
//
vector<int> HemisphereAlgo::getGrouping(){
  if (status != 1){this->reconstruct();}  
  return Object_Group;
}

// -----------------------------------------------------------------------------
//
int HemisphereAlgo::reconstruct(){

  bool debug = false;

  int vsize = (int) Object.size();

  if (debug) std::cout << " HemisphereAlgo method " << std::endl;
  
  Object_Group.clear();
  Axis1.clear();
  Axis2.clear();

  for(int j = 0; j < vsize; j++){
    Object_Group.push_back(0);
  }

  for(int j = 0; j < 5; j++){
    Axis1.push_back(0);
    Axis2.push_back(0);
  }
 
  for (int i = 0; i <vsize; i++){
   
    if ( Object[i].P() > Object[i].E() + 0.001) { 
 
      if (debug) std::cout << "Object " << i << " has E = " << Object[i].E()
			   << " less than P = " << Object[i].P() << std::endl;
    
    } 
  } 
   
  if (debug) std::cout << " Seeding method = " << seed_meth << std::endl;
  int I_Max = -1;
  int J_Max = -1;
   
  if (seed_meth == 1) {
    
    float P_Max = 0.;
    float DeltaRP_Max = 0.;
       
    // take highest momentum object as first axis   
    for (int i=0;i<vsize;i++){    
      Object_Group[i] = 0;
      if (Object_Noseed[i] == 0 && P_Max < Object[i].P()){
        P_Max = Object[i].P();
        I_Max = i; 
      }           
    }
    
    Axis1[0] = Object[I_Max].Px() /  Object[I_Max].P();
    Axis1[1] = Object[I_Max].Py() /  Object[I_Max].P();
    Axis1[2] = Object[I_Max].Pz() /  Object[I_Max].P();
    Axis1[3] = Object[I_Max].P();
    Axis1[4] = Object[I_Max].E();
    
    // take as second axis
    for (int i=0;i<vsize;i++){     
      
      float DeltaR = deltaR(Object[i].eta(),Object[i].phi(),Object[I_Max].eta(),Object[I_Max].phi()) ;   
      
      if (Object_Noseed[i] == 0 && DeltaR > 0.5) { 
    
        float DeltaRP = DeltaR * Object[i].P();       
        if (DeltaRP > DeltaRP_Max){
          DeltaRP_Max = DeltaRP;
          J_Max = i;
	}	
      }
    } 
    
    if (J_Max >=0){
      Axis2[0] = Object[J_Max].Px() /  Object[J_Max].P();
      Axis2[1] =Object[J_Max].Py() /  Object[J_Max].P();
      Axis2[2] = Object[J_Max].Pz() /  Object[J_Max].P();
      Axis2[3] = Object[J_Max].P();
      Axis2[4] = Object[J_Max].E();
     
    } else {   
      return 0;
    }
    if (debug) std::cout << " Axis 1 is Object = " << I_Max << std::endl;
    if (debug) std::cout << " Axis 2 is Object = " << J_Max << std::endl;

   
  } else if ( (seed_meth == 2) | (seed_meth == 3)  ) {

    float Mass_Max = 0.;
    float InvariantMass = 0.;
    
    // maximize the invariant mass of two objects
    for (int i=0;i<vsize;i++){    
      Object_Group[i] = 0;
      if (Object_Noseed[i] == 0){ 
        for (int j=i+1;j<vsize;j++){  
          if (Object_Noseed[j] == 0){ 

            // either the invariant mass
            if (seed_meth == 2){
              InvariantMass =  (Object[i].E() +  Object[j].E())* (Object[i].E() + Object[j].E())
                - (Object[i].Px() + Object[j].Px())* (Object[i].Px() + Object[j].Px()) 
                - (Object[i].Py() + Object[j].Py())* (Object[i].Py() + Object[j].Py())
                - (Object[i].Pz() + Object[j].Pz())* (Object[i].Pz() + Object[j].Pz()) ;  
            } 
            // or the transverse mass
            else if (seed_meth == 3){
              float pti = sqrt(Object[i].Px()*Object[i].Px() + Object[i].Py()*Object[i].Py());
              float ptj = sqrt(Object[j].Px()*Object[j].Px() + Object[j].Py()*Object[j].Py());
              InvariantMass =  2. * (pti*ptj - Object[i].Px()*Object[j].Px()
                                     - Object[i].Py()*Object[j].Py() );
            }
            if ( Mass_Max < InvariantMass){
              Mass_Max = InvariantMass;
              I_Max = i;
              J_Max = j;
            }
          }               
        }
      }
    }
    
    if (J_Max>0) {

      Axis1[0] = Object[I_Max].Px() /  Object[I_Max].P();
      Axis1[1] = Object[I_Max].Py() /  Object[I_Max].P();
      Axis1[2] = Object[I_Max].Pz() /  Object[I_Max].P();
    
      Axis1[3] = Object[I_Max].P();
      Axis1[4] = Object[I_Max].E(); 
  
      Axis2[0] = Object[J_Max].Px() /  Object[J_Max].P();
      Axis2[1] =Object[J_Max].Py() /  Object[J_Max].P();
      Axis2[2] = Object[J_Max].Pz() /  Object[J_Max].P();
    
      Axis2[3] = Object[J_Max].P();
      Axis2[4] = Object[J_Max].E(); 

    } else {
      return 0;
    }
    if (debug) std::cout << " Axis 1 is Object = " << I_Max << std::endl;
    if (debug) std::cout << " Axis 2 is Object = " << J_Max << std::endl;
    
    
  } else {
    std::cout << "ERROR: Please give a valid seeding method!" << std::endl;
  }
   
  // seeding done 
  // now do the hemisphere association
   
  if (debug) std::cout << " Association method = " << hemi_meth << std::endl;

  int numLoop = 0;
  bool I_Move = true;


  while (I_Move && (numLoop < 100)){

    I_Move = false;
    numLoop++;
    if (debug) std::cout  << " Iteration = " << numLoop << std::endl;
   
    float Sum1_Px = 0.;
    float Sum1_Py = 0.;
    float Sum1_Pz = 0.;
    float Sum1_P = 0.;
    float Sum1_E = 0.; 
    float Sum2_Px = 0.;
    float Sum2_Py = 0.;
    float Sum2_Pz = 0.;
    float Sum2_P = 0.;
    float Sum2_E = 0.; 
   
    
    if (hemi_meth == 1) {
       
      for (int i=0;i<vsize;i++){  
        float  P_Long1 = Object[i].Px()*Axis1[0] + Object[i].Py()*Axis1[1] + Object[i].Pz()*Axis1[2];
        float  P_Long2 = Object[i].Px()*Axis2[0]+ Object[i].Py()*Axis2[1] + Object[i].Pz()*Axis2[2];
        if (P_Long1 >= P_Long2){
          if (Object_Group[i] != 1){ 
	    I_Move = true;
	  }      
          Object_Group[i] = 1;
	  Sum1_Px += Object[i].Px();
	  Sum1_Py += Object[i].Py();
	  Sum1_Pz += Object[i].Pz();
	  Sum1_P += Object[i].P();
	  Sum1_E += Object[i].E(); 
        } else {
          if (Object_Group[i] != 2){ 
	    I_Move = true;
	  }
          Object_Group[i] = 2;
	  Sum2_Px += Object[i].Px();
	  Sum2_Py += Object[i].Py();
	  Sum2_Pz += Object[i].Pz();
	  Sum2_P += Object[i].P();
	  Sum2_E += Object[i].E(); 
        }
      }
    
    } else if (hemi_meth == 2 || hemi_meth == 3){
    
      for (int i=0;i<vsize;i++){  
        if (i == I_Max) {
	  Object_Group[i] = 1;
	  Sum1_Px += Object[i].Px();
	  Sum1_Py += Object[i].Py();
	  Sum1_Pz += Object[i].Pz();
	  Sum1_P += Object[i].P();
	  Sum1_E += Object[i].E(); 
	} else if (i == J_Max) {
	  Object_Group[i] = 2;
	  Sum2_Px += Object[i].Px();
	  Sum2_Py += Object[i].Py();
	  Sum2_Pz += Object[i].Pz();
	  Sum2_P += Object[i].P();
	  Sum2_E += Object[i].E(); 
        } else {
	
	
          if(!I_Move){ 
	  
            float NewAxis1_Px = Axis1[0] * Axis1[3];
            float NewAxis1_Py = Axis1[1] * Axis1[3];
            float NewAxis1_Pz = Axis1[2] * Axis1[3];
            float NewAxis1_E = Axis1[4];
	 
            float NewAxis2_Px = Axis2[0] * Axis2[3];
            float NewAxis2_Py = Axis2[1] * Axis2[3];
            float NewAxis2_Pz = Axis2[2] * Axis2[3];
            float NewAxis2_E = Axis2[4];
       
            if (Object_Group[i] == 1){
	  
              NewAxis1_Px = NewAxis1_Px - Object[i].Px();
              NewAxis1_Py = NewAxis1_Py - Object[i].Py();
              NewAxis1_Pz = NewAxis1_Pz - Object[i].Pz();
              NewAxis1_E = NewAxis1_E - Object[i].E(); 
	 
            } else if (Object_Group[i] == 2) {
	 
              NewAxis2_Px = NewAxis2_Px - Object[i].Px();
              NewAxis2_Py = NewAxis2_Py - Object[i].Py();
              NewAxis2_Pz = NewAxis2_Pz - Object[i].Pz();
              NewAxis2_E = NewAxis2_E - Object[i].E();
            }
               
	  
            float mass1 =  NewAxis1_E - ((Object[i].Px()*NewAxis1_Px + Object[i].Py()*NewAxis1_Py +
                                          Object[i].Pz()*NewAxis1_Pz)/Object[i].P());
	 
            float mass2 =  NewAxis2_E - ((Object[i].Px()*NewAxis2_Px + Object[i].Py()*NewAxis2_Py +
                                          Object[i].Pz()*NewAxis2_Pz)/Object[i].P());
	 
            if (hemi_meth == 3) {
	 
              mass1 *= NewAxis1_E/((NewAxis1_E+Object[i].E())*(NewAxis1_E+Object[i].E()));
	 
              mass2 *= NewAxis2_E/((NewAxis2_E+Object[i].E())*(NewAxis2_E+Object[i].E()));
	
            }
	 
            if(mass1 < mass2) {
              if (Object_Group[i] != 1){ 
                I_Move = true;
              }
              Object_Group[i] = 1;
       
              Sum1_Px += Object[i].Px();
              Sum1_Py += Object[i].Py();
              Sum1_Pz += Object[i].Pz();
              Sum1_P += Object[i].P();
              Sum1_E += Object[i].E(); 
            } else {
              if (Object_Group[i] != 2){ 
                I_Move = true;
              }
              Object_Group[i] = 2;
              Sum2_Px += Object[i].Px();
              Sum2_Py += Object[i].Py();
              Sum2_Pz += Object[i].Pz();
              Sum2_P += Object[i].P();
              Sum2_E += Object[i].E(); 
	 
            }
      
      
          } else {
	
            if (Object_Group[i] == 1){
              Sum1_Px += Object[i].Px();
              Sum1_Py += Object[i].Py();
              Sum1_Pz += Object[i].Pz();
              Sum1_P += Object[i].P();
              Sum1_E += Object[i].E(); 
            }
            if (Object_Group[i] == 2){
              Sum2_Px += Object[i].Px();
              Sum2_Py += Object[i].Py();
              Sum2_Pz += Object[i].Pz();
              Sum2_P += Object[i].P();
              Sum2_E += Object[i].E(); 
            }
         
	
	
          }
	
	
        }
      }
    } else {
      std::cout << "ERROR: Please give a valid hemisphere association method!" << std::endl;
    }
    
    // recomputing the axes     

    Axis1[3] = sqrt(Sum1_Px*Sum1_Px + Sum1_Py*Sum1_Py + Sum1_Pz*Sum1_Pz);
    if (Axis1[3]<0.0001) {
      if (debug) std::cout << "ZERO objects in group 1! " << std::endl;
    } else {    
      Axis1[0] = Sum1_Px / Axis1[3];   
      Axis1[1] = Sum1_Py / Axis1[3];
      Axis1[2] = Sum1_Pz / Axis1[3];
      Axis1[4] = Sum1_E; 
    }
    
   
    
    Axis2[3] = sqrt(Sum2_Px*Sum2_Px + Sum2_Py*Sum2_Py + Sum2_Pz*Sum2_Pz);
    if (Axis2[3]<0.0001) {
      if (debug) std::cout << "ZERO objects in group 2!" << std::endl;
    } else {  
      Axis2[0] = Sum2_Px / Axis2[3];   
      Axis2[1] = Sum2_Py / Axis2[3];
      Axis2[2] = Sum2_Pz / Axis2[3];
      Axis2[4] = Sum2_E; 
    }

    if (debug) std::cout << " Grouping = ";
    for (int i=0;i<vsize;i++){  
      if (debug) std::cout << "  " << Object_Group[i];
    }
    if (debug) std::cout << std::endl;
    
  }
  
        
  status = 1;
  return 1;
}



