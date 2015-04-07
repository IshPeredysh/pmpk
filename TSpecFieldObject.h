//---------------------------------------------------------------------------

#ifndef TSpecFieldObjectH
#define TSpecFieldObjectH
#include "ISpecField.h"
//---------------------------------------------------------------------------

class TSpecFieldObject: public ISpecField
{
	private:
		String FFieldName;
		int FFieldType;
		int FAppointment;
		int FListID;
		int FItemID;
		String FTextData;

		virtual void __fastcall SetFieldName(String Value) {FFieldName = Value;};
		virtual void __fastcall SetFieldType(int Value){FFieldType = Value;};
		virtual void __fastcall SetTextData(String Value){FTextData = Value;};
		virtual void __fastcall SetListID(int Value){FListID = Value;};
		virtual void __fastcall SetItemID(int Value){FItemID = Value;};
		virtual void __fastcall SetAppointment(int Value){FAppointment = Value;};

		void __fastcall SetColor(TColor Value) {};
		void __fastcall SetFocusSpec() {};

		virtual String __fastcall GetFieldName(){return FFieldName;};
		virtual int __fastcall GetFieldType(){return FFieldType;};
		virtual String __fastcall GetTextData(){return FTextData;};
		virtual int __fastcall GetListID(){return FListID;};
		virtual int __fastcall GetItemID(){return FItemID;};
		virtual int __fastcall GetAppointment(){return FAppointment;};
		TColor __fastcall GetColor() {return clWindow;};
	public:
		TSpecFieldObject();
		void Set(TSpecFieldObject obj);
};

class TRepField: public TSpecFieldObject
{
	public:
		TRepField():TSpecFieldObject(){Count = 0;};
		int Count;
};
#endif
