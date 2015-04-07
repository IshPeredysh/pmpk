//---------------------------------------------------------------------------

#ifndef RichEditSpecH
#define RichEditSpecH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "ISpecField.h"
#include <designintf.hpp>

//---------------------------------------------------------------------------

struct TPhrase
{
	String Text;
	int Start;
	int Length;
};


class PACKAGE TRichEditSpec : public TRichEdit, public ISpecField
{
	private:

		String FFieldName;
		int FFieldType;
		int FAppointment;
		int FListID;
		int FItemID;
		int FModify;

		//--interface
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
		String __fastcall GetTextData() {return Text;};
		int __fastcall GetItemID() {return FItemID;};
		int __fastcall GetListID() {return FListID;};
		int __fastcall GetAppointment() {return FAppointment;};
		int __fastcall GetModify() {return FModify;};
		TColor __fastcall GetColor() {return Color;};
		TNotifyEvent __fastcall  GetOnFontChange(){return FOnFontChange;};
		void __fastcall SetOnFontChange(TNotifyEvent EventFontChange){FOnFontChange = EventFontChange;};
		//interface--

		void __fastcall WmOnFontChange(TObject *Sender);
		TNotifyEvent FOnFontChange;
		TNotifyEvent OldOnFontChange;

		TNotifyEvent FOnAfterSetItemID;
		void SetCaption();

	public:
		int AnchorID;
		int MonitiorModify;
		__fastcall TRichEditSpec(TComponent* Owner);
		TPhrase __fastcall GetActivePhrase();
		void __fastcall InsertInCaret(String Value);
    	void __fastcall ReplaseActivePhrase(String Value);
		void __fastcall SetFocusSpec() {SetFocus();};
		void __fastcall SetStillItemID(int Value);
	__published:
		__property TNotifyEvent __fastcall OnAfterSetItemID = {read=FOnAfterSetItemID, write=FOnAfterSetItemID};
		//--interface
		__property String __fastcall FieldName ={read=GetFieldName, write=SetFieldName};
		__property int __fastcall FieldType ={read=GetFieldType, write=SetFieldType};
		__property String __fastcall TextData ={read=GetTextData, write=SetTextData};
		__property int __fastcall ListID ={read=FListID, write=SetListID};
		__property int __fastcall ItemID ={read=GetItemID, write=SetItemID};
		__property int __fastcall Appointment ={read=FAppointment, write=SetAppointment};
		__property int __fastcall Modify={read=GetModify, write=SetModify};
        __property TNotifyEvent __fastcall OnFontChange={read=FOnFontChange, write=FOnFontChange};

		//interface--
};
//---------------------------------------------------------------------------
#endif
