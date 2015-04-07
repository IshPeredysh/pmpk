//---------------------------------------------------------------------------

#ifndef MouseWheelUnitH
#define MouseWheelUnitH

#include <Grids.hpp>
//---------------------------------------------------------------------------

void __fastcall sgMouseWheelDownA(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled);
void __fastcall sgMouseWheelUpA(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled);

#endif
