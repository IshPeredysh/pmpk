//---------------------------------------------------------------------------

#ifndef TBaseListH
#define TBaseListH
#include <Classes.hpp>
#include <ADODB.hpp>
#include "TBase.h"
#include "TQueryGroup.h"


//---------------------------------------------------------------------------
//typedef void* (*funcBuilder)(TADOQuery*);

typedef int (__fastcall *TFuncSort)(void*, void*);
typedef int (*TConditionForSubList)(void*);
typedef void (*TReloadList)(TADOQuery *q);

extern int ConditionForSubList(void* Item);

class TBaseList: public TQueryGroup
{
	private:
		int GetVisibleCount();
		int GetCount() {return FList->Count;};
		void* GetItems(int Index);
	protected:
		TList *FList;
		int FIsTree;
	public:
		void *Root;
		int ListID;
		TFuncSort OnSortByDescr;
		TConditionForSubList FConditionForSubList;
//		TReloadList ReloadList;
		void ReloadList();
		int Add(void* NewItem);
		void Delete(int Index);
		int DeleteFromDB(void* Item, TADOQuery *DelQuery);
		int DeleteItemFromDB(TBase* Item, TADOQuery *qDel);
		int DeleteComboBoxItemFromDB(TBase* Item, TADOQuery *qDel);
		int GetMaxID(TADOQuery *MaxQuery);
		void** GetPointer(int Index);
		void* GetVisibleItem(int Index);
		void SetItem(int Index, void* Item);
		void SortByDescr();
		void FillFromDB(TADOQuery *q);
		virtual void AddFromDB(TADOQuery *q) = 0;
		int IndexByID(int ID);
		void* ItemByID(int ID);
		void* ItemByDescr(String ItemDescr);
		int SubListBySubString(TBaseList* List, String ss, int MaxCount);
		int SubListByFirstString(TBaseList* List, String fs, int MaxCount);
		int SubListBySubStringXorFirst(TBaseList* List, String ss, int MaxCount);
		void SetClone(int Index);
		void Clear();
		void Remove(void* Item);
		void RemoveItems();
		TBaseList();
		~TBaseList();
		__property int Count = {read=GetCount};
		__property void* VisibleItem[int Index] = {read=GetVisibleItem};
		__property int VisibleCount = {read=GetVisibleCount};
		__property int IsTree = {read=FIsTree};
		__property void* Items[int Index] = {read=GetItems};

};

#endif
