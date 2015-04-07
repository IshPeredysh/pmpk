//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ChildrenInfoH
#define ChildrenInfoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "TChildren.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "TEditSpec.h"
#include "TDateTimePickerSpec.h"
#include "TComboBoxSpec.h"
//---------------------------------------------------------------------------
class TChildrenInfoForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel19;
	TButton *CancelButton;
	TButton *SaveButton;
	TButton *Button1;
	TPanel *Panel2;
	TEdit *FIOEdit;
	TLabel *Label2;
	TDateTimePickerSpec *BirthdayPickerSpec;
	TLabel *Label1;
	TPanel *Panel1;
	TLabel *Label3;
	TEditSpec *AreaEditSpec;
	TSpeedButton *AreaButton;
	TEdit *AdressEdit;
	TPanel *Panel3;
	TLabel *Label4;
	TEditSpec *PlaceStudyEditSpec;
	TSpeedButton *SpeedButton1;
	TPanel *Panel4;
	TLabel *Label9;
	TComboBoxSpec *SexBoxSpec;
	TPanel *Panel6;
	TLabel *Label6;
	TEditSpec *FatherEditSpec;
	TSpeedButton *SpeedButton2;
	TLabel *Label7;
	TEditSpec *MotherEditSpec;
	TSpeedButton *SpeedButton3;
	TGridPanel *GridPanel1;
	TPanel *Panel5;
	TLabel *Label5;
	TMemo *HistoryMemo;
	TPanel *Panel7;
	TLabel *Label8;
	TMemo *ExtInfoMemo;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall FIOEditChange(TObject *Sender);
	void __fastcall AreaButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall HistoryMemoChange(TObject *Sender);
	void __fastcall ExtInfoMemoChange(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall EditSpecAfterSetItemID(TObject *Sender);
	void __fastcall BirthdayPickerKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall BirthdayPickerChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SexBoxSpecAfterSetItemID(TObject *Sender);
	void __fastcall SexBoxSpecSelect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TChildren *Children;
	TChildren *TempChildren;
	TChildren **PChildren; // Adress in Childrens;
	__fastcall TChildrenInfoForm(TComponent* Owner);
	void GetRecord();
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TChildrenInfoForm *ChildrenInfoForm;
//---------------------------------------------------------------------------
#endif
