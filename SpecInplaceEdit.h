//---------------------------------------------------------------------------

#ifndef SpecInplaceEditH
#define SpecInplaceEditH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------

class TSpecInplaceEdit: public TInplaceEdit
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

class TDrawGridSE: public TDrawGrid
{
	private:
		TSpecInplaceEdit* SpecEditor;
		TNotifyEvent FOnEnterEdit;
		TNotifyEvent FOnExitEdit;
		TInplaceEdit* __fastcall CreateEditor();
	public:
		Boolean IsEditMode();
		__fastcall TDrawGridSE(Classes::TComponent* AOwner);
	__published:
		__property TNotifyEvent OnEnterEdit ={read=FOnEnterEdit, write=FOnEnterEdit};
        __property TNotifyEvent OnExitEdit = {read=FOnExitEdit, write=FOnExitEdit};
};


#endif
