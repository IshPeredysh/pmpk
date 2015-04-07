//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//#undef INC_VCLEXT_HEADERS

#include "Main.h"
#include "Childrens.h"
#include "TChildrenList.h"
#include "DM3Unit.h"
#include "TTreeBaseEmptyList.h"
#include "TOrganizationList.h"
#include "TParentList.h"
#include "Parents.h"
#include "ParentsInfo.h"
#include "Organizations.h"
#include "Diagnosis.h"
#include "GroupData.h"
#include "TBaseEmptyList.h"
#include "Lang.h"
#include "Appointment.h"
#include "TAttrAppointList.h"
#include "AttrAppoint.h"
#include "Recommend.h"
#include "Journ.h"
#include "Protocol.h"
#include "ExtFunctions.h"
#include "TListList.h"
#include "Report.h"
#include "Report2.h"
#include "Progress.h"
#include "Areas.h"
#include "ChildrenInfo.h"
#include "FileINI.h"
#include "ReportAgeGroups.h"
#include "ComboBoxList.h"
#include "PathDB.h"
#include "TAutoSize.h"
#include "FileINI.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

extern TChildrenList* Childrens;
extern TTreeBaseEmptyList *AreaList;
extern TOrganizationList* Organizations;
extern TParentList* Parents;
extern TTreeBaseEmptyList *OtherObjectList;
extern TTreeBaseEmptyList *DiagnosisList;
extern TTreeBaseEmptyList *GroupDataList;
extern TBaseEmptyList *LangList;
extern TBaseEmptyList *SchoolTypeList;
extern TBaseEmptyList *GroupTypeList;
extern TBaseEmptyList *KGartenTypeList;
extern TBaseEmptyList *AppointmentList;
extern TAttrAppointList *AttrAppointList;
extern TTreeBaseEmptyList *RecommendList;
extern TListList *ListList;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N2Click(TObject *Sender)
{
	TADOQuery *q;

	/*ProgressForm->Show();
	ProgressForm->LabelText = "Загрузка таблицы \"Дети\"";
	Application->ProcessMessages();*/

	q = DM->ChildrenSelectQuery;
	Childrens->RemoveItems();
	q->Open();
	Childrens->FillFromDB(q);
	q->Close();

//	ProgressForm->CanClose = true;
//	ProgressForm->Close();

	ChildrensForm->SenderProtocol = 0;
	ChildrensForm->Show();
}
//---------------------------------------------------------------------------

String TMainForm::LoadDBaseStringINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));
	TStringList *list = new TStringList;
	String CompName, FileName;

	file->ReadSectionValues("DataBase", list);
	CompName = file->ReadString("DataBase", "ComputerName", "");
	FileName = file->ReadString("DataBase", "FileName", "");

	delete file, list;

	if (CompName != "")
		CompName = CompName + ":";


	return CompName + FileName;
}

void __fastcall TMainForm::CheckAppointJournTable()
{
	try {
		DM->CheckAppointJournQuery->Open();
    	DM->CheckAppointJournQuery->Close();
	} catch (...) {
		DM->CreateAppointJournTableQuery->ExecSQL();
		DM->AlterIDDocQuery->ExecSQL();
		DM->AlterAppointIDQuery->ExecSQL();
	}
}


void __fastcall TMainForm::FormShow(TObject *Sender)
{
	String FileNameDB, ConnectionString;
	int error = 0;

	try {
		FileNameDB = LoadDBaseStringINI();
		DM->ADOConnection1->Connected = false;
		ConnectionString = "Persist Security Info=True;Extended Properties=\"Driver=Firebird/InterBase(r) driver;Dbname=" +
				FileNameDB + ";CHARSET=WIN1251;PWD=masterkey;UID=sysdba;Client=gds32.dll;\"";
		DM->ADOConnection1->ConnectionString = ConnectionString;
		DM->ADOConnection1->Connected = true;
	} catch (...) {
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		ShowMessage("Ошибка! Не удалось подключиться к базе даных.");
		PathDBForm->ShowModal();
//		error = 1;
		Close();
		return;
	}

	CheckAppointJournTable();  //временно
	//Persist Security Info=True;Extended Properties="Driver=Firebird/InterBase(r) driver;Dbname=D:\sas\PMPK\DBase\DB.FDB;CHARSET=WIN1251;PWD=masterkey;UID=sysdba;Client=gds32.dll;"

	__try	{

	Childrens = new TChildrenList;
	Childrens->SetQueryGroup(DM->ChildrenInsertQuery, DM->ChildrenUpdateQuery,
		DM->ChildrenDeleteQuery, DM->ChildrenGetMaxQuery, DM->ChildrenSelectQuery);

	AreaList = new TTreeBaseEmptyList;
	AreaList->SetQueryGroup(DM->AreaInsertQuery, DM->AreaUpdateQuery,
		DM->AreaDeleteQuery, DM->AreaGetMaxQuery, DM->AreaSelectQuery);

	Organizations = new TOrganizationList;
	Organizations->SetQueryGroup(DM->OrgInsertQuery, DM->OrgUpdateQuery,
		DM->OrgDeleteQuery, DM->OrgGetMaxQuery, DM->OrgSelectQuery);

	Parents = new TParentList;
	Parents->SetQueryGroup(DM->ParentInsertQuery, DM->ParentUpdateQuery,
		DM->ParentDeleteQuery, DM->ParentGetMaxQuery, DM->ParentSelectQuery);

	OtherObjectList = new TTreeBaseEmptyList;

	DiagnosisList = new TTreeBaseEmptyList;
	DiagnosisList->SetQueryGroup(DM->DiagnosInsertQuery, DM->DiagnosUpdateQuery,
		DM->DiagnosDeleteQuery, DM->DiagnosGetMaxQuery, DM->DiagnosQuery);

	GroupDataList = new TTreeBaseEmptyList;
	GroupDataList->SetQueryGroup(DM->GDataInsertQuery, DM->GDataUpdateQuery,
		DM->GDataDeleteQuery, DM->GDataGetMaxQuery, DM->GDataQuery);

	LangList = new TBaseEmptyList;
	LangList->SetQueryGroup(DM->LangInsertQuery, DM->LangUpdateQuery,
		DM->LangDeleteQuery, DM->LangGetMaxQuery, DM->LangQuery);

	SchoolTypeList = new TBaseEmptyList;
	SchoolTypeList->SetQueryGroup(DM->SchoolTypeInsertQuery, DM->SchoolTypeUpdateQuery,
		DM->SchoolTypeDeleteQuery, DM->SchoolTypeGetMaxQuery, DM->SchoolTypeSelectQuery);

	GroupTypeList = new TBaseEmptyList;
	GroupTypeList->SetQueryGroup(DM->GroupTypeInsertQuery, DM->GroupTypeUpdateQuery,
		DM->GroupTypeDeleteQuery, DM->GroupTypeGetMaxQuery, DM->GroupTypeSelectQuery);

	KGartenTypeList = new TBaseEmptyList;
	KGartenTypeList->SetQueryGroup(DM->KGartenTypeInsertQuery, DM->KGartenTypeUpdateQuery,
		DM->KGartenTypeDeleteQuery, DM->KGartenTypeGetMaxQuery, DM->KGartenTypeSelectQuery);

	AppointmentList = new TBaseEmptyList;
	AppointmentList->SetQueryGroup(DM->AppointmentInsertQuery, DM->AppointmentUpdateQuery,
		DM->AppointmentDeleteQuery, DM->AppointmentGetMaxQuery, DM->AppointmentQuery);

	AttrAppointList = new TAttrAppointList;
	AttrAppointList->SetQueryGroup(NULL, DM->AttrAppointUpdateQuery,
		NULL, NULL, DM->AttrAppointQuery);

	RecommendList = new TTreeBaseEmptyList;
	RecommendList->SetQueryGroup(DM->RecomInsertQuery, DM->RecomUpdateQuery,
		DM->RecomDeleteQuery, DM->RecomGetMaxQuery, DM->RecomQuery);

	OtherObjectList->SetQueryGroup(DM->ObjectsInsertQuery, DM->ObjectsUpdateQuery,
		 DM->ObjectsDeleteQuery, DM->ObjectsGetMaxQuery, DM->ObjectsQuery);

	ListList = new TListList();
	ListList->AddList(AreaList, 123);
	ListList->AddList(Organizations, 36);
	ListList->AddList(GroupDataList, 62);
	ListList->AddList(OtherObjectList, 1);
	ListList->AddList(Childrens, 18);
	ListList->AddList(Parents, 84);
	ListList->AddList(LangList, 76);
	ListList->AddList(SchoolTypeList, 135);
	ListList->AddList(GroupTypeList, 152);
	ListList->AddList(KGartenTypeList, 154);
	ListList->AddList(DiagnosisList, 39);
	ListList->AddList(RecommendList, 121);

	TADOQuery *q;

	ProgressForm->LabelText = "Загрузка таблиц \"Районы\"";
	Application->ProcessMessages();
	q = DM->AreaSelectQuery;
	/*AreaList->RemoveItems();
	q->Open();
	AreaList->FillFromDB(q);
	q->Close();*/
	AreaList->ReloadList();
	AreaList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Дети\"";
	Application->ProcessMessages();
	q = DM->ChildrenSelectQuery;
	Childrens->RemoveItems();
	q->Open();
	Childrens->FillFromDB(q);
	q->Close();

	ProgressForm->LabelText = "Загрузка таблицы \"Организации\"";
	Application->ProcessMessages();
	q = DM->OrgSelectQuery;
	Organizations->RemoveItems();
	q->Open();
	Organizations->FillFromDB(q);
	q->Close();
	Organizations->SortByDescrAndIsFolder();

	ProgressForm->LabelText = "Загрузка таблицы \"Родители\"";
	Application->ProcessMessages();
	q = DM->ParentSelectQuery;
	Parents->RemoveItems();
	q->Open();
	Parents->FillFromDB(q);
	q->Close();
	Parents->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Выподающие списки\"";
	Application->ProcessMessages();
	q = DM->ObjectsQuery;
	OtherObjectList->RemoveItems();
	q->Open();
	OtherObjectList->FillFromDB(q);
	q->Close();
	OtherObjectList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Диагнозы\"";
	Application->ProcessMessages();
	q = DM->DiagnosQuery;
	DiagnosisList->RemoveItems();
	q->Open();
	DiagnosisList->FillFromDB(q);
	q->Close();
	DiagnosisList->SortByDescrAndIsFolder();

	ProgressForm->LabelText = "Загрузка таблицы \"Группы данных\"";
	Application->ProcessMessages();
	q = DM->GDataQuery;
	GroupDataList->RemoveItems();
	q->Open();
	GroupDataList->FillFromDB(q);
	q->Close();
	GroupDataList->SortByDescrAndIsFolder();

	ProgressForm->LabelText = "Загрузка таблицы \"Языки\"";
	Application->ProcessMessages();
	q = DM->LangQuery;
	LangList->RemoveItems();
	q->Open();
	LangList->FillFromDB(q);
	q->Close();
	LangList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Типы школ\"";
	Application->ProcessMessages();
	q = DM->SchoolTypeSelectQuery;
	SchoolTypeList->RemoveItems();
	q->Open();
	SchoolTypeList->FillFromDB(q);
	q->Close();
	SchoolTypeList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Типы групп\"";
	Application->ProcessMessages();
	q = DM->GroupTypeSelectQuery;
	GroupTypeList->RemoveItems();
	q->Open();
	GroupTypeList->FillFromDB(q);
	q->Close();
	GroupTypeList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Детские сады\"";
	Application->ProcessMessages();
	q = DM->KGartenTypeSelectQuery;
	KGartenTypeList->RemoveItems();
	q->Open();
	KGartenTypeList->FillFromDB(q);
	q->Close();
	KGartenTypeList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Должности\"";
	Application->ProcessMessages();
	q = DM->AppointmentQuery;
	AppointmentList->RemoveItems();
	q->Open();
	AppointmentList->FillFromDB(q);
	q->Close();
	AppointmentList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Атрибуты должностей\"";
	Application->ProcessMessages();
	q = DM->AttrAppointQuery;
	AttrAppointList->RemoveItems();
	q->Open();
	AttrAppointList->FillFromDB(q);
	q->Close();
	AttrAppointList->SortByDescr();

	ProgressForm->LabelText = "Загрузка таблицы \"Рекомендации\"";
	Application->ProcessMessages();
	q = DM->RecomQuery;
	RecommendList->RemoveItems();
	q->Open();
	RecommendList->FillFromDB(q);
	q->Close();
	RecommendList->SortByDescrAndIsFolder();

	//FillBox
		//Родители
	/*	FillBox(2, (TTreeBaseList*)OtherObjectList, ParentsInfoForm->EducationBox); //Образование
	FillBox(1, (TTreeBaseList*)OtherObjectList, ParentsInfoForm->BadHabitBox); //Вредные привычки
	FillBox(45, (TTreeBaseList*)OtherObjectList, ParentsInfoForm->BadStrainBox); //Отяг. наследст */
		//Организации
	FillBox(4, (TTreeBaseList*)OtherObjectList, OrganizationsForm->lb); //Вид организации
	FillBox(104, (TTreeBaseList*)OtherObjectList, ChildrenInfoForm->SexBoxSpec); //Пол
		//Протокол
	ProtocolForm->FillAllBox();
	ProtocolForm->FillAppointBox();

	ParentsInfoForm->FillAllBox();

	ProtocolForm->LoadINI();
	JournForm->LoadINI();

	LoadINI();
	}
	__finally	{
		ProgressForm->CanClose = true;
		ProgressForm->Close();
		Show();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender)
{
	ParentsForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N4Click(TObject *Sender)
{
	OrganizationsForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)
{
	DiagnosisForm->ShowModal();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N6Click(TObject *Sender)
{
	GroupDataForm->ShowModal();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N7Click(TObject *Sender)
{
	LangForm->ShowModal();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N8Click(TObject *Sender)
{
	AppointmentForm->ShowModal();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9Click(TObject *Sender)
{
	AttrAppointForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
	RecommendForm->ShowModal();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N11Click(TObject *Sender)
{
	JournForm->Show();
}
//---------------------------------------------------------------------------

void TMainForm::DestroyLists()
{
	int i;

	for (i = 0; i < ListList->Count; i++) {
    	delete ListList->Items[i];    
	}
	delete ListList;
}

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	JournForm->ClearGrid();
	JournForm->SaveINI();
	ProtocolForm->SaveINI();
	SaveINI();
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::N15Click(TObject *Sender)
{
	AreasForm->Show();	
}
//---------------------------------------------------------------------------





void __fastcall TMainForm::N16Click(TObject *Sender)
{
	ComboBoxForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{
	ReportForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N14Click(TObject *Sender)
{
	TADOQuery *q;

	q = DM->AppointJournDeleteAllQuery;
	q->ExecSQL();
	ShowMessage("Готово. Все протоколы закрыты.");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N17Click(TObject *Sender)
{
	PathDBForm->ShowModal();	
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ChangeFont(TFont *f)
{
	Font->Assign(f);
	ProtocolForm->ChangeFont(f);
	JournForm->ChangeFont(f);
	ChildrensForm->ChangeFont(f);
	ParentsForm->ChangeFont(f);
	OrganizationsForm->ChangeFont(f);
	ChildrenInfoForm->ChangeFont(f);
	ParentsInfoForm->ChangeFont(f);
	DiagnosisForm->ChangeFont(f);
	GroupDataForm->ChangeFont(f);
	LangForm->ChangeFont(f);
	AppointmentForm->ChangeFont(f);
	AttrAppointForm->ChangeFont(f);
	RecommendForm->ChangeFont(f);
	AreasForm->ChangeFont(f);
	ComboBoxForm->ChangeFont(f);
}

void __fastcall TMainForm::N18Click(TObject *Sender)
{
	if (!FontDialog1->Execute()) {
		return;
	}
	ChangeFont(FontDialog1->Font);
}
//---------------------------------------------------------------------------

void TMainForm::SaveINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));

	file->WriteInteger("Font", "Size", Font->Size);
	file->WriteString("Font", "Name", Font->Name);

	if (Font->Style.Contains(fsBold))
		file->WriteBool("Font", "Style_fsBold", 1);
	else
		file->WriteBool("Font", "Style_fsBold", 0);

	if (Font->Style.Contains(fsItalic))
		file->WriteBool("Font", "Style_fsItalic", 1);
	else
		file->WriteBool("Font", "Style_fsItalic", 0);

	file->Free();
}

void TMainForm::LoadINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));
	TStringList *list = new TStringList;

	file->ReadSectionValues("Font", list);
	Font->Size = file->ReadInteger("Font", "Size", 8);
	Font->Name = file->ReadString("Font", "Name", "Tahoma");
	if (file->ReadBool("Font", "Style_fsBold", 0))
		Font->Style = Font->Style << fsBold;
	if (file->ReadBool("Font", "Style_fsItalic", 0))
		Font->Style = Font->Style << fsItalic;

	ChangeFont(Font);
	delete file, list;
}
