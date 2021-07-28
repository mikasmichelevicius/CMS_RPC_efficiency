#include <TCanvas.h>


TPolyLine *makeBoxEC(float radius = 1., float angle_degree = 0., float xinc = 0.01, string pos = "none", int ring = 1){
   float PI = 3.141592653589793;
   Double_t yinc = 0.06;
   
   if((pos=="U" || pos=="D" || pos=="C") && ring==1) yinc = yinc*(1./3.+0.02);
   if(pos=="U" && ring==1) yinc = yinc*1.005;
   if(pos=="C" && ring==1) yinc = yinc*1.016;
   if(pos=="U" && ring==1) {radius = radius + 4.5*yinc; xinc = xinc*1.22;}
   if(pos=="C" && ring==1) xinc = xinc*1.1;
   if(pos=="D" && ring==1) {radius = radius - 4.5*yinc;  xinc = xinc*0.98;}

   if((pos=="U" || pos=="D" || pos=="C") && ring==2) yinc = yinc*(1./3.+0.02);
   if(pos=="U" && ring==2) yinc = yinc*0.98;
   if(pos=="C" && ring==2) yinc = yinc*0.98;
   if(pos=="U" && ring==2) {radius = radius + 4.69*yinc; xinc = xinc*1.39;}
   if(pos=="C" && ring==2) {radius = radius + 0.03*yinc; xinc = xinc*1.18;}
   if(pos=="D" && ring==2) {radius = radius - 4.5*yinc;  xinc = xinc*0.96;} 
   
   Double_t angle_radian = angle_degree * (PI/180.0);
   Double_t theta = atan(yinc/xinc);
   Double_t hyp = sqrt(yinc*yinc + xinc*xinc);
   Double_t radius_new = radius*0.4;
   Double_t centerX = 0.5+radius_new*sin(-angle_radian);
   Double_t centerY = 0.5+radius_new*cos(-angle_radian);
   Double_t theta_new = theta - 9.*(PI/180.0);


   Double_t x[5] = {centerX-hyp*(cos(angle_radian+theta)),
	  centerX+hyp*(cos(-angle_radian+theta)), 
	  centerX+hyp*(cos(angle_radian+theta_new)),
	  centerX-hyp*(cos(-angle_radian+theta_new)),
	  centerX-hyp*(cos(angle_radian+theta))};
	                
   Double_t y[5] = {centerY-hyp*(sin(angle_radian+theta)),
	  centerY-hyp*(sin(-angle_radian+theta)),
	  centerY+hyp*(sin(angle_radian+theta_new)),
	  centerY+hyp*(sin(-angle_radian+theta_new)),
	  centerY-hyp*(sin(angle_radian+theta))};	    
	   


   TPolyLine *pline = new TPolyLine(5,x,y);

  
   return pline;
}


	
TCanvas *EndcapPlot(int d, vector<string> name_station, vector<int> sector_number, vector<int> color_chamber, vector<int> style_chamber, bool just_one_chamber=false, TCanvas * c2 = 0){
//void EndcapPlot(){
	
  gStyle->SetOptStat(0);
  float PI = 3.141592653589793;
   auto c1 = new TCanvas("c1","c1",4000,4000);
   Double_t layer_1_pos = 0.95;
   Double_t layer_2_pos = 0.64;
   Double_t layer_3_pos = 0.55;


   
   char center_E[400];
   if(d==0)	sprintf(center_E,"RE-4"); 
   if(d==1)	sprintf(center_E,"RE-3"); 
   if(d==2)	sprintf(center_E,"RE-2"); 
   if(d==3)	sprintf(center_E,"RE-1"); 
   if(d==4)	sprintf(center_E,"RE+1"); 
   if(d==5)	sprintf(center_E,"RE+2"); 
   if(d==6)	sprintf(center_E,"RE+3"); 
   if(d==7)	sprintf(center_E,"RE+4"); 
 
   TText *tcenter = new TText(0.46,0.5,center_E);
   tcenter->SetTextFont(43);
   tcenter->SetTextSize(150);
   tcenter->Draw();

   vector<TPolyLine*> chambers_boxes;
   vector<string> chambers_names;
   vector<int> chambers_sector;

	double size_x = 0.025;
	double size_x_2 = 0.014;

   
   TPolyLine *pline10_1 = makeBoxEC(layer_1_pos,(1*10. -5.),size_x);
   pline10_1->Draw();
   TPolyLine *pline10_1_1 = makeBoxEC(layer_1_pos,(1*10. -5.),size_x,"U");
   pline10_1_1->SetLineWidth(0);
   TPolyLine *pline10_1_2 = makeBoxEC(layer_1_pos,(1*10. -5.),size_x,"D");
   pline10_1_2->SetLineWidth(0);
   TPolyLine *pline10_1_3 = makeBoxEC(layer_1_pos,(1*10. -5.),size_x,"C");
   pline10_1_3->SetLineWidth(0);
      
   TPolyLine *pline10_2 = makeBoxEC(layer_2_pos,(1*10. -5.),size_x_2);
   pline10_2->Draw();
   TPolyLine *pline10_2_1 = makeBoxEC(layer_2_pos,(1*10. -5.),size_x_2,"U",2);
   pline10_2_1->SetLineWidth(0);
   TPolyLine *pline10_2_2 = makeBoxEC(layer_2_pos,(1*10. -5.),size_x_2,"D",2);
   pline10_2_2->SetLineWidth(0);
   TPolyLine *pline10_2_3 = makeBoxEC(layer_2_pos,(1*10. -5.),size_x_2,"C",2);
   pline10_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline11_1 = makeBoxEC(layer_1_pos,(2*10. -5.),size_x);
   pline11_1->Draw();
   TPolyLine *pline11_1_1 = makeBoxEC(layer_1_pos,(2*10. -5.),size_x,"U");
   pline11_1_1->SetLineWidth(0);
   TPolyLine *pline11_1_2 = makeBoxEC(layer_1_pos,(2*10. -5.),size_x,"D");
   pline11_1_2->SetLineWidth(0);
   TPolyLine *pline11_1_3 = makeBoxEC(layer_1_pos,(2*10. -5.),size_x,"C");
   pline11_1_3->SetLineWidth(0);
      
   TPolyLine *pline11_2 = makeBoxEC(layer_2_pos,(2*10. -5.),size_x_2);
   pline11_2->Draw();
   TPolyLine *pline11_2_1 = makeBoxEC(layer_2_pos,(2*10. -5.),size_x_2,"U",2);
   pline11_2_1->SetLineWidth(0);
   TPolyLine *pline11_2_2 = makeBoxEC(layer_2_pos,(2*10. -5.),size_x_2,"D",2);
   pline11_2_2->SetLineWidth(0);
   TPolyLine *pline11_2_3 = makeBoxEC(layer_2_pos,(2*10. -5.),size_x_2,"C",2);
   pline11_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline12_1 = makeBoxEC(layer_1_pos,(3*10. -5.),size_x);
   pline12_1->Draw();
   TPolyLine *pline12_1_1 = makeBoxEC(layer_1_pos,(3*10. -5.),size_x,"U");
   pline12_1_1->SetLineWidth(0);
   TPolyLine *pline12_1_2 = makeBoxEC(layer_1_pos,(3*10. -5.),size_x,"D");
   pline12_1_2->SetLineWidth(0);
   TPolyLine *pline12_1_3 = makeBoxEC(layer_1_pos,(3*10. -5.),size_x,"C");
   pline12_1_3->SetLineWidth(0);
      
   TPolyLine *pline12_2 = makeBoxEC(layer_2_pos,(3*10. -5.),size_x_2);
   pline12_2->Draw();
   TPolyLine *pline12_2_1 = makeBoxEC(layer_2_pos,(3*10. -5.),size_x_2,"U",2);
   pline12_2_1->SetLineWidth(0);
   TPolyLine *pline12_2_2 = makeBoxEC(layer_2_pos,(3*10. -5.),size_x_2,"D",2);
   pline12_2_2->SetLineWidth(0);
   TPolyLine *pline12_2_3 = makeBoxEC(layer_2_pos,(3*10. -5.),size_x_2,"C",2);
   pline12_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline13_1 = makeBoxEC(layer_1_pos,(4*10. -5.),size_x);
   pline13_1->Draw();
   TPolyLine *pline13_1_1 = makeBoxEC(layer_1_pos,(4*10. -5.),size_x,"U");
   pline13_1_1->SetLineWidth(0);
   TPolyLine *pline13_1_2 = makeBoxEC(layer_1_pos,(4*10. -5.),size_x,"D");
   pline13_1_2->SetLineWidth(0);
   TPolyLine *pline13_1_3 = makeBoxEC(layer_1_pos,(4*10. -5.),size_x,"C");
   pline13_1_3->SetLineWidth(0);
      
   TPolyLine *pline13_2 = makeBoxEC(layer_2_pos,(4*10. -5.),size_x_2);
   pline13_2->Draw();
   TPolyLine *pline13_2_1 = makeBoxEC(layer_2_pos,(4*10. -5.),size_x_2,"U",2);
   pline13_2_1->SetLineWidth(0);
   TPolyLine *pline13_2_2 = makeBoxEC(layer_2_pos,(4*10. -5.),size_x_2,"D",2);
   pline13_2_2->SetLineWidth(0);
   TPolyLine *pline13_2_3 = makeBoxEC(layer_2_pos,(4*10. -5.),size_x_2,"C",2);
   pline13_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline14_1 = makeBoxEC(layer_1_pos,(5*10. -5.),size_x);
   pline14_1->Draw();
   TPolyLine *pline14_1_1 = makeBoxEC(layer_1_pos,(5*10. -5.),size_x,"U");
   pline14_1_1->SetLineWidth(0);
   TPolyLine *pline14_1_2 = makeBoxEC(layer_1_pos,(5*10. -5.),size_x,"D");
   pline14_1_2->SetLineWidth(0);
   TPolyLine *pline14_1_3 = makeBoxEC(layer_1_pos,(5*10. -5.),size_x,"C");
   pline14_1_3->SetLineWidth(0);
      
   TPolyLine *pline14_2 = makeBoxEC(layer_2_pos,(5*10. -5.),size_x_2);
   pline14_2->Draw();
   TPolyLine *pline14_2_1 = makeBoxEC(layer_2_pos,(5*10. -5.),size_x_2,"U",2);
   pline14_2_1->SetLineWidth(0);
   TPolyLine *pline14_2_2 = makeBoxEC(layer_2_pos,(5*10. -5.),size_x_2,"D",2);
   pline14_2_2->SetLineWidth(0);
   TPolyLine *pline14_2_3 = makeBoxEC(layer_2_pos,(5*10. -5.),size_x_2,"C",2);
   pline14_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline15_1 = makeBoxEC(layer_1_pos,(6*10. -5.),size_x);
   pline15_1->Draw();
   TPolyLine *pline15_1_1 = makeBoxEC(layer_1_pos,(6*10. -5.),size_x,"U");
   pline15_1_1->SetLineWidth(0);
   TPolyLine *pline15_1_2 = makeBoxEC(layer_1_pos,(6*10. -5.),size_x,"D");
   pline15_1_2->SetLineWidth(0);
   TPolyLine *pline15_1_3 = makeBoxEC(layer_1_pos,(6*10. -5.),size_x,"C");
   pline15_1_3->SetLineWidth(0);
      
   TPolyLine *pline15_2 = makeBoxEC(layer_2_pos,(6*10. -5.),size_x_2);
   pline15_2->Draw();
   TPolyLine *pline15_2_1 = makeBoxEC(layer_2_pos,(6*10. -5.),size_x_2,"U",2);
   pline15_2_1->SetLineWidth(0);
   TPolyLine *pline15_2_2 = makeBoxEC(layer_2_pos,(6*10. -5.),size_x_2,"D",2);
   pline15_2_2->SetLineWidth(0);
   TPolyLine *pline15_2_3 = makeBoxEC(layer_2_pos,(6*10. -5.),size_x_2,"C",2);
   pline15_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline16_1 = makeBoxEC(layer_1_pos,(7*10. -5.),size_x);
   pline16_1->Draw();
   TPolyLine *pline16_1_1 = makeBoxEC(layer_1_pos,(7*10. -5.),size_x,"U");
   pline16_1_1->SetLineWidth(0);
   TPolyLine *pline16_1_2 = makeBoxEC(layer_1_pos,(7*10. -5.),size_x,"D");
   pline16_1_2->SetLineWidth(0);
   TPolyLine *pline16_1_3 = makeBoxEC(layer_1_pos,(7*10. -5.),size_x,"C");
   pline16_1_3->SetLineWidth(0);
      
   TPolyLine *pline16_2 = makeBoxEC(layer_2_pos,(7*10. -5.),size_x_2);
   pline16_2->Draw();
   TPolyLine *pline16_2_1 = makeBoxEC(layer_2_pos,(7*10. -5.),size_x_2,"U",2);
   pline16_2_1->SetLineWidth(0);
   TPolyLine *pline16_2_2 = makeBoxEC(layer_2_pos,(7*10. -5.),size_x_2,"D",2);
   pline16_2_2->SetLineWidth(0);
   TPolyLine *pline16_2_3 = makeBoxEC(layer_2_pos,(7*10. -5.),size_x_2,"C",2);
   pline16_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline17_1 = makeBoxEC(layer_1_pos,(8*10. -5.),size_x);
   pline17_1->Draw();
   TPolyLine *pline17_1_1 = makeBoxEC(layer_1_pos,(8*10. -5.),size_x,"U");
   pline17_1_1->SetLineWidth(0);
   TPolyLine *pline17_1_2 = makeBoxEC(layer_1_pos,(8*10. -5.),size_x,"D");
   pline17_1_2->SetLineWidth(0);
   TPolyLine *pline17_1_3 = makeBoxEC(layer_1_pos,(8*10. -5.),size_x,"C");
   pline17_1_3->SetLineWidth(0);
      
   TPolyLine *pline17_2 = makeBoxEC(layer_2_pos,(8*10. -5.),size_x_2);
   pline17_2->Draw();
   TPolyLine *pline17_2_1 = makeBoxEC(layer_2_pos,(8*10. -5.),size_x_2,"U",2);
   pline17_2_1->SetLineWidth(0);
   TPolyLine *pline17_2_2 = makeBoxEC(layer_2_pos,(8*10. -5.),size_x_2,"D",2);
   pline17_2_2->SetLineWidth(0);
   TPolyLine *pline17_2_3 = makeBoxEC(layer_2_pos,(8*10. -5.),size_x_2,"C",2);
   pline17_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline18_1 = makeBoxEC(layer_1_pos,(9*10. -5.),size_x);
   pline18_1->Draw();
   TPolyLine *pline18_1_1 = makeBoxEC(layer_1_pos,(9*10. -5.),size_x,"U");
   pline18_1_1->SetLineWidth(0);
   TPolyLine *pline18_1_2 = makeBoxEC(layer_1_pos,(9*10. -5.),size_x,"D");
   pline18_1_2->SetLineWidth(0);
   TPolyLine *pline18_1_3 = makeBoxEC(layer_1_pos,(9*10. -5.),size_x,"C");
   pline18_1_3->SetLineWidth(0);
      
   TPolyLine *pline18_2 = makeBoxEC(layer_2_pos,(9*10. -5.),size_x_2);
   pline18_2->Draw();
   TPolyLine *pline18_2_1 = makeBoxEC(layer_2_pos,(9*10. -5.),size_x_2,"U",2);
   pline18_2_1->SetLineWidth(0);
   TPolyLine *pline18_2_2 = makeBoxEC(layer_2_pos,(9*10. -5.),size_x_2,"D",2);
   pline18_2_2->SetLineWidth(0);
   TPolyLine *pline18_2_3 = makeBoxEC(layer_2_pos,(9*10. -5.),size_x_2,"C",2);
   pline18_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline19_1 = makeBoxEC(layer_1_pos,(10*10. -5.),size_x);
   pline19_1->Draw();
   TPolyLine *pline19_1_1 = makeBoxEC(layer_1_pos,(10*10. -5.),size_x,"U");
   pline19_1_1->SetLineWidth(0);
   TPolyLine *pline19_1_2 = makeBoxEC(layer_1_pos,(10*10. -5.),size_x,"D");
   pline19_1_2->SetLineWidth(0);
   TPolyLine *pline19_1_3 = makeBoxEC(layer_1_pos,(10*10. -5.),size_x,"C");
   pline19_1_3->SetLineWidth(0);
      
   TPolyLine *pline19_2 = makeBoxEC(layer_2_pos,(10*10. -5.),size_x_2);
   pline19_2->Draw();
   TPolyLine *pline19_2_1 = makeBoxEC(layer_2_pos,(10*10. -5.),size_x_2,"U",2);
   pline19_2_1->SetLineWidth(0);
   TPolyLine *pline19_2_2 = makeBoxEC(layer_2_pos,(10*10. -5.),size_x_2,"D",2);
   pline19_2_2->SetLineWidth(0);
   TPolyLine *pline19_2_3 = makeBoxEC(layer_2_pos,(10*10. -5.),size_x_2,"C",2);
   pline19_2_3->SetLineWidth(0);
   

   TPolyLine *pline20_1 = makeBoxEC(layer_1_pos,(11*10. -5.),size_x);
   pline20_1->Draw();
   TPolyLine *pline20_1_1 = makeBoxEC(layer_1_pos,(11*10. -5.),size_x,"U");
   pline20_1_1->SetLineWidth(0);
   TPolyLine *pline20_1_2 = makeBoxEC(layer_1_pos,(11*10. -5.),size_x,"D");
   pline20_1_2->SetLineWidth(0);
   TPolyLine *pline20_1_3 = makeBoxEC(layer_1_pos,(11*10. -5.),size_x,"C");
   pline20_1_3->SetLineWidth(0);
      
   TPolyLine *pline20_2 = makeBoxEC(layer_2_pos,(11*10. -5.),size_x_2);
   pline20_2->Draw();
   TPolyLine *pline20_2_1 = makeBoxEC(layer_2_pos,(11*10. -5.),size_x_2,"U",2);
   pline20_2_1->SetLineWidth(0);
   TPolyLine *pline20_2_2 = makeBoxEC(layer_2_pos,(11*10. -5.),size_x_2,"D",2);
   pline20_2_2->SetLineWidth(0);
   TPolyLine *pline20_2_3 = makeBoxEC(layer_2_pos,(11*10. -5.),size_x_2,"C",2);
   pline20_2_3->SetLineWidth(0);
   

   TPolyLine *pline21_1 = makeBoxEC(layer_1_pos,(12*10. -5.),size_x);
   pline21_1->Draw();
   TPolyLine *pline21_1_1 = makeBoxEC(layer_1_pos,(12*10. -5.),size_x,"U");
   pline21_1_1->SetLineWidth(0);
   TPolyLine *pline21_1_2 = makeBoxEC(layer_1_pos,(12*10. -5.),size_x,"D");
   pline21_1_2->SetLineWidth(0);
   TPolyLine *pline21_1_3 = makeBoxEC(layer_1_pos,(12*10. -5.),size_x,"C");
   pline21_1_3->SetLineWidth(0);
      
   TPolyLine *pline21_2 = makeBoxEC(layer_2_pos,(12*10. -5.),size_x_2);
   pline21_2->Draw();
   TPolyLine *pline21_2_1 = makeBoxEC(layer_2_pos,(12*10. -5.),size_x_2,"U",2);
   pline21_2_1->SetLineWidth(0);
   TPolyLine *pline21_2_2 = makeBoxEC(layer_2_pos,(12*10. -5.),size_x_2,"D",2);
   pline21_2_2->SetLineWidth(0);
   TPolyLine *pline21_2_3 = makeBoxEC(layer_2_pos,(12*10. -5.),size_x_2,"C",2);
   pline21_2_3->SetLineWidth(0);


   TPolyLine *pline22_1 = makeBoxEC(layer_1_pos,(13*10. -5.),size_x);
   pline22_1->Draw();
   TPolyLine *pline22_1_1 = makeBoxEC(layer_1_pos,(13*10. -5.),size_x,"U");
   pline22_1_1->SetLineWidth(0);
   TPolyLine *pline22_1_2 = makeBoxEC(layer_1_pos,(13*10. -5.),size_x,"D");
   pline22_1_2->SetLineWidth(0);
   TPolyLine *pline22_1_3 = makeBoxEC(layer_1_pos,(13*10. -5.),size_x,"C");
   pline22_1_3->SetLineWidth(0);
      
   TPolyLine *pline22_2 = makeBoxEC(layer_2_pos,(13*10. -5.),size_x_2);
   pline22_2->Draw();
   TPolyLine *pline22_2_1 = makeBoxEC(layer_2_pos,(13*10. -5.),size_x_2,"U",2);
   pline22_2_1->SetLineWidth(0);
   TPolyLine *pline22_2_2 = makeBoxEC(layer_2_pos,(13*10. -5.),size_x_2,"D",2);
   pline22_2_2->SetLineWidth(0);
   TPolyLine *pline22_2_3 = makeBoxEC(layer_2_pos,(13*10. -5.),size_x_2,"C",2);
   pline22_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline23_1 = makeBoxEC(layer_1_pos,(14*10. -5.),size_x);
   pline23_1->Draw();
   TPolyLine *pline23_1_1 = makeBoxEC(layer_1_pos,(14*10. -5.),size_x,"U");
   pline23_1_1->SetLineWidth(0);
   TPolyLine *pline23_1_2 = makeBoxEC(layer_1_pos,(14*10. -5.),size_x,"D");
   pline23_1_2->SetLineWidth(0);
   TPolyLine *pline23_1_3 = makeBoxEC(layer_1_pos,(14*10. -5.),size_x,"C");
   pline23_1_3->SetLineWidth(0);
      
   TPolyLine *pline23_2 = makeBoxEC(layer_2_pos,(14*10. -5.),size_x_2);
   pline23_2->Draw();
   TPolyLine *pline23_2_1 = makeBoxEC(layer_2_pos,(14*10. -5.),size_x_2,"U",2);
   pline23_2_1->SetLineWidth(0);
   TPolyLine *pline23_2_2 = makeBoxEC(layer_2_pos,(14*10. -5.),size_x_2,"D",2);
   pline23_2_2->SetLineWidth(0);
   TPolyLine *pline23_2_3 = makeBoxEC(layer_2_pos,(14*10. -5.),size_x_2,"C",2);
   pline23_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline24_1 = makeBoxEC(layer_1_pos,(15*10. -5.),size_x);
   pline24_1->Draw();
   TPolyLine *pline24_1_1 = makeBoxEC(layer_1_pos,(15*10. -5.),size_x,"U");
   pline24_1_1->SetLineWidth(0);
   TPolyLine *pline24_1_2 = makeBoxEC(layer_1_pos,(15*10. -5.),size_x,"D");
   pline24_1_2->SetLineWidth(0);
   TPolyLine *pline24_1_3 = makeBoxEC(layer_1_pos,(15*10. -5.),size_x,"C");
   pline24_1_3->SetLineWidth(0);
      
   TPolyLine *pline24_2 = makeBoxEC(layer_2_pos,(15*10. -5.),size_x_2);
   pline24_2->Draw();
   TPolyLine *pline24_2_1 = makeBoxEC(layer_2_pos,(15*10. -5.),size_x_2,"U",2);
   pline24_2_1->SetLineWidth(0);
   TPolyLine *pline24_2_2 = makeBoxEC(layer_2_pos,(15*10. -5.),size_x_2,"D",2);
   pline24_2_2->SetLineWidth(0);
   TPolyLine *pline24_2_3 = makeBoxEC(layer_2_pos,(15*10. -5.),size_x_2,"C",2);
   pline24_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline25_1 = makeBoxEC(layer_1_pos,(16*10. -5.),size_x);
   pline25_1->Draw();
   TPolyLine *pline25_1_1 = makeBoxEC(layer_1_pos,(16*10. -5.),size_x,"U");
   pline25_1_1->SetLineWidth(0);
   TPolyLine *pline25_1_2 = makeBoxEC(layer_1_pos,(16*10. -5.),size_x,"D");
   pline25_1_2->SetLineWidth(0);
   TPolyLine *pline25_1_3 = makeBoxEC(layer_1_pos,(16*10. -5.),size_x,"C");
   pline25_1_3->SetLineWidth(0);
      
   TPolyLine *pline25_2 = makeBoxEC(layer_2_pos,(16*10. -5.),size_x_2);
   pline25_2->Draw();
   TPolyLine *pline25_2_1 = makeBoxEC(layer_2_pos,(16*10. -5.),size_x_2,"U",2);
   pline25_2_1->SetLineWidth(0);
   TPolyLine *pline25_2_2 = makeBoxEC(layer_2_pos,(16*10. -5.),size_x_2,"D",2);
   pline25_2_2->SetLineWidth(0);
   TPolyLine *pline25_2_3 = makeBoxEC(layer_2_pos,(16*10. -5.),size_x_2,"C",2);
   pline25_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline26_1 = makeBoxEC(layer_1_pos,(17*10. -5.),size_x);
   pline26_1->Draw();
   TPolyLine *pline26_1_1 = makeBoxEC(layer_1_pos,(17*10. -5.),size_x,"U");
   pline26_1_1->SetLineWidth(0);
   TPolyLine *pline26_1_2 = makeBoxEC(layer_1_pos,(17*10. -5.),size_x,"D");
   pline26_1_2->SetLineWidth(0);
   TPolyLine *pline26_1_3 = makeBoxEC(layer_1_pos,(17*10. -5.),size_x,"C");
   pline26_1_3->SetLineWidth(0);
      
   TPolyLine *pline26_2 = makeBoxEC(layer_2_pos,(17*10. -5.),size_x_2);
   pline26_2->Draw();
   TPolyLine *pline26_2_1 = makeBoxEC(layer_2_pos,(17*10. -5.),size_x_2,"U",2);
   pline26_2_1->SetLineWidth(0);
   TPolyLine *pline26_2_2 = makeBoxEC(layer_2_pos,(17*10. -5.),size_x_2,"D",2);
   pline26_2_2->SetLineWidth(0);
   TPolyLine *pline26_2_3 = makeBoxEC(layer_2_pos,(17*10. -5.),size_x_2,"C",2);
   pline26_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline27_1 = makeBoxEC(layer_1_pos,(18*10. -5.),size_x);
   pline27_1->Draw();
   TPolyLine *pline27_1_1 = makeBoxEC(layer_1_pos,(18*10. -5.),size_x,"U");
   pline27_1_1->SetLineWidth(0);
   TPolyLine *pline27_1_2 = makeBoxEC(layer_1_pos,(18*10. -5.),size_x,"D");
   pline27_1_2->SetLineWidth(0);
   TPolyLine *pline27_1_3 = makeBoxEC(layer_1_pos,(18*10. -5.),size_x,"C");
   pline27_1_3->SetLineWidth(0);
      
   TPolyLine *pline27_2 = makeBoxEC(layer_2_pos,(18*10. -5.),size_x_2);
   pline27_2->Draw();
   TPolyLine *pline27_2_1 = makeBoxEC(layer_2_pos,(18*10. -5.),size_x_2,"U",2);
   pline27_2_1->SetLineWidth(0);
   TPolyLine *pline27_2_2 = makeBoxEC(layer_2_pos,(18*10. -5.),size_x_2,"D",2);
   pline27_2_2->SetLineWidth(0);
   TPolyLine *pline27_2_3 = makeBoxEC(layer_2_pos,(18*10. -5.),size_x_2,"C",2);
   pline27_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline28_1 = makeBoxEC(layer_1_pos,(19*10. -5.),size_x);
   pline28_1->Draw();
   TPolyLine *pline28_1_1 = makeBoxEC(layer_1_pos,(19*10. -5.),size_x,"U");
   pline28_1_1->SetLineWidth(0);
   TPolyLine *pline28_1_2 = makeBoxEC(layer_1_pos,(19*10. -5.),size_x,"D");
   pline28_1_2->SetLineWidth(0);
   TPolyLine *pline28_1_3 = makeBoxEC(layer_1_pos,(19*10. -5.),size_x,"C");
   pline28_1_3->SetLineWidth(0);
      
   TPolyLine *pline28_2 = makeBoxEC(layer_2_pos,(19*10. -5.),size_x_2);
   pline28_2->Draw();
   TPolyLine *pline28_2_1 = makeBoxEC(layer_2_pos,(19*10. -5.),size_x_2,"U",2);
   pline28_2_1->SetLineWidth(0);
   TPolyLine *pline28_2_2 = makeBoxEC(layer_2_pos,(19*10. -5.),size_x_2,"D",2);
   pline28_2_2->SetLineWidth(0);
   TPolyLine *pline28_2_3 = makeBoxEC(layer_2_pos,(19*10. -5.),size_x_2,"C",2);
   pline28_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline29_1 = makeBoxEC(layer_1_pos,(20*10. -5.),size_x);
   pline29_1->Draw();
   TPolyLine *pline29_1_1 = makeBoxEC(layer_1_pos,(20*10. -5.),size_x,"U");
   pline29_1_1->SetLineWidth(0);
   TPolyLine *pline29_1_2 = makeBoxEC(layer_1_pos,(20*10. -5.),size_x,"D");
   pline29_1_2->SetLineWidth(0);
   TPolyLine *pline29_1_3 = makeBoxEC(layer_1_pos,(20*10. -5.),size_x,"C");
   pline29_1_3->SetLineWidth(0);
      
   TPolyLine *pline29_2 = makeBoxEC(layer_2_pos,(20*10. -5.),size_x_2);
   pline29_2->Draw();
   TPolyLine *pline29_2_1 = makeBoxEC(layer_2_pos,(20*10. -5.),size_x_2,"U",2);
   pline29_2_1->SetLineWidth(0);
   TPolyLine *pline29_2_2 = makeBoxEC(layer_2_pos,(20*10. -5.),size_x_2,"D",2);
   pline29_2_2->SetLineWidth(0);
   TPolyLine *pline29_2_3 = makeBoxEC(layer_2_pos,(20*10. -5.),size_x_2,"C",2);
   pline29_2_3->SetLineWidth(0);
   

   TPolyLine *pline30_1 = makeBoxEC(layer_1_pos,(21*10. -5.),size_x);
   pline30_1->Draw();
   TPolyLine *pline30_1_1 = makeBoxEC(layer_1_pos,(21*10. -5.),size_x,"U");
   pline30_1_1->SetLineWidth(0);
   TPolyLine *pline30_1_2 = makeBoxEC(layer_1_pos,(21*10. -5.),size_x,"D");
   pline30_1_2->SetLineWidth(0);
   TPolyLine *pline30_1_3 = makeBoxEC(layer_1_pos,(21*10. -5.),size_x,"C");
   pline30_1_3->SetLineWidth(0);
      
   TPolyLine *pline30_2 = makeBoxEC(layer_2_pos,(21*10. -5.),size_x_2);
   pline30_2->Draw();
   TPolyLine *pline30_2_1 = makeBoxEC(layer_2_pos,(21*10. -5.),size_x_2,"U",2);
   pline30_2_1->SetLineWidth(0);
   TPolyLine *pline30_2_2 = makeBoxEC(layer_2_pos,(21*10. -5.),size_x_2,"D",2);
   pline30_2_2->SetLineWidth(0);
   TPolyLine *pline30_2_3 = makeBoxEC(layer_2_pos,(21*10. -5.),size_x_2,"C",2);
   pline30_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline31_1 = makeBoxEC(layer_1_pos,(22*10. -5.),size_x);
   pline31_1->Draw();
   TPolyLine *pline31_1_1 = makeBoxEC(layer_1_pos,(22*10. -5.),size_x,"U");
   pline31_1_1->SetLineWidth(0);
   TPolyLine *pline31_1_2 = makeBoxEC(layer_1_pos,(22*10. -5.),size_x,"D");
   pline31_1_2->SetLineWidth(0);
   TPolyLine *pline31_1_3 = makeBoxEC(layer_1_pos,(22*10. -5.),size_x,"C");
   pline31_1_3->SetLineWidth(0);
      
   TPolyLine *pline31_2 = makeBoxEC(layer_2_pos,(22*10. -5.),size_x_2);
   pline31_2->Draw();
   TPolyLine *pline31_2_1 = makeBoxEC(layer_2_pos,(22*10. -5.),size_x_2,"U",2);
   pline31_2_1->SetLineWidth(0);
   TPolyLine *pline31_2_2 = makeBoxEC(layer_2_pos,(22*10. -5.),size_x_2,"D",2);
   pline31_2_2->SetLineWidth(0);
   TPolyLine *pline31_2_3 = makeBoxEC(layer_2_pos,(22*10. -5.),size_x_2,"C",2);
   pline31_2_3->SetLineWidth(0);
   

   TPolyLine *pline32_1 = makeBoxEC(layer_1_pos,(23*10. -5.),size_x);
   pline32_1->Draw();
   TPolyLine *pline32_1_1 = makeBoxEC(layer_1_pos,(23*10. -5.),size_x,"U");
   pline32_1_1->SetLineWidth(0);
   TPolyLine *pline32_1_2 = makeBoxEC(layer_1_pos,(23*10. -5.),size_x,"D");
   pline32_1_2->SetLineWidth(0);
   TPolyLine *pline32_1_3 = makeBoxEC(layer_1_pos,(23*10. -5.),size_x,"C");
   pline32_1_3->SetLineWidth(0);
      
   TPolyLine *pline32_2 = makeBoxEC(layer_2_pos,(23*10. -5.),size_x_2);
   pline32_2->Draw();
   TPolyLine *pline32_2_1 = makeBoxEC(layer_2_pos,(23*10. -5.),size_x_2,"U",2);
   pline32_2_1->SetLineWidth(0);
   TPolyLine *pline32_2_2 = makeBoxEC(layer_2_pos,(23*10. -5.),size_x_2,"D",2);
   pline32_2_2->SetLineWidth(0);
   TPolyLine *pline32_2_3 = makeBoxEC(layer_2_pos,(23*10. -5.),size_x_2,"C",2);
   pline32_2_3->SetLineWidth(0);
   

   TPolyLine *pline33_1 = makeBoxEC(layer_1_pos,(24*10. -5.),size_x);
   pline33_1->Draw();
   TPolyLine *pline33_1_1 = makeBoxEC(layer_1_pos,(24*10. -5.),size_x,"U");
   pline33_1_1->SetLineWidth(0);
   TPolyLine *pline33_1_2 = makeBoxEC(layer_1_pos,(24*10. -5.),size_x,"D");
   pline33_1_2->SetLineWidth(0);
   TPolyLine *pline33_1_3 = makeBoxEC(layer_1_pos,(24*10. -5.),size_x,"C");
   pline33_1_3->SetLineWidth(0);
      
   TPolyLine *pline33_2 = makeBoxEC(layer_2_pos,(24*10. -5.),size_x_2);
   pline33_2->Draw();
   TPolyLine *pline33_2_1 = makeBoxEC(layer_2_pos,(24*10. -5.),size_x_2,"U",2);
   pline33_2_1->SetLineWidth(0);
   TPolyLine *pline33_2_2 = makeBoxEC(layer_2_pos,(24*10. -5.),size_x_2,"D",2);
   pline33_2_2->SetLineWidth(0);
   TPolyLine *pline33_2_3 = makeBoxEC(layer_2_pos,(24*10. -5.),size_x_2,"C",2);
   pline33_2_3->SetLineWidth(0);
   

   TPolyLine *pline34_1 = makeBoxEC(layer_1_pos,(25*10. -5.),size_x);
   pline34_1->Draw();
   TPolyLine *pline34_1_1 = makeBoxEC(layer_1_pos,(25*10. -5.),size_x,"U");
   pline34_1_1->SetLineWidth(0);
   TPolyLine *pline34_1_2 = makeBoxEC(layer_1_pos,(25*10. -5.),size_x,"D");
   pline34_1_2->SetLineWidth(0);
   TPolyLine *pline34_1_3 = makeBoxEC(layer_1_pos,(25*10. -5.),size_x,"C");
   pline34_1_3->SetLineWidth(0);
      
   TPolyLine *pline34_2 = makeBoxEC(layer_2_pos,(25*10. -5.),size_x_2);
   pline34_2->Draw();
   TPolyLine *pline34_2_1 = makeBoxEC(layer_2_pos,(25*10. -5.),size_x_2,"U",2);
   pline34_2_1->SetLineWidth(0);
   TPolyLine *pline34_2_2 = makeBoxEC(layer_2_pos,(25*10. -5.),size_x_2,"D",2);
   pline34_2_2->SetLineWidth(0);
   TPolyLine *pline34_2_3 = makeBoxEC(layer_2_pos,(25*10. -5.),size_x_2,"C",2);
   pline34_2_3->SetLineWidth(0);
   

   TPolyLine *pline35_1 = makeBoxEC(layer_1_pos,(26*10. -5.),size_x);
   pline35_1->Draw();
   TPolyLine *pline35_1_1 = makeBoxEC(layer_1_pos,(26*10. -5.),size_x,"U");
   pline35_1_1->SetLineWidth(0);
   TPolyLine *pline35_1_2 = makeBoxEC(layer_1_pos,(26*10. -5.),size_x,"D");
   pline35_1_2->SetLineWidth(0);
   TPolyLine *pline35_1_3 = makeBoxEC(layer_1_pos,(26*10. -5.),size_x,"C");
   pline35_1_3->SetLineWidth(0);
      
   TPolyLine *pline35_2 = makeBoxEC(layer_2_pos,(26*10. -5.),size_x_2);
   pline35_2->Draw();
   TPolyLine *pline35_2_1 = makeBoxEC(layer_2_pos,(26*10. -5.),size_x_2,"U",2);
   pline35_2_1->SetLineWidth(0);
   TPolyLine *pline35_2_2 = makeBoxEC(layer_2_pos,(26*10. -5.),size_x_2,"D",2);
   pline35_2_2->SetLineWidth(0);
   TPolyLine *pline35_2_3 = makeBoxEC(layer_2_pos,(26*10. -5.),size_x_2,"C",2);
   pline35_2_3->SetLineWidth(0);
   

   TPolyLine *pline36_1 = makeBoxEC(layer_1_pos,(27*10. -5.),size_x);
   pline36_1->Draw();
   TPolyLine *pline36_1_1 = makeBoxEC(layer_1_pos,(27*10. -5.),size_x,"U");
   pline36_1_1->SetLineWidth(0);
   TPolyLine *pline36_1_2 = makeBoxEC(layer_1_pos,(27*10. -5.),size_x,"D");
   pline36_1_2->SetLineWidth(0);
   TPolyLine *pline36_1_3 = makeBoxEC(layer_1_pos,(27*10. -5.),size_x,"C");
   pline36_1_3->SetLineWidth(0);
      
   TPolyLine *pline36_2 = makeBoxEC(layer_2_pos,(27*10. -5.),size_x_2);
   pline36_2->Draw();
   TPolyLine *pline36_2_1 = makeBoxEC(layer_2_pos,(27*10. -5.),size_x_2,"U",2);
   pline36_2_1->SetLineWidth(0);
   TPolyLine *pline36_2_2 = makeBoxEC(layer_2_pos,(27*10. -5.),size_x_2,"D",2);
   pline36_2_2->SetLineWidth(0);
   TPolyLine *pline36_2_3 = makeBoxEC(layer_2_pos,(27*10. -5.),size_x_2,"C",2);
   pline36_2_3->SetLineWidth(0);


   TPolyLine *pline1_1 = makeBoxEC(layer_1_pos,(28*10. -5.),size_x);
   pline1_1->Draw();
   TPolyLine *pline1_1_1 = makeBoxEC(layer_1_pos,(28*10. -5.),size_x,"U");
   pline1_1_1->SetLineWidth(0);
   TPolyLine *pline1_1_2 = makeBoxEC(layer_1_pos,(28*10. -5.),size_x,"D");
   pline1_1_2->SetLineWidth(0);
   TPolyLine *pline1_1_3 = makeBoxEC(layer_1_pos,(28*10. -5.),size_x,"C");
   pline1_1_3->SetLineWidth(0);
      
   TPolyLine *pline1_2 = makeBoxEC(layer_2_pos,(28*10. -5.),size_x_2);
   pline1_2->Draw();
   TPolyLine *pline1_2_1 = makeBoxEC(layer_2_pos,(28*10. -5.),size_x_2,"U",2);
   pline1_2_1->SetLineWidth(0);
   TPolyLine *pline1_2_2 = makeBoxEC(layer_2_pos,(28*10. -5.),size_x_2,"D",2);
   pline1_2_2->SetLineWidth(0);
   TPolyLine *pline1_2_3 = makeBoxEC(layer_2_pos,(28*10. -5.),size_x_2,"C",2);
   pline1_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline2_1 = makeBoxEC(layer_1_pos,(29*10. -5.),size_x);
   pline2_1->Draw();
   TPolyLine *pline2_1_1 = makeBoxEC(layer_1_pos,(29*10. -5.),size_x,"U");
   pline2_1_1->SetLineWidth(0);
   TPolyLine *pline2_1_2 = makeBoxEC(layer_1_pos,(29*10. -5.),size_x,"D");
   pline2_1_2->SetLineWidth(0);
   TPolyLine *pline2_1_3 = makeBoxEC(layer_1_pos,(29*10. -5.),size_x,"C");
   pline2_1_3->SetLineWidth(0);
      
   TPolyLine *pline2_2 = makeBoxEC(layer_2_pos,(29*10. -5.),size_x_2);
   pline2_2->Draw();
   TPolyLine *pline2_2_1 = makeBoxEC(layer_2_pos,(29*10. -5.),size_x_2,"U",2);
   pline2_2_1->SetLineWidth(0);
   TPolyLine *pline2_2_2 = makeBoxEC(layer_2_pos,(29*10. -5.),size_x_2,"D",2);
   pline2_2_2->SetLineWidth(0);
   TPolyLine *pline2_2_3 = makeBoxEC(layer_2_pos,(29*10. -5.),size_x_2,"C",2);
   pline2_2_3->SetLineWidth(0);

      
   TPolyLine *pline3_1 = makeBoxEC(layer_1_pos,(30*10. -5.),size_x);
   pline3_1->Draw();
   TPolyLine *pline3_1_1 = makeBoxEC(layer_1_pos,(30*10. -5.),size_x,"U");
   pline3_1_1->SetLineWidth(0);
   TPolyLine *pline3_1_2 = makeBoxEC(layer_1_pos,(30*10. -5.),size_x,"D");
   pline3_1_2->SetLineWidth(0);
   TPolyLine *pline3_1_3 = makeBoxEC(layer_1_pos,(30*10. -5.),size_x,"C");
   pline3_1_3->SetLineWidth(0);
      
   TPolyLine *pline3_2 = makeBoxEC(layer_2_pos,(30*10. -5.),size_x_2);
   pline3_2->Draw();
   TPolyLine *pline3_2_1 = makeBoxEC(layer_2_pos,(30*10. -5.),size_x_2,"U",2);
   pline3_2_1->SetLineWidth(0);
   TPolyLine *pline3_2_2 = makeBoxEC(layer_2_pos,(30*10. -5.),size_x_2,"D",2);
   pline3_2_2->SetLineWidth(0);
   TPolyLine *pline3_2_3 = makeBoxEC(layer_2_pos,(30*10. -5.),size_x_2,"C",2);
   pline3_2_3->SetLineWidth(0);
   

   TPolyLine *pline4_1 = makeBoxEC(layer_1_pos,(31*10. -5.),size_x);
   pline4_1->Draw();
   TPolyLine *pline4_1_1 = makeBoxEC(layer_1_pos,(31*10. -5.),size_x,"U");
   pline4_1_1->SetLineWidth(0);
   TPolyLine *pline4_1_2 = makeBoxEC(layer_1_pos,(31*10. -5.),size_x,"D");
   pline4_1_2->SetLineWidth(0);
   TPolyLine *pline4_1_3 = makeBoxEC(layer_1_pos,(31*10. -5.),size_x,"C");
   pline4_1_3->SetLineWidth(0);
      
   TPolyLine *pline4_2 = makeBoxEC(layer_2_pos,(31*10. -5.),size_x_2);
   pline4_2->Draw();
   TPolyLine *pline4_2_1 = makeBoxEC(layer_2_pos,(31*10. -5.),size_x_2,"U",2);
   pline4_2_1->SetLineWidth(0);
   TPolyLine *pline4_2_2 = makeBoxEC(layer_2_pos,(31*10. -5.),size_x_2,"D",2);
   pline4_2_2->SetLineWidth(0);
   TPolyLine *pline4_2_3 = makeBoxEC(layer_2_pos,(31*10. -5.),size_x_2,"C",2);
   pline4_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline5_1 = makeBoxEC(layer_1_pos,(32*10. -5.),size_x);
   pline5_1->Draw();
   TPolyLine *pline5_1_1 = makeBoxEC(layer_1_pos,(32*10. -5.),size_x,"U");
   pline5_1_1->SetLineWidth(0);
   TPolyLine *pline5_1_2 = makeBoxEC(layer_1_pos,(32*10. -5.),size_x,"D");
   pline5_1_2->SetLineWidth(0);
   TPolyLine *pline5_1_3 = makeBoxEC(layer_1_pos,(32*10. -5.),size_x,"C");
   pline5_1_3->SetLineWidth(0);
      
   TPolyLine *pline5_2 = makeBoxEC(layer_2_pos,(32*10. -5.),size_x_2);
   pline5_2->Draw();
   TPolyLine *pline5_2_1 = makeBoxEC(layer_2_pos,(32*10. -5.),size_x_2,"U",2);
   pline5_2_1->SetLineWidth(0);
   TPolyLine *pline5_2_2 = makeBoxEC(layer_2_pos,(32*10. -5.),size_x_2,"D",2);
   pline5_2_2->SetLineWidth(0);
   TPolyLine *pline5_2_3 = makeBoxEC(layer_2_pos,(32*10. -5.),size_x_2,"C",2);
   pline5_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline6_1 = makeBoxEC(layer_1_pos,(33*10. -5.),size_x);
   pline6_1->Draw();
   TPolyLine *pline6_1_1 = makeBoxEC(layer_1_pos,(33*10. -5.),size_x,"U");
   pline6_1_1->SetLineWidth(0);
   TPolyLine *pline6_1_2 = makeBoxEC(layer_1_pos,(33*10. -5.),size_x,"D");
   pline6_1_2->SetLineWidth(0);
   TPolyLine *pline6_1_3 = makeBoxEC(layer_1_pos,(33*10. -5.),size_x,"C");
   pline6_1_3->SetLineWidth(0);
      
   TPolyLine *pline6_2 = makeBoxEC(layer_2_pos,(33*10. -5.),size_x_2);
   pline6_2->Draw();
   TPolyLine *pline6_2_1 = makeBoxEC(layer_2_pos,(33*10. -5.),size_x_2,"U",2);
   pline6_2_1->SetLineWidth(0);
   TPolyLine *pline6_2_2 = makeBoxEC(layer_2_pos,(33*10. -5.),size_x_2,"D",2);
   pline6_2_2->SetLineWidth(0);
   TPolyLine *pline6_2_3 = makeBoxEC(layer_2_pos,(33*10. -5.),size_x_2,"C",2);
   pline6_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline7_1 = makeBoxEC(layer_1_pos,(34*10. -5.),size_x);
   pline7_1->Draw();
   TPolyLine *pline7_1_1 = makeBoxEC(layer_1_pos,(34*10. -5.),size_x,"U");
   pline7_1_1->SetLineWidth(0);
   TPolyLine *pline7_1_2 = makeBoxEC(layer_1_pos,(34*10. -5.),size_x,"D");
   pline7_1_2->SetLineWidth(0);
   TPolyLine *pline7_1_3 = makeBoxEC(layer_1_pos,(34*10. -5.),size_x,"C");
   pline7_1_3->SetLineWidth(0);
      
   TPolyLine *pline7_2 = makeBoxEC(layer_2_pos,(34*10. -5.),size_x_2);
   pline7_2->Draw();
   TPolyLine *pline7_2_1 = makeBoxEC(layer_2_pos,(34*10. -5.),size_x_2,"U",2);
   pline7_2_1->SetLineWidth(0);
   TPolyLine *pline7_2_2 = makeBoxEC(layer_2_pos,(34*10. -5.),size_x_2,"D",2);
   pline7_2_2->SetLineWidth(0);
   TPolyLine *pline7_2_3 = makeBoxEC(layer_2_pos,(34*10. -5.),size_x_2,"C",2);
   pline7_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline8_1 = makeBoxEC(layer_1_pos,(35*10. -5.),size_x);
   pline8_1->Draw();
   TPolyLine *pline8_1_1 = makeBoxEC(layer_1_pos,(35*10. -5.),size_x,"U");
   pline8_1_1->SetLineWidth(0);
   TPolyLine *pline8_1_2 = makeBoxEC(layer_1_pos,(35*10. -5.),size_x,"D");
   pline8_1_2->SetLineWidth(0);
   TPolyLine *pline8_1_3 = makeBoxEC(layer_1_pos,(35*10. -5.),size_x,"C");
   pline8_1_3->SetLineWidth(0);
      
   TPolyLine *pline8_2 = makeBoxEC(layer_2_pos,(35*10. -5.),size_x_2);
   pline8_2->Draw();
   TPolyLine *pline8_2_1 = makeBoxEC(layer_2_pos,(35*10. -5.),size_x_2,"U",2);
   pline8_2_1->SetLineWidth(0);
   TPolyLine *pline8_2_2 = makeBoxEC(layer_2_pos,(35*10. -5.),size_x_2,"D",2);
   pline8_2_2->SetLineWidth(0);
   TPolyLine *pline8_2_3 = makeBoxEC(layer_2_pos,(35*10. -5.),size_x_2,"C",2);
   pline8_2_3->SetLineWidth(0);
   
   
   TPolyLine *pline9_1 = makeBoxEC(layer_1_pos,(36*10. -5.),size_x);
   pline9_1->Draw();
   TPolyLine *pline9_1_1 = makeBoxEC(layer_1_pos,(36*10. -5.),size_x,"U");
   pline9_1_1->SetLineWidth(0);
   TPolyLine *pline9_1_2 = makeBoxEC(layer_1_pos,(36*10. -5.),size_x,"D");
   pline9_1_2->SetLineWidth(0);
   TPolyLine *pline9_1_3 = makeBoxEC(layer_1_pos,(36*10. -5.),size_x,"C");
   pline9_1_3->SetLineWidth(0);
      
   TPolyLine *pline9_2 = makeBoxEC(layer_2_pos,(36*10. -5.),size_x_2);
   pline9_2->Draw();
   TPolyLine *pline9_2_1 = makeBoxEC(layer_2_pos,(36*10. -5.),size_x_2,"U",2);
   pline9_2_1->SetLineWidth(0);
   TPolyLine *pline9_2_2 = makeBoxEC(layer_2_pos,(36*10. -5.),size_x_2,"D",2);
   pline9_2_2->SetLineWidth(0);
   TPolyLine *pline9_2_3 = makeBoxEC(layer_2_pos,(36*10. -5.),size_x_2,"C",2);
   pline9_2_3->SetLineWidth(0);

   
   chambers_boxes.push_back(pline10_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(10);
   chambers_boxes.push_back(pline10_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(10);
   chambers_boxes.push_back(pline10_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(10);
   chambers_boxes.push_back(pline10_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(10);
   chambers_boxes.push_back(pline10_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(10);
   chambers_boxes.push_back(pline10_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(10);

   chambers_boxes.push_back(pline11_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(11);
   chambers_boxes.push_back(pline11_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(11);
   chambers_boxes.push_back(pline11_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(11);
   chambers_boxes.push_back(pline11_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(11);
   chambers_boxes.push_back(pline11_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(11);
   chambers_boxes.push_back(pline11_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(11);

   chambers_boxes.push_back(pline12_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(12);
   chambers_boxes.push_back(pline12_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(12);
   chambers_boxes.push_back(pline12_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(12);
   chambers_boxes.push_back(pline12_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(12);
   chambers_boxes.push_back(pline12_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(12);
   chambers_boxes.push_back(pline12_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(12);

   chambers_boxes.push_back(pline13_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(13);
   chambers_boxes.push_back(pline13_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(13);
   chambers_boxes.push_back(pline13_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(13);
   chambers_boxes.push_back(pline13_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(13);
   chambers_boxes.push_back(pline13_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(13);
   chambers_boxes.push_back(pline13_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(13);

   chambers_boxes.push_back(pline14_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(14);
   chambers_boxes.push_back(pline14_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(14);
   chambers_boxes.push_back(pline14_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(14);
   chambers_boxes.push_back(pline14_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(14);
   chambers_boxes.push_back(pline14_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(14);
   chambers_boxes.push_back(pline14_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(14);

   chambers_boxes.push_back(pline15_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(15);
   chambers_boxes.push_back(pline15_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(15);
   chambers_boxes.push_back(pline15_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(15);
   chambers_boxes.push_back(pline15_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(15);
   chambers_boxes.push_back(pline15_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(15);
   chambers_boxes.push_back(pline15_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(15);

   chambers_boxes.push_back(pline16_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(16);
   chambers_boxes.push_back(pline16_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(16);
   chambers_boxes.push_back(pline16_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(16);
   chambers_boxes.push_back(pline16_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(16);
   chambers_boxes.push_back(pline16_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(16);
   chambers_boxes.push_back(pline16_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(16);

   chambers_boxes.push_back(pline17_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(17);
   chambers_boxes.push_back(pline17_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(17);
   chambers_boxes.push_back(pline17_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(17);
   chambers_boxes.push_back(pline17_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(17);
   chambers_boxes.push_back(pline17_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(17);
   chambers_boxes.push_back(pline17_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(17);

   chambers_boxes.push_back(pline18_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(18);
   chambers_boxes.push_back(pline18_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(18);
   chambers_boxes.push_back(pline18_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(18);
   chambers_boxes.push_back(pline18_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(18);
   chambers_boxes.push_back(pline18_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(18);
   chambers_boxes.push_back(pline18_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(18);

   chambers_boxes.push_back(pline19_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(19);
   chambers_boxes.push_back(pline19_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(19);
   chambers_boxes.push_back(pline19_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(19);
   chambers_boxes.push_back(pline19_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(19);
   chambers_boxes.push_back(pline19_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(19);
   chambers_boxes.push_back(pline19_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(19);

   chambers_boxes.push_back(pline20_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(20);
   chambers_boxes.push_back(pline20_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(20);
   chambers_boxes.push_back(pline20_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(20);
   chambers_boxes.push_back(pline20_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(20);
   chambers_boxes.push_back(pline20_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(20);
   chambers_boxes.push_back(pline20_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(20);

   chambers_boxes.push_back(pline21_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(21);
   chambers_boxes.push_back(pline21_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(21);
   chambers_boxes.push_back(pline21_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(21);
   chambers_boxes.push_back(pline21_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(21);
   chambers_boxes.push_back(pline21_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(21);
   chambers_boxes.push_back(pline21_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(21);

   chambers_boxes.push_back(pline22_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(22);
   chambers_boxes.push_back(pline22_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(22);
   chambers_boxes.push_back(pline22_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(22);
   chambers_boxes.push_back(pline22_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(22);
   chambers_boxes.push_back(pline22_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(22);
   chambers_boxes.push_back(pline22_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(22);

   chambers_boxes.push_back(pline23_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(23);
   chambers_boxes.push_back(pline23_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(23);
   chambers_boxes.push_back(pline23_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(23);
   chambers_boxes.push_back(pline23_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(23);
   chambers_boxes.push_back(pline23_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(23);
   chambers_boxes.push_back(pline23_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(23);

   chambers_boxes.push_back(pline24_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(24);
   chambers_boxes.push_back(pline24_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(24);
   chambers_boxes.push_back(pline24_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(24);
   chambers_boxes.push_back(pline24_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(24);
   chambers_boxes.push_back(pline24_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(24);
   chambers_boxes.push_back(pline24_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(24);

   chambers_boxes.push_back(pline25_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(25);
   chambers_boxes.push_back(pline25_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(25);
   chambers_boxes.push_back(pline25_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(25);
   chambers_boxes.push_back(pline25_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(25);
   chambers_boxes.push_back(pline25_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(25);
   chambers_boxes.push_back(pline25_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(25);

   chambers_boxes.push_back(pline26_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(26);
   chambers_boxes.push_back(pline26_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(26);
   chambers_boxes.push_back(pline26_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(26);
   chambers_boxes.push_back(pline26_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(26);
   chambers_boxes.push_back(pline26_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(26);
   chambers_boxes.push_back(pline26_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(26);

   chambers_boxes.push_back(pline27_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(27);
   chambers_boxes.push_back(pline27_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(27);
   chambers_boxes.push_back(pline27_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(27);
   chambers_boxes.push_back(pline27_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(27);
   chambers_boxes.push_back(pline27_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(27);
   chambers_boxes.push_back(pline27_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(27);

   chambers_boxes.push_back(pline28_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(28);
   chambers_boxes.push_back(pline28_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(28);
   chambers_boxes.push_back(pline28_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(28);
   chambers_boxes.push_back(pline28_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(28);
   chambers_boxes.push_back(pline28_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(28);
   chambers_boxes.push_back(pline28_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(28);

   chambers_boxes.push_back(pline29_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(29);
   chambers_boxes.push_back(pline29_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(29);
   chambers_boxes.push_back(pline29_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(29);
   chambers_boxes.push_back(pline29_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(29);
   chambers_boxes.push_back(pline29_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(29);
   chambers_boxes.push_back(pline29_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(29);

   chambers_boxes.push_back(pline30_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(30);
   chambers_boxes.push_back(pline30_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(30);
   chambers_boxes.push_back(pline30_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(30);
   chambers_boxes.push_back(pline30_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(30);
   chambers_boxes.push_back(pline30_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(30);
   chambers_boxes.push_back(pline30_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(30);   

   chambers_boxes.push_back(pline31_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(31);
   chambers_boxes.push_back(pline31_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(31);
   chambers_boxes.push_back(pline31_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(31);
   chambers_boxes.push_back(pline31_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(31);
   chambers_boxes.push_back(pline31_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(31);
   chambers_boxes.push_back(pline31_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(31);

   chambers_boxes.push_back(pline32_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(32);
   chambers_boxes.push_back(pline32_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(32);
   chambers_boxes.push_back(pline32_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(32);
   chambers_boxes.push_back(pline32_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(32);
   chambers_boxes.push_back(pline32_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(32);
   chambers_boxes.push_back(pline32_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(32);

   chambers_boxes.push_back(pline33_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(33);
   chambers_boxes.push_back(pline33_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(33);
   chambers_boxes.push_back(pline33_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(33);
   chambers_boxes.push_back(pline33_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(33);
   chambers_boxes.push_back(pline33_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(33);
   chambers_boxes.push_back(pline33_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(33);

   chambers_boxes.push_back(pline34_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(34);
   chambers_boxes.push_back(pline34_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(34);
   chambers_boxes.push_back(pline34_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(34);
   chambers_boxes.push_back(pline34_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(34);
   chambers_boxes.push_back(pline34_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(34);
   chambers_boxes.push_back(pline34_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(34);

   chambers_boxes.push_back(pline35_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(35);
   chambers_boxes.push_back(pline35_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(35);
   chambers_boxes.push_back(pline35_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(35);
   chambers_boxes.push_back(pline35_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(35);
   chambers_boxes.push_back(pline35_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(35);
   chambers_boxes.push_back(pline35_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(35);

   chambers_boxes.push_back(pline36_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(36);
   chambers_boxes.push_back(pline36_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(36);
   chambers_boxes.push_back(pline36_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(36);
   chambers_boxes.push_back(pline36_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(36);
   chambers_boxes.push_back(pline36_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(36);
   chambers_boxes.push_back(pline36_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(36);

   chambers_boxes.push_back(pline1_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(1);
   chambers_boxes.push_back(pline1_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(1);
   chambers_boxes.push_back(pline1_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(1);
   chambers_boxes.push_back(pline1_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(1);
   chambers_boxes.push_back(pline1_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(1);
   chambers_boxes.push_back(pline1_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(1);

   chambers_boxes.push_back(pline2_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(2);
   chambers_boxes.push_back(pline2_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(2);
   chambers_boxes.push_back(pline2_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(2);
   chambers_boxes.push_back(pline2_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(2);
   chambers_boxes.push_back(pline2_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(2);
   chambers_boxes.push_back(pline2_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(2);

   chambers_boxes.push_back(pline3_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(3);
   chambers_boxes.push_back(pline3_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(3);
   chambers_boxes.push_back(pline3_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(3);
   chambers_boxes.push_back(pline3_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(3);
   chambers_boxes.push_back(pline3_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(3);
   chambers_boxes.push_back(pline3_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(3);

   chambers_boxes.push_back(pline4_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(4);
   chambers_boxes.push_back(pline4_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(4);
   chambers_boxes.push_back(pline4_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(4);
   chambers_boxes.push_back(pline4_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(4);
   chambers_boxes.push_back(pline4_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(4);
   chambers_boxes.push_back(pline4_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(4);

   chambers_boxes.push_back(pline5_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(5);
   chambers_boxes.push_back(pline5_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(5);
   chambers_boxes.push_back(pline5_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(5);
   chambers_boxes.push_back(pline5_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(5);
   chambers_boxes.push_back(pline5_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(5);
   chambers_boxes.push_back(pline5_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(5);

   chambers_boxes.push_back(pline6_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(6);
   chambers_boxes.push_back(pline6_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(6);
   chambers_boxes.push_back(pline6_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(6);
   chambers_boxes.push_back(pline6_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(6);
   chambers_boxes.push_back(pline6_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(6);
   chambers_boxes.push_back(pline6_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(6);

   chambers_boxes.push_back(pline7_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(7);
   chambers_boxes.push_back(pline7_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(7);
   chambers_boxes.push_back(pline7_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(7);
   chambers_boxes.push_back(pline7_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(7);
   chambers_boxes.push_back(pline7_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(7);
   chambers_boxes.push_back(pline7_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(7);

   chambers_boxes.push_back(pline8_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(8);
   chambers_boxes.push_back(pline8_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(8);
   chambers_boxes.push_back(pline8_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(8);
   chambers_boxes.push_back(pline8_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(8);
   chambers_boxes.push_back(pline8_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(8);
   chambers_boxes.push_back(pline8_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(8);

   chambers_boxes.push_back(pline9_1_1); chambers_names.push_back("Ring3 A"); chambers_sector.push_back(9);
   chambers_boxes.push_back(pline9_1_2); chambers_names.push_back("Ring3 C"); chambers_sector.push_back(9);
   chambers_boxes.push_back(pline9_1_3); chambers_names.push_back("Ring3 B"); chambers_sector.push_back(9);
   chambers_boxes.push_back(pline9_2_1); chambers_names.push_back("Ring2 A"); chambers_sector.push_back(9);
   chambers_boxes.push_back(pline9_2_2); chambers_names.push_back("Ring2 C"); chambers_sector.push_back(9);
   chambers_boxes.push_back(pline9_2_3); chambers_names.push_back("Ring2 B"); chambers_sector.push_back(9);


	if(just_one_chamber==false){
		for(int ii = 0; ii<chambers_boxes.size(); ii++){
			for(int jj = 0; jj<name_station.size(); jj++){
				if(chambers_names.at(ii)==name_station.at(jj) && chambers_sector.at(ii)==sector_number.at(jj)){
					chambers_boxes.at(ii)->SetFillColor(color_chamber.at(jj));
					chambers_boxes.at(ii)->Draw("f");
				}
		
			}
		}
	} else {
		c1 = c2;
		c2->Close();
		c1->cd();
		c1->Draw();
		for(int ii = 0; ii<chambers_boxes.size(); ii++){
			for(int jj = 0; jj<name_station.size(); jj++){
				if(chambers_names.at(ii)==name_station.at(jj) && chambers_sector.at(ii)==sector_number.at(jj)){
					chambers_boxes.at(ii)->SetFillColor(color_chamber.at(jj));
					chambers_boxes.at(ii)->SetFillStyle(style_chamber.at(jj));
					chambers_boxes.at(ii)->Draw("f");
				}
			}
		}		
    }

	c1->SetCanvasSize(4000,4000);


	for(int i = 1; i<37; i++){
		char str[10];
		int ii = i+9;
		if(ii>36) ii = ii - 36;
		sprintf(str, "%d", ii);
		TText *t = new TText((0.5+(layer_1_pos*0.465)*sin((-i*10.+5.-1.)*(PI/180.0))),(0.5+(layer_1_pos*0.465)*cos((-i*10.+5.-1.)*(PI/180.0))),str);
		t->SetTextFont(43);
		t->SetTextSize(77);
		t->SetTextAngle((i*10.-5.));
		t->Draw();
	}

	
	c1->Draw();
//	c1->SaveAs("test.pdf"); 
	return c1;
}

void ChangeColorEndcap(string RE="", string chamber="",int sector=0, int new_color=0, int new_style=1001){

	int re = 0;
	char name_root_file[400];
	char name_pdf_file[400];

	if(RE=="RE-4"){
		re = 0;
		sprintf(name_root_file,"RE-4_plot.root");
		sprintf(name_pdf_file,"RE-4_plot.pdf");		
	}
	if(RE=="RE-3"){
		re = 1;
		sprintf(name_root_file,"RE-3_plot.root");
		sprintf(name_pdf_file,"RE-3_plot.pdf");		
	}
	if(RE=="RE-2"){
		re = 2;
		sprintf(name_root_file,"RE-2_plot.root");
		sprintf(name_pdf_file,"RE-2_plot.pdf");		
	}
	if(RE=="RE-1"){
		re = 3;
		sprintf(name_root_file,"RE-1_plot.root");
		sprintf(name_pdf_file,"RE-1_plot.pdf");		
	}
	if(RE=="RE+1"){
		re = 4;
		sprintf(name_root_file,"RE+1_plot.root");
		sprintf(name_pdf_file,"RE+1_plot.pdf");		
	}
	if(RE=="RE+2"){
		re = 5;
		sprintf(name_root_file,"RE+2_plot.root");
		sprintf(name_pdf_file,"RE+2_plot.pdf");		
	}
	if(RE=="RE+3"){
		re = 6;
		sprintf(name_root_file,"RE+3_plot.root");
		sprintf(name_pdf_file,"RE+3_plot.pdf");		
	}
	if(RE=="RE+4"){
		re = 7;
		sprintf(name_root_file,"RE+4_plot.root");
		sprintf(name_pdf_file,"RE+4_plot.pdf");		
	}


	TFile* f_new = TFile::Open(name_root_file,"UPDATE");

	TCanvas *c1 = (TCanvas *)f_new->Get("c1");
	vector<string> name_station;
	vector<int> sector_number;
	vector<int> color_chamber;
	vector<int> style_chamber;
	name_station.clear();
	sector_number.clear();
	color_chamber.clear();
	style_chamber.clear();
	name_station.push_back(chamber);
	sector_number.push_back(sector);
	color_chamber.push_back(new_color);  
	style_chamber.push_back(new_style);  
	
	TCanvas *c2 = EndcapPlot(re, name_station, sector_number, color_chamber, style_chamber, true, c1);
	c1 = c2;
	c1->Draw();
	c1->SaveAs(name_pdf_file);  
	c1->Write("",TObject::kOverwrite);
	f_new->Close();
}

