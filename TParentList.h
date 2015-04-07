//---------------------------------------------------------------------------

#ifndef TParentListH
#define TParentListH
#include "TBaseList.h"
#include "TParent.h"
//---------------------------------------------------------------------------

class TParentList: public TBaseList
{
	private:
		TParent* GetItem(int i) {return (TParent*)FList->Items[i];};
	public:
		void AddFromDB(TADOQuery *q);
		TParent* ParentByID(int Value);
		__property TParent* Parent[int i] = {read=GetItem};
};
#endif
