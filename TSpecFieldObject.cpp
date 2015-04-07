//---------------------------------------------------------------------------


#pragma hdrstop

#include "TSpecFieldObject.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TSpecFieldObject::TSpecFieldObject()
{
	FFieldName = "";
	FFieldType = 0;
	FAppointment = 0;
	FListID = 0;
	FItemID = 0;
}

void TSpecFieldObject::Set(TSpecFieldObject obj)
{
	FFieldName = obj.FieldName;
	FFieldType = obj.FieldType;
	FAppointment = obj.Appointment;
	FListID = obj.ListID;
	FItemID = obj.ItemID;
}
