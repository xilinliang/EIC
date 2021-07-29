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

    TH2 *h2Pi_purity_vs_z;
    TH2 *h2Pi_purity_vs_z_E10_20;
    TH2 *h2Pi_purity_vs_z_E20_40;
    TH2 *h2Pi_purity_vs_z_E40_60;
    TH2 *h2Pi_purity_vs_z_E60_80;
    TH2 *h2Pi_purity_vs_E;
    TH1 *h1Pi_matchTrkE;
    TH1 *h1Pi_matchTrkZ;
    TH1 *h1Pi_checkmatchTrkE;
    TH1 *h1Pi_checkmatchTrkZ;
    TH1 *h1Pi_nomatchTrkE;
    TH1 *h1Pi_nomatchTrkZ;
    TH1 *h1Pi_checknomatchTrkE;
    TH1 *h1Pi_checkmismatchTrkE;
    TH1 *h1Pi_checknomatchTrkZ;

    TH2 *h2K_purity_vs_z;
    TH2 *h2K_purity_vs_z_E10_20;
    TH2 *h2K_purity_vs_z_E20_40;
    TH2 *h2K_purity_vs_z_E40_60;
    TH2 *h2K_purity_vs_z_E60_80;
    TH2 *h2K_purity_vs_E;
    TH1 *h1K_matchTrkE;
    TH1 *h1K_matchTrkZ;
    TH1 *h1K_checkmatchTrkE;
    TH1 *h1K_checkmatchTrkZ;
    TH1 *h1K_nomatchTrkE;
    TH1 *h1K_nomatchTrkZ;
    TH1 *h1K_checknomatchTrkE;
    TH1 *h1K_checkmismatchTrkE;
    TH1 *h1K_checknomatchTrkZ;

    TH2 *h2Pr_purity_vs_z;
    TH2 *h2Pr_purity_vs_z_E10_20;
    TH2 *h2Pr_purity_vs_z_E20_40;
    TH2 *h2Pr_purity_vs_z_E40_60;
    TH2 *h2Pr_purity_vs_z_E60_80;
    TH2 *h2Pr_purity_vs_E;
    TH1 *h1Pr_matchTrkE;
    TH1 *h1Pr_matchTrkZ;
    TH1 *h1Pr_checkmatchTrkE;
    TH1 *h1Pr_checkmatchTrkZ;
    TH1 *h1Pr_nomatchTrkE;
    TH1 *h1Pr_nomatchTrkZ;
    TH1 *h1Pr_checknomatchTrkE;
    TH1 *h1Pr_checkmismatchTrkE;
    TH1 *h1Pr_checknomatchTrkZ;

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

    TH1 *h1TrackP;


};




//------------------------------------------------------------------------------




void BookHistograms(ExRootResult *result, TestPlots *plots)

{

  TLegend *legend;

  TPaveText *comment;

  plots->h1matchTrkZ = result->AddHist1D("h1matchTrkZ","match track fraction z","z","events",20,0,1);
  plots->h1matchTrkE = result->AddHist1D("h1matchTrkE","match track energy","E [GeV]","events",100,0,80.);

  plots->h1nomatchTrkZ = result->AddHist1D("h1nomatchTrkZ","no match track fraction z","z","events",20,0,1);
  plots->h1nomatchTrkE = result->AddHist1D("h1nomatchTrkE","no match track energy","E [GeV]","events",100,0.,80.);
  plots->h1checknomatchTrkE = result->AddHist1D("h1checknomatchTrkE","no match EFlow track energy","E [GeV]","events",50,0.,12.);
  plots->h1checkmatchTrkE = result->AddHist1D("h1checkmatchTrkE","match EFlow track energy ","E [GeV]","events",50,0.,12.);


  plots->h1Pi_purity = result->AddHist1D("h1Pi_purity","Pion purity" , "pion purity" , "events" , 20,0,1.01);
  plots->h2Pi_purity_vs_z = result->AddHist2D("h2Pi_purity_vs_z","Pion purity vs z" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E10_20 = result->AddHist2D("h2Pi_purity_vs_z_E10_20","Pion purity vs z (10 < E < 20 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E20_40 = result->AddHist2D("h2Pi_purity_vs_z_E20_40","Pion purity vs z (20 < E < 40 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E40_60 = result->AddHist2D("h2Pi_purity_vs_z_E40_60","Pion purity vs z (40 < E < 60 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E60_80 = result->AddHist2D("h2Pi_purity_vs_z_E60_80","Pion purity vs z (60 < E < 80 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_E = result->AddHist2D("h2Pi_purity_vs_E","Pion purity vs jet E","jet E [GeV]","pion purity",80,10,90,20,0,1.01);
  plots->h1Pi_matchTrkZ = result->AddHist1D("h1Pi_matchTrkZ","match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_matchTrkE = result->AddHist1D("h1Pi_matchTrkE","match Pion track energy","E [GeV]","events",100,0,20.);
  plots->h1Pi_nomatchTrkZ = result->AddHist1D("h1Pi_nomatchTrkZ","no match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_nomatchTrkE = result->AddHist1D("h1Pi_nomatchTrkE","no match Pion track energy","E [GeV]","events",50,0,12.);
  plots->h1Pi_checkmatchTrkE = result->AddHist1D("h1Pi_checkmatchTrkE","match Pion track energy ","E [GeV]","events",100,0.,50.);
  plots->h1Pi_checknomatchTrkE = result->AddHist1D("h1Pi_checknomatchTrkE","no match Pion track energy","E [GeV]","events",100,0.,50.);
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
  plots->h1K_matchTrkE = result->AddHist1D("h1K_matchTrkE","match Kaon track energy","E [GeV]","events",100,0,20.);
  plots->h1K_nomatchTrkZ = result->AddHist1D("h1K_nomatchTrkZ","no match Kaon track fraction z","z","events",20,0,1.);
  plots->h1K_nomatchTrkE = result->AddHist1D("h1K_nomatchTrkE","no match Kaon track energy","E [GeV]","events",50,0,12.);
  plots->h1K_checkmatchTrkE = result->AddHist1D("h1K_checkmatchTrkE","match Kaon track energy ","E [GeV]","events",100,0.,50.);
  plots->h1K_checknomatchTrkE = result->AddHist1D("h1K_checknomatchTrkE","no Kaon track energy ","E [GeV]","events",100,0.,50.);
  plots->h1K_checkmatchTrkZ = result->AddHist1D("h1K_checkmatchTrkZ","match Kaon track energy fraction z","z","events",20,0,1.);
  plots->h1K_checknomatchTrkZ = result->AddHist1D("h1K_checknomatchTrkZ","no match Kaon track energy fraction z","z","events",20,0,1.);


  plots->h1Pr_purity = result->AddHist1D("h1Pr_purity","Proton purity" , "proton purity" , "events" , 20,0,1.01);
  plots->h2Pr_purity_vs_z = result->AddHist2D("h2Pr_purity_vs_z","(anti)proton purity vs z" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E10_20 = result->AddHist2D("h2Pr_purity_vs_z_E10_20","(anti)proton purity vs z (10 < E < 20 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E20_40 = result->AddHist2D("h2Pr_purity_vs_z_E20_40","(anti)proton purity vs z (20 < E < 40 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E40_60 = result->AddHist2D("h2Pr_purity_vs_z_E40_60","(anti)proton purity vs z (40 < E < 60 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E60_80 = result->AddHist2D("h2Pr_purity_vs_z_E60_80","(anti)proton purity vs z (60 < E < 80 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_E = result->AddHist2D("h2Pr_purity_vs_E","Proton purity vs jet E","jet E [GeV]","proton purity",80,10,90,20,0,1.01);
  plots->h1Pr_matchTrkZ = result->AddHist1D("h1Pr_matchTrkZ","match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pr_matchTrkE = result->AddHist1D("h1Pr_matchTrkE","match Pion track energy","E [GeV]","events",100,0,20.);
  plots->h1Pr_nomatchTrkZ = result->AddHist1D("h1Pr_nomatchTrkZ","no match Proton track fraction z","z","events",20,0,1.);
  plots->h1Pr_nomatchTrkE = result->AddHist1D("h1Pr_nomatchTrkE","no match Proton track energy","E [GeV]","events",100,0,20.);
  plots->h1Pr_checkmatchTrkE = result->AddHist1D("h1Pr_checkmatchTrkE","match Proton track energy ","E [GeV]","events",100,0.,50.);
  plots->h1Pr_checknomatchTrkE = result->AddHist1D("h1Pr_checknomatchTrkE","no match Proton track energy ","E [GeV]","events",100,0.,50.);
  plots->h1Pr_checkmatchTrkZ = result->AddHist1D("h1Pr_checkmatchTrkZ","match Proton track energy fraction z","z","events",20,0,1);
  plots->h1Pr_checknomatchTrkZ = result->AddHist1D("h1Pr_checknomatchTrkZ","no match Proton track energy fraction z","z","events",20,0,1);


  plots->h1E_purity = result->AddHist1D("h1E_purity","electron purity" , "electron purity" , "events" , 20,0,1.01);
  plots->h2E_purity_vs_z = result->AddHist2D("h2E_purity_vs_z","electron (positron) purity vs z" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E10_20 = result->AddHist2D("h2E_purity_vs_z_E10_20","electron (positron) purity vs z (10 < E < 20 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E20_40 = result->AddHist2D("h2E_purity_vs_z_E20_40","electron (positron) purity vs z (20 < E < 40 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E40_60 = result->AddHist2D("h2E_purity_vs_z_E40_60","electron (positron) purity vs z (40 < E < 60 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E60_80 = result->AddHist2D("h2E_purity_vs_z_E60_80","electron (positron) purity vs z (60 < E < 80 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_E = result->AddHist2D("h2E_purity_vs_E","electron purity vs jet E","jet E [GeV]","electron purity",80,10,90,20,0,1.01);
  plots->h1E_matchTrkZ = result->AddHist1D("h1E_matchTrkZ","match electron track fraction z","z","events",20,0,1.);
  plots->h1E_matchTrkE = result->AddHist1D("h1E_matchTrkE","match electron track energy","E [GeV]","events",100,0,20.);
  plots->h1E_nomatchTrkZ = result->AddHist1D("h1E_nomatchTrkZ","no match electron track fraction z","z","events",20,0,1.);
  plots->h1E_nomatchTrkE = result->AddHist1D("h1E_nomatchTrkE","no match electron track energy","E [GeV]","events",100,0,20.);

  plots->h1TrackP = result->AddHist1D("h1TrackP","track momentum","P [GeV]","events",100,0,20);

}

//------------------------------------------------------------------------------




void AnalyseEvents(ExRootTreeReader *treeReader, TestPlots *plots)

{

  cout<<"check 1"<<endl;

  TClonesArray *branchParticle = treeReader->UseBranch("Particle");

  TClonesArray *branchElectron = treeReader->UseBranch("Electron");

  TClonesArray *branchSmearingTrack = treeReader->UseBranch("Track");

  TClonesArray *branchEFlowPhoton = treeReader->UseBranch("EFlowPhoton");

  TClonesArray *branchEFlowNeutralHadron = treeReader->UseBranch("EFlowNeutralHadron");

  TClonesArray *branchJet = treeReader->UseBranch("Jet");

  TClonesArray *branchGenJet = treeReader->UseBranch("GenJet");

  TClonesArray *branchbarrelDIRCTrack = treeReader->UseBranch("barrelDIRCTrack"); 

  Long64_t allEntries = treeReader->GetEntries();




  cout << "** Chain contains " << allEntries << " events" << endl;




  GenParticle *particle;

  Electron *electron;

  Track *PIDTrack;
  
  Track *SmearingTrack;
 

  Track *track;

  Tower *tower;




  Jet *jet;

  Jet *genjet;

  Jet *matchedjet;

  TObject *object;




  TLorentzVector momentum, InPr , InE, OutE, SmearingTrackP4;



  Float_t Eem, Ehad;

  Bool_t skip;




  Long64_t entry;




  Int_t i, j, pdgCode;

	
//  Int_t nPi_PID , nPi_true , nK_PID , nK_true , nPr_PID , nPr_true, nE_PID , nE_true;
//
//  Int_t Pi_PID[30] ,Pi_true[30] , K_PID[30] , K_true[30] , Pr_PID[30] , Pr_true[30] , E_PID[30] , E_true[30], Pi_checkmatch[30] , K_checkmatch[30] ,Pr_checkmatch[30] ,E_checkmatch[30] ;
//
//  Int_t matchPi_PID , matchPr_PID , matchK_PID ,matchE_PID ;
//  Double_t Pi_purity, Pr_purity, K_purity, E_purity;
  Double_t SmearingTrackZ;

  // Loop over all events




  int njets = 0;
  int PIDnum = 0;


  for(entry = 0; entry < allEntries; ++entry)
//    for(entry = 0; entry < 5; ++entry)
  {

    // Load selected branches with data from specified event

    treeReader->ReadEntry(entry);

   // nPi_PID=0 ; 
   // nPi_true=0; 
   // nK_PID=0 ;
   // nK_true=0 ;
   // nPr_PID=0; 
   // nPr_true=0; 
   // nE_PID=0; 
   // nE_true=0;

    if (! branchParticle) continue;
    particle = (GenParticle*)branchParticle->At(0);
    InPr = particle->P4();
    particle = (GenParticle*)branchParticle->At(3);
    InE = particle->P4();
    particle = (GenParticle*)branchParticle->At(5);
    OutE = particle->P4();


    //loop for all Hcal tracks
    for (int i = 0; i < branchSmearingTrack->GetEntries(); ++i) 
    {
      SmearingTrack = (Track*)branchSmearingTrack->At(i);

      if (TMath::Abs(SmearingTrack->Eta) > 1.0) continue;
      if(!(abs(SmearingTrack->PID)==211 || abs(SmearingTrack->PID)==321 || abs(SmearingTrack->PID)==2212 )) continue; //if not a charged pion or kaon or proton or e, continue

	PIDnum = SmearingTrack->PID;

	PIDnum = TMath::Abs(PIDnum);

	SmearingTrack = (Track*)branchSmearingTrack->At(i);
	SmearingTrackP4 = SmearingTrack->P4();
	SmearingTrackZ = (InPr.Dot(SmearingTrackP4)) / (InPr.Dot(InE - OutE));
//	cout<<"energy fraction z:"<<SmearingTrackZ<<endl;

	int j=0; int checkmatch=0;
	while (j < branchbarrelDIRCTrack->GetEntries() && checkmatch == 0)
	{

		barrelDIRCTrack = (Track*)branchbarrelDIRCTrack->At(j);

			if (SmearingTrack->Particle.GetObject() == barrelDIRCTrack->Particle.GetObject()) 
			{
				checkmatch = -1;
				if (SmearingTrack->PID == barrelDIRCTrack->PID) {checkmatch = 1;}

			}

			j=j+1;
		

	}

	if (checkmatch == -1) 
	{
		h1checknomatchTrkE->Fill(SmearingTrack->P4().E());
		if (abs(PIDnum) == 211) {h1Pi_checknomatchTrkZ->Fill(SmearingTrackZ); h1Pi_checknomatchTrkE->Fill(SmearingTrack->P4().E());} 
		if (abs(PIDnum) == 321) {h1K_checknomatchTrkZ->Fill(SmearingTrackZ); h1K_checknomatchTrkE->Fill(SmearingTrack->P4().E());} 
		if (abs(PIDnum) == 2212) {h1Pr_checknomatchTrkZ->Fill(SmearingTrackZ); h1Pr_checknomatchTrkE->Fill(SmearingTrack->P4().E());} 
	}

	if (checkmatch == 1) 
	{
		h1checkmatchTrkE->Fill(SmearingTrack->P4().E());
		if (abs(PIDnum) == 211) {h1Pi_checkmatchTrkZ->Fill(SmearingTrackZ); h1Pi_checkmatchTrkE->Fill(SmearingTrack->P4().E());} 
		if (abs(PIDnum) == 321) {h1K_checkmatchTrkZ->Fill(SmearingTrackZ); h1K_checkmatchTrkE->Fill(SmearingTrack->P4().E());} 
		if (abs(PIDnum) == 2212) {h1Pr_checkmatchTrkZ->Fill(SmearingTrackZ); h1Pr_checkmatchTrkE->Fill(SmearingTrack->P4().E());} 
	}

   }//smearing track

    




  } //event

}




//------------------------------------------------------------------------------




void PrintHistograms(ExRootResult *result, TestPlots *plots)

{

  result->Print("root");

}




//------------------------------------------------------------------------------




void PID_barrelDIRCTrack_checkPIDtrk(const char *inputFile)

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

