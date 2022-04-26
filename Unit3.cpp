//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//---------------------------------------------------------------------------

__fastcall potok2::potok2(byte *dataBuffer, TEvent *sbt, bool CreateSuspended)
	: TThread(CreateSuspended)
{
	DataBuffer = dataBuffer;
	   Sbt=sbt;
}
//---------------------------------------------------------------------------
void __fastcall potok2::Execute()
{
	 while(!Terminated){

		if(Sbt->WaitFor(0)==wrSignaled)
		{
		Synchronize(&UpdateCaption);
		Sbt->ResetEvent();
		}
	}
	//---- Place thread code here ----
}
//---------------------------------------------------------------------------

	 void __fastcall potok2::UpdateCaption()
  {
   String s1;
	Form1->Label3->Caption = "";
			for (int i = 0; i < 512; i++)
		{
		s1 += reinterpret_cast<char*>(DataBuffer)[i];
		if(i%16 == 15)
		{
			Form1->Label3->Caption += s1;
			Form1->Label3->Caption += "\n";
			s1="";
		}
		}


  }