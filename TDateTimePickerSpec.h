//---------------------------------------------------------------------------

#ifndef TDateTimePickerSpecH
#define TDateTimePickerSpecH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include "ISpecField.h"
//---------------------------------------------------------------------------
class PACKAGE TDateTimePickerSpec : public TDateTimePicker, public ISpecField
{
	private:
		String FFieldName;
		int FFieldType;
		int FAppointment;
		int FListID;
		int FItemID;
		int FModify;

		void __fastcall SetFieldName(String Value);
		void __fastcall SetFieldType(int Value);
		void __fastcall SetTextData(String Value);
		void __fastcall SetListID(int Value);
		void __fastcall SetItemID(int Value);
		void __fastcall SetAppointment(int Value);
		void __fastcall SetModify(int Value);
		void __fastcall SetColor(TColor Value) {Color = Value;};

		String __fastcall GetFieldName() {return FFieldName;};
		int __fastcall GetFieldType() {return FFieldType;};
		String __fastcall GetTextData();
		TDateTime __fastcall GetDateSpec();
		int __fastcall GetItemID() {return FItemID;};
		int __fastcall GetListID() {return FListID;};
		int __fastcall GetAppointment() {return FAppointment;};
		int __fastcall GetModify() {return FModify;};
		TColor __fastcall GetColor() {return Color;};
		TNotifyEvent __fastcall  GetOnFontChange(){return FOnFontChange;};;
		void __fastcall SetOnFontChange(TNotifyEvent EventFontChange){FOnFontChange = EventFontChange;};

		void __fastcall WmOnFontChange(TObject *Sender);
		TNotifyEvent FOnFontChange;
		TNotifyEvent OldOnFontChange;
	protected:
	public:
		int MonitiorModify;
		__fastcall TDateTimePickerSpec(TComponent* Owner);
		void __fastcall SetFocusSpec() {SetFocus();};
	__published:
		__property String __fastcall FieldName ={read=GetFieldName, write=SetFieldName};
		__property int __fastcall FieldType ={read=GetFieldType, write=SetFieldType};
		__property String __fastcall TextData ={read=GetTextData, write=SetTextData};
		__property TDateTime __fastcall DateSpec = {read=GetDateSpec};
		__property int __fastcall ListID ={read=FListID, write=SetListID};
		__property int __fastcall ItemID ={read=GetItemID, write=SetItemID};
		__property int __fastcall Appointment ={read=FAppointment, write=SetAppointment};
		__property int __fastcall Modify={read=GetModify, write=SetModify};
		__property TNotifyEvent __fastcall OnFontChange={read=FOnFontChange, write=FOnFontChange};

};
//---------------------------------------------------------------------------
#endif
