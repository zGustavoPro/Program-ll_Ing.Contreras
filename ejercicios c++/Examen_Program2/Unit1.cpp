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
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  nomArch="C:\\ejercicios c++\\Examen_Program2\\Alumnos.dat";
  // nomArchIdxCod="C:\\Users\\usuario\\OneDrive\\Documents\\2024-1 universidad\\program II\\archivos2\\AlumnosCod.idx";
   pf=new fstream (nomArch.c_str(),ios::in|ios::binary);
   if (pf->fail()) {
	   delete(pf);
	   pf=new fstream (nomArch.c_str(),ios::out|ios::binary);
   }
   pf->close();
   delete(pf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	RegAlumno reg,reg2;
  bool hallado;
  AnsiString cadena;
  pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);
  if (!pf->fail()) {
	 reg.marca=0;
	 reg.cod=StrToInt(Edit1->Text);
	 cadena=Edit2->Text;
	 strcpy(reg.nombre,cadena.c_str());
	 cadena=Edit3->Text;
	 strcpy(reg.direccion,cadena.c_str());
	 reg.fechaNac.dia=StrToInt(Edit4->Text);
	 reg.fechaNac.mes=StrToInt(Edit5->Text);
	 reg.fechaNac.año=StrToInt(Edit6->Text);
	 //reg.telefono = StrToInt(Edit7->Text);
	 //falta un edit para el telefono
	 hallado = false;
	 while(!pf->eof() && !hallado)
	 {
		pf->read((char*)&reg2,sizeof(reg2));
		if(!pf->eof())
		{
		  hallado = (reg.cod==reg2.cod)&&(reg2.marca==0);
		}
	 }
	 if(hallado){
		pf->seekg(-sizeof(reg),ios::cur);
		pf->write((char *)&reg,sizeof(reg));
	 }else{
		pf->close();
		delete(pf);
		pf=new fstream(nomArch.c_str(),ios::app|ios::binary);
		pf->write((char *)&reg,sizeof(reg));
	 }
	 Button3Click(Sender);//limpi la pantallita
	 Edit1->Text="0";
	 Edit1->SetFocus();
	 pf->close();
  }
  delete(pf);

}
//---------------------------------------------------------------------------

