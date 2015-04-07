//---------------------------------------------------------------------------


#pragma hdrstop

#include "TParent.h"
#include "DMUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TParent::TParent(int MaxID):TBase(MaxID)
{
	FAge = 0;
	FEducation = 0;
	FBadHabit = 0;
	FBadStrain = 0;
	FWork = "";
};

TParent::TParent(TADOQuery *q):TBase(q)
{
	FAge = q->FieldByName("Age")->AsInteger;
	FEducation = q->FieldByName("Education")->AsInteger;
	FBadHabit = q->FieldByName("BadHabit")->AsInteger;
	FBadStrain = q->FieldByName("BadStrain")->AsInteger;
	FWork = q->FieldByName("FWork")->AsString;
}

int TParent::SetThisUpdateParams(TADOQuery *q)
{
	q->Parameters->ParamByName("Age")->Value = FAge;
	q->Parameters->ParamByName("Education")->Value = FEducation;
	q->Parameters->ParamByName("BadHabit")->Value = FBadHabit;
	q->Parameters->ParamByName("BadStrain")->Value = FBadStrain;
	q->Parameters->ParamByName("FWork")->Value = FWork;
	return 1;
}


TParent::TParent(TParent *Template):TBase(Template)
{
	this->FAge = Template->FAge;
	this->FEducation = Template->FEducation;
	this->FBadHabit = Template->FBadHabit;
	this->FBadStrain = Template->FBadStrain;
	this->FWork = Template->FWork;
}

String TParent::GetEducation()
{
	return "";
}

void TParent::SetAge(int Value)
{
	FAge = Value;
	FModified = true;
}

void TParent::SetEducation(int Value)
{
	FEducation = Value;
	FModified = true;
}

void TParent::SetBadHabit(int Value)
{
	FBadHabit = Value;
	FModified = true;
}

void TParent::SetBadStrain(int Value)
{
	FBadStrain = Value;
	FModified = true;
}

void TParent::SetWork(String Value)
{
	FWork = Value;
	FModified = true;
}

int TParent::DeleteFromDB()
{
	TADOQuery *q;

	q = DM->ParentCheckQuery;
	q->Parameters->ParamByName("fatherID")->Value = FID;
	q->Parameters->ParamByName("motherID")->Value = FID;
	q->Open();
	if (q->FieldByName("cnt")->AsInteger) {
		q->Close();
		return -1;
	}
	q->Close();

	return RemoveFromDB(DM->ParentDeleteQuery);
}

void TParent::SetBackUp()
{
	TBase::SetBackUp();
	BAge = FAge;
	BEducation = FEducation;
	BBadHabit = FBadHabit;
	BBadStrain = FBadStrain;
	BWork = FWork;

}

void TParent::BackUp()
{
	TBase::BackUp();
	BAge = FAge;
	BEducation = FEducation;
	BBadHabit = FBadHabit;
	BBadStrain = FBadStrain;
	BWork = FWork;
}

