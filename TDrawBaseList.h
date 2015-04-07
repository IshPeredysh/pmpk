//---------------------------------------------------------------------------

#ifndef TDrawBaseListH
#define TDrawBaseListH
#include "TBaseList.h"
#include "TChildrenList.h"
//---------------------------------------------------------------------------

class TDrawBaseList: public TBaseList
{
	public:
    	void AddFromDB(TADOQuery* q) {throw "error!";};
		~TDrawBaseList();
		
};


class TDrawChildList: public TChildrenList
{
	public:
    	void AddFromDB(TADOQuery* q) {throw "error!";};
		~TDrawChildList();
		
};
#endif
