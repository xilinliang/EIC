/*

This macro shows how to access the particle-level reference for reconstructed objects.

It is also shown how to loop over the jet constituents.



root -l examples/Example3.C'("delphes_output.root")'

*/




#ifdef __CLING__

R__LOAD_LIBRARY(libDelphes)

#include "classes/DelphesClasses.h"

#include "external/ExRootAnalysis/ExRootTreeReader.h"

#include "external/ExRootAnalysis/ExRootResult.h"

#else

class ExRootTreeReader;

class ExRootResult;

#endif










//------------------------------------------------------------------------------




struct TestPlots

{

  TH1 *fElectronDeltaPT;

  TH1 *fElectronDeltaEta;

  TH1 *fJetDeltaPT;

  TH1 *hjt;

  TH1 *hphi;

  TH1 *hz;

  TH1 *hr;




  TH1 *asym;

  TH1 *asym_smeared;

  

  TH1 *res_dphi_04_06;

  TH1 *res_dphi_01_02;  

  TH2 *res_dphi_z_10_20;

  TH2 *res_dphi_z_20_40;

  TH2 *res_dphi_z_40_60;

  TH2 *res_dphi_z_60_80;

  TH1 *res_dphi_diffz_10_20[16];

  TH1 *res_dphi_diffz_20_30[16];

  TH1 *res_dphi_diffz_30_40[16];

  TH1 *res_dphi_diffz_40_50[16];

  TH1 *res_dphi_diffz_50_60[16];

  TH1 *res_dphi_diffz_60_70[16];

  TH1 *res_dphi_diffz_70_80[16];

  TH1 *res_dz_diffphi_10_20[16];

  TH1 *res_dz_diffphi_20_30[16];

  TH1 *res_dz_diffphi_30_40[16];
 
  TH1 *res_dz_diffphi_40_50[16];

  TH1 *res_dz_diffphi_50_60[16];

  TH1 *res_dz_diffphi_60_70[16];

  TH1 *res_dz_diffphi_70_80[16];

  TH2 *h2_trackresolution_vs_p;

  TH1 *mom_res;

  TH2 *h2_trackresolution_vs_p_S;

  TH1 *mom_res_S;

};




//------------------------------------------------------------------------------




void BookHistograms(ExRootResult *result, TestPlots *plots)

{

  TLegend *legend;

  TPaveText *comment;




  plots->fElectronDeltaPT = result->AddHist1D(

    "electron_delta_pt", "(p_{T}^{particle} - p_{T}^{electron})/p_{T}^{particle}",

    "(p_{T}^{particle} - p_{T}^{electron})/p_{T}^{particle}", "number of electrons",

    100, -0.1, 0.1);




  plots->fElectronDeltaEta = result->AddHist1D(

    "electron_delta_eta", "(#eta^{particle} - #eta^{electron})/#eta^{particle}",

    "(#eta^{particle} - #eta^{electron})/#eta^{particle}", "number of electrons",

    100, -0.1, 0.1);




  plots->fJetDeltaPT = result->AddHist1D(

    "jet_delta_pt", "(p_{T}^{jet} - p_{T}^{constituents})/p_{T}^{jet}",

    "(p_{T}^{jet} - p_{T}^{constituents})/p_{T}^{jet}", "number of jets",

    100, -1.0e-1, 1.0e-1);







  plots->hjt  = result->AddHist1D("jt", "", "jt " , "entries",50,0,3.0);

  plots->hz   = result->AddHist1D("z", ""," z " , "entries",50,0,1.0);

  plots->hphi = result->AddHist1D("phi", "", "phi " , "entries",180,-6.0,9.0);

  plots->hr   = result->AddHist1D("r", "" , "z", "entries", 50, 0,1.0);

  plots->asym = result->AddHist1D("asym", "Generated asymmetry", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries" , 13,-TMath::Pi(),TMath::Pi());

  plots->asym_smeared = result->AddHist1D("asym_smeared", "Reconstructed asymmetry", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries",  13,-TMath::Pi(),TMath::Pi());

  

  double mindphi = TMath::Pi()/2.0;

  plots->res_dphi_04_06 = result->AddHist1D("dphi_res_04_06", "Collins Angle resolution, 40 < E_{jet} < 60 GeV and 0.4<z<0.6", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries", 100,-TMath::Pi(),TMath::Pi());

  plots->res_dphi_01_02 = result->AddHist1D("dphi_res_01_02", "Collins Angle resolution, 40 < E_{jet} < 60 GeV and 0.1<z<0.2", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries", 100,-TMath::Pi(),TMath::Pi());

  

  plots->res_dphi_z_10_20 = result->AddHist2D("dphi_res_z_10_20", "Collins Angle resolution, 10 <E_{jet}< 20 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51, -mindphi,mindphi, 10,0.0,1.0);

  plots->res_dphi_z_20_40 = result->AddHist2D("dphi_res_z_20_40", "Collins Angle resolution, 20 <E_{jet}< 40 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51,-mindphi, mindphi, 10,0.0,1.0); 

  plots->res_dphi_z_40_60 = result->AddHist2D("dphi_res_z_40_60", "Collins Angle resolution, 40 <E_{jet}< 60 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51, -mindphi, mindphi, 10,0.0,1.0); 

  plots->res_dphi_z_60_80 = result->AddHist2D("dphi_res_z_60_80", "Collins Angle resolution, 60 <E_{jet}< 80 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51, -mindphi, mindphi, 10,0.0,1.0); 

  plots->h2_trackresolution_vs_p = result->AddHist2D("h2_trackresolution_vs_p","hadron resolution vs gen hadron p","p_{gen hadron} [GeV]","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]",80,0,80,80,-2,2);

  plots->mom_res = result->AddHist1D("mom_res","momentum resolution","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]","",80,-2,2);

plots->h2_trackresolution_vs_p_S = result->AddHist2D("h2_trackresolution_vs_p_S","hadron resolution vs gen hadron p","p_{gen hadron} [GeV]","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]",50,0,20,60,-0.5,0.5);

  plots->mom_res_S = result->AddHist1D("mom_res_S","momentum resolution","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]","",60,-0.5,0.5);


  char name_hist[100];
  char title_hist[100];
  for (int i=0;i<16;i=i+1)
  {

	sprintf(name_hist,"dphi_z_%i_%i_1020",i*8,(i+1)*8);
	plots->res_dphi_diffz_10_20[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
	sprintf(name_hist,"dphi_z_%i_%i_2030",i*8,(i+1)*8);
        plots->res_dphi_diffz_20_30[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
	sprintf(name_hist,"dphi_z_%i_%i_3040",i*8,(i+1)*8);
        plots->res_dphi_diffz_30_40[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
	sprintf(name_hist,"dphi_z_%i_%i_4050",i*8,(i+1)*8);
        plots->res_dphi_diffz_40_50[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
	sprintf(name_hist,"dphi_z_%i_%i_5060",i*8,(i+1)*8);
        plots->res_dphi_diffz_50_60[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
	sprintf(name_hist,"dphi_z_%i_%i_6070",i*8,(i+1)*8);
        plots->res_dphi_diffz_60_70[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
	sprintf(name_hist,"dphi_z_%i_%i_7080",i*8,(i+1)*8);
        plots->res_dphi_diffz_70_80[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());


	sprintf(title_hist,"dz_phi_%i_1020",i);
	sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_1020",i-8,(i-7));
        plots->res_dz_diffphi_10_20[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
	sprintf(title_hist,"dz_phi_%i_2030",i);
        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_2030",i-8,(i-7));
        plots->res_dz_diffphi_20_30[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
	sprintf(title_hist,"dz_phi_%i_3040",i);
        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_3040",i-8,(i-7));
        plots->res_dz_diffphi_30_40[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
	sprintf(title_hist,"dz_phi_%i_4050",i);
        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_4050",i-8,(i-7));
        plots->res_dz_diffphi_40_50[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
	sprintf(title_hist,"dz_phi_%i_5060",i);
        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_5060",i-8,(i-7));
        plots->res_dz_diffphi_50_60[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
	sprintf(title_hist,"dz_phi_%i_6070",i);
        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_6070",i-8,(i-7));
        plots->res_dz_diffphi_60_70[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
	sprintf(title_hist,"dz_phi_%i_7080",i);
        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_7080",i-8,(i-7));
        plots->res_dz_diffphi_70_80[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);


  }

}

//------------------------------------------------------------------------------




void AnalyseEvents(ExRootTreeReader *treeReader, TestPlots *plots)

{

  cout<<"check 1"<<endl;

  TClonesArray *branchParticle = treeReader->UseBranch("Particle");

  TClonesArray *branchElectron = treeReader->UseBranch("Electron");

  TClonesArray *branchEFlowTrack = treeReader->UseBranch("EFlowTrack");

  TClonesArray *branchEFlowPhoton = treeReader->UseBranch("EFlowPhoton");

  TClonesArray *branchEFlowNeutralHadron = treeReader->UseBranch("EFlowNeutralHadron");

  TClonesArray *branchJet = treeReader->UseBranch("Jet");

  TClonesArray *branchGenJet = treeReader->UseBranch("GenJet");



  Long64_t allEntries = treeReader->GetEntries();




  cout << "** Chain contains " << allEntries << " events" << endl;




  GenParticle *particle;

  Electron *electron;




  Track *track;

  Tower *tower;




  Jet *jet;

  Jet *genjet;

  Jet *matchedjet;

  TObject *object;




  TLorentzVector momentum;




  Float_t Eem, Ehad;

  Bool_t skip;




  Long64_t entry;




  Int_t i, j, pdgCode;




  // Loop over all events




  TF1 *f1 = new TF1("f1","1+0.05*sin(x)",-TMath::Pi(),TMath::Pi());
 
  int njets = 0;

//  char name_hist[100];
//  int i=1;
//  sprintf(name_hist,"dphi_z_%i_%i_E_10_20",i*5,(i+1)*5);
//  cout<<name_hist<<endl;

  for(entry = 0; entry < allEntries; ++entry)
//    for(entry = 0; entry < 100; ++entry)
  {

    // Load selected branches with data from specified event

    treeReader->ReadEntry(entry);




    // Loop over all electrons in event

    for(i = 0; i < branchElectron->GetEntriesFast(); ++i)

    {

      electron = (Electron*) branchElectron->At(i);

      particle = (GenParticle*) electron->Particle.GetObject();




      plots->fElectronDeltaPT->Fill((particle->PT - electron->PT)/particle->PT);

      plots->fElectronDeltaEta->Fill((particle->Eta - electron->Eta)/particle->Eta);

    }


    // Loop over all photons in event

    cout<<"check 2"<<endl;


    // Loop over all jets in event

    for(int i = 0; i < branchJet->GetEntriesFast(); ++i)

    {
	cout<<"check 3"<<endl;

      jet = (Jet*) branchJet->At(i);

      if(jet->PT<10.0) continue;


      float deltaR = 999;


      //auto jetMomentum = jet->P4();

      TLorentzVector jetMomentum = jet->P4();

      deltaR = 999;

      int matched_index = -999;

      for(j = 0; j < branchGenJet->GetEntriesFast(); j++)

	{

	  genjet = (Jet*) branchGenJet->At(j);

	  TLorentzVector genJetMomentum = genjet->P4();


 	  // this is simply to avoid warnings from initial state particle

	  // having infite rapidity ...

	  if(genJetMomentum.Px() == 0 && genJetMomentum.Py() == 0) continue;



	  // take the closest parton candidate

	  if(genJetMomentum.DeltaR(jetMomentum) < deltaR)

	    {

	      deltaR = genJetMomentum.DeltaR(jetMomentum);

	    //  auto matchedJetMomentum = genJetMomentum;

	      matched_index = j;

	    }

	}

          

      if(deltaR>0.3) continue;

      //cout << deltaR << endl;

      genjet = (Jet*) branchGenJet->At(matched_index); 

      // genjet = bestGenJetMomentum #branchGenJet.At(0)



      

      momentum.SetPxPyPzE(0.0, 0.0, 0.0, 0.0);




      // cout<<"Looping over jet constituents. Jet pt: "<<jet->PT<<", eta: "<<jet->Eta<<", phi: "<<jet->Phi<<endl;




      // Loop over all jet's constituents

      for(j = 0; j < jet->Constituents.GetEntriesFast(); ++j)

      {

        object = jet->Constituents.At(j);

        // Check if the constituent is accessible

        if(object == 0) continue;

        if(object->IsA() == Track::Class())

        {

          track = (Track*) object;

	  if(track->PT<0.100) continue;  // if track has less than 200 MeV, then do not consider it

          //cout << "    Track pt: " << track->PT << ", eta: " << track->Eta << ", phi: " << track->Phi << endl;

          momentum += track->P4();

	  if(abs(track->PID)!=211) continue; //if not a charged pion, continue

	  double pxh, pyh, pzh, cross;

         

	  pxh = track->P4().Px();

	  pyh = track->P4().Py();

	  pzh = track->P4().Pz();

          double ptrack = TMath::Sqrt(pxh*pxh + pyh*pyh + pzh*pzh);

	  

	  double pxj, pyj, pzj;

          pxj = jet->P4().Px();

	  pyj = jet->P4().Py();

	  pzj = jet->P4().Pz();

          double p = TMath::Sqrt(pxj*pxj + pyj*pyj + pzj*pzj);




	  //cout << jet->P4().Vect().Mag() << endl;

	  //cout << track->P4().Vect().Mag() << endl;

	  

	  //cout << " " << endl;

	  TVector3 crossproduct = jet->P4().Vect().Unit().Cross(track->P4().Vect().Unit());

          //cout << "Cross product " << crossproduct.Mag() << endl;

	  //cout << "angle " << TMath::ASin(crossproduct.Mag()) << endl;  

	  

	  double sin = crossproduct.Mag()/(jet->P4().Vect().Mag());

	    

	  double z = jet->P4().Vect().Dot( track->P4().Vect() )/(jet->P4().P()*jet->P4().P());

          //if( !(z>0.4 and z<0.6)) continue;

	  

          double r = TMath::Sqrt( pow(jet->P4().Phi() - track->P4().Phi(),2.0) + pow(jet->P4().Eta() - track->P4().Eta(),2.0));

	  TVector3 zaxis(0,0,1);

          TVector3 N = zaxis.Cross(jet->P4().Vect());

	  TVector3 S = N.Cross(jet->P4().Vect());

	  N = N.Unit();

	  S = S.Unit();

	  TVector3 jt  = track->P4().Vect().Dot(N)*N + track->P4().Vect().Dot(S)*S;

          double angle = track->P4().Vect().Dot(N)/track->P4().Vect().Dot(S);	  

          double phi_h = TMath::ATan(angle); 

	  //cout << "asd" << jt.Unit().Dot(jet->P4().Vect()) << endl;

	  //double phi_h = TMath::ACos(jt.Unit().Dot(N.Unit()));

	  //std::cout << jet->P4().Vect().Cross(  track->P4().Vect() ) / (ptrack*p)  << endl;

          //double phi_h = TMath::ASin(jet->P4().Vect().Cross(  track->P4().Vect() ) / (ptrack*p));

          //cout<< sin << endl;

	    // double phi_h =crossproduct.Mag();// TMath::ASin(sin);

	  

	  plots->hphi->Fill(phi_h);

	  plots->hz->Fill(z);

	  plots->hjt->Fill(jt.Mag());

	  plots->hr->Fill(r);     


          //track truth

	  auto gentrack = (GenParticle*) track->Particle.GetObject();

	  genpxh = gentrack->P4().Px();

          genpyh = gentrack->P4().Py();

          genpzh = gentrack->P4().Pz();

          double genptrack = TMath::Sqrt(genpxh*genpxh + genpyh*genpyh + genpzh*genpzh);


          TVector3 gen_crossproduct = genjet->P4().Vect().Cross(gentrack->P4().Vect());

	  double genz = genjet->P4().Vect().Dot( gentrack->P4().Vect() )/(genjet->P4().P()*genjet->P4().P());

	  double dz = genz - z;

	  //if( !(genz>0.4 and genz<0.6)) continue;

	  double genr=0;
//	  genr=TMath::Sqrt(pow(genjet->P4().Phi()-gentrack->P4().Phi(),2.0)+pow(genjet->P4().Eta()-gentrack->P4().Eta(),2.0)); 

	  TVector3 genN = zaxis.Cross(genjet->P4().Vect());

	  TVector3 genS = genN.Cross(genjet->P4().Vect());

	  genN = genN.Unit();

	  genS = genS.Unit();

	  TVector3 genjt  = gentrack->P4().Vect().Dot(genN)*genN + gentrack->P4().Vect().Dot(genS)*genS;

	  double genphi_h = TMath::ATan(gentrack->P4().Vect().Dot(genN)/gentrack->P4().Vect().Dot(genS)); 




          double dphi = TVector2::Phi_mpi_pi(genphi_h-phi_h);

	  if(dphi> TMath::Pi()/2.0){

	    dphi = dphi- TMath::Pi();

	  }

	  else if(dphi<-TMath::Pi()/2.0){

	    dphi = dphi+ TMath::Pi();

	  }

	  h2_trackresolution_vs_p->Fill(genptrack,((genptrack-ptrack)/genptrack)); 

          mom_res->Fill((genptrack-ptrack)/genptrack);

	h2_trackresolution_vs_p_S->Fill(genptrack,((genptrack-ptrack)/genptrack));

          mom_res_S->Fill((genptrack-ptrack)/genptrack);

//	 cout<<"(genjet->P4().E()="<<genjet->P4().E()<<endl;
          


	  if((genjet->P4().E())>10 && (genjet->P4().E())<20){

	      plots->res_dphi_z_10_20->Fill(dphi, genz);
	      
		if ((genz < 0.72) && (genz >0)) 
		{
		  cout<<(floor(genz * 12.5))<<endl;
		  plots->res_dphi_diffz_10_20[floor(genz * 12.5)]->Fill(dphi);
		}

	      cout<<"genphi="<<genphi_h<<"  "<<floor(genphi_h * 8 / TMath::Pi()+8)<<endl;
	      plots->res_dz_diffphi_10_20[floor(genphi_h * 8 / TMath::Pi()+8)]->Fill(dz);

	  }

	  if((genjet->P4().E())>20 && (genjet->P4().E())<40){

	    plots->res_dphi_z_20_40->Fill(dphi, genz);

	    if (genjet->P4().E() < 30) {plots->res_dz_diffphi_20_30[floor(genphi_h * 8 / TMath::Pi() +8)]->Fill(dz);}  
	    else {plots->res_dz_diffphi_30_40[floor(genphi_h * 8 / TMath::Pi()+8)]->Fill(dz);}

	    if (genz < 0.72 && (genz >0))
	    {
		cout<<(floor(genz * 12.5))<<" "<<genjet->P4().E()<<endl;
		if ((genjet->P4().E())>30) {plots->res_dphi_diffz_30_40[floor(genz * 12.5)]->Fill(dphi);
		}
		else {plots->res_dphi_diffz_20_30[floor(genz * 12.5)]->Fill(dphi);}
	    }

	  }

	  if((genjet->P4().E())>40 && (genjet->P4().E())<60){

	    plots->res_dphi_z_40_60->Fill(dphi, genz);

	    if ((genjet->P4().E())<50 && (genz < 0.72) && (genz >0)) {
		cout<<(floor(genz * 12.5))<<endl;
		plots->res_dphi_diffz_40_50[floor(genz * 12.5)]->Fill(dphi);
		plots->res_dz_diffphi_40_50[floor(genphi_h * 8 / TMath::Pi()+8)]->Fill(dz);}
	    else if(genjet->P4().E() < 50) {plots->res_dz_diffphi_40_50[floor(genphi_h * 8 / TMath::Pi() +8)]->Fill(dz);}

	    if ((genjet->P4().E())>50 && (genz < 0.72) && (genz >0)) {
                plots->res_dphi_diffz_50_60[floor(genz * 12.5)]->Fill(dphi);
                plots->res_dz_diffphi_50_60[floor(genphi_h * 8 / TMath::Pi()+8)]->Fill(dz);}
            else if(genjet->P4().E() > 50) {plots->res_dz_diffphi_50_60[floor(genphi_h * 8 / TMath::Pi() +8)]->Fill(dz);}

	    if(genz>0.4 && genz<0.6 ){

	      plots->res_dphi_04_06->Fill(dphi);

	    }

	    else if(genz>0.1 && genz<0.2 ){

	      plots->res_dphi_01_02->Fill(dphi);

	      double x = f1->GetRandom();

	      //cout << x << endl;

	      plots->asym->Fill(x);

	      plots->asym_smeared->Fill(x+dphi);

	    }

	  }

	  if((genjet->P4().E())>60 && (genjet->P4().E())<80){

	    plots->res_dphi_z_60_80->Fill(dphi, genz);                                                                                                                                                 
	    if ((genjet->P4().E())<70 && (genz < 0.72) && (genz >0)) {
                cout<<(floor(genz * 12.5))<<endl;
                plots->res_dphi_diffz_60_70[floor(genz * 12.5)]->Fill(dphi);
                plots->res_dz_diffphi_60_70[floor(genphi_h * 8 / TMath::Pi()+8)]->Fill(dz);}
            else if(genjet->P4().E() < 70) {plots->res_dz_diffphi_60_70[floor(genphi_h * 8 / TMath::Pi() +8)]->Fill(dz);}

            if ((genjet->P4().E())>70 && (genz < 0.72) && (genz >0)) {
                plots->res_dphi_diffz_70_80[floor(genz * 12.5)]->Fill(dphi);
                plots->res_dz_diffphi_70_80[floor(genphi_h * 8 / TMath::Pi()+8)]->Fill(dz);}
            else if(genjet->P4().E() > 70) {plots->res_dz_diffphi_70_80[floor(genphi_h * 8 / TMath::Pi() +8)]->Fill(dz);}


	  }  

	                

	  // cout << "track" << track->P4().Px() <<  " " << particle->P4().Px() <<endl;

          //cout << "jet " << jet->P4().Px() << " " << genjet->P4().Px() << endl; 

	  //cout << " angle " << phi_h << std::endl;

	  //cout << " r " << r << " jt " << jt << " z " << z << " " << jet->P4().P() <<  " " << jet->PT << endl;

        }

        else if(object->IsA() == Tower::Class())

        {

          tower = (Tower*) object;

          //cout << "    Tower pt: " << tower->ET << ", eta: " << tower->Eta << ", phi: " << tower->Phi << endl;

          momentum += tower->P4();

        }

      }




      

      plots->fJetDeltaPT->Fill((jet->PT - momentum.Pt())/jet->PT);

    }

  }

}




//------------------------------------------------------------------------------




void PrintHistograms(ExRootResult *result, TestPlots *plots)

{

  result->Print("root");

}




//------------------------------------------------------------------------------




void Collins2(const char *inputFile)

{

  gSystem->Load("libDelphes");




  TChain *chain = new TChain("Delphes");

  chain->Add(inputFile);




  ExRootTreeReader *treeReader = new ExRootTreeReader(chain);

  ExRootResult *result = new ExRootResult();




  TestPlots *plots = new TestPlots;




  BookHistograms(result, plots);




  AnalyseEvents(treeReader, plots);




  PrintHistograms(result, plots);




  result->Write("results.root");




  cout << "** Exiting..." << endl;




  delete plots;

  delete result;

  delete treeReader;

  delete chain;

}




//------------------------------------------------------------------------------

