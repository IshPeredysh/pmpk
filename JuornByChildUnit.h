//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef JuornByChildUnitH
#define JuornByChildUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include "MouseWheelUnit.h"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TJournByChildForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *sg;
	TImageList *ImageList1;
	void __fastcall sgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall sgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall sgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall sgDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TJournByChildForm(TComponent* Owner);
	int FillGrid(int ChildID);
	void ClearGrid();
};
//---------------------------------------------------------------------------
extern PACKAGE TJournByChildForm *JournByChildForm;
//---------------------------------------------------------------------------
#endif
