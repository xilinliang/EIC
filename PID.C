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

    TH2 *h2Pi_purity_vs_z;
    TH2 *h2Pi_purity_vs_z_E10_20;
    TH2 *h2Pi_purity_vs_z_E20_40;
    TH2 *h2Pi_purity_vs_z_E40_60;
    TH2 *h2Pi_purity_vs_z_E60_80;
    TH2 *h2Pi_purity_vs_E;

    TH2 *h2K_purity_vs_z;
    TH2 *h2K_purity_vs_z_E10_20;
    TH2 *h2K_purity_vs_z_E20_40;
    TH2 *h2K_purity_vs_z_E40_60;
    TH2 *h2K_purity_vs_z_E60_80;
    TH2 *h2K_purity_vs_E;

    TH2 *h2Pr_purity_vs_z;
    TH2 *h2Pr_purity_vs_z_E10_20;
    TH2 *h2Pr_purity_vs_z_E20_40;
    TH2 *h2Pr_purity_vs_z_E40_60;
    TH2 *h2Pr_purity_vs_z_E60_80;
    TH2 *h2Pr_purity_vs_E;

    TH2 *h2E_purity_vs_z;
    TH2 *h2E_purity_vs_z_E10_20;
    TH2 *h2E_purity_vs_z_E20_40;
    TH2 *h2E_purity_vs_z_E40_60;
    TH2 *h2E_purity_vs_z_E60_80;
    TH2 *h2E_purity_vs_E;

//  TH1 *fElectronDeltaPT;
//
//  TH1 *fElectronDeltaEta;
//
//  TH1 *fJetDeltaPT;
//
//  TH1 *hjt;
//
//  TH1 *hphi;
//
//  TH1 *hz;
//
//  TH1 *hr;
//
//
//
//
//  TH1 *asym;
//
//  TH1 *asym_smeared;
//
//  
//
//  TH1 *res_dphi_04_06;
//
//  TH1 *res_dphi_01_02;  
//
//  TH2 *res_dphi_z_10_20;
//
//  TH2 *res_dphi_z_20_40;
//
//  TH2 *res_dphi_z_40_60;
//
//  TH2 *res_dphi_z_60_80;
//
//  TH1 *res_dphi_diffz_10_20[16];
//
//  TH1 *res_dphi_diffz_20_30[16];
//
//  TH1 *res_dphi_diffz_30_40[16];
//
//  TH1 *res_dphi_diffz_40_50[16];
//
//  TH1 *res_dphi_diffz_50_60[16];
//
//  TH1 *res_dphi_diffz_60_70[16];
//
//  TH1 *res_dphi_diffz_70_80[16];
//
//  TH1 *res_dz_diffphi_10_20[16];
//
//  TH1 *res_dz_diffphi_20_30[16];
//
//  TH1 *res_dz_diffphi_30_40[16];
// 
//  TH1 *res_dz_diffphi_40_50[16];
//
//  TH1 *res_dz_diffphi_50_60[16];
//
//  TH1 *res_dz_diffphi_60_70[16];
//
//  TH1 *res_dz_diffphi_70_80[16];
//
//  TH2 *h2_trackresolution_vs_p;
//
//  TH1 *mom_res;
//
//  TH2 *h2_trackresolution_vs_p_S;
//
//  TH1 *mom_res_S;

};




//------------------------------------------------------------------------------




void BookHistograms(ExRootResult *result, TestPlots *plots)

{

  TLegend *legend;

  TPaveText *comment;

  plots->h1matchTrkZ = result->AddHist1D("h1matchTrkZ","match track fraction z","z","events",20,0,1);
  plots->h1matchTrkE = result->AddHist1D("h1matchTrkE","match track energy","E [GeV]","events",100,10,80);

  plots->h1nomatchTrkZ = result->AddHist1D("h1nomatchTrkZ","no match track fraction z","z","events",20,0,1);
  plots->h1nomatchTrkE = result->AddHist1D("h1nomatchTrkE","no match track energy","E [GeV]","events",100,10,80);


  plots->h1Pi_purity = result->AddHist1D("h1Pi_purity","Pion purity" , "pion purity" , "events" , 20,0,1.01);
  plots->h2Pi_purity_vs_z = result->AddHist2D("h2Pi_purity_vs_z","Pion purity vs z" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E10_20 = result->AddHist2D("h2Pi_purity_vs_z_E10_20","Pion purity vs z (10 < E < 20 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E20_40 = result->AddHist2D("h2Pi_purity_vs_z_E20_40","Pion purity vs z (20 < E < 40 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E40_60 = result->AddHist2D("h2Pi_purity_vs_z_E40_60","Pion purity vs z (40 < E < 60 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_z_E60_80 = result->AddHist2D("h2Pi_purity_vs_z_E60_80","Pion purity vs z (60 < E < 80 GeV)" , "z" , "pion purity"  , 20,0,1,20,0,1.01);
  plots->h2Pi_purity_vs_E = result->AddHist2D("h2Pi_purity_vs_E","Pion purity vs jet E","jet E [GeV]","pion purity",80,10,90,20,0,1.01);


  plots->h1K_purity = result->AddHist1D("h1K_purity","Kaon purity" , "kaon purity" , "events" , 20,0,1.01);
  plots->h2K_purity_vs_z = result->AddHist2D("h2K_purity_vs_z","Kaon purity vs z" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E10_20 = result->AddHist2D("h2K_purity_vs_z_E10_20","Kaon purity vs z (10 < E < 20 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E20_40 = result->AddHist2D("h2K_purity_vs_z_E20_40","Kaon purity vs z (20 < E < 40 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E40_60 = result->AddHist2D("h2K_purity_vs_z_E40_60","Kaon purity vs z (40 < E < 60 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_z_E60_80 = result->AddHist2D("h2K_purity_vs_z_E60_80","Kaon purity vs z (60 < E < 80 GeV)" , "z" , "Kaon purity"  , 20,0,1,20,0,1.01);
  plots->h2K_purity_vs_E = result->AddHist2D("h2K_purity_vs_E","Kaon purity vs jet E","jet E [GeV]","Kaon purity",80,10,90,20,0,1.01);

  plots->h1Pr_purity = result->AddHist1D("h1Pr_purity","Proton purity" , "proton purity" , "events" , 20,0,1.01);
  plots->h2Pr_purity_vs_z = result->AddHist2D("h2Pr_purity_vs_z","(anti)proton purity vs z" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E10_20 = result->AddHist2D("h2Pr_purity_vs_z_E10_20","(anti)proton purity vs z (10 < E < 20 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E20_40 = result->AddHist2D("h2Pr_purity_vs_z_E20_40","(anti)proton purity vs z (20 < E < 40 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E40_60 = result->AddHist2D("h2Pr_purity_vs_z_E40_60","(anti)proton purity vs z (40 < E < 60 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_z_E60_80 = result->AddHist2D("h2Pr_purity_vs_z_E60_80","(anti)proton purity vs z (60 < E < 80 GeV)" , "z" , "(anti)proton purity"  , 20,0,1,20,0,1.01);
  plots->h2Pr_purity_vs_E = result->AddHist2D("h2Pr_purity_vs_E","Proton purity vs jet E","jet E [GeV]","proton purity",80,10,90,20,0,1.01);

  plots->h1E_purity = result->AddHist1D("h1E_purity","electron purity" , "electron purity" , "events" , 20,0,1.01);
  plots->h2E_purity_vs_z = result->AddHist2D("h2E_purity_vs_z","electron (positron) purity vs z" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E10_20 = result->AddHist2D("h2E_purity_vs_z_E10_20","electron (positron) purity vs z (10 < E < 20 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E20_40 = result->AddHist2D("h2E_purity_vs_z_E20_40","electron (positron) purity vs z (20 < E < 40 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E40_60 = result->AddHist2D("h2E_purity_vs_z_E40_60","electron (positron) purity vs z (40 < E < 60 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_z_E60_80 = result->AddHist2D("h2E_purity_vs_z_E60_80","electron (positron) purity vs z (60 < E < 80 GeV)" , "z" , "electron (positron) purity"  , 20,0,1,20,0,1.01);
  plots->h2E_purity_vs_E = result->AddHist2D("h2E_purity_vs_E","electron purity vs jet E","jet E [GeV]","electron purity",80,10,90,20,0,1.01);

//  plots->fElectronDeltaPT = result->AddHist1D(
//
//    "electron_delta_pt", "(p_{T}^{particle} - p_{T}^{electron})/p_{T}^{particle}",
//
//    "(p_{T}^{particle} - p_{T}^{electron})/p_{T}^{particle}", "number of electrons",
//
//    100, -0.1, 0.1);
//
//
//
//
//  plots->fElectronDeltaEta = result->AddHist1D(
//
//    "electron_delta_eta", "(#eta^{particle} - #eta^{electron})/#eta^{particle}",
//
//    "(#eta^{particle} - #eta^{electron})/#eta^{particle}", "number of electrons",
//
//    100, -0.1, 0.1);
//
//
//
//
//  plots->fJetDeltaPT = result->AddHist1D(
//
//    "jet_delta_pt", "(p_{T}^{jet} - p_{T}^{constituents})/p_{T}^{jet}",
//
//    "(p_{T}^{jet} - p_{T}^{constituents})/p_{T}^{jet}", "number of jets",
//
//    100, -1.0e-1, 1.0e-1);
//
//
//
//
//
//
//
//  plots->hjt  = result->AddHist1D("jt", "", "jt " , "entries",50,0,3.0);
//
//  plots->hz   = result->AddHist1D("z", ""," z " , "entries",50,0,1.0);
//
//  plots->hphi = result->AddHist1D("phi", "", "phi " , "entries",180,-6.0,9.0);
//
//  plots->hr   = result->AddHist1D("r", "" , "z", "entries", 50, 0,1.0);
//
//  plots->asym = result->AddHist1D("asym", "Generated asymmetry", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries" , 13,-TMath::Pi(),TMath::Pi());
//
//  plots->asym_smeared = result->AddHist1D("asym_smeared", "Reconstructed asymmetry", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries",  13,-TMath::Pi(),TMath::Pi());
//
//  
//
//  double mindphi = TMath::Pi()/2.0;
//
//  plots->res_dphi_04_06 = result->AddHist1D("dphi_res_04_06", "Collins Angle resolution, 40 < E_{jet} < 60 GeV and 0.4<z<0.6", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries", 100,-TMath::Pi(),TMath::Pi());
//
//  plots->res_dphi_01_02 = result->AddHist1D("dphi_res_01_02", "Collins Angle resolution, 40 < E_{jet} < 60 GeV and 0.1<z<0.2", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "entries", 100,-TMath::Pi(),TMath::Pi());
//
//  
//
//  plots->res_dphi_z_10_20 = result->AddHist2D("dphi_res_z_10_20", "Collins Angle resolution, 10 <E_{jet}< 20 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51, -mindphi,mindphi, 10,0.0,1.0);
//
//  plots->res_dphi_z_20_40 = result->AddHist2D("dphi_res_z_20_40", "Collins Angle resolution, 20 <E_{jet}< 40 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51,-mindphi, mindphi, 10,0.0,1.0); 
//
//  plots->res_dphi_z_40_60 = result->AddHist2D("dphi_res_z_40_60", "Collins Angle resolution, 40 <E_{jet}< 60 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51, -mindphi, mindphi, 10,0.0,1.0); 
//
//  plots->res_dphi_z_60_80 = result->AddHist2D("dphi_res_z_60_80", "Collins Angle resolution, 60 <E_{jet}< 80 GeV", "#phi_{C}^{gen}-#phi_{C}^{reco} [rad]", "generated z", 51, -mindphi, mindphi, 10,0.0,1.0); 
//
//  plots->h2_trackresolution_vs_p = result->AddHist2D("h2_trackresolution_vs_p","hadron resolution vs gen hadron p","p_{gen hadron} [GeV]","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]",80,0,80,80,-2,2);
//
//  plots->mom_res = result->AddHist1D("mom_res","momentum resolution","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]","",80,-2,2);
//
//plots->h2_trackresolution_vs_p_S = result->AddHist2D("h2_trackresolution_vs_p_S","hadron resolution vs gen hadron p","p_{gen hadron} [GeV]","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]",50,0,20,60,-0.5,0.5);
//
//  plots->mom_res_S = result->AddHist1D("mom_res_S","momentum resolution","(p_{gen hadron} - p_{hadron})/p_{gen hadron} [GeV]","",60,-0.5,0.5);
//
//
//  char name_hist[100];
//  char title_hist[100];
//  for (int i=0;i<16;i=i+1)
//  {
//
//	sprintf(name_hist,"dphi_z_%i_%i_1020",i*8,(i+1)*8);
//	plots->res_dphi_diffz_10_20[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//	sprintf(name_hist,"dphi_z_%i_%i_2030",i*8,(i+1)*8);
//        plots->res_dphi_diffz_20_30[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//	sprintf(name_hist,"dphi_z_%i_%i_3040",i*8,(i+1)*8);
//        plots->res_dphi_diffz_30_40[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//	sprintf(name_hist,"dphi_z_%i_%i_4050",i*8,(i+1)*8);
//        plots->res_dphi_diffz_40_50[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//	sprintf(name_hist,"dphi_z_%i_%i_5060",i*8,(i+1)*8);
//        plots->res_dphi_diffz_50_60[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//	sprintf(name_hist,"dphi_z_%i_%i_6070",i*8,(i+1)*8);
//        plots->res_dphi_diffz_60_70[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//	sprintf(name_hist,"dphi_z_%i_%i_7080",i*8,(i+1)*8);
//        plots->res_dphi_diffz_70_80[i] = result->AddHist1D(name_hist,name_hist,"#phi_{C}^{gen}-#phi_{C}^{reco} [rad]","event",70,-TMath::Pi(),TMath::Pi());
//
//
//	sprintf(title_hist,"dz_phi_%i_1020",i);
//	sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_1020",i-8,(i-7));
//        plots->res_dz_diffphi_10_20[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//	sprintf(title_hist,"dz_phi_%i_2030",i);
//        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_2030",i-8,(i-7));
//        plots->res_dz_diffphi_20_30[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//	sprintf(title_hist,"dz_phi_%i_3040",i);
//        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_3040",i-8,(i-7));
//        plots->res_dz_diffphi_30_40[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//	sprintf(title_hist,"dz_phi_%i_4050",i);
//        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_4050",i-8,(i-7));
//        plots->res_dz_diffphi_40_50[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//	sprintf(title_hist,"dz_phi_%i_5060",i);
//        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_5060",i-8,(i-7));
//        plots->res_dz_diffphi_50_60[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//	sprintf(title_hist,"dz_phi_%i_6070",i);
//        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_6070",i-8,(i-7));
//        plots->res_dz_diffphi_60_70[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//	sprintf(title_hist,"dz_phi_%i_7080",i);
//        sprintf(name_hist,"dz_phi_%i/8#pi_%i/8#pi_7080",i-8,(i-7));
//        plots->res_dz_diffphi_70_80[i] = result->AddHist1D(title_hist,name_hist,"z_{C}^{gen}-z_{C}^{reco} [rad]","event",70,-1,1);
//
//
//  }

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

  TClonesArray *branchPIDSystemsTrack = treeReader->UseBranch("PIDSystemsTrack"); 

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




  TLorentzVector momentum;




  Float_t Eem, Ehad;

  Bool_t skip;




  Long64_t entry;




  Int_t i, j, pdgCode;

	
  Int_t nPi_PID , nPi_true , nK_PID , nK_true , nPr_PID , nPr_true, nE_PID , nE_true;

  Int_t Pi_PID[30] ,Pi_true[30] , K_PID[30] , K_true[30] , Pr_PID[30] , Pr_true[30] , E_PID[30] , E_true[30];

  Int_t matchPi_PID , matchPr_PID , matchK_PID ,matchE_PID ;
  Double_t Pi_purity, Pr_purity, K_purity, E_purity;

  // Loop over all events




  TF1 *f1 = new TF1("f1","1+0.05*sin(x)",-TMath::Pi(),TMath::Pi());
 
  int njets = 0;
  int PIDnum = 0;

//  char name_hist[100];
//  int i=1;
//  sprintf(name_hist,"dphi_z_%i_%i_E_10_20",i*5,(i+1)*5);
//  cout<<name_hist<<endl;

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


    //loop for all Hcal tracks
    for (int i = 0; i < branchEFlowTrack->GetEntries(); ++i) {
      EFlowTrack = (Track*)branchEFlowTrack->At(i);

      if (EFlowTrack->PT < 0.1 || TMath::Abs(EFlowTrack->Eta) > 3.5) continue;

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


//	cout<< "PID num true " << PIDnum << endl;
   }

//	trk_in.trk = EFlowTrack;
//      true_tracks.push_back(trk_in);
    

    //loop for all PID system tracks
    for (int i = 0; i < branchPIDSystemsTrack->GetEntries(); ++i) {
      PIDSystemsTrack = (Track*)branchPIDSystemsTrack->At(i);

      if (PIDSystemsTrack->PT < 0.1 || TMath::Abs(PIDSystemsTrack->Eta) > 3.5) continue;

	PIDnum = PIDSystemsTrack->PID;

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
	
//	cout<< "PID num PID " << PIDnum << endl;

    }

//    cout << "nPr_true: " << nPr_true << " nPr_PID: "<<nPr_PID << endl;
//    cout << "nPi_true: " << nPi_true << " nPi_PID: "<<nPi_PID << endl;    
//    cout << "nK_true: " << nK_true << " nK_PID: "<<nK_PID << endl;
//    cout << "nE_true: " << nE_true << " nE_PID: "<<nE_PID << endl;


//    cout<<"matchPi_PID: "<<matchPi_PID<<" nPi_true:"<<nPi_true<<endl;


    // Loop over all jets in event

    for(int i = 0; i < branchJet->GetEntriesFast(); ++i)

    {

      jet = (Jet*) branchJet->At(i);

      if(jet->PT<10.0) continue;


      float deltaR = 999;


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



//
//      // cout<<"Looping over jet constituents. Jet pt: "<<jet->PT<<", eta: "<<jet->Eta<<", phi: "<<jet->Phi<<endl;
//
//
//
//
//      // Loop over all jet's constituents
//

	int NTrack=0;

	int totalPi=0; matchPi_PID = 0; Pi_purity = -1;
	int totalK=0; matchK_PID = 0; K_purity = -1;
	int totalPr=0; matchPr_PID = 0; Pr_purity = -1;
	int totalE=0; matchE_PID = 0; E_purity = -1;

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
	
		  	if(!(abs(track->PID)==211 || abs(track->PID)==321 || abs(track->PID)==2212 || abs(track->PID)==11)) continue; //if not a charged pion or kaon or proton or e, continue
	
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

			int isMatch=0;
	
			//find PID systenm pion match
			if (abs(track->PID) == 211)
			{
				totalPi=totalPi+1;
				for (int PIDi=0;PIDi < nPi_PID;++PIDi)
				{
	
					PIDSystemsTrack = (Track*)branchPIDSystemsTrack->At(Pi_PID[PIDi]);
					if (track->Particle == PIDSystemsTrack->Particle) {isMatch = 1;++matchPi_PID;}
	
				}
			}
	
			//kaon
			if (abs(track->PID) == 321)
	                {
	                        totalK=totalK+1;
	                        for (int PIDi=0;PIDi < nK_PID;++PIDi)
	                        {
	
	                                PIDSystemsTrack = (Track*)branchPIDSystemsTrack->At(K_PID[PIDi]);
	                                if (track->Particle == PIDSystemsTrack->Particle) {isMatch = 1;++matchK_PID;}
	
	                        }
	                }
	
			//proton
			if (abs(track->PID) == 2212)
	                {
	                        totalPr=totalPr+1;
	                        for (int PIDi=0;PIDi < nPr_PID;++PIDi)
	                        {
	
	                                PIDSystemsTrack = (Track*)branchPIDSystemsTrack->At(Pr_PID[PIDi]);
	                                if (track->Particle == PIDSystemsTrack->Particle) {isMatch = 1; ++matchPr_PID;}
	
	                        }
	                }
	
			//electron
			if (abs(track->PID) == 11)
	                {
	                        totalE=totalE+1;
	                        for (int PIDi=0;PIDi < nE_PID;++PIDi)
	                        {
	
	                                PIDSystemsTrack = (Track*)branchPIDSystemsTrack->At(E_PID[PIDi]);
	                                if (track->Particle == PIDSystemsTrack->Particle) {isMatch =1; ++matchE_PID;}
	
	                        }
	                }
	
		  //cout << jet->P4().Vect().Mag() << endl;
	
		  //cout << track->P4().Vect().Mag() << endl;
	
		  
	
		  //cout << " " << endl;
	
		  	TVector3 crossproduct = jet->P4().Vect().Unit().Cross(track->P4().Vect().Unit());
	
	          //cout << "Cross product " << crossproduct.Mag() << endl;
	
		  //cout << "angle " << TMath::ASin(crossproduct.Mag()) << endl;  
	
		  
	
		  	double sin = crossproduct.Mag()/(jet->P4().Vect().Mag());
	
		    
	
		  	double z = jet->P4().Vect().Dot( track->P4().Vect() )/(jet->P4().P()*jet->P4().P());
	
	          //if( !(z>0.4 and z<0.6)) continue;

		if (isMatch == 1) 
		{
			h1matchTrkZ->Fill(z); 
			h1matchTrkE->Fill(track->P4().E());
		}
		else
		{
			h1nomatchTrkZ->Fill(z);
                        h1nomatchTrkE->Fill(track->P4().E());
		}

		}
	}

		double jetE = jet->P4().E();

		if (totalPi > 0) Pi_purity = (double) matchPi_PID / totalPi;

                if (Pi_purity > -1) {h2Pi_purity_vs_E->Fill(jetE,Pi_purity);h1Pi_purity->Fill(Pi_purity);}

                if (totalPr > 0) Pr_purity = (double) matchPi_PID / totalPr;
                if (Pr_purity > -1) {h2Pr_purity_vs_E->Fill(jetE,Pr_purity); h1Pr_purity->Fill(Pr_purity);}

                if (totalK > 0) K_purity = (double) matchK_PID / totalK;

                if (K_purity > -1) {h2K_purity_vs_E->Fill(jetE,K_purity); h1K_purity->Fill(K_purity);}

                if (totalE > 0) E_purity = (double) matchE_PID / totalE;
                if (E_purity > -1) {h2E_purity_vs_E->Fill(jetE,E_purity); h1E_purity->Fill(E_purity);}

//		if (jetE > 10 && jetE < 20)
//		{
//			h2Pi_purity_vs_z_E10_20->Fill(z,Pi_purity);
//			h2K_purity_vs_z_E10_20->Fill(z,K_purity);
//			h2Pr_purity_vs_z_E10_20->Fill(z,Pr_purity);
//			h2E_purity_vs_z_E10_20->Fill(z,E_purity);
//		}
//
//		if (jetE > 20 && jetE < 40)
//                {
//                        h2Pi_purity_vs_z_E20_40->Fill(z,Pi_purity);
//                        h2K_purity_vs_z_E20_40->Fill(z,K_purity);
//                        h2Pr_purity_vs_z_E20_40->Fill(z,Pr_purity);
//                        h2E_purity_vs_z_E20_40->Fill(z,E_purity);
//                }
//
//		if (jetE > 40 && jetE < 60)
//                {
//                        h2Pi_purity_vs_z_E40_60->Fill(z,Pi_purity);
//                        h2K_purity_vs_z_E40_60->Fill(z,K_purity);
//                        h2Pr_purity_vs_z_E40_60->Fill(z,Pr_purity);
//                        h2E_purity_vs_z_E40_60->Fill(z,E_purity);
//                }
//
//		if (jetE > 60 && jetE < 80)
//                {
//                        h2Pi_purity_vs_z_E60_80->Fill(z,Pi_purity);
//                        h2K_purity_vs_z_E60_80->Fill(z,K_purity);
//                        h2Pr_purity_vs_z_E60_80->Fill(z,Pr_purity);
//                        h2E_purity_vs_z_E60_80->Fill(z,E_purity);
//                }


//          	double r = TMath::Sqrt( pow(jet->P4().Phi() - track->P4().Phi(),2.0) + pow(jet->P4().Eta() - track->P4().Eta(),2.0));
//
//	  	TVector3 zaxis(0,0,1.01);
//
//          	TVector3 N = zaxis.Cross(jet->P4().Vect());
//
//	  	TVector3 S = N.Cross(jet->P4().Vect());
//
//	  	N = N.Unit();
//
//	  	S = S.Unit();

//	  	TVector3 jt  = track->P4().Vect().Dot(N)*N + track->P4().Vect().Dot(S)*S;
//
//          	double angle = track->P4().Vect().Dot(N)/track->P4().Vect().Dot(S);	  
//
//          	double phi_h = TMath::ATan(angle); 

	  //cout << "asd" << jt.Unit().Dot(jet->P4().Vect()) << endl;

	  //double phi_h = TMath::ACos(jt.Unit().Dot(N.Unit()));

	  //std::cout << jet->P4().Vect().Cross(  track->P4().Vect() ) / (ptrack*p)  << endl;

          //double phi_h = TMath::ASin(jet->P4().Vect().Cross(  track->P4().Vect() ) / (ptrack*p));

          //cout<< sin << endl;

	    // double phi_h =crossproduct.Mag();// TMath::ASin(sin);


	


	      

      




      
//
//      plots->fJetDeltaPT->Fill((jet->PT - momentum.Pt())/jet->PT);

    }

  }

}




//------------------------------------------------------------------------------




void PrintHistograms(ExRootResult *result, TestPlots *plots)

{

  result->Print("root");

}




//------------------------------------------------------------------------------




void PID(const char *inputFile)

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

