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
	return (TAttrAppoint*)this->ItemByID(Value);
}

TAttrAppoint* TAttrAppointList::ItemByDescr(String Value)
{
	return (TAttrAppoint*)((TBaseList*)this)->ItemByDescr(Value);
}

#pragma package(smart_init)
