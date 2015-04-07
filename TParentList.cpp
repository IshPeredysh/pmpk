//---------------------------------------------------------------------------


#pragma hdrstop

#include "TParentList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TParentList* Parents;

void TParentList::AddFromDB(TADOQuery *q)
{
	TParent* NewItem = new TParent(q);
	FList->Add(NewItem);
}

TParent* TParentList::ParentByID(int Value)
{
	return (TParent*)this->ItemByID(Value);
}