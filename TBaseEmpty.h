//---------------------------------------------------------------------------

#ifndef TBaseEmptyH
#define TBaseEmptyH
#include "TBase.h"
//---------------------------------------------------------------------------
class TBaseEmpty: public TBase
{
	protected:
		virtual int SetThisUpdateParams(TADOQuery *q) {return 1;};
	public:
		TBaseEmpty(TADOQuery *q):TBase(q) {};
		TBaseEmpty(int MaxID):TBase(MaxID){};
};
#endif
