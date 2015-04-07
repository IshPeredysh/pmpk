//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "RichEditSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//


void TRichEditSpec::SetCaption()
{
	this->Text = "[" + FFieldName + "][" + IntToStr(FFieldType) + "][" + FAppointment + "][" + IntToStr(FListID) + "]";
}

void __fastcall TRichEditSpec::SetFieldName(String Value)
{
	FFieldName = Value;
	SetCaption();
}


void __fastcall TRichEditSpec::SetListID(int Value)
{
	FListID = Value;
	SetCaption();
}

void __fastcall TRichEditSpec::SetTextData(String Value)
{
	Text = Value;
}

void __fastcall TRichEditSpec::SetFieldType(int Value)
{
	FFieldType = Value;
	SetCaption();
}

/*
    void __fastcall TRichEditSpec::SetAccess(String Value)
    {
    	FAccess = Value;
    	SetCaption();
	}
*/

void __fastcall TRichEditSpec::SetAppointment(int Value)
{
	FAppointment = Value;
}


void __fastcall TRichEditSpec::SetItemID(int Value)
{
	if (ListID == 0) {
		ShowMessage("ListID empty in " + this->Name);
//		throw "ListID empty in " + this->Name;
	}

	FItemID = Value;

	if (FOnAfterSetItemID) {
		FOnAfterSetItemID(this);
	}
}


void __fastcall TRichEditSpec::SetModify(int Value)
{
	if (MonitiorModify == true) {
		FModify = Value;
	}
};

static inline void ValidCtrCheck(TRichEditSpec *)
{
	new TRichEditSpec(NULL);
}

//---------------------------------------------------------------------------
__fastcall TRichEditSpec::TRichEditSpec(TComponent* Owner)
	: TRichEdit(Owner)
{
	/*MonitiorModify = false;
	FModify = false;*/
	OldOnFontChange = Font->OnChange;
	Font->OnChange = WmOnFontChange;
}

void __fastcall TRichEditSpec::InsertInCaret(String Value)
{
	String str1, str2;
	int p;

	str1 = Text.SubString(1, SelStart);
	p = SelStart + SelLength;
	str2 = Text.SubString(p, Text.Length() - p - 1);

	Text = str1 + Value + str2;
}

TPhrase __fastcall TRichEditSpec::GetActivePhrase()
{
	int i;
	TPhrase phrase;

	i = SelStart;
	if (i != 0)
		i--;
	while (i > 0 && i < Text.Length())	{
		if (Text[i + 1] == ';') {
			i++;
			break;
		}
		i--;
	}
//	i++;
	phrase.Start = i;

	i = SelStart;
	while (i >= 0 && i < Text.Length() && Text[i + 1] != ';')	{
		if (Text[i + 1] == ';') {
			i--;
			break;
		}
		i++;
	}
//	i--;

	phrase.Length = i - phrase.Start;

	phrase.Text = Text.SubString(phrase.Start + 1, phrase.Length);

	return phrase;
}

void __fastcall TRichEditSpec::ReplaseActivePhrase(String Value)
{
	TPhrase p;
	String s1, s2, temp;
	int l;

	p = GetActivePhrase();
//	Text.Delete(p.Start + 1, p.Length);

	s1 = Text.SubString(1, p.Start);
	l = p.Start + p.Length;
	s2 = Text.SubString(l + 1, Text.Length() - l - 1);

	if (s1 != "" && s1[s1.Length()] == ';')
		if (Value != "" && Value[1] != ' ') {
			s1 += " ";
	}

	Text = s1 + Value + s2;
	SelStart = s1.Length() + Value.Length();
}

void __fastcall TRichEditSpec::SetStillItemID(int Value)
{
	FItemID = Value;
}


void __fastcall TRichEditSpec::WmOnFontChange(TObject *Sender)
{
    OldOnFontChange(this);
	if (FOnFontChange) {
		FOnFontChange(this);
	}
}


//---------------------------------------------------------------------------
namespace Richeditspec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TRichEditSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
