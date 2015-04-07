//---------------------------------------------------------------------------

#ifndef TObjMasH
#define TObjMasH
#include "TDrawBaseList.h"
//---------------------------------------------------------------------------

class TObjMas
{
	private:
		int **FObjType;
		int FColCount;
		int FRowCount;
	public:
		TObjMas(int Col_Count, int Row_Count);
		~TObjMas();
		int GetObjType(int Col, int Row);
		int* GetPObjType(int Col, int Row);
		__property int ColCount = {read=FColCount};
		__property int RowCount = {read=FRowCount};

};

#define coText 1
#define coList 2

#define tlChild 1
#define tlProt 2

class TCellObjList
{
	public:
		int TypeList;
		void* List;
		TCellObjList(int type_list, void* list);
		~TCellObjList();
};

/*class TCellObjType
{
	public:
		int ObjType;
		void* Obj;
}; */


#endif
