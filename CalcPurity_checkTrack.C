void CalcPurity_checkTrack(TString inputFile, const char* PIDSystem,  Int_t ID)
{

	TFile* MyFile = TFile::Open(inputFile);

	TH2D* Pi_goodE=MyFile->Get("h1Pi_checkmatchTrkE");
        TH2D* K_goodE=MyFile->Get("h1K_checkmatchTrkE");
        TH2D* Pr_goodE=MyFile->Get("h1Pr_checkmatchTrkE");

        TH2D* Pi_badE=MyFile->Get("h1Pi_checknomatchTrkE");
        TH2D* K_badE=MyFile->Get("h1K_checknomatchTrkE");
        TH2D* Pr_badE=MyFile->Get("h1Pr_checknomatchTrkE");

	TH2D* Pi_goodZ=MyFile->Get("h1Pi_checkmatchTrkZ");
        TH2D* K_goodZ=MyFile->Get("h1K_checkmatchTrkZ");
        TH2D* Pr_goodZ=MyFile->Get("h1Pr_checkmatchTrkZ");

        TH2D* Pi_badZ=MyFile->Get("h1Pi_checknomatchTrkZ");
        TH2D* K_badZ=MyFile->Get("h1K_checknomatchTrkZ");
        TH2D* Pr_badZ=MyFile->Get("h1Pr_checknomatchTrkZ");

	TFile *result_file;
	result_file = new TFile(TString::Format("purity_%s_%d.root",PIDSystem,ID),"recreate");
	
	int Ebin=100;
	int Zbin=20;
	if (PIDSystem == "dualRICHag")
	{int Ebin=50;double Emin=0.; double Emax=12.;}

	if (PIDSystem == "dualRICHcf")
        {double Emin=12.; double Emax=50.;}	

	if (PIDSystem == "barrelDIRCTrack")
	{double Emin=0.; double Emax=50.;}
	
	TH1D *h1Pi_resultE= new TH1D("h1Pi_resultE","Pion Purity by track energy; E [GeV]",Ebin,Emin,Emax);
        TH1D *h1K_resultE= new TH1D("h1K_resultE","Kaon Purity by track energy; E [GeV]",Ebin,Emin,Emax);
        TH1D *h1Pr_resultE= new TH1D("h1Pr_resultE","proton Purity by track energy; E [GeV]",Ebin,Emin,Emax);
	TH1D *h1Pi_resultZ= new TH1D("h1Pi_resultZ","Pion Purity by energy fraction z; z",Zbin,0.,1.);
        TH1D *h1K_resultZ= new TH1D("h1K_resultZ","Kaon Purity by energy fraction z; z",Zbin,0.,1.);
        TH1D *h1Pr_resultZ= new TH1D("h1Pr_resultZ","proton Purity by energy fraction z; z",Zbin,0.,1.);


	for (Int_t i=1; i<=Ebin ; ++i)
        {

		Double_t ngood=0;
		Double_t nbad=0;
		ngood=Pi_goodE->GetBinContent(i);
                nbad=Pi_badE->GetBinContent(i);
		if ((ngood + nbad) == 0) {Double_t purity=0;} else {Double_t purity=ngood / (ngood+ nbad);}
                h1Pi_resultE->SetBinContent(i,purity);

		Double_t ngood=0;
                Double_t nbad=0;
                ngood=K_goodE->GetBinContent(i);
                nbad=K_badE->GetBinContent(i);
                if ((ngood + nbad) == 0) {Double_t purity=0;} else {Double_t purity=ngood / (ngood+ nbad);}
                h1K_resultE->SetBinContent(i,purity);

		Double_t ngood=0;
                Double_t nbad=0;
                ngood=Pr_goodE->GetBinContent(i);
                nbad=Pr_badE->GetBinContent(i);
                if ((ngood + nbad) == 0) {Double_t purity=0;} else {Double_t purity=ngood / (ngood+ nbad);}
                h1Pr_resultE->SetBinContent(i,purity);

        }


	for (Int_t i=1; i<=Zbin ; ++i)
        {

		Double_t ngood=0;
		Double_t nbad=0;
		ngood=Pi_goodZ->GetBinContent(i);
                nbad=Pi_badZ->GetBinContent(i);
		if ((ngood + nbad) == 0) {Double_t purity=0;} else {Double_t purity=ngood / (ngood+ nbad);}
                h1Pi_resultZ->SetBinContent(i,purity);

		Double_t ngood=0;
                Double_t nbad=0;
                ngood=K_goodZ->GetBinContent(i);
                nbad=K_badZ->GetBinContent(i);
                if ((ngood + nbad) == 0) {Double_t purity=0;} else {Double_t purity=ngood / (ngood+ nbad);}
                h1K_resultZ->SetBinContent(i,purity);

		Double_t ngood=0;
                Double_t nbad=0;
                ngood=Pr_goodZ->GetBinContent(i);
                nbad=Pr_badZ->GetBinContent(i);
                if ((ngood + nbad) == 0) {Double_t purity=0;} else {Double_t purity=ngood / (ngood+ nbad);}
                h1Pr_resultZ->SetBinContent(i,purity);

        }

	h1Pi_resultE->SetMinimum(0);
	h1K_resultE->SetMinimum(0);
	h1Pr_resultE->SetMinimum(0);
	h1Pi_resultE->Draw();
        h1K_resultE->Draw();
        h1Pr_resultE->Draw();

	h1Pi_resultZ->SetMinimum(0);
	h1K_resultZ->SetMinimum(0);
	h1Pr_resultZ->SetMinimum(0);
	h1Pi_resultZ->Draw();
        h1K_resultZ->Draw();
        h1Pr_resultZ->Draw();

	result_file->Write();
	result_file->Close();
}
