//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	yaPotok = NULL;
	stranica=0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
       	yaPotok=new potok(stranica, false);
		Label2->Caption="Текущий сектор ";
		Label2->Caption+=stranica;
		Button1->Enabled=false;
		Button2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	stranica=0;
	yaPotok->Terminate();  // стоп поток
	yaPotok = NULL;
	Button1->Enabled=true;
	Button2->Enabled=false;
}
//---------------------------------------------------------------------------


