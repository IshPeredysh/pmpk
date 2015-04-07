//---------------------------------------------------------------------------

#ifndef TOrganizationH
#define TOrganizationH
#include "TTreeBase.h"
//---------------------------------------------------------------------------

class TOrganization: public TTreeBase
{
	private:
		int FOrgTypeID;
		String GetOrgType();
		void SetOrgTypeID(int Value);
		int SetThisUpdateParams(TADOQuery *q);
	public:
		TOrganization(int VIsFolder, int ParentID, int MaxID);
		TOrganization(TADOQuery *q);
		TOrganization(TOrganization *Template);
		__property int OrgTypeID = {read=FOrgTypeID, write=SetOrgTypeID};
		__property String OrgType = {read=GetOrgType};

};
#endif
