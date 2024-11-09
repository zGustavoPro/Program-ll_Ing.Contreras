//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Alumnos.h"
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
  nomArch="Alumnos.dat";
  nomArchIdxCod = "AlumnosCod.idx";
  pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
  if (pf->fail()) {
	 delete(pf);
	 pf=new fstream(nomArch.c_str(),ios::out|ios::binary);
  }
  pf->close();
  delete(pf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Edit2 ->Text= "";
	Edit3 ->Text= "";
	Edit4 ->Text= "";
	Edit5 ->Text= "";
	Edit6 ->Text= "";
	Edit7->Text="";
}
//---------------------------------------------------------------------------
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
	 strcpy(reg.direcci�n,cadena.c_str());
	 reg.fechaNac.d�a=StrToInt(Edit4->Text);
	 reg.fechaNac.mes=StrToInt(Edit5->Text);
	 reg.fechaNac.a�o=StrToInt(Edit6->Text);
	 reg.telefono=StrToInt(Edit7->Text);
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
void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
  RegAlumno reg; Word codi;  bool hallado;
  codi=StrToInt(Edit1->Text);
  pf=new fstream(nomArch.c_str());
  if (!pf->fail()) {
	 hallado=false;
	 while (!pf->eof() && !hallado){
	   pf->read((char*)&reg,sizeof(reg));
	   if (!pf->eof()) {
		  if ((codi==reg.cod)&& (reg.marca ==0)) {
			 hallado=true;
		  }
	   }
	 }
	 if (hallado) { //mostrar los datos en la pantallita
		Edit2->Text=reg.nombre;
		Edit3->Text=reg.direcci�n;
		Edit4->Text=reg.fechaNac.d�a;
		Edit5->Text=reg.fechaNac.mes;
		Edit6->Text=reg.fechaNac.a�o;
		Edit7->Text=reg.telefono;
		Edit2->SetFocus();
	 } else { //limpiar la pantallita
		Button3Click(Sender);
	 }
	 pf->close();
  }
  delete(pf);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{ RegAlumno reg;//nueva estructura
  RegAlumnoAnt rAnt; //estructura anterior
  pf = new fstream(nomArch.c_str(),ios::binary|ios::in);
  fstream fNuevo("temporal.dat",ios::binary|ios::out);
  if(!pf->fail()){
	while(!pf->eof()){
	  pf->read((char*)&rAnt,sizeof(rAnt));
	  if(!pf->eof()){
		reg.marca= 0;
		reg.cod= rAnt.cod;
		strcpy(reg.nombre, rAnt.nombre);
		strcpy(reg.direcci�n, rAnt.direcci�n);
		reg.fechaNac=rAnt.fechaNac;
		reg.telefono=0;
		fNuevo.write((char*)&reg,sizeof(reg));

	  }
	}
	pf->close();
	fNuevo.close();
	remove(nomArch.c_str());
	rename("temporal.dat",nomArch.c_str());
	Button4->Enabled = false;
  }
  delete(pf);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)    //Algoritmo para borrado logico de un registro
{
  RegAlumno reg; bool hallado; Word codi;
  pf = new fstream(nomArch.c_str(),ios::binary|ios::in|ios::out);
  if(!pf->fail()){
	hallado = false;
	codi=StrToInt(Edit1->Text);
	while(!pf->eof()&&!hallado){
	  pf->read((char*)&reg,sizeof(reg));
	  if(!pf->eof()){
		hallado= (codi==reg.cod)&&(reg.marca==0);
	  }
	}
	  if(hallado){
	  byte marca = 1;
	  pf->seekg(-sizeof(reg),ios::cur);
	  pf->write((char*)&marca,1);
	  Button3Click(Sender);
	  Edit1->Text="0"; Edit1->SetFocus();
	}
	pf->close();
  }
  delete(pf);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IndexarporCodigo1Click(TObject *Sender)
{//Algoritmo para crear el archivo indice por codigo
  RegAlumno reg; RegIdxCod rIdx;
  pf = new fstream(nomArch.c_str(),ios::binary|ios::in);
  pfIdx= new fstream(nomArchIdxCod.c_str(),ios::binary|ios::out);
  if (!pf->fail()) {
	while (!pf->eof()){
		rIdx.pos= pf->tellg();//posicion del untero en el archivo de datos
		pf ->read((char*)&reg,sizeof(reg));
		if (!pf->eof()) {
			rIdx.cod=reg.cod;
			pfIdx->write((char*)&rIdx,sizeof(rIdx));
		}
	}
   pf->close();
   pfIdx->close();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{//algoritmo que busca el indice por codigo
  RegAlumno reg; RegIdxCod rIdx; bool hallado;
  Word codi = StrToInt(Edit1->Text);
  pfIdx= new fstream(nomArchIdxCod.c_str(),ios::binary|ios::in);
  if (!pfIdx->fail()) {
	 hallado = false;
	 while (!pfIdx->eof()&& !hallado){
		  pfIdx ->read((char*)&rIdx,sizeof(rIdx));
		  hallado = rIdx.cod== codi;
	 }
	 pfIdx->close();
	 if(hallado){
	   pf= new fstream(nomArch.c_str(), ios:: binary|ios::in);
	   pf->seekg(rIdx.pos,ios::beg);
	   pf->read((char*)&reg, sizeof(reg));
	   pf->close();
	   delete(pf);
	   Edit2->Text= reg.nombre;
	   Edit3->Text= reg.direcci�n;
	   Edit4->Text = reg.fechaNac.d�a;
	   Edit5->Text= reg.fechaNac.mes;
	   Edit6->Text= reg.fechaNac.a�o;
	 }else {
	   Button3Click(Sender);//borrar la pantalla

	 }
	 delete(pfIdx);
  }

}
//---------------------------------------------------------------------------

 // ordenar decendente los meses
void __fastcall TForm1::Button6Click(TObject *Sender)
{
RegAlumno reg;
AnsiString cad;
pf=new fstream(nomArch.c_str(),ios::in|ios::binary|ios::out);
pf2=new fstream("lista.dat");

  if (!pf->fail()) {
  for (int i=12; i>0; i--) {

  }
  while (!pf->eof()){


  }
} }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
RegAlumno reg,reg2;
pf=new fstream(nomArch.c_str(),ios::binary|ios::in);
 fstream pf2("temporal.dat",ios::binary|ios::out|ios::trunc);  bool sw=true;
   if (!pf->fail()) {
	Cardinal c=0;
	   while (!pf->eof())    {
	   pf->read((char*)&reg,sizeof(reg));
			if (sw) {
				reg.telefono=reg.telefono*10000;
				 reg2=reg;
				sw=false;
				c=reg.fechaNac.a�o;
			}else {
				reg.telefono=(reg.telefono*10000)+c;
				c=reg.fechaNac.a�o;
				reg2=reg;
			}
				pf2.write((char*)&reg2,sizeof(reg2));
			}
		   pf->close();
		   pf2.close();
		   remove(nomArch.c_str());
		   rename("temporal.dat",nomArch.c_str());
   }
   delete(pf);
}
//---------------------------------------------------------------------------

