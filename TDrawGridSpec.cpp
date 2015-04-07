//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TDrawGridSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

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

TInplaceEdit* __fastcall TDrawGridSpec::CreateEditor()
{
  SpecEditor = new TSpecInplaceEdit(this);
  SpecEditor->OnEnterEdit = FOnEnterEdit;
  SpecEditor->OnExitEdit = FOnExitEdit;
  return SpecEditor;
}


/*
     __fastcall TDrawGridSpec::TDrawGridSpec(Classes::TComponent* AOwner):TDrawGrid(AOwner)
    {
    		Options = Options << goEditing;
	}
*/


Boolean TDrawGridSpec::IsEditMode()
{
	return SpecEditor->Mode;
}







static inline void ValidCtrCheck(TDrawGridSpec *)
{
	new TDrawGridSpec(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDrawGridSpec::TDrawGridSpec(TComponent* Owner)
	: TDrawGrid(Owner)
{
//	Options = Options << goEditing;
}
//---------------------------------------------------------------------------
namespace Tdrawgridspec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TDrawGridSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
