// NtupleCounter
	
// C++ includes
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

// Read histograms from a ROOT file

// Read InteractionType
void NtupleCounter_InteractionType() 
{
	// Open root file
	TFile *input = new TFile("myntuple.root","read");
 	TTree *t = (TTree*)input->Get("MyEnergyAnalysis/MyTree");
     	
     	// Choose elements
     	int InteractionType;
     	t->SetBranchAddress("InteractionType",&InteractionType);
     	
     	// Plot the histogram
     	TCanvas *c = new TCanvas("c","InteractionType",700,500);
     	TH1I *hist = new TH1I("hist","InteractionType",2,0,2);
     	c->cd();
   	t->Draw("InteractionType >> hist");
   	hist->GetXaxis()->SetTitle("InteractionType");
   	hist->Draw();
   	c->SaveAs("InteractionType.pdf");
     	
     	// Set empty list
     	vector<int> ItrcType = {};	// Original
     	vector<int> ItrcType_c = {};	// Clone
     	
     	// Put elements in ntuple into vector list
     	int n = t->GetEntries();
     	for(int i = 0; i < n; i++)
     	{
     		t->GetEntry(i);
     		ItrcType.insert(ItrcType.begin() + i, InteractionType);
     		ItrcType_c.insert(ItrcType_c.begin() + i, InteractionType);
     		//cout << "i="<< i << "\t" << "InteractionType:" << InteractionType << endl;
     	}
     	
     	// Check the list
     	/*
     	cout<< "num:"<< ItrcType_c.size() <<endl;
     	for(int i = 0; i < ItrcType_c.size(); i++)
	{
		cout<< "num:"<< ItrcType_c[i]<<endl;
	}
	*/
	
	// Sort this vector
	sort(ItrcType_c.begin(), ItrcType_c.end());
	
	// Manipulate the original vector list, delete repeated elements and store into cloned vector list
	for(int i = 1; i < ItrcType_c.size(); i++) {
    		if (ItrcType_c[i] == ItrcType_c[i - 1]) 
    		{
      		  ItrcType_c.erase(ItrcType_c.begin() + i);
       		 i--;
    		}
	}
	
	// Count the new list's size
	cout << "Total number of repeated elements in InteractionType is: " << ItrcType_c.size()<<endl;
	
	// Count the number of occurrences of each element in the original list
	for(int i = 0; i < ItrcType_c.size(); i++)
	{
		int numOccurrences = count(ItrcType.begin(), ItrcType.end(), ItrcType_c[i]);
		cout << ItrcType_c[i] << " appeared " << numOccurrences << " times" << endl;
	}	     	
}



// Read CCNC
void NtupleCounter_CCNC() 
{
	// Open root file
	TFile *input = new TFile("myntuple.root","read");
 	TTree *t = (TTree*)input->Get("MyEnergyAnalysis/MyTree");
     	
     	// Choose elements
     	int CCNC_truth;
     	t->SetBranchAddress("CCNC_truth",&CCNC_truth);
     	
     	// Plot the histogram
     	TCanvas *c = new TCanvas("c","CCNC_truth",700,500);
     	TH1I *hist = new TH1I("hist","CCNC_truth",2,0,2);
     	c->cd();
   	t->Draw("CCNC_truth >> hist");
   	hist->GetXaxis()->SetTitle("CCNC_truth");
   	hist->Draw();
   	c->SaveAs("CCNC_truth.pdf");
     	
     	// Set empty list
     	vector<int> CCNC = {};	// Original
     	vector<int> CCNC_c = {};	// Clone
     	
     	// Put elements in ntuple into vector list
     	int n = t->GetEntries();
     	for(int i = 0; i < n; i++)
     	{
     		t->GetEntry(i);
     		CCNC.insert(CCNC.begin() + i, CCNC_truth);
     		CCNC_c.insert(CCNC_c.begin() + i, CCNC_truth);
     	}

	// Sort this vector
	sort(CCNC_c.begin(), CCNC_c.end());
	
	// Manipulate the original vector list, delete repeated elements and store into cloned vector list
	for(int i = 1; i < CCNC_c.size(); i++) {
    		if (CCNC_c[i] == CCNC_c[i - 1]) 
    		{
      		  CCNC_c.erase(CCNC_c.begin() + i);
       		 i--;
    		}
	}
	
	// Count the new list's size
	cout << "Total number of repeated elements in CCNC is: " << CCNC_c.size()<<endl;
	
	// Count the number of occurrences of each element in the original list
	for(int i = 0; i < CCNC_c.size(); i++)
	{
		int numOccurrences = count(CCNC.begin(), CCNC.end(), CCNC_c[i]);
		cout << CCNC_c[i] << " appeared " << numOccurrences << " times" << endl;
	}	     	
}



// Read Mode
void NtupleCounter_Mode() 
{
	// Open root file
	TFile *input = new TFile("myntuple.root","read");
 	TTree *t = (TTree*)input->Get("MyEnergyAnalysis/MyTree");
     	
     	// Choose elements
     	int Mode_truth;
     	t->SetBranchAddress("Mode_truth",&Mode_truth);
     	
     	// Plot the histogram
     	TCanvas *c = new TCanvas("c","Mode_truth",700,500);
     	TH1I *hist = new TH1I("hist","Mode_truth",2,0,2);
     	c->cd();
   	t->Draw("Mode_truth >> hist");
   	hist->GetXaxis()->SetTitle("Mode_truth");
   	hist->Draw();
   	c->SaveAs("Mode_truth.pdf");
     	
     	// Set empty list
     	vector<int> Mode = {};	// Original
     	vector<int> Mode_c = {};	// Clone
     	
     	// Put elements in ntuple into vector list
     	int n = t->GetEntries();
     	for(int i = 0; i < n; i++)
     	{
     		t->GetEntry(i);
     		Mode.insert(Mode.begin() + i, Mode_truth);
     		Mode_c.insert(Mode_c.begin() + i, Mode_truth);
     	}

	// Sort this vector
	sort(Mode_c.begin(), Mode_c.end());
	
	// Manipulate the original vector list, delete repeated elements and store into cloned vector list
	for(int i = 1; i < Mode_c.size(); i++) {
    		if (Mode_c[i] == Mode_c[i - 1]) 
    		{
      		  Mode_c.erase(Mode_c.begin() + i);
       		 i--;
    		}
	}
	
	// Count the new list's size
	cout << "Total number of repeated elements in Mode is: " << Mode_c.size()<<endl;
	
	// Count the number of occurrences of each element in the original list
	for(int i = 0; i < Mode_c.size(); i++)
	{
		int numOccurrences = count(Mode.begin(), Mode.end(), Mode_c[i]);
		cout << Mode_c[i] << " appeared " << numOccurrences << " times" << endl;
	}	     	
}
