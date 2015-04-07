//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ParentsH
#define ParentsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "RichEditSpec.h"
#include "TEditSpec.h"
#include "TComboBoxSpec.h"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>

#define COLW_0 30
//---------------------------------------------------------------------------
class TParentsForm : public TForm
{
__published:	// IDE-managed Components
	TDrawGrid *dg;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TEdit *Edit1;
	TToolButton *ToolButton4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall dgDblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall dgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	int ID;
	int iFind;
	int SenderProtocol;
	int SenderChildren;
	TEditSpec *FIOEdit;
	TRichEditSpec* FIORichEdit;
	TRichEditSpec* AgeRichEdit;
	TComboBoxSpec* EducationComboBox;
	TRichEditSpec* PlaceWorkRichEdit;
	TComboBoxSpec* BadHabitRichComboBox;
	TComboBoxSpec* BadStrainRichComboBox;
	__fastcall TParentsForm(TComponent* Owner);
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TParentsForm *ParentsForm;
//---------------------------------------------------------------------------
#endif
