//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PathDB.h"
#include "FileINI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPathDBForm *PathDBForm;
//---------------------------------------------------------------------------
__fastcall TPathDBForm::TPathDBForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TPathDBForm::SaveINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));

	file->WriteString("DataBase", "ComputerName", Edit1->Text);
	file->WriteString("DataBase", "FileName", Edit2->Text);
	file->Free();
}

void __fastcall TPathDBForm::LoadINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));
	TStringList *list = new TStringList;
	String CompName, FileName;

	file->ReadSectionValues("DataBase", list);
	CompName = file->ReadString("DataBase", "ComputerName", "");
	FileName = file->ReadString("DataBase", "FileName", "");

	Edit1->Text = CompName;
	Edit2->Text = FileName;
	
	delete file, list;
}

//---------------------------------------------------------------------------
void __fastcall TPathDBForm::SpeedButton1Click(TObject *Sender)
{
	OpenDialog1->Title = "Укажите файл базы данных";
	if (OpenDialog1->Execute()) {
		Edit2->Text = OpenDialog1->FileName;
	}

}
//---------------------------------------------------------------------------
void __fastcall TPathDBForm::Button1Click(TObject *Sender)
{
	SaveINI();
	ShowMessage("Чтобы изменения вступили в силу, перезапустите программу.");
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TPathDBForm::Button2Click(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------


void __fastcall TPathDBForm::FormShow(TObject *Sender)
{
	LoadINI();	
}
//---------------------------------------------------------------------------

