//---------------------------------------------------------------------------


#pragma hdrstop

#include "TChildrenList.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

TChildrenList* Childrens;


void TChildrenList::AddFromDB(TADOQuery *q)
{
	TChildren* NewItem = new TChildren(q);
	FList->Add(NewItem);
}

TChildren* TChildrenList::ChildrenByFIO(String FIO)
{
	int i;

	for (i = 0; i < FList->Count; i++) {
		if ( Children[i]->Descr == FIO )
			return Children[i];
	}
	return NULL;
}
