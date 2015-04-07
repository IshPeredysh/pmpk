//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImagesDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TImages *Images;
//---------------------------------------------------------------------------
__fastcall TImages::TImages(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
