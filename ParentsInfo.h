//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ParentInfoH
#define ParentInfoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "TParent.h"
#include "TTreeBaseList.h"
#include "TComboBoxSpec.h"
#include "TEditSpec.h"
#include <ExtCtrls.hpp>


//---------------------------------------------------------------------------
class TParentsInfoForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TPanel *Panel2;
	TButton *CancelButton;
	TButton *Button1;
	TListBox *ListBox1;
	TPanel *Panel3;
	TLabel *Label1;
	TEdit *FIOEdit;
	TPanel *Panel4;
	TLabel *Label2;
	TEdit *AgeEdit;
	TPanel *Panel5;
	TLabel *Label3;
	TComboBoxSpec *EducationBoxSpec;
	TPanel *Panel6;
	TLabel *Label4;
	TEditSpec *WorkEditSpec;
	TSpeedButton *SpeedButton1;
	TPanel *Panel7;
	TComboBoxSpec *BadHabitBoxSpec;
	TLabel *Label5;
	TPanel *Panel1;
	TLabel *Label6;
	TComboBoxSpec *BadStrainBoxSpec;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FIOEditChange(TObject *Sender);
	void __fastcall AgeEditChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall BoxSpecAfterSetItemID(TObject *Sender);
	void __fastcall BoxSpecSelect(TObject *Sender);
	void __fastcall ListBox1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TParent *ThisParent;
	TParent **PThisParent;
	__fastcall TParentsInfoForm(TComponent* Owner);
	void FillAllBox();
	void FillChildren();
	void ClearChildren();
	/*void FillBox(String ID, TTreeBaseList *list, TComboBox *box);
	void BoxItemByID(String ID, TComboBox* box); */
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TParentsInfoForm *ParentsInfoForm;
//---------------------------------------------------------------------------
#endif
