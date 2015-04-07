//---------------------------------------------------------------------------

#ifndef TBaseEmptyListH
#define TBaseEmptyListH
#include "TBaseList.h"
#include "TBaseEmpty.h"
//---------------------------------------------------------------------------

class TBaseEmptyList: public TBaseList
{
	private:
		TBaseEmpty* GetItem(int i) {return (TBaseEmpty*)FList->Items[i];};
	public:
		void AddFromDB(TADOQuery *q);
		__property TBaseEmpty* Items[int i] = {read=GetItem};
};
#endif
