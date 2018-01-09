//---------------------------------------------------------------------------


#pragma hdrstop

#include "TAttrAppointList.h"

TAttrAppointList *AttrAppointList;

//---------------------------------------------------------------------------

void TAttrAppointList::AddFromDB(TADOQuery *q)
{
	TAttrAppoint* NewItem = new TAttrAppoint(q);
	FList->Add(NewItem);
}

TAttrAppoint* TAttrAppointList::ItemByID(int Value)
{
	return (TAttrAppoint*)TBaseList::ItemByID(Value);
}

TAttrAppoint* TAttrAppointList::ItemByDescr(String Value)
{
	TAttrAppoint* p = NULL;

	p = (TAttrAppoint*)TBaseList::ItemByDescr(Value);
	return p;
}

#pragma package(smart_init)
