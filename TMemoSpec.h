//---------------------------------------------------------------------------

#ifndef TMemoSpecH
#define TMemoSpecH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------

class PACKAGE TMemoSpec : public TMemo
{
	private:
		void __fastcall SetFieldData(String Value);
		void __fastcall SetAccess(String Value);
		String FFieldData;
		String FAccess;
//		int FAutoHeight;
	protected:
//		virtual void __fastcall WndProc(Messages::TMessage &msg);
//		void __fastcall _AutoHeight(TObject *Sender);
	public:
		__fastcall TMemoSpec(TComponent* AOwner);
	__published:
//		__property int AutoHeight = {read=FAutoHeight, write=FAutoHeight};
		__property String __fastcall FieldData ={read=FFieldData, write=SetFieldData};
		__property String __fastcall Access ={read=FAccess, write=SetAccess};
};
//---------------------------------------------------------------------------
#endif
