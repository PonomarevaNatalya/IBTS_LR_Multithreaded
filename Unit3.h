//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class potok2 : public TThread
{
private:
protected:
	void __fastcall Execute();
	void __fastcall UpdateCaption();
public:
	byte *DataBuffer;
	TEvent *Sbt;
	__fastcall potok2(byte *dataBuffer, TEvent *sbt, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
