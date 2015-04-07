//---------------------------------------------------------------------------


#pragma hdrstop

#include "SpecEvents.h"
#include "TBase.h"
#include "ExtFunctions.h"
#include "TTreeBaseEmptyList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

extern TTreeBaseEmptyList *OtherObjectList;


void __fastcall ComboBoxSpecSelect(TObject *Sender)
{
	TComboBoxSpec *sBox = (TComboBoxSpec*)Sender;
	TNotifyEvent event;

	event = sBox->OnAfterSetItemID;
	sBox->OnAfterSetItemID = NULL;

	sBox->ItemID = *((int*)sBox->Items->Objects[sBox->ItemIndex]);

	sBox->OnAfterSetItemID = event;
}

void __fastcall ComboBoxSpecAfterSetItemID(TObject *Sender)
{
	TComboBoxSpec *sBox = (TComboBoxSpec*)Sender;
	TBase *item;

	BoxItemByID(sBox->ItemID, (TComboBox*)sBox);
	if (sBox->ItemIndex == -1) {
		item = (TBase*)OtherObjectList->ItemByID(sBox->ItemID);
		if (item != NULL)
			sBox->Text = item->Descr;
	}
}
