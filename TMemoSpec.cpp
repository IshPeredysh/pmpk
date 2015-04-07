//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TMemoSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//


/*void __fastcall TMemoSpec::WndProc(Messages::TMessage &msg)
{
	if (msg.Msg == EN_CHANGE) {
		if (FAutoHeight)
			_AutoHeight(this);
	}
	TWinControl::WndProc(msg);
} */


/*void __fastcall TMemoSpec::_AutoHeight(TObject *Sender)
{
	int len, cnt;
	String lastChar;
	TMemo *m = this;

	len = m->Lines->Text.Length();
	lastChar = m->Lines->Text.SubString(len - 1, 2);

	cnt = m->Lines->Count;
	if (lastChar == "\r\n" || m->Lines->Text.data() == NULL)
		cnt++;

	m->Height = (cnt * (m->Font->Height + (m->Font->Height + m->Font->Size) + 1) * -1) + 6;
}*/


void __fastcall TMemoSpec::SetFieldData(String Value)
{
	FFieldData = Value;
	this->Text = "[" + FFieldData + "][" + FAccess + "]";
}

void __fastcall TMemoSpec::SetAccess(String Value)
{
	FAccess = Value;
	this->Text = "[" + FFieldData + "][" + FAccess + "]";
}


static inline void ValidCtrCheck(TMemoSpec *)
{
	new TMemoSpec(NULL);
}
//---------------------------------------------------------------------------
__fastcall TMemoSpec::TMemoSpec(TComponent* Owner)
	: TMemo(Owner)
{
//	FAutoHeight = 1;
//	this->Parent = (TWinControl*)Owner;
}
//---------------------------------------------------------------------------
namespace Tmemospec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TMemoSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
