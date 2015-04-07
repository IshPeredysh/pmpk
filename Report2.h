//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef Report2H
#define Report2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "TSpecFieldObject.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------


class TReportForm2 : public TForm
{
__published:	// IDE-managed Components
	TSplitter *Splitter1;
	TToolBar *ToolBar1;
	TPanel *Panel6;
	TDateTimePicker *DateTimePicker1;
	TPanel *Panel7;
	TDateTimePicker *DateTimePicker2;

private:	// User declarations
public:		// User declarations
	__fastcall TReportForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TReportForm2 *ReportForm2;
//---------------------------------------------------------------------------
#endif
