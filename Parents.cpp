//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Parents.h"
#include "TParentList.h"
#include "ParentsInfo.h"
#include "ExtFunctions.h"
#include "MouseWheelUnit.h"
#include "TAutoSize.h"
#include "ImagesDM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TParentsForm *ParentsForm;

extern TParentList* Parents;
//---------------------------------------------------------------------------
__fastcall TParentsForm::TParentsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TParentsForm::FormShow(TObject *Sender)
{
	TADOQuery *q;

	q = DM->ParentSelectQuery;
	Parents->RemoveItems();
	q->Open();
	Parents->FillFromDB(q);
	q->Close();
	Parents->SortByDescr();

	if (Parents->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = Parents->Count;
	//Caption = IntToStr(Parent);
}
//---------------------------------------------------------------------------
void __fastcall TParentsForm::FormResize(TObject *Sender)
{
//	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = (dg->Width - dg->ColWidths[0] - GetSystemMetrics(SM_CXVSCROLL));
	/*dg->ColWidths[2] = dg->ColWidths[1] / 3;
	dg->ColWidths[3] = dg->ColWidths[1] / 3;
	dg->ColWidths[4] = dg->ColWidths[1] / 3;  */
}
//---------------------------------------------------------------------------
void __fastcall TParentsForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= Parents->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, Parents->Parent[ARow]->Descr);
			break;
		case 2:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, Parents->Parent[ARow]->Education);
			break;
		case 3:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, Parents->Parent[ARow]->BadHabit);
			break;
		case 4:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, Parents->Parent[ARow]->BadStrain);
			break;
		default:
			c->FillRect(Rect);
	}
}
//---------------------------------------------------------------------------


void __fastcall TParentsForm::dgDblClick(TObject *Sender)
{

	TParent *parent;

	parent = Parents->Parent[dg->Row];

	if (SenderChildren)	{
		if (FIOEdit != NULL)	{
			FIOEdit->ItemID = parent->ID;
//			FIOEdit->Text = parent->Descr;
			Close();
			return;
		}
	}
	else if (SenderProtocol)	{

		if (FIORichEdit != NULL)	{
			FIORichEdit->Text = parent->Descr;
            FIORichEdit->ItemID = parent->ID;
		}

		if (AgeRichEdit != NULL)
			AgeRichEdit->Text = parent->Age;

		if (EducationComboBox != NULL)
			BoxItemByID(parent->Education, EducationComboBox);

		if (PlaceWorkRichEdit != NULL)
			PlaceWorkRichEdit->Text = parent->Work;

		if (BadHabitRichComboBox != NULL)
			BoxItemByID(parent->BadHabit, BadHabitRichComboBox);

		if (BadStrainRichComboBox != NULL)
			BoxItemByID(parent->BadStrain, BadStrainRichComboBox);

		if (PlaceWorkRichEdit != NULL)
			PlaceWorkRichEdit->Text = parent->Work;

		Close();
		return;
	}
	else	{
		ParentsInfoForm->ThisParent = Parents->Parent[dg->Row];
		if (ParentsInfoForm->Visible == true)
			ParentsInfoForm->FormShow(Sender);
		else
			ParentsInfoForm->Show();
	}
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	FIORichEdit = NULL;
	AgeRichEdit = NULL;
	EducationComboBox = NULL;
	PlaceWorkRichEdit = NULL;
	BadHabitRichComboBox = NULL;
	BadStrainRichComboBox = NULL;
	SenderProtocol = false;
	SenderChildren = false;
    FIOEdit = NULL;
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*int h;
	TStringGrid* g = ((TStringGrid*)(Sender));
	h = (g->RowCount - g->Height/g->DefaultRowHeight) - g->FixedRows;
	Handled = false;
	if (g->TopRow <= h) {
	g->TopRow = g->TopRow + 5;
	}
	Handled = true;*/
	sgMouseWheelDownA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > 5 + g->FixedRows)
		g->TopRow = g->TopRow - 5;
	else
		g->TopRow = 1;
	Handled = true;*/
	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::ToolButton1Click(TObject *Sender)
{
	ParentsInfoForm->ThisParent = new TParent(0);
	if (ParentsInfoForm->ShowModal() == mrOk)
		Parents->Add(ParentsInfoForm->ThisParent);
	else
       delete ParentsInfoForm->ThisParent;	
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::ToolButton2Click(TObject *Sender)
{
	String text, caption;

	text = "Вы действительно хотите удалить \"" + Parents->Parent[dg->Row]->Descr + "\"?";
	caption = "Удаление";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)
		if (Parents->Parent[dg->Row]->DeleteFromDB() == -1)
			ShowMessage("Записть не удалена т.к. используется в справочнике \"Дети\".");
		else	{
			Parents->Delete(dg->Row);
			FormShow(Sender);
			dg->Repaint();
		}
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::Edit1Change(TObject *Sender)
{
	int i, p;
	TParent *c;


	for (i = 0; i < Parents->Count; i++) {
		c = Parents->Parent[i];
		if (c->Descr.Pos(Edit1->Text)) {
			dg->Row = i;
			iFind = i + 1;
			return;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::Edit1Enter(TObject *Sender)
{
    iFind = 0;
	Edit1->Text = "";	
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::Edit1Exit(TObject *Sender)
{
	Edit1->Text = "Поиск";
}
//---------------------------------------------------------------------------



void __fastcall TParentsForm::ToolButton4Click(TObject *Sender)
{
	int i, Parent;
	TParent *c;

	for (i = iFind; i < Parents->Count; i++) {
		c = Parents->Parent[i];
		if (c->Descr.Pos(Edit1->Text)) {
			dg->Row = i;
			iFind = i + 1;
			return;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TParentsForm::ChangeFont(TFont *f)
{
	int w;

	Font->Assign(f);
	w = Canvas->TextWidth(IntToStr(Parents->Count) + "T");
	dg->ColWidths[0] = w;
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	ToolBarAutoSizeLevelDown(ToolBar1);
	DrawGridRowsAutoHeigth(dg, (TImageList*)ToolBar1->Images);
}
