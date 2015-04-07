//---------------------------------------------------------------------------


#pragma hdrstop

#include "TBaseEmptyList.h"
TBaseEmptyList *LangList;
TBaseEmptyList *AppointmentList;
TBaseEmptyList *SchoolTypeList;
TBaseEmptyList *GroupTypeList;
TBaseEmptyList *KGartenTypeList;


//---------------------------------------------------------------------------


#pragma package(smart_init)




void TBaseEmptyList::AddFromDB(TADOQuery *q)
{
	TBaseEmpty* NewItem = new TBaseEmpty(q);
	FList->Add(NewItem);
}




