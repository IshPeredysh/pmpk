//---------------------------------------------------------------------------

#ifndef TOrganizationListH
#define TOrganizationListH
#include "TTreeBaseList.h"
#include "TOrganization.h"
//---------------------------------------------------------------------------

class TOrganizationList: public TTreeBaseList
{
	private:
		TOrganization* GetItem(int i);
	public:
		TOrganization* Root;
		void AddFromDB(TADOQuery *q);
		void DeleteOrg(int Index);
		int DeleteOrg(TOrganization* Org);
		TOrganization* OrganizationByID(int Value);
        ~TOrganizationList();
		__property TOrganization* Organization[int i] = {read=GetItem};
};

#endif
