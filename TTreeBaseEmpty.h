//---------------------------------------------------------------------------

#ifndef TTreeBaseEmptyH
#define TTreeBaseEmptyH
#include "TTreeBase.h"
//---------------------------------------------------------------------------
class TTreeBaseEmpty: public TTreeBase
{
	protected:
		int SetThisUpdateParams(TADOQuery *q);
	public:
		TTreeBaseEmpty(TADOQuery *q):TTreeBase(q) {};
		TTreeBaseEmpty(int VIsFolder, int ParentID, int MaxID)
			:TTreeBase(VIsFolder, ParentID, MaxID){};
};
#endif
