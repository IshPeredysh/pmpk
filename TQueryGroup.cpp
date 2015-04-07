//---------------------------------------------------------------------------


#pragma hdrstop

#include "TQueryGroup.h"

//---------------------------------------------------------------------------

void __fastcall TQueryGroup::SetQueryGroup(TADOQuery *InsQuery, TADOQuery *UpdQuery,
		TADOQuery *DelQuery, TADOQuery *MaxQuery, TADOQuery *SelQuery)
{
	InsertQuery = InsQuery;
	UpdateQuery = UpdQuery;
	DeleteQuery = DelQuery;
	GetMaxQuery = MaxQuery;
	SelectQuery = SelQuery;
}


TQueryGroup::TQueryGroup()
{
	InsertQuery = NULL;
	UpdateQuery = NULL;
	DeleteQuery = NULL;
	GetMaxQuery = NULL;
	SelectQuery = NULL;
}

#pragma package(smart_init)
