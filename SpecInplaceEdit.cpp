//---------------------------------------------------------------------------


#pragma hdrstop

#include "SpecInplaceEdit.h"

//---------------------------------------------------------------------------

void __fastcall TSpecInplaceEdit::WndProc(Messages::TMessage &msg)
{
	if (msg.Msg == WM_SETFOCUS)
		EnterEdit(msg.Msg = WM_SETFOCUS);

	if (msg.Msg == WM_KILLFOCUS)
		ExitEdit(msg.Msg = WM_KILLFOCUS);
	TInplaceEdit::WndProc(msg);
}


void TSpecInplaceEdit::EnterEdit(Boolean mode)
{
	FMode = mode;
	if (FOnEnterEdit)
		FOnEnterEdit(Grid);
}


void TSpecInplaceEdit::ExitEdit(Boolean mode)
{
	FMode = mode;
	if (FOnExitEdit)
		FOnExitEdit(Grid);
}

TInplaceEdit* __fastcall TDrawGridSE::CreateEditor()
{
  SpecEditor = new TSpecInplaceEdit(this);
  SpecEditor->OnEnterEdit = FOnEnterEdit;
  SpecEditor->OnExitEdit = FOnExitEdit;
  return SpecEditor;
}

__fastcall TDrawGridSE::TDrawGridSE(Classes::TComponent* AOwner):TDrawGrid(AOwner)
{
	Options = Options << goEditing;
}

Boolean TDrawGridSE::IsEditMode()
{
	return SpecEditor->Mode;
}

#pragma package(smart_init)
