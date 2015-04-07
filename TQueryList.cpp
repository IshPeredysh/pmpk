//---------------------------------------------------------------------------


#pragma hdrstop

#include "TQueryList.h"


//---------------------------------------------------------------------------

TQueryList::TQueryList(TADOQuery *qSelect, TADOQuery *qUpdate, TADOQuery *qDelete, TADOQuery *qMaxID)
{
	ArrQuery[qSel] = qSelect;
	ArrQuery[qUpd] = qUpdate;
	ArrQuery[qDel] = qDelete;
	ArrQuery[qMax] = qMaxID;
}

TADOQuery* TQueryList::GetQuery(int i)
{
	return ArrQuery[i];
}


#pragma package(smart_init)
