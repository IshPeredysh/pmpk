//---------------------------------------------------------------------------


#pragma hdrstop

#include "TTreeBaseList.h"


#pragma package(smart_init)
//---------------------------------------------------------------------------

int __fastcall _SortByDescrAndIsFolder(void* Item1, void* Item2)
{
	int Compare;
	TTreeBase *i1 = (TTreeBase*)Item1;
	TTreeBase *i2 = (TTreeBase*)Item2;

	if (i1->IsFolder != i2->IsFolder) {
		if (i1->IsFolder < i2->IsFolder)
			Compare = -1;
		else
			Compare = 1;
	}
	else
		Compare = i1->Descr.AnsiCompare(i2->Descr);

	return Compare;
}

int TTreeBaseList::Add(void* NewItem)
{
	TTreeBase *Item1;
	TTreeBase *Item2 = (TTreeBase*)NewItem;
	int i = 0;

	if (FList->Count > 0)	{
		do	{
			Item1 = (TTreeBase*)FList->Items[i];
			i++;
		}
		while (_SortByDescrAndIsFolder(Item1, Item2) != 1 && i < FList->Count);
	}
	else
    	i = 1;

	FList->Insert(i - 1, NewItem);
	return i;
}

int TTreeBaseList::NumberChildByID(String ParentID, String ID)
{
	TTreeBase* Item;
	int i = 0;

	Item = GetFirstItemByParentID(ParentID);
	while (Item->ID != ID && Item != NULL) {
		i++;
		Item = GetNextItemByParentID(ParentID);
	}
	if (Item == NULL)
		i = -1;

	return i;
}

int ConditionForSubTreeList(void* Item)
{
	String str;

	if (!ConditionForSubList(Item))
		return 0;
	if (((TTreeBase*)Item)->IsFolder != 2)
		return 0;
	return 1;
}


TTreeBaseList::TTreeBaseList():TBaseList()
{
	CurrentID = 0;
	FIsTree = 1;
	FAnchorID = 0;
	FConditionForSubList = ConditionForSubTreeList;
}

TTreeBase* TTreeBaseList::GetFirstItemByParentID(String ID)
{
	int i;
	TTreeBase* TempItem;

	CurrentID = 0;
	for (i = 0; i < FList->Count; i++) {
		TempItem = (TTreeBase*)FList->Items[i];
		if (TempItem->ParentID == ID)	{
			CurrentID = i + 1;
			return TempItem;
		}
	}
	CurrentID = i;
	return NULL;
}

TTreeBase* TTreeBaseList::GetNextItemByParentID(String ID)
{
	int i;
	TTreeBase* TempItem;

	for (i = CurrentID; i < FList->Count; i++) {
		TempItem = (TTreeBase*)FList->Items[i];
		if (TempItem->ParentID == ID)	{
			CurrentID = i + 1;
			return TempItem;
		}
	}
	CurrentID = i;
	return NULL;
}

int TTreeBaseList::GetChildCount(String ParentID)
{

	int i, cnt = 0;
	TTreeBase *item;

	for (i = 0; i < FList->Count; i++) {
		item = (TTreeBase*)FList->Items[i];
		if (item->ParentID == ParentID) {
			cnt++;
		}
	}
	return cnt;
}


void* TTreeBaseList::GetChildItem(String ParentID, int Index)
{
	int i, cnt = 0;
	TTreeBase *item;

	for (i = 0; i < FList->Count; i++) {
		item = (TTreeBase*)FList->Items[i];
		if (item->ParentID == ParentID) {
			if (Index == cnt) {
				return item;
			}
			else
				cnt++;
		}
	}
	return NULL;
}

int __fastcall _SortByIsFolder(void* Item1, void* Item2)
{
	int Compare;
	TTreeBase *i1 = (TTreeBase*)Item1;
	TTreeBase *i2 = (TTreeBase*)Item2;

		if (i1->IsFolder == i2->IsFolder)
			Compare = 0;
		else
			if (i1->IsFolder < i2->IsFolder)
				Compare = -1;
			else
				Compare = 1;

	return Compare;
}

void TTreeBaseList::SortByDescrAndIsFolder()
{
	FList->Sort(_SortByDescrAndIsFolder);
}

void TTreeBaseList::SortByIsFolder()
{
	FList->Sort(_SortByIsFolder);
}

TTreeBaseList::TTreeBaseList(String ParentID, TTreeBaseList *List)
{
	int i;
	TTreeBase *item;
	void *temp;

	i = 0;
	while (i < List->Count) {
		item = (TTreeBase*)List->FList->Items[i];
		if (item->ParentID == ParentID) {
			FList->Add(item);
			List->FList->Delete(i);
		}
		else
			i++;
	}
}

int TTreeBaseList::DeleteItem(TTreeBase* Item)
{
	int i;

	for (i = 0; i < FList->Count; i++) {
		if (((TTreeBase*)(FList->Items[i]))->ParentID == Item->ID) {
			return 0;
		}
	}

	FList->Remove(Item);
	return 1;
}

/*void TTreeBaseList::SubListBySubString(TBaseList* List, String ss, int Folder, int cnt)
{
	int i, p;
	TTreeBase* Item;
	String s1, s2;

	List->Clear();

	for (i = 0; (i < FList->Count) && (MaxCount == 0 || cnt < MaxCount); i++) {
		Item = (TBase*)FList->Items[i];
		if (Item != NULL && Item->IsFolder == Folder) {
			s1 = Item->Descr.UpperCase();
			p = s1.Pos(ss.UpperCase());
			if (p != 0)	{
				List->Add(Item);
				cnt++;
			}
		}
	}
	return cnt;
}   */

String TTreeBaseList::GetFullPath(int Index, TTreeBaseList* Tree)
{
	String s;
	TStringList *list = new TStringList;
	TTreeBase *Item;
	int i;

	Item = (TTreeBase*)FList->Items[Index];

	if (Item == NULL)	{
    	delete list;
		return "";
	}

	list->Add(Item->Descr);

	while (Item->ParentID != 0) 	{
		Item = (TTreeBase*)(Tree->ItemByID(Item->ParentID));
		if (Item == NULL)
			break;
		list->Add(Item->Descr);
	}

	for (i = list->Count - 1; i >= 0; i--) {
		s += list->Strings[i] + "->";
	}

	s.Delete(s.Length() - 1, 2);
	delete list;

	return s;
}


String TTreeBaseList::GetPath(int Index, TTreeBaseList* Tree)
{
	String s;
	TStringList *list = new TStringList;
	TTreeBase *Item;
	int i;

	Item = (TTreeBase*)FList->Items[Index];

	if (Item == NULL)	{
    	delete list;
		return "";
	}

//	list->Add(Item->Descr);

	while (Item->ParentID != 0) 	{
		Item = (TTreeBase*)(Tree->ItemByID(Item->ParentID));
		if (Item == NULL)
			break;
		list->Add(Item->Descr);
	}

	for (i = list->Count - 1; i >= 0; i--) {
		s += list->Strings[i] + "->";
	}

	s.Delete(s.Length() - 1, 2);
	delete list;

	return s;
}

void TTreeBaseList::SetAnchorID(int Value)
{
	int i;
	TTreeBase* Item;

	if (ItemByID(Value) == NULL)	{
		FAnchorID = 0;
		return;
	}

	FAnchorID = Value;
}

void TTreeBaseList::AddItemsByRoot(TTreeBaseList* SourceList, int RootID)
{
	int i;
	TTreeBase* Item;

	for (i = 0; i < SourceList->Count; i++) {
		Item = (TTreeBase*)SourceList->Items[i];
		if (Item->ParentID == RootID) {
			Add(Item);
            AddItemsByRoot(SourceList, Item->ID);
		}
	}
}


int TTreeBaseList::ExistParent(void* Item, void* parent)
{
	int ID, ParentID;
	TTreeBase* temp;

	temp = (TTreeBase*)Item;
	if (temp == NULL || parent == NULL)
		return 0;

	ID = temp->ParentID;
	ParentID = ((TTreeBase*)parent)->ID;
	if (ParentID == ID)
		return 1;

	while (ID != 0)	{
		if (ID == ParentID)
			return 1;
		temp = (TTreeBase*)ItemByID(ID);
		if (temp == NULL)
			break;
		ID = temp->ParentID;
	}
	return 0;
}
