/*

This macro shows how to access the particle-level reference for reconstructed objects.

It is also shown how to loop over the jet constituents.



root -l examples/Example3.C'("delphes_output.root")'

*/

//dualRICH_aerogel PID system PID study
//Author: Xilin Liang


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


    TH1 *h1TrackZ;
    TH1 *h1TrackE;
    TH1 *h1dualRICH_aerogel_TrackZ;
    TH1 *h1dualRICH_aerogel_PiTrackZ;
    TH1 *h1dualRICH_aerogel_KTrackZ;
    TH1 *h1dualRICH_aerogel_PrTrackZ;
    TH1 *h1dualRICH_c2f6_TrackZ;
    TH1 *h1dualRICH_c2f6_PiTrackZ;
    TH1 *h1dualRICH_c2f6_KTrackZ;
    TH1 *h1dualRICH_c2f6_PrTrackZ;
    TH1 *h1BarrelTrackZ;
    TH1 *h1BarrelPiTrackZ;
    TH1 *h1BarrelKTrackZ;
    TH1 *h1BarrelPrTrackZ;
    

//    TH1 *h1Pi_purity;
//
//    TH1 *h1K_purity;
//
//    TH1 *h1Pr_purity;
// 
//    TH1 *h1E_purity;
//
//    TH1 *h1matchTrkE;
//    TH1 *h1matchTrkZ;
//
//    TH1 *h1nomatchTrkE;
//    TH1 *h1nomatchTrkZ;
//
//    TH2 *h2Pi_purity_vs_z;
//    TH2 *h2Pi_purity_vs_z_E10_20;
//    TH2 *h2Pi_purity_vs_z_E20_40;
//    TH2 *h2Pi_purity_vs_z_E40_60;
//    TH2 *h2Pi_purity_vs_z_E60_80;
//    TH2 *h2Pi_purity_vs_E;
//    TH1 *h1Pi_matchTrkE;
//    TH1 *h1Pi_matchTrkZ;
//    TH1 *h1Pi_nomatchTrkE;
//    TH1 *h1Pi_nomatchTrkZ;
//
//    TH2 *h2K_purity_vs_z;
//    TH2 *h2K_purity_vs_z_E10_20;
//    TH2 *h2K_purity_vs_z_E20_40;
//    TH2 *h2K_purity_vs_z_E40_60;
//    TH2 *h2K_purity_vs_z_E60_80;
//    TH2 *h2K_purity_vs_E;
//    TH1 *h1K_matchTrkE;
//    TH1 *h1K_matchTrkZ;
//    TH1 *h1K_nomatchTrkE;
//    TH1 *h1K_nomatchTrkZ;
//
//    TH2 *h2Pr_purity_vs_z;
//    TH2 *h2Pr_purity_vs_z_E10_20;
//    TH2 *h2Pr_purity_vs_z_E20_40;
//    TH2 *h2Pr_purity_vs_z_E40_60;
//    TH2 *h2Pr_purity_vs_z_E60_80;
//    TH2 *h2Pr_purity_vs_E;
//    TH1 *h1Pr_matchTrkE;
//    TH1 *h1Pr_matchTrkZ;
//    TH1 *h1Pr_nomatchTrkE;
//    TH1 *h1Pr_nomatchTrkZ;
//
//    TH2 *h2E_purity_vs_z;
//    TH2 *h2E_purity_vs_z_E10_20;
//    TH2 *h2E_purity_vs_z_E20_40;
//    TH2 *h2E_purity_vs_z_E40_60;
//    TH2 *h2E_purity_vs_z_E60_80;
//    TH2 *h2E_purity_vs_E;
//    TH1 *h1E_matchTrkE;
//    TH1 *h1E_matchTrkZ;
//    TH1 *h1E_nomatchTrkE;
//    TH1 *h1E_nomatchTrkZ;

    //TH1 *h1TrackP;


};




//------------------------------------------------------------------------------




void BookHistograms(ExRootResult *result, TestPlots *plots)

{

  TLegend *legend;

  TPaveText *comment;

  plots->h1TrackZ = result->AddHist1D("h1TrackZ","EFlow Track energy fraction z","z","events",20,0.,1.);
  plots->h1TrackE = result->AddHist1D("h1TrackE","EFlow Track energy","E [GeV]","events",100,0,50.);
  plots->h1dualRICH_aerogel_TrackZ = result->AddHist1D("h1dualRICH_aerogel_TrackZ","EFlow Track energy fraction z (dualRICH aerogel)","z","events",20,0.,1.);
  plots->h1dualRICH_c2f6_TrackZ = result->AddHist1D("h1dualRICH_c2f6_TrackZ","EFlow Track energy fraction z (dualRICH c2f6)","z","events",20,0.,1.);
  plots->h1BarrelTrackZ = result->AddHist1D("h1BarrelTrackZ","EFlow Track energy fraction z (barrelDIRC)","z","events",20,0.,1.);
  plots->h1dualRICH_aerogel_PiTrackZ = result->AddHist1D("h1dualRICH_aerogel_PiTrackZ","EFlow Pion Track energy fraction z (dualRICH aerogel)","z","events",20,0.,1.);
  plots->h1dualRICH_aerogel_KTrackZ = result->AddHist1D("h1dualRICH_aerogel_KTrackZ","EFlow Kaon Track energy fraction z (dualRICH aerogel)","z","events",20,0.,1.);
  plots->h1dualRICH_aerogel_PrTrackZ = result->AddHist1D("h1dualRICH_aerogel_PrTrackZ","EFlow Proton Track energy fraction z (dualRICH aerogel)","z","events",20,0.,1.);
  plots->h1dualRICH_c2f6_PiTrackZ = result->AddHist1D("h1dualRICH_c2f6_PiTrackZ","EFlow PionTrack energy fraction z (dualRICH c2f6)","z","events",20,0.,1.);
  plots->h1dualRICH_c2f6_KTrackZ = result->AddHist1D("h1dualRICH_c2f6_KTrackZ","EFlow Kaon Track energy fraction z (dualRICH c2f6)","z","events",20,0.,1.);
  plots->h1dualRICH_c2f6_PrTrackZ = result->AddHist1D("h1dualRICH_c2f6_PrTrackZ","EFlow Proton Track energy fraction z (dualRICH c2f6)","z","events",20,0.,1.);
  plots->h1BarrelPiTrackZ = result->AddHist1D("h1BarrelPiTrackZ","EFlow Pion Track energy fraction z (barrelDIRC)","z","events",20,0.,1.);
  plots->h1BarrelKTrackZ = result->AddHist1D("h1BarrelKTrackZ","EFlow Kaon Track energy fraction z (barrelDIRC)","z","events",20,0.,1.);
  plots->h1BarrelPrTrackZ = result->AddHist1D("h1BarrelPrTrackZ","EFlow Proton Track energy fraction z (barrelDIRC)","z","events",20,0.,1.);


//  plots->h1matchTrkZ = result->AddHist1D("h1matchTrkZ","match track fraction z","z","events",20,0,1);
//  plots->h1matchTrkE = result->AddHist1D("h1matchTrkE","match track energy","E [GeV]","events",100,0,80);
//
//  plots->h1nomatchTrkZ = result->AddHist1D("h1nomatchTrkZ","no match track fraction z","z","events",20,0,1);
//  plots->h1nomatchTrkE = result->AddHist1D("h1nomatchTrkE","no match track energy","E [GeV]","events",100,0,80);
//
//
//  plots->h1Pi_purity = result->AddHist1D("h1Pi_purity","Pion purity" , "pion purity" , "events" , 20,0,1.01);
//  plots->h2Pi_purity_vs_z = result->AddHist2D("h2Pi_purity_vs_z","Pion purity vs z" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pi_purity_vs_z_E10_20 = result->AddHist2D("h2Pi_purity_vs_z_E10_20","Pion purity vs z (10 < E < 20 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pi_purity_vs_z_E20_40 = result->AddHist2D("h2Pi_purity_vs_z_E20_40","Pion purity vs z (20 < E < 40 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pi_purity_vs_z_E40_60 = result->AddHist2D("h2Pi_purity_vs_z_E40_60","Pion purity vs z (40 < E < 60 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pi_purity_vs_z_E60_80 = result->AddHist2D("h2Pi_purity_vs_z_E60_80","Pion purity vs z (60 < E < 80 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pi_purity_vs_E = result->AddHist2D("h2Pi_purity_vs_E","Pion purity vs jet E","jet E [GeV]","pion purity",80,10,90,20,0,1.01);
//  plots->h1Pi_matchTrkZ = result->AddHist1D("h1Pi_matchTrkZ","match Pion track fraction z","z","events",20,0,1.);
//  plots->h1Pi_matchTrkE = result->AddHist1D("h1Pi_matchTrkE","match Pion track energy","E [GeV]","events",100,0,20.);
//  plots->h1Pi_nomatchTrkZ = result->AddHist1D("h1Pi_nomatchTrkZ","no match Pion track fraction z","z","events",20,0,1.);
//  plots->h1Pi_nomatchTrkE = result->AddHist1D("h1Pi_nomatchTrkE","no match Pion track energy","E [GeV]","events",100,0,20.);
//
//
//  plots->h1K_purity = result->AddHist1D("h1K_purity","Kaon purity" , "kaon purity" , "events" , 20,0,1.01);
//  plots->h2K_purity_vs_z = result->AddHist2D("h2K_purity_vs_z","Kaon purity vs z" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
//  plots->h2K_purity_vs_z_E10_20 = result->AddHist2D("h2K_purity_vs_z_E10_20","Kaon purity vs z (10 < E < 20 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
//  plots->h2K_purity_vs_z_E20_40 = result->AddHist2D("h2K_purity_vs_z_E20_40","Kaon purity vs z (20 < E < 40 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
//  plots->h2K_purity_vs_z_E40_60 = result->AddHist2D("h2K_purity_vs_z_E40_60","Kaon purity vs z (40 < E < 60 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
//  plots->h2K_purity_vs_z_E60_80 = result->AddHist2D("h2K_purity_vs_z_E60_80","Kaon purity vs z (60 < E < 80 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
//  plots->h2K_purity_vs_E = result->AddHist2D("h2K_purity_vs_E","Kaon purity vs jet E","jet E [GeV]","Kaon purity",80,10,90,20,0,1.01);
//  plots->h1K_matchTrkZ = result->AddHist1D("h1K_matchTrkZ","match Kaon track fraction z","z","events",20,0,1.);
//  plots->h1K_matchTrkE = result->AddHist1D("h1K_matchTrkE","match Kaon track energy","E [GeV]","events",100,0,20.);
//  plots->h1K_nomatchTrkZ = result->AddHist1D("h1K_nomatchTrkZ","no match Kaon track fraction z","z","events",20,0,1.);
//  plots->h1K_nomatchTrkE = result->AddHist1D("h1K_nomatchTrkE","no match Kaon track energy","E [GeV]","events",100,0,20.);
//
//
//  plots->h1Pr_purity = result->AddHist1D("h1Pr_purity","Proton purity" , "proton purity" , "events" , 20,0,1.01);
//  plots->h2Pr_purity_vs_z = result->AddHist2D("h2Pr_purity_vs_z","(anti)proton purity vs z" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pr_purity_vs_z_E10_20 = result->AddHist2D("h2Pr_purity_vs_z_E10_20","(anti)proton purity vs z (10 < E < 20 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pr_purity_vs_z_E20_40 = result->AddHist2D("h2Pr_purity_vs_z_E20_40","(anti)proton purity vs z (20 < E < 40 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pr_purity_vs_z_E40_60 = result->AddHist2D("h2Pr_purity_vs_z_E40_60","(anti)proton purity vs z (40 < E < 60 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pr_purity_vs_z_E60_80 = result->AddHist2D("h2Pr_purity_vs_z_E60_80","(anti)proton purity vs z (60 < E < 80 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
//  plots->h2Pr_purity_vs_E = result->AddHist2D("h2Pr_purity_vs_E","Proton purity vs jet E","jet E [GeV]","proton purity",80,10,90,20,0,1.01);
//  plots->h1Pr_matchTrkZ = result->AddHist1D("h1Pr_matchTrkZ","match Proton track fraction z","z","events",20,0,1.);
//  plots->h1Pr_matchTrkE = result->AddHist1D("h1Pr_matchTrkE","match Proton track energy","E [GeV]","events",100,0,20.);
//  plots->h1Pr_nomatchTrkZ = result->AddHist1D("h1Pr_nomatchTrkZ","no match Proton track fraction z","z","events",20,0,1.);
//  plots->h1Pr_nomatchTrkE = result->AddHist1D("h1Pr_nomatchTrkE","no match Proton track energy","E [GeV]","events",100,0,20.);
//
//
//  plots->h1E_purity = result->AddHist1D("h1E_purity","electron purity" , "electron purity" , "events" , 20,0,1.01);
//  plots->h2E_purity_vs_z = result->AddHist2D("h2E_purity_vs_z","electron (positron) purity vs z" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
//  plots->h2E_purity_vs_z_E10_20 = result->AddHist2D("h2E_purity_vs_z_E10_20","electron (positron) purity vs z (10 < E < 20 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
//  plots->h2E_purity_vs_z_E20_40 = result->AddHist2D("h2E_purity_vs_z_E20_40","electron (positron) purity vs z (20 < E < 40 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
//  plots->h2E_purity_vs_z_E40_60 = result->AddHist2D("h2E_purity_vs_z_E40_60","electron (positron) purity vs z (40 < E < 60 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
//  plots->h2E_purity_vs_z_E60_80 = result->AddHist2D("h2E_purity_vs_z_E60_80","electron (positron) purity vs z (60 < E < 80 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
//  plots->h2E_purity_vs_E = result->AddHist2D("h2E_purity_vs_E","electron purity vs jet E","jet E [GeV]","electron purity",80,10,90,20,0,1.01);
//  plots->h1E_matchTrkZ = result->AddHist1D("h1E_matchTrkZ","match electron track fraction z","z","events",20,0,1.);
//  plots->h1E_matchTrkE = result->AddHist1D("h1E_matchTrkE","match electron track energy","E [GeV]","events",100,0,20.);
//  plots->h1E_nomatchTrkZ = result->AddHist1D("h1E_nomatchTrkZ","no match electron track fraction z","z","events",20,0,1.);
//  plots->h1E_nomatchTrkE = result->AddHist1D("h1E_nomatchTrkE","no match electron track energy","E [GeV]","events",100,0,20.);

  //plots->h1TrackP = result->AddHist1D("h1TrackP","track momentum","P [GeV]","events",100,0,20);

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

  TClonesArray *branchdualRICHagTrack = treeReader->UseBranch("dualRICHagTrack"); 

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


  Int_t OutEid;

  Int_t i, j, pdgCode;

	
  Int_t nPi_PID , nPi_true , nK_PID , nK_true , nPr_PID , nPr_true, nE_PID , nE_true;

  Int_t Pi_PID[30] ,Pi_true[30] , K_PID[30] , K_true[30] , Pr_PID[30] , Pr_true[30] , E_PID[30] , E_true[30], Pi_checkmatch[30] , K_checkmatch[30] ,Pr_checkmatch[30] ,E_checkmatch[30] ;

  Int_t matchPi_PID , matchPr_PID , matchK_PID ,matchE_PID ;
  Double_t Pi_purity, Pr_purity, K_purity, E_purity;

  Double_t EFlowTrackZ;

  // Loop over all events




 
  int njets = 0;
  int PIDnum = 0;


  for(entry = 0; entry < allEntries; ++entry)
//    for(entry = 0; entry < 5; ++entry)
  {



    // Load selected branches with data from specified event

    treeReader->ReadEntry(entry);


    //loop for all particles

    //for (int i = 0; i < branchParticle->GetEntries(); ++i) {


      if (! branchParticle) continue;
      particle = (GenParticle*)branchParticle->At(0);
      InPr = particle->P4();
      particle = (GenParticle*)branchParticle->At(3);
      InE = particle->P4();
      OutEid = particle->D1;
      particle = (GenParticle*)branchParticle->At(5);
      OutE = particle->P4();

//	cout<<"In e energy:"<<InE.E()<<" Out e energy:"<<OutE.E()<<endl;

//    for (int i = 0; i < branchParticle->GetEntries(); ++i) {
//      particle = (GenParticle*)branchParticle->At(i);
//      cout<<i<<" Status:"<<particle->Status<<"  PID:"<<particle->PID<<endl;
//    }




    //}


    //loop for all Hcal tracks
    for (int i = 0; i < branchEFlowTrack->GetEntries(); ++i) 
   {
        track = (Track*)branchEFlowTrack->At(i);

	EFlowTrackP4 = track->P4();

	//cout<<"Photon E"<<EFlowPhotoni.E()<<endl;

	EFlowTrackZ = (InPr.Dot(EFlowTrackP4)) / (InPr.Dot(InE - OutE));

	h1TrackZ->Fill(EFlowTrackZ);
	h1TrackE->Fill(EFlowTrackP4.E());
	
	if ((track->Eta > 1) && (track->Eta < 3.5) && (track->P4().E() < 12)) 
	{
		h1dualRICH_aerogel_TrackZ->Fill(EFlowTrackZ);
		PIDnum = TMath::Abs(track->PID);
		if (PIDnum == 211) {h1dualRICH_aerogel_PiTrackZ->Fill(EFlowTrackZ);}		
		if (PIDnum == 321) {h1dualRICH_aerogel_KTrackZ->Fill(EFlowTrackZ);}		
		if (PIDnum == 2212) {h1dualRICH_aerogel_PrTrackZ->Fill(EFlowTrackZ);}		
	}

	if ((track->Eta > 1) && (track->Eta < 3.5) && (track->P4().E() >= 12)) 
	{
		h1dualRICH_c2f6_TrackZ->Fill(EFlowTrackZ);
		PIDnum = TMath::Abs(track->PID);
		if (PIDnum == 211) {h1dualRICH_c2f6_PiTrackZ->Fill(EFlowTrackZ);}
		if (PIDnum == 321) {h1dualRICH_c2f6_KTrackZ->Fill(EFlowTrackZ);}
		if (PIDnum == 2212) {h1dualRICH_c2f6_PrTrackZ->Fill(EFlowTrackZ);}
	}

	if ((track->Eta > -1) && (track->Eta < 1)) 
	{
		h1BarrelTrackZ->Fill(EFlowTrackZ);
		PIDnum = TMath::Abs(track->PID);
		if (PIDnum == 211) {h1BarrelPiTrackZ->Fill(EFlowTrackZ);}
		if (PIDnum == 321) {h1BarrelKTrackZ->Fill(EFlowTrackZ);}
		if (PIDnum == 2212) {h1BarrelPrTrackZ->Fill(EFlowTrackZ);}
	}

//	cout<<"z:"<<EFlowPhotonZ<<endl;

   }

    

//    //loop for all PID system tracks
//    for (int i = 0; i < branchdualRICHagTrack->GetEntries(); ++i) {
//      dualRICHagTrack = (Track*)branchdualRICHagTrack->At(i);
//
//      if (dualRICHagTrack->PT < 0.1 || TMath::Abs(dualRICHagTrack->Eta) > 3.5) continue;
//
//	PIDnum = dualRICHagTrack->PID;
//
//	PIDnum = TMath::Abs(PIDnum);
//
//	cout<<"PID system track E"<<dualRICHagTrack->P4().E()<<endl;
//	cout<<"PID system track eta"<<dualRICHagTrack->P4().Eta()<<endl;
//
//	switch(PIDnum)
//	{
//
//		case 211 :
//			Pi_PID[nPi_PID] = i ;
//			Pi_checkmatch[nPi_PID]=-1;
//			nPi_PID = nPi_PID +1;
//		break;
//
//		case 321 :
//                        K_PID[nK_PID] = i ;
//			K_checkmatch[nK_PID]=-1;
//                        nK_PID = nK_PID +1;
//                break;
//
//		case 2212 :
//                        Pr_PID[nPr_PID] = i ;
//			Pr_checkmatch[nPr_PID]=-1;
//                        nPr_PID = nPr_PID +1;
//                break;
//
//		case 11 :
//                        E_PID[nE_PID] = i ;
//			E_checkmatch[nE_PID]=-1;
//                        nE_PID = nE_PID +1;
//                break;
//
//	}
//	
////	cout<< "PID num PID " << PIDnum << endl;
//
//    }

//    cout << "nPr_true: " << nPr_true << " nPr_PID: "<<nPr_PID << endl;
//    cout << "nPi_true: " << nPi_true << " nPi_PID: "<<nPi_PID << endl;    
//    cout << "nK_true: " << nK_true << " nK_PID: "<<nK_PID << endl;
//    cout << "nE_true: " << nE_true << " nE_PID: "<<nE_PID << endl;




    // Loop over all jets in event

//    cout<<"n Jets:"<<branchJet->GetEntriesFast()<<endl;

//    for(int i = 0; i < branchJet->GetEntriesFast(); ++i)
//
//    {
//
//      jet = (Jet*) branchJet->At(i);
//
////      if(jet->PT<10.0) continue;
//
//
//      float deltaR = 999;
//
//
//      TLorentzVector jetMomentum = jet->P4();
//
//      deltaR = 999;
//
//      int matched_index = -999;
//
////
////      // Loop over all jet's constituents
////
//
//	int NTrack=0;
//
//	int totalPi=0; matchPi_PID = 0; Pi_purity = -1;
//	int totalK=0; matchK_PID = 0; K_purity = -1;
//	int totalPr=0; matchPr_PID = 0; Pr_purity = -1;
//	int totalE=0; matchE_PID = 0; E_purity = -1;
//
//
//      for(j = 0; j < jet->Constituents.GetEntriesFast(); ++j)
//
//      {
//
//	        object = jet->Constituents.At(j);
//
//        // Check if the constituent is accessible
//
//        	if(object == 0) continue;
//
//        	if(object->IsA() == Track::Class())
//
//        	{
//
//	          	track = (Track*) object;
//	
//	
////		  	if(track->PT<0.100) continue;  // if track has less than 200 MeV, then do not consider it
//	
//	          //cout << "    Track pt: " << track->PT << ", eta: " << track->Eta << ", phi: " << track->Phi << endl;
//	
//	          	momentum += track->P4();
//
//			cout<<"track in jet E"<<track->P4().E()<<endl;
//
//			//if (track->P4().Mag() > 12) continue;
//			if ((track->P4().Eta() < 1)||(track->P4().Eta()>3.5)) continue;
//	
//		  	if(!(abs(track->PID)==211 || abs(track->PID)==321 || abs(track->PID)==2212 || abs(track->PID)==11)) continue; //if not a charged pion or kaon or proton or e, continue
//	
//		  	double pxh, pyh, pzh, cross;
//	
//		  	pxh = track->P4().Px();
//	
//		  	pyh = track->P4().Py();
//	
//		  	pzh = track->P4().Pz();
//	
//		        double ptrack = TMath::Sqrt(pxh*pxh + pyh*pyh + pzh*pzh);
//		  
//			h1TrackP->Fill(ptrack);
//			if (ptrack > 12) continue;
//
//		 	double pxj, pyj, pzj;
//	
//	          	pxj = jet->P4().Px();
//	
//		  	pyj = jet->P4().Py();
//	
//		  	pzj = jet->P4().Pz();
//	
//	          	double p = TMath::Sqrt(pxj*pxj + pyj*pyj + pzj*pzj);
//
//			double z = jet->P4().Vect().Dot( track->P4().Vect() )/(jet->P4().P()*jet->P4().P());
//
//			int isMatch=0;
//
//	
//			//find PID systenm pion match
//			if (abs(track->PID) == 211)
//			{
//				totalPi=totalPi+1;
//				for (int PIDi=0;PIDi < nPi_PID;++PIDi)
//				{
//	
//					dualRICHagTrack = (Track*)branchdualRICHagTrack->At(Pi_PID[PIDi]);
//					if (track->Particle.GetObject() == dualRICHagTrack->Particle.GetObject()) 
//					{isMatch = 1; Pi_checkmatch[PIDi]=999; ++matchPi_PID; h1Pi_matchTrkZ->Fill(z); h1Pi_matchTrkE->Fill(track->P4().E());}
//
//
//				}
//			}
//			if ((abs(track->PID) == 211) && (isMatch != 1)) 			
//				{h1Pi_nomatchTrkZ->Fill(z); h1Pi_nomatchTrkE->Fill(track->P4().E());}
//
//	
//			//kaon
//			if (abs(track->PID) == 321)
//	                {
//	                        totalK=totalK+1;
//	                        for (int PIDi=0;PIDi < nK_PID;++PIDi)
//	                        {
//	
//	                                dualRICHagTrack = (Track*)branchdualRICHagTrack->At(K_PID[PIDi]);
//	                                if (track->Particle.GetObject() == dualRICHagTrack->Particle.GetObject()) {isMatch = 1; K_checkmatch[PIDi]=999; ++matchK_PID; h1K_matchTrkZ->Fill(z); h1K_matchTrkE->Fill(track->P4().E());}
//
//
//	                        }
//	                }
//			if ((abs(track->PID) == 321) && (isMatch != 1)) {h1K_nomatchTrkZ->Fill(z); h1K_nomatchTrkE->Fill(track->P4().E());}
//
//			//proton
//			if (abs(track->PID) == 2212)
//	                {
//	                        totalPr=totalPr+1;
//	                        for (int PIDi=0;PIDi < nPr_PID;++PIDi)
//	                        {
//	
//	                                dualRICHagTrack = (Track*)branchdualRICHagTrack->At(Pr_PID[PIDi]);
//	                                if (track->Particle.GetObject() == dualRICHagTrack->Particle.GetObject()) {isMatch = 1; Pr_checkmatch[PIDi]=999;  ++matchPr_PID; h1Pr_matchTrkZ->Fill(z); h1Pr_matchTrkE->Fill(track->P4().E());}
//
//
//	                        }
//	                }
//			if ((abs(track->PID) == 2212) && (isMatch != 1)) {h1Pr_nomatchTrkZ->Fill(z); h1Pr_nomatchTrkE->Fill(track->P4().E());}
//	
//			//electron
//			if (abs(track->PID) == 11)
//	                {
//	                        totalE=totalE+1;
//	                        for (int PIDi=0;PIDi < nE_PID;++PIDi)
//	                        {
//	
//	                                dualRICHagTrack = (Track*)branchdualRICHagTrack->At(E_PID[PIDi]);
//	                                if (track->Particle.GetObject() == dualRICHagTrack->Particle.GetObject()) {isMatch = 1; E_checkmatch[PIDi]=999;  ++matchE_PID; h1E_matchTrkZ->Fill(z); h1E_matchTrkE->Fill(track->P4().E());}
//
//	                        }
//	                }
//			if ((abs(track->PID) == 11) && (isMatch != 1)) {h1E_nomatchTrkZ->Fill(z); h1E_nomatchTrkE->Fill(track->P4().E());}
//	
//		  //cout << jet->P4().Vect().Mag() << endl;
//	
//		  //cout << track->P4().Vect().Mag() << endl;
//	
//		  
//	
//		  //cout << " " << endl;
//	
//		  	TVector3 crossproduct = jet->P4().Vect().Unit().Cross(track->P4().Vect().Unit());
//	
//	          //cout << "Cross product " << crossproduct.Mag() << endl;
//	
//		  //cout << "angle " << TMath::ASin(crossproduct.Mag()) << endl;  
//	
//		  
//	
//		  	double sin = crossproduct.Mag()/(jet->P4().Vect().Mag());
//	
//		    
//	
//	
//	          //if( !(z>0.4 and z<0.6)) continue;
//
//		//if (isMatch == 0) 
//		//{
//		//	h1nomatchTrkZ->Fill(z);
//                //        h1nomatchTrkE->Fill(track->P4().E());
//
//		//}
//
//		}
//	}
//
//		double jetE = jet->P4().E();
//
//	}//jet


  } //event

}




//------------------------------------------------------------------------------




void PrintHistograms(ExRootResult *result, TestPlots *plots)

{

  result->Print("root");

}




//------------------------------------------------------------------------------




void EFlowTrack_z(const char *inputFile)

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

