//---------------------------------------------------------------------------

#ifndef TTreeBaseEmptyListH
#define TTreeBaseEmptyListH
#include "TTreeBaseEmpty.h"
#include "TTreeBaseList.h"
//---------------------------------------------------------------------------
class TTreeBaseEmptyList: public TTreeBaseList
{
	private:
		TTreeBaseEmpty* GetItem(int i) {return (TTreeBaseEmpty*)FList->Items[i];};
		TTreeBaseEmpty* GetVisibleItem(int i) {return (TTreeBaseEmpty*)VisibleItem[i];};
	public:
    	TTreeBaseEmptyList();
		TTreeBaseEmpty* Root;
		void AddFromDB(TADOQuery *q);
		int DeleteItem(TTreeBaseEmpty* Item);
		TTreeBaseEmpty* GetFirstItem(String ID);
		TTreeBaseEmpty* GetNextItem(String ID);
		__property TTreeBaseEmpty* Items[int i] = {read=GetItem};
		__property TTreeBaseEmpty* VisibleItems[int i] = {read=GetVisibleItem};

};
#endif
