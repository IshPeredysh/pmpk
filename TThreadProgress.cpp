//$$---- Thread CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TThreadProgress.h"
#include "Progress.h"
#include "Areas.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TThreadProgress::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TThreadProgress::TThreadProgress(bool CreateSuspended)
	: TThread(CreateSuspended)
{

}

void __fastcall TThreadProgress::ShowMessageT()
{
	ShowMessage(MessageText);
}

void __fastcall TThreadProgress::RefreshFuncT()
{
	RefreshFunc();
}



//---------------------------------------------------------------------------
void __fastcall TThreadProgress::Execute()
{
	MessageText = "Запись не удалена т.к. используется в других таблицах.";

	if (Func())
		Synchronize(&ShowMessageT);
	else
		if (RefreshFunc)
			Synchronize(&RefreshFuncT);
}
//---------------------------------------------------------------------------
