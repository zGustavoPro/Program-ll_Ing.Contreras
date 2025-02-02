//---------------------------------------------------------------------------

#ifndef AlumnosH
#define AlumnosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <fstream>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button4;
	TMainMenu *MainMenu1;
	TMenuItem *Archivo1;
	TMenuItem *Reestructurar1;
	TMenuItem *IndexarporCodigo1;
	TMenuItem *Indexarpornombre1;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TEdit *Edit7;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall IndexarporCodigo1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
	AnsiString nomArch; //archivo de los datos
	fstream *pf;
    fstream *pf2;
	AnsiString nomArchIdxCod;   //archivo indice por codigo
	fstream *pfIdx;// puntero archivo de indice
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
struct Fecha {
   byte d�a;
   byte mes;
   Word a�o;
};
struct RegAlumnoAnt {     //anterior
   Word cod;
   char nombre[21];
   char direcci�n[21];
   Fecha fechaNac;
};
struct RegAlumno {     //nueva
   byte marca ; // 0= activo  1=borrado
   Word cod;
   char nombre[31];
   char direcci�n[26];
   Fecha fechaNac;
   Cardinal telefono;
};
struct RegIdxCod{  //estructura del registro indice por codigo
   Word cod;
   Cardinal pos;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
