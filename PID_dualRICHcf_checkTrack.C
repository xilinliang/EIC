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

#include <vector>

#else

class ExRootTreeReader;

class ExRootResult;

class Track;
#endif










//------------------------------------------------------------------------------




struct TestPlots

{

    TH1 *h1Pi_purity;

    TH1 *h1K_purity;

    TH1 *h1Pr_purity;
 
    TH1 *h1E_purity;

    TH1 *h1matchTrkE;
    TH1 *h1matchTrkZ;

    TH1 *h1nomatchTrkE;
    TH1 *h1nomatchTrkZ;
    TH1 *h1checknomatchTrkE;
    TH1 *h1checkmatchTrkE;

    TH1 *h1PIDTrkE;
    TH1 *h1JetTrkE;
    TH1 *h1PIDTrkEta;
    TH1 *h1JetTrkEta;

    TH2 *h2Pi_purity_vs_z;
    TH2 *h2Pi_purity_vs_z_E10_20;
    TH2 *h2Pi_purity_vs_z_E20_40;
    TH2 *h2Pi_purity_vs_z_E40_60;
    TH2 *h2Pi_purity_vs_z_E60_80;
    TH2 *h2Pi_purity_vs_E;
    TH1 *h1Pi_matchTrkE;
    TH1 *h1Pi_matchTrkZ;
    TH1 *h1Pi_nomatchTrkE;
    TH1 *h1Pi_notidTrkE;
    TH1 *h1Pi_nomatchTrkZ;
    TH1 *h1Pi_notidTrkZ;
    TH1 *h1Pi_checknomatchTrkE;
    TH1 *h1Pi_checkmatchTrkE;
    TH1 *h1Pi_checknomatchTrkZ;
    TH1 *h1Pi_checkmatchTrkZ;

    TH2 *h2K_purity_vs_z;
    TH2 *h2K_purity_vs_z_E10_20;
    TH2 *h2K_purity_vs_z_E20_40;
    TH2 *h2K_purity_vs_z_E40_60;
    TH2 *h2K_purity_vs_z_E60_80;
    TH2 *h2K_purity_vs_E;
    TH1 *h1K_matchTrkE;
    TH1 *h1K_matchTrkZ;
    TH1 *h1K_nomatchTrkE;
    TH1 *h1K_nomatchTrkZ;
    TH1 *h1K_notidTrkE;
    TH1 *h1K_notidTrkZ;
    TH1 *h1K_checknomatchTrkE;
    TH1 *h1K_checkmatchTrkE;
    TH1 *h1K_checknomatchTrkZ;
    TH1 *h1K_checkmatchTrkZ;

    TH2 *h2Pr_purity_vs_z;
    TH2 *h2Pr_purity_vs_z_E10_20;
    TH2 *h2Pr_purity_vs_z_E20_40;
    TH2 *h2Pr_purity_vs_z_E40_60;
    TH2 *h2Pr_purity_vs_z_E60_80;
    TH2 *h2Pr_purity_vs_E;
    TH1 *h1Pr_matchTrkE;
    TH1 *h1Pr_matchTrkZ;
    TH1 *h1Pr_nomatchTrkE;
    TH1 *h1Pr_nomatchTrkZ;
    TH1 *h1Pr_notidTrkE;
    TH1 *h1Pr_notidTrkZ;
    TH1 *h1Pr_checknomatchTrkE;
    TH1 *h1Pr_checkmatchTrkE;
    TH1 *h1Pr_checknomatchTrkZ;
    TH1 *h1Pr_checkmatchTrkZ;

    TH2 *h2E_purity_vs_z;
    TH2 *h2E_purity_vs_z_E10_20;
    TH2 *h2E_purity_vs_z_E20_40;
    TH2 *h2E_purity_vs_z_E40_60;
    TH2 *h2E_purity_vs_z_E60_80;
    TH2 *h2E_purity_vs_E;
    TH1 *h1E_matchTrkE;
    TH1 *h1E_matchTrkZ;
    TH1 *h1E_nomatchTrkE;
    TH1 *h1E_nomatchTrkZ;


};




//------------------------------------------------------------------------------




void BookHistograms(ExRootResult *result, TestPlots *plots)

{

  TLegend *legend;

  TPaveText *comment;

  plots->h1PIDTrkE = result->AddHist1D("h1PIDTrkE","all PID track E","E [GeV]","events",100,10,60);
  plots->h1JetTrkE = result->AddHist1D("h1JetTrkE","all track in PID coverage E","E [GeV]","events",100,10,60);

  plots->h1PIDTrkEta = result->AddHist1D("h1PIDTrkEta","all PID track Eta","Eta","events",50,1,3.5);
  plots->h1JetTrkEta = result->AddHist1D("h1JetTrkEta","all track in PID coverage Eta","Eta","events",50,1,3.5);

  plots->h1matchTrkZ = result->AddHist1D("h1matchTrkZ","match track fraction z","z","events",20,0,1);
  plots->h1matchTrkE = result->AddHist1D("h1matchTrkE","match track energy","E [GeV]","events",100,10,80);

  plots->h1nomatchTrkZ = result->AddHist1D("h1nomatchTrkZ","no match track fraction z","z","events",20,0,1);
  plots->h1nomatchTrkE = result->AddHist1D("h1nomatchTrkE","no match track energy","E [GeV]","events",100,10,80);

  plots->h1checknomatchTrkE = result->AddHist1D("h1checknomatchTrkE","no match EFlow track energy","E [GeV]","events",100,12.,60.);
  plots->h1checkmatchTrkE = result->AddHist1D("h1checkmatchTrkE","match EFlow track energy","E [GeV]","events",100,12.,60.);

  plots->h1Pi_purity = result->AddHist1D("h1Pi_purity","Pion purity" , "pion purity" , "events" , 20,0,1.01);
  plots->h2Pi_purity_vs_z = result->AddHist2D("h2Pi_purity_vs_z","Pion purity vs z" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E10_20 = result->AddHist2D("h2Pi_purity_vs_z_E10_20","Pion purity vs z (10 < E < 20 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E20_40 = result->AddHist2D("h2Pi_purity_vs_z_E20_40","Pion purity vs z (20 < E < 40 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E40_60 = result->AddHist2D("h2Pi_purity_vs_z_E40_60","Pion purity vs z (40 < E < 60 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E60_80 = result->AddHist2D("h2Pi_purity_vs_z_E60_80","Pion purity vs z (60 < E < 80 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_E = result->AddHist2D("h2Pi_purity_vs_E","Pion purity vs jet E","jet E [GeV]","pion purity",80,10,90,20,0,1.01);
  plots->h1Pi_matchTrkZ = result->AddHist1D("h1Pi_matchTrkZ","match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_matchTrkE = result->AddHist1D("h1Pi_matchTrkE","match Pion track energy","E [GeV]","events",100,10.,60.);
  plots->h1Pi_nomatchTrkZ = result->AddHist1D("h1Pi_nomatchTrkZ","no match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_notidTrkZ = result->AddHist1D("h1Pi_notidTrkZ","misidentify Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_nomatchTrkE = result->AddHist1D("h1Pi_nomatchTrkE","no match Pion track energy","E [GeV]","events",100,10.,60.);
  plots->h1Pi_notidTrkE = result->AddHist1D("h1Pi_notidTrkE","misidentify Pion track energy","E [GeV]","events",100,10.,60.);
  plots->h1Pi_checkmatchTrkE = result->AddHist1D("h1Pi_checkmatchTrkE","match Pion track energy ","E [GeV]","events",100,12.,50.);
  plots->h1Pi_checknomatchTrkE = result->AddHist1D("h1Pi_checknomatchTrkE","no match Pion track energy","E [GeV]","events",100,12.,50.);
  plots->h1Pi_checkmatchTrkZ = result->AddHist1D("h1Pi_checkmatchTrkZ","match Pion track energy fraction z","z","events",20,0,1.);
  plots->h1Pi_checknomatchTrkZ = result->AddHist1D("h1Pi_checknomatchTrkZ","no match Pion track energy fraction z","z","events",20,0,1.);


  plots->h1K_purity = result->AddHist1D("h1K_purity","Kaon purity" , "kaon purity" , "events" , 20,0,1.01);
  plots->h2K_purity_vs_z = result->AddHist2D("h2K_purity_vs_z","Kaon purity vs z" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E10_20 = result->AddHist2D("h2K_purity_vs_z_E10_20","Kaon purity vs z (10 < E < 20 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E20_40 = result->AddHist2D("h2K_purity_vs_z_E20_40","Kaon purity vs z (20 < E < 40 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E40_60 = result->AddHist2D("h2K_purity_vs_z_E40_60","Kaon purity vs z (40 < E < 60 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E60_80 = result->AddHist2D("h2K_purity_vs_z_E60_80","Kaon purity vs z (60 < E < 80 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_E = result->AddHist2D("h2K_purity_vs_E","Kaon purity vs jet E","jet E [GeV]","Kaon purity",80,10,90,20,0,1.01);
  plots->h1K_matchTrkZ = result->AddHist1D("h1K_matchTrkZ","match Kaon track fraction z","z","events",20,0,1.);
  plots->h1K_matchTrkE = result->AddHist1D("h1K_matchTrkE","match Kaon track energy","E [GeV]","events",100,10.,60.);
  plots->h1K_nomatchTrkZ = result->AddHist1D("h1K_nomatchTrkZ","no match Kaon track fraction z","z","events",20,0,1.);
  plots->h1K_nomatchTrkE = result->AddHist1D("h1K_nomatchTrkE","no match Kaon track energy","E [GeV]","events",100,10.,60.);
  plots->h1K_notidTrkZ = result->AddHist1D("h1K_notidTrkZ","misidentify Kaon track fraction z","z","events",20,0,1.);
  plots->h1K_notidTrkE = result->AddHist1D("h1K_notidTrkE","misidentify Kaon track energy","E [GeV]","events",100,10.,60.);
  plots->h1K_checkmatchTrkE = result->AddHist1D("h1K_checkmatchTrkE","match Kaon track energy ","E [GeV]","events",100,12.,50.);
  plots->h1K_checknomatchTrkE = result->AddHist1D("h1K_checknomatchTrkE","no Kaon track energy ","E [GeV]","events",100,12.,50.);
  plots->h1K_checkmatchTrkZ = result->AddHist1D("h1K_checkmatchTrkZ","match Kaon track energy fraction z","z","events",20,0,1.);
  plots->h1K_checknomatchTrkZ = result->AddHist1D("h1K_checknomatchTrkZ","no match Kaon track energy fraction z","z","events",20,0,1.);


  plots->h1Pr_purity = result->AddHist1D("h1Pr_purity","Proton purity" , "proton purity" , "events" , 20,0,1.01);
  plots->h2Pr_purity_vs_z = result->AddHist2D("h2Pr_purity_vs_z","(anti)proton purity vs z" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E10_20 = result->AddHist2D("h2Pr_purity_vs_z_E10_20","(anti)proton purity vs z (10 < E < 20 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E20_40 = result->AddHist2D("h2Pr_purity_vs_z_E20_40","(anti)proton purity vs z (20 < E < 40 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E40_60 = result->AddHist2D("h2Pr_purity_vs_z_E40_60","(anti)proton purity vs z (40 < E < 60 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E60_80 = result->AddHist2D("h2Pr_purity_vs_z_E60_80","(anti)proton purity vs z (60 < E < 80 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_E = result->AddHist2D("h2Pr_purity_vs_E","Proton purity vs jet E","jet E [GeV]","proton purity",80,10,90,20,0,1.01);
  plots->h1Pr_matchTrkZ = result->AddHist1D("h1Pr_matchTrkZ","match Proton track fraction z","z","events",20,0,1);
  plots->h1Pr_matchTrkE = result->AddHist1D("h1Pr_matchTrkE","match Proton track energy","E [GeV]","events",100,10.,60.);
  plots->h1Pr_nomatchTrkZ = result->AddHist1D("h1Pr_nomatchTrkZ","no match Proton track fraction z","z","events",20,0,1);
  plots->h1Pr_nomatchTrkE = result->AddHist1D("h1Pr_nomatchTrkE","no match Proton track energy","E [GeV]","events",100,10.,60.);
  plots->h1Pr_notidTrkZ = result->AddHist1D("h1Pr_notidTrkZ","misidentify proton track fraction z","z","events",20,0,1.);
  plots->h1Pr_notidTrkE = result->AddHist1D("h1Pr_notidTrkE","misidentify proton track energy","E [GeV]","events",100,10.,60.);
  plots->h1Pr_checkmatchTrkE = result->AddHist1D("h1Pr_checkmatchTrkE","match Proton track energy ","E [GeV]","events",100,12.,50.);
  plots->h1Pr_checknomatchTrkE = result->AddHist1D("h1Pr_checknomatchTrkE","no match Proton track energy ","E [GeV]","events",100,12.,50.);
  plots->h1Pr_checkmatchTrkZ = result->AddHist1D("h1Pr_checkmatchTrkZ","match Proton track energy fraction z","z","events",20,0,1);
  plots->h1Pr_checknomatchTrkZ = result->AddHist1D("h1Pr_checknomatchTrkZ","no match Proton track energy fraction z","z","events",20,0,1);




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

  TClonesArray *branchdualRICHcfTrack = treeReader->UseBranch("dualRICHcfTrack"); 

  Long64_t allEntries = treeReader->GetEntries();




  cout << "** Chain contains " << allEntries << " events" << endl;




  GenParticle *particle;

  Electron *electron;

  Track *PIDTrack;
  
  Track *EFlowTrack;
 

  Track *track;

  Tower *tower;




  Jet *jet;

  Jet *genjet;

  Jet *matchedjet;

  TObject *object;




  TLorentzVector momentum, InPr , InE, OutE, EFlowTrackP4;




  Float_t Eem, Ehad;

  Bool_t skip;




  Long64_t entry;




  Int_t i, j, pdgCode;

	
  Int_t nPi_PID , nPi_true , nK_PID , nK_true , nPr_PID , nPr_true, nE_PID , nE_true;

  Int_t Pi_PID[30] ,Pi_true[30] , K_PID[30] , K_true[30] , Pr_PID[30] , Pr_true[30] , E_PID[30] , E_true[30];

  Int_t matchPi_PID , matchPr_PID , matchK_PID ,matchE_PID ;
  Double_t Pi_purity, Pr_purity, K_purity, E_purity;
  Double_t EFlowTrackZ;

  // Loop over all events




  TF1 *f1 = new TF1("f1","1+0.05*sin(x)",-TMath::Pi(),TMath::Pi());
 
  int njets = 0;
  int PIDnum = 0;


  for(entry = 0; entry < allEntries; ++entry)
//    for(entry = 0; entry < 5; ++entry)
  {

    // Load selected branches with data from specified event

    treeReader->ReadEntry(entry);

    nPi_PID=0 ; 
    nPi_true=0; 
    nK_PID=0 ;
    nK_true=0 ;
    nPr_PID=0; 
    nPr_true=0; 
    nE_PID=0; 
    nE_true=0;

    if (! branchParticle) continue;
    particle = (GenParticle*)branchParticle->At(0);
    InPr = particle->P4();
    particle = (GenParticle*)branchParticle->At(3);
    InE = particle->P4();
    particle = (GenParticle*)branchParticle->At(5);
    OutE = particle->P4();

    if (!branchdualRICHcfTrack) continue;
 
   //loop for all Hcal tracks
    for (int i = 0; i < branchEFlowTrack->GetEntries(); ++i) {
      EFlowTrack = (Track*)branchEFlowTrack->At(i);

      if (EFlowTrack->P < 12 || TMath::Abs(EFlowTrack->Eta) < 1.0  || TMath::Abs(EFlowTrack->Eta) > 3.5) continue;
      if(!(abs(EFlowTrack->PID)==211 || abs(EFlowTrack->PID)==321 || abs(EFlowTrack->PID)==2212 )) continue; //if not a charged pion or kaon or proton or e, continue


	int j=0; int checkmatch=0;
	while (j < branchdualRICHcfTrack->GetEntries() && checkmatch == 0)
		{

			dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(j);

			if (EFlowTrack->Particle.GetObject() == dualRICHcfTrack->Particle.GetObject()) {checkmatch = 1;}
			j=j+1;
		

		}
		
	if (checkmatch == 0) h1checknomatchTrkE->Fill(EFlowTrack->P4().E());
	if (checkmatch == 1) h1checkmatchTrkE->Fill(EFlowTrack->P4().E());

	PIDnum = EFlowTrack->PID;


	PIDnum = TMath::Abs(PIDnum);

	switch(PIDnum)
	{

		case 211 :
			Pi_true[nPi_true] = i ;
			nPi_true = nPi_true +1;
		break;

		case 321 :
                        K_true[nK_true] = i ;
                        nK_true = nK_true +1;
                break;

		case 2212 :
                        Pr_true[nPr_true] = i ;
                        nPr_true = nPr_true +1;
                break;

		case 11 :
                        E_true[nE_true] = i ;
                        nE_true = nE_true +1;
                break;

	}

    }

    //loop for all PID system tracks
    for (int i = 0; i < branchdualRICHcfTrack->GetEntries(); ++i) {
      dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(i);

      if (dualRICHcfTrack->P < 12 || TMath::Abs(dualRICHcfTrack->Eta) < 1.0  || TMath::Abs(dualRICHcfTrack->Eta) > 3.5) continue;

	PIDnum = dualRICHcfTrack->PID;

	PIDnum = TMath::Abs(PIDnum);


	switch(PIDnum)
	{

		case 211 :
			Pi_PID[nPi_PID] = i ;
			nPi_PID = nPi_PID +1;
		break;

		case 321 :
                        K_PID[nK_PID] = i ;
                        nK_PID = nK_PID +1;
                break;

		case 2212 :
                        Pr_PID[nPr_PID] = i ;
                        nPr_PID = nPr_PID +1;
                break;

		case 11 :
                        E_PID[nE_PID] = i ;
                        nE_PID = nE_PID +1;
                break;

	}



    }
    
    matchPi_PID = 0;
    for (int i=0; i< nPi_true; ++i)
    {

	int j=0; int checkmatch=0;
	EFlowTrack = (Track*)branchEFlowTrack->At(Pi_true[i]);
	EFlowTrackP4 = EFlowTrack->P4();
	EFlowTrackZ = (InPr.Dot(EFlowTrackP4)) / (InPr.Dot(InE - OutE));
	while (checkmatch == 0 && j<nPi_PID)
	{

		dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(Pi_PID[j]);
		if (EFlowTrack->Particle.GetObject() == dualRICHcfTrack->Particle.GetObject()) {checkmatch = 1;}
		j=j+1;		

	}
	//cout<<"check Pion match:"<<checkmatch<<endl;
	if (checkmatch == 0) { h1Pi_checknomatchTrkZ->Fill(EFlowTrackZ); h1Pi_checknomatchTrkE->Fill(EFlowTrack->P4().E());}
	if (checkmatch == 1) {h1Pi_checkmatchTrkZ->Fill(EFlowTrackZ); h1Pi_checkmatchTrkE->Fill(EFlowTrack->P4().E());}

    }

    matchK_PID = 0;
    for (int i=0; i< nK_true; ++i)
    {

	int j=0; int checkmatch=0;
	EFlowTrack = (Track*)branchEFlowTrack->At(K_true[i]);
	EFlowTrackP4 = EFlowTrack->P4();
	EFlowTrackZ = (InPr.Dot(EFlowTrackP4)) / (InPr.Dot(InE - OutE));
	while (checkmatch == 0 && j<nK_PID)
	{

		dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(K_PID[j]);
		if (EFlowTrack->Particle.GetObject() == dualRICHcfTrack->Particle.GetObject()) {checkmatch = 1;}
		j=j+1;		

	}
	//cout<<"check Kaon match:"<<checkmatch<<endl;
	//cout<<"EFlow track z:"<<EFlowTrackZ<<endl;
	if (checkmatch == 0) { h1K_checknomatchTrkZ->Fill(EFlowTrackZ); h1K_checknomatchTrkE->Fill(EFlowTrack->P4().E());}
	if (checkmatch == 1) {h1K_checkmatchTrkZ->Fill(EFlowTrackZ); h1K_checkmatchTrkE->Fill(EFlowTrack->P4().E());}

    }

	
    matchPr_PID = 0;
    for (int i=0; i< nPr_true; ++i)
    {

	int j=0; int checkmatch=0;
	EFlowTrack = (Track*)branchEFlowTrack->At(Pr_true[i]);
	EFlowTrackP4 = EFlowTrack->P4();
	EFlowTrackZ = (InPr.Dot(EFlowTrackP4)) / (InPr.Dot(InE - OutE));
	while (checkmatch == 0 && j<nPr_PID)
	{

		dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(Pr_PID[j]);
		if (EFlowTrack->Particle.GetObject() == dualRICHcfTrack->Particle.GetObject()) {checkmatch = 1;}
		j=j+1;		

	}
	if (checkmatch == 0) { h1Pr_checknomatchTrkZ->Fill(EFlowTrackZ); h1Pr_checknomatchTrkE->Fill(EFlowTrack->P4().E());}
	if (checkmatch == 1) {h1Pr_checkmatchTrkZ->Fill(EFlowTrackZ); h1Pr_checkmatchTrkE->Fill(EFlowTrack->P4().E());}

    }


    //loop for all PID system tracks

    if (!branchdualRICHcfTrack) continue;
    for (int i = 0; i < branchdualRICHcfTrack->GetEntries(); ++i) {
      dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(i);

      //if (dualRICHcfTrack->PT < 0.1 || TMath::Abs(dualRICHcfTrack->Eta) > 3.5) continue;

	PIDnum = dualRICHcfTrack->PID;

	PIDnum = TMath::Abs(PIDnum);

	//cout<<"LINE = "<<__LINE__<<endl;	
	h1PIDTrkE->Fill(dualRICHcfTrack->P4().E());
	h1PIDTrkEta->Fill(dualRICHcfTrack->P4().Eta());

	switch(PIDnum)
	{

		case 211 :
			Pi_PID[nPi_PID] = i ;
			nPi_PID = nPi_PID +1;
		break;

		case 321 :
                        K_PID[nK_PID] = i ;
                        nK_PID = nK_PID +1;
                break;

		case 2212 :
                        Pr_PID[nPr_PID] = i ;
                        nPr_PID = nPr_PID +1;
                break;

		case 11 :
                        E_PID[nE_PID] = i ;
                        nE_PID = nE_PID +1;
                break;

	}
	
//	cout<< "PID num PID " << PIDnum << endl;

    }

  }

}




//------------------------------------------------------------------------------




void PrintHistograms(ExRootResult *result, TestPlots *plots)

{

  result->Print("root");

}




//------------------------------------------------------------------------------




void PID_dualRICHcf_checkTrack(const char *inputFile)

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

