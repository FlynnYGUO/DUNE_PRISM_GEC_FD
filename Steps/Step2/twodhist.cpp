// C++ includes
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

void twodhist_ND()
{
	TFile *input = new TFile("Output_FDGeoEff.root","read");
 	TTree *t = (TTree*)input->Get("effTreeFD");	
	
	double ND_Sim_mu_start_vy;  
  	double ND_Sim_mu_start_vz;
  	
  	t->SetBranchAddress("ND_Sim_mu_start_vy",&ND_Sim_mu_start_vy);
	t->SetBranchAddress("ND_Sim_mu_start_vz",&ND_Sim_mu_start_vz);

	TCanvas *c = new TCanvas();
	gStyle->SetPalette(kRainBow);
	
	TH2F *hist = new TH2F("hist","y vs z after rotation",160,-100,1500,140,-900,500);
	//hist->SetStats(0);	
	
	int n = t->GetEntries();
     	for(int i = 0; i < n; i++)
     	{
     		t->GetEntry(i);
     		hist->Fill(ND_Sim_mu_start_vz,ND_Sim_mu_start_vy);
     	}
     	
     	hist->GetXaxis()->SetTitle("z_axis");
     	hist->GetYaxis()->SetTitle("y_axis");
     	
     	hist->Draw("colz");
}

void twodhist_FD()
{
	TFile *input = new TFile("Step1/myntuple.root","read");
 	TTree *t = (TTree*)input->Get("MyEnergyAnalysis/MyTree");
 	
	int FD_Sim_nMu;
	int FD_CCNC_truth;
	int FD_neuPDG;
	double FD_Sim_n_hadronic_Edep_a;	
	double FD_Sim_mu_start_vy;  
  	double FD_Sim_mu_start_vz;
  	
  	t->SetBranchAddress("Sim_nMu",&FD_Sim_nMu);
	t->SetBranchAddress("CCNC_truth",&FD_CCNC_truth);
	t->SetBranchAddress("neuPDG",&FD_neuPDG);
	t->SetBranchAddress("Sim_n_hadronic_Edep_a",&FD_Sim_n_hadronic_Edep_a);
	t->SetBranchAddress("Sim_mu_start_vy",&FD_Sim_mu_start_vy);
	t->SetBranchAddress("Sim_mu_start_vz",&FD_Sim_mu_start_vz);

	TCanvas *c = new TCanvas();
	gStyle->SetPalette(kRainBow);
	
	TH2F *hist = new TH2F("hist","y vs z after rotation",170,-200,1500,150,-700,800);
	//hist->SetStats(0);	
	
	int n = t->GetEntries();
     	for(int i = 0; i < n; i++)
     	{
     		t->GetEntry(i);
     		if ( FD_Sim_nMu == 0 || FD_Sim_n_hadronic_Edep_a == 0 ) continue;
    		if ( FD_CCNC_truth == 1) continue;   // only use CC events
    		if ( abs(FD_neuPDG) != 14 ) continue;       // only use muon neu
     		hist->Fill(FD_Sim_mu_start_vz,FD_Sim_mu_start_vy);
     	}
     	
     	hist->GetXaxis()->SetTitle("z_axis");
     	hist->GetYaxis()->SetTitle("y_axis");
     	
     	hist->Draw("colz");
}

void NDvsFD()
{
	TFile *input = new TFile("Output_FDGeoEff.root","read");
 	TTree *t = (TTree*)input->Get("effTreeFD");
 	
 	double ND_Sim_mu_start_vy;  
  	double ND_Sim_mu_start_vz;
  	double FD_Sim_mu_start_vy;  
  	double FD_Sim_mu_start_vz;
  	
  	t->SetBranchAddress("ND_Sim_mu_start_vy",&ND_Sim_mu_start_vy);
	t->SetBranchAddress("ND_Sim_mu_start_vz",&ND_Sim_mu_start_vz);
 	t->SetBranchAddress("FD_Sim_mu_start_vy",&FD_Sim_mu_start_vy);
	t->SetBranchAddress("FD_Sim_mu_start_vz",&FD_Sim_mu_start_vz);
 	
 	TCanvas *c = new TCanvas();
 	gStyle->SetOptTitle(kFALSE);
   	gStyle->SetOptStat(0);
   	
 	TH2D *hist1 = new TH2D("hist1","y vs z before rotation",160,-100,1500,160,-900,700);
 	TH2D *hist2 = new TH2D("hist2","y vs z after rotation",160,-100,1500,160,-900,700);
 	int n = t->GetEntries();
     	for(int i = 0; i < 5; i++)
     	{
     		t->GetEntry(i);
     		hist1->Fill(FD_Sim_mu_start_vz,FD_Sim_mu_start_vy);
     		hist2->Fill(ND_Sim_mu_start_vz,ND_Sim_mu_start_vy);
     	}
     	hist1->SetMarkerStyle(8);
     	hist1->SetMarkerColor(kRed);
   	hist2->SetMarkerStyle(22);
   	hist2->SetMarkerColor(kBlue);
   	hist1->GetXaxis()->SetTitle("z_axis");
     	hist1->GetYaxis()->SetTitle("y_axis");
 	hist1->Draw();
        hist2->Draw("same");
 	
 	gPad->BuildLegend();
}	
