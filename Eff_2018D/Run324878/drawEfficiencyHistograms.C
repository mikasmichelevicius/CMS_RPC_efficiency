#include <sstream>
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"

void drawEfficiencyHistograms(std::string filename){

  gROOT->Reset();
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetPadGridX(true);
  gStyle->SetPadGridY(true);

  TFile *f = new TFile(filename.c_str());
   
  int colorPaletteEff[10];
  colorPaletteEff[0] = 205; 
  colorPaletteEff[1] = 205; 
  colorPaletteEff[2] = kRed; 
  colorPaletteEff[3] = kRed;
  colorPaletteEff[4] = kOrange-3;
  colorPaletteEff[5] = kOrange-3;
  colorPaletteEff[6] = kOrange;
  colorPaletteEff[7] = kOrange; // O
  colorPaletteEff[8] = kYellow; // y
  colorPaletteEff[9] = kGreen; // G
  
  gStyle->SetPalette(10, colorPaletteEff);
  gStyle->SetPaintTextFormat("3.2f");

  std::stringstream ss; 
  TCanvas * cB[5];
  TH1F * hB[5]; 
  for (int w = 0; w<5; w++){
    ss.str("");
    ss<<"CanvasW"<<w-2;
    cB[w] = new TCanvas(ss.str().c_str(),"RPC Efficiency",800, 800);
    cB[w]->SetFillColor(kWhite);
    cB[w]->SetRightMargin(0.13);	//set right margin to have enough place for the Z title

    ss.str("");
    ss<<"Barrel/FiducialCutEffW"<<w-2;
//    ss<<"Barrel/RPCRealOccW"<<w-2;
    hB[w] = (TH1F*)f->Get(ss.str().c_str());
    hB[w]->GetXaxis()->SetNdivisions(-510);
    hB[w]->GetYaxis()->SetNdivisions(-510);
    hB[w]->GetYaxis()->SetLabelSize(0.03);
    hB[w]->GetZaxis()->SetTitle("Efficiency [%]");
    hB[w]->GetZaxis()->SetTitleSize(0.03);
    hB[w]->GetZaxis()->SetLabelSize(0.02);
    hB[w]->Draw("colztext");


   TLine *line = new TLine(0.55,17.5,3.5,17.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(3.5,17.5,3.5,21.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(3.5,21.5,4.5,21.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(4.5,21.5,4.5,17.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(4.5,17.5,8.5, 17.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(8.5,17.5,8.5,15.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(8.5,15.5,9.5,15.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(9.5,15.5,9.5,17.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(9.5,17.5,10.5,17.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(10.5,17.5,10.5,15.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(10.5,15.5,11.5,15.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(11.5,15.5,11.5,17.5);
   line->SetLineWidth(3);
   line->Draw();
   line = new TLine(11.5,17.5,12.5,17.5);
   line->SetLineWidth(3);
   line->Draw();

    std::string outName = std::string(hB[w]->GetName()) + ".png";	//save histogram as a image
    cB[w]->SaveAs(outName.c_str());
    
///////////////////////////////// MY MODIFICATIONS
		vector<string> name_station;
		vector<int> sector_number;
		vector<int> color_chamber;
		vector<int> style_chamber;
		name_station.clear();
		sector_number.clear();
		color_chamber.clear();
		style_chamber.clear();
		
		double size_colorPaletteEff = sizeof(colorPaletteEff)/sizeof(int);
		double range_bin = (hB[w]->GetBinContent(hB[w]->GetMaximumBin()) - hB[w]->GetBinContent(hB[w]->GetMinimumBin()))/size_colorPaletteEff;
		
		for (int i = 1; i < 13; ++i) {
			for (int j = 1; j < 22; ++j) {
				name_station.push_back(hB[w]->GetYaxis()->GetBinLabel(j));
				sector_number.push_back(i);			
				int temp = (hB[w]->GetBinContent(i,j)-hB[w]->GetBinContent(hB[w]->GetMinimumBin()))/range_bin;
				if(temp==size_colorPaletteEff) temp = temp - 1;
				if(hB[w]->GetBinContent(i,j)==0) {color_chamber.push_back(0);} else {color_chamber.push_back(colorPaletteEff[temp]);}
			}
		}
		
		char name_pdf_file[400];
		char name_root_file[400];
		
		if(w==0){
			sprintf(name_root_file,"w-2_plot.root");
			sprintf(name_pdf_file,"w-2_plot.pdf");		
		}
		
		if(w==1){
			sprintf(name_root_file,"w-1_plot.root");
			sprintf(name_pdf_file,"w-1_plot.pdf");		
		}
		if(w==2){
			sprintf(name_root_file,"w0_plot.root");
			sprintf(name_pdf_file,"w0_plot.pdf");		
		}
		if(w==3){
			sprintf(name_root_file,"w+1_plot.root");
			sprintf(name_pdf_file,"w+1_plot.pdf");		
		}
		if(w==4){
			sprintf(name_root_file,"w+2_plot.root");
			sprintf(name_pdf_file,"w+2_plot.pdf");		
		}
		
		TCanvas *c1 = WheelPlot(w, name_station, sector_number, color_chamber, style_chamber);
		c1->SaveAs(name_pdf_file);

		TFile* f_new = TFile::Open(name_root_file,"RECREATE");
		c1->Write("",TObject::kOverwrite);
		f_new->Close();		
/////////////////////////////////     

  }

  TCanvas * cE[8];
  TH1F * hE[8]; 
  int disk = -4;
  for (int d = 0; d<8; d++){

    
    ss.str("");
    ss<<"CanvasD"<<disk;
    cE[d] = new TCanvas(ss.str().c_str(),"RPC Efficiency",1200, 800);
    cE[d]->SetFillColor(kWhite);
    cE[d]->SetRightMargin(0.13);	//set right margin to have enough place for the Z title

    ss.str("");
    ss<<"Endcap/FiducialCutEffD"<<disk;
    hE[d] = (TH1F*)f->Get(ss.str().c_str());
    hE[d]->GetXaxis()->SetNdivisions(-510);
    hE[d]->GetYaxis()->SetNdivisions(-510);
    hE[d]->GetZaxis()->SetTitle("Efficiency [%]");
    hE[d]->GetZaxis()->SetTitleSize(0.03);
    hE[d]->GetZaxis()->SetLabelSize(0.02);
    hE[d]->Draw("colztext90");
    std::string outName = std::string(hE[d]->GetName()) + ".png";	//save histogram as a image
    cE[d]->SaveAs(outName.c_str());
  
///////////////////////////////// MY MODIFICATIONS
		vector<string> name_station;
		vector<int> sector_number;
		vector<int> color_chamber;
		vector<int> style_chamber;
		name_station.clear();
		sector_number.clear();
		color_chamber.clear();
		style_chamber.clear();
		
		double size_colorPaletteEff = sizeof(colorPaletteEff)/sizeof(int);
		double range_bin = (hE[d]->GetBinContent(hE[d]->GetMaximumBin()) - hE[d]->GetBinContent(hE[d]->GetMinimumBin()))/size_colorPaletteEff;
		
		for (int i = 1; i < 37; ++i) {
			for (int j = 1; j < 7; ++j) {
				if(j==1) name_station.push_back("Ring2 C");
				if(j==2) name_station.push_back("Ring2 B");
				if(j==3) name_station.push_back("Ring2 A");
				if(j==4) name_station.push_back("Ring3 C");
				if(j==5) name_station.push_back("Ring3 B");
				if(j==6) name_station.push_back("Ring3 A");
				sector_number.push_back(i);			
				int temp = (hE[d]->GetBinContent(i,j)-hE[d]->GetBinContent(hE[d]->GetMinimumBin()))/range_bin;
				if(temp==size_colorPaletteEff) temp = temp - 1;
				if(hE[d]->GetBinContent(i,j)==0) {color_chamber.push_back(0);} else {color_chamber.push_back(colorPaletteEff[temp]);}
			}
		}
		
		char name_pdf_file[400];
		char name_root_file[400];
		
		if(d==0){
			sprintf(name_root_file,"RE-4_plot.root");
			sprintf(name_pdf_file,"RE-4_plot.pdf");		
		}
		if(d==1){
			sprintf(name_root_file,"RE-3_plot.root");
			sprintf(name_pdf_file,"RE-3_plot.pdf");		
		}
		if(d==2){
			sprintf(name_root_file,"RE-2_plot.root");
			sprintf(name_pdf_file,"RE-2_plot.pdf");		
		}
		if(d==3){
			sprintf(name_root_file,"RE-1_plot.root");
			sprintf(name_pdf_file,"RE-1_plot.pdf");		
		}
		if(d==4){
			sprintf(name_root_file,"RE+1_plot.root");
			sprintf(name_pdf_file,"RE+1_plot.pdf");		
		}
		if(d==5){
			sprintf(name_root_file,"RE+2_plot.root");
			sprintf(name_pdf_file,"RE+2_plot.pdf");		
		}
		if(d==6){
			sprintf(name_root_file,"RE+3_plot.root");
			sprintf(name_pdf_file,"RE+3_plot.pdf");		
		}
		if(d==7){
			sprintf(name_root_file,"RE+4_plot.root");
			sprintf(name_pdf_file,"RE+4_plot.pdf");		
		}
		
		TCanvas *c1 = EndcapPlot(d, name_station, sector_number, color_chamber, style_chamber);
		c1->SaveAs(name_pdf_file);

		TFile* f_new = TFile::Open(name_root_file,"RECREATE");
		c1->Write("",TObject::kOverwrite);
		f_new->Close();		
		
/////////////////////////////////     
    
    disk++;
    if(disk == 0){disk = 1;}
  }

}
