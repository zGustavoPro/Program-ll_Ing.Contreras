//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <fstream>
#include <windows.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button4;
	TMainMenu *MainMenu1;
	TMenuItem *Archivo1;
	TMenuItem *Archivo2;
	TMenuItem *Reestructurar1;
	TMenuItem *Reestructurar2;
	TMenuItem *Indexarpornombre1;
	TButton *Button5;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Reestructurar2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
AnsiString nomArch;
fstream *pf;
AnsiString nomArchIdxCod;//Archivo indice por codigo
fstream *pfIdx;//puntero de arcivo indice
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
struct Fecha{
	byte dia;
	byte mes;
	Word año;
};
struct RegAlumnoAnt{ //Estructura anterior
	Word cod;
	char nombre[21];
	char direccion[21];
	Fecha fechaNac;
};
struct RegAlumno{        //estructur NUEVA
	byte marca;
	Word cod;
	char nombre[31];
	char direccion[26];
	Fecha fechaNac;
	Cardinal telefono;
};
struct RegIdxCod{                  //estructura del registro indice por codi
  Word cod;
  Cardinal pos;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
