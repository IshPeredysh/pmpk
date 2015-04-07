//---------------------------------------------------------------------------

#ifndef TDrawGridSpecH
#define TDrawGridSpecH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------


class PACKAGE TSpecInplaceEdit: public TInplaceEdit
{
	private:
		boolean FMode;
		TNotifyEvent FOnEnterEdit;
		TNotifyEvent FOnExitEdit;
	protected:
		void __fastcall WndProc(Messages::TMessage &Message);
		void EnterEdit(Boolean mode);
		void ExitEdit(Boolean mode);
	public:
		__fastcall TSpecInplaceEdit(Classes::TComponent* AOwner):TInplaceEdit(AOwner){};
		__property TNotifyEvent OnEnterEdit = {read=FOnEnterEdit, write=FOnEnterEdit};
		__property TNotifyEvent OnExitEdit = {read=FOnExitEdit, write=FOnExitEdit};
		__property boolean Mode = {read=FMode, write=FMode};
};


class PACKAGE TDrawGridSpec : public TDrawGrid
{
private:
		TSpecInplaceEdit* SpecEditor;
		TNotifyEvent FOnEnterEdit;
		TNotifyEvent FOnExitEdit;
		TInplaceEdit* __fastcall CreateEditor();
protected:
		Boolean IsEditMode();
		//__fastcall TDrawGridSpec(Classes::TComponent* AOwner);
public:
		__fastcall TDrawGridSpec(TComponent* Owner);
__published:
		__property TNotifyEvent OnEnterEdit ={read=FOnEnterEdit, write=FOnEnterEdit};
		__property TNotifyEvent OnExitEdit = {read=FOnExitEdit, write=FOnExitEdit};
};
//---------------------------------------------------------------------------
#endif
