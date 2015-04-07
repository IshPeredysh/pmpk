//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AttrAppoint.h"
#include "TAttrAppointList.h"
#include "MouseWheelUnit.h"
#include <Clipbrd.hpp>
#include "ImagesDM.h"
#include "TAutoSize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"
TAttrAppointForm *AttrAppointForm;
extern TAttrAppointList *AttrAppointList;
//---------------------------------------------------------------------------
__fastcall TAttrAppointForm::TAttrAppointForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAttrAppointForm::FormShow(TObject *Sender)
{
	dg->RowCount = AttrAppointList->Count + 1;
}
//---------------------------------------------------------------------------
void __fastcall TAttrAppointForm::dgDrawCell(TObject *Sender,
	  int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;
	TAttrAppoint* Item;
	int cnt;
	tagRECT r;
	int test;

	r = Rect;

	cnt = AttrAppointList->Count;
	c->FillRect(Rect);

	if (ARow == 0)	{
		c->Font->Style = c->Font->Style << fsBold;
		switch (ACol) {
			case 0:
				DrawText(c->Handle, "Код", 3, &r, DT_CENTER);
//				c->TextOutA(Rect.left + 16 + 2, Rect.top + 2, "Код");
				break;
			case 1:
				DrawText(c->Handle, "Должность", 9, &r, DT_CENTER);
//				c->TextOutA(Rect.left + 2, Rect.top + 2, "Должность");
				break;
			case 2:
				DrawText(c->Handle, "Название", 8, &r, DT_CENTER);
//				c->TextOutA(Rect.left + 2, Rect.top + 2, "Название");
				break;
		}
		c->Font->Style = c->Font->Style >> fsBold;
	}

	try {
        
	if (ARow > 0 && ARow <= cnt) {
		Item = AttrAppointList->Items[ARow - 1];
		if (ARow == 19 && ACol == 1)
			test = 1;

		switch (ACol) {
			case 0:
				c->TextOutA(Rect.left + 2, Rect.top + 2, Item->Descr);
				break;
			case 1:
				c->TextOutA(Rect.left + 2, Rect.top + 2, Item->Appoint);
				break;
			case 2:
				ImageList->Draw(c, Rect.left, Rect.top, STRING_IMG, true);
				c->TextOutA(Rect.left + ImageList->Width + 4, Rect.top + 2, Item->Caption);
				break;
			}
	}
	} catch (...) {
		ShowMessage("Col " + IntToStr(ACol) + ", Row " + IntToStr(ARow));
	}
}
//---------------------------------------------------------------------------
void __fastcall TAttrAppointForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*	int h;
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

void __fastcall TAttrAppointForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*	TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > 5 + g->FixedRows)
		g->TopRow = g->TopRow - 5;
	else
		g->TopRow = 1;
	Handled = true;*/

	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TAttrAppointForm::FormResize(TObject *Sender)
{
	/*float ColWidthsPercent[3];
	int ColWidths[3], i;
	int TotalWidths = 0; */
//	int i, width = (dg->Width - GetSystemMetrics(SM_CXVSCROLL)) / 3;

												 /*- GetSystemMetrics(SM_CXVSCROLL) * 2*/
//	for (i = 0; i < 3; i++)
//		dg->ColWidths[i] = width;
		
	/*for (i = 0; i <= 10; i++) {
		if (dg->ColWidths[i] < 10)
			ColWidths[i] = 10;
		else
			ColWidths[i] = dg->ColWidths[i];
	}

	for (i = 0; i < 3; i++)
		TotalWidths += (ColWidths[i]);

	for (i = 0; i < 3; i++)
		ColWidths[i] = ((ColWidths[i] - 1) * (dg->Width )) / (TotalWidths);

	for (i = 0; i < 3; i++)
		dg->ColWidths[i] = ColWidths[i];    */
}
//---------------------------------------------------------------------------


void __fastcall TAttrAppointForm::EditButtonClick(TObject *Sender)
{
	EditItem = (TAttrAppoint*)AttrAppointList->Items[dg->Row - dg->FixedRows];
	String str = "";
	String tmp = EditItem->Caption;

	str = InputBox("Изменение названия поля.", "Введите новое названия поля", EditItem->Caption);
	if (str == "")
		return;

	EditItem->Caption = str;
	try {
		EditItem->UpdateDB(DM->AttrAppointUpdateQuery);
	} catch (...) {
		ShowMessage("Не удалось переименовать. Произошла ошибка при сохранении.\n \
Изменения не сохранены");
		EditItem->Caption = tmp;
	}
}
//---------------------------------------------------------------------------




void __fastcall TAttrAppointForm::dgMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int row, col;
	TRect rect;

	dg->MouseToCell(X, Y, col, row);
	rect = dg->CellRect(col, row);

	if (col != 2 || row < dg->FixedRows)	{
    	IconClickDown = false;
		return;
	}

	if (rect.left + 2 <= X &&  rect.left + 18 >= X && rect.top <= Y && rect.bottom >= Y)
		IconClickDown = true;
	else	{
		IconClickDown = false;
	}
}
//---------------------------------------------------------------------------


void __fastcall TAttrAppointForm::EditIconClick(TObject *Sender)
{
	EditButtonClick(Sender);
}


void __fastcall TAttrAppointForm::dgMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int row, col;
	TRect rect;

	dg->MouseToCell(X, Y, col, row);
	rect = dg->CellRect(col, row);

	if (col != 2 || row < dg->FixedRows)
		return;

	if (rect.left + 2 <= X &&  rect.left + 18 >= X && rect.top <= Y && rect.bottom >= Y)
	if (IconClickDown == true)	{
		IconClickDown = false;
		EditIconClick(Sender);

	}

}
//---------------------------------------------------------------------------


void __fastcall TAttrAppointForm::dgKeyPress(TObject *Sender, char &Key)
{
	if (Key == 13) {
        EditButtonClick(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TAttrAppointForm::N1Click(TObject *Sender)
{
	TAttrAppoint* Item;
	TClipboard *buff = Clipboard();
	THandle h;
	String s;

	if (dg->Row < dg->FixedRows)
		return;

	Item = (TAttrAppoint*)AttrAppointList->Items[dg->Row - dg->FixedRows];

	switch (dg->Col) {
		case 0:
			s = Item->Descr;
			break;
		case 1:
			s = Item->Appoint;
			break;
		case 2:
			s = Item->Caption;
			break;
		default:
			return;
	}

	buff->Open();
	buff->AsText = s;
	h = buff->GetAsHandle(CF_TEXT);
	SetClipboardData(CF_LOCALE, (void*)h);
	buff->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAttrAppointForm::dgContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
	int c, r;

	dg->MouseToCell(MousePos.x, MousePos.y, c, r);
	if (c >= dg->FixedCols && r >= dg->FixedRows) {
		dg->Row = r;
		dg->Col = c;
	}
	else
		Handled = true; 
}
//---------------------------------------------------------------------------

void __fastcall TAttrAppointForm::ChangeFont(TFont *f)
{
	Font->Assign(f);
	ImageList = ImageListByFont(f, Images->ImageList1, Images->ImageList2, Images->ImageList3);
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	ToolBarAutoSizeLevelDown(ToolBar1);
	DrawGridRowsAutoHeigth(dg, ImageList);
}
