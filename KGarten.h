//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef KGartenH
#define KGartenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RichEditSpec.h"
#include "TDrawGridSpec.h"
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "TBaseEmpty.h"
#include "TEditSpec.h"


#define COLW_0 30
//---------------------------------------------------------------------------
class TKGartenForm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TToolButton *AddStringButton;
	TToolButton *DeleteButton;
	TToolButton *EditButton;
	TDrawGridSpec *dg;
	TImageList *ImageList1;
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall dgDblClick(TObject *Sender);
	void __fastcall dgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall AddStringButtonClick(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall dgExitEdit(TObject *Sender);
	void __fastcall dgGetEditText(TObject *Sender, int ACol, int ARow,
          AnsiString &Value);
	void __fastcall dgSetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
	void __fastcall DeleteButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TBaseEmpty *DelItem;
	int ID;
	TBaseEmpty *EditItem;
	TRichEditSpec* AddRichEdit;
	TRichEditSpec* SetRichEdit;
	TEditSpec* SetEdit;
	__fastcall TKGartenForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKGartenForm *KGartenForm;
//---------------------------------------------------------------------------
#endif
