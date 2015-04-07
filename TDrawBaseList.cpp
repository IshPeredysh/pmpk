//---------------------------------------------------------------------------


#pragma hdrstop

#include "TDrawBaseList.h"
#include "TBase.h"


#pragma package(smart_init)
//---------------------------------------------------------------------------

//-------------------------------TDrawBaseList-------------------------//

TDrawBaseList::~TDrawBaseList()
{
	delete FList;
}


//--------------------------TDrawChildList-----------------------------//

TDrawChildList::~TDrawChildList()
{
	delete FList;
}




