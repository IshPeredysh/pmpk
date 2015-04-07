//---------------------------------------------------------------------------

#ifndef TChildrenListH
#define TChildrenListH
#include "TChildren.h"
#include "TBaseList.h"
//---------------------------------------------------------------------------

class TChildrenList: public TBaseList
{
	private:
		TChildren* GetItem(int i) {return (TChildren*)FList->Items[i];};
		TChildren* GetVisibleItem(int i) {return (TChildren*)VisibleItem[i];};
	public:
		void AddFromDB(TADOQuery *q);
		TChildren* ChildrenByFIO(String FIO);
		__property TChildren* Children[int i] = {read=GetItem};
		__property TChildren* VisibleChildren[int i] = {read=GetVisibleItem};
};
#endif
