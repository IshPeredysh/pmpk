//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef BeforeReportH
#define BeforeReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------

typedef void (__fastcall *TCreateReportFunc)(TDateTime, TDateTime);

class TBeforeReportForm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TStringGrid *sg;
	TToolButton *ExeclButton;
	TImageList *ImageList1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sgDblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall sgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall sgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall sgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall ExeclButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBeforeReportForm(TComponent* Owner);
    TCreateReportFunc ExportExcel;
	void ClearGrid();
};
//---------------------------------------------------------------------------
extern PACKAGE TBeforeReportForm *BeforeReportForm;
//---------------------------------------------------------------------------
#endif
