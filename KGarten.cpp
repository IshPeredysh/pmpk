//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KGarten.h"
#include "TBaseEmptyList.h"
#include "DMUnit.h"
#include "TAttrAppoint.h"
#include "Progress.h"
#include "TThreadProgress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"

#pragma resource "*.dfm"
TKGartenForm *KGartenForm;
extern TBaseEmptyList *KGartenTypeList;
//---------------------------------------------------------------------------
__fastcall TKGartenForm::TKGartenForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKGartenForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
	  TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= KGartenTypeList->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, KGartenTypeList->Items[ARow]->Descr);
//        	c->TextOutA(Rect.left + 2, Rect.top + 2, KGartenTypeList->VisibleItems[ARow]->Descr);
			break;
		default:
			c->FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
void __fastcall TKGartenForm::FormShow(TObject *Sender)
{
	TADOQuery *q;

	q = DM->KGartenTypeSelectQuery;
	KGartenTypeList->RemoveItems();
	q->Open();
	KGartenTypeList->FillFromDB(q);
	q->Close();
	KGartenTypeList->SortByDescr();

	if (KGartenTypeList->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = KGartenTypeList->Count;
}
//---------------------------------------------------------------------------
void __fastcall TKGartenForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - COLW_0 - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------



void __fastcall TKGartenForm::dgDblClick(TObject *Sender)
{
	if (SetRichEdit != NULL)	{
		SetRichEdit->ItemID = KGartenTypeList->Items[dg->Row]->ID;
		Close();
	}

	if (SetEdit != NULL)	{
		SetEdit->ItemID = KGartenTypeList->Items[dg->Row]->ID;
		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TKGartenForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
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

void __fastcall TKGartenForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
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


void __fastcall TKGartenForm::AddStringButtonClick(TObject *Sender)
{
	TBaseEmpty *NewItem = NULL;
	String str = "";

	str = InputBox("Добавление вида детского сада.", "Введите название вид детского сада", "");
	if (str == "")
		return;

	NewItem = (TBaseEmpty*)KGartenTypeList->ItemByDescr(str);
	if (NewItem != NULL) {
		ShowMessage("Вид детского сада с таким название уже существует. Новый вид детского сада не добавлен.");
		return;
	}

	NewItem = new TBaseEmpty(0);
	NewItem->Descr = str;
	NewItem->Save(DM->KGartenTypeGetMaxQuery, DM->KGartenTypeInsertQuery, NULL, NULL);
	KGartenTypeList->Add(NewItem);
	FormShow(Sender);
	dg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TKGartenForm::EditButtonClick(TObject *Sender)
{
	EditItem = (TBaseEmpty*)KGartenTypeList->Items[dg->Row];
	String str = "";
	String tmp = EditItem->Descr;

	str = InputBox("Изменение \"Вид детского сада\".", "Введите новое название для Вид детского сада", EditItem->Descr);
	if (str == "")
		return;

	EditItem->Descr = str;
	try {
		EditItem->UpdateDB(DM->KGartenTypeUpdateQuery);
	} catch (...) {
		ShowMessage("Не удалось переименовать. Вид детского сада с таким названием уже существует.");
		EditItem->Descr = tmp;
	}

	/*dg->Options = dg->Options << goEditing;
	dg->EditorMode = true;*/
}
//---------------------------------------------------------------------------

void __fastcall TKGartenForm::dgExitEdit(TObject *Sender)
{
	EditItem->UpdateDB(DM->KGartenTypeUpdateQuery);
	dg->Options = dg->Options >> goEditing;
}
//---------------------------------------------------------------------------


void __fastcall TKGartenForm::dgGetEditText(TObject *Sender, int ACol, int ARow,
      AnsiString &Value)
{
	Value = EditItem->Descr;	
}
//---------------------------------------------------------------------------

void __fastcall TKGartenForm::dgSetEditText(TObject *Sender, int ACol, int ARow,
	  const AnsiString Value)
{
	EditItem->Descr = Value;
}
//---------------------------------------------------------------------------


int __fastcall DelKGartenType()
{
	int r = 0;
	__try	{
		r = KGartenTypeList->DeleteItemFromDB(KGartenForm->DelItem, DM->KGartenTypeDeleteQuery);
	}
	__finally	{
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		return r;
	}
}

void __fastcall RefreshGridKGartenType()
{
	KGartenForm->FormShow(KGartenForm);
}


void __fastcall TKGartenForm::DeleteButtonClick(TObject *Sender)
{

	String text;
	String caption = "Удаление";
	TThreadProgress* thread;

	DelItem = (TBaseEmpty*)KGartenTypeList->Items[dg->Row];
	text = "Вы действительно хотите удалить \"" + DelItem->Descr + "\"?";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)	{
		ProgressForm->LabelText = "Удаление \"" + DelItem->Descr + "\"";
		ProgressForm->Show();

		thread = new TThreadProgress(true);
		thread->Func = &DelKGartenType;
		thread->RefreshFunc = &RefreshGridKGartenType;
		thread->FreeOnTerminate;
		thread->Resume();
	}
	
}
//---------------------------------------------------------------------------

