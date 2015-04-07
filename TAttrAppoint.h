//---------------------------------------------------------------------------

#ifndef TAttrAppointH
#define TAttrAppointH
#include "TBase.h"

const String START_FIELDCODE = "<|";
const String END_FIELDCODE = "|>";

//---------------------------------------------------------------------------
class TAttrAppoint: public TBase
{
	private:
		String GetAppoint();
		int SetThisUpdateParams(TADOQuery *q);
		void SetAnchor(int Value);
		void SetCaption(String Value);
		String GetFieldCode();
	protected:
		int FAppointment; //String SP118;
		int FAnchorID;
		String FCaption;
		int FFieldType;
	public:
		TAttrAppoint(TADOQuery *q);
		TAttrAppoint(int MaxID);
		__property int AppointID = {read=FAppointment};
		__property String Appoint = {read=GetAppoint};
		__property int FieldType = {read=FFieldType};
		__property int AnchorID = {read=FAnchorID, write=SetAnchor};
		__property String Caption = {read=FCaption, write=SetCaption};
		__property String AsFieldCode = {read=GetFieldCode};
};
#endif
