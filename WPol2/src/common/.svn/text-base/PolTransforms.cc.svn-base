#include "PolTransforms.hh"
//originally written Jad Marrouche, Sep 2009 onwards
namespace Operation {

  //====================================
  // Helicity Frame Transformation Function
  //====================================
  TLorentzVector HTransform(const TLorentzVector & input_particle, const TLorentzVector & w_vector) {

    bool printinfo = false; //change to select option to print out stuff

    //The following block of code is complementary to the FindBoost to get cos(theta*) - but can also find phi*

    //some notes:
    //What we want to achieve:
    //  1.Rotate our measurement axes so that the z-axis is matched with the W flight dir
    //  2.The z-x plane is in the plane spanned by the ppW
    //  3.The y-axis direction convention (up or down) is chosen so that the angle between the x-axis and the closest proton is minimised
    //Something which can easily confuse - rotating the axes is equivalent to rotating the vectors, and this is what is done in the code below.
    //The reason is simple: we want to be able to use the Phi() and CosTheta() methods - which assume measurement wrt the "standard axes".

    TLorentzVector output_particle(input_particle);
    TLorentzVector w(w_vector);
    TLorentzVector proton1;
    TLorentzVector proton2;

    //initialise our 3.5TeV protons!
    proton1.SetXYZM(0.0,0.0,3500.0,1.0);
    proton2.SetXYZM(0.0,0.0,-3500.0,1.0);

    //set-up the boost vector
    TVector3 boostvec= w.BoostVector();;

    //boost to the W rest-frame
    output_particle.Boost(-boostvec);
    proton1.Boost(-boostvec);
    proton2.Boost(-boostvec);

    //the next bit sets up the rotation of all the vectors so that we transform to the plane spanned by ppW (same as for CSTransform)
    TVector3 normal_plane1;
    TVector3 normal_plane2;
    //this is just the cross product between the two proton vector which gives a vector normal to both of them (but not a unit vector)
    double xp_i = (proton1.Py() * proton2.Pz()) - (proton1.Pz() * proton2.Py());
    double xp_j = (proton1.Pz() * proton2.Px()) - (proton1.Px() * proton2.Pz());
    double xp_k = (proton1.Px() * proton2.Py()) - (proton1.Py() * proton2.Px());
    normal_plane1.SetXYZ(xp_i, xp_j, xp_k);
    normal_plane2.SetXYZ(0.0,1.0,0.0);
    //use the vector normal to the x-z plane and the vec normal to both protons to find the rotation angle
    double rotation_angle = TMath::Pi() - normal_plane1.Angle(normal_plane2);
    TVector3 rotation_axis;
    //this is the cross product of the two normal vectors, which gives a vector parallel to the line of intersection
    double xp2_i = -1.0 * normal_plane1.Pz();
    double xp2_j = 0.0;
    double xp2_k = normal_plane1.Px();
    rotation_axis.SetXYZ(xp2_i, xp2_j, xp2_k);

    //perform the rotation by the angle
    proton1.Rotate(-rotation_angle, rotation_axis);
    proton2.Rotate(-rotation_angle, rotation_axis);
    output_particle.Rotate(-rotation_angle, rotation_axis);
    w.Rotate(-rotation_angle, rotation_axis); //this is not included in the CSTransform because we do not care about aligning to the W-vector (whereas here we do)

    //so now we are in the plane spanned by ppW
    if(printinfo) std::cout << "wY = " << w.Y() << std::endl; //this gives 0 as expected (the W lies in the same plane spanned by the 2 boosted protons)

    //now we need to rotate all the vectors so that the W z-axis is aligned with the frame z-axis. Then we measure the angle wrt the proton and the x-axis
    TVector3 zaxis(0.0,0.0,1.0);
    double rotation2 = w.Angle(zaxis);
    if(printinfo) std::cout << "angle between Wz and z-axis before rotation2: " << rotation2 << std::endl;
    w.RotateY(-rotation2); //rotation about the y-axis
    if(printinfo) std::cout << "angle between Wz and z-axis after rotation2: " << w.Angle(zaxis) << std::endl; //should be zero (i.e. w.X()=0 too, given that we know w.Y() =0)
    output_particle.RotateY(-rotation2);
    proton1.RotateY(-rotation2);
    proton2.RotateY(-rotation2);
    if(printinfo) {
      std::cout << "lepton costhetastar1: " << output_particle.CosTheta() << std::endl; //this is the right one when compared to the FindBoost method
      std::cout << "lepton phi: " << output_particle.Phi() << std::endl;
    }

    TVector3 xaxis(1.0,0.0,0.0);
    TVector3 xaxis2(-1.0,0.0,0.0);//this'll be the x-axis if we choose the other proton i.e. the normal to the "spanning" plane points the other way
    if(printinfo) {
      std::cout << "angle between proton1 and xaxis: " << proton1.Angle(xaxis) << std::endl;
      std::cout << "angle between proton2 and xaxis: " << proton2.Angle(xaxis) << std::endl;
      std::cout << "angle between proton1 and -xaxis: " << proton1.Angle(xaxis2) << std::endl;
      std::cout << "angle between proton2 and -xaxis: " << proton2.Angle(xaxis2) << std::endl;
    }
    double minAngle1, minAngle2;
    if( fabs(proton1.Angle(xaxis)) < fabs(proton2.Angle(xaxis))) minAngle1 = fabs(proton1.Angle(xaxis));
    else minAngle1 = fabs(proton2.Angle(xaxis));
    if( fabs(proton1.Angle(xaxis2)) < fabs(proton2.Angle(xaxis2))) minAngle2 = fabs(proton1.Angle(xaxis2));
    else minAngle2 = fabs(proton2.Angle(xaxis2));

    //RotateZ by TMath::Pi() if you find that the smallest angle between the x-axis and proton is the other side
    if(minAngle2 < minAngle1) {
      output_particle.RotateZ(TMath::Pi());
      proton1.RotateZ(TMath::Pi());
      proton2.RotateZ(TMath::Pi());
      w.RotateZ(TMath::Pi());
    }

    if(printinfo) {
      std::cout << "angle between proton1 and xaxis: " << proton1.Angle(xaxis) << std::endl;
      std::cout << "angle between proton2 and xaxis: " << proton2.Angle(xaxis) << std::endl;
    }

    return output_particle;

  }

  //====================================
  // CS Frame Transformation Function
  //====================================
  TLorentzVector CSTransform(const TLorentzVector & input_particle, const TLorentzVector & w_vector) {

    bool printinfo = false; //change to select option to print out stuff

    TLorentzVector proton1;
    TLorentzVector proton2;
    TLorentzVector w(w_vector);
    //TLorentzVector muon;
    //TLorentzVector neutrino;
    TLorentzVector output_particle(input_particle);

    TVector3 boostvec;

    //initialise our 3.5TeV protons!
    proton1.SetXYZM(0.0,0.0,3500.0,1.0);
    proton2.SetXYZM(0.0,0.0,-3500.0,1.0);
    //w = w_vector;
    //output_particle = input_particle;

    boostvec = w.BoostVector();
    proton1.Boost(-boostvec);
    proton2.Boost(-boostvec);
    output_particle.Boost(-boostvec);
    //muon.Boost(-boostvec);
    //neutrino.Boost(-boostvec);

    if(printinfo) {
      std::cout << "After boost into W rest-frame" << std::endl;
      std::cout << "W boson: Px= " << w.Px() << " Py= " << w.Py() << " Pz= " << w.Pz() << std::endl;
      std::cout << "Proton1: Px= " << proton1.Px() << " Py= " << proton1.Py() << " Pz= " << proton1.Pz() << std::endl;
      std::cout << "Proton2: Px= " << proton2.Px() << " Py= " << proton2.Py() << " Pz= " << proton2.Pz() << std::endl;
      std::cout << "Angle between protons in W-rest frame = " << proton1.Angle(proton2.Vect()) << std::endl;
    }

    TVector3 normal_plane1;
    TVector3 normal_plane2;
    //this is just the cross product between the two proton vectors which gives a vector normal to both of them (but not a unit vector)
    double xp_i = (proton1.Py() * proton2.Pz()) - (proton1.Pz() * proton2.Py());
    double xp_j = (proton1.Pz() * proton2.Px()) - (proton1.Px() * proton2.Pz());
    double xp_k = (proton1.Px() * proton2.Py()) - (proton1.Py() * proton2.Px());
    normal_plane1.SetXYZ(xp_i, xp_j, xp_k);
    normal_plane2.SetXYZ(0.0,1.0,0.0);
    //use the vector normal to the x-z plane and the vec normal to both protons to find the rotation angle
    //the pi - angle is to get the direction of the vector correct
    double rotation_angle = TMath::Pi() - normal_plane1.Angle(normal_plane2);

    if(printinfo) {
      std::cout << "normal_plane1: X= " << normal_plane1.X() << " Y= " << normal_plane1.Y() << " Z= " << normal_plane1.Z() << std::endl;
      std::cout << "Angle between two planes: " << rotation_angle << std::endl;
    }
    //now rotate the boosted protons about the line of intersection (TVector3) of the two planes by the angle above
    TVector3 rotation_axis;
    //this is the cross product of the two normal vectors, which gives a vector parallel to the line of intersection
    //if you have worked this out on a piece of paper, you might think that this is wrong given that the line of intersection is the z-axis
    //this is technically the correct way to perform such rotations and if you turn printinfo on you will see the rotation_axis is along z-axis
    double xp2_i = -1.0 * normal_plane1.Pz();
    double xp2_j = 0.0;
    double xp2_k = normal_plane1.Px();
    rotation_axis.SetXYZ(xp2_i, xp2_j, xp2_k);

    //perform the rotation by the angle
    //the negative sign is required because we don't rotate our co-ordinate axes but rather the 4-vectors, so that .CosTheta(), .Phi() etc make sense. See note below
    proton1.Rotate(-rotation_angle, rotation_axis);
    proton2.Rotate(-rotation_angle, rotation_axis);
    output_particle.Rotate(-rotation_angle, rotation_axis);
    //muon.Rotate(-rotation_angle, rotation_axis);
    //neutrino.Rotate(-rotation_angle, rotation_axis);
    //NOTE: After this rotation has been performed, we are in the plane spanned by the two protons in the W rest-frame (+W flight dir - see note above)
    //BUT DON'T GET CONFUSED. We have not rotated the measurement axes to lie in the plane of the protons, but rather the protons to lie in our co-ordinate frame
    //This is so when we return the output_vector at the end, things like vector.CosTheta() actually give you the CS CosTheta because we cannot rotate the co-ordinate basis in ROOT
    //A good test that it worked is the proton.Y() values which should be zero.
    //Note that a little bit of algebra can prove that this plane also spans the W flight direction.
    //You can see this by constructing the determinant of the (-W) vector, and the two boosted protons.
    //This evaluates to zero, which means that you can write any vector in terms of the other two (property of determinants), so they must be in the same basis i.e. plane

    if(printinfo) {
      std::cout << "Rotation Axis: X= " << rotation_axis.X() << " Y= " << rotation_axis.Y() << " Z= " << rotation_axis.Z() << std::endl;
      std::cout << "After rotation" << std::endl;
      std::cout << "W boson: Px= " << w.Px() << " Py= " << w.Py() << " Pz= " << w.Pz() << std::endl;
      std::cout << "Proton1: Px= " << proton1.Px() << " Py= " << proton1.Py() << " Pz= " << proton1.Pz() << std::endl;
      std::cout << "Proton2: Px= " << proton2.Px() << " Py= " << proton2.Py() << " Pz= " << proton2.Pz() << std::endl;
      std::cout << "Angle between protons in W-rest frame = " << proton1.Angle(proton2.Vect()) << std::endl;
    }

    //now need to rotate again so that the z-axis bisects (i.e. cuts equally in two) the angle between the proton and the negative proton moving against z-dir originally
    //start by calculating the angle between each vector and the z-axis
    TVector3 zaxis;
    zaxis.SetXYZ(0.0, 0.0, 1.0);
    if(printinfo) {
      std::cout << "Angle between proton1 and z-axis = " << proton1.Angle(zaxis) << std::endl;
      //std::cout << "Angle between proton2 and z-axis = " << proton2.Angle(zaxis) << std::endl;
      std::cout << "Angle between -proton2 and z-axis = " << (-1.0*proton2).Angle(zaxis) << std::endl;
    }

    //then rotate around y, the negative average of the values
    //the reason there is a minus sign is because in general, the z-axis will already be between the two vectors and the Angle() method does not return a sign...
    //Again, DON'T GET CONFUSED. We have not rotated the measurement axes so that z-axis bisects the average direction of the protons, but rather the protons themselves
    //if you do the same things to the output_particle then when you measure the Phi() and CosTheta() you have done it right
    double rotation_angle2 = ((-1.0*proton2).Angle(zaxis) - proton1.Angle(zaxis)) / 2.0;
    proton1.RotateY(-rotation_angle2);
    proton2.RotateY(-rotation_angle2);
    output_particle.RotateY(-rotation_angle2);
    //muon.RotateY(-rotation_angle2);
    //neutrino.RotateY(-rotation_angle2);

    if(printinfo) {
      std::cout << rotation_angle2 << std::endl;
      std::cout << "In Collins-Soper Frame" << std::endl;
      std::cout << "W boson: Px= " << w.Px() << " Py= " << w.Py() << " Pz= " << w.Pz() << std::endl;
      std::cout << "Proton1: Px= " << proton1.Px() << " Py= " << proton1.Py() << " Pz= " << proton1.Pz() << std::endl;
      std::cout << "Proton2: Px= " << proton2.Px() << " Py= " << proton2.Py() << " Pz= " << proton2.Pz() << std::endl;
      std::cout << "Angle between protons = " << proton1.Angle(proton2.Vect()) << std::endl;
      std::cout << "Angle between proton1 and z-axis = " << proton1.Angle(zaxis) << std::endl;
      std::cout << "Angle between -proton2 and z-axis = " << (-1.0*proton2).Angle(zaxis) << std::endl;
      std::cout << "----- End of event -----" << std::endl << std::endl;
    }
    return output_particle;
  }

} // end namespace

