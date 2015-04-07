//---------------------------------------------------------------------------

#ifndef TQueryListH
#define TQueryListH
#include "DMUnit.h"
#include <ADODB.hpp>
//---------------------------------------------------------------------------

enum TQueryType
{
	qSel,
	qUpd,
	qDel,
	qMax
};


class TQueryList
{
	private:
		TADOQuery* ArrQuery[4];
		TADOQuery* GetQuery(int i);
	public:
		TQueryList(TADOQuery *qSelect, TADOQuery *qUpdate, TADOQuery *qDelete, TADOQuery *qMaxID);
		__property TADOQuery* Item[int i] = {read=GetQuery};
};
#endif
