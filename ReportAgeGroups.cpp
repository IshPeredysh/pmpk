//---------------------------------------------------------------------------


#pragma hdrstop

#include "ReportAgeGroups.h"
#include <Dialogs.hpp>
#include "TAttrAppointList.h"
#include "TSpecFieldObject.h"
#include "TAttrAppoint.h"
#include "DMUnit.h"

//---------------------------------------------------------------------------

int GetFullYear(TDateTime date1, TDateTime date2)
{
	WORD y1, y2, m1, m2, d1, d2, y;

	DecodeDate(date1, y1, m1, d1);
	DecodeDate(date2, y2, m2, d2);

	y = y2 - y1;
	if (m2 > m1)
		return y;
	else if (m2 < m1)
		return y - 1;
	else if (m2 == m1)	{
		if (d2 >= d1)
			return y;
		else
			return y - 1;
	}
	return 0;
}


void __fastcall CreateReportAgeGruops(TDateTime RepDate1, TDateTime RepDate2)
{
	enum {A0_2, A2_6, A7_10, A11_15, A16_18};
	String BaseXls = ExtractFilePath(Application->ExeName) + "xlt\\book.xlsx";
	String FileName, xls, s, str, test;
	Variant Excel, WorkBooks, Sheet, Cell;
	String Value = "Hi!", ReplaceValue, FindValue, FieldName;
	int ColCount, RowCount, c, r, p, i, j, CntSpec, sh, SheetCount;
	TDateTime date1, date2;
	int AgeGroups[5], y;

	TADOQuery* q = DM->ReportAgeGroupsQuery;


	FileName = ExtractFilePath(Application->ExeName) + "xlt\\Возрастные группы.xlt";

	if (!FileExists(FileName))	{
		ShowMessage("Файл \"" + FileName + "\" не найден");
		return;
	}

	try   {
		Excel = CreateOleObject("Excel.Application");
	}
	catch(...) {
		Application->MessageBox("Невозможно установить соединение с Microsoft Excel.","Ошибка",MB_OK);
		return;
	}

	WorkBooks = Excel.OlePropertyGet("WorkBooks");
	WorkBooks.OleProcedure("open",FileName.c_str());

	Sheet = Excel.OlePropertyGet("WorkSheets",1);

	for (i = 0; i < 5; i++)
		AgeGroups[i] = 0;

	q->Parameters->ParamByName("fdate1")->Value = RepDate1;
	q->Parameters->ParamByName("fdate2")->Value = RepDate2;
	q->Open();
	Sheet.OlePropertyGet("Cells", 4, 2).OlePropertySet("Value", String("Период с " + RepDate1.DateString() +
		" по " + RepDate2.DateString()).c_str());

	while (!q->Eof)	{
		date1 = q->FieldByName("Birthday")->AsDateTime;
		date2 = q->FieldByName("FDate")->AsDateTime;
		y = GetFullYear(date1, date2);
		if (y >= 0 && y <= 2)
			AgeGroups[A0_2]++;
		if (y >= 2 && y <= 6)
			AgeGroups[A2_6]++;
		if (y >= 7 && y <= 10)
			AgeGroups[A7_10]++;
		if (y >= 11 && y <= 15)
			AgeGroups[A11_15]++;
		if (y >= 16 && y <= 18)
			AgeGroups[A16_18]++;
		q->Next();
	}
	Sheet.OlePropertyGet("Cells", 9, 2).OlePropertySet("Value", String("Всего " + IntToStr(q->RecordCount)).c_str());
	q->Close();
	r = 7;
	c = 2;
	for (i = 0; i < 5; i++)
		Sheet.OlePropertyGet("Cells", r, c + i).OlePropertySet("Value", AgeGroups[i]);

	Excel.OlePropertySet("Visible", true);
}

#pragma package(smart_init)


