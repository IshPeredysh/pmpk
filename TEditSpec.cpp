//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TEditSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

void TEditSpec::SetCaption()
{
	this->Text = "[" + FFieldName + "][" + IntToStr(FFieldType) + "][" + FAppointment + "][" + IntToStr(FListID) + "]";
}

//----interface
//---Set



void __fastcall TEditSpec::SetFieldName(String Value)
{
	FFieldData = Value;
	FFieldName = FFieldData;
	SetCaption();
}

void __fastcall TEditSpec::SetFieldType(int Value)
{
	FFieldType = Value;
	SetCaption();
}

void __fastcall TEditSpec::SetTextData(String Value)
{
	Text = Value;
}

void __fastcall TEditSpec::SetListID(int Value)
{
	FListID = Value;
	SetCaption();
}

void __fastcall TEditSpec::SetItemID(int Value)
{
	if (ListID == 0) {
		throw "ListID empty";
	}

	FItemID = Value;

	if (FOnAfterSetItemID) {
		FOnAfterSetItemID(this);
	}
}

void __fastcall TEditSpec::SetAppointment(int Value)
{
	FAppointment = Value;
}

//interface---

void __fastcall TEditSpec::SetModify(int Value)
{
	if (MonitiorModify == true) {
		FModify = Value;
	}
};


static inline void ValidCtrCheck(TEditSpec *)
{
	new TEditSpec(NULL);
}
//---------------------------------------------------------------------------
__fastcall TEditSpec::TEditSpec(TComponent* Owner)
	: TEdit(Owner)
{
	MonitiorModify = false;
	FModify = false;
	OldOnFontChange = Font->OnChange;
	Font->OnChange = WmOnFontChange;
}

void __fastcall TEditSpec::WmOnFontChange(TObject *Sender)
{
	OldOnFontChange(this);
	if (FOnFontChange) {
		FOnFontChange(this);
	}
}
//---------------------------------------------------------------------------
namespace Teditspec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TEditSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
