//---------------------------------------------------------------------------


#pragma hdrstop

#include "MouseWheelUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

#define MOUSEWHEEL 5

void __fastcall sgMouseWheelDownA(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	int h;
	TStringGrid* g = ((TStringGrid*)(Sender));
	h = (g->RowCount - g->Height/(g->DefaultRowHeight + 2));
	Handled = false;
	if (g->TopRow <= h) {
		g->TopRow = g->TopRow + MOUSEWHEEL;
	}
	Handled = true;
}

void __fastcall sgMouseWheelUpA(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > MOUSEWHEEL + g->FixedRows)	{
		g->TopRow = g->TopRow - MOUSEWHEEL;
	}
	else
		g->TopRow = g->FixedRows;
	Handled = true;
}

