//---------------------------------------------------------------------------

#ifndef TQueryGroupH
#define TQueryGroupH
#include "DMUnit.h"
//---------------------------------------------------------------------------

class TQueryGroup
{
	public:
		TADOQuery *InsertQuery;
		TADOQuery *UpdateQuery;
		TADOQuery *DeleteQuery;
		TADOQuery *GetMaxQuery;
		TADOQuery *SelectQuery;
		TQueryGroup();
		void __fastcall SetQueryGroup(TADOQuery *InsQuery, TADOQuery *UpdQuery,
				TADOQuery *DelQuery, TADOQuery *MaxQuery, TADOQuery *SelQuery);
};

#endif
