//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall potok::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall potok::potok(int stranica, bool CreateSuspended)
	: TThread(CreateSuspended)
{
	  Sbt=new TEvent(NULL,true,false,"",false);
	  dataBuffer = new byte[512];
	  Stranica=stranica;
	  Ppotok2= new potok2(dataBuffer, Sbt, true);
}
//---------------------------------------------------------------------------
void __fastcall potok::Execute()
{
   wchar_t *fileName =L"\\\\.\\C:";
   HANDLE fileHander=CreateFileW(fileName,
   GENERIC_READ,
   FILE_SHARE_READ | FILE_SHARE_WRITE,
   NULL,
   OPEN_EXISTING,
   FILE_ATTRIBUTE_NORMAL,
   NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		Form1->Label1->Caption = "Не удалось открыть диск C:.\nИспользуйте запуск exe-файла с правами администратора.\n";
		Sleep(INFINITY);
	}
	Ppotok2->Start();
	 //while (!Terminated) {
	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=Stranica*512;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)
	  {}

	 DWORD bytesToRead=512;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead)
	 {
			Form1->Label1->Caption = L"Ошибка чтения";
			Sleep(INFINITY);
	 }
	Sbt->SetEvent();
	Synchronize(&UpdateCaption);
	while (Sbt ->WaitFor(0)==wrSignaled)
		 {
			 Sleep(0);
		 }
  //	}
	Ppotok2->Terminate();
	delete[] dataBuffer;
	delete Ppotok2;
	CloseHandle(fileHander);

}
//---------------------------------------------------------------------------
	 void __fastcall potok::UpdateCaption()
  {
   String s1;
	Form1->Label1->Caption = "";
			for (int i = 0; i < 512; i++)
		{
		s1 += reinterpret_cast<char*>(dataBuffer)[i];
		if(i%16 == 15)
		{
			String s2;
		   std::stringstream ss;
			for (const auto &item : s1) {
				if (int(item)>65280) {
					 ss << std::hex << int(item)-65280;
				}
				 else

				if (int(item)<=15) {
					ss << std::hex << "0" << int(item);
				}
				else
				ss << std::hex << int(item);
				ss << " ";
			}
			s2 = ss.str();
			Form1->Label1->Caption += s2;
			Form1->Label1->Caption += "\n";
			s1="";
		}
		}


  }
