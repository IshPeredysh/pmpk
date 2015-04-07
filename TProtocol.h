//---------------------------------------------------------------------------

#ifndef TProtocolH
#define TProtocolH
#include <Classes.hpp>
#include "DMUnit.h"
//---------------------------------------------------------------------------

const int DEF_APPOINT = 8; //ReadOnly for all

class TProtocol
{
	private:
		int FIDDoc;
		int FDocNo;
		TDateTime FDate;
		int FChildID;
		int FClosed;
		int FAppointmentID;

		void SetDocNo(int Value);
		void SetDate(TDateTime Value);
		void SetChildID(int Value);

		int FModified;

	public:
		TProtocol();
		TProtocol(TProtocol* NewProt, int AppointID);
		TProtocol(TADOQuery *q);
		int DeleteProtocol();
		void LoadFromBD(TADOQuery *q);
		int InsertToDB();
		void SaveChild();
		void UpdateToDB();
		int ProtocolOpen(int AppointID);
		void ProtocolClose();
		int __fastcall SetAppoint(int ID_Appoint);
		__property int IDDoc = {read=FIDDoc};
		__property int AppointmentID = {read=FAppointmentID, write=FAppointmentID};
		__property int Closed = {read=FClosed};
		__property int DocNo = {read=FDocNo, write=SetDocNo};
		__property TDateTime Date = {read=FDate, write=SetDate};
		__property int ChildID = {read=FChildID, write=SetChildID};

};
#endif
