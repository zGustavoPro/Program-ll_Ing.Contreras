//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<fstream>



#include "archivostexto.h"
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
  bool numero(AnsiString cad) {
    AnsiString aux = "";
    int c = 0;
    cad = cad + " ";
    for (int i = 1; i <= cad.Length(); i++) {
        if (isdigit(cad[i])) {
            aux = aux + cad[i];
        } else if (aux != "") {
            c++;
            aux = "";
        }
    }
    return c > 1;
}
     Word cant_linea(AnsiString nom) {
    char x;
    AnsiString aux = "";
    Word c = 0;
	ifstream fi(nom.c_str());
	if (!fi.fail()) {
		while (!fi.eof()) {
			x = fi.get();
			if (!fi.eof()) {
				if (x == '\n') {
					if (numero(aux)) {
						c++;
					}
					aux = "";
				} else {
					aux = aux + x;
				}
			}
		}
		if (numero(aux)) {
			c++;
		}
		fi.close();
	}
	return c;
}
 void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 if (OpenTextFileDialog1->Execute()) {
		 Edit1->Text=OpenTextFileDialog1->FileName;
	   Edit2->Text=IntToStr(cant_linea(Edit1->Text));
	  // Edit2->Text=numero(Edit1->Text);
	  }

}
//---------------------------------------------------------------------------
 bool vocal(char e)
 {
  AnsiString x="aeiouAEIOU��������������������";
 return x.Pos(e)>0;
 }
 bool letra(char c)
{
 AnsiString letra ="qwertyuiopasdfghjkl�zxcvbnmQWERTYUIOPASDFGHJKL�ZXCVBNM���������������";
		   return letra.Pos(c)>0;
	 }
 bool eliminar(AnsiString cad) {
	AnsiString aux = "";  cad=cad+" ";
	int c = 0, c2 = 0;
	bool sw = false;
	for (int i = 1; i <= cad.Length(); i++) {
		if (letra(cad[i])) {
			aux = aux + cad[i];
		} else if (aux != "") {
			c = 0;
			for (int j = 1; j <= aux.Length(); j++) {
				if (vocal(aux[j])) {
					c++;
				}
			}
			if (c > c2) {
				c2 = c;
			}
			aux = "";
		}
	}
	return c2 > 2;
}
		  void eliminar_linea(AnsiString nom) {
	AnsiString aux = "";
	char x;
	ifstream fi(nom.c_str());
	ofstream fo("temporal.txt");
	if (!fi.fail()) {
		while (!fi.eof()) {
			x = fi.get();
			if (!fi.eof()) {
				if (x == '\n') {
					if (!eliminar(aux)) {
						fo << aux << '\n';
					}
					aux = "";
				} else {
					aux = aux + x;
				}
			}
		}
		if (!eliminar(aux)) {
			fo << aux << '\n';
		}
		fi.close();
		fo.close();
		remove(nom.c_str());
		rename("temporal.txt", nom.c_str());
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (OpenTextFileDialog1->Execute()) {
	Edit1->Text=OpenTextFileDialog1->FileName;
	eliminar_linea(Edit1->Text);
}
}
//---------------------------------------------------------------------------
