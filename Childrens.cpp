//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Childrens.h"
#include "Main.h"
#include "TChildrenList.h"
#include "ChildrenInfo.h"
#include "ExtFunctions.h"
#include "Protocol.h"
#include "Progress.h"
#include "TAutoSize.h"
#include "ImagesDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildrensForm *ChildrensForm;

extern TChildrenList* Childrens;

//---------------------------------------------------------------------------
__fastcall TChildrensForm::TChildrensForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChildrensForm::FormShow(TObject *Sender)
{
	iFind = 0;
	if (Childrens->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = Childrens->Count;

	if (RowOnShow >= 0 && RowOnShow < dg->RowCount) {
		dg->Row = RowOnShow;
	}

}
//---------------------------------------------------------------------------
void __fastcall TChildrensForm::FormResize(TObject *Sender)
{
//	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - dg->ColWidths[0] - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------


void __fastcall TChildrensForm::dgDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= Childrens->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 1, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 1, Childrens->Children[ARow]->Descr);
			/*c->TextOutA(Rect.left + 250, Rect.top + 1, Childrens->Children[ARow]->Birthday.DateString());
			c->TextOutA(Rect.left + 350, Rect.top + 1, Childrens->Children[ARow]->Area);*/
			break;
		default:
			c->FillRect(Rect);
	}
}
//---------------------------------------------------------------------------


void __fastcall TChildrensForm::dgDblClick(TObject *Sender)
{
	TChildren *child = NULL;

	if (Childrens->Count > dg->Row)
		child = Childrens->Children[dg->Row];
	if (child == NULL)
		return;

	if (SenderProtocol)	{
//		FIORichEdit->ItemID = child->ID;
		ProtocolForm->FillChild(child);
		/*FIORichEdit->Text = child->Descr;
		FIORichEdit->ItemID = child->ID;
		BirthdayDateTimePicker->Date = child->Birthday;
		AreaRichEdit->ItemID = child->AreaID;
		AdressRichEdit->Text = child->Adress;
		WhereStudyRichEdit->Text = child->PlaceStudy;
		HistoryStudyRichEdit->Text = child->History;
		ExtInfoRichEdit->Text = child->ExtInfo;*/
		Close();
		return;

	}

//	ChildrenInfoForm->PChildren = (TChildren**)Childrens->GetPointer(dg->Row);
/*
    	ChildrenInfoForm->Children = new TChildren(Childrens->Children[dg->Row]);
    	if (ChildrenInfoForm->ShowModal() == mrOk)	{
    		delete Childrens->Children[dg->Row];
    		Childrens->SetItem(dg->Row, ChildrenInfoForm->Children);
    	}
    	else
			delete ChildrenInfoForm->Children;
*/

	ChildrenInfoForm->Children = Childrens->Children[dg->Row];
	if (ChildrenInfoForm->Visible == true)	{
		ChildrenInfoForm->GetRecord();
		ChildrenInfoForm->SetFocus();
	}
	else
    	ChildrenInfoForm->Show();
}
//---------------------------------------------------------------------------



void __fastcall TChildrensForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	FIORichEdit = NULL;
	BirthdayDateTimePicker = NULL;
	SexComboBox = NULL;
	AreaRichEdit = NULL;
	AdressRichEdit = NULL;
	WhereStudyRichEdit = NULL;
	HistoryStudyRichEdit = NULL;
	ExtInfoRichEdit = NULL;
	SenderProtocol = 0;
	RowOnShow = -1;
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	int h;
	TStringGrid* g = ((TStringGrid*)(Sender));
	h = (g->RowCount - g->Height/g->DefaultRowHeight) - g->FixedRows;
	Handled = false;
	if (g->TopRow <= h) {
	g->TopRow = g->TopRow + 5;
	}
	Handled = true;
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > 5 + g->FixedRows)
		g->TopRow = g->TopRow - 5;
	else
		g->TopRow = 0;
	Handled = true;
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::ToolButton1Click(TObject *Sender)
{
	ChildrenInfoForm->Children = new TChildren(2, 0, 0);
	if (ChildrenInfoForm->ShowModal() == mrOk)	{
		Childrens->Add(ChildrenInfoForm->Children);
		if (Childrens->Count == 0)
			dg->RowCount = 1;
		else
			dg->RowCount = Childrens->Count;

		dg->Repaint();
	}
	else
       delete ChildrenInfoForm->Children;
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::ToolButton2Click(TObject *Sender)
{
	String text, caption;

	text = "Вы действительно хотите удалить \"" + Childrens->Children[dg->Row]->Descr + "\"?";
	caption = "Удаление";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)
		if (Childrens->Children[dg->Row]->DeleteFromDB() == -1)
			ShowMessage("Записть не удалена т.к. используется в протоколах.");
		else	{
			Childrens->Delete(dg->Row);
			FormShow(Sender);
			dg->Repaint();
		}
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::Edit1Enter(TObject *Sender)
{
    iFind = 0;
	Edit1->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TChildrensForm::Edit1Change(TObject *Sender)
{
	int i, p;
	TChildren *c;


	for (i = 0; i < Childrens->Count; i++) {
		c = Childrens->Children[i];
		if (c->Descr.Pos(Edit1->Text)) {
			dg->Row = i;
			iFind = i + 1;
			return;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::Edit1Exit(TObject *Sender)
{
	Edit1->Text = "Поиск";	
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::ToolButton4Click(TObject *Sender)
{
	int i, p;
	TChildren *c;
	String s1, s2;
	int Cycle = 0;

	s1 = Edit1->Text.LowerCase();
	while (Cycle < 2)	{
		for (i = iFind; i < Childrens->Count; i++) {
			c = Childrens->Children[i];
			s2 = c->Descr.LowerCase();
			if (s2.Pos(s1)) {
				dg->Row = i;
				iFind = i + 1;
				return;
			}
		}
		iFind = 0;
		Cycle++;
	}
	Caption = ToolBar1->ButtonHeight;
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::FormCreate(TObject *Sender)
{
	RowOnShow = -1;	
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::FormKeyPress(TObject *Sender, char &Key)
{
	switch ((int)Key) {
	case 13:
		dgDblClick(Sender);
		break;
	default:
		if (!Edit1->Focused()) {
			Edit1->SetFocus();
			Edit1->Text = String(Key);
			Edit1->SelStart = Edit1->Text.Length();
		}
		;
	}
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	switch (Key) {
	case 38:
		if (dg->Row > dg->FixedRows )
			dg->Row = dg->Row - 1;
		break;
	case 40:
		if (dg->Row < dg->RowCount - 1)
			dg->Row = dg->Row + 1;
		break;
	}

}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::ToolButton6Click(TObject *Sender)
{
	Childrens->ReloadList();	
}
//---------------------------------------------------------------------------

void __fastcall TChildrensForm::ChangeFont(TFont *f)
{
	int w;

	Font->Assign(f);
	w = Canvas->TextWidth(IntToStr(Childrens->Count) + "T");
	dg->ColWidths[0] = w;
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	ToolBarAutoSizeLevelDown(ToolBar1);
	DrawGridRowsAutoHeigth(dg, (TImageList*)ToolBar1->Images);
}
