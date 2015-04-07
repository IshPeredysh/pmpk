//---------------------------------------------------------------------------


#pragma hdrstop

#include "TTreeBase.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

/*void TTreeBase::SetBaseUpdateParamDB(TADOQuery *q)
{
	TBase::SetBaseUpdateParamDB(q);
	q->Parameters->ParamByName("ParentID")->Value = FParentID;
	q->Parameters->ParamByName("IsFolder")->Value = FIsFolder;
}   */



int TTreeBase::SetThisUpdateParams(TADOQuery *q)
{
	q->Parameters->ParamByName("ParentID")->Value = FParentID;
	q->Parameters->ParamByName("IsFolder")->Value = FIsFolder;
	return 1;
}

TTreeBase::TTreeBase(int VIsFolder, int ParentID, int MaxID):TBase(MaxID)
{
	this->FParentID = ParentID;
	this->FIsFolder = VIsFolder;
//	this->FIsTree = 1;
}

TTreeBase::TTreeBase(TADOQuery *q):TBase(q)
{
	this->FParentID = q->FieldByName("ParentID")->AsInteger;
	this->FIsFolder = q->FieldByName("IsFolder")->AsInteger;
//	this->FIsTree = 1;
}

TTreeBase::TTreeBase(TTreeBase *Template):TBase(Template)
{
	this->FParentID = Template->FParentID;
	this->FIsFolder = Template->FIsFolder;
//	this->FIsTree = 1;
}

int TTreeBase::GetChildCountFromDB(TADOQuery *q)
{
	int cnt;

	q->Parameters->ParamByName("ParentID")->Value = ID;
	q->Open();
	cnt = q->Fields->Fields[0]->AsInteger;
	q->Close();

	return cnt;
}


void TTreeBase::SetParentID(int Value)
{
	if (FParentID != Value)	{
		FParentID = Value;
		FModified = true;
	}
}


