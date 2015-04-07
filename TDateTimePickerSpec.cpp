//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TDateTimePickerSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

void __fastcall TDateTimePickerSpec::SetFieldName(String Value)
{
	FFieldName = Value;
}

void __fastcall TDateTimePickerSpec::SetListID(int Value)
{
	FListID = Value;
}

void __fastcall TDateTimePickerSpec::SetTextData(String Value)
{
	Text = Value;
}

void __fastcall TDateTimePickerSpec::SetFieldType(int Value)
{
	FFieldType = Value;
}

void __fastcall TDateTimePickerSpec::SetAppointment(int Value)
{
	FAppointment = Value;
}


void __fastcall TDateTimePickerSpec::SetItemID(int Value)
{
	FItemID = Value;
}

String __fastcall TDateTimePickerSpec::GetTextData()
{
	if (this->Format == "")
		return DateToStr(this->Date);
	else
		return "";
}

TDateTime __fastcall TDateTimePickerSpec::GetDateSpec()
{
	if (this->Format == " ")
		return NULL;
	else
		return this->Date;
}

void __fastcall TDateTimePickerSpec::SetModify(int Value)
{
	if (MonitiorModify == true) {
		FModify = Value;
	}
}

static inline void ValidCtrCheck(TDateTimePickerSpec *)
{
	new TDateTimePickerSpec(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDateTimePickerSpec::TDateTimePickerSpec(TComponent* Owner)
	: TDateTimePicker(Owner)
{
	MonitiorModify = false;
	FModify = false;
	OldOnFontChange = Font->OnChange;
	Font->OnChange = WmOnFontChange;
}

void __fastcall TDateTimePickerSpec::WmOnFontChange(TObject *Sender)
{
    OldOnFontChange(this);
	if (FOnFontChange) {
		FOnFontChange(this);
	}
}

/*void __fastcall TDateTimePickerSpec::WndProc(Messages::TMessage &msg)
{
	if (msg.Msg == WM_FONTCHANGE)
		FontChange(msg.Msg = WM_FONTCHANGE);

	TDateTimePicker::WndProc(msg);
}*/
//---------------------------------------------------------------------------

/*void __fastcall TDateTimePickerSpec::OnFontChange(TObject *Sender)
{

	if (FOnFontChange) {

	}
	TDateTimePicker* d = (TDateTimePicker*)Sender;

	ShowMessage(String(Sender->ClassName()) + " font changed! " + IntToStr(d->Font->Height));
}*/


namespace Tdatetimepickerspec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TDateTimePickerSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
