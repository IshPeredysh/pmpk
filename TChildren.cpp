//---------------------------------------------------------------------------


#pragma hdrstop

#include "TChildren.h"
#include "DigitConvertion.h"
#include "TOrganizationList.h"
#include "TParentList.h"
#include "TBaseEmptyList.h"
#include "TTreeBaseEmptyList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

extern TBaseEmptyList *AreaList;
extern TOrganizationList* Organizations;
extern TParentList* Parents;
extern TTreeBaseEmptyList *OtherObjectList;


int TChildren::SetThisUpdateParams(TADOQuery *q)
{
	TMemoryStream *sHistory = new TMemoryStream;
	TMemoryStream *sExtInfo = new TMemoryStream;

	TTreeBase::SetThisUpdateParams(q);
	q->Parameters->ParamByName("Birthday")->Value = FBirthday;
	q->Parameters->ParamByName("PlaceStudy")->Value = IfNull(FPlaceStudy);
	q->Parameters->ParamByName("Father")->Value = IfNull(FFather);
	q->Parameters->ParamByName("Mother")->Value = IfNull(FMother);
	q->Parameters->ParamByName("Area")->Value = IfNull(FArea);
	q->Parameters->ParamByName("SP133")->Value = IfNull(SP133);
	q->Parameters->ParamByName("Adress")->Value = FAdress;
	q->Parameters->ParamByName("Sex")->Value = FSex;

	//History
	sHistory->Clear();
	sHistory->Write(FHistory.c_str(), FHistory.Length());
	q->Parameters->ParamByName("History")->LoadFromStream(sHistory, ftBlob);
	sHistory->Free();

	//ExtInfo
	sExtInfo->Clear();
	sExtInfo->Write(FExtInfo.c_str(), FExtInfo.Length());
	q->Parameters->ParamByName("ExtInfo")->LoadFromStream(sExtInfo, ftBlob);
	sExtInfo->Free();

	return 1;
}

TChildren::TChildren(int VIsFolder, int VParentID, int MaxID):TTreeBase(VIsFolder, VParentID, MaxID)
{
	FIsFolder = VIsFolder;
	FParentID = VParentID;
    FID = MaxID;
}

TChildren::TChildren(TADOQuery *q):TTreeBase(q)
{
	//TMemoryStream *sHistory = new TMemoryStream;
	//TBlobField *bf;

	this->FBirthday = q->FieldByName("Birthday")->AsDateTime;
	this->FPlaceStudy = q->FieldByName("PlaceStudy")->AsInteger;
	this->FFather = q->FieldByName("Father")->AsInteger;
	this->FMother = q->FieldByName("Mother")->AsInteger;
	this->FArea = q->FieldByName("Area")->AsInteger;
	this->SP133 = q->FieldByName("SP133")->AsInteger;
	this->FAdress = q->FieldByName("Adress")->AsString;
	this->FHistory = q->FieldByName("History")->AsString;
	this->FExtInfo = q->FieldByName("ExtInfo")->AsString;
	this->FSex = q->FieldByName("Sex")->AsInteger;
}

TChildren::TChildren(TChildren *Template):TTreeBase(Template)
{
	this->FID = Template->ID;
	this->FBirthday = Template->FBirthday;
	this->FPlaceStudy = Template->FPlaceStudy;
	this->FFather = Template->FFather;
	this->FMother = Template->FMother;
	this->FArea = Template->FArea;
	this->SP133 = Template->SP133;
	this->FAdress = Template->FAdress;
	this->FHistory = Template->FHistory;
	this->FExtInfo = Template->FExtInfo;
	this->FSex = Template->FSex;
}

AnsiString TChildren::GetAdress()
{
	return FAdress;
}

AnsiString TChildren::GetArea()
{
	TBaseEmpty *AreaItem;
	if (AreaList == NULL)
		return "Îøèáêà!";
	if (FArea == 0)
		return "";
	AreaItem = (TBaseEmpty*)AreaList->ItemByID(FArea);
	if (AreaItem != NULL)
		return AreaItem->Descr;
	return "Îøèáêà!";

}

AnsiString TChildren::GetExtInfo()
{
	return FExtInfo;
}

String TChildren::GetFather()
{
	TParent *Parent;
	if (Parents == NULL)
		return "Îøèáêà!";
	if (FFather == 0)
		return "";
	Parent = Parents->ParentByID(FFather);
	if (Parent != NULL)
		return Parent->Descr;
	return "Îøèáêà!";

}

String TChildren::GetMother()
{
	TParent *Parent;
	if (Parents == NULL)
		return "Îøèáêà!";
	if (FMother == 0)
		return "";
	Parent = Parents->ParentByID(FMother);
	if (Parent != NULL)
		return Parent->Descr;
	return "Îøèáêà!";

}

AnsiString TChildren::GetHistory()
{
	return FHistory;
}

String TChildren::GetPlaceStudy()
{
	TOrganization *Org;
	
	if (Organizations == NULL)
		return "Îøèáêà!";
	if (FPlaceStudy == 0)
		return "";
	Org = Organizations->OrganizationByID(FPlaceStudy);
	if (Org != NULL)
		return Org->Descr;
	return "Îøèáêà!";
}

void TChildren::SetAreaID(int Value)
{
	FArea = Value;
	FModified = true;

}

void TChildren::SetBirthday(TDateTime Value)
{
	FBirthday = Value;
	FModified = true;
}

void TChildren::SetFatherID(int Value)
{
	FFather = Value;
	FModified = true;
}

void TChildren::SetMotherID(int Value)
{
	FMother = Value;
	FModified = true;
}

void TChildren::SetPlaceStudyID(int Value)
{
	FPlaceStudy = Value;
	FModified = true;
}

void TChildren::SetAdress(String Value)
{
	FAdress = Value;
	FModified = true;
}

void TChildren::SetHistory(String Value)
{
	FHistory = Value;
	FModified = true;
}

void TChildren::SetExtInfo(String Value)
{
	FExtInfo = Value;
	FModified = true;
}

void TChildren::SetSexID(int Value)
{
	FSex = Value;
	FModified = true;
}

int TChildren::DeleteFromDB()
{
	TADOQuery *q;

	q = DM->ChildrenCheckQuery;
	q->Parameters->ParamByName("ChildID")->Value = FID;
	q->Open();
	if (q->FieldByName("cnt")->AsInteger) {
		q->Close();
		return -1;
	}
	q->Close();

	return RemoveFromDB(DM->ChildrenDeleteQuery);
}

String TChildren::GetSex()
{
	TBase *Item;

	if ((Item = (TBase*)OtherObjectList->ItemByID(FSex)) != NULL)
    	return Item->Descr;
	return NULL;
}
