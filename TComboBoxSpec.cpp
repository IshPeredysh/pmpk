//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TComboBoxSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

/*void __fastcall TComboBoxSpec::WndProc(Messages::TMessage &Message)
{
//	if (msg.Msg == WM_MOUSEWHEEL){
//			ChangeHeight();
//		}
	TComboBox::WndProc(Message);
}      */

void __fastcall TComboBoxSpec::WMMouseWheel(TWMMouseWheel &msg)
{
	TShiftState shift;
	TPoint point;
	bool handled = false;

	point.x = msg.Pos.x;
	point.y = msg.Pos.y;
	shift.Clear();
	if (msg.WheelDelta > 0)	{
		if (FOnMouseWheelUp)
			OnMouseWheelUp(this, shift, point, handled);
	}
	else
		if (FOnMouseWheelDown) {
			OnMouseWheelDown(this, shift, point, handled);
		}
}

void TComboBoxSpec::SetCaption()
{
	this->Text = "[" + FFieldName + "][" + IntToStr(FFieldType) + "][" + IntToStr(FAppointment)+ "][" + IntToStr(FParentID) + "]";
}

void __fastcall TComboBoxSpec::SetFieldName(String Value)
{
	FFieldName = Value;
	SetCaption();
}

void __fastcall TComboBoxSpec::SetFieldType(int Value)
{
	FFieldType = Value;
	SetCaption();
}


void __fastcall TComboBoxSpec::SetAppointment(int Value)
{
	FAppointment = Value;
	SetCaption();
}
void __fastcall TComboBoxSpec::SetParentID(int Value)
{
	FParentID = Value;
	SetCaption();
}

void __fastcall TComboBoxSpec::SetItemID(int Value)
{
		/*if (ListID == 0) {
			throw "ListID empty";
		} */

	FItemID = Value;

	if (FOnAfterSetItemID) {
		FOnAfterSetItemID(this);
	}
}

void __fastcall TComboBoxSpec::SetListID(int Value)
{
	FListID = Value;
}

void __fastcall TComboBoxSpec::SetModify(int Value)
{
	if (MonitiorModify == true) {
		FModify = Value;
	}
};

static inline void ValidCtrCheck(TComboBoxSpec *)
{
	new TComboBoxSpec(NULL);
}
//---------------------------------------------------------------------------
__fastcall TComboBoxSpec::TComboBoxSpec(TComponent* Owner)
	: TComboBox(Owner)
{
	MonitiorModify = false;
	FModify = false;
	OldOnFontChange = Font->OnChange;
	Font->OnChange = WmOnFontChange;
}


void __fastcall TComboBoxSpec::WmOnFontChange(TObject *Sender)
{
    OldOnFontChange(this);
	if (FOnFontChange) {
		FOnFontChange(this);
	}
}
//---------------------------------------------------------------------------
namespace Tcomboboxspec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TComboBoxSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
