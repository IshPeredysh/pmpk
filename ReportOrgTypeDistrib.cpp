//---------------------------------------------------------------------------


#pragma hdrstop

#include "ReportOrgTypeDistrib.h"
#include <Dialogs.hpp>
#include "TAttrAppointList.h"
#include "TSpecFieldObject.h"
#include "TAttrAppoint.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


void __fastcall CreateReportOrgTypeDistrib(TDateTime RepDate1, TDateTime RepDate2)
{
	String FileName, xls, s, str, test;
	Variant Excel, WorkBooks, Sheet, Cell;
	String Value = "Hi!", ReplaceValue, FindValue, FieldName;
	String Org, OrgType;
	int ColCount, RowCount, c, r, p, i, j, CntSpec, sh, SheetCount, FirstRow, FirstCol;
	int CntChild, OrgTypeID, nn, sum;
	TDateTime date1, date2;

	TADOQuery* q = DM->ReportOrgTypeDistibQuery;


	FileName = ExtractFilePath(Application->ExeName) + "xlt\\По учреждениям.xlt";

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

	q->Parameters->ParamByName("fdate1")->Value = RepDate1;
	q->Parameters->ParamByName("fdate2")->Value = RepDate2;
	q->Open();


	Sheet.OlePropertyGet("Cells", 4, 2).OlePropertySet("Value", String("Период с " + RepDate1.DateString() +
		" по " + RepDate2.DateString()).c_str());

	OrgTypeID = -1;
	FirstRow = 6;
	FirstCol = 2;
	r = FirstRow + 2;
	sum = 0;
	while (!q->Eof)	{
		if (OrgTypeID != q->FieldByName("OrgTypeID")->AsInteger)	{
			nn = 1;
			Sheet.OlePropertyGet("Rows",r).OleProcedure("Insert");
			Sheet.OlePropertyGet("Cells", r, FirstCol + 1).OlePropertySet("Value",
				q->FieldByName("OrgType")->AsString.c_str());
			Sheet.OlePropertyGet("Cells", r, FirstCol + 1).OlePropertyGet("Font").OlePropertySet("Bold", True);
			Sheet.OlePropertyGet("Cells", r, FirstCol + 1).OlePropertySet("HorizontalAlignment", -4108);
			r++;
//			r++;
		}
		Org = q->FieldByName("Org")->AsString;
		OrgTypeID = q->FieldByName("OrgTypeID")->AsInteger;
		OrgType = q->FieldByName("OrgType")->AsString;
		CntChild = q->FieldByName("cnt")->AsInteger;
		sum += CntChild;
		Sheet.OlePropertyGet("Rows",r+1).OleProcedure("Insert");
		Sheet.OlePropertyGet("Cells", r, FirstCol + 0).OlePropertySet("Value", nn);
		Sheet.OlePropertyGet("Cells", r, FirstCol + 1).OlePropertySet("Value", Org.c_str());
		Sheet.OlePropertyGet("Cells", r, FirstCol + 2).OlePropertySet("Value", CntChild);
		r++;
		nn++;
//		r++;
		q->Next();
	}
	q->Close();

	Sheet.OlePropertyGet("Cells", r, FirstCol + 1).OlePropertySet("Value", String("Всего").c_str());
	Sheet.OlePropertyGet("Cells", r, FirstCol + 2).OlePropertySet("Value", sum);
	Sheet.OlePropertyGet("Rows",r + 1).OleProcedure("Delete");
	Sheet.OlePropertyGet("Rows",FirstRow + 1).OleProcedure("Delete");
	Sheet.OlePropertyGet("Cells", r - 1, FirstCol + 1).OlePropertyGet("Font").OlePropertySet("Bold", True);
	Sheet.OlePropertyGet("Cells", r - 1, FirstCol + 1).OlePropertySet("HorizontalAlignment", -4108);
	Sheet.OlePropertyGet("Cells", r - 1, FirstCol + 2).OlePropertyGet("Font").OlePropertySet("Bold", True);
	Sheet.OlePropertyGet("Cells", r - 1, FirstCol + 2).OlePropertySet("HorizontalAlignment", -4108);
    Excel.OlePropertySet("Visible", true);
};