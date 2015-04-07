//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Appointment.h"
#include "TBaseEmptyList.h"
#include "ImagesDM.h"
#include "TAutoSize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"
TAppointmentForm *AppointmentForm;
extern TBaseEmptyList *AppointmentList;
//---------------------------------------------------------------------------
__fastcall TAppointmentForm::TAppointmentForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAppointmentForm::FormShow(TObject *Sender)
{
	dg->RowCount = AppointmentList->Count + 1;
}
//---------------------------------------------------------------------------
void __fastcall TAppointmentForm::dgDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;
	TBaseEmpty* Item;
	int cnt;

	cnt = AppointmentList->Count;

	if (ARow > 0 && ARow <= cnt) {
		Item = (TBaseEmpty*)AppointmentList->Items[ARow - 1];
		ImageList->Draw(c, Rect.left, Rect.top, STRING_IMG, true);
		c->TextOutA(Rect.left + ImageList->Width + 4, Rect.top, Item->Descr);
	}
	else
		c->FillRect(Rect);
}
//---------------------------------------------------------------------------
void __fastcall TAppointmentForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	int h;
	TStringGrid* g = ((TStringGrid*)(Sender));
	h = (g->RowCount - g->Height/g->DefaultRowHeight) - g->FixedRows;
	Handled = false;
	if (g->TopRow <= h) {
	g->TopRow = g->TopRow + 5;
	}
	Handled = true;
}
//---------------------------------------------------------------------------

void __fastcall TAppointmentForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > 5 + g->FixedRows)
		g->TopRow = g->TopRow - 5;
	else
		g->TopRow = 1;
	Handled = true;
}
//---------------------------------------------------------------------------

void __fastcall TAppointmentForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = (dg->Width - GetSystemMetrics(SM_CXVSCROLL));
}
//---------------------------------------------------------------------------


void __fastcall TAppointmentForm::ChangeFont(TFont *f)
{
	int w;
	Font->Assign(f);
	ImageList = ImageListByFont(f, Images->ImageList1, Images->ImageList2, Images->ImageList3);
	DrawGridRowsAutoHeigth(dg, ImageList);
}
