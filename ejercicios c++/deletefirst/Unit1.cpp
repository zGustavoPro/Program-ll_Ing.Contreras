//---------------------------------------------------------------------------

#include <vcl.h>
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
bool pertenece(char e){
AnsiString con="qwertyuiopasdfghjklñmnbvcxz";
byte pos = con.Pos(e);
return pos >0;
}
void deletefirstword(AnsiString &x){
if (x=="") {
} else {
char e=x[1];
x.Delete(1,1);
if (!pertenece(e)){
deletefirstword(x);
}else  if (x!="" && pertenece(x[1])) {
	deletefirstword(x);
}

}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
deletefirstword(Edit1->Text);
}
//---------------------------------------------------------------------------
