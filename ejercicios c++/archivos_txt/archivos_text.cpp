//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<string>
#include "archivos_text.h"
#include <fstream>

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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (OpenTextFileDialog1->Execute()) {
	Edit1->Text=OpenTextFileDialog1->FileName;
}
}
//---------------------------------------------------------------------------


bool letra(char c)
{
 AnsiString letra ="qwertyuiopasdfghjkl�zxcvbnmQWERTYUIOPASDFGHJKL�ZXCVBNM���������������";
		   return letra.Pos(c)>0;
	 }

 Word cant_letra(AnsiString cad)
 {
   Word c=0;
   for (int i=1; i<=cad.Length(); i++) {
	  if (letra(cad[i])) {
		  c++;
	  }
   }
   return c;
 }
 Word cant_num(AnsiString cad)
 {  Word c=0;cad=cad+" ";
 for (int i=1; i<cad.Length(); i++) {
	 if (isdigit(cad[i]) && !isdigit(cad[i+1])) {
	 c++;
	 }
 }
 return c;
 }

 void creartxt(AnsiString nom)
{
	char x;
	AnsiString aux,aux2 = "";
	ifstream fi(nom.c_str());
	ofstream fo("C:\\ejercicios c++\\archivos_examen\\E1.txt");

	if (!fi.fail()) {
		while (fi.get(x)) {
			if (x != '\n') { // omitir el car�cter de nueva l�nea
				aux += x;
			} else {
			  aux2 = IntToStr(cant_letra(aux))+",";
				  aux2= aux2+IntToStr(cant_num(aux));
				fo << aux2 << '\n';
				aux = ""; // reiniciar auxiliar para la siguiente l�nea
			}
		}
		fi.close();
		 aux2 = IntToStr(cant_letra(aux))+",";
		 aux2= aux2+IntToStr(cant_num(aux));
		fo<<aux2<<'\n';
		fo.close();
	}
}


void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (OpenTextFileDialog1->Execute()) {
Edit1->Text=OpenTextFileDialog1->FileName;
AnsiString nom=Edit1->Text;
creartxt(nom);                       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Edit2->Text=IntToStr(cant_num(Edit1->Text));
}
//---------------------------------------------------------------------------
  bool c_pal(AnsiString cad){
  AnsiString aux="";  Word c=0;
  for (int i=1;i<=cad.Length(); i++) {
 if (letra(cad[i])) {
	aux=aux+cad[i];
 }  else {
 if (aux !="") {
	 c++;
	 aux="";
 }
	 }
 }
 return  c>1;
  }


Word cant_pal( AnsiString nom){
 char x;  AnsiString aux =""; Word c=0;
  ifstream fi(nom.c_str());
  if (!fi.fail()) {
				while (!fi.eof()){
				x=fi.get();
				if (!fi.eof()) {
				 aux=aux+x;
				 if (x==10) {
				   if (c_pal(aux)) {
				   c++;
				   aux="";
				   }
				 }
				}
				}
		if (c_pal(aux)) {
		   c++;
		   aux="";
		}
	 fi.close();
  }

 return c;
}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  if (OpenTextFileDialog1->Execute()) {
	   Edit2->Text=OpenTextFileDialog1->FileName;
	  Edit1->Text=IntToStr(cant_pal(Edit2->Text));
  }
}
//---------------------------------------------------------------------------
  bool cont_digit(AnsiString cad)
  {  AnsiString aux="";     Word c,c2=0;
   for (int i=1; i <= cad.Length(); i++) {
	if (isdigit(cad[i])) {
		aux=aux+cad[i];
	} else if (aux!="") {
			c2=aux.Length();
			if (c2>c) {
			 c=c2;
			}
			 else{
				 aux="";
			} }

   }
	if (aux != "") {
		c2 = aux.Length();
		if (c2 > c) {
			c = c2;
		}
	}
   return  c>4;
  }
void eliminar_linea(AnsiString nom)
{
  AnsiString aux=""; char x;
 ifstream fi(nom.c_str());
 ofstream fo("temporal.txt");
 if (!fi.fail()) {
	 while (!fi.eof())
	 {
	  x=fi.get();
	  if (!fi.eof()) {
	  if (x==10) {
	   if (cont_digit(aux)) {
		  fo<<aux<<'\n';
		  aux="";
	   }
	 }     else
	 {
	   aux=aux+x;
	 }
	  }
	 }
	 if (cont_digit(aux)) {
		 fo<<aux<<'\n';
		 aux="";
	 }
	 fi.close();
	 fo.close();
	 remove(nom.c_str());
	 rename("temporal.txt",nom.c_str());
 }
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
if (OpenTextFileDialog1->Execute()) {
	Edit1->Text=OpenTextFileDialog1->FileName;

}

}
//---------------------------------------------------------------------------
