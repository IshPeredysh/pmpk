//---------------------------------------------------------------------------


#pragma hdrstop

#include "TTreeBaseEmpty.h"

//---------------------------------------------------------------------------
int TTreeBaseEmpty::SetThisUpdateParams(TADOQuery *q)
{
	TTreeBase::SetThisUpdateParams(q);
	return 1;
};

#pragma package(smart_init)
