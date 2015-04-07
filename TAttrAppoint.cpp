//---------------------------------------------------------------------------


#pragma hdrstop

#include "TAttrAppoint.h"
#include "TBaseEmptyList.h"

#pragma package(smart_init)

extern TBaseEmptyList *AppointmentList;

//---------------------------------------------------------------------------



String TAttrAppoint::GetAppoint()
{
	TBaseEmpty *Item;

	Item = (TBaseEmpty*)AppointmentList->ItemByID(FAppointment);
	if (Item == NULL)
		return "";
	return Item->Descr;
}

TAttrAppoint::TAttrAppoint(int MaxID):TBase(MaxID)
{
	FAppointment = 0;
}

TAttrAppoint::TAttrAppoint(TADOQuery *q):TBase(q)
{
	FAppointment = q->FieldByName("AppointmentID")->AsInteger;
	AnchorID = q->FieldByName("AnchorID")->AsInteger;
	FFieldType = q->FieldByName("FIELDTYPE")->AsInteger;
	FCaption = q->FieldByName("CAPTION")->AsString;
}

int TAttrAppoint::SetThisUpdateParams(TADOQuery *q)
{
	q->Parameters->ParamByName("AppointmentID")->Value = FAppointment;
	q->Parameters->ParamByName("AnchorID")->Value = FAnchorID;
	q->Parameters->ParamByName("FIELDTYPE")->Value = FFieldType;
	q->Parameters->ParamByName("CAPTION")->Value = FCaption;
	return 1;
}

void TAttrAppoint::SetAnchor(int Value)
{
    FModified = true;
	FAnchorID = Value;
}

void TAttrAppoint::SetCaption(String Value)
{
	FModified = true;
	FCaption = Value;
}

String TAttrAppoint::GetFieldCode()
{
	return START_FIELDCODE + FDescr + END_FIELDCODE;
}

