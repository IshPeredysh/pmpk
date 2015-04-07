//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Journ.h"
#include "DM2Unit.h"
#include "Protocol.h"
#include "TChildrenList.h"
#include "Progress.h"
#include "DigitConvertion.h"
#include "FileINI.h"
#include "MouseWheelUnit.h"
#include "TAutoSize.h"
#include "ImagesDM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MOUSEWHEEL 5

TJournForm *JournForm;
extern TChildrenList* Childrens;

//---------------------------------------------------------------------------
__fastcall TJournForm::TJournForm(TComponent* Owner)
	: TForm(Owner)
{
}


void TJournForm::FillGrid()
{
	int r;
	TADOQuery *q = DM->JournQuery;
	TProtocol *p;

    ClearGrid();
	sg->Cells[1][0] = "Дата";
	sg->Cells[2][0] = "Номер";
	sg->Cells[3][0] = "Ребёнок";

	q->Parameters->ParamByName("Date1")->Value = DateTimePicker1->Date;
	q->Parameters->ParamByName("Date2")->Value = DateTimePicker2->Date;
	q->Open();
	q->First();
	r = 1;
	while (!q->Eof)	{
		sg->Objects[0][r] = (TObject*)new TProtocol(q);
		q->Next();
		r++;
	}
	if (r < 2)
		sg->RowCount = 2;
	else
		sg->RowCount = r;
	q->Close();

	sg->Repaint();
}

void TJournForm::ClearGrid()
{
	int i;

	try {
		for (i = 0; i < sg->RowCount; i++) {
			delete (TProtocol*)sg->Objects[0][i];
            sg->Objects[0][i] = NULL;
		}
	} catch (...) {
		return;
	}

/*
    	try {
    		for (i = 0; i < sg->RowCount; i++) {
    			delete (int*)sg->Objects[0][i];
    			delete (int*)sg->Objects[1][i];
    		}
    	} catch (...) {
    		return;
		}
*/

}
//---------------------------------------------------------------------------
void __fastcall TJournForm::sgDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	TCanvas *c = sg->Canvas;
	TChildren *child;
	TProtocol *p;
	int id, Img;

	if (sg->Objects[0][ARow] == NULL)
    	return;

	if (ARow > 0) {
		p = (TProtocol*)sg->Objects[0][ARow];
		if (sg->Objects[0][ARow] != NULL)
			switch (ACol) {
			case 0:
				if (p->AppointmentID >= 1 && p->AppointmentID <= 7)
					Img = ANCHOR_IMG;
				else
					Img = STRING_IMG;

				ImageList->Draw(c, Rect.left, Rect.top, Img, true);
				break;
			case 1:
				c->TextOutA(Rect.left + 2, Rect.top + 2, p->Date.DateString());
				break;
			case 2:
				c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(p->DocNo));
				break;
			case 3:
				id = p->ChildID;
				child = (TChildren*)Childrens->ItemByID(id);
				if (child != NULL)
					c->TextOutA(Rect.left + 2, Rect.top + 2, child->Descr);
				else
					c->TextOutA(Rect.left + 2, Rect.top + 2, "Не указан");
				break;
			}
	}
}

int __fastcall TJournForm::RowByIDDoc(int IDDoc)
{
	int i;
	TProtocol *p;
	
	for (i = sg->FixedRows; i < sg->RowCount; i++) {
		p = (TProtocol*)sg->Objects[0][i];
		if (p == NULL)
			continue;
		if (p->IDDoc == IDDoc)
			return i;
	}
	return -1;
}

//---------------------------------------------------------------------------
void __fastcall TJournForm::sgDblClick(TObject *Sender)
{
	TProtocol *p = (TProtocol*)sg->Objects[0][sg->Row];

	if (p == NULL)
		return;

//	ProtocolForm->prot = p;
	/*if (ProtocolForm->Visible)
		ProtocolForm->OnFormClose();  */
//		ProtocolForm->FormClose(Sender, caNone);
	if (ProtocolForm->Visible)
		ProtocolForm->prot->ProtocolClose();
	if (ProtocolForm->GetProtocol(p))
		ProtocolForm->Show();
	else
		ShowMessage("Не возможно открыть протокол. \nВозможно он уже не существует. Обновите список и повторите попытку.");
}

void TJournForm::AddProtocolToGrid(TProtocol *p, int row)
{
		sg->Objects[0][row] = (TObject*)p;
		sg->Cells[1][row] = p->Date.DateString();
		sg->Cells[2][row] = IntToStr(p->DocNo);
}

int TJournForm::GetProtocolCount()
{
	int i, cnt = 0;;

	for (i = 0; i < sg->RowCount; i++) 
		if ((TProtocol*)sg->Objects[0][i] != NULL)
			cnt++;
	return cnt;
}

int TJournForm::AddProtocol()
{
	TProtocol *NewProtocol = new TProtocol();
	delete NewProtocol;
	FillGrid();
	/*sg->RowCount = sg->FixedRows + GetProtocolCount() + 1;
	sg->Objects[0][sg->RowCount - 1] = (TObject*)NewProtocol;
	sg->Repaint();
	sg->Row = sg->RowCount - 1; */

	return 1;
}

/*int TJournForm::AddProtocol()
{
	int iMaxID, r, LastDocNo;
	TDateTime NowDate;

	DM2->JournInsertQuery->Parameters->ParamByName("IDJOURNAL")->Value = "   F";

	DM2->JournGetMaxQuery->Open();
	iMaxID = DM2->JournGetMaxQuery->FieldByName("MaxID")->AsInteger;
	DM2->JournGetMaxQuery->Close();
	iMaxID++;

	DM2->JournInsertQuery->Parameters->ParamByName("newIDDOC")->Value = iMaxID;
	DM2->JournInsertQuery->Parameters->ParamByName("IDDOCDEF")->Value = "   E";
	DM2->JournInsertQuery->Parameters->ParamByName("APPCODE")->Value = 0;
	NowDate = Now();
	DM2->JournInsertQuery->Parameters->ParamByName("FDATE")->Value = NowDate;
	DM2->JournInsertQuery->Parameters->ParamByName("FTIME")->Value = "";
	DM2->JournInsertQuery->Parameters->ParamByName("DNPREFIX")->Value = "";

	DM2->JournGetDocNoQuery->Open();
	LastDocNo = DM2->JournGetDocNoQuery->FieldByName("newDOCNO")->AsInteger;
	DM2->JournGetDocNoQuery->Close();
	LastDocNo++;

	DM2->JournInsertQuery->Parameters->ParamByName("newDOCNO")->Value = LastDocNo;
	DM2->JournInsertQuery->Parameters->ParamByName("CLOSED")->Value = 0;
	DM2->JournInsertQuery->Parameters->ParamByName("ISMARK")->Value = " ";
	DM2->JournInsertQuery->Parameters->ParamByName("ACTCNT")->Value = "";
	DM2->JournInsertQuery->Parameters->ParamByName("newVERSTAMP")->Value = 0;

	DM2->JournInsertQuery->ExecSQL();

	sg->RowCount = sg->RowCount + 1;
	r = sg->RowCount - 1;
	sg->Objects[0][r] = (TObject*)new int(iMaxID);
	sg->Objects[1][r] = (TObject*)new int(0);
	sg->Cells[1][r] = DateToStr(NowDate);
	sg->Cells[2][r] = IntToStr(LastDocNo);

	return iMaxID;
}   */

//---------------------------------------------------------------------------


void __fastcall TJournForm::ToolButton1Click(TObject *Sender)
{
	AddProtocol();
}
//---------------------------------------------------------------------------

void TJournForm::SaveINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));

	file->WriteDate("JournDate", "Date1", DateTimePicker1->Date);
	file->WriteDate("JournDate", "Date2", DateTimePicker2->Date);
	file->WriteInteger("JournDate", "CurrentYear", CurrentYearCheckBox->Checked);
	file->Free();
}

void TJournForm::LoadINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));
	TStringList *list = new TStringList;

	file->ReadSectionValues("JournDate", list);
	DateTimePicker1->Date = file->ReadDate("JournDate", "Date1", Now());
	DateTimePicker2->Date = file->ReadDate("JournDate", "Date2", Now());
	CurrentYearCheckBox->Checked = file->ReadInteger("JournDate", "CurrentYear", 1);

	delete file, list;
}

void __fastcall TJournForm::ToolButton2Click(TObject *Sender)
{
	FillGrid();
	sg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TJournForm::sgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*int h;
	TStringGrid* g = ((TStringGrid*)(Sender));
	h = (g->RowCount - g->Height/g->DefaultRowHeight) - g->FixedRows;
	Handled = false;
	if (g->TopRow <= h) {
	g->TopRow = g->TopRow + MOUSEWHEEL;
	}
	Handled = true;*/
	sgMouseWheelDownA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TJournForm::sgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > MOUSEWHEEL + g->FixedRows)
		g->TopRow = g->TopRow - MOUSEWHEEL;
	else
		g->TopRow = 1;
	Handled = true; */
	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------
void __fastcall TJournForm::GridRowDelete(int Row)
{
	int r, c, ProtCount;

	delete (TProtocol*)sg->Objects[0][Row];
	sg->Objects[0][Row] = NULL;

	for (r = Row; r < sg->RowCount - 1; r++) {
		for (c = 0; c < sg->ColCount; c++)
			sg->Cells[c][r] = sg->Cells[c][r + 1];
		sg->Objects[0][r] = sg->Objects[0][r + 1];
		sg->Objects[0][r + 1] = NULL;
	}
	sg->Objects[0][r] = NULL;

	ProtCount = GetProtocolCount();
	if (ProtCount == 0)
		ProtCount++;

	sg->RowCount =  sg->FixedRows + ProtCount;

}

void __fastcall TJournForm::ToolButton4Click(TObject *Sender)
{
	TADOQuery *q;
	int KolRec, DocOpened;
	String FIO;
	TProtocol *prot = (TProtocol*)(sg->Objects[0][sg->Row]);
	if (prot == NULL)
		return;

	TChildren *child = (TChildren*)Childrens->ItemByID(prot->ChildID);
	if (child != NULL)
		FIO = child->Descr;
	else
		FIO = "Не указан";

	String text = "Удалить протокол № " + IntToStr(prot->DocNo) + ", дата: '" + DateToStr(prot->Date) +
					"', ребёнок: '" + FIO + "'?";
	String caption = "Удаление";

	q = DM->AppointJournCheckAllQuery;
	q->Parameters->ParamByName("IDDoc")->Value = prot->IDDoc;
	q->Open();
	DocOpened = q->RecordCount;
	q->Close();

	if (/*ProtocolForm->Visible && ProtocolForm->prot->IDDoc == prot->IDDoc && */DocOpened) {
		ShowMessage("Невозможно удалить. В данный момент протокол используется. \nЗакройте окно, которое использует выбранный протокол, и повторите попытку.");
		return;
	}

	if (Application->MessageBox(text.c_str(), caption.c_str(), MB_YESNO) == 6)
	{
		if ((KolRec = prot->DeleteProtocol()) != 1)	{
			ShowMessage("Ошибка при удалении. Удалено " + IntToStr(KolRec) + "записей.");
			ProtocolForm->Close();
			FillGrid();
			sg->Repaint();
		}
		else	{
			GridRowDelete(sg->Row);
			FillGrid();
		}

	}

}
//---------------------------------------------------------------------------


void __fastcall TJournForm::CurrentYearCheckBoxClick(TObject *Sender)
{
	TDate date;
	unsigned short int yy, mm, dd;

	if (CurrentYearCheckBox->Checked == true) {
		date = Now();
		DecodeDate(Now(), yy, mm, dd);
		mm = 1;
		dd = 1;
		DateTimePicker1->Date = EncodeDate(yy, mm, dd);
		DateTimePicker1->Enabled = false;
		mm = 12;
		dd = MonthDays[IsLeapYear(yy)][12];
		DateTimePicker2->Date = EncodeDate(yy, mm, dd);
		DateTimePicker2->Enabled = false;
	}
	else	{
		DateTimePicker1->Enabled = true;
		DateTimePicker2->Enabled = true;
    }
    ToolButton2Click(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TJournForm::FormShow(TObject *Sender)
{
	JournForm->FillGrid();
}
//---------------------------------------------------------------------------

void __fastcall TJournForm::ChangeFont(TFont *f)
{
	JournForm->Font->Assign(f);
	ImageList = ImageListByFont(f, Images->ImageList1, Images->ImageList2, Images->ImageList3);
	DrawGridRowsAutoHeigth(sg, ImageList);
	sg->ColWidths[0] = ImageList->Width + 4;
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	ToolBarAutoSizeLevelDown(ToolBar2);

}
