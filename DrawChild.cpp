//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DrawChild.h"
#include "MouseWheelUnit.h"
#include "ChildrenInfo.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDrawChildForm *DrawChildForm;


//---------------------------------------------------------------------------
__fastcall TDrawChildForm::TDrawChildForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (DrawList == NULL || ARow < 0 || ARow >= DrawList->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 1, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 1, DrawList->Children[ARow]->Descr);
			/*c->TextOutA(Rect.left + 250, Rect.top + 1, DrawList->Children[ARow]->Birthday.DateString());
			c->TextOutA(Rect.left + 350, Rect.top + 1, DrawList->Children[ARow]->Area);*/
			break;
		default:
			c->FillRect(Rect);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::FormCreate(TObject *Sender)
{
	DrawList = NULL;	
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::FormClose(TObject *Sender, TCloseAction &Action)
{
//	DrawList = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::FormShow(TObject *Sender)
{

	if (DrawList->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = DrawList->Count;
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - COLW_0 - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::dgMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	sgMouseWheelDownA(Sender, Shift, MousePos, Handled);	
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::dgMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------
void __fastcall TDrawChildForm::dgDblClick(TObject *Sender)
{
	ChildrenInfoForm->Children = DrawList->Children[dg->Row];
	if (ChildrenInfoForm->Visible == true)	{
		ChildrenInfoForm->GetRecord();
		ChildrenInfoForm->SetFocus();
	}
	else
		ChildrenInfoForm->Show();
}
//---------------------------------------------------------------------------
