//---------------------------------------------------------------------------


#pragma hdrstop

#include "TTreeBaseEmptyList.h"
#include "DMUnit.h"
#include "TBaseEmptyList.h"
#include "TListList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TTreeBaseEmptyList *AreaList;
TTreeBaseEmptyList *OtherObjectList;
TTreeBaseEmptyList *DiagnosisList;
TTreeBaseEmptyList *GroupDataList;
TTreeBaseEmptyList *RecommendList;
extern TListList *ListList;



TTreeBaseEmptyList::TTreeBaseEmptyList():TTreeBaseList()
{

}

void TTreeBaseEmptyList::AddFromDB(TADOQuery *q)
{
	TTreeBaseEmpty* NewItem = new TTreeBaseEmpty(q);
	FList->Add(NewItem);
}

int TTreeBaseEmptyList::DeleteItem(TTreeBaseEmpty* Item)
{
	delete Item;
	return FList->Remove(Item);
}



TTreeBaseEmpty* TTreeBaseEmptyList::GetFirstItem(String ID)
{
	return (TTreeBaseEmpty*)GetFirstItemByParentID(ID);
}


TTreeBaseEmpty* TTreeBaseEmptyList::GetNextItem(String ID)
{
	return (TTreeBaseEmpty*)GetNextItemByParentID(ID);
}

