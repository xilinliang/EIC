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


    TH1 *h1Pi_matchTrkE;
    TH1 *h1Pi_matchTrkZ;
    TH1 *h1Pi_checkmatchTrkE;
    TH1 *h1Pi_checkmatchTrkZ;
    TH1 *h1Pi_nomatchTrkE;
    TH1 *h1Pi_nomatchTrkZ;
    TH1 *h1Pi_checknomatchTrkE;
    TH1 *h1Pi_checkmismatchTrkE;
    TH1 *h1Pi_checknomatchTrkZ;
	TH1 *h1TruePiPID;


    TH1 *h1K_matchTrkE;
    TH1 *h1K_matchTrkZ;
    TH1 *h1K_checkmatchTrkE;
    TH1 *h1K_checkmatchTrkZ;
    TH1 *h1K_nomatchTrkE;
    TH1 *h1K_nomatchTrkZ;
    TH1 *h1K_checknomatchTrkE;
    TH1 *h1K_checkmismatchTrkE;
    TH1 *h1K_checknomatchTrkZ;
	TH1 *h1TrueKPID;


    TH1 *h1Pr_matchTrkE;
    TH1 *h1Pr_matchTrkZ;
    TH1 *h1Pr_checkmatchTrkE;
    TH1 *h1Pr_checkmatchTrkZ;
    TH1 *h1Pr_nomatchTrkE;
    TH1 *h1Pr_nomatchTrkZ;
    TH1 *h1Pr_checknomatchTrkE;
    TH1 *h1Pr_checkmismatchTrkE;
    TH1 *h1Pr_checknomatchTrkZ;
	TH1 *h1TruePrPID;



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

  plots->h1Pi_matchTrkZ = result->AddHist1D("h1Pi_matchTrkZ","match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_matchTrkE = result->AddHist1D("h1Pi_matchTrkE","match Pion track energy","E [GeV]","events",100,0,20.);
  plots->h1Pi_nomatchTrkZ = result->AddHist1D("h1Pi_nomatchTrkZ","no match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pi_nomatchTrkE = result->AddHist1D("h1Pi_nomatchTrkE","no match Pion track energy","E [GeV]","events",50,0,12.);
  plots->h1Pi_checkmatchTrkE = result->AddHist1D("h1Pi_checkmatchTrkE","match Pion track energy ","E [GeV]","events",100,0.,50.);
  plots->h1Pi_checknomatchTrkE = result->AddHist1D("h1Pi_checknomatchTrkE","no match Pion track energy","E [GeV]","events",100,0.,50.);
  plots->h1Pi_checkmatchTrkZ = result->AddHist1D("h1Pi_checkmatchTrkZ","match Pion track energy fraction z","z","events",20,0,1.);
  plots->h1Pi_checknomatchTrkZ = result->AddHist1D("h1Pi_checknomatchTrkZ","no match Pion track energy fraction z","z","events",20,0,1.);
  plots->h1TruePiPID = result->AddHist1D("h1TruePiPID","True Pion PID track type" , "type" , "events" , 5,0.,5.);
  h1TruePiPID->GetXaxis()->SetBinLabel(1,"electron");
  h1TruePiPID->GetXaxis()->SetBinLabel(2,"pion");
  h1TruePiPID->GetXaxis()->SetBinLabel(3,"kaon");
  h1TruePiPID->GetXaxis()->SetBinLabel(4,"proton");
  h1TruePiPID->GetXaxis()->SetBinLabel(5,"other");


  plots->h1K_purity = result->AddHist1D("h1K_purity","Kaon purity" , "kaon purity" , "events" , 20,0,1.01);

  plots->h1K_matchTrkZ = result->AddHist1D("h1K_matchTrkZ","match Kaon track fraction z","z","events",20,0,1.);
  plots->h1K_matchTrkE = result->AddHist1D("h1K_matchTrkE","match Kaon track energy","E [GeV]","events",100,0,20.);
  plots->h1K_nomatchTrkZ = result->AddHist1D("h1K_nomatchTrkZ","no match Kaon track fraction z","z","events",20,0,1.);
  plots->h1K_nomatchTrkE = result->AddHist1D("h1K_nomatchTrkE","no match Kaon track energy","E [GeV]","events",50,0,12.);
  plots->h1K_checkmatchTrkE = result->AddHist1D("h1K_checkmatchTrkE","match Kaon track energy ","E [GeV]","events",100,0.,50.);
  plots->h1K_checknomatchTrkE = result->AddHist1D("h1K_checknomatchTrkE","no match Kaon track energy ","E [GeV]","events",100,0.,50.);
  plots->h1K_checkmatchTrkZ = result->AddHist1D("h1K_checkmatchTrkZ","match Kaon track energy fraction z","z","events",20,0,1.);
  plots->h1K_checknomatchTrkZ = result->AddHist1D("h1K_checknomatchTrkZ","no match Kaon track energy fraction z","z","events",20,0,1.);
  plots->h1TrueKPID = result->AddHist1D("h1TrueKPID","True Kaon PID track type" , "type" , "events" , 5,0.,5.);
  h1TrueKPID->GetXaxis()->SetBinLabel(1,"electron");
  h1TrueKPID->GetXaxis()->SetBinLabel(2,"pion");
  h1TrueKPID->GetXaxis()->SetBinLabel(3,"kaon");
  h1TrueKPID->GetXaxis()->SetBinLabel(4,"proton");
  h1TrueKPID->GetXaxis()->SetBinLabel(5,"other");


  plots->h1Pr_purity = result->AddHist1D("h1Pr_purity","Proton purity" , "proton purity" , "events" , 20,0,1.01);

  plots->h1Pr_matchTrkZ = result->AddHist1D("h1Pr_matchTrkZ","match Pion track fraction z","z","events",20,0,1.);
  plots->h1Pr_matchTrkE = result->AddHist1D("h1Pr_matchTrkE","match Pion track energy","E [GeV]","events",100,0,20.);
  plots->h1Pr_nomatchTrkZ = result->AddHist1D("h1Pr_nomatchTrkZ","no match Proton track fraction z","z","events",20,0,1.);
  plots->h1Pr_nomatchTrkE = result->AddHist1D("h1Pr_nomatchTrkE","no match Proton track energy","E [GeV]","events",100,0,20.);
  plots->h1Pr_checkmatchTrkE = result->AddHist1D("h1Pr_checkmatchTrkE","match Proton track energy ","E [GeV]","events",100,0.,50.);
  plots->h1Pr_checknomatchTrkE = result->AddHist1D("h1Pr_checknomatchTrkE","no match Proton track energy ","E [GeV]","events",100,0.,50.);
  plots->h1Pr_checkmatchTrkZ = result->AddHist1D("h1Pr_checkmatchTrkZ","match Proton track energy fraction z","z","events",20,0,1);
  plots->h1Pr_checknomatchTrkZ = result->AddHist1D("h1Pr_checknomatchTrkZ","no match Proton track energy fraction z","z","events",20,0,1);
  plots->h1TruePrPID = result->AddHist1D("h1TruePrPID","True Proton PID track type" , "type" , "events" , 5,0.,5.);
  h1TruePrPID->GetXaxis()->SetBinLabel(1,"electron");
  h1TruePrPID->GetXaxis()->SetBinLabel(2,"pion");
  h1TruePrPID->GetXaxis()->SetBinLabel(3,"kaon");
  h1TruePrPID->GetXaxis()->SetBinLabel(4,"proton");
  h1TruePrPID->GetXaxis()->SetBinLabel(5,"other");


  plots->h1E_purity = result->AddHist1D("h1E_purity","electron purity" , "electron purity" , "events" , 20,0,1.01);

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

  TClonesArray *branchdualRICHcfTrack = treeReader->UseBranch("dualRICHcfTrack"); 

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




  TLorentzVector momentum, InPr , InE, OutE, dualRICHcfTrackP4;



  Float_t Eem, Ehad;

  Bool_t skip;




  Long64_t entry;




  Int_t i, j, pdgCode;

	

  Double_t dualRICHcfTrackZ;

  // Loop over all events




  int njets = 0;
  int PIDnum = 0;
  int PIDtrknum=0;


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

      //if (SmearingTrack->P < 12 || (SmearingTrack->Eta) < 1.0  || (SmearingTrack->Eta) > 3.5) continue;
      //if(!(abs(SmearingTrack->PID)==211 || abs(SmearingTrack->PID)==321 || abs(SmearingTrack->PID)==2212 )) continue; //if not a charged pion or kaon or proton or e, continue



	for (int j=0; j < branchdualRICHcfTrack->GetEntries(); ++j)
	{

		dualRICHcfTrack = (Track*)branchdualRICHcfTrack->At(j);
		dualRICHcfTrackP4 = dualRICHcfTrack->P4();
		dualRICHcfTrackZ = (InPr.Dot(dualRICHcfTrackP4)) / (InPr.Dot(InE - OutE));
		particle = (GenParticle*) dualRICHcfTrack->Particle.GetObject();
		if (abs(particle->PID) == abs(dualRICHcfTrack->PID)) {checkmatch = 1;} else {checkmatch = -1;}
		//cout<<"check match="<<checkmatch<<endl;
		//cout<<"true track PID:"<<abs(particle->PID)<<"  PID track PID:"<<abs(dualRICHcfTrack->PID)<<endl;
		PIDnum = abs(particle->PID);
		PIDtrknum = abs(dualRICHcfTrack->PID);



		if (checkmatch == -1) 
		{
			h1checknomatchTrkE->Fill(dualRICHcfTrack->P4().E());
			if (abs(PIDnum) == 211) {h1Pi_checknomatchTrkZ->Fill(dualRICHcfTrackZ); h1Pi_checknomatchTrkE->Fill(dualRICHcfTrack->P4().E());} 
			if (abs(PIDnum) == 321) {h1K_checknomatchTrkZ->Fill(dualRICHcfTrackZ); h1K_checknomatchTrkE->Fill(dualRICHcfTrack->P4().E());} 
			if (abs(PIDnum) == 2212) {h1Pr_checknomatchTrkZ->Fill(dualRICHcfTrackZ); h1Pr_checknomatchTrkE->Fill(dualRICHcfTrack->P4().E());} 
		}

		if (checkmatch == 1) 
		{
			h1checkmatchTrkE->Fill(dualRICHcfTrack->P4().E());
			if (abs(PIDnum) == 211) {h1Pi_checkmatchTrkZ->Fill(dualRICHcfTrackZ); h1Pi_checkmatchTrkE->Fill(dualRICHcfTrack->P4().E());} 
			if (abs(PIDnum) == 321) {h1K_checkmatchTrkZ->Fill(dualRICHcfTrackZ); h1K_checkmatchTrkE->Fill(dualRICHcfTrack->P4().E());} 
			if (abs(PIDnum) == 2212) {h1Pr_checkmatchTrkZ->Fill(dualRICHcfTrackZ); h1Pr_checkmatchTrkE->Fill(dualRICHcfTrack->P4().E());} 
		}
		
		switch (PIDtrknum)
		{
		
			case 11: 
				if (abs(PIDnum) == 211) {h1TruePiPID->Fill(0);} 
				if (abs(PIDnum) == 321) {h1TrueKPID->Fill(0);} 
				if (abs(PIDnum) == 2212) {h1TruePrPID->Fill(0);}
			break;
			
			case 211: 
				
				if (abs(PIDnum) == 211) {h1TruePiPID->Fill(1);} 
				if (abs(PIDnum) == 321) {h1TrueKPID->Fill(1);} 
				if (abs(PIDnum) == 2212) {h1TruePrPID->Fill(1);}
			break;
			
			case 321: 
				if (abs(PIDnum) == 211) {h1TruePiPID->Fill(2);} 
				if (abs(PIDnum) == 321) {h1TrueKPID->Fill(2);} 
				if (abs(PIDnum) == 2212) {h1TruePrPID->Fill(2);}
			break;
			
			case 2212: 
				if (abs(PIDnum) == 211) {h1TruePiPID->Fill(3);} 
				if (abs(PIDnum) == 321) {h1TrueKPID->Fill(3);} 
				if (abs(PIDnum) == 2212) {h1TruePrPID->Fill(3);}
			break;
			
			default: 
				if (abs(PIDnum) == 211) {h1TruePiPID->Fill(4);} 
				if (abs(PIDnum) == 321) {h1TrueKPID->Fill(4);} 
				if (abs(PIDnum) == 2212) {h1TruePrPID->Fill(4);}
			break;
		
		}

	}//PID track

    



  } //event

}




//------------------------------------------------------------------------------




void PrintHistograms(ExRootResult *result, TestPlots *plots)

{

  result->Print("root");

}




//------------------------------------------------------------------------------




void PID_dualRICHcf_checkPIDtrk2(const char *inputFile)

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

