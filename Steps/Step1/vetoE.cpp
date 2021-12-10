// C++ includes
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;
void vetoE()
{
	gROOT->Reset();
	
	// Read root file
	TFile *input = new TFile("Output_FDGeoEff.root","read");
 	TTree *t = (TTree*)input->Get("effTreeFD");
 	
 	// Extract branch
 	float VetoEnergyFD;
 	t->SetBranchAddress("VetoEnergyFD",&VetoEnergyFD);
 	
 	// Plot the histogram
     	TCanvas *c = new TCanvas("c","VetoEnergyFD",1500,500);
     	c->Divide(2,1);
     	
     	c->cd(1);
     	TH1F *hist = new TH1F("hist","VetoEnergyFD",70,0,1400);
   	t->Draw("VetoEnergyFD >> hist");
   	hist->GetXaxis()->SetTitle("VetoEnergyFD");
   	hist->Draw();
   	
   	
   	c->cd(2);
	TH1F *hist2 = new TH1F("hist2","VetoEnergyFD<30",4,0,40);
	   		
   	int n = t->GetEntries();
   	for(int i = 0; i < n; i++)
   	{
	   	t->GetEntry(i);
	   	if( VetoEnergyFD < 30 )
	   	{
	   		hist2->Fill(VetoEnergyFD);	   		
	   	}
   	}
   	
   	hist2->GetXaxis()->SetTitle("VetoEnergyFD");
	hist2->Draw();
	
	c->SaveAs("VetoEnergyFD.pdf");
}
