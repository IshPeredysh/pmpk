//---------------------------------------------------------------------------

#ifndef TTreeBaseH
#define TTreeBaseH
#include "TBase.h"
//---------------------------------------------------------------------------

class TTreeBase: public TBase
{
	protected:
		int FParentID;
		int FIsFolder;
		int GetIsFolder();
		//void SetBaseUpdateParamDB(TADOQuery *q);
		/*virtual int SetThisUpdateParams(TADOQuery *q); = 0*/
		int SetThisUpdateParams(TADOQuery *q);
		void SetParentID(int Value);
	public:
		int GetChildCountFromDB(TADOQuery *q);
		void FillFromDB(TADOQuery *q);
		__property int ParentID = {read=FParentID, write=SetParentID};
		TTreeBase(int VIsFolder, int ParentID, int MaxID);
		TTreeBase(TADOQuery *q);
		TTreeBase(TTreeBase *Template);
		__property int IsFolder = {read=FIsFolder};
};

#endif
