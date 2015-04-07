//$$---- Thread CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TCreateReportThread.h"
#include "Report.h"
#include "Progress.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCreateReportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCreateReportThread::TCreateReportThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TCreateReportThread::Execute()
{
	ProgressForm->Show();
	ReportForm->CreateReport();
	ProgressForm->CanClose = true;
	ProgressForm->Close();
	//---- Place thread code here ----
}


//---------------------------------------------------------------------------
