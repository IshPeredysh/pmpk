//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DM2Unit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM2 *DM2;
//---------------------------------------------------------------------------
__fastcall TDM2::TDM2(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
