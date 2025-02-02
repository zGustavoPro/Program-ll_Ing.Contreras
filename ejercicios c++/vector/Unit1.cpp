//---------------------------------------------------------------------------

#include <vcl.h>
#include<string>
#include<sstream>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
  //secuencia numeros   eje: hola123ho12 => 2
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
bool EsDigito(char d){
return (d>='0') && (d<='9');
}
Word cantNumeros(AnsiString x){
Word c;
Word n=x.Length();

if (n==0)       //caso base
	c=0;
else  if (n==1){   //2do caso
if (EsDigito(x[1]))
	c=1;   else
	c=0;
 }
 else {       //caso general
AnsiString y=x;
x.Delete( n/2+1,n-n/2);
y.Delete(1,n/2);
c=cantNumeros(x)+cantNumeros(y);
if(EsDigito(x[n/2]) && EsDigito(y[1]))
c--;
}
return c;
}
//---------------------------------------------------------------------------
AnsiString generar_cad(TStringGrid *v,byte n)
{
if (v->ColCount==1)
return v->Cells[n][0];
else if (n<v->ColCount)
return generar_cad(v,n+1)+v->Cells[n][0];
}

void __fastcall TForm1::Button7Click(TObject *Sender)
{
byte n=0;
Edit1->Text=generar_cad(SG1,n);
}
//---------------------------------------------------------------------------
void tsupasc(TStringGrid *v,byte f1,byte c1,byte k)
{
if (f1<v->ColCount) {
   if (c1<v->ColCount) {
   v->Cells[c1][f1]=k;
   c1++;
   k++;
   tsupasc(v,f1,c1,k);	   
   }  else 
   tsupasc(v,f1+1,f1+1,k);        }
}


void __fastcall TForm1::Button8Click(TObject *Sender)
{
 byte f1=0;
 byte c1=0;
 byte k=1;
 tsupasc(SG2,f1,c1,k);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{  Word n=19;            // "/" parte entera y decimal manda el de lado izquierdo
 Edit2->Text=cantNumeros(Edit1->Text);
}
//---------------------------------------------------------------------------
void CargarV (TStringGrid*v,byte n){

if (n>0) //caso general
{
  CargarV(v,n-1);
  v->Cells[n-1][0]=Random(10);
}
}
void __fastcall TForm1::Button10Click(TObject *Sender)
{
 SG1->ColCount=StrToInt(Edit1->Text);
CargarV(SG1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

int sumaV(TStringGrid*v,byte a,byte b){
int s;
byte n=b-a+1;
if (n==0) ;

else if (n==1)
 s=StrToInt(v->Cells[a][0]) ;

else{
	 s=sumaV(v,a+2,b);
	 s=s+StrToInt(v->Cells[a][0])+ StrToInt(v->Cells[a][1]);
	 }
return s;
}
void __fastcall TForm1::Button11Click(TObject *Sender)
{
		Edit2->Text=IntToStr(sumaV(SG1,0,SG1->ColCount-1)) ;
}
//---------------------------------------------------------------------------
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

void __fastcall TForm1::Button12Click(TObject *Sender)
{
   InvertirV(SG1,0,SG1->ColCount);
}
//---------------------------------------------------------------------------
   void num_may(TStringGrid*v,byte a,int n,int &may,int &i){
if (n<a)
{
  if (StrToInt(v->Cells[n][0])>may){
may=StrToInt(v->Cells[n][0]);
i=n;   }
num_may(v,a,n+1,may,i);
}
if (i !=a-1 ) {
 String aux=v->Cells[i][0];
 v->Cells[i][0]=v->Cells[a-1][0];
 v->Cells[a-1][0]=aux;
 }
 }



void __fastcall TForm1::Button13Click(TObject *Sender)
{
int n=0;
int may=0;
int i=0;
 num_may(SG1,SG1->ColCount,n,may,i);
 Edit2->Text=IntToStr(may);
}
//---------------------------------------------------------------------------
 byte cant_dig(Cardinal n){
 if (n<10)
		 return 1;
		 else return 1+cant_dig(n/10);
 }
	  //gveafhvsjf
							int inv(int c)
							{
										   return ((c%10)*10)+(c/10);
							}
 void inv_pares(TStringGrid *v,byte a,int n){
		if (a==1 && n<10)
		   v->Cells[0][0]=IntToStr(n); else
		   if(n>10 || n!=0)
		   {
			int c=n%100;
		   c=((c%10)*10)+(c/10);
		   v->Cells[a-1][0]=IntToStr(c);
			inv_pares(v,a-1,n/100);
		   }
 }

void __fastcall TForm1::Button14Click(TObject *Sender)
{
   int m=StrToInt(Edit1->Text);
   byte k=cant_dig(m);
   if (k%2==0)
  k=k/2;
  else
  k=(k+2)/2;

  SG1->ColCount=k;
   inv_pares(SG1,k,m);
}
//---------------------------------------------------------------------------
bool pertenece_pal(char e)
{
AnsiString cad="abcdefghijklm�opqrstuvwxyzABCDEFGHIJKLM�OPQRSTUVWXYZ";
   byte x=cad.Pos(e);
   return x>0;
}
bool pertenece_num(char e)
{
	AnsiString num="1234567890";
	byte x=num.Pos(e);
	return x>0;
}
bool pertenece_espac(char e){
AnsiString cad=",:. _-<>;";
  byte x=cad.Pos(e);
					return x>0;
							 }
	 AnsiString eliminar_espac(AnsiString &cad){
	 if (!pertenece_espac(cad[1]))
	 return eliminar_espac(cad.Delete(1,1));
	 else return cad.Delete(1,1);
			}

void Cargar_1er_car(AnsiString &cad,TStringGrid *v,int &n)
{                                                           byte k=cad.Length();
	  if (cad !="" ) {
	 if (pertenece_pal (cad[1]) && pertenece_pal (cad[2])  ) {
		 v->Cells[n][0]=cad[1];
		 n++;
		 v->Cells[n][0]=cad[2];
		 n++;
		 v->Cells[n][0]="";
		 n++;
		 cad=eliminar_espac(cad);
		   Cargar_1er_car(cad,v,n) ;
	 }   else
	Cargar_1er_car(cad.Delete(1,1),v,n); }
}

void __fastcall TForm1::Button16Click(TObject *Sender)
{
int n=0;
AnsiString cad=Edit1->Text+" ";
  Cargar_1er_car(cad,SG1,n);
  SG1->ColCount=n;
 /* AnsiString cad=Edit1->Text;
 Edit2->Text=eliminar_espac(cad);*/
}
//---------------------------------------------------------------------------
void llenarf1inv (TStringGrid *v,byte f,byte ca,byte cb,byte &k)
{
 byte c=cb-ca+1;
 if (c>0) {
 llenarf1inv(v,f,ca,cb-1,k);
 v->Cells[cb][f]=k;
 }
}
void llenarc2inv(TStringGrid *v,byte fa,byte fb,byte cb,byte &k)
{
   byte f=fb-fa+1;
   if (f>0) {
	   llenarc2inv(v,fa,fb-1,cb,k);
	   v->Cells[cb][fb]=k;
   }
}
void llenarf2inv(TStringGrid *v,byte fa,byte ca,byte cb,byte &k){
byte c=cb-ca+1;
			   if (c>0) {
				   llenarf2inv(v,fa,ca+1,cb,k);
				   v->Cells[ca][fa]=k;
			   }
}

void llenarc1inv (TStringGrid *v,byte fa,byte fb,byte ca,byte &k)
{
   byte f=fb-fa+1;
   if (f>0) {
	   llenarc1inv(v,fa+1,fb,ca,k);
	   v->Cells[ca][fa]=k;
   }
}

void cargar2019_B2(TStringGrid *v,byte fa,byte fb,byte ca,byte cb,byte &k)
{
	byte f=fb-fa+1;
	byte c=cb-ca+1;
	if (f*c>0) {
		if (f*c==1)
			v->Cells[ca][fa]=k;
			else {
				llenarf2inv(v,fb,ca+1,cb,k);
				llenarc1inv(v,fa+1,fb,ca,k);
				k++;
					llenarf1inv(v,fa,ca,cb-1,k);
				llenarc2inv(v,fa,fb-1,cb,k);
				k++;
				cargar2019_B2(v,fa+1,fb-1,ca+1,cb-1,k);
			}

	}
}



void __fastcall TForm1::Button1Click(TObject *Sender)
{
		byte fa=0;
					byte fb=SG2->RowCount-1;
					byte ca=0;
					byte cb=SG2->ColCount-1;
					byte k=1;
					cargar2019_B2(SG2,fa,fb,ca,cb,k);
}

//---------------------------------------------------------------------------
   //cargar con dig menores a 100            cargar numeros en par
 //x=2356879==[2,35,68,79]                    x=2356879==[2,35,68,79]
void Vect_mincien(TStringGrid *v,int k,byte n)
{
	if (n==1)
	v->Cells[0][0]=IntToStr(k);
else if (k>10 || k !=0) {
		 int c=k%100;
		 v->Cells[n-1][0]=IntToStr(c);
		 Vect_mincien(v,k/100,n-1);
	 }
}
int par_impar(int n)
{
   if (n%2==0)
 return n/2;
 else
 return (n+2)/2 ;
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int k=StrToInt(Edit1->Text);
 byte n=cant_dig(k);
 SG1->ColCount=par_impar(n);
 Vect_mincien(SG1,k,SG1->ColCount);
}
//---------------------------------------------------------------------------
 AnsiString V_cad_inv(TStringGrid *v,byte n)
 {
		 if (n<v->ColCount) {
		 if (StrToInt(v->Cells[n][0])<10)
		 return v->Cells[n][0]+V_cad_inv(v,n+1);
		 else
				return  IntToStr(((StrToInt(v->Cells[n][0])%10)*10)+StrToInt(v->Cells[n][0])/10)+V_cad_inv(v,n+1);
		 }
 }
void __fastcall TForm1::Button3Click(TObject *Sender)
{
byte n=0;
  Edit1->Text=V_cad_inv(SG1,n);
}
//---------------------------------------------------------------------------

	  AnsiString inv_cadena(AnsiString cad)
	  {
	  if (cad=="") {
		  return "";
	  }
	  else
	  if (cad!="")     {
	  char c=cad[1];
	  return inv_cadena(cad.Delete(1,1))+towupper(c);
	  }
	  }
	   AnsiString cadena(AnsiString cad)
	  {
	  if (cad=="") {
		  return "";
	  }
	  else
	  if (cad!="")     {
	  char c=cad[1];
	  return cadena(cad.Delete(1,1))+c;
	  }
	  }


	  AnsiString palindromo(AnsiString cad,AnsiString cad2)
	  {
		 if (cad==cad2)
		 return "true";
		 else
		 return "false";
	  }
void __fastcall TForm1::Button4Click(TObject *Sender)
{
//towupper
AnsiString cad=Edit1->Text;
AnsiString m=cadena(cad);
m=inv_cadena(m);
cad=inv_cadena(cad);
 Edit2->Text=palindromo(m,cad);

}
//---------------------------------------------------------------------------

 AnsiString get_cad (TStringGrid *v,byte n)
 {
  if (v->ColCount==1)
  return v->Cells[n][0];
  else   if (n<v->ColCount)
  return  v->Cells[n][0]+get_cad(v,n+1);
 }
 AnsiString vector_palindromo(TStringGrid *v,byte a)
 {
 if (a==1)
  return  "true" ;
  else  {
  AnsiString cad=get_cad(v,0);
  InvertirV(v,0,a);
  AnsiString cad2=get_cad(v,0);
  if (cad==cad2)
  return "true";      else
  return "false";                 }

 }
void __fastcall TForm1::vect_palindromoClick(TObject *Sender)
{
  Edit2->Text=vector_palindromo(SG1,SG1->ColCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
		  Edit1->Text=get_cad(SG1,0);
}
//---------------------------------------------------------------------------

void eliminar_n_ele(TStringGrid *v,byte p,byte n)
{           if (p<1|| n<0)
			   ShowMessage("Fuera de rango");
			   else
 if (p+n<v->ColCount) {
	v->Cells[p][0]=v->Cells[p+n][0];
	eliminar_n_ele(v,p+1,n);
 }
}


void __fastcall TForm1::Button5Click(TObject *Sender)
{
byte p = StrToInt(Edit1->Text);
byte n =  StrToInt(Edit2->Text);
eliminar_n_ele(SG1,p,n);
	SG1->ColCount=SG1->ColCount-n;
}
//---------------------------------------------------------------------------
void llenarf1 (TStringGrid *v,byte f,byte ca,byte cb,byte &k)
{
 byte c=cb-ca+1;
 if (c>0) {
 llenarf1(v,f,ca,cb-1,k);
 v->Cells[cb][f]=k;
 }
}
void llenarc2(TStringGrid *v,byte fa,byte fb,byte cb,byte &k)
{
   byte f=fb-fa+1;
   if (f>0) {
	   llenarc2(v,fa,fb-1,cb,k);
	   v->Cells[cb][fb]=k;
   }
}
void llenarf2(TStringGrid *v,byte fa,byte ca,byte cb,byte &k){
byte c=cb-ca+1;
			   if (c>0) {
				   llenarf2(v,fa,ca+1,cb,k);
				   v->Cells[ca][fa]=k;
			   }
}

void llenarc1 (TStringGrid *v,byte fa,byte fb,byte ca,byte &k)
{
   byte f=fb-fa+1;
   if (f>0) {
	   llenarc1(v,fa+1,fb,ca,k);
	   v->Cells[ca][fa]=k;
   }
}

void cargar2019_2B(TStringGrid *v,byte fa,byte fb,byte ca,byte cb,byte &k)
{
	byte f=fb-fa+1;
	byte c=cb-ca+1;
	if (f*c>0) {
		if (f*c==1)
			v->Cells[ca][fa]=k;
			else {
				llenarf1(v,fa,ca,cb-1,k);
				llenarc2(v,fa,fb-1,cb,k);
				k++;
				llenarf2(v,fb,ca+1,cb,k);
				llenarc1(v,fa+1,fb,ca,k);
				k++;
				cargar2019_2B(v,fa+1,fb-1,ca+1,cb-1,k);
			}

	}
}
void __fastcall TForm1::Button17Click(TObject *Sender)
{
					byte fa=0;
					byte fb=SG2->RowCount-1;
					byte ca=0;
					byte cb=SG2->ColCount-1;
					byte k=1;
					cargar2019_2B(SG2,fa,fb,ca,cb,k);
}
//---------------------------------------------------------------------------
void Tinf_asc(TStringGrid *v,byte f1,byte c2,byte k)
{
 if (f1<v->ColCount) {
 if (c2<v->ColCount) {
		v->Cells[c2][f1]=k;
		k++;
		Tinf_asc(v,f1,c2+1,k);
 }                 else {
 f1++;
 Tinf_asc(v,f1,c2-f1-1,k); }
 }
}
void __fastcall TForm1::Button18Click(TObject *Sender)
{
byte f1=0;
  byte c2=SG2->ColCount-1;
  byte k=1;
		  Tinf_asc(SG2,f1,c2,k);
}
//---------------------------------------------------------------------------

void Tprincipal(TStringGrid *v,int f1,byte c1,byte &k)
{
	if (f1<v->ColCount  ) {
	if (f1>=0) {
		 v->Cells[c1][f1]=k;
		 k++;
		 Tprincipal(v,f1-1,c1+1,k);
	} else {
	  f1=f1+c1+1;
	Tprincipal(v,f1,c1-f1,k);
	}       }
}
void TprincipalB(TStringGrid *v,int f1,int c1,byte &k,int n)
{
if (c1<v->ColCount ) {
	v->Cells[c1][f1]=k;
	k++;
	TprincipalB(v,f1-1,c1+1,k,n);
}  else  if (n<v->ColCount) {
  n++;
  f1=v->ColCount-1;
  c1=n;
  TprincipalB(v,f1,c1,k,n);  }
}


void __fastcall TForm1::Button19Click(TObject *Sender)
{
byte k=1;
int f1=0;
byte c1=0;
Tprincipal(SG2,f1,c1,k);

int f2=SG2->ColCount-1;
int c2=1;
int n=1;
TprincipalB(SG2,f2,c2,k,n);
}
//---------------------------------------------------------------------------
void cargarf2_c1(TStringGrid *v,int f1,int c1,int k,byte paco)
{      if (f1>=0 && paco ==1) {
	if (c1<=f1 ) {
	v->Cells[c1][f1]=k;
	k++;
	cargarf2_c1(v,f1,c1+1,k,paco);
	} else { paco=2;
		cargarf2_c1(v,f1-1,c1-2,k,paco);
	}
	   }  else    {
  if (f1>=0 && paco ==2) {
   if (c1>=0) {
   v->Cells[c1][f1]=k;
   k++;
   cargarf2_c1(v,f1,c1-1,k,paco);
   }  else  { paco=1;
   cargarf2_c1(v,f1-1,c1+1,k,paco);           }  }}

}

void __fastcall TForm1::Button20Click(TObject *Sender)
{
int k=1;
int f1=SG2->ColCount-1;
int c1=0;
byte paco=1;
cargarf2_c1(SG2,f1,c1,k,paco);
}
//---------------------------------------------------------------------------
void fila(TStringGrid *v,byte f,byte c2,byte k,byte n)
{
			  if (c2<=n-1){
						 v->Cells[c2][f]=k;
						 fila(v,f,c2+1,k,n);
			  }
}
void columna(TStringGrid *v,byte f2,byte k,byte n)
{
   if (f2<=n) {
	   v->Cells[n-1][f2]=k;
	   columna(v,f2+1,k,n);
   }
}
void car(TStringGrid *v,byte f1,byte c1,byte k,byte n){
if (n>0) {
fila(v,f1,c1,k,n);
columna(v,f1+1,k,n);
 car(v,f1+1,c1,k+1,n-1);
}
}
void __fastcall TForm1::Button21Click(TObject *Sender)
{
	 byte n=SG2->ColCount;
	 byte f1=0;
	 byte c1=0;
	 byte k=1;
	 car(SG2,f1,c1,k,n);
}
//---------------------------------------------------------------------------

void cargarnum(TStringGrid *v,AnsiString cad,AnsiString aux,byte &n)
{
if (cad!="") {
if (pertenece_num(cad[1])) {
	aux=aux+cad[1];
	cargarnum(v,cad.Delete(1,1),aux,n);
} else  if (aux !="") {
   v->Cells[n][0]=aux;
   n++;  aux="";
   cad.Delete(1,1);
   cargarnum(v,cad,aux,n);           } else
   cargarnum(v,cad.Delete(1,1),aux,n);
}
}

void __fastcall TForm1::Button22Click(TObject *Sender)
{
 byte n=0;
AnsiString aux="";
 cargarnum(SG1,Edit1->Text+" ",aux,n);
			 SG1->ColCount=n+1;

}
//---------------------------------------------------------------------------

