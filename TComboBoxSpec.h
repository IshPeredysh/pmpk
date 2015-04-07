//---------------------------------------------------------------------------

#ifndef TComboBoxSpecH
#define TComboBoxSpecH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "ISpecField.h"

//---------------------------------------------------------------------------
class PACKAGE TComboBoxSpec : public TComboBox, public ISpecField
{
private:
	void SetCaption();
	void __fastcall SetFieldName(String Value);
	void __fastcall SetParentID(int Value);
	void __fastcall SetAppointment(int Value);
	void __fastcall SetFieldType(int Value);
	void __fastcall SetTextData(String Value) {};
	void __fastcall SetItemID(int Value);
	void __fastcall SetListID(int Value);
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
	TNotifyEvent __fastcall  GetOnFontChange(){return FOnFontChange;};;
	void __fastcall SetOnFontChange(TNotifyEvent EventFontChange){FOnFontChange = EventFontChange;};

	void __fastcall WmOnFontChange(TObject *Sender);
	TNotifyEvent FOnFontChange;
	TNotifyEvent OldOnFontChange;

	String FFieldName;
	int FFieldType;
	int FParentID;
	int FAppointment;
	int FItemID;
	int FListID;
	int FModify;

	TNotifyEvent FOnAfterSetItemID;
	TMouseWheelUpDownEvent FOnMouseWheelUp;
	TMouseWheelUpDownEvent FOnMouseWheelDown;
protected:
//	void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall WMMouseWheel(TWMMouseWheel &msg);
	BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(WM_MOUSEWHEEL, TWMMouseWheel, WMMouseWheel)
	END_MESSAGE_MAP(TComboBox);

public:
	int MonitiorModify;
	__fastcall TComboBoxSpec(TComponent* Owner);
	void __fastcall SetFocusSpec() {SetFocus();};
__published:
	__property TNotifyEvent __fastcall OnAfterSetItemID = {read=FOnAfterSetItemID, write=FOnAfterSetItemID};
	__property TMouseWheelUpDownEvent __fastcall OnMouseWheelUp = {read=FOnMouseWheelUp, write=FOnMouseWheelUp};
	__property TMouseWheelUpDownEvent __fastcall OnMouseWheelDown = {read=FOnMouseWheelDown, write=FOnMouseWheelDown};

	__property String __fastcall FieldName ={read=GetFieldName, write=SetFieldName};
	__property int __fastcall FieldType ={read=GetFieldType, write=SetFieldType};
	__property int __fastcall ParentID ={read=FParentID, write=SetParentID};
	__property int __fastcall Appointment ={read=FAppointment, write=SetAppointment};
	__property int __fastcall ItemID ={read=GetItemID, write=SetItemID};
	__property int __fastcall ListID ={read=FListID, write=SetListID};
	__property int __fastcall Modify={read=GetModify, write=SetModify};
    __property TNotifyEvent __fastcall OnFontChange={read=FOnFontChange, write=FOnFontChange};
};
//---------------------------------------------------------------------------
#endif
