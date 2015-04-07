//---------------------------------------------------------------------------


#pragma hdrstop

#include "ReportProtocol.h"
#include "Protocol.h"
#include "TAttrAppointList.h"
#include "TSpecFieldObject.h"
#include "TAttrAppoint.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

extern TAttrAppointList *AttrAppointList;

TProtocolForm *pf = ProtocolForm;

void __fastcall InsToStr(String *Str, String SubStr, int Num)
{
	*Str = (*Str).SubString(1, Num - 1) + SubStr +
		(*Str).SubString(Num, (*Str).Length() - Num + 1);
}

void __fastcall ReplaceStr(String *Str, String FindValue, String ReplaceValue)
{
	int p;

	p = (*Str).Pos(FindValue);
	if (p) {
		(*Str).Delete(p, FindValue.Length());
		InsToStr(Str, ReplaceValue, p);
	}
}

String GetTextByFieldName(String FieldName, ISpecField **sfMas, int cnt)
{
	int i;

	for (i = 0; i < cnt; i++) {
		if (sfMas[i]->FieldName == FieldName) {
            return sfMas[i]->TextData;
		}
	}
	return "";
}

String __fastcall FindFieldInString(String Value)
{
	int p, start, end;
	String FieldName;

	p = Value.Pos(START_FIELDCODE);
	if (p) {
		start = p;
		p = Value.Pos(END_FIELDCODE);
		if (p) {
			end = p;
			FieldName = Value.SubString(start + START_FIELDCODE.Length(), end - (start + START_FIELDCODE.Length()) );
			if (AttrAppointList->ItemByDescr(FieldName) != NULL) {
				return FieldName;
			}
		}
	}
	return "";

}

void __fastcall CreateReportProtocol()
{
//    TSpecFieldObject
	ISpecField **sfMas;
	ISpecField *spec;

	String FileName, xls, s, str, test;
	Variant Excel, WorkBooks, Sheet, Cell;
	String Value = "Hi!", ReplaceValue, FindValue, FieldName;
	int ColCount, RowCount, c, r, p, i, j, CntSpec, sh, SheetCount;

	TEditSpec *EditSpec;
	TRichEditSpec *RichEditSpec;
	TComboBoxSpec *ComboBoxSpec;
	TDateTimePickerSpec *DateTimePickerSpec;


	FileName = ExtractFilePath(Application->ExeName) + "xlt\\Протокол.xlt";

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

//	ActiveCell.Value = ActiveSheet.Cells.SpecialCells(xlCellTypeLastCell).Column

	pf = ProtocolForm;

	CntSpec = 0;
	for (i = 0; i < pf->ComponentCount; i++) {
		str = pf->Components[i]->ClassName();
		s = pf->Components[i]->Name;

		if (str == "TEditSpec")
			CntSpec++;
		else if (str == "TRichEditSpec")
			CntSpec++;
		else if (str == "TComboBoxSpec")
			CntSpec++;
		else if (str == "TDateTimePickerSpec")
			CntSpec++;
	}

	sfMas = (ISpecField**)new THandle*[CntSpec];

	j = 0;
	for (i = 0; i < pf->ComponentCount; i++) {
		str = pf->Components[i]->ClassName();
		s = pf->Components[i]->Name;

		if (str == "TEditSpec")	{
			EditSpec = (TEditSpec*)(pf->Components[i]);
			sfMas[j++] = (ISpecField*)(EditSpec);
		}
		else if (str == "TRichEditSpec")	{
			RichEditSpec = (TRichEditSpec*)(pf->Components[i]);
			sfMas[j++] = (ISpecField*)(RichEditSpec);
		}
		else if (str == "TComboBoxSpec")	{
			ComboBoxSpec = (TComboBoxSpec*)(pf->Components[i]);
			sfMas[j++] = (ISpecField*)(ComboBoxSpec);
		}
		else if (str == "TDateTimePickerSpec")	{
			DateTimePickerSpec = ((TDateTimePickerSpec*)(pf->Components[i]));
			sfMas[j++] = (ISpecField*)(DateTimePickerSpec);
        }
	}

	SheetCount = Excel.OlePropertyGet("ActiveWorkbook").OlePropertyGet("Sheets").OlePropertyGet("Count");
	for (sh = 1; sh <= SheetCount; sh++) {
		Sheet = Excel.OlePropertyGet("WorkSheets",sh);
		ColCount = Sheet.OlePropertyGet("Cells").OlePropertyGet("SpecialCells", 11).OlePropertyGet("Column");
		RowCount = Sheet.OlePropertyGet("Cells").OlePropertyGet("SpecialCells", 11).OlePropertyGet("Row");
		for (c = 1; c <= ColCount; c++) {
			for (r = 1; r <= RowCount; r++) {
				Cell = Sheet.OlePropertyGet("Cells", r, c);
				s = Cell.OlePropertyGet("Text");
				while ((FieldName = FindFieldInString(s)) != "")	{
//					if (FieldName != "")	{
						ReplaceValue = GetTextByFieldName(FieldName, sfMas, CntSpec);
						FindValue = START_FIELDCODE + FieldName + END_FIELDCODE;
						ReplaceStr(&s, FindValue, ReplaceValue);
						Cell.OlePropertySet("Value", s.c_str());
					}
			}
		}
	}

	Excel.OlePropertySet("Visible", true);
}
