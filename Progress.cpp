//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Progress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
__fastcall TProgressForm::TProgressForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TProgressForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (!CanClose) {
		Action = caNone;
	}
	else
    	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TProgressForm::FormShow(TObject *Sender)
{
	PointsCount = 0;
	Timer1->Enabled = true;
	CanClose = false;
}
//---------------------------------------------------------------------------

String TProgressForm::RunPoints()
{
	String str = "";
	int i;

	i = 0;
	while (i < PointsCount)	{
		str += ".";
		i++;
	}

	PointsCount++;
	if (PointsCount > 5) {
    	PointsCount = 0;
	}
    return str;
}


void __fastcall TProgressForm::Timer1Timer(TObject *Sender)
{
	Label1->Caption = LabelText + RunPoints();
}
//---------------------------------------------------------------------------

void __fastcall TProgressForm::FormCreate(TObject *Sender)
{
	ProgressForm->LabelText = "Загрузка.";
	ProgressForm->Show();

}
//---------------------------------------------------------------------------

void TProgressForm::SetLabelText(String Value)
{
	FLabelText = Value;
	Label1->Caption = Value;
	Application->ProcessMessages();
}

