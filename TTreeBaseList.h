//---------------------------------------------------------------------------

#ifndef TTreeBaseListH
#define TTreeBaseListH
#include "TBaseList.h"
#include "TTreeBase.h"
//---------------------------------------------------------------------------



class TTreeBaseList: public TBaseList
{
	private:
		int CurrentID;
		int FAnchorID;
	public:
		int Add(void* NewItem);
		TTreeBaseList* Childs;
		int DeleteItem(TTreeBase* Item);
		void *GetChildItem(String ParentID, int Index);
		int GetChildCount(String ParentID);
		String GetFullPath(int Index, TTreeBaseList* Tree);
		String GetPath(int Index, TTreeBaseList* Tree);
		int NumberChildByID(String ParentID, String ID);
		void SortByDescrAndIsFolder();
		void SortByIsFolder();
		void SetAnchorID(int Value);
		TTreeBase* GetFirstItemByParentID(String ID);
		TTreeBase* GetNextItemByParentID(String ID);
		void AddItemsByRoot(TTreeBaseList* SourceList, int RootID);
		TTreeBaseList();
		int ExistParent(void* Item, void* parent);
		TTreeBaseList(String ParentID, TTreeBaseList *List);
		__property int AnchorID = {read=FAnchorID, write=SetAnchorID};
		/*void SubListBySubString(TBaseList* List, String ss, int Folder, int cnt);
		int SubListByFirstString(TBaseList* List, String fs, int MaxCount);
		int SubListBySubStringXorFirst(TBaseList* List, String ss, int MaxCount);*/
};

#endif
