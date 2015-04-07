//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SchoolType.h"
#include "TBaseEmptyList.h"
#include "DMUnit.h"
#include "Progress.h"
#include "TThreadProgress.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"
TSchoolTypeForm *SchoolTypeForm;

extern TBaseEmptyList *SchoolTypeList;
//---------------------------------------------------------------------------
__fastcall TSchoolTypeForm::TSchoolTypeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSchoolTypeForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= SchoolTypeList->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, SchoolTypeList->Items[ARow]->Descr);
//        	c->TextOutA(Rect.left + 2, Rect.top + 2, SchoolTypeList->VisibleItems[ARow]->Descr);
			break;
		default:
			c->FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
void __fastcall TSchoolTypeForm::FormShow(TObject *Sender)
{
	TADOQuery *q;

	q = DM->SchoolTypeSelectQuery;
	SchoolTypeList->RemoveItems();
	q->Open();
	SchoolTypeList->FillFromDB(q);
	q->Close();
	SchoolTypeList->SortByDescr();

	if (SchoolTypeList->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = SchoolTypeList->Count;
}
//---------------------------------------------------------------------------
void __fastcall TSchoolTypeForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - COLW_0 - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------



void __fastcall TSchoolTypeForm::dgDblClick(TObject *Sender)
{
	if (SetRichEdit != NULL)	{
		SetRichEdit->ItemID = SchoolTypeList->Items[dg->Row]->ID;
		Close();
	}

	if (SetEdit != NULL)	{
		SetEdit->ItemID = SchoolTypeList->Items[dg->Row]->ID;
		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSchoolTypeForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
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

void __fastcall TSchoolTypeForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
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


void __fastcall TSchoolTypeForm::AddStringButtonClick(TObject *Sender)
{
	TBaseEmpty *NewItem = NULL;
	String str = "";

	str = InputBox("Добавление типа школ.", "Введите название школы", "");
	if (str == "")
		return;

	NewItem = (TBaseEmpty*)SchoolTypeList->ItemByDescr(str);
	if (NewItem != NULL) {
		ShowMessage("типа школы с таким название уже существует. Новый тип школы не добавлен.");
		return;
	}

	NewItem = new TBaseEmpty(0);
    NewItem->Descr = str;
	NewItem->Save(DM->SchoolTypeGetMaxQuery, DM->SchoolTypeInsertQuery, NULL, NULL);
	SchoolTypeList->Add(NewItem);
	FormShow(Sender);
	dg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TSchoolTypeForm::EditButtonClick(TObject *Sender)
{
	EditItem = (TBaseEmpty*)SchoolTypeList->Items[dg->Row];
	String str = "";
	String tmp = EditItem->Descr;

	str = InputBox("Изменение типа школы.", "Введите новое название типа школы", EditItem->Descr);
	if (str == "")
		return;

	EditItem->Descr = str;
	try {
		EditItem->UpdateDB(DM->SchoolTypeUpdateQuery);
	} catch (...) {
		ShowMessage("Не удалось переименовать. Тип школы с таким названием уже существует.");
		EditItem->Descr = tmp;
	}

	/*dg->Options = dg->Options << goEditing;
	dg->EditorMode = true;*/
}
//---------------------------------------------------------------------------

void __fastcall TSchoolTypeForm::dgExitEdit(TObject *Sender)
{
	EditItem->UpdateDB(DM->SchoolTypeUpdateQuery);
	dg->Options = dg->Options >> goEditing;
}
//---------------------------------------------------------------------------


void __fastcall TSchoolTypeForm::dgGetEditText(TObject *Sender, int ACol, int ARow,
      AnsiString &Value)
{
	Value = EditItem->Descr;	
}
//---------------------------------------------------------------------------

void __fastcall TSchoolTypeForm::dgSetEditText(TObject *Sender, int ACol, int ARow,
	  const AnsiString Value)
{
	EditItem->Descr = Value;
}
//---------------------------------------------------------------------------


int __fastcall DelSchoolType()
{
	int r = 0;
	__try	{
		r = SchoolTypeList->DeleteItemFromDB(SchoolTypeForm->DelItem, DM->SchoolTypeDeleteQuery);
	}
	__finally	{
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		return r;
	}
}

void __fastcall RefreshGridSchoolType()
{
	SchoolTypeForm->FormShow(SchoolTypeForm);
}


void __fastcall TSchoolTypeForm::DeleteButtonClick(TObject *Sender)
{

	String text;
	String caption = "Удаление";
	TThreadProgress* thread;

	DelItem = (TBaseEmpty*)SchoolTypeList->Items[dg->Row];
	text = "Вы действительно хотите удалить \"" + DelItem->Descr + "\"?";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)	{
		ProgressForm->LabelText = "Удаление \"" + DelItem->Descr + "\"";
		ProgressForm->Show();

		thread = new TThreadProgress(true);
		thread->Func = &DelSchoolType;
		thread->RefreshFunc = &RefreshGridSchoolType;
		thread->FreeOnTerminate;
		thread->Resume();
	}
	
}
//---------------------------------------------------------------------------

