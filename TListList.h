//---------------------------------------------------------------------------

#ifndef TListListH
#define TListListH
#include "TBaseList.h"
//---------------------------------------------------------------------------

const int LL_AREA = 123;
const int LL_ORGANIZATIONS = 36;
const int LL_GROUPDATA = 62;
const int LL_OTHEROBJECT = 1;
const int LL_CHILDRENS = 18;
const int LL_PARENTS = 84;
const int LL_LANG = 76;
const int LL_SCHOOLTYPE = 135;
const int LL_GROUPTYPE = 152;
const int LL_KGARTENTYPE = 154;
const int LL_DIAGNOSIS = 39;
const int LL_RECOMMEND = 121;


class TListList
{
	private:
		TList *FList;
		int CheckUnique(String ListID);
		int GetCount() { return FList->Count; };
		void* GetItem(int Index) { return FList->Items[Index]; };
	public:
		TBaseList* GetByListID(int ListID);
		int GetListID(TBaseList* List);
		void AddList(void *Item);
		void AddList(void *Item, int ItemID);
		int __fastcall SaveNewItemOfList(int ListID, String Descr, int ParentID);
		TListList();
		~TListList();
		__property int Count = {read=GetCount};
		__property void* Items[int Index] = {read=GetItem};
};
#endif
