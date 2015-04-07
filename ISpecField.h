//---------------------------------------------------------------------------

#ifndef ISpecFieldH
#define ISpecFieldH
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------

enum TFieldTypeSpec {ftsNone, ftsString, ftsNumber, ftsDate, ftsRefList, ftsRefBox};

class ISpecField
{
	protected:
		virtual void __fastcall SetFieldName(String Value) = 0;
		virtual void __fastcall SetFieldType(int Value) = 0;
		virtual void __fastcall SetTextData(String Value) = 0;
		virtual void __fastcall SetListID(int Value) = 0;
		virtual void __fastcall SetItemID(int Value) = 0;
		virtual void __fastcall SetAppointment(int Value) = 0;
		virtual void __fastcall SetColor(TColor Value) = 0;

		virtual String __fastcall GetFieldName() = 0;
		virtual int __fastcall GetFieldType() = 0;
		virtual String __fastcall GetTextData() = 0;
		virtual int __fastcall GetListID() = 0;
		virtual int __fastcall GetItemID() = 0;
		virtual int __fastcall GetAppointment() = 0;
		virtual TColor __fastcall GetColor() = 0;

	public:
    	virtual void __fastcall SetFocusSpec() = 0;
		__property String __fastcall FieldName = {read=GetFieldName, write=SetFieldName};
		__property int __fastcall FieldType = {read=GetFieldType, write=SetFieldType};
		__property String __fastcall TextData ={read=GetTextData, write=SetTextData};
		__property int __fastcall ListID = {read=GetListID, write=SetListID};
		__property int __fastcall ItemID = {read=GetItemID, write=SetItemID};
		__property int __fastcall Appointment = {read=GetAppointment, write=SetAppointment};
		__property TColor __fastcall ColorSpec = {read=GetColor, write=SetColor};
};
#endif
