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
	  if(yaPotok==NULL)
		yaPotok=new potok(stranica, false);
		Label2->Caption="Текущая страница ";
		Label2->Caption+=stranica;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Label1->Caption="";
	Label2->Caption="";
	stranica=0;
	Label3->Caption="";
    yaPotok = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
stranica++;
Label2->Caption="Текущая страница ";
Label2->Caption+=stranica;
yaPotok=new potok(stranica, false);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
if (stranica>0) {
	stranica--;
Label2->Caption="Текущая страница ";
Label2->Caption+=stranica;
yaPotok=new potok(stranica, false);
}
}
//---------------------------------------------------------------------------
