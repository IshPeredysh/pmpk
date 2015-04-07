//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ParentsInfo.h"
#include "TParent.h"
#include "TTreeBaseEmptyList.h"
#include "DMUnit.h"
#include "ExtFunctions.h"
#include "SpecEvents.h"
#include "ChildrenInfo.h"
#include "TChildrenList.h"
#include "TAutoSize.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TComboBoxSpec"
#pragma link "TEditSpec"
#pragma resource "*.dfm"
TParentsInfoForm *ParentsInfoForm;
extern TTreeBaseEmptyList *OtherObjectList;
extern TChildrenList* Childrens;

//---------------------------------------------------------------------------
__fastcall TParentsInfoForm::TParentsInfoForm(TComponent* Owner)
	: TForm(Owner)
{
}

void SetInitValue(TEdit *Control, String Value) //Обходим OnChange
{
	TNotifyEvent Event;

	Event = Control->OnChange;
	Control->OnChange = NULL;
	Control->Text = "";
	Control->Text = Value;
	Control->OnChange = Event;
}


/*void TParentsInfoForm::FillBox(String ID, TTreeBaseList *list, TComboBox *box)
{
	TTreeBase *Item;

	box->Items->Clear();
	if ((Item = list->GetFirstItemByParentID(ID)) != NULL) {
		box->Items->AddObject(Item->Descr, (TObject*) new String(Item->ID));
	}

	while ((Item = OtherObjectList->GetNextItemByParentID(ID)) != NULL)	{
		box->Items->AddObject(Item->Descr, (TObject*) new String(Item->ID));
	}
}   */


/*void TParentsInfoForm::BoxItemByID(String ID, TComboBox* box)
{
	int i;
	String str;

	for (i = 0; i < box->Items->Count; i++) {
		str = *((String*)(box->Items->Objects[i]));
		if (str == ID)	{
			box->ItemIndex = i;
			return;
		}
	}
	box->ItemIndex = -1;
} */

//---------------------------------------------------------------------------


void TParentsInfoForm::FillAllBox()
{
	TComboBoxSpec* box;
	int i;
	String str;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		if (str == "TComboBoxSpec") {
			box = (TComboBoxSpec*)Components[i];
			FillBox(box->ParentID, OtherObjectList, box);
		}
	}
}

void TParentsInfoForm::ClearChildren()
{
	int i;

	/*for (i = 0; i < ListBox1->Items->Count; i++) {
		delete (TChildren*)ListBox1->Items->Objects[i];
	}*/
    ListBox1->Items->Clear();
}

void TParentsInfoForm::FillChildren()
{
	TADOQuery *q = DM->ParentGetChildQuery;
	TChildren *child;

	ClearChildren();
	q->Parameters->ParamByName("fatherID")->Value = ThisParent->ID;
	q->Parameters->ParamByName("motherID")->Value = ThisParent->ID;
	q->Open();
	q->First();
	while (!q->Eof)	{
		child = (TChildren*)Childrens->ItemByID(q->FieldByName("ID")->AsInteger);
		if (child != NULL) {
			ListBox1->Items->AddObject(child->Descr, (TObject*)child);
		}
		q->Next();
	}
	q->Close();
}

void __fastcall TParentsInfoForm::FormShow(TObject *Sender)
{
	//	ThisParent = new TParent(*(ParentsInfoForm->PThisParent));
//	FillAllBox();

	FIOEdit->Text = ThisParent->Descr;
	AgeEdit->Text = ThisParent->Age;
	BoxItemByID(ThisParent->Education, EducationBoxSpec);
	BoxItemByID(ThisParent->BadHabit, BadHabitBoxSpec);
	BoxItemByID(ThisParent->BadStrain, BadStrainBoxSpec);
	WorkEditSpec->Text = ThisParent->Work;

	FillChildren();
}
//---------------------------------------------------------------------------
void __fastcall TParentsInfoForm::FIOEditChange(TObject *Sender)
{
	ThisParent->Descr = FIOEdit->Text;
}
//---------------------------------------------------------------------------

void __fastcall TParentsInfoForm::AgeEditChange(TObject *Sender)
{
    ThisParent->Age = AgeEdit->Text.ToIntDef(0);
}
//---------------------------------------------------------------------------


void __fastcall TParentsInfoForm::Button1Click(TObject *Sender)
{
	ThisParent->Descr = FIOEdit->Text;
	ThisParent->Age = AgeEdit->Text.ToIntDef(0);
	ThisParent->Education = EducationBoxSpec->ItemID;
	ThisParent->BadHabit = BadHabitBoxSpec->ItemID;
	ThisParent->BadStrain = BadStrainBoxSpec->ItemID;
	ThisParent->Work = WorkEditSpec->Text;

	ThisParent->Save(DM->ParentGetMaxQuery, DM->ParentInsertQuery, DM->ParentUpdateQuery, NULL);
    Close();
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TParentsInfoForm::CancelButtonClick(TObject *Sender)
{
    Close();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TParentsInfoForm::BoxSpecAfterSetItemID(
      TObject *Sender)
{
	ComboBoxSpecAfterSetItemID(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentsInfoForm::BoxSpecSelect(TObject *Sender)
{
	ComboBoxSpecSelect(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TParentsInfoForm::ListBox1DblClick(TObject *Sender)
{
	if (ListBox1->Items->Count == 0)
		return;
	
	ChildrenInfoForm->Children = (TChildren*)ListBox1->Items->Objects[ListBox1->ItemIndex];
	if (ChildrenInfoForm->Visible) 
		ChildrenInfoForm->GetRecord();
	else
		ChildrenInfoForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TParentsInfoForm::ChangeFont(TFont *f)
{
	int i;
	TControl* c;

	Font->Assign(f);
	for (i = 0; i < ParentsInfoForm->ControlCount; i++) {
		c = ParentsInfoForm->Controls[i];
		ControlAutoSizeLevelDown(c);
	}
}
