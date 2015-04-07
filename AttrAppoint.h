//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef AttrAppointH
#define AttrAppointH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TDrawGridSpec.h"
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "TAttrAppoint.h"
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TAttrAppointForm : public TForm
{
__published:	// IDE-managed Components
	TDrawGridSpec *dg;
	TToolBar *ToolBar1;
	TToolButton *EditButton;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall dgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall dgMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall dgMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall dgKeyPress(TObject *Sender, char &Key);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall dgContextPopup(TObject *Sender, TPoint &MousePos,
          bool &Handled);
private:	// User declarations
public:		// User declarations
	TAttrAppoint *EditItem;
	int IconClickDown;
	TImageList *ImageList;
	__fastcall TAttrAppointForm(TComponent* Owner);
	void __fastcall EditIconClick(TObject *Sender);
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TAttrAppointForm *AttrAppointForm;
//---------------------------------------------------------------------------
#endif
