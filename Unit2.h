//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class potok : public TThread
{
private:
class potok2 *Ppotok2;
protected:
	int Stranica;
	void __fastcall UpdateCaption();
	void __fastcall Execute();
public:
	byte *dataBuffer;
	TEvent *Sbt;
	__fastcall potok(int stranica, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
