//---------------------------------------------------------------------------


#pragma hdrstop

#include "TOrganizationList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TOrganizationList* Organizations;

void TOrganizationList::AddFromDB(TADOQuery *q)
{
	TOrganization* NewItem = new TOrganization(q);
	FList->Add(NewItem);
}

void TOrganizationList::DeleteOrg(int Index)
{
	delete FList->Items[Index];
	FList->Delete(Index);
}

int TOrganizationList::DeleteOrg(TOrganization* Org)
{
	delete Org;
	return FList->Remove(Org);
}

TOrganization* TOrganizationList::OrganizationByID(int Value)
{
	return (TOrganization*)this->ItemByID(Value);
}

TOrganizationList::~TOrganizationList()
{
	delete FList;
}

TOrganization* TOrganizationList::GetItem(int i)
{
	return (TOrganization*)FList->Items[i];
}
