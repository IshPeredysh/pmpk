//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef AppointmentH
#define AppointmentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TDrawGridSpec.h"
#include <Grids.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TAppointmentForm : public TForm
{
__published:	// IDE-managed Components
	TDrawGridSpec *dg;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall dgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TImageList *ImageList;
	__fastcall TAppointmentForm(TComponent* Owner);
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TAppointmentForm *AppointmentForm;
//---------------------------------------------------------------------------
#endif
