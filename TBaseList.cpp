//---------------------------------------------------------------------------


#pragma hdrstop

#include "TBaseList.h"
#include "DMUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



int __fastcall _SortByDescr(void* Item1, void* Item2)
{
	TBase *i1 = (TBase*)Item1;
	TBase *i2 = (TBase*)Item2;

	return AnsiCompareStr(i1->Descr, i2->Descr);
}

void TBaseList::ReloadList()
{
	if (!SelectQuery)
		return;
	RemoveItems();
	SelectQuery->Open();
	FillFromDB(SelectQuery);
	SelectQuery->Close();
}

int TBaseList::Add(void* NewItem)
{
	TBase *Item1;
	TBase *Item2 = (TBase*)NewItem;
	int i = 0;

	if (OnSortByDescr) {
		if (FList->Count > 0)	{
			do	{
				Item1 = (TBase*)FList->Items[i];
				i++;
			}
//			while (_SortByDescr(Item1, Item2) != 1 && i < FList->Count);
			while (OnSortByDescr(Item1, Item2) != 1 && i < FList->Count);
			FList->Insert(i - 1, NewItem);
		}
		else
			FList->Add(NewItem);
	}
	else	{
		FList->Add(NewItem);
    }

	return i;
}

int TBaseList::GetMaxID(TADOQuery *MaxQuery)
{
	int max;

	MaxQuery->Open();
	if (MaxQuery->RecordCount != 1)
		return 0;

	max = MaxQuery->Fields->Fields[0]->AsInteger;
	MaxQuery->Close();

	return max;
}

void** TBaseList::GetPointer(int Index)
{
	return &(FList->List[Index]);
}

int TBaseList::GetVisibleCount()
{
	int i;
	int VisibleCnt = 0;

	for (i = 0; i < FList->Count; i++) {
		if (((TBase*)FList->Items[i])->IsMark != "*") {
			VisibleCnt++;
		}
	}
	return VisibleCnt;
}

void* TBaseList::GetVisibleItem(int Index)
{
	int i;
	int VisibleCnt = 0;

	for (i = 0; i < FList->Count; i++) {
		if (((TBase*)FList->Items[i])->IsMark != "*") {
			if (Index == VisibleCnt)
				return FList->Items[i];
			VisibleCnt++;
		}
	}
	return NULL;
}

void* TBaseList::ItemByID(int ID)
{
	int i;

	if (ID == 0)
		return NULL;

	for (i = 0; i < FList->Count; i++) {
		if ( ((TBase*)(FList->Items[i]))->ID == ID ) {
			return FList->Items[i];
		}
	}

	ReloadList();

	for (i = 0; i < FList->Count; i++) {
		if ( ((TBase*)(FList->Items[i]))->ID == ID ) {
			return FList->Items[i];
		}
	}

	return NULL;
}

void* TBaseList::ItemByDescr(String ItemDescr)
{
	int i;

	for (i = 0; i < FList->Count; i++) {
		if ( ((TBase*)(FList->Items[i]))->Descr == ItemDescr ) {
			return FList->Items[i];
		}
	}
	return NULL;
}


void TBaseList::FillFromDB(TADOQuery *q)
{

	q->First();
	while (!q->Eof)	{
		AddFromDB(q);
		q->Next();
	}
}

void TBaseList::SetClone(int Index)
{
	/*void *tmp;

	tmp = FList->Items[Index];
	SetItem(Index, ((TTreeBase*)tmp->)Clone);
	tmp->Clone->PParent = NULL;
	delete tmp; */
}

void TBaseList::SetItem(int Index, void* Item)
{
	delete FList->Items[Index];
	FList->List[Index] = Item;
}

void TBaseList::SortByDescr()
{
	FList->Sort(_SortByDescr);
}

int ConditionForSubList(void* Item)
{
	if (Item == NULL)
		return 0;
	return 1;
}


TBaseList::TBaseList():TQueryGroup()
{
	Root = NULL;
	FList = new TList;
	FIsTree = 0;
	OnSortByDescr = &_SortByDescr;
	FConditionForSubList = ConditionForSubList;

}

TBaseList::~TBaseList()
{
	RemoveItems();
}

void TBaseList::Delete(int Index)
{
	FList->Delete(Index);
}

int TBaseList::DeleteFromDB(void* Item, TADOQuery *DelQuery)
{
	int r;

	DM->ADOConnection1->BeginTrans();
	r = ((TBase*)Item)->RemoveFromDB(DelQuery);

	if (r == 1)	{
		FList->Remove(Item);
		DM->ADOConnection1->CommitTrans();
		return r;
	}
	else	{
		DM->ADOConnection1->RollbackTrans();
	}
	return r;
}

int TBaseList::IndexByID(int ID)
{
	int i;
	TBase* Item;

	for (i = 0; i < FList->Count; i++) {
		Item = (TBase*)FList->Items[i];
		if (Item->ID == ID) {
			return i;
		}
	}
	return -1;
}


int TBaseList::SubListBySubString(TBaseList* List, String ss, int MaxCount)
{
	int i, p, cnt = 0;
	TBase* Item;
	String s1, s2;

	List->Clear();

	if (FConditionForSubList != NULL)
	for (i = 0; (i < FList->Count) && (MaxCount == 0 || cnt < MaxCount); i++) {
		Item = (TBase*)FList->Items[i];
		if (FConditionForSubList(Item)) {
			s1 = Item->Descr.UpperCase();
			p = s1.Pos(ss.UpperCase());
			if (p != 0)	{
				List->Add(Item);
				cnt++;
			}
		}
	}
	return cnt;
}

int TBaseList::SubListByFirstString(TBaseList* List, String fs, int MaxCount)
{
	int i, p, cnt = 0;
	TBase* Item;
	String s1, check;

	List->Clear();

	if (FConditionForSubList != NULL)
	for (i = 0; (i < FList->Count) && (MaxCount == 0 || cnt < MaxCount); i++) {
		Item = (TBase*)FList->Items[i];
		if (Item->Descr == "Новосибирск") {
			check = "";
		}
		if (FConditionForSubList(Item)) {
			s1 = Item->Descr.UpperCase();
			if (s1.SubString(1, fs.Length()) == fs.UpperCase()) {
				List->Add(Item);
				cnt++;
			}
		}
	}
	return cnt;
}

int TBaseList::SubListBySubStringXorFirst(TBaseList* List, String ss, int MaxCount)
{
	int i, p, cnt = 0;
	TBase* Item;
	String s1, s2;

	List->Clear();

	if (FConditionForSubList != NULL)
	for (i = 0; (i < FList->Count) && (MaxCount == 0 || cnt < MaxCount); i++) {
		Item = (TBase*)FList->Items[i];
		if (FConditionForSubList(Item))	{
			s1 = Item->Descr.UpperCase();
			p = s1.Pos(ss.UpperCase());
			if (s1.SubString(1, ss.Length()) == ss.UpperCase())
            	continue;
			if (p != 0)	{
				List->Add(Item);
				cnt++;
			}
		}
	}
	return cnt;
}



void TBaseList::Clear()
{
	FList->Clear();
}


int TBaseList::DeleteItemFromDB(TBase* Item, TADOQuery *qDel)
{
	TADOQuery* q = DM->CheckFieldExistQuery;
	int r, d;

	q->Parameters->ParamByName("ListID")->Value = ListID;
	q->Parameters->ParamByName("ItemID")->Value = Item->ID;
	q->Open();
	r = q->Fields->Fields[0]->AsInteger;
	q->Close();

	if (r == 0)	{
		q = qDel;
		q->Parameters->ParamByName("ID")->Value = Item->ID;
		if (q->ExecSQL() != 1)
			throw "TBaseList::DeleteItemFromDB. Error!";

		FList->Remove(Item);
	}

	return r;
}

int TBaseList::DeleteComboBoxItemFromDB(TBase* Item, TADOQuery *qDel)
{
	TADOQuery* q = DM->CheckFieldExistQuery;
	int r, d;

	q->Parameters->ParamByName("ListID")->Value = ListID;
	q->Parameters->ParamByName("ItemID")->Value = Item->ID;
	q->Open();
	r = q->Fields->Fields[0]->AsInteger;
	q->Close();

	if (r == 0)	{
		q = qDel;
		q->Parameters->ParamByName("ID")->Value = Item->ID;
		if (q->ExecSQL() != 1)
			throw "TBaseList::DeleteItemFromDB. Error!";

		FList->Remove(Item);
	}

	return r;
}


void* TBaseList::GetItems(int Index)
{
	return FList->Items[Index];
}

void TBaseList::Remove(void* Item)
{
	FList->Remove(Item);
}

void TBaseList::RemoveItems()
{
	int i;

	for (i = 0; i < FList->Count; i++) {
		delete FList->Items[FList->Count - 1];
	}
	Clear();

}
