//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef AreasH
#define AreasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "RichEditSpec.h"
#include "TEditSpec.h"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "TDrawGridSpec.h"
#include "TTreeBaseEmpty.h"

#define COLW_0 30
//---------------------------------------------------------------------------
class TAreasForm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TToolButton *AddStringButton;
	TToolButton *EditButton;
	TDrawGridSpec *dg;
	TToolButton *DeleteButton;
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
	TTreeBaseEmpty *DelItem;
	int ID;
	TTreeBaseEmpty *EditItem;
	TRichEditSpec* AddRichEdit;
	TRichEditSpec* SetRichEdit;
	TEditSpec* SetEdit;
	__fastcall TAreasForm(TComponent* Owner);
	void __fastcall ChangeFont(TFont *f);
//	int __fastcall DelArea();
};
//---------------------------------------------------------------------------
extern PACKAGE TAreasForm *AreasForm;
//---------------------------------------------------------------------------
#endif
