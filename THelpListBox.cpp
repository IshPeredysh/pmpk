//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "THelpListBox.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

void __fastcall THelpListBox::SetSubString(String Value)
{
	FSubString = Value;
}

void __fastcall THelpListBox::Close()
{
	Visible = false;
	Items->Clear();
}

void __fastcall THelpListBox::WmOnFontChange(TObject *Sender)
{
    OldOnFontChange(this);
	if (FOnFontChange) {
		FOnFontChange(this);
	}
}


static inline void ValidCtrCheck(THelpListBox *)
{
	new THelpListBox(NULL);
}
//---------------------------------------------------------------------------
__fastcall THelpListBox::THelpListBox(TComponent* Owner)
	: TListBox(Owner)
{
	OldOnFontChange = Font->OnChange;
	Font->OnChange = WmOnFontChange;
}
//---------------------------------------------------------------------------
namespace Thelplistbox
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(THelpListBox)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
