//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
byte suma(Cardinal n){
	   byte s;
	   if (n<10) return n;
		 else
		 s=(n%10)+suma(n/10);

		 return s;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 Edit2->Text=IntToStr(suma(StrToInt(Edit1->Text))) ;

}
//---------------------------------------------------------------------------
 byte sum_par(Cardinal n){
byte s=0;
if ((n<10) &&(n%2==0)){
	return n;         }

else if ((n%10)%2==0)
	  s= (n % 10)+sum_par(n/10);
else   return sum_par(n/10);

			return s;
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Edit2->Text=IntToStr(sum_par(StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------
byte sum_impar(Cardinal n){
 byte s=0;
if ((n<10) &&(n%2!=0)){
	return n;         }

else if ((n%10)%2!=0)
	  s= (n % 10)+sum_impar(n/10);
else   return sum_impar(n/10);

			return s;
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Edit2->Text=IntToStr(sum_impar(StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------
int inv(int n,int n1=0){
if (n==0)
 return n1;
else
return inv(n/10,n1*10+n%10);

}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Edit2->Text=IntToStr(inv(StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------
  int factorial(int n){
 if (n==0)
 n=1;
 else
 n=n*factorial(n-1);
	return n;
}
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Edit2->Text=IntToStr(factorial(StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------
AnsiString  inver_cad(AnsiString x){
AnsiString y;
if (x=="")
y="";
else {
char z=x[1];
x.Delete(1,1);
y=inver_cad(x);
y=y+z;
}
  return y;
}
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 Edit2->Text=inver_cad(Edit1->Text);
}
//---------------------------------------------------------------------------
bool pertenece (char x){
		   if (x>='0' && x<='9')
		   return true;
		   else
		   return false;
}

int ult_num(AnsiString x){
int n=x.Length();
AnsiString num="1234567890";
AnsiString s=0;
if (x=="")
	return 0;
else if(num.Pos(x)>0){
  s=x[n];
  x.Delete(n-1,n);
	 if(num.Pos(x)==0)
		 return StrToInt(s);
		   else s= s+ult_num(x);} }



void __fastcall TForm1::Button7Click(TObject *Sender)
{
 Edit2->Text=IntToStr(ult_num(Edit1->Text));
}
//---------------------------------------------------------------------------
 byte cant_dig(int n) {
 if (n<10)
	 return 1;
	 else
	 return 1+cant_dig(n/10) ; }


  void Inv_Vpar(TStringGrid *V,byte &n,int &k)
  {
 if(k>0)
 {
 int c = k % 100;
	V->Cells[n][0]=IntToStr(c/10);
   V->Cells[n-1][0]=IntToStr(c%10);
   Inv_Vpar(V,n-2,k/100);
   }
}

//vector ,columnas,digito

void inv_Vimpar(TStringGrid *V,byte &n,int k){

 if (k>10){
   int c=k%100;
   V->Cells[n][0]=IntToStr(c/10);
   V->Cells[n-1][0]=IntToStr(c%10);
   inv_Vimpar(V,n-2,k/100);
 } else
 V->Cells[0][0]=IntToStr(k);
}


	void InvertirV(TStringGrid *v,byte a,byte n){
   if (n>1)// caso general
   {
	byte b=n+a-1;
	  InvertirV(v,a+1,n-2);
	  String aux = v ->Cells[a][0];
	  v->Cells[a][0]=v->Cells[b][0];
	  v->Cells[b][0]=aux;
   }
   }


void __fastcall TForm1::Button8Click(TObject *Sender)
{
int k=StrToInt(Edit1->Text);

byte cont=cant_dig(k);
SG1->ColCount=cont-1;
byte f=cont-1;

  if (cont%2==0)
	 Inv_Vpar(SG1,f,k);
	 else
  inv_Vimpar(SG1,f,k);
}
//---------------------------------------------------------------------------
 void inver_V(TStringGrid *V,byte n,byte i)
 {
 if (i<n/2) {

	inver_V(V,n-1,i+1);
   String aux=V->Cells[i][0];
   V->Cells[i][0]=V->Cells[n][0];
   V->Cells[n][0]=aux;

  }
 }
	/*		 void InvertirV(TStringGrid *v,byte a,byte n){
   if (n>1)// caso general
   {
	byte b=n+a-1;
	  InvertirV(v,a+1,n-2);
	  String aux = v ->Cells[a][0];
	  v->Cells[a][0]=v->Cells[b][0];
	  v->Cells[b][0]=aux;
   }
   }    */
void __fastcall TForm1::Button9Click(TObject *Sender)
{
byte n=SG1->ColCount;
 InvertirV(SG1,0,n);
  // inver_V(SG1,n,0);
}
//---------------------------------------------------------------------------

void Cargar(TStringGrid *V,byte n)
{
if (n>0) {
  Cargar (V,n-1);
V->Cells[n-1][0]=Random(10);
}}
void __fastcall TForm1::Button10Click(TObject *Sender)
{
SG1->ColCount=StrToInt(Edit1->Text);
Cargar(SG1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)
{
Edit2->Text=IntToStr(cant_dig(StrToInt(Edit1->text)));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
    SG1->ColCount=IntToStr(cant_dig(StrToInt(Edit1->text)));
}
//---------------------------------------------------------------------------
