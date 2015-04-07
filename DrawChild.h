//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef DrawChildH
#define DrawChildH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "TDrawBaseList.h"

#define COLW_0 30
//---------------------------------------------------------------------------
class TDrawChildForm : public TForm
{
__published:	// IDE-managed Components
	TDrawGrid *dg;
	TImageList *ImageList1;
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall dgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TDrawChildList *DrawList;
	__fastcall TDrawChildForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDrawChildForm *DrawChildForm;
//---------------------------------------------------------------------------
#endif
