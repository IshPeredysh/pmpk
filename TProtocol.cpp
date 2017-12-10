//---------------------------------------------------------------------------


#pragma hdrstop

#include "TProtocol.h"
#include <Dialogs.hpp>
#include "TDrawBaseList.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)


int TProtocol::DeleteProtocol()
{
	TADOQuery *q = DM->ProtocolDeleteQuery;

	q->Parameters->ParamByName("IDDoc")->Value = this->FIDDoc;
	return q->ExecSQL();
}

void TProtocol::SetDocNo(int Value)
{
	FDocNo = Value;
	FModified = true;
}

void TProtocol::SetDate(TDateTime Value)
{
	FDate = Value;
	FModified = true;
}

void TProtocol::SetChildID(int Value)
{
	FChildID = Value;
	FModified = true;
}

int TProtocol::InsertToDB()
{
	TADOQuery * q;
	int result;

	q = DM->JournInsertQuery;
	try {
		q->Parameters->ParamByName("IDDOC")->Value = this->FIDDoc; //
		q->Parameters->ParamByName("FDATE")->Value = this->FDate;    //
		q->Parameters->ParamByName("FTIME")->Value = "";
		q->Parameters->ParamByName("DOCNO")->Value = this->FDocNo;  //
		q->Parameters->ParamByName("CLOSED")->Value = 0;
		q->Parameters->ParamByName("ISMARK")->Value = " ";
		q->Parameters->ParamByName("ACTCNT")->Value = "";
		q->Parameters->ParamByName("VERSTAMP")->Value = 0;
		result = q->ExecSQL();
		if (result == 1)
			FModified = false;
		else
			throw "Ќе удалось сохронить новый протокол. IDDOC=" + IntToStr(this->FIDDoc)
			+ "DocNo=" + IntToStr(this->FDocNo);
	} catch (char str) {
		ShowMessage(str);
	}
	return result;
}

TProtocol::TProtocol()
{
	int iMaxID, LastDocNo;
	TADOQuery* q;

	q = DM->JournGetMaxQuery;
	q->Open();
	iMaxID = q->FieldByName("MaxID")->AsInteger;
	q->Close();
	iMaxID++;
	FIDDoc = iMaxID;

	q = DM->JournGetDocNoQuery;
	q->Open();
	LastDocNo = q->FieldByName("DOCNO")->AsInteger;
	q->Close();
	LastDocNo++;
	FDocNo = LastDocNo;

	FDate = Now();
	FClosed = 0;

	FChildID = 0;

	FModified = false;

	InsertToDB();
}

TProtocol::TProtocol(TADOQuery *q)
{
	this->LoadFromBD(q);
}

void TProtocol::LoadFromBD(TADOQuery *q)
{
	this->FIDDoc = q->FieldByName("iddoc")->AsInteger;
	this->FChildID = q->FieldByName("childid")->AsInteger;
	this->FDate = q->FieldByName("FDATE")->AsDateTime;
	this->FDocNo = q->FieldByName("DOCNO")->AsInteger;
	this->FClosed = q->FieldByName("Closed")->AsInteger;
	this->FAppointmentID = q->FieldByName("AppointmentID")->AsInteger;
	FModified = false;
}

void TProtocol::SaveChild()
{
	TADOQuery *q;

	q = DM->JournalChildUpdateQuery;
	
	if (FChildID == 0)
		q->Parameters->ParamByName("childid")->Value.Clear();
	else
		q->Parameters->ParamByName("childid")->Value = FChildID;

	q->Parameters->ParamByName("iddoc")->Value = FIDDoc;
	if (!q->ExecSQL())	{
		q = DM->JournalChildInsertQuery;
		if (FChildID == 0)
			q->Parameters->ParamByName("childid")->Value.Clear();
		else
			q->Parameters->ParamByName("childid")->Value = FChildID;
		q->Parameters->ParamByName("iddoc")->Value = FIDDoc;
		q->ExecSQL();
	}
}

void TProtocol::UpdateToDB()
{
	TADOQuery *q;

	if (!FModified)
		 return;

	q = DM->JournUpdateQuery;
	q->Parameters->ParamByName("DocNo")->Value = FDocNo;
	q->Parameters->ParamByName("FDate")->Value = FDate;
	q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
	q->ExecSQL();

	SaveChild();
}

int __fastcall TProtocol::SetAppoint(int ID_Appoint)
{
	int AppointCnt;

	TADOQuery *q;

	/*q = DM->AppointJournDeleteQuery;
	q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
	q->Parameters->ParamByName("AppointmentID")->Value = FAppointmentID;
	q->ExecSQL(); */

	/*if (ID_Appoint == DEF_APPOINT)	{
		FAppointmentID = ID_Appoint;
		return FAppointmentID;
	}*/

	q = DM->AppointJournCheckQuery;
	q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
	q->Parameters->ParamByName("AppointmentID")->Value = ID_Appoint;
	q->Open();
	if (q->RecordCount)	{
		q->Close();
		FAppointmentID = DEF_APPOINT;
	}
	else	{
		q->Close();
		q = DM->AppointJournInsertQuery;
		q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
		q->Parameters->ParamByName("AppointmentID")->Value = ID_Appoint;
		q->ExecSQL();
		FAppointmentID = ID_Appoint;
	}

	return FAppointmentID;
}

int TProtocol::ProtocolOpen(int AppointID)
{
	return SetAppoint(AppointID);

	/*TADOQuery *q = DM->JournGetClosedQuery;

	q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
	q->Open();
	FClosed = q->FieldByName("Closed")->AsInteger + 1;
	q->Close();

	q = DM->JournOpenQuery;
	q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
	q->ExecSQL();*/
}

void TProtocol::ProtocolClose()
{
    TADOQuery *q;
	/*TADOQuery *q = DM->JournGetClosedQuery;

	if (FClosed < 2)	{
		q = DM->JournCloseQuery;
		q->Parameters->ParamByName("IDDoc")->Value = FIDDoc;
		q->ExecSQL();
	}*/

	q = DM->AppointJournDeleteQuery;
	q->Parameters->ParamByName("IDDoc")->Value = this->FIDDoc;
	q->Parameters->ParamByName("AppointmentID")->Value = this->FAppointmentID;
	q->ExecSQL();

	this->FAppointmentID = 0;
}

TProtocol::TProtocol(TProtocol* p, int AppointID)
{
	this->FIDDoc = p->FIDDoc;
	this->FDocNo = p->FDocNo;
	this->FDate = p->FDate;
	this->FChildID = p->FChildID;
	this->FClosed = p->FClosed;
	this->FModified = p->FModified;
	this->FAppointmentID = AppointID;
}
