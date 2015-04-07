//---------------------------------------------------------------------------


#pragma hdrstop

#include "ExtFunctions.h"
#include "TComboBoxSpec.h"
#include "TTreeBaseEmptyList.h"

//---------------------------------------------------------------------------
extern TTreeBaseEmptyList *OtherObjectList;

#pragma package(smart_init)

void FillStrings(int ID, TTreeBaseList *list, TStrings *Items)
{
	TTreeBase *Item;

	Items->Clear();
	Items->AddObject("", (TObject*) new int(0));

	if ((Item = list->GetFirstItemByParentID(ID)) != NULL) {
		Items->AddObject(Item->Descr, (TObject*) new int(Item->ID));
	}

	while ((Item = list->GetNextItemByParentID(ID)) != NULL)	{
		Items->AddObject(Item->Descr, (TObject*) new int(Item->ID));
	}
}


void FillBox(int ID, TTreeBaseList *list, TComboBox *box)
{
	TTreeBase *Item;

	FillStrings(ID, list, box->Items);
}

void FillBox(int ID, TTreeBaseList *list, TListBox *box)
{
	TTreeBase *Item;

	FillStrings(ID, list, box->Items);
}


void BoxItemByID(int ID, TComboBox* box)
{
	int i;
	int d;

	for (i = 0; i < box->Items->Count; i++) {
		d = *((int*)(box->Items->Objects[i]));
		if (d == ID)	{
			box->ItemIndex = i;
			return;
		}
	}
	box->Text = "";
	box->ItemIndex = -1;
}

void BoxItemByTBase(TBase* Item, TComboBox* box)
{
	int i;
	TBase* temp;

	for (i = 0; i < box->Items->Count; i++) {
		temp = (TBase*)(box->Items->Objects[i]);
		if (temp == Item)	{
			box->ItemIndex = i;
			return;
		}
	}
	box->Text = "";
	box->ItemIndex = -1;
}

void BoxItemByTBaseID(int ID, TComboBox* box)
{
	int i;
	TBase* temp;

	for (i = 0; i < box->Items->Count; i++) {
		temp = (TBase*)(box->Items->Objects[i]);
		if (temp->ID == ID)	{
			box->ItemIndex = i;
			return;
		}
	}
	box->Text = "";
	box->ItemIndex = -1;
}

void BoxItemByID(String ID, TListBox* box)
{
	int i;
	int d;

	for (i = 0; i < box->Items->Count; i++) {
		d = *((int*)(box->Items->Objects[i]));
		if (d == ID)	{
			box->ItemIndex = i;
			return;
		}
	}
	box->ItemIndex = -1;
}


