//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChildrenInfo.h"
#include "TChildrenList.h"
#include "DM3Unit.h"
#include "Areas.h"
#include "Parents.h"
#include "Organizations.h"
#include "TListList.h"
#include "JuornByChildUnit.h"
#include "SpecEvents.h"
#include "TAutoSize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TEditSpec"
#pragma link "TDateTimePickerSpec"
#pragma link "TComboBoxSpec"
#pragma resource "*.dfm"
TChildrenInfoForm *ChildrenInfoForm;

extern TChildrenList* Childrens;
extern TListList *ListList;

void SetInitValue(TEdit *Control, String Value) //Обходим OnChange
{
	TNotifyEvent Event;

	Event = Control->OnChange;
	Control->OnChange = NULL;
	Control->Text = "";
	Control->Text = Value;
	Control->OnChange = Event;
}

void SetInitValue(TMemo *Control, String Value) //Обходим OnChange
{
	TNotifyEvent Event;

	Event = Control->OnChange;
	Control->OnChange = NULL;
	Control->Text = "";
	Control->Text = Value;
	Control->OnChange = Event;
}

void TChildrenInfoForm::GetRecord()
{
	/*TLocateOptions opts;
	TADOQuery *q = DM->ChildGetInfoQuery;*/

	/*SetInitValue(FIOEdit, Children->Descr.TrimRight());
	BirthdayPicker->Date = Children->Birthday;
	BirthdayPickerChange(BirthdayPicker);
	AreaEditSpec->ItemID = Children->AreaID;
	PlaceStudyEditSpec->ItemID = Children->PlaceStudyID;
	FatherEditSpec->Text = Children->Father.TrimRight();
	MotherEdit->Text = Children->Mother.TrimRight();
	SetInitValue(AdressEdit, Children->Adress);
	SetInitValue(HistoryMemo, Children->History);
	SetInitValue(ExtInfoMemo, Children->ExtInfo); */

	FIOEdit->Text = Children->Descr;
	AdressEdit->Text = Children->Adress;
	HistoryMemo->Lines->Text = Children->History;
	ExtInfoMemo->Lines->Text = Children->ExtInfo;
	PlaceStudyEditSpec->ItemID = Children->PlaceStudyID;
	FatherEditSpec->ItemID = Children->FatherID;
	MotherEditSpec->ItemID = Children->MotherID;
	AreaEditSpec->ItemID = Children->AreaID;
	BirthdayPickerSpec->Date = Children->Birthday;
	BirthdayPickerChange(BirthdayPickerSpec);
	SexBoxSpec->ItemID = Children->SexID;

//	q->Close();
}

//---------------------------------------------------------------------------
__fastcall TChildrenInfoForm::TChildrenInfoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TChildrenInfoForm::FormShow(TObject *Sender)
{
//	ChildrenInfoForm->Children = new TChildren(*(ChildrenInfoForm->PChildren));
//	ChildrenInfoForm->Children = new TChildren(Children);
	GetRecord();
}
//---------------------------------------------------------------------------


void __fastcall TChildrenInfoForm::SaveButtonClick(TObject *Sender)
{
	Children->Descr = FIOEdit->Text;
	Children->Adress = AdressEdit->Text;
	Children->History = HistoryMemo->Lines->Text;
	Children->ExtInfo = ExtInfoMemo->Lines->Text;
	Children->PlaceStudyID = PlaceStudyEditSpec->ItemID;
	Children->FatherID = FatherEditSpec->ItemID;
	Children->MotherID = MotherEditSpec->ItemID;
	Children->AreaID = AreaEditSpec->ItemID;
	Children->Birthday = BirthdayPickerSpec->DateSpec;
	Children->SexID = SexBoxSpec->ItemID;

	Children->Save(DM->ChildrenGetMaxQuery, DM->ChildrenInsertQuery, DM->ChildrenUpdateQuery, NULL);

	Close();
	ModalResult = mrOk;

}
//---------------------------------------------------------------------------


void __fastcall TChildrenInfoForm::SpeedButton2Click(TObject *Sender)
{
	ParentsForm->SenderChildren = 1;
    ParentsForm->FIOEdit = FatherEditSpec; 
	ParentsForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::SpeedButton3Click(TObject *Sender)
{
	ParentsForm->SenderChildren = 1;
    ParentsForm->FIOEdit = MotherEditSpec; 
	ParentsForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::FIOEditChange(TObject *Sender)
{
	Children->Descr = FIOEdit->Text;
}
//---------------------------------------------------------------------------


void __fastcall TChildrenInfoForm::AreaButtonClick(TObject *Sender)
{
	AreasForm->SetEdit = AreaEditSpec;
	AreasForm->Show();

}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::CancelButtonClick(TObject *Sender)
{
	ModalResult = mrCancel;
	Close();	
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::HistoryMemoChange(TObject *Sender)
{
	Children->History = HistoryMemo->Text;
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::ExtInfoMemoChange(TObject *Sender)
{
	Children->ExtInfo = ExtInfoMemo->Text;
}
//---------------------------------------------------------------------------




void __fastcall TChildrenInfoForm::SpeedButton1Click(TObject *Sender)
{
	OrganizationsForm->SetEdit = PlaceStudyEditSpec;
	OrganizationsForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::EditSpecAfterSetItemID(TObject *Sender)
{
	TEditSpec *es = (TEditSpec*)Sender;
	TBaseList *bl;
	TBase *b;

	bl = ListList->GetByListID(es->ListID);
	if (bl == NULL)	{
    	es->Text = "";
		return;
	}

	b = (TBase*)bl->ItemByID(es->ItemID);
	if (b == NULL)	{
        es->Text = "";
		return;
	}

	es->Text = b->Descr;
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::BirthdayPickerKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	TDateTimePicker *dt = (TDateTimePicker*)Sender;

	if (Key == 46) {
		dt->Format = " ";
		dt->Date = Now();
	}
	else
		dt->Format = "";
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::BirthdayPickerChange(TObject *Sender)
{
	TDateTimePicker *dt = (TDateTimePicker*)Sender;
	String str;

	str = dt->Date.DateString();
	if (str == "30.12.1899")	{
		dt->Format = " ";
		dt->Date = Now();
	}
	else
		dt->Format = "";
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::Button1Click(TObject *Sender)
{
	if (JournByChildForm->FillGrid(Children->ID) > 1)
		JournByChildForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TChildrenInfoForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == 27) {
		ModalResult = mrCancel;
		Close();
	}
}
//---------------------------------------------------------------------------




void __fastcall TChildrenInfoForm::SexBoxSpecAfterSetItemID(TObject *Sender)
{
	ComboBoxSpecAfterSetItemID(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TChildrenInfoForm::SexBoxSpecSelect(TObject *Sender)
{
	ComboBoxSpecSelect(Sender);	
}
//---------------------------------------------------------------------------


void __fastcall TChildrenInfoForm::ChangeFont(TFont *f)
{
	int i;
	TControl* c;

	Font->Assign(f);
	for (i = 0; i < ChildrenInfoForm->ControlCount; i++) {
		c = ChildrenInfoForm->Controls[i];
		ControlAutoSizeLevelDown(c);
	}
}
