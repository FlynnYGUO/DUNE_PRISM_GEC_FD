void FDplot()
{
	gROOT->Reset();
	
	//Read root file
	TFile *input = new TFile("myntuple.root","read");
 	TTree *t = (TTree*)input->Get("MyEnergyAnalysis/MyTree");
 	
	//Make FD ntuple plots into one root file
	TFile * output = new TFile("FDplot.root", "RECREATE");
	
	
	
	//Sim_mu_start_vx
	TCanvas *c1 = new TCanvas("c1","mu start x",700,500);
	c1->Divide(2,2);
	
   	c1->cd(1);
   	TH1D *hist_x1 = new TH1D("hist_x1","mu_start_vx(nMu==0)",100,-200,0);
   	t->Draw("Sim_mu_start_vx >> hist_x1","Sim_nMu == 0");
   	hist_x1->GetXaxis()->SetTitle("Sim_mu_start_vx");
   	hist_x1->Draw();
   	
   	c1->cd(2);
   	TH1D *hist_x2 = new TH1D("hist_x2","mu_start_vx(n_hadronic_Edep_a==0)",500,-500,500);
   	t->Draw("Sim_mu_start_vx >> hist_x2","Sim_n_hadronic_Edep_a == 0");
   	hist_x2->GetXaxis()->SetTitle("Sim_mu_start_vx");
   	hist_x2->Draw();
   	
   	c1->cd(3);
   	TH1D *hist_x3 = new TH1D("hist_x3","mu_start_vx(nMu==0||n_hadronic_Edep_a==0)",500,-500,500);
   	t->Draw("Sim_mu_start_vx >> hist_x3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_x3->GetXaxis()->SetTitle("Sim_mu_start_vx");
   	hist_x3->Draw();
   	
   	c1->cd(4);
   	TH1D *hist_x4 = new TH1D("hist_x4","mu_start_vx(nMu==0&&n_hadronic_Edep_a==0)",100,-200,0);
   	t->Draw("Sim_mu_start_vx >> hist_x4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_x4->GetXaxis()->SetTitle("Sim_mu_start_vx");
   	hist_x4->Draw();
   	
   	//Save into root file
   	c1->Write();
   	c1->Print("FDplots.pdf(","Title:Mu_start_vx");
   	c1->SaveAs("Sim_mu_start_vx.pdf");
   	
   	
   	
   	//Sim_mu_start_vy
	TCanvas *c2 = new TCanvas("c2","mu start y",700,500);
	c2->Divide(2,2);
	
   	c2->cd(1);
   	TH1D *hist_y1 = new TH1D("hist_y1","mu_start_vy(nMu==0)",100,-200,0);
   	t->Draw("Sim_mu_start_vy >> hist_y1","Sim_nMu == 0");
   	hist_y1->GetXaxis()->SetTitle("Sim_mu_start_vy");
   	hist_y1->Draw();
   	
   	c2->cd(2);
   	TH1D *hist_y2 = new TH1D("hist_y2","mu_start_vy(n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Sim_mu_start_vy >> hist_y2","Sim_n_hadronic_Edep_a == 0");
   	hist_y2->GetXaxis()->SetTitle("Sim_mu_start_vy");
   	hist_y2->Draw();
   	
   	c2->cd(3);
   	TH1D *hist_y3 = new TH1D("hist_y3","mu_start_vy(nMu==0||n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Sim_mu_start_vy >> hist_y3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_y3->GetXaxis()->SetTitle("Sim_mu_start_vy");
   	hist_y3->Draw();
   	
   	c2->cd(4);
   	TH1D *hist_y4 = new TH1D("hist_y4","mu_start_vy(nMu==0&&n_hadronic_Edep_a==0)",100,-200,0);
   	t->Draw("Sim_mu_start_vy >> hist_y4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_y4->GetXaxis()->SetTitle("Sim_mu_start_vy");
   	hist_y4->Draw();
   	
   	//Save into root file
   	c2->Write();
   	c2->Print("FDplots.pdf","Title:Mu_start_vy");
   	c2->SaveAs("Sim_mu_start_vy.pdf");
	
	
	
	//Sim_mu_start_vz
	TCanvas *c3 = new TCanvas("c3","mu start z",700,500);
	c3->Divide(2,2);
	
   	c3->cd(1);
   	TH1D *hist_z1 = new TH1D("hist_z1","mu_start_vz(nMu==0)",100,-200,0);
   	t->Draw("Sim_mu_start_vz >> hist_z1","Sim_nMu == 0");
   	hist_z1->GetXaxis()->SetTitle("Sim_mu_start_vz");
   	hist_z1->Draw();
   	
   	c3->cd(2);
   	TH1D *hist_z2 = new TH1D("hist_z2","mu_start_vz(n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Sim_mu_start_vz >> hist_z2","Sim_n_hadronic_Edep_a == 0");
   	hist_z2->GetXaxis()->SetTitle("Sim_mu_start_vz");
   	hist_z2->Draw();
   	
   	c3->cd(3);
   	TH1D *hist_z3 = new TH1D("hist_z3","mu_start_vz(nMu==0||n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Sim_mu_start_vz >> hist_z3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_z3->GetXaxis()->SetTitle("Sim_mu_start_vz");
   	hist_z3->Draw();
   	
   	c3->cd(4);
   	TH1D *hist_z4 = new TH1D("hist_z4","mu_start_vz(nMu==0&&n_hadronic_Edep_a==0)",100,-200,0);
   	t->Draw("Sim_mu_start_vz >> hist_z4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_z4->GetXaxis()->SetTitle("Sim_mu_start_vz");
   	hist_z4->Draw();
   	
   	//Save into root file
   	c3->Write();
   	c3->Print("FDplots.pdf","Title:Mu_start_vz");
   	c3->SaveAs("Sim_mu_start_vz.pdf");
   	
   	
   	//True neutrino interaction vertex x
	TCanvas *c4 = new TCanvas("c4","Nuvtxx_truth",700,500);
	c4->Divide(2,2);
	
   	c4->cd(1);
   	TH1D *hist_vx1 = new TH1D("hist_vx1","Nuvtxx_truth(nMu==0)",500,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx1","Sim_nMu == 0");
   	hist_vx1->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx1->Draw();
   	
   	c4->cd(2);
   	TH1D *hist_vx2 = new TH1D("hist_vx2","Nuvtxx_truth(n_hadronic_Edep_a==0)",500,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx2","Sim_n_hadronic_Edep_a == 0");
   	hist_vx2->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx2->Draw();
   	
   	c4->cd(3);
   	TH1D *hist_vx3 = new TH1D("hist_vx3","Nuvtxx_truth(nMu==0||n_hadronic_Edep_a==0)",500,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_vx3->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx3->Draw();
   	
   	c4->cd(4);
   	TH1D *hist_vx4 = new TH1D("hist_vx4","Nuvtxx_truth(nMu==0&&n_hadronic_Edep_a==0)",500,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_vx4->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx4->Draw();
   	
   	//Save into root file
   	c4->Write();
   	c4->Print("FDplots.pdf","Title:Nuvtxx_truth");
   	c4->SaveAs("Nuvtxx_truth.pdf");
   	
   	
   	//True neutrino interaction vertex y
	TCanvas *c5 = new TCanvas("c5","Nuvtxy_truth",700,500);
	c5->Divide(2,2);
	
   	c5->cd(1);
   	TH1D *hist_vy1 = new TH1D("hist_vy1","Nuvtxy_truth(nMu==0)",800,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy1","Sim_nMu == 0");
   	hist_vy1->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy1->Draw();
   	
   	c5->cd(2);
   	TH1D *hist_vy2 = new TH1D("hist_vy2","Nuvtxy_truth(n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy2","Sim_n_hadronic_Edep_a == 0");
   	hist_vy2->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy2->Draw();
   	
   	c5->cd(3);
   	TH1D *hist_vy3 = new TH1D("hist_vy3","Nuvtxy_truth(nMu==0||n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_vy3->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy3->Draw();
   	
   	c5->cd(4);
   	TH1D *hist_vy4 = new TH1D("hist_vy4","Nuvtxy_truth(nMu==0&&n_hadronic_Edep_a==0)",800,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_vy4->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy4->Draw();
   	
   	//Save into root file
   	c5->Write();
   	c5->Print("FDplots.pdf","Title:Nuvtxy_truth");
   	c5->SaveAs("Nuvtxy_truth.pdf");
   	
   	
   	//True neutrino interaction vertex z
	TCanvas *c6 = new TCanvas("c6","Nuvtxz_truth",700,500);
	c6->Divide(2,2);
	
   	c6->cd(1);
   	TH1D *hist_vz1 = new TH1D("hist_vz1","Nuvtxz_truth(nMu==0)",900,-200,1600);
   	t->Draw("Nuvtxz_truth >> hist_vz1","Sim_nMu == 0");
   	hist_vz1->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz1->Draw();
   	
   	c6->cd(2);
   	TH1D *hist_vz2 = new TH1D("hist_vz2","Nuvtxz_truth(n_hadronic_Edep_a==0)",900,-200,1600);
   	t->Draw("Nuvtxz_truth >> hist_vz2","Sim_n_hadronic_Edep_a == 0");
   	hist_vz2->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz2->Draw();
   	
   	c6->cd(3);
   	TH1D *hist_vz3 = new TH1D("hist_vz3","Nuvtxz_truth(nMu==0||n_hadronic_Edep_a==0)",900,-200,1600);
   	t->Draw("Nuvtxz_truth >> hist_vz3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_vz3->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz3->Draw();
   	
   	c6->cd(4);
   	TH1D *hist_vz4 = new TH1D("hist_vz4","Nuvtxz_truth(nMu==0&&n_hadronic_Edep_a==0)",900,-200,1600);
   	t->Draw("Nuvtxz_truth >> hist_vz4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_vz4->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz4->Draw();
   	
   	//Save into root file
   	c6->Write();
   	c6->Print("FDplots.pdf)","Title:Nuvtxz_truth");
   	c6->SaveAs("Nuvtxz_truth.pdf");
   	
   	

	
	
	
	
} 

