//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lang.h"
#include "TBaseEmptyList.h"
#include "DMUnit.h"
#include "Progress.h"
#include "TThreadProgress.h"
#include "MouseWheelUnit.h"
#include "ImagesDM.h"
#include "TAutoSize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"
TLangForm *LangForm;
extern TBaseEmptyList *LangList;
//---------------------------------------------------------------------------
__fastcall TLangForm::TLangForm(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TLangForm::dgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;

	if (ARow < 0 || ARow >= LangList->Count)
		return;

	switch (ACol) {
		case 0:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(ARow + 1));
			break;
		case 1:
			c->FillRect(Rect);
			c->TextOutA(Rect.left + 2, Rect.top + 2, LangList->Items[ARow]->Descr);
//        	c->TextOutA(Rect.left + 2, Rect.top + 2, LangList->VisibleItems[ARow]->Descr);
			break;
		default:
			c->FillRect(Rect);
	}

}
//---------------------------------------------------------------------------
void __fastcall TLangForm::FormShow(TObject *Sender)
{
	TADOQuery *q;

	q = DM->LangQuery;
	LangList->RemoveItems();
	q->Open();
	LangList->FillFromDB(q);
	q->Close();
	LangList->SortByDescr();

	if (LangList->Count == 0)
		dg->RowCount = 1;
	else
		dg->RowCount = LangList->Count;
}
//---------------------------------------------------------------------------
void __fastcall TLangForm::FormResize(TObject *Sender)
{
	dg->ColWidths[0] = COLW_0;
	dg->ColWidths[1] = dg->Width - COLW_0 - GetSystemMetrics(SM_CXVSCROLL);
}
//---------------------------------------------------------------------------



void __fastcall TLangForm::dgDblClick(TObject *Sender)
{
	if (SetRichEdit != NULL)	{
		SetRichEdit->ItemID = LangList->Items[dg->Row]->ID;
		Close();
	}

	if (SetEdit != NULL)	{
		SetEdit->ItemID = LangList->Items[dg->Row]->ID;
		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TLangForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
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

void __fastcall TLangForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > 5 + g->FixedRows)
		g->TopRow = g->TopRow - 5;
	else
		g->TopRow = 0;
	Handled = true;*/

	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------


void __fastcall TLangForm::AddStringButtonClick(TObject *Sender)
{
	TBaseEmpty *NewItem = NULL;
	String str = "";

	str = InputBox("Добавление языка.", "Введите название языка", "");
	if (str == "")
		return;

	NewItem = (TBaseEmpty*)LangList->ItemByDescr(str);
	if (NewItem != NULL) {
		ShowMessage("Язык с таким название уже существует. Новый язык не добавлен.");
		return;
	}

	NewItem = new TBaseEmpty(0);
    NewItem->Descr = str;
	NewItem->Save(DM->LangGetMaxQuery, DM->LangInsertQuery, NULL, NULL);
	LangList->Add(NewItem);
	FormShow(Sender);
	dg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TLangForm::EditButtonClick(TObject *Sender)
{
	EditItem = (TBaseEmpty*)LangList->Items[dg->Row];
	String str = "";
	String tmp = EditItem->Descr;

	str = InputBox("Изменение языка.", "Введите новое название языка", EditItem->Descr);
	if (str == "")
		return;

	EditItem->Descr = str;
	try {
		EditItem->UpdateDB(DM->LangUpdateQuery);
	} catch (...) {
		ShowMessage("Не удалось переименовать. Язык с таким названием уже существует.");
		EditItem->Descr = tmp;
	}

}
//---------------------------------------------------------------------------

void __fastcall TLangForm::dgExitEdit(TObject *Sender)
{
	EditItem->UpdateDB(DM->LangUpdateQuery);
	dg->Options = dg->Options >> goEditing;
}
//---------------------------------------------------------------------------


void __fastcall TLangForm::dgGetEditText(TObject *Sender, int ACol, int ARow,
      AnsiString &Value)
{
	Value = EditItem->Descr;	
}
//---------------------------------------------------------------------------

void __fastcall TLangForm::dgSetEditText(TObject *Sender, int ACol, int ARow,
	  const AnsiString Value)
{
	EditItem->Descr = Value;
}
//---------------------------------------------------------------------------


int __fastcall DelLang()
{
	int r = 0;
	__try	{
		r = LangList->DeleteItemFromDB(LangForm->DelItem, DM->LangDeleteQuery);
	}
	__finally	{
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		return r;
	}
}

void __fastcall RefreshGridLang()
{
	LangForm->FormShow(LangForm);
}


void __fastcall TLangForm::DeleteButtonClick(TObject *Sender)
{

	String text;
	String caption = "Удаление";
	TThreadProgress* thread;

	DelItem = (TBaseEmpty*)LangList->Items[dg->Row];
	text = "Вы действительно хотите удалить \"" + DelItem->Descr + "\"?";

	if (Application->MessageBoxA(text.c_str(), caption.c_str(), MB_YESNO) == IDYES)	{
		ProgressForm->LabelText = "Удаление \"" + DelItem->Descr + "\"";
		ProgressForm->Show();

		thread = new TThreadProgress(true);
		thread->Func = &DelLang;
		thread->RefreshFunc = &RefreshGridLang;
		thread->FreeOnTerminate;
		thread->Resume();
	}
}
//---------------------------------------------------------------------------


void __fastcall TLangForm::ChangeFont(TFont *f)
{
	int w;

	Font->Assign(f);
	w = Canvas->TextWidth(IntToStr(LangList->Count) + "T");
	dg->ColWidths[0] = w;
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	ToolBarAutoSizeLevelDown(ToolBar1);
	DrawGridRowsAutoHeigth(dg, (TImageList*)ToolBar1->Images);
}
