//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TMyEdit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

void __fastcall TMyEdit::WndProc(Messages::TMessage &msg)
{
	if (msg.Msg == EN_CHANGE) {
		change(this);
	}
	TEdit::WndProc(msg);
}

void __fastcall TMyEdit::change(TObject *Sender)
{
	((TEdit*)Sender)->Text = String(Sender->ClassName());
}

static inline void ValidCtrCheck(TMyEdit *)
{
	new TMyEdit(NULL);
}
//---------------------------------------------------------------------------
__fastcall TMyEdit::TMyEdit(TComponent* Owner)
	: TEdit(Owner)
{
}
//---------------------------------------------------------------------------
namespace Tmyedit
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TMyEdit)};
		RegisterComponents("Samples", classes, 0);
	}
}
//---------------------------------------------------------------------------
