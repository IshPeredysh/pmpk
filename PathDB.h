//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef PathDBH
#define PathDBH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TPathDBForm : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TSpeedButton *SpeedButton1;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPathDBForm(TComponent* Owner);
	void __fastcall SaveINI();
	void __fastcall LoadINI();
};
//---------------------------------------------------------------------------
extern PACKAGE TPathDBForm *PathDBForm;
//---------------------------------------------------------------------------
#endif
