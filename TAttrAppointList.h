//---------------------------------------------------------------------------

#ifndef TAttrAppointListH
#define TAttrAppointListH
#include "TBaseList.h"
#include "TAttrAppoint.h"
//---------------------------------------------------------------------------

class TAttrAppointList: public TBaseList
{
	private:
		TAttrAppoint* GetItem(int i) {return (TAttrAppoint*)FList->Items[i];};
	public:
		void AddFromDB(TADOQuery *q);
		TAttrAppoint* ItemByID(int Value);
        TAttrAppoint* ItemByDescr(String Value);
		__property TAttrAppoint* Items[int i] = {read=GetItem};

};
#endif
