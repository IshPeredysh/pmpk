//---------------------------------------------------------------------------


#pragma hdrstop

#include "TListList.h"
#include "TBaseEmpty.h"
#include "TChildren.h"
#include "TOrganization.h"
#include "TParent.h"
#include "TTreeBaseEmpty.h"

#include "TChildrenList.h"
#include "TTreeBaseEmptyList.h"
#include "TOrganizationList.h"
#include "TParentList.h"
#include "TBaseEmptyList.h"
#include "TAttrAppointList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


extern TChildrenList* Childrens;
extern TTreeBaseEmptyList *AreaList;
extern TOrganizationList* Organizations;
extern TParentList* Parents;
extern TTreeBaseEmptyList *OtherObjectList;
extern TTreeBaseEmptyList *DiagnosisList;
extern TTreeBaseEmptyList *GroupDataList;
extern TBaseEmptyList *LangList;
extern TBaseEmptyList *SchoolTypeList;
extern TBaseEmptyList *GroupTypeList;
extern TBaseEmptyList *KGartenTypeList;
extern TBaseEmptyList *AppointmentList;
extern TAttrAppointList *AttrAppointList;
extern TTreeBaseEmptyList *RecommendList;


TListList *ListList;

int TListList::CheckUnique(String ListID)
{
	int i;
	TBaseList *Item;

	for (i = 0; i < FList->Count; i++) {
		Item = (TBaseList*)FList->Items[i];
		if (Item->ListID == ListID)
			return 0;
	}
	return 1;
}

TBaseList* TListList::GetByListID(int ListID)
{
	int i;
	TBaseList *Item;

	for (i = 0; i < FList->Count; i++) {
		Item = (TBaseList*)FList->Items[i];
		if (Item->ListID == ListID)
			return Item;
	}
	return NULL;
}

int TListList::GetListID(TBaseList* List)
{
	TBaseList* Item;
	int i;

	for (i = 0; i < FList->Count; i++) {
		if (List == (Item = (TBaseList*)FList->Items[i])) {
			return Item->ListID;
		}
	}
	throw "ListList::GetListID error!";
}

void TListList::AddList(void *Item)
{

	if (CheckUnique(((TBaseList*)Item)->ListID))
		FList->Add(Item);
	else
		throw "Error TListList::AddList(void *Item)";
}

void TListList::AddList(void *Item, int ListID)
{
	((TBaseList*)Item)->ListID = ListID;
	AddList(Item);
}

TListList::TListList()
{
	FList = new TList();
}

TListList::~TListList()
{
	delete FList;
}

int __fastcall TListList::SaveNewItemOfList(int ListID, String Descr, int ParentID)
{
	TChildren *Child;
	TTreeBaseEmpty *Area, *Diag, *GData;
	TOrganization *Org;
	TParent *ParentItem;
	TBaseEmpty *Lang, *SchoolType, *GroupType, *KGartenType;
//	TAttrAppointList *AttrAppoint;

	switch (ListID) {
		case LL_AREA:
			{
				Area = new TTreeBaseEmpty(2, ParentID, 0);
				Area->Descr = Descr;
				Area->Save(AreaList->GetMaxQuery, AreaList->InsertQuery, AreaList->UpdateQuery, AreaList->DeleteQuery);
				AreaList->Add(Area);
				return Area->ID;
			}
		case LL_ORGANIZATIONS:
			{
				Org = new TOrganization(2, ParentID, 0);
				Org->Descr = Descr;
				Org->Save(Organizations->GetMaxQuery, Organizations->InsertQuery, Organizations->UpdateQuery, Organizations->DeleteQuery);
				Organizations->Add(Org);
				return Org->ID;
			}
		case LL_GROUPDATA:
        	{
				break;
			}
		case LL_OTHEROBJECT:
        	{
				break;
			}
		case LL_CHILDRENS:
        	{
				break;
			}
		case LL_PARENTS:
        	{
				break;
			}
		case LL_LANG:
			{
				Lang = new TBaseEmpty(0);
				Lang->Descr = Descr;
				Lang->Save(LangList->GetMaxQuery, LangList->InsertQuery, LangList->UpdateQuery, LangList->DeleteQuery);
				LangList->Add(Lang);
				return Lang->ID;
			}
		case LL_SCHOOLTYPE:
        	{
				break;
			}
		case LL_GROUPTYPE:
        	{
				break;
			}
		case LL_KGARTENTYPE:
        	{
				break;
			}
		case LL_DIAGNOSIS:
        	{
				break;
			}
		case LL_RECOMMEND:
        	{
				break;
			}
	default:
		return 0;
	}

	return 1;
}
