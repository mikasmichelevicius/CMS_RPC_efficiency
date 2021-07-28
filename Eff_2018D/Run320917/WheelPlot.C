#include <TCanvas.h>


TPolyLine *makeBox(float radius = 1., float angle_degree = 0., float xinc = 0.01, string pos = "C"){
   float PI = 3.141592653589793;
   Double_t yinc = 0.006;
   Double_t angle_radian = angle_degree * (PI/180.0);
   Double_t theta = atan(yinc/xinc);
   Double_t hyp = sqrt(yinc*yinc + xinc*xinc);
   Double_t radius_new = radius*0.4;
   Double_t centerX = 0.5+radius_new*sin(-angle_radian);
   Double_t centerY = 0.5+radius_new*cos(-angle_radian);

		Double_t xR[5] = {centerX-hyp*(cos(angle_radian+theta))+xinc*cos(angle_radian),
	                centerX+hyp*(cos(-angle_radian+theta)), 
	                centerX+hyp*(cos(angle_radian+theta)),
	                centerX-hyp*(cos(-angle_radian+theta))+xinc*cos(angle_radian),
	                centerX-hyp*(cos(angle_radian+theta))+xinc*cos(angle_radian)};
 		Double_t yR[5] = {centerY-hyp*(sin(angle_radian+theta))+xinc*sin(angle_radian),
	                centerY-hyp*(sin(-angle_radian+theta)),
	                centerY+hyp*(sin(angle_radian+theta)),
	                centerY+hyp*(sin(-angle_radian+theta))+xinc*sin(angle_radian),
	                centerY-hyp*(sin(angle_radian+theta))+xinc*sin(angle_radian)};

		Double_t xL[5] = {centerX-hyp*(cos(angle_radian+theta)),
	                centerX+hyp*(cos(-angle_radian+theta))-xinc*cos(angle_radian),
	                centerX+hyp*(cos(angle_radian+theta))-xinc*cos(angle_radian),
	                centerX-hyp*(cos(-angle_radian+theta)),
	                centerX-hyp*(cos(angle_radian+theta))};
 		Double_t yL[5] = {centerY-hyp*(sin(angle_radian+theta)),
	                centerY-hyp*(sin(-angle_radian+theta))-xinc*sin(angle_radian),
	                centerY+hyp*(sin(angle_radian+theta))-xinc*sin(angle_radian),
	                centerY+hyp*(sin(-angle_radian+theta)),
	                centerY-hyp*(sin(angle_radian+theta))};	                

		Double_t xC[5] = {centerX-hyp*(cos(angle_radian+theta)),
	                centerX+hyp*(cos(-angle_radian+theta)), 
	                centerX+hyp*(cos(angle_radian+theta)),
	                centerX-hyp*(cos(-angle_radian+theta)),
	                centerX-hyp*(cos(angle_radian+theta))};
 		Double_t yC[5] = {centerY-hyp*(sin(angle_radian+theta)),
	                centerY-hyp*(sin(-angle_radian+theta)),
	                centerY+hyp*(sin(angle_radian+theta)),
	                centerY+hyp*(sin(-angle_radian+theta)),
	                centerY-hyp*(sin(angle_radian+theta))};	     
	                
		Double_t xR1[5] = {centerX-hyp*(cos(angle_radian+theta))+(4./3.)*xinc*cos(angle_radian), //1
	                centerX+hyp*(cos(-angle_radian+theta)),  //2
	                centerX+hyp*(cos(angle_radian+theta)), //3
	                centerX-hyp*(cos(-angle_radian+theta))+(4./3.)*xinc*cos(angle_radian), //4
	                centerX-hyp*(cos(angle_radian+theta))+(4./3.)*xinc*cos(angle_radian)}; //5
 		Double_t yR1[5] = {centerY-hyp*(sin(angle_radian+theta))+(4./3.)*xinc*sin(angle_radian), //1
	                centerY-hyp*(sin(-angle_radian+theta)), //2
	                centerY+hyp*(sin(angle_radian+theta)), //3
	                centerY+hyp*(sin(-angle_radian+theta))+(4./3.)*xinc*sin(angle_radian), //4
	                centerY-hyp*(sin(angle_radian+theta))+(4./3.)*xinc*sin(angle_radian)}; //5

		Double_t xL1[5] = {centerX-hyp*(cos(angle_radian+theta)), //1
	                centerX+hyp*(cos(-angle_radian+theta))-(4./3.)*xinc*cos(angle_radian), //2
	                centerX+hyp*(cos(angle_radian+theta))-(4./3.)*xinc*cos(angle_radian), //3
	                centerX-hyp*(cos(-angle_radian+theta)), //4
	                centerX-hyp*(cos(angle_radian+theta))}; //5
 		Double_t yL1[5] = {centerY-hyp*(sin(angle_radian+theta)), //1
	                centerY-hyp*(sin(-angle_radian+theta))-(4./3.)*xinc*sin(angle_radian), //2
	                centerY+hyp*(sin(angle_radian+theta))-(4./3.)*xinc*sin(angle_radian), //3
	                centerY+hyp*(sin(-angle_radian+theta)), //4
	                centerY-hyp*(sin(angle_radian+theta))};	   //5

		Double_t xC1[5] = {centerX+hyp*(cos(-angle_radian+theta))-(4./3.)*xinc*cos(angle_radian), //1
	                centerX-hyp*(cos(angle_radian+theta))+(4./3.)*xinc*cos(angle_radian), //2 
	                centerX-hyp*(cos(-angle_radian+theta))+(4./3.)*xinc*cos(angle_radian), //3
	                centerX+hyp*(cos(angle_radian+theta))-(4./3.)*xinc*cos(angle_radian), //4
	                centerX+hyp*(cos(-angle_radian+theta))-(4./3.)*xinc*cos(angle_radian)}; //5
 		Double_t yC1[5] = {centerY-hyp*(sin(-angle_radian+theta))-(4./3.)*xinc*sin(angle_radian), //1
	                centerY-hyp*(sin(angle_radian+theta))+(4./3.)*xinc*sin(angle_radian), //2
	                centerY+hyp*(sin(-angle_radian+theta))+(4./3.)*xinc*sin(angle_radian), //3
	                centerY+hyp*(sin(angle_radian+theta))-(4./3.)*xinc*sin(angle_radian), //4
	                centerY-hyp*(sin(-angle_radian+theta))-(4./3.)*xinc*sin(angle_radian)};	  //5

	    Double_t x0[5] = {0.,0.,0.,0.,0.};            
	    Double_t y0[5] = {0.,0.,0.,0.,0.};            
	                
   TPolyLine *pline;
   if(pos=="R"){
		pline = new TPolyLine(5,xR,yR);
   }
   if(pos=="L"){
		pline = new TPolyLine(5,xL,yL);
   }
   if(pos=="C"){
		pline = new TPolyLine(5,xC,yC);
   }
   if(pos=="R1"){
		pline = new TPolyLine(5,xR1,yR1);
   }
   if(pos=="L1"){
		pline = new TPolyLine(5,xL1,yL1);
   }
   if(pos=="C1"){
		pline = new TPolyLine(5,xC1,yC1);
   }
   if(pos=="none"){
		pline = new TPolyLine(5,x0,y0);
   }
   
   return pline;
}


/*
w = 0 -> W-2
w = 1 -> W-1
w = 2 -> W0
w = 3 -> W+1
w = 4 -> W+2 
*/ 
	
TCanvas *WheelPlot(int w, vector<string> name_station, vector<int> sector_number, vector<int> color_chamber, vector<int> style_chamber, bool just_one_chamber=false, TCanvas * c2 = 0){
  gStyle->SetOptStat(0);
   float PI = 3.141592653589793;  
   auto c1 = new TCanvas("c1","c1",4000,4000);
   Double_t layer_1_pos = 0.75;
   Double_t layer_2_pos = 0.65;
   Double_t layer_3_pos = 0.55;
   Double_t layer_4_pos = 0.5;
   Double_t layer_5_pos = 0.4;
   Double_t layer_6_pos = 0.35;
   Double_t layer_7_pos = 0.27;
   TText *t4 = new TText((0.495+(layer_7_pos*0.4)*sin(-0)),(0.5+(layer_7_pos*0.4)*cos(-0)),"4");
   t4->SetTextFont(43);
   t4->SetTextSize(70);
   t4->Draw();
   TText *t5 = new TText((0.495+(layer_7_pos*0.4)*sin(-30*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-30*(PI/180.0))),"5");
   t5->SetTextFont(43);
   t5->SetTextSize(70);
   t5->Draw();
   TText *t6 = new TText((0.495+(layer_7_pos*0.4)*sin(-60*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-60*(PI/180.0))),"6");
   t6->SetTextFont(43);
   t6->SetTextSize(70);
   t6->Draw();
   TText *t7 = new TText((0.495+(layer_7_pos*0.4)*sin(-90*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-90*(PI/180.0))),"7");
   t7->SetTextFont(43);
   t7->SetTextSize(70);
   t7->Draw();
   TText *t8 = new TText((0.495+(layer_7_pos*0.4)*sin(-120*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-120*(PI/180.0))),"8");
   t8->SetTextFont(43);
   t8->SetTextSize(70);
   t8->Draw();
   TText *t9 = new TText((0.495+(layer_7_pos*0.4)*sin(-150*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-150*(PI/180.0))),"9");
   t9->SetTextFont(43);
   t9->SetTextSize(70);
   t9->Draw();
   TText *t10 = new TText((0.495+(layer_7_pos*0.4)*sin(-180*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-180*(PI/180.0))),"10");
   t10->SetTextFont(43);
   t10->SetTextSize(70);
   t10->Draw();
   TText *t11 = new TText((0.495+(layer_7_pos*0.4)*sin(-210*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-210*(PI/180.0))),"11");
   t11->SetTextFont(43);
   t11->SetTextSize(70);
   t11->Draw();
   TText *t12 = new TText((0.495+(layer_7_pos*0.4)*sin(-240*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-240*(PI/180.0))),"12");
   t12->SetTextFont(43);
   t12->SetTextSize(70);
   t12->Draw();
   TText *t1 = new TText((0.495+(layer_7_pos*0.4)*sin(-270*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-270*(PI/180.0))),"1");
   t1->SetTextFont(43);
   t1->SetTextSize(70);
   t1->Draw();
   TText *t2 = new TText((0.495+(layer_7_pos*0.4)*sin(-300*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-300*(PI/180.0))),"2");
   t2->SetTextFont(43);
   t2->SetTextSize(70);
   t2->Draw();
   TText *t3 = new TText((0.495+(layer_7_pos*0.4)*sin(-330*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-330*(PI/180.0))),"3");
   t3->SetTextFont(43);
   t3->SetTextSize(70);
   t3->Draw();

   char center_w[400];
   if(w==0)	sprintf(center_w,"W-2"); 
   if(w==1)	sprintf(center_w,"W-1"); 
   if(w==2)	sprintf(center_w,"W0"); 
   if(w==3)	sprintf(center_w,"W+1"); 
   if(w==4)	sprintf(center_w,"W+2"); 
   
   TText *tcenter = new TText(0.48,0.5,center_w);
   tcenter->SetTextFont(43);
   tcenter->SetTextSize(100);
   tcenter->Draw();
   

   TLine *line4 = new TLine((0.495+(layer_7_pos*0.4)*sin(-15*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-15*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-15*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-15*(PI/180.0))));
   TLine *line5 = new TLine((0.495+(layer_7_pos*0.4)*sin(-45*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-45*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-45*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-45*(PI/180.0))));
   TLine *line6 = new TLine((0.495+(layer_7_pos*0.4)*sin(-75*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-75*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-75*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-75*(PI/180.0))));
   TLine *line7 = new TLine((0.495+(layer_7_pos*0.4)*sin(-105*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-105*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-105*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-105*(PI/180.0))));
   TLine *line8 = new TLine((0.495+(layer_7_pos*0.4)*sin(-135*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-135*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-135*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-135*(PI/180.0))));
   TLine *line9 = new TLine((0.495+(layer_7_pos*0.4)*sin(-165*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-165*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-165*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-165*(PI/180.0))));
   TLine *line10 = new TLine((0.495+(layer_7_pos*0.4)*sin(-195*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-195*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-195*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-195*(PI/180.0))));
   TLine *line11 = new TLine((0.495+(layer_7_pos*0.4)*sin(-225*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-225*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-225*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-225*(PI/180.0))));
   TLine *line12 = new TLine((0.495+(layer_7_pos*0.4)*sin(-255*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-255*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-255*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-255*(PI/180.0))));
   TLine *line1 = new TLine((0.495+(layer_7_pos*0.4)*sin(-285*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-285*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-285*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-285*(PI/180.0))));
   TLine *line2 = new TLine((0.495+(layer_7_pos*0.4)*sin(-315*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-315*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-315*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-315*(PI/180.0))));
   TLine *line3 = new TLine((0.495+(layer_7_pos*0.4)*sin(-345*(PI/180.0))),(0.5+(layer_7_pos*0.4)*cos(-345*(PI/180.0))),(0.495+(layer_1_pos*0.4)*sin(-345*(PI/180.0))),(0.5+(layer_1_pos*0.4)*cos(-345*(PI/180.0))));
   line4->SetLineWidth(1);
   line5->SetLineWidth(1);
   line6->SetLineWidth(1);
   line7->SetLineWidth(1);
   line8->SetLineWidth(1);
   line9->SetLineWidth(1);
   line10->SetLineWidth(1);
   line11->SetLineWidth(1);
   line12->SetLineWidth(1);
   line1->SetLineWidth(1);
   line2->SetLineWidth(1);
   line3->SetLineWidth(1);
   line4->Draw();
   line5->Draw();
   line6->Draw();
   line7->Draw();
   line8->Draw();
   line9->Draw();
   line10->Draw();
   line11->Draw();
   line12->Draw();
   line1->Draw();
   line2->Draw();
   line3->Draw();

   //Define RB2
   char rb2_3_1_1[400];
   char rb2_3_1_2[400];
   char rb2_3_1_3[400];
   char rb2_4_1_1[400];
   char rb2_4_1_2[400];
   char rb2_4_1_3[400];
   if(w==0 || w==4){
		sprintf(rb2_3_1_1,"R1");
		sprintf(rb2_3_1_2,"L1");
		sprintf(rb2_3_1_3,"C1");
		sprintf(rb2_4_1_1,"R");
		sprintf(rb2_4_1_2,"L");
		sprintf(rb2_4_1_3,"none");
   } else {
		sprintf(rb2_3_1_1,"R");
		sprintf(rb2_3_1_2,"L");
		sprintf(rb2_3_1_3,"none");
		sprintf(rb2_4_1_1,"R1");
		sprintf(rb2_4_1_2,"L1");
		sprintf(rb2_4_1_3,"C1");
   }

   vector<TPolyLine*> chambers_boxes;
   vector<string> chambers_names;
   vector<int> chambers_sector;

///////////sector 4

   //RB4
   TPolyLine *pline4_1_1 = makeBox(layer_1_pos,-7.5,0.01);
   pline4_1_1->Draw();
   TPolyLine *pline4_1_1_1 = makeBox(layer_1_pos,-7.5,0.01,"R");
   pline4_1_1_1->SetLineWidth(0);
   TPolyLine *pline4_1_1_2 = makeBox(layer_1_pos,-7.5,0.01,"L");
   pline4_1_1_2->SetLineWidth(0);
   
   TPolyLine *pline4_1_2 = makeBox(layer_1_pos,-2.5,0.01);
   pline4_1_2->Draw();
   TPolyLine *pline4_1_2_1 = makeBox(layer_1_pos,-2.5,0.01,"R");
   pline4_1_2_1->SetLineWidth(0);
   TPolyLine *pline4_1_2_2 = makeBox(layer_1_pos,-2.5,0.01,"L");
   pline4_1_2_2->SetLineWidth(0);
   
   TPolyLine *pline4_1_3 = makeBox(layer_1_pos,2.5,0.01);
   pline4_1_3->Draw();
   TPolyLine *pline4_1_3_1 = makeBox(layer_1_pos,2.5,0.01,"R");
   pline4_1_3_1->SetLineWidth(0);
   TPolyLine *pline4_1_3_2 = makeBox(layer_1_pos,2.5,0.01,"L");
   pline4_1_3_2->SetLineWidth(0);
   
   TPolyLine *pline4_1_4 = makeBox(layer_1_pos,7.5,0.01);
   pline4_1_4->Draw();
   TPolyLine *pline4_1_4_1 = makeBox(layer_1_pos,7.5,0.01,"R");
   pline4_1_4_1->SetLineWidth(0);
   TPolyLine *pline4_1_4_2 = makeBox(layer_1_pos,7.5,0.01,"L");
   pline4_1_4_2->SetLineWidth(0);
   
   //RB3
   TPolyLine *pline4_2_1 = makeBox(layer_2_pos,-5.,0.02);
   pline4_2_1->Draw();
   TPolyLine *pline4_2_1_1 = makeBox(layer_2_pos,-5.,0.02,"R");
   pline4_2_1_1->SetLineWidth(0);
   TPolyLine *pline4_2_1_2 = makeBox(layer_2_pos,-5.,0.02,"L");
   pline4_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline4_2_2 = makeBox(layer_2_pos,+5.,0.02);
   pline4_2_2->Draw();
   TPolyLine *pline4_2_2_1 = makeBox(layer_2_pos,+5.,0.02,"R");
   pline4_2_2_1->SetLineWidth(0);
   TPolyLine *pline4_2_2_2 = makeBox(layer_2_pos,+5.,0.02,"L");
   pline4_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline4_3_1 = makeBox(layer_3_pos,0.,0.02);
   pline4_3_1->Draw();
   TPolyLine *pline4_3_1_1 = makeBox(layer_3_pos,0.,0.02,rb2_3_1_1);
   pline4_3_1_1->SetLineWidth(0);
   TPolyLine *pline4_3_1_2 = makeBox(layer_3_pos,0.,0.02,rb2_3_1_2);
   pline4_3_1_2->SetLineWidth(0);
   TPolyLine *pline4_3_1_3 = makeBox(layer_3_pos,0.,0.02,rb2_3_1_3);
   pline4_3_1_3->SetLineWidth(0);
   
   TPolyLine *pline4_4_1 = makeBox(layer_4_pos,0.,0.02);
   pline4_4_1->Draw();
   TPolyLine *pline4_4_1_1 = makeBox(layer_4_pos,0.,0.02,rb2_4_1_1);
   pline4_4_1_1->SetLineWidth(0);
   TPolyLine *pline4_4_1_2 = makeBox(layer_4_pos,0.,0.02,rb2_4_1_2);
   pline4_4_1_2->SetLineWidth(0);
   TPolyLine *pline4_4_1_3 = makeBox(layer_4_pos,0.,0.02,rb2_4_1_3);
   pline4_4_1_3->SetLineWidth(0);   
   
   //RB1
   TPolyLine *pline4_5_1 = makeBox(layer_5_pos,0.,0.02);
   pline4_5_1->Draw();
   TPolyLine *pline4_5_1_1 = makeBox(layer_5_pos,0.,0.02,"R");
   pline4_5_1_1->SetLineWidth(0);
   TPolyLine *pline4_5_1_2 = makeBox(layer_5_pos,0.,0.02,"L");
   pline4_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline4_6_1 = makeBox(layer_6_pos,0.,0.02);
   pline4_6_1->Draw();
   TPolyLine *pline4_6_1_1 = makeBox(layer_6_pos,0.,0.02,"R");
   pline4_6_1_1->SetLineWidth(0);
   TPolyLine *pline4_6_1_2 = makeBox(layer_6_pos,0.,0.02,"L");
   pline4_6_1_2->SetLineWidth(0);


///////////sector 5   

   //RB4
   TPolyLine *pline5_1_1 = makeBox(layer_1_pos,25.,0.02);
   pline5_1_1->Draw();
   TPolyLine *pline5_1_1_1 = makeBox(layer_1_pos,25.,0.02,"R");
   pline5_1_1_1->SetLineWidth(0);
   TPolyLine *pline5_1_1_2 = makeBox(layer_1_pos,25.,0.02,"L");
   pline5_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline5_1_2 = makeBox(layer_1_pos,35.,0.02);
   pline5_1_2->Draw();
   TPolyLine *pline5_1_2_1 = makeBox(layer_1_pos,35.,0.02,"R");
   pline5_1_2_1->SetLineWidth(0);
   TPolyLine *pline5_1_2_2 = makeBox(layer_1_pos,35.,0.02,"L");
   pline5_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline5_2_1 = makeBox(layer_2_pos,25.,0.02);
   pline5_2_1->Draw();
   TPolyLine *pline5_2_1_1 = makeBox(layer_2_pos,25.,0.02,"R");
   pline5_2_1_1->SetLineWidth(0);
   TPolyLine *pline5_2_1_2 = makeBox(layer_2_pos,25.,0.02,"L");
   pline5_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline5_2_2 = makeBox(layer_2_pos,35.,0.02);
   pline5_2_2->Draw();
   TPolyLine *pline5_2_2_1 = makeBox(layer_2_pos,35.,0.02,"R");
   pline5_2_2_1->SetLineWidth(0);
   TPolyLine *pline5_2_2_2 = makeBox(layer_2_pos,35.,0.02,"L");
   pline5_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline5_3_1 = makeBox(layer_3_pos,30.,0.02);
   pline5_3_1->Draw();
   TPolyLine *pline5_3_1_1 = makeBox(layer_3_pos,30.,0.02,rb2_3_1_1);
   pline5_3_1_1->SetLineWidth(0);
   TPolyLine *pline5_3_1_2 = makeBox(layer_3_pos,30.,0.02,rb2_3_1_2);
   pline5_3_1_2->SetLineWidth(0);
   TPolyLine *pline5_3_1_3 = makeBox(layer_3_pos,30.,0.02,rb2_3_1_3);
   pline5_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline5_4_1 = makeBox(layer_4_pos,30.,0.02);
   TPolyLine *pline5_4 = makeBox(layer_4_pos,30.,0.02);
   pline5_4_1->Draw();
   TPolyLine *pline5_4_1_1 = makeBox(layer_4_pos,30.,0.02,rb2_4_1_1);
   pline5_4_1_1->SetLineWidth(0);
   TPolyLine *pline5_4_1_2 = makeBox(layer_4_pos,30.,0.02,rb2_4_1_2);
   pline5_4_1_2->SetLineWidth(0);
   TPolyLine *pline5_4_1_3 = makeBox(layer_4_pos,30.,0.02,rb2_4_1_3);
   pline5_4_1_3->SetLineWidth(0);      
   
   //RB1
   TPolyLine *pline5_5_1 = makeBox(layer_5_pos,30.,0.02);
   pline5_5_1->Draw();
   TPolyLine *pline5_5_1_1 = makeBox(layer_5_pos,30.,0.02,"R");
   pline5_5_1_1->SetLineWidth(0);
   TPolyLine *pline5_5_1_2 = makeBox(layer_5_pos,30.,0.02,"L");
   pline5_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline5_6_1 = makeBox(layer_6_pos,30.,0.02);
   pline5_6_1->Draw();
   TPolyLine *pline5_6_1_1 = makeBox(layer_6_pos,30.,0.02,"R");
   pline5_6_1_1->SetLineWidth(0);
   TPolyLine *pline5_6_1_2 = makeBox(layer_6_pos,30.,0.02,"L");
   pline5_6_1_2->SetLineWidth(0);


///////////sector 6   

   //RB4
   TPolyLine *pline6_1_1 = makeBox(layer_1_pos,55.,0.02);
   pline6_1_1->Draw();
   TPolyLine *pline6_1_1_1 = makeBox(layer_1_pos,55.,0.02,"R");
   pline6_1_1_1->SetLineWidth(0);
   TPolyLine *pline6_1_1_2 = makeBox(layer_1_pos,55.,0.02,"L");
   pline6_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline6_1_2 = makeBox(layer_1_pos,65.,0.02);
   pline6_1_2->Draw();
   TPolyLine *pline6_1_2_1 = makeBox(layer_1_pos,65.,0.02,"R");
   pline6_1_2_1->SetLineWidth(0);
   TPolyLine *pline6_1_2_2 = makeBox(layer_1_pos,65.,0.02,"L");
   pline6_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline6_2_1 = makeBox(layer_2_pos,55.,0.02);
   pline6_2_1->Draw();
   TPolyLine *pline6_2_1_1 = makeBox(layer_2_pos,55.,0.02,"R");
   pline6_2_1_1->SetLineWidth(0);
   TPolyLine *pline6_2_1_2 = makeBox(layer_2_pos,55.,0.02,"L");
   pline6_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline6_2_2 = makeBox(layer_2_pos,65.,0.02);
   pline6_2_2->Draw();
   TPolyLine *pline6_2_2_1 = makeBox(layer_2_pos,65.,0.02,"R");
   pline6_2_2_1->SetLineWidth(0);
   TPolyLine *pline6_2_2_2 = makeBox(layer_2_pos,65.,0.02,"L");
   pline6_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline6_3_1 = makeBox(layer_3_pos,60.,0.02);
   pline6_3_1->Draw();
   TPolyLine *pline6_3_1_1 = makeBox(layer_3_pos,60.,0.02,rb2_3_1_1);
   pline6_3_1_1->SetLineWidth(0);
   TPolyLine *pline6_3_1_2 = makeBox(layer_3_pos,60.,0.02,rb2_3_1_2);
   pline6_3_1_2->SetLineWidth(0);
   TPolyLine *pline6_3_1_3 = makeBox(layer_3_pos,60.,0.02,rb2_3_1_3);
   pline6_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline6_4_1 = makeBox(layer_4_pos,60.,0.02);
   pline6_4_1->Draw();
   TPolyLine *pline6_4_1_1 = makeBox(layer_4_pos,60.,0.02,rb2_4_1_1);
   pline6_4_1_1->SetLineWidth(0);
   TPolyLine *pline6_4_1_2 = makeBox(layer_4_pos,60.,0.02,rb2_4_1_2);
   pline6_4_1_2->SetLineWidth(0);
   TPolyLine *pline6_4_1_3 = makeBox(layer_4_pos,60.,0.02,rb2_4_1_3);
   pline6_4_1_3->SetLineWidth(0);      
   
   //RB1
   TPolyLine *pline6_5_1 = makeBox(layer_5_pos,60.,0.02);
   pline6_5_1->Draw();
   TPolyLine *pline6_5_1_1 = makeBox(layer_5_pos,60.,0.02,"R");
   pline6_5_1_1->SetLineWidth(0);
   TPolyLine *pline6_5_1_2 = makeBox(layer_5_pos,60.,0.02,"L");
   pline6_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline6_6_1 = makeBox(layer_6_pos,60.,0.02);
   pline6_6_1->Draw();
   TPolyLine *pline6_6_1_1 = makeBox(layer_6_pos,60.,0.02,"R");
   pline6_6_1_1->SetLineWidth(0);
   TPolyLine *pline6_6_1_2 = makeBox(layer_6_pos,60.,0.02,"L");
   pline6_6_1_2->SetLineWidth(0);



///////////sector 7    
   //RB4
   TPolyLine *pline7_1_1 = makeBox(layer_1_pos,85.,0.02);
   pline7_1_1->Draw();
   TPolyLine *pline7_1_1_1 = makeBox(layer_1_pos,85.,0.02,"R");
   pline7_1_1_1->SetLineWidth(0);
   TPolyLine *pline7_1_1_2 = makeBox(layer_1_pos,85.,0.02,"L");
   pline7_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline7_1_2 = makeBox(layer_1_pos,95.,0.02);
   pline7_1_2->Draw();
   TPolyLine *pline7_1_2_1 = makeBox(layer_1_pos,95.,0.02,"R");
   pline7_1_2_1->SetLineWidth(0);
   TPolyLine *pline7_1_2_2 = makeBox(layer_1_pos,95.,0.02,"L");
   pline7_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline7_2_1 = makeBox(layer_2_pos,85.,0.02);
   pline7_2_1->Draw();
   TPolyLine *pline7_2_1_1 = makeBox(layer_2_pos,85.,0.02,"R");
   pline7_2_1_1->SetLineWidth(0);
   TPolyLine *pline7_2_1_2 = makeBox(layer_2_pos,85.,0.02,"L");
   pline7_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline7_2_2 = makeBox(layer_2_pos,95.,0.02);
   pline7_2_2->Draw();
   TPolyLine *pline7_2_2_1 = makeBox(layer_2_pos,95.,0.02,"R");
   pline7_2_2_1->SetLineWidth(0);
   TPolyLine *pline7_2_2_2 = makeBox(layer_2_pos,95.,0.02,"L");
   pline7_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline7_3_1 = makeBox(layer_3_pos,90.,0.02);
   pline7_3_1->Draw();
   TPolyLine *pline7_3_1_1 = makeBox(layer_3_pos,90.,0.02,rb2_3_1_1);
   pline7_3_1_1->SetLineWidth(0);
   TPolyLine *pline7_3_1_2 = makeBox(layer_3_pos,90.,0.02,rb2_3_1_2);
   pline7_3_1_2->SetLineWidth(0);
   TPolyLine *pline7_3_1_3 = makeBox(layer_3_pos,90.,0.02,rb2_3_1_3);
   pline7_3_1_3->SetLineWidth(0);
   
   TPolyLine *pline7_4_1 = makeBox(layer_4_pos,90.,0.02);
   pline7_4_1->Draw();
   TPolyLine *pline7_4_1_1 = makeBox(layer_4_pos,90.,0.02,rb2_4_1_1);
   pline7_4_1_1->SetLineWidth(0);
   TPolyLine *pline7_4_1_2 = makeBox(layer_4_pos,90.,0.02,rb2_4_1_2);
   pline7_4_1_2->SetLineWidth(0);
   TPolyLine *pline7_4_1_3 = makeBox(layer_4_pos,90.,0.02,rb2_4_1_3);
   pline7_4_1_3->SetLineWidth(0);    
   
   //RB1
   TPolyLine *pline7_5_1 = makeBox(layer_5_pos,90.,0.02);
   pline7_5_1->Draw();
   TPolyLine *pline7_5_1_1 = makeBox(layer_5_pos,90.,0.02,"R");
   pline7_5_1_1->SetLineWidth(0);
   TPolyLine *pline7_5_1_2 = makeBox(layer_5_pos,90.,0.02,"L");
   pline7_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline7_6_1 = makeBox(layer_6_pos,90.,0.02);
   pline7_6_1->Draw();
   TPolyLine *pline7_6_1_1 = makeBox(layer_6_pos,90.,0.02,"R");
   pline7_6_1_1->SetLineWidth(0);
   TPolyLine *pline7_6_1_2 = makeBox(layer_6_pos,90.,0.02,"L");
   pline7_6_1_2->SetLineWidth(0);


///////////sector 8    
   //RB4
   TPolyLine *pline8_1_1 = makeBox(layer_1_pos,115.,0.02);
   pline8_1_1->Draw();
   TPolyLine *pline8_1_1_1 = makeBox(layer_1_pos,115.,0.02,"R");
   pline8_1_1_1->SetLineWidth(0);
   TPolyLine *pline8_1_1_2 = makeBox(layer_1_pos,115.,0.02,"L");
   pline8_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline8_1_2 = makeBox(layer_1_pos,125.,0.02);
   pline8_1_2->Draw();
   TPolyLine *pline8_1_2_1 = makeBox(layer_1_pos,125.,0.02,"R");
   pline8_1_2_1->SetLineWidth(0);
   TPolyLine *pline8_1_2_2 = makeBox(layer_1_pos,125.,0.02,"L");
   pline8_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline8_2_1 = makeBox(layer_2_pos,115.,0.02);
   pline8_2_1->Draw();
   TPolyLine *pline8_2_1_1 = makeBox(layer_2_pos,115.,0.02,"R");
   pline8_2_1_1->SetLineWidth(0);
   TPolyLine *pline8_2_1_2 = makeBox(layer_2_pos,115.,0.02,"L");
   pline8_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline8_2_2 = makeBox(layer_2_pos,125.,0.02);
   pline8_2_2->Draw();
   TPolyLine *pline8_2_2_1 = makeBox(layer_2_pos,125.,0.02,"R");
   pline8_2_2_1->SetLineWidth(0);
   TPolyLine *pline8_2_2_2 = makeBox(layer_2_pos,125.,0.02,"L");
   pline8_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline8_3_1 = makeBox(layer_3_pos,120.,0.02);
   pline8_3_1->Draw();
   TPolyLine *pline8_3_1_1 = makeBox(layer_3_pos,120.,0.02,rb2_3_1_1);
   pline8_3_1_1->SetLineWidth(0);
   TPolyLine *pline8_3_1_2 = makeBox(layer_3_pos,120.,0.02,rb2_3_1_2);
   pline8_3_1_2->SetLineWidth(0);
   TPolyLine *pline8_3_1_3 = makeBox(layer_3_pos,120.,0.02,rb2_3_1_3);
   pline8_3_1_3->SetLineWidth(0);
   
   TPolyLine *pline8_4_1 = makeBox(layer_4_pos,120.,0.02);
   pline8_4_1->Draw();
   TPolyLine *pline8_4_1_1 = makeBox(layer_4_pos,120.,0.02,rb2_4_1_1);
   pline8_4_1_1->SetLineWidth(0);
   TPolyLine *pline8_4_1_2 = makeBox(layer_4_pos,120.,0.02,rb2_4_1_2);
   pline8_4_1_2->SetLineWidth(0);
   TPolyLine *pline8_4_1_3 = makeBox(layer_4_pos,120.,0.02,rb2_4_1_3);
   pline8_4_1_3->SetLineWidth(0);    
   
   //RB1
   TPolyLine *pline8_5_1 = makeBox(layer_5_pos,120.,0.02);
   pline8_5_1->Draw();
   TPolyLine *pline8_5_1_1 = makeBox(layer_5_pos,120.,0.02,"R");
   pline8_5_1_1->SetLineWidth(0);
   TPolyLine *pline8_5_1_2 = makeBox(layer_5_pos,120.,0.02,"L");
   pline8_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline8_6_1 = makeBox(layer_6_pos,120.,0.02);
   pline8_6_1->Draw();
   TPolyLine *pline8_6_1_1 = makeBox(layer_6_pos,120.,0.02,"R");
   pline8_6_1_1->SetLineWidth(0);
   TPolyLine *pline8_6_1_2 = makeBox(layer_6_pos,120.,0.02,"L");
   pline8_6_1_2->SetLineWidth(0);


///////////sector 9    
   //RB4
   TPolyLine *pline9_1_1 = makeBox(layer_1_pos,150.,0.02);
   pline9_1_1->Draw();
   TPolyLine *pline9_1_1_1 = makeBox(layer_1_pos,150.,0.02,"R");
   pline9_1_1_1->SetLineWidth(0);
   TPolyLine *pline9_1_1_2 = makeBox(layer_1_pos,150.,0.02,"L");
   pline9_1_1_2->SetLineWidth(0);    

    
   //RB3
   TPolyLine *pline9_2_1 = makeBox(layer_2_pos,145.,0.02);
   pline9_2_1->Draw();
   TPolyLine *pline9_2_1_1 = makeBox(layer_2_pos,145.,0.02,"R");
   pline9_2_1_1->SetLineWidth(0);
   TPolyLine *pline9_2_1_2 = makeBox(layer_2_pos,145.,0.02,"L");
   pline9_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline9_2_2 = makeBox(layer_2_pos,155.,0.02);
   pline9_2_2->Draw();
   TPolyLine *pline9_2_2_1 = makeBox(layer_2_pos,155.,0.02,"R");
   pline9_2_2_1->SetLineWidth(0);
   TPolyLine *pline9_2_2_2 = makeBox(layer_2_pos,155.,0.02,"L");
   pline9_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline9_3_1 = makeBox(layer_3_pos,150.,0.02);
   pline9_3_1->Draw();
   TPolyLine *pline9_3_1_1 = makeBox(layer_3_pos,150.,0.02,rb2_3_1_1);
   pline9_3_1_1->SetLineWidth(0);
   TPolyLine *pline9_3_1_2 = makeBox(layer_3_pos,150.,0.02,rb2_3_1_2);
   pline9_3_1_2->SetLineWidth(0);
   TPolyLine *pline9_3_1_3 = makeBox(layer_3_pos,150.,0.02,rb2_3_1_3);
   pline9_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline9_4_1 = makeBox(layer_4_pos,150.,0.02);
   pline9_4_1->Draw();
   TPolyLine *pline9_4_1_1 = makeBox(layer_4_pos,150.,0.02,rb2_4_1_1);
   pline9_4_1_1->SetLineWidth(0);
   TPolyLine *pline9_4_1_2 = makeBox(layer_4_pos,150.,0.02,rb2_4_1_2);
   pline9_4_1_2->SetLineWidth(0);
   TPolyLine *pline9_4_1_3 = makeBox(layer_4_pos,150.,0.02,rb2_4_1_3);
   pline9_4_1_3->SetLineWidth(0);    
   
   //RB1
   TPolyLine *pline9_5_1 = makeBox(layer_5_pos,150.,0.02);
   pline9_5_1->Draw();
   TPolyLine *pline9_5_1_1 = makeBox(layer_5_pos,150.,0.02,"R");
   pline9_5_1_1->SetLineWidth(0);
   TPolyLine *pline9_5_1_2 = makeBox(layer_5_pos,150.,0.02,"L");
   pline9_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline9_6_1 = makeBox(layer_6_pos,150.,0.02);
   pline9_6_1->Draw();
   TPolyLine *pline9_6_1_1 = makeBox(layer_6_pos,150.,0.02,"R");
   pline9_6_1_1->SetLineWidth(0);
   TPolyLine *pline9_6_1_2 = makeBox(layer_6_pos,150.,0.02,"L");
   pline9_6_1_2->SetLineWidth(0);


///////////sector 10    
   //RB4
   TPolyLine *pline10_1_1 = makeBox(layer_1_pos,175.,0.02);
   pline10_1_1->Draw();
   TPolyLine *pline10_1_1_1 = makeBox(layer_1_pos,175.,0.02,"R");
   pline10_1_1_1->SetLineWidth(0);
   TPolyLine *pline10_1_1_2 = makeBox(layer_1_pos,175.,0.02,"L");
   pline10_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline10_1_2 = makeBox(layer_1_pos,185.,0.02);
   pline10_1_2->Draw();
   TPolyLine *pline10_1_2_1 = makeBox(layer_1_pos,185.,0.02,"R");
   pline10_1_2_1->SetLineWidth(0);
   TPolyLine *pline10_1_2_2 = makeBox(layer_1_pos,185.,0.02,"L");
   pline10_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline10_2_1 = makeBox(layer_2_pos,175.,0.02);
   pline10_2_1->Draw();
   TPolyLine *pline10_2_1_1 = makeBox(layer_2_pos,175.,0.02,"R");
   pline10_2_1_1->SetLineWidth(0);
   TPolyLine *pline10_2_1_2 = makeBox(layer_2_pos,175.,0.02,"L");
   pline10_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline10_2_2 = makeBox(layer_2_pos,185.,0.02);
   pline10_2_2->Draw();
   TPolyLine *pline10_2_2_1 = makeBox(layer_2_pos,185.,0.02,"R");
   pline10_2_2_1->SetLineWidth(0);
   TPolyLine *pline10_2_2_2 = makeBox(layer_2_pos,185.,0.02,"L");
   pline10_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline10_3_1 = makeBox(layer_3_pos,180.,0.02);
   pline10_3_1->Draw();
   TPolyLine *pline10_3_1_1 = makeBox(layer_3_pos,180.,0.02,rb2_3_1_1);
   pline10_3_1_1->SetLineWidth(0);
   TPolyLine *pline10_3_1_2 = makeBox(layer_3_pos,180.,0.02,rb2_3_1_2);
   pline10_3_1_2->SetLineWidth(0);
   TPolyLine *pline10_3_1_3 = makeBox(layer_3_pos,180.,0.02,rb2_3_1_3);
   pline10_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline10_4_1 = makeBox(layer_4_pos,180.,0.02);
   pline10_4_1->Draw();
   TPolyLine *pline10_4_1_1 = makeBox(layer_4_pos,180.,0.02,rb2_4_1_1);
   pline10_4_1_1->SetLineWidth(0);
   TPolyLine *pline10_4_1_2 = makeBox(layer_4_pos,180.,0.02,rb2_4_1_2);
   pline10_4_1_2->SetLineWidth(0);
   TPolyLine *pline10_4_1_3 = makeBox(layer_4_pos,180.,0.02,rb2_4_1_3);
   pline10_4_1_3->SetLineWidth(0);    
   
   //RB1
   TPolyLine *pline10_5_1 = makeBox(layer_5_pos,180.,0.02);
   pline10_5_1->Draw();
   TPolyLine *pline10_5_1_1 = makeBox(layer_5_pos,180.,0.02,"R");
   pline10_5_1_1->SetLineWidth(0);
   TPolyLine *pline10_5_1_2 = makeBox(layer_5_pos,180.,0.02,"L");
   pline10_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline10_6_1 = makeBox(layer_6_pos,180.,0.02);
   pline10_6_1->Draw();
   TPolyLine *pline10_6_1_1 = makeBox(layer_6_pos,180.,0.02,"R");
   pline10_6_1_1->SetLineWidth(0);
   TPolyLine *pline10_6_1_2 = makeBox(layer_6_pos,180.,0.02,"L");
   pline10_6_1_2->SetLineWidth(0);



///////////sector 11  
   //RB4
   TPolyLine *pline11_1_1 = makeBox(layer_1_pos,210.,0.02);
   pline11_1_1->Draw();
   TPolyLine *pline11_1_1_1 = makeBox(layer_1_pos,210.,0.02,"R");
   pline11_1_1_1->SetLineWidth(0);
   TPolyLine *pline11_1_1_2 = makeBox(layer_1_pos,210.,0.02,"L");
   pline11_1_1_2->SetLineWidth(0);
    
        
   //RB3
   TPolyLine *pline11_2_1 = makeBox(layer_2_pos,205.,0.02);
   pline11_2_1->Draw();
   TPolyLine *pline11_2_1_1 = makeBox(layer_2_pos,205.,0.02,"R");
   pline11_2_1_1->SetLineWidth(0);
   TPolyLine *pline11_2_1_2 = makeBox(layer_2_pos,205.,0.02,"L");
   pline11_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline11_2_2 = makeBox(layer_2_pos,215.,0.02);
   pline11_2_2->Draw();
   TPolyLine *pline11_2_2_1 = makeBox(layer_2_pos,215.,0.02,"R");
   pline11_2_2_1->SetLineWidth(0);
   TPolyLine *pline11_2_2_2 = makeBox(layer_2_pos,215.,0.02,"L");
   pline11_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline11_3_1 = makeBox(layer_3_pos,210.,0.02);
   pline11_3_1->Draw();
   TPolyLine *pline11_3_1_1 = makeBox(layer_3_pos,210.,0.02,rb2_3_1_1);
   pline11_3_1_1->SetLineWidth(0);
   TPolyLine *pline11_3_1_2 = makeBox(layer_3_pos,210.,0.02,rb2_3_1_2);
   pline11_3_1_2->SetLineWidth(0);
   TPolyLine *pline11_3_1_3 = makeBox(layer_3_pos,210.,0.02,rb2_3_1_3);
   pline11_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline11_4_1 = makeBox(layer_4_pos,210.,0.02);
   pline11_4_1->Draw();
   TPolyLine *pline11_4_1_1 = makeBox(layer_4_pos,210.,0.02,rb2_4_1_1);
   pline11_4_1_1->SetLineWidth(0);
   TPolyLine *pline11_4_1_2 = makeBox(layer_4_pos,210.,0.02,rb2_4_1_2);
   pline11_4_1_2->SetLineWidth(0);
   TPolyLine *pline11_4_1_3 = makeBox(layer_4_pos,210.,0.02,rb2_4_1_3);
   pline11_4_1_3->SetLineWidth(0);     
   
   //RB1
   TPolyLine *pline11_5_1 = makeBox(layer_5_pos,210.,0.02);
   pline11_5_1->Draw();
   TPolyLine *pline11_5_1_1 = makeBox(layer_5_pos,210.,0.02,"R");
   pline11_5_1_1->SetLineWidth(0);
   TPolyLine *pline11_5_1_2 = makeBox(layer_5_pos,210.,0.02,"L");
   pline11_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline11_6_1 = makeBox(layer_6_pos,210.,0.02);
   pline11_6_1->Draw();
   TPolyLine *pline11_6_1_1 = makeBox(layer_6_pos,210.,0.02,"R");
   pline11_6_1_1->SetLineWidth(0);
   TPolyLine *pline11_6_1_2 = makeBox(layer_6_pos,210.,0.02,"L");
   pline11_6_1_2->SetLineWidth(0);



///////////sector 12   
   //RB4
   TPolyLine *pline12_1_1 = makeBox(layer_1_pos,235.,0.02);
   pline12_1_1->Draw();
   TPolyLine *pline12_1_1_1 = makeBox(layer_1_pos,235.,0.02,"R");
   pline12_1_1_1->SetLineWidth(0);
   TPolyLine *pline12_1_1_2 = makeBox(layer_1_pos,235.,0.02,"L");
   pline12_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline12_1_2 = makeBox(layer_1_pos,245.,0.02);
   pline12_1_2->Draw();
   TPolyLine *pline12_1_2_1 = makeBox(layer_1_pos,245.,0.02,"R");
   pline12_1_2_1->SetLineWidth(0);
   TPolyLine *pline12_1_2_2 = makeBox(layer_1_pos,245.,0.02,"L");
   pline12_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline12_2_1 = makeBox(layer_2_pos,235.,0.02);
   pline12_2_1->Draw();
   TPolyLine *pline12_2_1_1 = makeBox(layer_2_pos,235.,0.02,"R");
   pline12_2_1_1->SetLineWidth(0);
   TPolyLine *pline12_2_1_2 = makeBox(layer_2_pos,235.,0.02,"L");
   pline12_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline12_2_2 = makeBox(layer_2_pos,245.,0.02);
   pline12_2_2->Draw();
   TPolyLine *pline12_2_2_1 = makeBox(layer_2_pos,245.,0.02,"R");
   pline12_2_2_1->SetLineWidth(0);
   TPolyLine *pline12_2_2_2 = makeBox(layer_2_pos,245.,0.02,"L");
   pline12_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline12_3_1 = makeBox(layer_3_pos,240.,0.02);
   pline12_3_1->Draw();
   TPolyLine *pline12_3_1_1 = makeBox(layer_3_pos,240.,0.02,rb2_3_1_1);
   pline12_3_1_1->SetLineWidth(0);
   TPolyLine *pline12_3_1_2 = makeBox(layer_3_pos,240.,0.02,rb2_3_1_2);
   pline12_3_1_2->SetLineWidth(0);
   TPolyLine *pline12_3_1_3 = makeBox(layer_3_pos,240.,0.02,rb2_3_1_3);
   pline12_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline12_4_1 = makeBox(layer_4_pos,240.,0.02);
   pline12_4_1->Draw();
   TPolyLine *pline12_4_1_1 = makeBox(layer_4_pos,240.,0.02,rb2_4_1_1);
   pline12_4_1_1->SetLineWidth(0);
   TPolyLine *pline12_4_1_2 = makeBox(layer_4_pos,240.,0.02,rb2_4_1_2);
   pline12_4_1_2->SetLineWidth(0);
   TPolyLine *pline12_4_1_3 = makeBox(layer_4_pos,240.,0.02,rb2_4_1_3);
   pline12_4_1_3->SetLineWidth(0);     
   
   //RB1
   TPolyLine *pline12_5_1 = makeBox(layer_5_pos,240.,0.02);
   pline12_5_1->Draw();
   TPolyLine *pline12_5_1_1 = makeBox(layer_5_pos,240.,0.02,"R");
   pline12_5_1_1->SetLineWidth(0);
   TPolyLine *pline12_5_1_2 = makeBox(layer_5_pos,240.,0.02,"L");
   pline12_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline12_6_1 = makeBox(layer_6_pos,240.,0.02);
   pline12_6_1->Draw();
   TPolyLine *pline12_6_1_1 = makeBox(layer_6_pos,240.,0.02,"R");
   pline12_6_1_1->SetLineWidth(0);
   TPolyLine *pline12_6_1_2 = makeBox(layer_6_pos,240.,0.02,"L");
   pline12_6_1_2->SetLineWidth(0);


///////////sector 1   
   //RB4
   TPolyLine *pline1_1_1 = makeBox(layer_1_pos,265.,0.02);
   pline1_1_1->Draw();
   TPolyLine *pline1_1_1_1 = makeBox(layer_1_pos,265.,0.02,"R");
   pline1_1_1_1->SetLineWidth(0);
   TPolyLine *pline1_1_1_2 = makeBox(layer_1_pos,265.,0.02,"L");
   pline1_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline1_1_2 = makeBox(layer_1_pos,275.,0.02);
   pline1_1_2->Draw();
   TPolyLine *pline1_1_2_1 = makeBox(layer_1_pos,275.,0.02,"R");
   pline1_1_2_1->SetLineWidth(0);
   TPolyLine *pline1_1_2_2 = makeBox(layer_1_pos,275.,0.02,"L");
   pline1_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline1_2_1 = makeBox(layer_2_pos,265.,0.02);
   pline1_2_1->Draw();
   TPolyLine *pline1_2_1_1 = makeBox(layer_2_pos,265.,0.02,"R");
   pline1_2_1_1->SetLineWidth(0);
   TPolyLine *pline1_2_1_2 = makeBox(layer_2_pos,265.,0.02,"L");
   pline1_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline1_2_2 = makeBox(layer_2_pos,275.,0.02);
   pline1_2_2->Draw();
   TPolyLine *pline1_2_2_1 = makeBox(layer_2_pos,275.,0.02,"R");
   pline1_2_2_1->SetLineWidth(0);
   TPolyLine *pline1_2_2_2 = makeBox(layer_2_pos,275.,0.02,"L");
   pline1_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline1_3_1 = makeBox(layer_3_pos,270.,0.02);
   pline1_3_1->Draw();
   TPolyLine *pline1_3_1_1 = makeBox(layer_3_pos,270.,0.02,rb2_3_1_1);
   pline1_3_1_1->SetLineWidth(0);
   TPolyLine *pline1_3_1_2 = makeBox(layer_3_pos,270.,0.02,rb2_3_1_2);
   pline1_3_1_2->SetLineWidth(0);
   TPolyLine *pline1_3_1_3 = makeBox(layer_3_pos,270.,0.02,rb2_3_1_3);
   pline1_3_1_3->SetLineWidth(0);
      
   TPolyLine *pline1_4_1 = makeBox(layer_4_pos,270.,0.02);
   pline1_4_1->Draw();
   TPolyLine *pline1_4_1_1 = makeBox(layer_4_pos,270.,0.02,rb2_4_1_1);
   pline1_4_1_1->SetLineWidth(0);
   TPolyLine *pline1_4_1_2 = makeBox(layer_4_pos,270.,0.02,rb2_4_1_2);
   pline1_4_1_2->SetLineWidth(0);
   TPolyLine *pline1_4_1_3 = makeBox(layer_4_pos,270.,0.02,rb2_4_1_3);
   pline1_4_1_3->SetLineWidth(0);     
   
   //RB1
   TPolyLine *pline1_5_1 = makeBox(layer_5_pos,270.,0.02);
   pline1_5_1->Draw();
   TPolyLine *pline1_5_1_1 = makeBox(layer_5_pos,270.,0.02,"R");
   pline1_5_1_1->SetLineWidth(0);
   TPolyLine *pline1_5_1_2 = makeBox(layer_5_pos,270.,0.02,"L");
   pline1_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline1_6_1 = makeBox(layer_6_pos,270.,0.02);
   pline1_6_1->Draw();
   TPolyLine *pline1_6_1_1 = makeBox(layer_6_pos,270.,0.02,"R");
   pline1_6_1_1->SetLineWidth(0);
   TPolyLine *pline1_6_1_2 = makeBox(layer_6_pos,270.,0.02,"L");
   pline1_6_1_2->SetLineWidth(0);
 

///////////sector 2    
   //RB4
   TPolyLine *pline2_1_1 = makeBox(layer_1_pos,295.,0.02);
   pline2_1_1->Draw();
   TPolyLine *pline2_1_1_1 = makeBox(layer_1_pos,295.,0.02,"R");
   pline2_1_1_1->SetLineWidth(0);
   TPolyLine *pline2_1_1_2 = makeBox(layer_1_pos,295.,0.02,"L");
   pline2_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline2_1_2 = makeBox(layer_1_pos,305.,0.02);
   pline2_1_2->Draw();
   TPolyLine *pline2_1_2_1 = makeBox(layer_1_pos,305.,0.02,"R");
   pline2_1_2_1->SetLineWidth(0);
   TPolyLine *pline2_1_2_2 = makeBox(layer_1_pos,305.,0.02,"L");
   pline2_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline2_2_1 = makeBox(layer_2_pos,295.,0.02);
   pline2_2_1->Draw();
   TPolyLine *pline2_2_1_1 = makeBox(layer_2_pos,295.,0.02,"R");
   pline2_2_1_1->SetLineWidth(0);
   TPolyLine *pline2_2_1_2 = makeBox(layer_2_pos,295.,0.02,"L");
   pline2_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline2_2_2 = makeBox(layer_2_pos,305.,0.02);
   pline2_2_2->Draw();
   TPolyLine *pline2_2_2_1 = makeBox(layer_2_pos,305.,0.02,"R");
   pline2_2_2_1->SetLineWidth(0);
   TPolyLine *pline2_2_2_2 = makeBox(layer_2_pos,305.,0.02,"L");
   pline2_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline2_3_1 = makeBox(layer_3_pos,300.,0.02);
   pline2_3_1->Draw();
   TPolyLine *pline2_3_1_1 = makeBox(layer_3_pos,300.,0.02,rb2_3_1_1);
   pline2_3_1_1->SetLineWidth(0);
   TPolyLine *pline2_3_1_2 = makeBox(layer_3_pos,300.,0.02,rb2_3_1_2);
   pline2_3_1_2->SetLineWidth(0);
   TPolyLine *pline2_3_1_3 = makeBox(layer_3_pos,300.,0.02,rb2_3_1_3);
   pline2_3_1_3->SetLineWidth(0);
   
   TPolyLine *pline2_4_1 = makeBox(layer_4_pos,300.,0.02);
   pline2_4_1->Draw();
   TPolyLine *pline2_4_1_1 = makeBox(layer_4_pos,300.,0.02,rb2_4_1_1);
   pline2_4_1_1->SetLineWidth(0);
   TPolyLine *pline2_4_1_2 = makeBox(layer_4_pos,300.,0.02,rb2_4_1_2);
   pline2_4_1_2->SetLineWidth(0);
   TPolyLine *pline2_4_1_3 = makeBox(layer_4_pos,300.,0.02,rb2_4_1_3);
   pline2_4_1_3->SetLineWidth(0);     
   
   //RB1
   TPolyLine *pline2_5_1 = makeBox(layer_5_pos,300.,0.02);
   pline2_5_1->Draw();
   TPolyLine *pline2_5_1_1 = makeBox(layer_5_pos,300.,0.02,"R");
   pline2_5_1_1->SetLineWidth(0);
   TPolyLine *pline2_5_1_2 = makeBox(layer_5_pos,300.,0.02,"L");
   pline2_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline2_6_1 = makeBox(layer_6_pos,300.,0.02);
   pline2_6_1->Draw();
   TPolyLine *pline2_6_1_1 = makeBox(layer_6_pos,300.,0.02,"R");
   pline2_6_1_1->SetLineWidth(0);
   TPolyLine *pline2_6_1_2 = makeBox(layer_6_pos,300.,0.02,"L");
   pline2_6_1_2->SetLineWidth(0);


///////////sector 3    
   //RB4
   TPolyLine *pline3_1_1 = makeBox(layer_1_pos,325.,0.02);
   pline3_1_1->Draw();
   TPolyLine *pline3_1_1_1 = makeBox(layer_1_pos,325.,0.02,"R");
   pline3_1_1_1->SetLineWidth(0);
   TPolyLine *pline3_1_1_2 = makeBox(layer_1_pos,325.,0.02,"L");
   pline3_1_1_2->SetLineWidth(0);
    
   TPolyLine *pline3_1_2 = makeBox(layer_1_pos,335.,0.02);
   pline3_1_2->Draw();
   TPolyLine *pline3_1_2_1 = makeBox(layer_1_pos,335.,0.02,"R");
   pline3_1_2_1->SetLineWidth(0);
   TPolyLine *pline3_1_2_2 = makeBox(layer_1_pos,335.,0.02,"L");
   pline3_1_2_2->SetLineWidth(0);
    
   //RB3
   TPolyLine *pline3_2_1 = makeBox(layer_2_pos,325.,0.02);
   pline3_2_1->Draw();
   TPolyLine *pline3_2_1_1 = makeBox(layer_2_pos,325.,0.02,"R");
   pline3_2_1_1->SetLineWidth(0);
   TPolyLine *pline3_2_1_2 = makeBox(layer_2_pos,325.,0.02,"L");
   pline3_2_1_2->SetLineWidth(0);
   
   
   TPolyLine *pline3_2_2 = makeBox(layer_2_pos,335.,0.02);
   pline3_2_2->Draw();
   TPolyLine *pline3_2_2_1 = makeBox(layer_2_pos,335.,0.02,"R");
   pline3_2_2_1->SetLineWidth(0);
   TPolyLine *pline3_2_2_2 = makeBox(layer_2_pos,335.,0.02,"L");
   pline3_2_2_2->SetLineWidth(0);
   
   
   //RB2
   TPolyLine *pline3_3_1 = makeBox(layer_3_pos,330.,0.02);
   pline3_3_1->Draw();
   TPolyLine *pline3_3_1_1 = makeBox(layer_3_pos,330.,0.02,rb2_3_1_1);
   pline3_3_1_1->SetLineWidth(0);
   TPolyLine *pline3_3_1_2 = makeBox(layer_3_pos,330.,0.02,rb2_3_1_2);
   pline3_3_1_2->SetLineWidth(0);
   TPolyLine *pline3_3_1_3 = makeBox(layer_3_pos,330.,0.02,rb2_3_1_3);
   pline3_3_1_3->SetLineWidth(0);
   
   TPolyLine *pline3_4_1 = makeBox(layer_4_pos,330.,0.02);
   pline3_4_1->Draw();
   TPolyLine *pline3_4_1_1 = makeBox(layer_4_pos,330.,0.02,rb2_4_1_1);
   pline3_4_1_1->SetLineWidth(0);
   TPolyLine *pline3_4_1_2 = makeBox(layer_4_pos,330.,0.02,rb2_4_1_2);
   pline3_4_1_2->SetLineWidth(0);
   TPolyLine *pline3_4_1_3 = makeBox(layer_4_pos,330.,0.02,rb2_4_1_3);
   pline3_4_1_3->SetLineWidth(0);     
   
   //RB1
   TPolyLine *pline3_5_1 = makeBox(layer_5_pos,330.,0.02);
   pline3_5_1->Draw();
   TPolyLine *pline3_5_1_1 = makeBox(layer_5_pos,330.,0.02,"R");
   pline3_5_1_1->SetLineWidth(0);
   TPolyLine *pline3_5_1_2 = makeBox(layer_5_pos,330.,0.02,"L");
   pline3_5_1_2->SetLineWidth(0);
   
   TPolyLine *pline3_6_1 = makeBox(layer_6_pos,330.,0.02);
   pline3_6_1->Draw();
   TPolyLine *pline3_6_1_1 = makeBox(layer_6_pos,330.,0.02,"R");
   pline3_6_1_1->SetLineWidth(0);
   TPolyLine *pline3_6_1_2 = makeBox(layer_6_pos,330.,0.02,"L");
   pline3_6_1_2->SetLineWidth(0);

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

chambers_boxes.push_back(pline4_1_1_1); chambers_names.push_back("RB4--_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_1_2); chambers_names.push_back("RB4--_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_2_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_2_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_3_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_3_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_4_1); chambers_names.push_back("RB4++_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_1_4_2); chambers_names.push_back("RB4++_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(4);
chambers_boxes.push_back(pline4_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(4);

chambers_boxes.push_back(pline5_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(5);
chambers_boxes.push_back(pline5_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(5);

chambers_boxes.push_back(pline6_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(6);
chambers_boxes.push_back(pline6_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(6);

chambers_boxes.push_back(pline7_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(7);
chambers_boxes.push_back(pline7_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(7);

chambers_boxes.push_back(pline8_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(8);
chambers_boxes.push_back(pline8_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(8);

chambers_boxes.push_back(pline9_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(9);
chambers_boxes.push_back(pline9_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(9);

chambers_boxes.push_back(pline10_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(10);
chambers_boxes.push_back(pline10_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(10);

chambers_boxes.push_back(pline11_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(11);
chambers_boxes.push_back(pline11_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(11);

chambers_boxes.push_back(pline12_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(12);
chambers_boxes.push_back(pline12_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(12);

chambers_boxes.push_back(pline1_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(1);
chambers_boxes.push_back(pline1_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(1);

chambers_boxes.push_back(pline2_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(2);
chambers_boxes.push_back(pline2_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(2);

chambers_boxes.push_back(pline3_1_1_1); chambers_names.push_back("RB4,-_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_1_1_2); chambers_names.push_back("RB4,-_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_1_2_1); chambers_names.push_back("RB4+_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_1_2_2); chambers_names.push_back("RB4+_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_2_1_1); chambers_names.push_back("RB3-_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_2_1_2); chambers_names.push_back("RB3-_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_2_2_1); chambers_names.push_back("RB3+_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_2_2_2); chambers_names.push_back("RB3+_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_3_1_1); chambers_names.push_back("RB2out_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_3_1_2); chambers_names.push_back("RB2out_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_3_1_3); chambers_names.push_back("RB2out_M"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_4_1_1); chambers_names.push_back("RB2in_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_4_1_2); chambers_names.push_back("RB2in_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_4_1_3); chambers_names.push_back("RB2in_M"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_5_1_1); chambers_names.push_back("RB1out_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_5_1_2); chambers_names.push_back("RB1out_F"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_6_1_1); chambers_names.push_back("RB1in_B"); chambers_sector.push_back(3);
chambers_boxes.push_back(pline3_6_1_2); chambers_names.push_back("RB1in_F"); chambers_sector.push_back(3);


	/*
	bool DrawNames = true;
	if(DrawNames){
		char name_pdf_file[400];
		if(w==0){
			sprintf(name_pdf_file,"w-2_names.pdf");		
		}
		if(w==1){
			sprintf(name_pdf_file,"w-1_names.pdf");		
		}
		if(w==2){
			sprintf(name_pdf_file,"w0_names.pdf");		
		}
		if(w==3){
			sprintf(name_pdf_file,"w+1_names.pdf");		
		}
		if(w==4){
			sprintf(name_pdf_file,"w+2_names.pdf");		
		}	
		auto c3 = new TCanvas("c3","c3",4000,4000);
		c3 = c1;
		c3->cd();
		for(int ii = 0; ii<chambers_boxes.size(); ii++){
			for(int jj = 0; jj<name_station.size(); jj++){
				if(chambers_names.at(ii)==name_station.at(jj) && chambers_sector.at(ii)==sector_number.at(jj)){
						TText *tname = new TText((chambers_boxes.at(ii)->GetX()[0]+chambers_boxes.at(ii)->GetX()[1]+chambers_boxes.at(ii)->GetX()[2]+chambers_boxes.at(ii)->GetX()[3])/4.,(chambers_boxes.at(ii)->GetY()[0]+chambers_boxes.at(ii)->GetY()[1]+chambers_boxes.at(ii)->GetY()[2]+chambers_boxes.at(ii)->GetY()[3])/4.,&chambers_names.at(ii)[0]);
						tname->SetTextFont(63);
						tname->SetTextAngle(45);
						tname->SetTextSize(15);
						tname->SetTextColor(2);
						tname->Draw();
				}
			}
		}
		c3->SaveAs(name_pdf_file);
		c3->Close();
	}
	*/

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
	
	c1->Draw();
	return c1;
}

void ChangeColorWheel(string wheel="", string chamber="",int sector=0, int new_color=0, int new_style=1001){

	int w = 0;
	char name_root_file[400];
	char name_pdf_file[400];

	if(wheel=="w-2"){
		w = 0;
		sprintf(name_root_file,"w-2_plot.root");
		sprintf(name_pdf_file,"w-2_plot.pdf");		
	}
	if(wheel=="w-1"){
		w = 1;
		sprintf(name_root_file,"w-1_plot.root");
		sprintf(name_pdf_file,"w-1_plot.pdf");		
	}
	if(wheel=="w0"){
		w = 2;
		sprintf(name_root_file,"w0_plot.root");
		sprintf(name_pdf_file,"w0_plot.pdf");		
	}
	if(wheel=="w+1"){
		w = 3;
		sprintf(name_root_file,"w+1_plot.root");
		sprintf(name_pdf_file,"w+1_plot.pdf");		
	}
	if(wheel=="w+2"){
		w = 4;
		sprintf(name_root_file,"w+2_plot.root");
		sprintf(name_pdf_file,"w+2_plot.pdf");		
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
	
	TCanvas *c2 = WheelPlot(w, name_station, sector_number, color_chamber, style_chamber, true, c1);
	c1 = c2;
	c1->Draw();
	c1->SaveAs(name_pdf_file);  
	c1->Write("",TObject::kOverwrite);
	f_new->Close();
}

