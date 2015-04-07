//---------------------------------------------------------------------------

#ifndef TMyEditH
#define TMyEditH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TMyEdit : public TEdit
{
	private:
		TNotifyEvent FOnchange;
		void __fastcall change(TObject *Sender);
	protected:
		void __fastcall WndProc(Messages::TMessage &msg);
	public:
		__fastcall TMyEdit(TComponent* AOwner);
		//void __fastcall change(TObject *Sender);
		__property TNotifyEvent Onchange = {read=FOnchange, write=FOnchange};
};
//---------------------------------------------------------------------------
#endif
