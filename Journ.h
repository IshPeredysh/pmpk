//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef JournH
#define JournH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "TProtocol.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TJournForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *sg;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TCoolBar *CoolBar1;
	TToolBar *ToolBar2;
	TLabel *Label1;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label2;
	TDateTimePicker *DateTimePicker2;
	TCheckBox *CurrentYearCheckBox;
	void __fastcall sgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall sgDblClick(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall sgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall sgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall CurrentYearCheckBoxClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TImageList *ImageList;
	__fastcall TJournForm(TComponent* Owner);
	void ClearGrid();
	void FillGrid();
	void __fastcall GridRowDelete(int Row);
	void AddProtocolToGrid(TProtocol *p, int row);
	int AddProtocol();
	int __fastcall DeleteProtocol(int IDDoc);
	void SaveINI();
	void LoadINI();
	int GetProtocolCount();
	int __fastcall RowByIDDoc(int IDDoc);
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TJournForm *JournForm;
//---------------------------------------------------------------------------
#endif
