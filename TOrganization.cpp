//---------------------------------------------------------------------------


#pragma hdrstop

#include "TOrganization.h"
#include "TTreeBaseEmptyList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

extern TTreeBaseEmptyList *OtherObjectList;

String TOrganization::GetOrgType()
{
	TTreeBaseEmpty *item;

	item = (TTreeBaseEmpty*)OtherObjectList->ItemByID(this->FOrgTypeID);
	if (item == NULL)
		return "";
	else
		return item->Descr;

}

void TOrganization::SetOrgTypeID(int Value)
{
	this->FOrgTypeID = Value;
	FModified = true;
}

int TOrganization::SetThisUpdateParams(TADOQuery *q)
{
    TTreeBase::SetThisUpdateParams(q);
	q->Parameters->ParamByName("OrgTypeID")->Value = FOrgTypeID;
	return 1;
}

TOrganization::TOrganization(TADOQuery *q):TTreeBase(q)
{
	FOrgTypeID = q->FieldByName("OrgTypeID")->AsInteger;
}

TOrganization::TOrganization(int VIsFolder, int ParentID, int MaxID):TTreeBase(VIsFolder, ParentID, MaxID)
{
	FOrgTypeID = 0;
}

TOrganization::TOrganization(TOrganization *Template):TTreeBase(Template)
{
	FOrgTypeID = Template->FOrgTypeID;
}

