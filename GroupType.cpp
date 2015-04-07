//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GroupType.h"
#include "DMUnit.h"
#include "Progress.h"
#include "TThreadProgress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#include "TBaseEmptyList.h"
#pragma resource "*.dfm"
TGroupTypeForm *GroupTypeForm;

extern TBaseEmptyList *GroupTypeList;
//---------------------------------------------------------------------------
__fastcall TGroupTypeForm::TGroupTypeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGroupTypeForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= GroupTypeList->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, GroupTypeList->Items[ARow]->Descr);
//        	c->TextOutA(Rect.left + 2, Rect.top + 2, GroupTypeList->VisibleItems[ARow]->Descr);
			break;
		default:
			c->FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
void __fastcall TGroupTypeForm::FormShow(TObject *Sender)
{
	TADOQuery *q;

	q = DM->GroupTypeSelectQuery;
	GroupTypeList->RemoveItems();
	q->Open();
	GroupTypeList->FillFromDB(q);
	q->Close();
	GroupTypeList->SortByDescr();

	if (GroupTypeList->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = GroupTypeList->Count;
}
//---------------------------------------------------------------------------
void __fastcall TGroupTypeForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - COLW_0 - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------



void __fastcall TGroupTypeForm::dgDblClick(TObject *Sender)
{
	if (SetRichEdit != NULL)	{
		SetRichEdit->ItemID = GroupTypeList->Items[dg->Row]->ID;
		Close();
	}

	if (SetEdit != NULL)	{
		SetEdit->ItemID = GroupTypeList->Items[dg->Row]->ID;
		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TGroupTypeForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
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

void __fastcall TGroupTypeForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
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


void __fastcall TGroupTypeForm::AddStringButtonClick(TObject *Sender)
{
	TBaseEmpty *NewItem = NULL;
	String str = "";

	str = InputBox("Добавление типа группы.", "Введите название вида группы", "");
	if (str == "")
		return;

	NewItem = (TBaseEmpty*)GroupTypeList->ItemByDescr(str);
	if (NewItem != NULL) {
		ShowMessage("типа группы с таким название уже существует. Новый тип группы не добавлен.");
		return;
	}

	NewItem = new TBaseEmpty(0);
    NewItem->Descr = str;
	NewItem->Save(DM->GroupTypeGetMaxQuery, DM->GroupTypeInsertQuery, NULL, NULL);
	GroupTypeList->Add(NewItem);
	FormShow(Sender);
	dg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TGroupTypeForm::EditButtonClick(TObject *Sender)
{
	EditItem = (TBaseEmpty*)GroupTypeList->Items[dg->Row];
	String str = "";
	String tmp = EditItem->Descr;

	str = InputBox("Изменение типа группы.", "Введите новое название типа группы", EditItem->Descr);
	if (str == "")
		return;

	EditItem->Descr = str;
	try {
		EditItem->UpdateDB(DM->GroupTypeUpdateQuery);
	} catch (...) {
		ShowMessage("Не удалось переименовать. Тип группы с таким названием уже существует.");
		EditItem->Descr = tmp;
	}

	/*dg->Options = dg->Options << goEditing;
	dg->EditorMode = true;*/
}
//---------------------------------------------------------------------------

void __fastcall TGroupTypeForm::dgExitEdit(TObject *Sender)
{
	EditItem->UpdateDB(DM->GroupTypeUpdateQuery);
	dg->Options = dg->Options >> goEditing;
}
//---------------------------------------------------------------------------


void __fastcall TGroupTypeForm::dgGetEditText(TObject *Sender, int ACol, int ARow,
      AnsiString &Value)
{
	Value = EditItem->Descr;	
}
//---------------------------------------------------------------------------

void __fastcall TGroupTypeForm::dgSetEditText(TObject *Sender, int ACol, int ARow,
	  const AnsiString Value)
{
	EditItem->Descr = Value;
}
//---------------------------------------------------------------------------


int __fastcall DelGroupType()
{
	int r = 0;
	__try	{
		r = GroupTypeList->DeleteItemFromDB(GroupTypeForm->DelItem, DM->GroupTypeDeleteQuery);
	}
	__finally	{
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		return r;
	}
}

void __fastcall RefreshGridGroupType()
{
	GroupTypeForm->FormShow(GroupTypeForm);
}


void __fastcall TGroupTypeForm::DeleteButtonClick(TObject *Sender)
{

	String text;
	String caption = "Удаление";
	TThreadProgress* thread;

	DelItem = (TBaseEmpty*)GroupTypeList->Items[dg->Row];
	text = "Вы действительно хотите удалить \"" + DelItem->Descr + "\"?";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)	{
		ProgressForm->LabelText = "Удаление \"" + DelItem->Descr + "\"";
		ProgressForm->Show();

		thread = new TThreadProgress(true);
		thread->Func = &DelGroupType;
		thread->RefreshFunc = &RefreshGridGroupType;
		thread->FreeOnTerminate;
		thread->Resume();
	}
	
}
//---------------------------------------------------------------------------

