//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Report.h"


#include "TSpecFieldObject.h"
#include "TTreeBaseEmptyList.h"
#include "FileINI.h"
#include "TListList.h"
#include "Progress.h"
#include "TCreateReportThread.h"
#include "TAttrAppointList.h"
#include "ReportAgeGroups.h"
#include "ReportOrgTypeDistrib.h"
#include "BeforeReport.h"
#include "TDrawBaseList.h"
#include "TChildrenList.h"
#include "TObjMas.h"


extern TChildrenList* Childrens;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReportForm *ReportForm;

extern TTreeBaseEmptyList *OtherObjectList;
extern TListList *ListList;
extern TAttrAppointList *AttrAppointList;
//---------------------------------------------------------------------------
__fastcall TReportForm::TReportForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TReportForm::FillList()
{
	int i;
	TAttrAppoint *Item;
	LoadINI();


    lb->Items->Clear();
	for (i = 0; i < AttrAppointList->Count; i++) {
		Item = (TAttrAppoint*)AttrAppointList->Items[i];
		if (Item->FieldType == ftsRefList || Item->FieldType == ftsRefBox) {
			lb->Items->AddObject(Item->Caption, (TObject*)Item);
		}
	}
}
//---------------------------------------------------------------------------
String TReportForm::GetBoxValue(int ListID, int ItemID)
{
	TTreeBaseEmpty *item;

	item = (TTreeBaseEmpty*)OtherObjectList->ItemByID(ItemID);
	if (item != NULL && item->ParentID == ListID) {
		return item->Descr;
	}
	else
		return "";
//		return "<не заполнено>";
}

String TReportForm::GetListValue(int ListID, int ItemID)
{
	TBase *item;
	TBaseList *list;

	list = (TBaseList*)ListList->GetByListID(ListID);
	if (list == NULL) 
		return "";
//		return "<не найдено>";


	item = (TBase*)list->ItemByID(ItemID);
	if (item != NULL) {
		return item->Descr;
	}
	else
		return "";
//        return "<не заполнено>";
}

String TReportForm::GetValue(TRepField *spec)
{
	switch (spec->FieldType) {
		case ftsRefBox: return GetBoxValue(spec->ListID, spec->ItemID);
		case ftsRefList: return GetListValue(spec->ListID, spec->ItemID);
	default:
		return "";
//		return "<не найдено>";
	}
}

void TReportForm::GetSpec(TRepField *spec, TADOQuery *q)
{
	spec->FieldName = q->FieldByName("sp26")->AsString;
	spec->TextData = q->FieldByName("TextData")->AsString;
	spec->FieldType = q->FieldByName("FieldType")->AsInteger;
	spec->ItemID = q->FieldByName("ItemID")->AsInteger;
	spec->ListID = q->FieldByName("ListID")->AsInteger;
	spec->Count = q->FieldByName("cnt")->AsInteger;

}

//---------------------------------------------------------------------------
void __fastcall TReportForm::CreateReport()
{
	Variant Excel,WorkBooks,Sheet,Cell;
	String FileName = ExtractFilePath(Application->ExeName) + "xlt\\zakl.xlt";
	String str, FieldName, Value, cnt;
	unsigned short int yy, MM, dd;
	int i, FieldType, ListID, ItemID, StartRow = 4;
	TADOQuery *q = DM->ReportGetFieldsValueQuery;
	TDateTime d;
	TRepField spec;
	TAttrAppoint *Item;

	SaveINI();

	if (lb->ItemIndex == -1 && lb->Count == 0) {
		return;
	}

	Item = (TAttrAppoint*)lb->Items->Objects[lb->ItemIndex];
	FieldName = Item->Descr;
	q->Parameters->ParamByName("fdate1")->Value = DateTimePicker1->Date;
	q->Parameters->ParamByName("fdate2")->Value = DateTimePicker2->Date;
	q->Parameters->ParamByName("sp26")->Value = FieldName;
	ProgressForm->LabelText = "Выполнение запроса";
	q->Open();

	try
	{
		ProgressForm->LabelText = "Запуск Excel";
		Excel = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		Application->MessageBox("Невозможно установить соединение с Microsoft Excel.","Ошибка",MB_OK);
		return;
	}

	WorkBooks = Excel.OlePropertyGet("WorkBooks");
	ProgressForm->LabelText = "Создание листа";
	WorkBooks.OleProcedure("Add");
	Sheet = Excel.OlePropertyGet("WorkSheets", 1);


	ProgressForm->LabelText = "Заполнение";
	Sheet.OlePropertyGet("Cells", 2, 2).OlePropertySet("Value", String("Распределение с " + DateTimePicker1->Date.DateString() +
	" по " + DateTimePicker2->Date.DateString()).c_str());

	Sheet.OlePropertyGet("Cells", StartRow, 2).OlePropertySet("Value", FieldName.c_str());
	Sheet.OlePropertyGet("Range", String("B" + IntToStr(StartRow) + ":C" + IntToStr(StartRow)).c_str()).OleProcedure("Select");
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OleProcedure("Merge");
	Sheet.OlePropertyGet("Cells", StartRow + 1, 2).OlePropertySet("Value", "Значение");
	Sheet.OlePropertyGet("Cells", StartRow + 1, 3).OlePropertySet("Value", "Кол-во");
	i = StartRow + 2;
	while (!q->Eof)	{
		GetSpec(&spec, q);
		Value = GetValue(&spec);
		if (Value != "") {
			Sheet.OlePropertyGet("Cells", i, 2).OlePropertySet("Value", Value.c_str());
			Sheet.OlePropertyGet("Cells", i, 3).OlePropertySet("Value", (int)spec.Count);
			i++;
		}
		q->Next();
	}
	Sheet.OlePropertyGet("Columns", "B:C").OlePropertyGet("EntireColumn").OleProcedure("AutoFit");
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertySet("HorizontalAlignment", -4108);
	Sheet.OlePropertyGet("Range", String("B" + IntToStr(StartRow) + ":C" + IntToStr(i - 1)).c_str()).OleProcedure("Select");
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 8).OlePropertySet("LineStyle", 1) ;
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 7).OlePropertySet("LineStyle", 1) ;
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 9).OlePropertySet("LineStyle", 1) ;
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 10).OlePropertySet("LineStyle", 1) ;
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 11).OlePropertySet("LineStyle", 1) ;
	Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 12).OlePropertySet("LineStyle", 1) ;
	Sheet.OlePropertyGet("Range", "A1").OleProcedure("Select");
	q->Close();

	
	q = DM->JournChildCountQuery;
	q->Parameters->ParamByName("fdate1")->Value = DateTimePicker1->Date;
	q->Parameters->ParamByName("fdate2")->Value = DateTimePicker2->Date;
	q->Open();
	cnt = q->FieldByName("cnt")->AsString;
	q->Close();
	Sheet.OlePropertyGet("Cells", i, 2).OlePropertySet("Value", String("Всего: " + cnt).c_str());
//	Selection.Borders(xlEdgeLeft)
//	Range("B2:C11").Select
//	Sheet.OlePropertyGet("Selection").OlePropertySet("Merge", true);
//	Range("B2:C2").Select
//	Selection.Merge
//	Columns("B:C").EntireColumn.AutoFit


	Excel.OlePropertySet("Visible", true);
}

void TReportForm::SaveINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));

	file->WriteDate("ReportDate", "Date1", DateTimePicker1->Date);
	file->WriteDate("ReportDate", "Date2", DateTimePicker2->Date);
	file->WriteInteger("ReportDate", "CurrentYear", CurrentYearCheckBox->Checked);
	file->Free();
}

void TReportForm::LoadINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));
	TStringList *list = new TStringList;

	file->ReadSectionValues("ReportDate", list);
	DateTimePicker1->Date = file->ReadDate("ReportDate", "Date1", Now());
	DateTimePicker2->Date = file->ReadDate("ReportDate", "Date2", Now());
	CurrentYearCheckBox->Checked = file->ReadInteger("ReportDate", "CurrentYear", 1);

	delete file, list;
}
//---------------------------------------------------------------------------

void __fastcall TReportForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	SaveINI();
}
//---------------------------------------------------------------------------

void __fastcall TReportForm::Button1Click(TObject *Sender)
{
	TCreateReportThread *thread = new TCreateReportThread(false);
//    thread->Free();
//	thread->Resume();
}
//---------------------------------------------------------------------------


void __fastcall TReportForm::FormShow(TObject *Sender)
{
	LoadINI();
	FillList();
	FillList(ListBox1);
	FillList(ListBox2);
}
//---------------------------------------------------------------------------




TListItemID* TListItemMas::Add(int ListID, int ItemID, String Caption)
{
	TListItemID* temp = new TListItemID;
	int i;

	temp->ListID = ListID;
	temp->ItemID = ItemID;
	temp->Caption = Caption;

	for (i = 0; i < Count; i++) {
		if (Items[i]->ListID == ListID && Items[i]->ItemID == ItemID)
			return NULL;
	}

	FList->Add(temp);
	return temp;
}

int TListItemMas::IndexByListItem(int ListID, int ItemID)
{
	int i;
	TListItemID* temp;

	for (i = 0; i < FList->Count; i++) {
		if (Items[i]->ListID == ListID && Items[i]->ItemID == ItemID)
			return i;
	}

	return -1;
}

TListItemMas::TListItemMas()
{
	FList = new TList;
}

void __fastcall TReportForm::CleanList(TListBox* box)
{
	int i;

	for (i = 0; i < box->Items->Count; i++) {
		delete box->Items->Objects[i];
	}
	box->Items->Clear();
}

void __fastcall TReportForm::FillList(TListBox* box)
{
//	TADOQuery *q = DM->ReportGetFieldsNameQuery;
	int i;
	int FieldType;
	TAttrAppoint* Item;
	String caption;

	box->Items->Clear();

	for (i = 0; i < AttrAppointList->Count; i++) {
		Item = AttrAppointList->Items[i];
		if (Item->Caption == "")
			caption = Item->Descr;
		else
			caption = Item->Caption;
		box->Items->AddObject(caption, (TObject*)Item);
	}
//	CleanList(box);

	/*q->Open();
	q->First();
	while (!q->Eof)	{
		FieldType = q->FieldByName("fieldtype")->AsInteger;
		if (FieldType == ftsRefBox || FieldType == ftsRefList)
			box->Items->AddObject(q->FieldByName("Caption")->AsString, (TObject*) new String(q->FieldByName("Descr")->AsString));
		q->Next();
	}
	q->Close();*/
}


void TReportForm::GetSpec(TRepField *spec1, TRepField *spec2, TADOQuery *q)
{
	spec1->FieldType = q->FieldByName("FieldType1")->AsInteger;
	spec1->ItemID = q->FieldByName("ItemID1")->AsInteger;
	spec1->ListID = q->FieldByName("ListID1")->AsInteger;
	spec1->Count = q->FieldByName("cnt")->AsInteger;
	spec1->TextData = GetValue(spec1);

	spec2->FieldType = q->FieldByName("FieldType2")->AsInteger;
	spec2->ItemID = q->FieldByName("ItemID2")->AsInteger;
	spec2->ListID = q->FieldByName("ListID2")->AsInteger;
	spec2->Count = q->FieldByName("cnt")->AsInteger;
	spec2->TextData = GetValue(spec2);
}

String DigitToColumn(int d)
{
	const n = 26;
	int t = d;
	int ost;
	String s;

	do	{
		ost = t % n;
		if (s != "") {
			ost--;
		}
		s = String(char( ost + 'A')) + s;
		t = t / n;
	}
	while (t > 0);

	return s;
}

int TReportForm::CreateReport2()
{
	Variant Excel, WorkBooks, Sheet, Cell;
	TListItemMas* Cols;
	TListItemMas* Rows;
	TListItemID* li;
	String FileName;
	String str, FieldName1, FieldName2, FieldValue1, FieldValue2, range, ColsCaption, RowsCaption;
	unsigned short int yy, MM, dd;
	int i, FieldType, ListID1, ItemID1, ListID2, ItemID2, StartRow, StartCol, row, col, cnt;
	TADOQuery *q = DM->Report2GetFieldsValueQuery;
	TDateTime d;
	TRepField spec1, spec2;
	TAttrAppoint* Item;

	SaveINI();

	if (ListBox1->ItemIndex == -1 || ListBox1->Count == 0 ) {
		ShowMessage("Не выбранны строки.");
		return 0;
	}

	if (ListBox2->ItemIndex == -1 || ListBox2->Count == 0 ) {
		ShowMessage("Не выбранны колонки.");
		return 0;
	}

	Item = (TAttrAppoint*)ListBox1->Items->Objects[ListBox1->ItemIndex];
	if (Item == NULL)	{
		ShowMessage("Не выбранны колонки.");
		return 0;
	}
	FieldName1 = Item->Descr;

	Item = (TAttrAppoint*)ListBox2->Items->Objects[ListBox2->ItemIndex];
	if (Item == NULL)
		return 0;
	FieldName2 = Item->Descr;

	q->Parameters->ParamByName("fdate1")->Value = DateTimePicker1->Date;
	q->Parameters->ParamByName("fdate2")->Value = DateTimePicker2->Date;
	q->Parameters->ParamByName("sp26_1")->Value = FieldName1;
	q->Parameters->ParamByName("sp26_2")->Value = FieldName2;
	ProgressForm->LabelText = "Выполнение запроса";
	q->Open();

	try
	{
		ProgressForm->LabelText = "Запуск Excel";
		Excel = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		Application->MessageBox("Невозможно установить соединение с Microsoft Excel.","Ошибка",MB_OK);
		return 0;
	}

	WorkBooks = Excel.OlePropertyGet("WorkBooks");
	ProgressForm->LabelText = "Создание листа";
	WorkBooks.OleProcedure("Add");
	Sheet = Excel.OlePropertyGet("WorkSheets", 1);


	ProgressForm->LabelText = "Заполнение";
/*
		Sheet.OlePropertyGet("Cells", 2, 2).OlePropertySet("Value", String("Распределение с " + DateTimePicker1->Date.DateString() +
		" по " + DateTimePicker2->Date.DateString()).c_str());

		Sheet.OlePropertyGet("Cells", StartRow, 2).OlePropertySet("Value", FieldName.c_str());
		Sheet.OlePropertyGet("Range", String("B" + IntToStr(StartRow) + ":C" + IntToStr(StartRow)).c_str()).OleProcedure("Select");
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OleProcedure("Merge");
		Sheet.OlePropertyGet("Cells", StartRow + 1, 2).OlePropertySet("Value", "Значение");
		Sheet.OlePropertyGet("Cells", StartRow + 1, 3).OlePropertySet("Value", "Кол-во");
*/
//	i = StartRow + 2;

	Cols = new TListItemMas;
	Rows = new TListItemMas;
	spec1.FieldName = FieldName1;
	spec2.FieldName = FieldName2;
	q->First();
	while (!q->Eof)	{
		GetSpec(&spec1, &spec2, q);
		Cols->Add(q->FieldByName("ListID1")->AsInteger, q->FieldByName("ItemID1")->AsInteger, spec1.TextData);
		Rows->Add(q->FieldByName("ListID2")->AsInteger, q->FieldByName("ItemID2")->AsInteger, spec2.TextData);
		q->Next();
	}

	/*
	ListBox1->Items->Clear();
	ListBox2->Items->Clear();

	for (i = 0; i < Cols->Count; i++) {
		li = Cols->Items[i];
		str = Cols->Items[i]->Caption;
		ListBox1->Items->Add(Cols->Items[i]->Caption);
	}

	for (i = 0; i < Rows->Count; i++) {
    	str = Rows->Items[i]->Caption;
		ListBox2->Items->Add(Rows->Items[i]->Caption);
	} */


	spec1.TextData = "";
	spec1.FieldName = FieldName1;
	spec1.FieldType = q->FieldByName("fieldtype1")->AsInteger;
	spec1.ListID = -1;
	spec1.ItemID = -1;
	spec2.TextData = "";
	spec2.FieldName = FieldName2;
	spec2.FieldType = q->FieldByName("fieldtype2")->AsInteger;
	spec2.FieldType = 0;
	spec2.ListID = -1;
	spec2.ItemID = -1;

	row = StartRow  = 7;
	col = StartCol = 2;


	Sheet.OlePropertyGet("Cells", 2, 2).OlePropertySet("Value", String("Распределение с " + DateTimePicker1->Date.DateString() +
	" по " + DateTimePicker2->Date.DateString()).c_str());

	ColsCaption = ListBox1->Items->Strings[ListBox1->ItemIndex];
	RowsCaption = ListBox2->Items->Strings[ListBox2->ItemIndex];
	Sheet.OlePropertyGet("Cells", 4, 2).OlePropertySet("Value", String("Столбцы - " + ColsCaption).c_str());
	Sheet.OlePropertyGet("Cells", 5, 2).OlePropertySet("Value", String("Строки - " + RowsCaption).c_str());

	q->First();

	for (i = 0; i < Cols->Count; i++) {
    	Sheet.OlePropertyGet("Cells", StartRow, StartCol + i + 1).OlePropertySet("Value", Cols->Items[i]->Caption.c_str());
	}

	for (i = 0; i < Rows->Count; i++) {
		Sheet.OlePropertyGet("Cells", StartRow + i + 1, StartCol).OlePropertySet("Value", Rows->Items[i]->Caption.c_str());
	}

	while (!q->Eof)	{
		col = Cols->IndexByListItem(q->FieldByName("ListID1")->AsInteger, q->FieldByName("ItemID1")->AsInteger);
		if (col == -1) {
			ShowMessage("Error!");
			continue;
		}
		row = Rows->IndexByListItem(q->FieldByName("ListID2")->AsInteger, q->FieldByName("ItemID2")->AsInteger);
		if (row == -1) {
			ShowMessage("Error!");
			continue;
		}
		Sheet.OlePropertyGet("Cells", StartRow + row + 1, StartCol + col + 1).OlePropertySet("Value", q->FieldByName("cnt")->AsInteger);
		q->Next();
	}

//		Sheet.OlePropertyGet("Columns", "B:C").OlePropertyGet("EntireColumn").OleProcedure("AutoFit");
//		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertySet("HorizontalAlignment", -4108);

		i = Cols->Count;
		range = DigitToColumn(StartCol - 1) + IntToStr(StartRow) + ":" + DigitToColumn(Cols->Count + StartCol - 1) + IntToStr(StartRow + Rows->Count);
		Sheet.OlePropertyGet("Range", range.c_str()).OleProcedure("Select");
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 8).OlePropertySet("LineStyle", 1) ;
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 7).OlePropertySet("LineStyle", 1) ;
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 9).OlePropertySet("LineStyle", 1) ;
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 10).OlePropertySet("LineStyle", 1) ;
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 11).OlePropertySet("LineStyle", 1) ;
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertyGet("Borders", 12).OlePropertySet("LineStyle", 1) ;

		range = String(DigitToColumn(StartCol - 1) + ":" + DigitToColumn(Cols->Count + StartCol - 1));
		Sheet.OlePropertyGet("Columns", range.c_str()).OleProcedure("Select");
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertySet("ColumnWidth", 18);

		range = String(String(IntToStr(StartRow)) + ":" + IntToStr(StartRow));
		Sheet.OlePropertyGet("Rows", range.c_str()).OleProcedure("Select");
		Sheet.OlePropertyGet("Application").OlePropertyGet("Selection").OlePropertySet("WrapText", true);

		Sheet.OlePropertyGet("Range", "A1").OleProcedure("Select");

//		Columns("D:H").Select
//		Selection.ColumnWidth = 17.57

	q->Close();

	
/*
    	q = DM->JournChildCountQuery;
    	q->Parameters->ParamByName("fdate1")->Value = DateTimePicker1->Date;
    	q->Parameters->ParamByName("fdate2")->Value = DateTimePicker2->Date;
    	q->Open();
    	cnt = q->FieldByName("cnt")->AsString;
    	q->Close();
		Sheet.OlePropertyGet("Cells", i, 2).OlePropertySet("Value", String("Всего: " + cnt).c_str());
*/
//	Selection.Borders(xlEdgeLeft)
//	Range("B2:C11").Select
//	Sheet.OlePropertyGet("Selection").OlePropertySet("Merge", true);
//	Range("B2:C2").Select
//	Selection.Merge
//	Columns("B:C").EntireColumn.AutoFit

	Excel.OlePropertySet("Visible", true);
	return 1;
}

void __fastcall TReportForm::Button4Click(TObject *Sender)
{

	if (!CreateReport2())	{
		ShowMessage("Произошла ошибка при создании отчёта. Отчет не создан.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TReportForm::CurrentYearCheckBoxClick(TObject *Sender)
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
}
//---------------------------------------------------------------------------




void __fastcall TReportForm::Button5Click(TObject *Sender)
{
	TBeforeReportForm *br = BeforeReportForm;

	br->ClearGrid();

	enum {A0_2, A2_6, A7_10, A11_15, A16_18};
	String BaseXls = ExtractFilePath(Application->ExeName) + "xlt\\book.xlsx";
	String FileName, xls, s, str, test;
	String Value = "Hi!", ReplaceValue, FindValue, FieldName;
	int ColCount, RowCount, c, r, p, i, j, CntSpec, sh, SheetCount, y, ID;
	TDateTime date1, date2;
	TDrawBaseList *AgeGroups[5];

	TDateTime RepDate1;
	TDateTime RepDate2;

	TADOQuery* q = DM->BefoReportAgeGroupsQuery;
	RepDate1 = DateTimePicker1->Date;
	RepDate2 = DateTimePicker2->Date;
	br->sg->DefaultColWidth = 90;
    br->ExportExcel = &CreateReportAgeGruops; 

	for (i = 0; i < 5; i++)
		AgeGroups[i] = new TDrawBaseList;

	br->Caption = "Возрастные группы";

	q->Parameters->ParamByName("fdate1")->Value = RepDate1;
	q->Parameters->ParamByName("fdate2")->Value = RepDate2;
	q->Open();

	while (!q->Eof)	{
		date1 = q->FieldByName("Birthday")->AsDateTime;
		date2 = q->FieldByName("FDate")->AsDateTime;
		ID = q->FieldByName("ID")->AsInteger;
		y = GetFullYear(date1, date2);
		if (y >= 0 && y <= 2)
			AgeGroups[A0_2]->Add(Childrens->ItemByID(ID));
		if (y >= 2 && y <= 6)
			AgeGroups[A2_6]->Add(Childrens->ItemByID(ID));
		if (y >= 7 && y <= 10)
			AgeGroups[A7_10]->Add(Childrens->ItemByID(ID));
		if (y >= 11 && y <= 15)
			AgeGroups[A11_15]->Add(Childrens->ItemByID(ID));
		if (y >= 16 && y <= 18)
			AgeGroups[A16_18]->Add(Childrens->ItemByID(ID));
		q->Next();
	}
	r = 0;
	c = 0;
	br->sg->ColCount = c + 5;
	br->sg->RowCount = r + 3;
	br->sg->Cells[c][r + 2] = "Всего " + IntToStr(q->RecordCount);
	q->Close();
	br->sg->Cells[c][r] = "Возраст детей с 0 до 3 лет";
	br->sg->Cells[c + 1][r] = "Возраст детей с 3 до 7 лет";
	br->sg->Cells[c + 2][r] = "Возраст детей с 7 до 11 лет";
	br->sg->Cells[c + 3][r] = "Возраст детей с 11 до 16 лет";
	br->sg->Cells[c + 4][r] = "Возраст детей с 16 до 18 лет";

	for (i = 0; i < 5; i++)	{
		br->sg->Cells[c + i][r + 1] = AgeGroups[i]->Count;
		br->sg->Objects[c + i][r + 1] = (TObject*)new TCellObjList(tlChild, AgeGroups[i]);
	}

    
	br->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TReportForm::Button6Click(TObject *Sender)
{
	TBeforeReportForm *br = BeforeReportForm;

	String FileName, xls, s, str, test;
	String Value = "Hi!", ReplaceValue, FindValue, FieldName;
	String Org, OrgType;
	int ColCount, RowCount, c, r, p, i, j, CntSpec, sh, SheetCount, FirstRow, FirstCol, NullChild;
	int CntChild, OrgTypeID, OrgID, nn, sum, ChildID;
	TDateTime date1, date2, RepDate1, RepDate2;
	TDrawBaseList *List;

	TADOQuery* q = DM->BeforeportOrgTypeDistribQuery;

	FirstRow = 0;
	FirstCol = 0;
	br->sg->DefaultColWidth = 70;
	br->sg->ColWidths[1] = 300;
	br->sg->RowCount = 1;
	br->sg->ColCount = 3;
	br->ExportExcel = &CreateReportOrgTypeDistrib;
	br->sg->Cells[0][FirstRow] = "<b><c>№ п/п";
	br->sg->Cells[1][FirstRow] = "<b><c>Учреждения";
	br->sg->Cells[2][FirstRow] = "<b><c>Общее кол-во";

	br->Caption = "Количество обследованных детей по районам";

	RepDate1 = DateTimePicker1->Date;
	RepDate2 = DateTimePicker2->Date;
	q->Parameters->ParamByName("fdate1")->Value = RepDate1;
	q->Parameters->ParamByName("fdate2")->Value = RepDate2;
	q->Open();



	br->sg->Cells[2][4] = "Период с " + RepDate1.DateString() + " по " + RepDate2.DateString();

	OrgTypeID = -1;
	OrgID = -1;
	r = FirstRow;
	sum = 0;
	while (!q->Eof)	{
		if (q->FieldByName("OrgTypeID")->AsInteger == 0 || q->FieldByName("OrgID")->AsInteger == 0) {
			q->Next();
			continue;            
		}
		if (OrgTypeID != q->FieldByName("OrgTypeID")->AsInteger)	{
			nn = 1;
//			 && OrgTypeID != q->FieldByName("OrgTypeID")->AsInteger
			br->sg->RowCount = br->sg->RowCount + 1;
//			Sheet.OlePropertyGet("Rows",r).OleProcedure("Insert");
			r++;
			br->sg->Cells[FirstCol + 1][r] = "<b><c>" + q->FieldByName("OrgType")->AsString;
			OrgID = -1;
//			r++;
		}
		if (OrgID != q->FieldByName("OrgID")->AsInteger)	{
			Org = q->FieldByName("Org")->AsString;
			OrgTypeID = q->FieldByName("OrgTypeID")->AsInteger;
			OrgType = q->FieldByName("OrgType")->AsString;
			OrgID = q->FieldByName("OrgID")->AsInteger;
//			sum += CntChild;
			if (br->sg->Objects[FirstCol + 2][r] != NULL) {
				br->sg->Cells[FirstCol + 2][r] = List->Count;
			}
			r++;
			br->sg->RowCount = br->sg->RowCount + 1;
			br->sg->Cells[FirstCol + 0][r] = nn;
			br->sg->Cells[FirstCol + 1][r] = Org;
//			br->sg->Cells[FirstCol + 2][r] = CntChild;
        	List = new TDrawBaseList;
			br->sg->Objects[FirstCol + 2][r] = (TObject*)new TCellObjList(tlChild, List);
			nn++;
		}
		ChildID = q->FieldByName("ChildID")->AsInteger;
		if (ChildID != 0)
			List->Add(Childrens->ItemByID(ChildID));
		q->Next();
	}
	if (br->sg->Objects[FirstCol + 2][r] != NULL) {
		br->sg->Cells[FirstCol + 2][r] = List->Count;
	}
	r++;
	br->sg->Cells[FirstCol + 1][r] = "<b>Всего";
//	br->sg->Cells[FirstCol + 2][r] = sum;
	br->sg->Cells[FirstCol + 2][r] = "<b>" + IntToStr(q->RecordCount);
    br->sg->RowCount = r + 1;

	q->Close();
	br->ShowModal();
}
//---------------------------------------------------------------------------

