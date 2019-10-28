//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{  }
//---------------------------------------------------------------------------
const im = 20;
int Gd, Gm, k,i,m,j,kmax;
float dt,dTr,c,Tpl,at,xt,g,L,time1,dR,v;
float T[100];  float B[100]; float R[100]; float RR[100]; float tt[100];
AnsiString ss;     


void __fastcall TForm1::Button1Click(TObject *Sender)
{
time1=0;
        R[1]=0.001;        //radius of liquid
        RR[1]=R[1];
	R[im]=0.003;    //radius of surrounded solid
        g=8800;  //kg/m**3 	//closeness of matter
	L=24370*8800;  //heat of fusion, J/m**3
	xt=92;	//Bt/m/K; Parameters of Al
	c=460;        //heat capacity J/kg/grad
	at=xt/(g*c);           //m^^2/s
	dR=(R[im]-R[1])/(im-1);
	dt=0.005*dR*dR/at;

	Tpl=1452;        //temperature of fusion
	T[2]=1400; T[3]=1300; T[4]=1000;  T[5]=800;
        T[1]=Tpl;

        for (m=6; m<=im; m++)   T[m]=20;
        for (i=2; i<=im-1; i++) R[i]=R[i-1]+dR;
        B[1]=Tpl;
        v=xt*(T[2]-T[1])/(dR*L);
         kmax=1;
      for (k=1; k<=20; k++)
  {   for(j=1; j<=1000; j++)
   {

       for (i=2; i<=im-1; i++)
    {
    dR=(R[im]-R[1])/(im-1);
    R[i]= R[im]-dR*(im-i);
    dTr=(T[i+1]-T[i-1])/(2*dR);	  //first derivation
    B[i]=T[i]+dt*at*(((T[i+1]+T[i-1]-2*T[i])/(dR*dR))+dTr*2/R[i]);
    B[i]=B[i]+v*dt*(im-i)/(im-1)*dTr; //new temperatures
    }
       for (i=2; i<=im; i++) T[i]=B[i];

    v=xt*(T[2]-T[1])/(dR*L);		//new velocity of the interface
    R[1] += v*dt; time1 += dt;  //new size of liquid and new time

    //drawing of liquid bath and isoterms
    if (j==1)
    {   int RKK= R[1]*100000;
     Form1->Canvas->Brush->Color = clGray;	  //background for image
     Form1->Canvas->FillRect(Rect(0,200,450,450));
    
      for (i=8; i>=1; i--)
     {  int RK= R[i]*100000;			//painting of isotherms
     Form1->Canvas->RoundRect(200-RK, 200-RK, 200+RK, 200+RK,2*RK,2*RK);
        if(i%2==0)
     {  int TTT=T[i];
      ss=IntToStr(abs(TTT));
      Form1->Canvas->TextOutA(190,RK+196,ss);	//values of temperatures for some isotherms
     }
    } Form1->Canvas->Brush->Color = clRed;
      Form1->Canvas->Ellipse(200-RKK, 200-RKK,200+RKK, 200+RKK);  //image of liguid
      Form1->Canvas->Brush->Color = clLtGray;
      Form1->Canvas->FillRect(Rect(0,0,450,200));
     if  (R[1]<=0.00001) break;
       for (i=1; i<=6; i++)    //six values of the temperature (near liquid)
       Memo1->Lines->Add(FloatToStrF(T[i], ffGeneral, 10, 6));
       Memo1->Lines->Add(FloatToStrF(111111111, ffGeneral, 10, 6));
          Sleep(400);
   } //end if j=1
      } if  (R[1]<=0.00001)  break;  // end in j=1000
      RR[k]=R[1]; tt[k]=time1;  kmax +=1;
        //Series2.Clear;

    Series2.AddXY(tt[k],RR[k],'',clBlue);
    end;


       //data for R[k(t)] in the cycle for k
       if  (R[1]<=0.00001)  break;
     }    //end in k

      for (k=1; k < kmax; k++)		//data for R[k(t)] in Memo1
      {Memo1->Lines->Add(FloatToStrF(RR[k], ffGeneral, 10, 4));
      Memo1->Lines->Add(FloatToStrF(tt[k], ffGeneral, 10, 4));
      Memo1->Lines->Add(FloatToStrF(111111111, ffGeneral, 10, 6));}

}                 
