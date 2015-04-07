//---------------------------------------------------------------------------


#pragma hdrstop

#include "TBlob.h"
#include "DigitConvertion.h"
#include <alloc.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

TBlob::TBlob(String FieldID, String ObjID)
{
	int len, lenSrc, kolRec, i;
	String str;
	FList = new TStringList;
	char* c, *cDigit, *cRes;
	TADOQuery *q = DM->BlobSelectQuery;

	this->FFieldID = FieldID;
	this->FObjID = ObjID;

	FList->Text = "";

	//Поиск поля. Запрос упорядочен по FieldID, BlockNo
	q->First();
	while (FFieldID != q->FieldByName("FieldID")->AsString && !q->Eof)	{
		q->Next();
	}

	//Подсчитываем кол-во записей
	kolRec = 0;
	while (FFieldID == q->FieldByName("FieldID")->AsString && !q->Eof)	{
		kolRec++;
		q->Next();
	}

	if (kolRec == 0) {
		FModified = false;
		return;
	}

	//Создаём массив в который будем считывать BLOB
	c = (char*)malloc(sizeof(char)*(kolRec*80));
	c[0] = '\0';

	//заново ищем запись.
	q->First();
	while (FFieldID != q->FieldByName("FieldID")->AsString && !q->Eof)	{
		q->Next();
	}

	//Считываем данные в "c"
	while (FFieldID == q->FieldByName("FieldID")->AsString && !q->Eof) {
		StrCat(c, q->FieldByName("Block")->AsString.c_str());
		q->Next();
	}

	//Находим кол-во символов, которые нужно считать
	cDigit = (char*)malloc(sizeof(char)*9);
	for (i = 0; i < 9; i++)
		cDigit[i] = c[i];
	i++;
	cDigit[i] = '\0';
	len = StrHexToInt(cDigit);
	delete []cDigit;

	//Считываем заданное кол-во символов
	cRes = (char*)malloc(sizeof(char)*(len));
	i = 9;
	while (i < len + 9)	{
		cRes[i - 9] = c[i];
		i++;
	}
	cRes[i - 9] = '\0';

	FList->SetText(cRes);
	str = FList->Text;
	delete []cRes;
	delete []c;

	this->FModified = false;
}

TBlob::~TBlob()
{
	delete FList;
}

AnsiString TBlob::GetText()
{
	int kol;

	if (FList->Text == "")
		return "";

	kol = StrHexToInt(FList->Text.SubString(1, 9).c_str());
	return FList->Text.SubString(10, kol);

};

void TBlob::UpdateDB(AnsiString Text)
{
	if (!FModified)
		return;
	FList->Text = Text;
	UpdateBase();
}

void TBlob::UpdateDB(TStrings* list)
{
	if (!FModified)
		return;
	FList->Assign(list);
	UpdateBase();
}


void TBlob::UpdateBase()
{
	const int kol = 80;
	int i, len, start, No, success;
	String str, str1, str2;

	TADOQuery* qUpd = DM->BlobUpdateQuery;
	TADOQuery* qIns = DM->BlobInsertQuery;
	TADOQuery* qDel = DM->BlobDeleteQuery;

//	if (!FModified)
//		return;

	//Копируем
	//FList->Assign(list);

	len = FList->Text.Length();
	FList->Text = IntToStrHex(len) + FList->Text;
	//c = (char*)malloc(sizeof(char)*len);

	len = FList->Text.Length();
	start = 1;
	No = 0;
	    /*
        DM->ADOCommand1->CommandText = "ready PMPK";
        	DM->ADOCommand1->Execute();    
    */
	while ((start - 1 + kol) <= len)	{
		str = FList->Text.SubString(start, kol);
		qUpd->Parameters->ParamByName("FieldID")->Value = FFieldID;
		qUpd->Parameters->ParamByName("ObjID")->Value = FObjID;
		qUpd->Parameters->ParamByName("BlockNo")->Value = No;
		qUpd->Parameters->ParamByName("Block")->Value = str;
		if (!qUpd->ExecSQL())	{
			qIns->Parameters->ParamByName("FieldID")->Value = FFieldID;
			qIns->Parameters->ParamByName("ObjID")->Value = FObjID;
			qIns->Parameters->ParamByName("BlockNo")->Value = No;
			qIns->Parameters->ParamByName("Block")->Value = str;
			qIns->ExecSQL();
		}
		start = start + 80;
		No++;
	}

	str = FList->Text.SubString(start, len - (start - 1));
	qUpd->Parameters->ParamByName("FieldID")->Value = FFieldID;
	qUpd->Parameters->ParamByName("ObjID")->Value = FObjID;
	qUpd->Parameters->ParamByName("BlockNo")->Value = No;
	qUpd->Parameters->ParamByName("Block")->Value = str;
	if (!qUpd->ExecSQL())	{
		qIns->Parameters->ParamByName("FieldID")->Value = FFieldID;
		qIns->Parameters->ParamByName("ObjID")->Value = FObjID;
		qIns->Parameters->ParamByName("BlockNo")->Value = No;
		qIns->Parameters->ParamByName("Block")->Value = str;
		qIns->ExecSQL();
	}


	do	{
		No++;
		qDel->Parameters->ParamByName("FieldID")->Value = FFieldID;
		qDel->Parameters->ParamByName("ObjID")->Value = FObjID;
		qDel->Parameters->ParamByName("BlockNo")->Value = No;
	}
	while (qDel->ExecSQL());

	FModified = false;
	//delete [] c;
}

void TBlob::SetModified()
{
	FModified = true;
}
