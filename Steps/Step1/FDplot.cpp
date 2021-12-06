void FDplot()
{
	gROOT->Reset();
	
	//Read root file
	TFile *input = new TFile("myntuple.root","read");
 	TTree *t = (TTree*)input->Get("MyEnergyAnalysis/MyTree");
 	
	//Make FD ntuple plots into one root file
	TFile * output = new TFile("FDplot.root", "RECREATE");
	
	
	
	/*
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
   	*/
   	
   	
   	//True neutrino interaction vertex x
	TCanvas *c4 = new TCanvas("c4","Nuvtxx_truth",1200,600);
	c4->Divide(3,2);
	
   	c4->cd(1);
   	TH1D *hist_vx1 = new TH1D("hist_vx1","Nuvtxx_truth(nMu==0)",20,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx1","Sim_nMu == 0");
   	hist_vx1->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx1->Draw();
   	
   	c4->cd(2);
   	TH1D *hist_vx2 = new TH1D("hist_vx2","Nuvtxx_truth(n_hadronic_Edep_a==0)",20,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx2","Sim_n_hadronic_Edep_a == 0");
   	hist_vx2->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx2->Draw();
   	
   	c4->cd(4);
   	TH1D *hist_vx3 = new TH1D("hist_vx3","Nuvtxx_truth(nMu==0||n_hadronic_Edep_a==0)",20,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_vx3->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx3->Draw();
   	
   	c4->cd(3);
   	TH1D *hist_vx4 = new TH1D("hist_vx4","Nuvtxx_truth(nMu==0&&n_hadronic_Edep_a==0)",20,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_vx4->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx4->Draw();
   	
   	c4->cd(5);
   	TH1D *hist_vx5 = new TH1D("hist_vx5","Nuvtxx_truth(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",20,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_vx5->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx5->Draw();
   	
   	c4->cd(6);
   	TH1D *hist_vx6 = new TH1D("hist_vx6","Nuvtxx_truth(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",20,-500,500);
   	t->Draw("Nuvtxx_truth >> hist_vx6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_vx6->GetXaxis()->SetTitle("Nuvtxx_truth");
   	hist_vx6->Draw();
   	
   	//Save into root file
   	c4->Write();
   	c4->Print("FDplots.pdf(","Title:Nuvtxx_truth");
   	c4->SaveAs("Nuvtxx_truth.pdf");
   	
   	
   	//True neutrino interaction vertex y
	TCanvas *c5 = new TCanvas("c5","Nuvtxy_truth",1200,600);
	c5->Divide(3,2);
	
   	c5->cd(1);
   	TH1D *hist_vy1 = new TH1D("hist_vy1","Nuvtxy_truth(nMu==0)",32,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy1","Sim_nMu == 0");
   	hist_vy1->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy1->Draw();
   	
   	c5->cd(2);
   	TH1D *hist_vy2 = new TH1D("hist_vy2","Nuvtxy_truth(n_hadronic_Edep_a==0)",32,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy2","Sim_n_hadronic_Edep_a == 0");
   	hist_vy2->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy2->Draw();
   	
   	c5->cd(4);
   	TH1D *hist_vy3 = new TH1D("hist_vy3","Nuvtxy_truth(nMu==0||n_hadronic_Edep_a==0)",32,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_vy3->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy3->Draw();
   	
   	c5->cd(3);
   	TH1D *hist_vy4 = new TH1D("hist_vy4","Nuvtxy_truth(nMu==0&&n_hadronic_Edep_a==0)",32,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_vy4->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy4->Draw();
   	
   	c5->cd(5);
   	TH1D *hist_vy5 = new TH1D("hist_vy5","Nuvtxy_truth(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0)))",32,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_vy5->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy5->Draw();
   	
   	c5->cd(6);
   	TH1D *hist_vy6 = new TH1D("hist_vy6","Nuvtxy_truth(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0)))",32,-800,800);
   	t->Draw("Nuvtxy_truth >> hist_vy6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_vy6->GetXaxis()->SetTitle("Nuvtxy_truth");
   	hist_vy6->Draw();
   	
   	//Save into root file
   	c5->Write();
   	c5->Print("FDplots.pdf","Title:Nuvtxy_truth");
   	c5->SaveAs("Nuvtxy_truth.pdf");
   	
   	
   	//True neutrino interaction vertex z
	TCanvas *c6 = new TCanvas("c6","Nuvtxz_truth",1200,600);
	c6->Divide(3,2);
	
   	c6->cd(1);
   	TH1D *hist_vz1 = new TH1D("hist_vz1","Nuvtxz_truth(nMu==0)",32,-100,1500);
   	t->Draw("Nuvtxz_truth >> hist_vz1","Sim_nMu == 0");
   	hist_vz1->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz1->Draw();
   	
   	c6->cd(2);
   	TH1D *hist_vz2 = new TH1D("hist_vz2","Nuvtxz_truth(n_hadronic_Edep_a==0)",32,-100,1500);
   	t->Draw("Nuvtxz_truth >> hist_vz2","Sim_n_hadronic_Edep_a == 0");
   	hist_vz2->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz2->Draw();
   	
   	c6->cd(4);
   	TH1D *hist_vz3 = new TH1D("hist_vz3","Nuvtxz_truth(nMu==0||n_hadronic_Edep_a==0)",32,-100,1500);
   	t->Draw("Nuvtxz_truth >> hist_vz3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_vz3->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz3->Draw();
   	
   	c6->cd(3);
   	TH1D *hist_vz4 = new TH1D("hist_vz4","Nuvtxz_truth(nMu==0&&n_hadronic_Edep_a==0)",32,-100,1500);
   	t->Draw("Nuvtxz_truth >> hist_vz4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_vz4->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz4->Draw();
   	
   	c6->cd(5);
   	TH1D *hist_vz5 = new TH1D("hist_vz5","Nuvtxz_truth(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",32,-100,1500);
   	t->Draw("Nuvtxz_truth >> hist_vz5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_vz5->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz5->Draw();
   	
   	c6->cd(6);
   	TH1D *hist_vz6 = new TH1D("hist_vz6","Nuvtxz_truth(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",32,-100,1500);
   	t->Draw("Nuvtxz_truth >> hist_vz6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_vz6->GetXaxis()->SetTitle("Nuvtxz_truth");
   	hist_vz6->Draw();
   	
   	//Save into root file
   	c6->Write();
   	c6->Print("FDplots.pdf","Title:Nuvtxz_truth");
   	c6->SaveAs("Nuvtxz_truth.pdf");
   	
   	
   	
   	//True neutrino interaction CCNC
	TCanvas *c7 = new TCanvas("c7","CCNC",800,600);
	c7->Divide(2,2);
	
   	c7->cd(1);
   	TH1D *hist_ccnc1 = new TH1D("hist_ccnc1","CCNC_truth(nMu==0)",2,0,2);
   	t->Draw("CCNC_truth >> hist_ccnc1","Sim_nMu == 0");
   	hist_ccnc1->GetXaxis()->SetTitle("CCNC_truth");
   	hist_ccnc1->Draw();
   	
   	c7->cd(2);
   	TH1D *hist_ccnc2 = new TH1D("hist_ccnc2","CCNC_truth(n_hadronic_Edep_a==0)",2,0,2);
   	t->Draw("CCNC_truth >> hist_ccnc2","Sim_n_hadronic_Edep_a == 0");
   	hist_ccnc2->GetXaxis()->SetTitle("CCNC_truth");
   	hist_ccnc2->Draw();
   	
   	c7->cd(4);
   	TH1D *hist_ccnc4 = new TH1D("hist_ccnc4","CCNC_truth(nMu==0&&n_hadronic_Edep_a==0)",2,0,2);
   	t->Draw("CCNC_truth >> hist_ccnc4","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_ccnc4->GetXaxis()->SetTitle("CCNC_truth");
   	hist_ccnc4->Draw();
   	
   	c7->cd(3);
   	TH1D *hist_ccnc3 = new TH1D("hist_ccnc3","CCNC_truth(nMu==0||n_hadronic_Edep_a==0)",2,0,2);
   	t->Draw("CCNC_truth >> hist_ccnc3","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_ccnc3->GetXaxis()->SetTitle("CCNC_truth");
   	hist_ccnc3->Draw();
   	
   	//Save into root file
   	c7->Write();
   	c7->Print("FDplots.pdf","Title:CCNC_truth");
   	c7->SaveAs("CCNC.pdf");
   	
   	
   	
   	//True neutrino interaction Mode
	TCanvas *c8 = new TCanvas("c8","Mode",1200,600);
	c8->Divide(3,2);
	
   	c8->cd(1);
   	TH1D *hist_mode1 = new TH1D("hist_mode1","Mode_truth(nMu==0)",16,-2,14);
   	t->Draw("Mode_truth >> hist_mode1","Sim_nMu == 0");
   	hist_mode1->GetXaxis()->SetTitle("Mode_truth");
   	hist_mode1->Draw();
   	
   	c8->cd(2);
   	TH1D *hist_mode2 = new TH1D("hist_mode2","Mode_truth(n_hadronic_Edep_a==0)",16,-2,14);
   	t->Draw("Mode_truth >> hist_mode2","Sim_n_hadronic_Edep_a == 0");
   	hist_mode2->GetXaxis()->SetTitle("Mode_truth");
   	hist_mode2->Draw();
   	
   	c8->cd(3);
   	TH1D *hist_mode3 = new TH1D("hist_mode3","Mode_truth(nMu==0&&n_hadronic_Edep_a==0)",16,-2,14);
   	t->Draw("Mode_truth >> hist_mode3","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_mode3->GetXaxis()->SetTitle("Mode_truth");
   	hist_mode3->Draw();
   	
   	c8->cd(4);
   	TH1D *hist_mode4 = new TH1D("hist_mode4","Mode_truth(nMu==0||n_hadronic_Edep_a==0)",16,-2,14);
   	t->Draw("Mode_truth >> hist_mode4","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_mode4->GetXaxis()->SetTitle("Mode_truth");
   	hist_mode4->Draw();
   	
   	c8->cd(5);
   	TH1D *hist_mode5 = new TH1D("hist_mode5","Mode_truth(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",16,-2,14);
   	t->Draw("Mode_truth >> hist_mode5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_mode5->GetXaxis()->SetTitle("Mode_truth");
   	hist_mode5->Draw();
   	
   	c8->cd(6);
   	TH1D *hist_mode6 = new TH1D("hist_mode6","Mode_truth(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",16,-2,14);
   	t->Draw("Mode_truth >> hist_mode6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_mode6->GetXaxis()->SetTitle("Mode_truth");
   	hist_mode6->Draw();
   	
   	//Save into root file
   	c8->Write();
   	c8->Print("FDplots.pdf","Title:Mode_truth");
   	c8->SaveAs("Mode.pdf");
   	
   	
   	
   	
   	//True neutrino interaction type
	TCanvas *c9 = new TCanvas("c9","InteractionType",1200,600);
	c9->Divide(3,2);
	
   	c9->cd(1);
   	TH1D *hist_IT1 = new TH1D("hist_IT1","InteractionType(nMu==0)",110,990,1100);
   	t->Draw("InteractionType >> hist_IT1","Sim_nMu == 0");
   	hist_IT1->GetXaxis()->SetTitle("InteractionType");
   	hist_IT1->Draw();
   	
   	c9->cd(2);
   	TH1D *hist_IT2 = new TH1D("hist_IT2","InteractionType(n_hadronic_Edep_a==0)",110,990,1100);
   	t->Draw("InteractionType >> hist_IT2","Sim_n_hadronic_Edep_a == 0");
   	hist_IT2->GetXaxis()->SetTitle("InteractionType");
   	hist_IT2->Draw();
   	
   	c9->cd(3);
   	TH1D *hist_IT3 = new TH1D("hist_IT3","InteractionType(nMu==0&&n_hadronic_Edep_a==0)",110,990,1100);
   	t->Draw("InteractionType >> hist_IT3","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_IT3->GetXaxis()->SetTitle("InteractionType");
   	hist_IT3->Draw();
   	
   	c9->cd(4);
   	TH1D *hist_IT4 = new TH1D("hist_IT4","InteractionType(nMu==0||n_hadronic_Edep_a==0)",110,990,1100);
   	t->Draw("InteractionType >> hist_IT4","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_IT4->GetXaxis()->SetTitle("InteractionType");
   	hist_IT4->Draw();
   	
   	c9->cd(5);
   	TH1D *hist_IT5 = new TH1D("hist_IT5","InteractionType(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",110,990,1100);
   	t->Draw("InteractionType >> hist_IT5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_IT5->GetXaxis()->SetTitle("InteractionType");
   	hist_IT5->Draw();
   	
   	c9->cd(6);
   	TH1D *hist_IT6 = new TH1D("hist_IT6","InteractionType(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",110,990,1100);
   	t->Draw("InteractionType >> hist_IT6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_IT6->GetXaxis()->SetTitle("InteractionType");
   	hist_IT6->Draw();
   	
   	//Save into root file
   	c9->Write();
   	c9->Print("FDplots.pdf","Title:InteractionType");
   	c9->SaveAs("InteractionType_truth.pdf");
   	
   	
   	
   	//Sim neutrino interaction momentum x
	TCanvas *c10 = new TCanvas("c10","Sim_mu_start_px",1200,600);
	c10->Divide(3,2);
	
   	c10->cd(1);
   	TH1D *hist_px1 = new TH1D("hist_px1","Sim_mu_start_px(nMu==0)",60,-110,10);
   	t->Draw("Sim_mu_start_px >> hist_px1","Sim_nMu == 0");
   	hist_px1->GetXaxis()->SetTitle("Sim_mu_start_px");
   	hist_px1->Draw();
   	
   	c10->cd(2);
   	TH1D *hist_px2 = new TH1D("hist_px2","Sim_mu_start_px(n_hadronic_Edep_a==0)",60,-110,10);
   	t->Draw("Sim_mu_start_px >> hist_px2","Sim_n_hadronic_Edep_a == 0");
   	hist_px2->GetXaxis()->SetTitle("Sim_mu_start_px");
   	hist_px2->Draw();
   	
   	c10->cd(3);
   	TH1D *hist_px3 = new TH1D("hist_px3","Sim_mu_start_px(nMu==0&&n_hadronic_Edep_a==0)",60,-110,10);
   	t->Draw("Sim_mu_start_px >> hist_px3","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_px3->GetXaxis()->SetTitle("Sim_mu_start_px");
   	hist_px3->Draw();
   	
   	c10->cd(4);
   	TH1D *hist_px4 = new TH1D("hist_px4","Sim_mu_start_px(nMu==0||n_hadronic_Edep_a==0)",60,-110,10);
   	t->Draw("Sim_mu_start_px >> hist_px4","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_px4->GetXaxis()->SetTitle("Sim_mu_start_px");
   	hist_px4->Draw();
   	
   	c10->cd(5);
   	TH1D *hist_px5 = new TH1D("hist_px5","Sim_mu_start_px(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",60,-110,10);
   	t->Draw("Sim_mu_start_px >> hist_px5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_px5->GetXaxis()->SetTitle("Sim_mu_start_px");
   	hist_px5->Draw();
   	
   	c10->cd(6);
   	TH1D *hist_px6 = new TH1D("hist_px6","Sim_mu_start_px(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",60,-110,10);
   	t->Draw("Sim_mu_start_px >> hist_px6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_px6->GetXaxis()->SetTitle("Sim_mu_start_px");
   	hist_px6->Draw();
   	
   	//Save into root file
   	c10->Write();
   	c10->Print("FDplots.pdf","Title:Sim_mu_start_px");
   	c10->SaveAs("Sim_mu_start_px.pdf");
   	
   	
   	
   	//Sim neutrino interaction momentum y
	TCanvas *c11 = new TCanvas("c11","Sim_mu_start_py",1200,600);
	c11->Divide(3,2);
	
   	c11->cd(1);
   	TH1D *hist_py1 = new TH1D("hist_py1","Sim_mu_start_py(nMu==0)",60,-110,10);
   	t->Draw("Sim_mu_start_py >> hist_py1","Sim_nMu == 0");
   	hist_py1->GetXaxis()->SetTitle("Sim_mu_start_py");
   	hist_py1->Draw();
   	
   	c11->cd(2);
   	TH1D *hist_py2 = new TH1D("hist_py2","Sim_mu_start_py(n_hadronic_Edep_a==0)",60,-110,10);
   	t->Draw("Sim_mu_start_py >> hist_py2","Sim_n_hadronic_Edep_a == 0");
   	hist_py2->GetXaxis()->SetTitle("Sim_mu_start_py");
   	hist_py2->Draw();
   	
   	c11->cd(3);
   	TH1D *hist_py3 = new TH1D("hist_py3","Sim_mu_start_py(nMu==0&&n_hadronic_Edep_a==0)",60,-110,10);
   	t->Draw("Sim_mu_start_py >> hist_py3","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_py3->GetXaxis()->SetTitle("Sim_mu_start_py");
   	hist_py3->Draw();
   	
   	c11->cd(4);
   	TH1D *hist_py4 = new TH1D("hist_py4","Sim_mu_start_py(nMu==0||n_hadronic_Edep_a==0)",60,-110,10);
   	t->Draw("Sim_mu_start_py >> hist_py4","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_py4->GetXaxis()->SetTitle("Sim_mu_start_py");
   	hist_py4->Draw();
   	
   	c11->cd(5);
   	TH1D *hist_py5 = new TH1D("hist_py5","Sim_mu_start_py(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",60,-110,10);
   	t->Draw("Sim_mu_start_py >> hist_py5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_py5->GetXaxis()->SetTitle("Sim_mu_start_py");
   	hist_py5->Draw();
   	
   	c11->cd(6);
   	TH1D *hist_py6 = new TH1D("hist_py6","Sim_mu_start_py(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",60,-110,10);
   	t->Draw("Sim_mu_start_py >> hist_py6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_py6->GetXaxis()->SetTitle("Sim_mu_start_py");
   	hist_py6->Draw();
   	
   	//Save into root file
   	c11->Write();
   	c11->Print("FDplots.pdf","Title:Sim_mu_start_py");
   	c11->SaveAs("Sim_mu_start_py.pdf");
   	
   	
   	
   	//Sim neutrino interaction momentum z
	TCanvas *c12= new TCanvas("c12","Sim_mu_start_pz",1200,600);
	c12->Divide(3,2);
	
   	c12->cd(1);
   	TH1D *hist_pz1 = new TH1D("hist_pz1","Sim_mu_start_pz(nMu==0)",90,-110,70);
   	t->Draw("Sim_mu_start_pz >> hist_pz1","Sim_nMu == 0");
   	hist_pz1->GetXaxis()->SetTitle("Sim_mu_start_pz");
   	hist_pz1->Draw();
   	
   	c12->cd(2);
   	TH1D *hist_pz2 = new TH1D("hist_pz2","Sim_mu_start_pz(n_hadronic_Edep_a==0)",90,-110,70);
   	t->Draw("Sim_mu_start_pz >> hist_pz2","Sim_n_hadronic_Edep_a == 0");
   	hist_pz2->GetXaxis()->SetTitle("Sim_mu_start_pz");
   	hist_pz2->Draw();
   	
   	c12->cd(3);
   	TH1D *hist_pz3 = new TH1D("hist_pz3","Sim_mu_start_pz(nMu==0&&n_hadronic_Edep_a==0)",90,-110,70);
   	t->Draw("Sim_mu_start_pz >> hist_pz3","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_pz3->GetXaxis()->SetTitle("Sim_mu_start_pz");
   	hist_pz3->Draw();
   	
   	c12->cd(4);
   	TH1D *hist_pz4 = new TH1D("hist_pz4","Sim_mu_start_pz(nMu==0||n_hadronic_Edep_a==0)",90,-110,70);
   	t->Draw("Sim_mu_start_pz >> hist_pz4","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_pz4->GetXaxis()->SetTitle("Sim_mu_start_pz");
   	hist_pz4->Draw();
   	
   	c12->cd(5);
   	TH1D *hist_pz5 = new TH1D("hist_pz5","Sim_mu_start_pz(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",90,-110,70);
   	t->Draw("Sim_mu_start_pz >> hist_pz5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_pz5->GetXaxis()->SetTitle("Sim_mu_start_pz");
   	hist_pz5->Draw();
   	
   	c12->cd(6);
   	TH1D *hist_pz6 = new TH1D("hist_pz6","Sim_mu_start_pz(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",90,-110,70);
   	t->Draw("Sim_mu_start_pz >> hist_pz6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_pz6->GetXaxis()->SetTitle("Sim_mu_start_pz");
   	hist_pz6->Draw();
   	
   	//Save into root file
   	c12->Write();
   	c12->Print("FDplots.pdf","Title:Sim_mu_start_pz");
   	c12->SaveAs("Sim_mu_start_pz.pdf");
   	

	
	//True neutrino interaction energy 
	TCanvas *c13 = new TCanvas("c13","Gen_numu_E",1200,600);
	c13->Divide(3,2);
	
   	c13->cd(1);
   	TH1D *hist_e1 = new TH1D("hist_e1","Gen_numu_E(nMu==0)",50,-10,90);
   	t->Draw("Gen_numu_E >> hist_e1","Sim_nMu == 0");
   	hist_e1->GetXaxis()->SetTitle("Gen_numu_E");
   	hist_e1->Draw();
   	
   	c13->cd(2);
   	TH1D *hist_e2 = new TH1D("hist_e2","Gen_numu_E(n_hadronic_Edep_a==0)",50,-10,90);
   	t->Draw("Gen_numu_E >> hist_e2","Sim_n_hadronic_Edep_a == 0");
   	hist_e2->GetXaxis()->SetTitle("Gen_numu_E");
   	hist_e2->Draw();
   	
   	c13->cd(3);
   	TH1D *hist_e3 = new TH1D("hist_e3","Gen_numu_E(nMu==0&&n_hadronic_Edep_a==0)",50,-10,90);
   	t->Draw("Gen_numu_E >> hist_e3","Sim_nMu == 0 && Sim_n_hadronic_Edep_a == 0");
   	hist_e3->GetXaxis()->SetTitle("Gen_numu_E");
   	hist_e3->Draw();
   	
   	c13->cd(4);
   	TH1D *hist_e4 = new TH1D("hist_e4","Gen_numu_E(nMu==0||n_hadronic_Edep_a==0)",50,-10,90);
   	t->Draw("Gen_numu_E >> hist_e4","Sim_nMu == 0 || Sim_n_hadronic_Edep_a == 0");
   	hist_e4->GetXaxis()->SetTitle("Gen_numu_E");
   	hist_e4->Draw();
   	
   	c13->cd(5);
   	TH1D *hist_e5 = new TH1D("hist_e5","Gen_numu_E(CCNC_truth==0&&(nMu==0||n_hadronic_Edep_a==0))",50,-10,90);
   	t->Draw("Gen_numu_E >> hist_e5","CCNC_truth==0&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_e5->GetXaxis()->SetTitle("Gen_numu_E");
   	hist_e5->Draw();
   	
   	c13->cd(6);
   	TH1D *hist_e6 = new TH1D("hist_e6","Gen_numu_E(CCNC_truth==1&&(nMu==0||n_hadronic_Edep_a==0))",50,-10,90);
   	t->Draw("Gen_numu_E >> hist_e6","CCNC_truth==1&&(Sim_nMu==0||Sim_n_hadronic_Edep_a==0)");
   	hist_e6->GetXaxis()->SetTitle("Gen_numu_E");
   	hist_e6->Draw();
   	
   	//Save into root file
   	c13->Write();
   	c13->Print("FDplots.pdf)","Title:Gen_numu_E");
   	c13->SaveAs("Gen_numu_E.pdf");
	
	
} 

