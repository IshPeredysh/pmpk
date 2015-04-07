//---------------------------------------------------------------------------


#pragma hdrstop

#include "TBase.h"
#include "DigitConvertion.h"
#include "DMUnit.h"
#include <Dialogs.hpp>

//---------------------------------------------------------------------------

#pragma package(smart_init)


Variant IfNull(int Value)
{
	Variant tmp;

	tmp.IsNull();

	if (Value == 0)
		return tmp;
	else
    	return Value;
}

void TBase::SetBaseUpdateParamDB(TADOQuery *q)
{
	q->Parameters->ParamByName("ID")->Value = FID;
//	q->Parameters->ParamByName("Code")->Value = FCode;
	q->Parameters->ParamByName("Descr")->Value = FDescr;
	q->Parameters->ParamByName("IsMark")->Value = FIsMark;
	q->Parameters->ParamByName("VerStamp")->Value = FVerStamp;
}

int TBase::SetUpdateParams(TADOQuery *q)
{
	SetBaseUpdateParamDB(q);
	SetThisUpdateParams(q);
	return 1;
}

void TBase::GetFromDB(TADOQuery *q)
{
	this->FID = q->FieldByName("ID")->AsInteger;
//	this->FCode = q->FieldByName("Code")->AsString;
	this->FDescr = q->FieldByName("Descr")->AsString;
	this->FIsMark = q->FieldByName("IsMark")->AsString;
	this->FVerStamp = q->FieldByName("VerStamp")->AsInteger;
	this->FModified = false;
}

void TBase::SetDescr(String Value)
{
	if (FDescr == Value)
		return;

	FDescr = Value;
	FModified = true;

	/*if (FChangeDescr) {
        FChangeDescr(Value);
	}*/
	//FVerStamp++;
}

TBase::TBase(int MaxID)
{
	int Code;

	this->Clone = NULL;
	this->IsDeleted = false;
	this->PParent = NULL;

	this->FID = MaxID;
//	Code = MaxID;
//	this->FCode = DigitToCharBySize(Code, 5);
	this->FDescr = "";
	this->FIsMark = "";
	this->FVerStamp = 0;
	this->FModified = false;
//	this->FIsTree = 0;

//	InsertDB(InsertQuery);
}

TBase::TBase(TBase *Template)
{
	this->Clone = NULL;
	this->IsDeleted = false;
	this->PParent = Template;

	this->FID = Template->FID;
//	this->FCode = Template->FCode;
	this->FDescr = Template->Descr;
	this->FIsMark = Template->FIsMark;
	this->FVerStamp = Template->FVerStamp;
	this->FModified = Template->FModified;

//	this->FIsTree = 0;
}

TBase::TBase(TADOQuery *q)
{
	this->Clone = NULL;
	this->PParent = NULL;
	this->IsDeleted = false;

//	this->FIsTree = 0;
	GetFromDB(q);

}

int TBase::RemoveFromDB(TADOQuery *q)
{
	q->Parameters->ParamByName("id")->Value = this->ID;
	return q->ExecSQL(); 
}

int TBase::UpdateDB(TADOQuery *q)
{
	if (!FModified)
		return -1;

	SetUpdateParams(q);

	if (q->ExecSQL())	{
		FModified = false;
		return 1;
	}
	else
		return 0;
}

int TBase::InsertDB(TADOQuery *q)
{

	SetUpdateParams(q);
	q->ExecSQL();

	return 1;
}

int TBase::GetMaxID(TADOQuery *q)
{
	int MaxID;

	q->Open();
	try {
		if (q->RecordCount != 1)
			throw "Неверное количество записей в GetMaxID.";
		else
			MaxID = q->FieldByName("MaxID")->AsInteger;
	}
	catch (char msg) {
		ShowMessage(msg);
		return -1;
	}
	q->Close();
    return MaxID;
}

void TBase::Save(TADOQuery *qMax, TADOQuery *qInsert, TADOQuery *qUpdate, TADOQuery *qDelete)
{
	if (FID == 0) {
		FID = GetMaxID(qMax) + 1;
		if (FID == -1)
			return;
		InsertDB(qInsert);
	}
	else if (IsDeleted)	{
		RemoveFromDB(qDelete);
	}
	else	{
		UpdateDB(qUpdate);
	}
}

void TBase::SetBackUp()
{
	BDescr = FDescr;
}

void TBase::BackUp()
{
	FDescr = BDescr;
}

