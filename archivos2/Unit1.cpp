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
   nomArch="C:\\Users\\usuario\\OneDrive\\Documents\\2024-1 universidad\\program II\\archivos2\\Alumnos.dat";
   nomArchIdxCod="C:\\Users\\usuario\\OneDrive\\Documents\\2024-1 universidad\\program II\\archivos2\\AlumnosCod.idx";
   pf=new fstream (nomArch.c_str(),ios::in|ios::binary);
   if (pf->fail()) {
	   delete(pf);
	   pf=new fstream (nomArch.c_str(),ios::out|ios::binary);
   }
   pf->close();
   delete(pf);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
Edit5->Text="";
Edit6->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Exit(TObject *Sender)           //edit1 exit
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
		Edit3->Text=reg.direccion;
		Edit4->Text=reg.fechaNac.dia;
		Edit5->Text=reg.fechaNac.mes;
		Edit6->Text=reg.fechaNac.año;
		//Edit7->Text=reg.telefono;
		Edit2->SetFocus();
	 } else { //limpiar la pantallita
		Button3Click(Sender);
	 }
	 pf->close();
  }
  delete(pf);
}
//---------------------------------------------------------------------------
															 //graba o actualiza los datos
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

void __fastcall TForm1::Button4Click(TObject *Sender)
{
//algoritmo para REESTRUCTURAR UN ARCHIVO DE DATOS
RegAlumno reg; //estructura nueva
RegAlumnoAnt rAnt;    //para leer la estructura anterior
pf=new fstream(nomArch.c_str(),ios::binary|ios::in);
fstream fNuevo("temporal.dat",ios::binary|ios::out);
			 if (!pf->fail()) {
			  while(!pf->eof()) {
				  pf->read((char*)&rAnt,sizeof(rAnt));
				  if (!pf->eof()) {
				  reg.marca=0;
				  reg.cod=rAnt.cod;
				  strcpy(reg.nombre,rAnt.nombre);
					 strcpy(reg.direccion,rAnt.direccion);
					 reg.fechaNac=rAnt.fechaNac;
					 reg.telefono=0;
					 fNuevo.write ((char*)&reg,sizeof(reg));
				  }
			  }
			  pf->close();
			  fNuevo.close();
			  remove(nomArch.c_str());
			  rename("temporal.dat",nomArch.c_str());
			  Button4->Enabled=false;
			 }
			 delete(pf);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{//eliminar un registro
RegAlumno reg; bool hallado; Word codi;
pf = new fstream(nomArch.c_str(),ios::binary|ios::in|ios::out);
  if (!pf->fail()) {
  hallado=false;
  codi=StrToInt(Edit1->Text);
	  while (!pf->eof() && !hallado)  {
	  hallado =false;
		  pf->read((char*)&reg,sizeof(reg));
		  if (!pf->eof()) {
				  hallado=(codi==reg.cod)&&(reg.marca==0);
		  }
	  }
	 if (hallado) {
	 byte m=1;
		 pf->seekg(-sizeof(reg),ios::cur);
		 pf->write((char*)&m,1);//pone la marca
		 Button3Click(Sender);
		 Edit1->Text=0;
		 Edit1->SetFocus();
	 }
		pf->close();
  }
delete(pf) ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Reestructurar2Click(TObject *Sender)
{       //Indexar por codigo
RegAlumno reg; RegIdxCod rIdx;
pf=new fstream (nomArch.c_str(),ios::binary|ios::in);
pfIdx=new fstream(nomArchIdxCod.c_str(),ios::binary|ios::out);
if (!pf->fail()) {
	 while (!pf->eof())  {
	 rIdx.pos=pf->tellg();//posicion del  puntero  en el archivo de datos
		 pf->read((char *)&reg,sizeof(reg));
		 if (!pf->eof()) {
		 rIdx.cod=reg.cod;
		 pfIdx->write((char *)&rIdx,sizeof(rIdx));

		 }
	 }
	 pf->close();
	 pfIdx->close();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	 // algoritmo que busca utilizando el indice por codigo
RegAlumno reg; RegIdxCod rIdx; bool hallado;
Word codi=StrToInt(Edit1->Text);
pfIdx=new fstream(nomArchIdxCod.c_str(),ios::binary|ios::in);
if (!pfIdx->fail()) {
	hallado=false;
	while ( !pfIdx->eof() && !hallado) {
	  pfIdx->read((char*)&rIdx,sizeof(rIdx));
	  if (!pfIdx->eof()) {
		  hallado=rIdx.cod==codi;
	  }
	}
	pfIdx->close();
	if (hallado) {
		pf=new fstream(nomArch.c_str(),ios::binary|ios::in);
		pf->seekg(rIdx.pos,ios::beg);  //ios::beg con respecto al inicio
		pf->read((char *)&reg,sizeof(reg));
		pf->close();
		delete(pf);
		Edit2->Text=reg.nombre;
		 Edit3->Text=reg.direccion;
		  Edit4->Text=reg.fechaNac.dia;
		   Edit5->Text=reg.fechaNac.mes;
			Edit6->Text=reg.fechaNac.año;
	}  else
	  Button3Click(Sender);//borra pantalla

}
	delete(pf); // Tarea hacer busqueda por nombre
}
//---------------------------------------------------------------------------




