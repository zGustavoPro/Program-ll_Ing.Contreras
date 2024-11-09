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
 //alf. ingles 52 caracteres
 //alf. español 66 caracteres
 bool esletra(char c){
		   AnsiString letra ="qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNMáéíóúÁÉÍÓÚÄËÏÖÜ";
		   return letra.Pos(c)>0;
 }
int cant_pal(AnsiString nom)
  {
 bool sw; char x; int c;
 ifstream f(nom.c_str());
 if (!f.fail()) {
	 c=0; sw=false;
	 while (!f.eof())
		 {
	 x=f.get();
	 if (!f.eof()) {
		 if (esletra(x)) {
			 if (!sw) {//si la bandera esta desacticada
			 sw=true;
			 c++;
			 }
		 }  else   {   // si la bandera esta activada
		 sw=false;
		 }
	 }
		 }
 }
 return c;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if( OpenTextFileDialog1->Execute()){
Edit1->Text=IntToStr(cant_pal(OpenTextFileDialog1->FileName));
}

}
//---------------------------------------------------------------------------
  bool vocal(char e){
   AnsiString p="aeiouAEIOUáéíóúÁÉÍÓÚÄËÏÖÜ";
   return p.Pos(e)>0;
  }
 bool pal(AnsiString s){
 int c,i;
 c=0;
 for ( i=1;i<=s.Length();i++) {
   if (vocal(s[i])) {
	  c++;           }
 }
 return c>1;
 }

  int cant_pal2(AnsiString nom){
  bool sw; char x; int c,v; AnsiString cad="";
  v=0;       c=0;
	   ifstream f(nom.c_str());
	   if (!f.fail()) {

			while (!f.eof()) {
			x=f.get();
			if (!f.eof()) {
			if (esletra(x)) {
			cad=cad+x;
	   } else if (pal(cad)) {
				c++;
			  cad="";
			  } else {
			  cad="";
			  }
			}
			}

	   }
return c;
  }
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if( OpenTextFileDialog1->Execute()){
Edit1->Text=IntToStr(cant_pal2(OpenTextFileDialog1->FileName));
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Edit2->Text=pal(Edit1->Text);
}
//---------------------------------------------------------------------------
  bool EsPunto(char z){
  AnsiString p=".,:;-_!¡¿?'¨";
  return p.Pos(z)>0;
  }
  void eliminar_notalf(AnsiString nom){
  char x;
  ifstream fi(nom.c_str());
  ofstream fo("temporal.dat");
  if (!fi.fail()) {
	  while (!fi.eof()) {
		  x=fi.get();
		  if (!fi.eof()) {
			  if (esletra(x)||EsPunto(x)||(x==10)||(x==32)) {
			  fo.put(x);
			  }
		  }
	  }
	  fi.close();
	  fo.close();
	  remove(nom.c_str());
	  rename("temporal.dat",nom.c_str());
  }
}




void __fastcall TForm1::Button4Click(TObject *Sender)
{
  if (OpenTextFileDialog1->Execute()) {
  Edit1->Text="Procesando.....";
	  Edit2->Text=OpenTextFileDialog1->FileName;
	  eliminar_notalf(OpenTextFileDialog1->FileName);
	  Edit1->Text="Terminado.....";
  }
}
//---------------------------------------------------------------------------

void Alinear_izq(AnsiString nom){
char x;    bool sw=false;
ifstream fi(nom.c_str());
ofstream fo("temporal.dat");
if (!fi.fail()) {
	while (!fi.eof()) {
	 x=fi.get();
	 if (!fi.eof()) {
		 if (x==32) { //es espacio
			if (sw) {
		   fo.put(x);
		   }
		 }else
		 {
			 fo.put(x);
			 sw=true;
			 if (x==10) { //10 = fin de linea
				sw=false;
			 }
		 }
	 }

	}
 fi.close();
 fo.close();
 remove(nom.c_str());
 rename("terporal.dat",nom.c_str());
}
}




void __fastcall TForm1::Button5Click(TObject *Sender)
{
										  if (OpenTextFileDialog1->Execute()) {
  Edit1->Text="Procesando.....";
	  Edit2->Text=OpenTextFileDialog1->FileName;
	  Alinear_izq(OpenTextFileDialog1->FileName);
	  Edit1->Text="Terminado.....";
  }
}
//---------------------------------------------------------------------------

