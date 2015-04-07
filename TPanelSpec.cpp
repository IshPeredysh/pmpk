//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TPanelSpec.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TPanelSpec *)
{
	new TPanelSpec(NULL);
}
//---------------------------------------------------------------------------
__fastcall TPanelSpec::TPanelSpec(TComponent* Owner)
	: TPanel(Owner)
{
}
//---------------------------------------------------------------------------
namespace Tpanelspec
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TPanelSpec)};
		RegisterComponents("PMPK", classes, 0);
	}
}
//---------------------------------------------------------------------------
