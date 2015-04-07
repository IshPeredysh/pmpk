//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Areas.h"
#include "TTreeBaseEmptyList.h"
#include "DMUnit.h"
#include "Progress.h"
#include "TThreadProgress.h"
#include "TAutoSize.h"
#include "ImagesDM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"

#define MOUSEWHEEL 5

TAreasForm *AreasForm;

extern TTreeBaseEmptyList *AreaList;
//---------------------------------------------------------------------------
__fastcall TAreasForm::TAreasForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAreasForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= AreaList->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, AreaList->Items[ARow]->Descr);
//        	c->TextOutA(Rect.left + 2, Rect.top + 2, AreaList->VisibleItems[ARow]->Descr);
			break;
		default:
			c->FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
void __fastcall TAreasForm::FormShow(TObject *Sender)
{
	TADOQuery *q;

	q = DM->AreaSelectQuery;
	AreaList->RemoveItems();
	q->Open();
	AreaList->FillFromDB(q);
	q->Close();
	AreaList->SortByDescr();

	if (AreaList->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = AreaList->Count;
}
//---------------------------------------------------------------------------
void __fastcall TAreasForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - COLW_0 - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------



void __fastcall TAreasForm::dgDblClick(TObject *Sender)
{
	if (SetRichEdit != NULL)	{
		SetRichEdit->ItemID = AreaList->Items[dg->Row]->ID;
		Close();
	}

	if (SetEdit != NULL)	{
		SetEdit->ItemID = AreaList->Items[dg->Row]->ID;
		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TAreasForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
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

void __fastcall TAreasForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
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


void __fastcall TAreasForm::AddStringButtonClick(TObject *Sender)
{
	TTreeBaseEmpty *NewItem = NULL;
	String str = "";

	str = InputBox("Добавление района.", "Введите название района", "");
	if (str == "")
		return;

	NewItem = (TTreeBaseEmpty*)AreaList->ItemByDescr(str);
	if (NewItem != NULL) {
		ShowMessage("Район с таким название уже существует. Новый район не добавлен.");
		return;
	}

	NewItem = new TTreeBaseEmpty(2, 0, 0);
    NewItem->Descr = str;
	NewItem->Save(DM->AreaGetMaxQuery, DM->AreaInsertQuery, NULL, NULL);
	AreaList->Add(NewItem);
	FormShow(Sender);
	dg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TAreasForm::EditButtonClick(TObject *Sender)
{
	EditItem = (TTreeBaseEmpty*)AreaList->Items[dg->Row];
	String str = "";
	String tmp = EditItem->Descr;

	str = InputBox("Изменение района.", "Введите новое название района", EditItem->Descr);
	if (str == "")
		return;

	EditItem->Descr = str;
	try {
		EditItem->UpdateDB(DM->AreaUpdateQuery);
	} catch (...) {
        ShowMessage("Не удалось переименовать. Район с таким названием уже существует.");
		EditItem->Descr = tmp;
	}

	/*dg->Options = dg->Options << goEditing;
	dg->EditorMode = true;*/
}
//---------------------------------------------------------------------------

void __fastcall TAreasForm::dgExitEdit(TObject *Sender)
{
	EditItem->UpdateDB(DM->AreaUpdateQuery);
	dg->Options = dg->Options >> goEditing;
}
//---------------------------------------------------------------------------


void __fastcall TAreasForm::dgGetEditText(TObject *Sender, int ACol, int ARow,
      AnsiString &Value)
{
	Value = EditItem->Descr;	
}
//---------------------------------------------------------------------------

void __fastcall TAreasForm::dgSetEditText(TObject *Sender, int ACol, int ARow,
	  const AnsiString Value)
{
	EditItem->Descr = Value;
}
//---------------------------------------------------------------------------


int __fastcall DelArea()
{
	int r = 0;
	__try	{
		r = AreaList->DeleteItemFromDB(AreasForm->DelItem, DM->AreaDeleteQuery);
	}
	__finally	{
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		return r;
	}
}

void __fastcall RefreshGridArea()
{
	AreasForm->FormShow(AreasForm);
}


void __fastcall TAreasForm::DeleteButtonClick(TObject *Sender)
{

	String text;
	String caption = "Удаление";
	TThreadProgress* thread;

	DelItem = (TTreeBaseEmpty*)AreaList->Items[dg->Row];
	text = "Вы действительно хотите удалить \"" + DelItem->Descr + "\"?";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)	{
		ProgressForm->LabelText = "Удаление \"" + DelItem->Descr + "\"";
		ProgressForm->Show();

		thread = new TThreadProgress(true);
		thread->Func = &DelArea;
		thread->RefreshFunc = &RefreshGridArea;
		thread->FreeOnTerminate;
		thread->Resume();
	}
	
}
//---------------------------------------------------------------------------

void __fastcall TAreasForm::ChangeFont(TFont *f)
{
	int w;

	Font->Assign(f);
	w = Canvas->TextWidth(IntToStr(AreaList->Count) + "T");
	dg->ColWidths[0] = w;
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	ToolBarAutoSizeLevelDown(ToolBar1);
	DrawGridRowsAutoHeigth(dg, (TImageList*)ToolBar1->Images);
}
