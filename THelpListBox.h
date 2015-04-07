//---------------------------------------------------------------------------

#ifndef THelpListBoxH
#define THelpListBoxH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "RichEditSpec.h"

//THelpList(HWND ParentWindow):TListBox(ParentWindow){};
//---------------------------------------------------------------------------
class PACKAGE THelpListBox : public TListBox
{
private:
	String FSubString;
	void __fastcall SetSubString(String Value);

	void __fastcall WmOnFontChange(TObject *Sender);
	TNotifyEvent FOnFontChange;
	TNotifyEvent OldOnFontChange;

protected:
public:
	TRichEditSpec* JoinSpec;
	__fastcall THelpListBox(TComponent* Owner);
    void __fastcall Close();
__published:
	__property String SubString = {read=FSubString, write=SetSubString};
    __property TNotifyEvent __fastcall OnFontChange={read=FOnFontChange, write=FOnFontChange};
};
//---------------------------------------------------------------------------
#endif
