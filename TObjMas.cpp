//---------------------------------------------------------------------------


#pragma hdrstop

#include "TObjMas.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//------------TObjMas------------------

TObjMas::TObjMas(int Col_Count, int Row_Count)
{
	int i;

	FColCount = Col_Count;
	FRowCount = Row_Count;

	FObjType = new int*[Col_Count];
	for (i = 0; i < Col_Count; i++) {
		FObjType[i] = new int[Row_Count];
	}
}

TObjMas::~TObjMas()
{
	int i;

	for (i = 0; i < ColCount; i++) {
		delete []FObjType;
	}
	delete []FObjType;
}


int TObjMas::GetObjType(int Col, int Row)
{
	return FObjType[Col][Row];
}


int* TObjMas::GetPObjType(int Col, int Row)
{
	return &(FObjType[Col][Row]);
}

//-----------------TCellObjList-----------------

TCellObjList::TCellObjList(int type_list, void* list)
{
	TypeList = type_list;
	List = list;

	/*switch (type_list) {
	case tlChild:

		break;

	default:
		;
	}
	if (type_list) {

	}  */
}

TCellObjList::~TCellObjList()
{
	switch (TypeList) {
	case tlChild:
        delete (TDrawChildList*)List;
		break;
		/*delete (TChildrenList*)List;
		break;*/

	default:
		;
	}
}

