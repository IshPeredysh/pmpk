//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMUnit.h"
#include "Progress.h"
#include "ExtFunctions.h"
#include "TAttrAppointList.h"
#include "TOrganizationList.h"
#include "TParentList.h"
#include "TChildrenList.h"
#include "TListList.h"
#include "Diagnosis.h"
#include "Organizations.h"
#include "Areas.h"
#include "TOrganization.h"
#include "GroupData.h"
#include "Childrens.h"
#include "Recommend.h"
#include "ISpecField.h"
#include "Lang.h"
#include "SchoolType.h"
#include "DM2Unit.h"
#include "GroupType.h"
#include "KGarten.h"
#include "Journ.h"
#include "Protocol.h"
#include "FileINI.h"
#include "ParentsInfo.h"
#include "Parents.h"
#include "ReportProtocol.h"
#include <Clipbrd.hpp>
#include "TAutoSize.h"
#include <vector>
#include "ImagesDM.h"

using namespace std;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TEditSpec"
#pragma link "TDateTimePickerSpec"
#pragma link "TMemoSpec"
#pragma link "TComboBoxSpec"
#pragma link "RichEditSpec"
#pragma link "THelpListBox"
#pragma resource "*.dfm"

#define ERROR 0
TProtocolForm *ProtocolForm;

extern TChildrenList* Childrens;
extern TTreeBaseEmptyList *AreaList;
extern TOrganizationList* Organizations;
extern TParentList* Parents;
extern TTreeBaseEmptyList *OtherObjectList;
extern TTreeBaseEmptyList *DiagnosisList;
extern TTreeBaseEmptyList *GroupDataList;
extern TBaseEmptyList *LangList;
extern TBaseEmptyList *AppointmentList;
extern TAttrAppointList *AttrAppointList;
extern TTreeBaseEmptyList *RecommendList;
extern TListList *ListList;


void TProtocolForm::FillSpecBox(TComboBoxSpec *box)
{
	FillBox(box->ParentID, OtherObjectList, box);
}

void TProtocolForm::FillAllBox()
{
	TComboBoxSpec* box;
	int i;
	String str;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		if (str == "TComboBoxSpec") {
			box = (TComboBoxSpec*)Components[i];
			FillBox(box->ParentID, OtherObjectList, box);
		}
	}
}

void TProtocolForm::SetTextForSpec(TRichEditSpec *res)
{
	TBaseList *list;
	TBase *Item;

	if (res->ItemID == 0) {
		res->Text = "";
		return;
	}

	list = ListList->GetByListID(res->ListID);
	if (list != NULL)	{
		Item = (TBase*)list->ItemByID(res->ItemID);
		if (Item != NULL)	{
			res->Text = Item->Descr;
			return;
		}
	}
	res->Text = "";
}


TEditSpec* TProtocolForm::GetSpecEdit(String FieldName)
{
	int i;

	for (i = 0; i < ComponentCount; i++) {
		if (String(Components[i]->ClassName()) == "TEditSpec") {
			if (((TEditSpec*)Components[i])->FieldName == FieldName) {
				return (TEditSpec*)Components[i];
			}
		}
	}
	return NULL;
}

TRichEditSpec* TProtocolForm::GetSpecRichEdit(String FieldName)
{
	int i;

	for (i = 0; i < ComponentCount; i++) {
		if (String(Components[i]->ClassName()) == "TRichEditSpec") {
			if (((TRichEditSpec*)Components[i])->FieldName == FieldName) {
				return (TRichEditSpec*)Components[i];
			}
		}
	}

	return NULL;
}

TComboBoxSpec* TProtocolForm::GetSpecComboBox(String FieldName)
{
	int i;

	for (i = 0; i < ComponentCount; i++) {
		if (String(Components[i]->ClassName()) == "TComboBoxSpec") {
			if (((TComboBoxSpec*)Components[i])->FieldName == FieldName) {
				return (TComboBoxSpec*)Components[i];
			}
		}
	}

	return NULL;
}

TDateTimePickerSpec* TProtocolForm::GetSpecTimePicker(String FieldName)
{
	int i;

	for (i = 0; i < ComponentCount; i++) {
		if (String(Components[i]->ClassName()) == "TDateTimePickerSpec") {
			if (((TDateTimePickerSpec*)Components[i])->FieldName == FieldName) {
				return (TDateTimePickerSpec*)Components[i];                
			}           
		}
	}
	return NULL;
}



void TProtocolForm::ClearSpecComponent()
{
	int i;
	String str, s;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;

//	RichEditSpec1->ItemID = 0;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;

		try {

			if (str == "TEditSpec") {
				if (s == "EditSpec1")
					continue;
				else	{
					if (((TEditSpec*)Components[i])->ListID != 0)
						((TEditSpec*)Components[i])->ItemID = 0;
					((TEditSpec*)Components[i])->Text = "";
				}
			}

			if (str == "TRichEditSpec") {
					if (((TRichEditSpec*)Components[i])->ListID != 0)
						((TRichEditSpec*)Components[i])->ItemID = 0;
				((TRichEditSpec*)Components[i])->Text = "";
			}

			if (str == "TComboBoxSpec") {
					if (((TComboBoxSpec*)Components[i])->ListID != 0)
						((TComboBoxSpec*)Components[i])->ItemID = 0;
				((TComboBoxSpec*)Components[i])->Text = "";
				((TComboBoxSpec*)Components[i])->ItemIndex = -1;
			}

			if (str == "TDateTimePickerSpec") {
				if (s == "DateTimePickerSpec1")
					continue;
				else	{
					if (((TDateTimePickerSpec*)Components[i])->ListID != 0)
						((TDateTimePickerSpec*)Components[i])->ItemID = 0;
					((TDateTimePickerSpec*)Components[i])->Format = " ";
				}
			}
		} catch (...) {
			ShowMessage("Error on clear! " + s);
		}
	}
}

TDateTime TProtocolForm::ToDate(String d)
{
	String s;

	if (d.SubString(7, 2).ToIntDef(-1) == -1)
		return 0;
	s = d.SubString(7, 2) + ".";

	if (d.SubString(5, 2).ToIntDef(-1) == -1)
		return 0;
	s += d.SubString(5, 2) + ".";

	if (d.SubString(1, 4).ToIntDef(-1) == -1)
		return 0;
	s += d.SubString(1, 4);

	try {
		StrToDate(s);
	} catch (...) {
		return 0;
	}
	return StrToDate(s);
}



void TProtocolForm::SetAllSpecModify(int Value)
{
	int i;
	String str, s;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;

		if (str == "TEditSpec")
			((TEditSpec*)Components[i])->Modify = Value;
		if (str == "TRichEditSpec")
			((TRichEditSpec*)Components[i])->Modify = Value;
		if (str == "TComboBoxSpec")
			((TComboBoxSpec*)Components[i])->Modify = Value;
		if (str == "TDateTimePickerSpec")
			((TDateTimePickerSpec*)Components[i])->Modify = Value;
	}
}

void TProtocolForm::SetMonitorModify(int Value)
{
	int i;
	String str, s;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;

		if (str == "TEditSpec")
			((TEditSpec*)Components[i])->MonitiorModify = Value;
		if (str == "TRichEditSpec")
			((TRichEditSpec*)Components[i])->MonitiorModify = Value;
		if (str == "TComboBoxSpec")
			((TComboBoxSpec*)Components[i])->MonitiorModify = Value;
		if (str == "TDateTimePickerSpec")
			((TDateTimePickerSpec*)Components[i])->MonitiorModify = Value;
	}
}

String TProtocolForm::CheckModify()
{
	int i;
	String str, s, sum;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;

	sum = "";
	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;

		if (str == "TEditSpec")
			if (((TEditSpec*)Components[i])->Modify)
				sum += "; " + s;
//				return s;
		if (str == "TRichEditSpec")
			if (((TRichEditSpec*)Components[i])->Modify)
			sum += "; " + s;
//				return s;
		if (str == "TComboBoxSpec")
			if (((TComboBoxSpec*)Components[i])->Modify)
			sum += "; " + s;
//				return s;
		if (str == "TDateTimePickerSpec")
			if (((TDateTimePickerSpec*)Components[i])->Modify)
			sum += "; " + s;
//				return s;
	}
	return sum;
}

int TProtocolForm::GetProtocol(TProtocol *p)
{
	TADOQuery *q = DM->ProtocolQuery;
	TEditSpec *sEdit;
	TRichEditSpec *sRichEdit;
	TComboBoxSpec *sComboBox;
	TDateTimePickerSpec *sTimePicker;
	int ID, ListID, ParentID, FieldType, i;
	String num, test, FieldName;
	TDate CheckDate;
	TParent *parent;
	TChildren *child;
	TNotifyEvent event;
	TBase* Item;

	TBaseList *list;
	TBase *ItemApp;
	unsigned short int yy, MM, dd;

//	if (prot != NULL)
//		prot->ProtocolClose();

	if (prot != NULL)
		prot->ProtocolClose();

	if (prot != p)
		delete prot;

	ItemApp = (TBase*)(AppointBox->Items->Objects[AppointBox->ItemIndex]);
//	ShowMessage("\"" + ItemApp->Descr + "\" - \"" +  AppointBox->Items->Strings[AppointBox->ItemIndex] + " Index=" + IntToStr(AppointBox->ItemIndex));
	prot = new TProtocol(p, ItemApp->ID);
	try {
		if (prot->ProtocolOpen(ItemApp->ID) == DEF_APPOINT)	{
			event = AppointBox->OnSelect;
			BoxItemByTBaseID(DEF_APPOINT, AppointBox);
			AppointBox->OnSelect = event;
			if (ItemApp->ID != DEF_APPOINT && ItemApp->ID != 0) {
				ShowMessage("Должность \"" + ItemApp->Descr + "\" для данного протокола занята");
			}
		}
	} catch (...) {
     	return 0;
	}

	/*if ((i = JournForm->RowByIDDoc(prot->IDDoc)) >= 0)	{
		p = (TProtocol*)JournForm->sg->Objects[0][i];
		delete p;
		JournForm->sg->Objects[0][i] = (TObject*)prot;
		prot = new TProtocol(prot, OldAppointID);
	}*/

	SetEnableSpec(prot->AppointmentID);
//	prot->ProtocolOpen();

	ClearSpecComponent();
	SetAllSpecContextPopup();

	SetAllSpecModify(false);
	SetMonitorModify(false);

	RichEditSpec1->ItemID = prot->ChildID;
	if (prot->ChildID != 0) {
		child = (TChildren*)Childrens->ItemByID(prot->ChildID);
		if (child != NULL) {
			RichEditSpec15->ItemID = child->FatherID;
			RichEditSpec14->ItemID = child->MotherID;
		}
	}

	EditSpec1->Text = IntToStr(prot->DocNo);
	DateTimePickerSpec1->Date = prot->Date;
//	DateTimePickerSpecChange(DateTimePickerSpec1);

	q->Parameters->ParamByName("iddoc")->Value = prot->IDDoc;
	q->Open();
	q->First();
	while (!q->Eof)	{

		FieldName = q->FieldByName("sp26")->AsString;
		FieldType = q->FieldByName("FieldType")->AsInteger;
		//String
		if (FieldType == ftsString)	{
			if ((sEdit = GetSpecEdit(FieldName)) != NULL)
				sEdit->Text = q->FieldByName("TextData")->AsString;
			if ((sRichEdit = GetSpecRichEdit(FieldName)) != NULL)
				sRichEdit->Text = q->FieldByName("TextData")->AsString;
		}

		//Date
		if (FieldType == ftsDate)
			if ((sTimePicker = GetSpecTimePicker(FieldName)) != NULL)	{
				CheckDate = StrToDateDef(q->FieldByName("textdata")->AsString, 0);
				sTimePicker->Date = CheckDate;
				DateTimePickerChanged(sTimePicker);
				DecodeDate(sTimePicker->Date, yy, MM, dd);
				if (yy == 1899)
					sTimePicker->Format = " ";
			}

		//Number
		if (FieldType == ftsNumber)
			if ((sEdit = GetSpecEdit(FieldName)) != NULL)	{
				num = q->FieldByName("TextData")->AsString;
				sEdit->Text = num.Trim();
			}
			if ((sRichEdit = GetSpecRichEdit(FieldName)) != NULL)	{
				num = q->FieldByName("TextData")->AsString;
				sRichEdit->Text = num.Trim();
			}

		//Box
		if (FieldType == ftsRefBox)
			if ((sComboBox = GetSpecComboBox(FieldName)) != NULL)	{
				ID = q->FieldByName("ItemID")->AsInteger;
				sComboBox->ItemID = ID;
			}

		//Button
		if (FieldType == ftsRefList)	{
			if ((sEdit = GetSpecEdit(FieldName)) != NULL)	{
				ListID = q->FieldByName("ListID")->AsInteger;
				list = ListList->GetByListID(ListID);
				if (list != NULL) {
					ID = q->FieldByName("ItemID")->AsInteger;
					Item = (TBase*)list->ItemByID(ID);
					if (Item != NULL)
						sEdit->Text = Item->Descr;
				}
			}

			if ((sRichEdit = GetSpecRichEdit(FieldName)) != NULL)	{
				sRichEdit->ListID = q->FieldByName("ListID")->AsInteger;
				sRichEdit->ItemID = q->FieldByName("ItemID")->AsInteger;
			}
		}
		q->Next();
	}
	q->Close();
    FillAnchors();
	SetMonitorModify(true);
	return 1;
}


//---------------------------------------------------------------------------
__fastcall TProtocolForm::TProtocolForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::FormMouseWheelDown(TObject *Sender,
	  TShiftState Shift, TPoint &MousePos, bool &Handled)
{

	TScrollBox *sBox = NULL;

	switch (PageControl1->ActivePageIndex) {
		case 0: sBox = ScrollBox1; break;
		case 1: sBox = ScrollBox2; break;
		case 2: sBox = ScrollBox4; break;
		case 3: sBox = ScrollBox7; break;
		case 4: sBox = ScrollBox6; break;
		case 5: sBox = ScrollBox5; break;
		case 6: sBox = ScrollBox3; break;
	}

	if (sBox != NULL)
		sBox->VertScrollBar->Position += 40;

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::FormMouseWheelUp(TObject *Sender,
	  TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	TScrollBox *sBox = NULL;

	switch (PageControl1->ActivePageIndex) {
		case 0: sBox = ScrollBox1; break;
		case 1: sBox = ScrollBox2; break;
		case 2: sBox = ScrollBox4; break;
		case 3: sBox = ScrollBox7; break;
		case 4: sBox = ScrollBox6; break;
		case 5: sBox = ScrollBox5; break;
		case 6: sBox = ScrollBox3; break;
	}

	if (sBox != NULL)
		sBox->VertScrollBar->Position -= 40;
}
//---------------------------------------------------------------------------



/*void __fastcall TProtocolForm::WMCommand(TWMCommand &msg)
{
	String str;
	int i;

	for (i = 0; i < ControlCount; i++)
		if (String(Controls[i]->ClassName()) == "TMemoSpec")
			if (((TMemoSpec*)(Controls[i]))->Focused())
				if (msg.NotifyCode == EN_CHANGE)
					SendMessageA(((TMemoSpec*)(Controls[i]))->Handle, EN_CHANGE, 0, 0);
}  */

void __fastcall TProtocolForm::MemoAutoHeight(TObject *Sender)
{
	int len, cnt, h;
	String lastChar;
	TMemo *m = (TMemoSpec*)Sender;
	TPanel *p;

	len = m->Lines->Text.Length();
	lastChar = m->Lines->Text.SubString(len - 1, 2);

	cnt = m->Perform(EM_GETLINECOUNT, 0, 0);
	/*cnt = m->Lines->Count;
	if (lastChar == "\r\n" || m->Lines->Text.data() == NULL)
		cnt++; */

	h = (cnt * (m->Font->Height + (m->Font->Height + m->Font->Size) + 1) * -1) + 6;

	if (String(((TObject*)(m->Parent))->ClassName()) == "TPanel") {
		p = (TPanel*)m->Parent;
		p->Height = h + 4;
	}
}

void __fastcall TProtocolForm::GroupBoxAutoHeight(TObject *Sender)
{
	int len, cnt, h, i, sum = 0;
	String lastChar;
	TGroupBox *g = (TGroupBox*)Sender;
	TPanel *p;
	String s;

	s = g->Caption;
	if (s == "Отец") {
		i = i;
	}

	for (i = 0; i < g->ControlCount; i++) {
		if (g->Controls[i]->Constraints->MinHeight < g->Controls[i]->Height)
			sum  += g->Controls[i]->Height + 6;
		else
			sum  += g->Controls[i]->Constraints->MinHeight + 6;
	}

	if (String(g->Parent->ClassName()) == "TGroupBox") {
		GroupBoxAutoHeight((TGroupBox*)g->Parent);
	}

	g->Height = sum;
}
//--Modify
void __fastcall TProtocolForm::RichEditModify(TObject *Sender)
{
	TRichEditSpec *m = (TRichEditSpec*)Sender;

	m->Modify = true;
}

void __fastcall TProtocolForm::EditModify(TObject *Sender)
{
	TEditSpec *m = (TEditSpec*)Sender;

	m->Modify = true;
}

void __fastcall TProtocolForm::ComboBoxModify(TObject *Sender)
{
	TComboBoxSpec *m = (TComboBoxSpec*)Sender;

	m->Modify = true;
}

void __fastcall TProtocolForm::DateTimePickerModify(TObject *Sender)
{
	TComboBoxSpec *m = (TComboBoxSpec*)Sender;

	m->Modify = true;
}
//

//--Changed

int TProtocolForm::GetTop(String ToClassName, TControl *Crtl)
{
	int s = 0;
	TControl * obj;

	obj = Crtl;
	while (String(obj->ClassName()) != ToClassName)	{
		s += obj->Top;
		obj = obj->Parent;
	}
	return s;
}

int TProtocolForm::GetTop(TObject* ParentObj, TControl *Crtl)
{
	int s = 0;
	TControl * obj;
//	String cName;

	obj = Crtl;
	while (obj != ParentObj)	{
//    	cName = obj->Name;
		s += obj->Top;
		obj = obj->Parent;
	}
	return s;
}

int TProtocolForm::GetLeft(String ToClassName, TControl *Crtl)
{
	int s = 0;
	TControl * obj;

	obj = Crtl;
	while (String(obj->ClassName()) != ToClassName)	{
		s += obj->Left;
		obj = obj->Parent;
	}
	return s;
}

int TProtocolForm::GetLeft(TObject* ParentObj, TControl *Crtl)
{
	int s = 0;
	TControl * obj;

	obj = Crtl;
	while (obj != ParentObj)	{
		s += obj->Left;
		obj = obj->Parent;
	}
	return s;
}

/*void __fastcall TProtocolForm::FillHelpBaseList(THelpListBox *hlb, TBaseEmptyList* list, String ss, int MaxCount)
{
	TBaseEmptyList *list1, *list2;
	int i, top, cnt_list1, cnt_list2;

	list1 = new TBaseEmptyList;
	list2 = new TBaseEmptyList;

	cnt_list1 = list->SubListByFirstString(list1, ss, 0);   //ByDescr
	for (i = 0; i < list1->Count; i++)
		lb->Items->AddObject(list1->Items[i]->Descr, (TObject*)(list1->Items[i]));

	cnt_list2 =  MaxCount - cnt_list1;                      //BySubString
	if (cnt_list2 > 0) {
		list->SubListBySubStringXorFirst(list2, ss, cnt_list2);
		for (i = 0; i < list2->Count; i++)
			lb->Items->AddObject(list2->Items[i]->Descr, (TObject*)(list2->Items[i]));
	}

	list1->Clear();
	list2->Clear();
	delete list1;
	delete list2;
}    */

void __fastcall TProtocolForm::FillHelpTreeBaseList(THelpListBox *hlb, TTreeBaseEmptyList* list, String ss, int MaxCount)
{
	TTreeBaseEmptyList *list1, *list2;
	int i, top, cnt_list1, cnt_list2;
	String s;

	lb->OnDrawItem = (TDrawItemEvent)(&lbDrawTreeItem);

	list1 = new TTreeBaseEmptyList;
	list2 = new TTreeBaseEmptyList;

	cnt_list1 = list->SubListByFirstString(list1, ss, 0);   //ByDescr
	for (i = 0; i < list1->Count; i++)	{
		s = list1->GetPath(i, list);
		lb->Items->AddObject(s, (TObject*)(list1->Items[i]));
	}

	cnt_list2 =  MaxCount - cnt_list1;                      //BySubString
	if (cnt_list2 > 0) {
		list->SubListBySubStringXorFirst(list2, ss, cnt_list2);
		for (i = 0; i < list2->Count; i++)
			lb->Items->AddObject(list2->GetPath(i, list), (TObject*)(list2->Items[i]));
	}

	list1->Clear();
	list2->Clear();
	delete list1;
	delete list2;
}

void __fastcall TProtocolForm::FillHelpBaseList(THelpListBox *hlb, TBaseEmptyList* list, String ss, int MaxCount)
{
	TBaseEmptyList *list1, *list2;
	int i, top, cnt_list1, cnt_list2;

	lb->OnDrawItem = (TDrawItemEvent)(&lbDrawItem);

	list1 = new TBaseEmptyList;
	list2 = new TBaseEmptyList;

	cnt_list1 = list->SubListByFirstString(list1, ss, 0);   //ByDescr
	for (i = 0; i < list1->Count; i++)
		lb->Items->AddObject(list1->Items[i]->Descr, (TObject*)(list1->Items[i]));

	cnt_list2 =  MaxCount - cnt_list1;                      //BySubString
	if (cnt_list2 > 0) {
		list->SubListBySubStringXorFirst(list2, ss, cnt_list2);
		for (i = 0; i < list2->Count; i++)
			lb->Items->AddObject(list2->Items[i]->Descr, (TObject*)(list2->Items[i]));
	}

	list1->Clear();
	list2->Clear();
	delete list1;
	delete list2;
}





void __fastcall TProtocolForm::lbChange(TRichEditSpec *re, String ss,int ListID)
{
	const MaxCount = 200;
	TBaseEmptyList *list;
	TTreeBaseEmptyList* tlist;
	int i, top;

	if (ListList == NULL || ListID == 0)
		return;

//	lb->Parent = GetParentFor_lb("ScrollBox"); //ScrollBox1;

	list = (TBaseEmptyList*)(ListList->GetByListID(ListID));

	if (list == NULL)
		return;

	lb->Clear();

	lb->SubString = ss;

	if (list->IsTree == 0)
		FillHelpBaseList(lb, list, ss, MaxCount);
	else	{
		tlist = new TTreeBaseEmptyList();
		tlist->AddItemsByRoot((TTreeBaseList*)list, re->AnchorID);
		FillHelpTreeBaseList(lb, tlist, ss, MaxCount);
        tlist->Clear();
		delete tlist;
	}


	if (lb->Count == 0)
		lb->Visible = false;
	else	{
//		top = GetTop("TScrollBox", re);
		top = GetTop(lb->Parent, re);
		if ((lb->Height + top + re->Height + 2) > lb->Parent->Height)	{
			lb->Top = top - lb->Height;
		}
		else	{
			top += re->Height;
			lb->Top = top + 2;
		}
		lb->Left = GetLeft(lb->Parent, re);
		lb->Width = re->Width;
		lb->Visible = true;
	}
}

String __fastcall TProtocolForm::GetLastWord(String str)
{
	int i = str.Length();

	while (i > 0 && str[i] != ' ')	{
		i--;
	}

	return str.SubString(i + 1, str.Length() - i);

}

void __fastcall TProtocolForm::RichEditChanged(TObject *Sender)
{
	TRichEditSpec *m = (TRichEditSpec*)Sender;
	String ss;
	int p;

//	RichEditAutoHeight(Sender);
    RichEditAutoHeightLevelUp(m);
	RichEditModify(Sender);
	if (m->FieldType == ftsRefList)
		if (m->Name != "RichEditSpec1")
			m->SetStillItemID(0);

	if (ComboBox1 == NULL) {
		return;
	}

//	ss = GetLastWord(m->Text.SubString(1 ,m->SelStart));
	if (m->Focused())
		ss = m->GetActivePhrase().Text.Trim();

	if (ss == "")	{
		lb->Visible = false;
		return;
	}

	switch (ComboBox1->ItemIndex)	{
		case 2:
			if (m->Focused())	{
				lbChange(m, ss, m->ListID);
				lb->JoinSpec = m;
			}
			break;
		case 1:
			if (m->Focused() && lb->Visible)	{
				lbChange(m, ss, m->ListID);
				lb->JoinSpec = m;
			}
			break;
		case 0:
            lb->Close();
			break;
	}
}

void __fastcall TProtocolForm::EditChanged(TObject *Sender)
{
	EditModify(Sender);
}

void __fastcall TProtocolForm::ComboBoxChanged(TObject *Sender)
{
	ComboBoxSpecAfterSetItemID(Sender);
	ComboBoxModify(Sender);
}

void __fastcall TProtocolForm::DateTimePickerChanged(TObject *Sender)
{
	DateTimePickerModify(Sender);
	DateTimePickerSpecSetFormat(Sender);
}
//Changed--

/*void __fastcall TProtocolForm::RichEditAutoHeight(TObject *Sender)
{
	int len, cnt, h, LinesCount, NewHeight;
	String lastChar;
	TRichEditSpec *m = (TRichEditSpec*)Sender;
	TPanel *p;
	TGroupBox *g;

	len = m->Lines->Text.Length();
	cnt = m->Perform(EM_GETLINECOUNT, 0, 0);
	m->Perform(WM_VSCROLL, SB_TOP, 0);

	lastChar = m->Lines->Text.SubString(len - 1, 2);

	h = (cnt * (m->Font->Height + (m->Font->Height + m->Font->Size) + 1) * -1) + 10;

	if (String(((TObject*)(m->Parent))->ClassName()) == "TPanel") {
		p = (TPanel*)m->Parent;

		if (p->Height != h)	{
			NewHeight = h;
			if (NewHeight > p->Constraints->MinHeight)
				p->Height = NewHeight;
			else
				p->Height = p->Constraints->MinHeight;

			if (String(((TObject*)(p->Parent))->ClassName()) == "TGroupBox") {
				g = (TGroupBox*)p->Parent;
				GroupBoxAutoHeight(g);
			}
		}
	}
}*/


void __fastcall TProtocolForm::RichEditAutoHeight(TObject *Sender)
{
	int len, cnt, h, LinesCount, NewHeight;
	String lastChar;
	TRichEditSpec *m = (TRichEditSpec*)Sender;
	TPanel *p;
	TGroupBox *g;

	len = m->Lines->Text.Length();
	cnt = m->Perform(EM_GETLINECOUNT, 0, 0);
	m->Perform(WM_VSCROLL, SB_TOP, 0);

	lastChar = m->Lines->Text.SubString(len - 1, 2);

	h = (cnt * (m->Font->Height + (m->Font->Height + m->Font->Size) + 1) * -1) + 10 + 6;

	if (String(((TObject*)(m->Parent))->ClassName()) == "TPanel") {
		p = (TPanel*)m->Parent;

		if (p->Height != h)	{
			NewHeight = h;
			if (NewHeight > p->Constraints->MinHeight)
				p->Height = NewHeight;
			else
				p->Height = p->Constraints->MinHeight;
			//PanelControlsAutoSize(p);

			if (String(((TObject*)(p->Parent))->ClassName()) == "TGroupBox") {
				g = (TGroupBox*)p->Parent;
				GroupBoxAutoHeight(g);
			}
		}
	}
}

void __fastcall TProtocolForm::SpeedButton2Click(TObject *Sender)
{
	/*GroupDataList->SetAnchorByID(RichEditSpec6->AnchorID);
	if (GroupDataList->Anchor != NULL)
		GroupDataForm->StartID = GroupDataList->Anchor->ID;//"    2U   "; //Категория детей

	GroupDataForm->AddRichEdit = RichEditSpec6;
	GroupDataForm->Show();*/

	/*DiagnosisList->SetAnchorByID(RichEditSpec3->AnchorID);
	if (GroupDataList->Anchor != NULL)
		DiagnosisForm->StartID = GroupDataList->Anchor->ID;

	DiagnosisForm->AddRichEdit = RichEditSpec3;
	DiagnosisForm->Show(); */

	ShowDiagnosisForm(RichEditSpec3, &(DiagnosisForm->AddRichEdit));

//	DiagnosisForm->AddRichEdit = RichEditSpec3;
//	DiagnosisForm->Show();
}
//---------------------------------------------------------------------------



void __fastcall TProtocolForm::WndProc(Messages::TMessage &Message)
{
	int i;
	TRichEditSpec* r;
	String str, s;
	TWinControl *ctrl;

	if (Message.Msg == WM_EXITSIZEMOVE ) {
		for (i = 0; i < ComponentCount; i++) {
			str = Components[i]->ClassName();
			s = Components[i]->Name;
			/*if (s == "RichEditSpec103")
				continue;
			if (s == "RichEditSpec104")
				continue;
			if (s == "RichEditSpec108")
				continue;
			if (s == "RichEditSpec109")
				continue;

			if (String(Components[i]->ClassName()) == "TRichEditSpec") {
				RichEditAutoHeight((TRichEditSpec*)Components[i]);
			} */
            if (String(Components[i]->ClassName()) == "TRichEditSpec")
			RichEditAutoHeightLevelUp((TRichEditSpec*)Components[i]);
		}
	}
	TForm::WndProc(Message);
}



void __fastcall TProtocolForm::SpeedButton1Click(TObject *Sender)
{
	ShowOrganizationsForm(RichEditSpec4, &(OrganizationsForm->SetRichEdit));

	/*OrganizationsForm->SetRichEdit = RichEditSpec4;
	OrganizationsForm->Show();*/
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::RichEditSpecAfterSetItemID(TObject *Sender)
{
	TRichEditSpec* re = (TRichEditSpec*)Sender;
	TNotifyEvent event = re->OnChange;
	int i;

	re->OnChange = NULL;
	SetTextForSpec(re);
	re->OnChange = event;
	re->Modify = true;

	lb->Close();
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::SpeedButton5Click(TObject *Sender)
{
	AreasForm->SetRichEdit = RichEditSpec7;
	AreasForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::ShowGroupDataForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork)
{
	GroupDataList->SetAnchorID(RichEditDest->AnchorID);
//	if (GroupDataList->AnchorID != 0)
		GroupDataForm->StartID = GroupDataList->AnchorID;

	*RichEditWork = RichEditDest;
	GroupDataForm->Show();
}

void __fastcall TProtocolForm::ShowDiagnosisForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork)
{
	DiagnosisList->SetAnchorID(RichEditDest->AnchorID);
//	if (DiagnosisList->AnchorID != 0)
		DiagnosisForm->StartID = DiagnosisList->AnchorID;

	*RichEditWork = RichEditDest;
	DiagnosisForm->Show();
}

void __fastcall TProtocolForm::ShowRecommendForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork)
{
	RecommendList->SetAnchorID(RichEditDest->AnchorID);
//	if (RecommendList->AnchorID != 0)
		RecommendForm->StartID = RecommendList->AnchorID;

	*RichEditWork = RichEditDest;
	RecommendForm->Show();
}

void __fastcall TProtocolForm::ShowOrganizationsForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork)
{
	Organizations->SetAnchorID(RichEditDest->AnchorID);
//	if (Organizations->AnchorID != 0)
		OrganizationsForm->StartID = Organizations->AnchorID;

	*RichEditWork = RichEditDest;
	OrganizationsForm->Show();
}

//ShowRecommendForm(RichEditSpec62, &(RecommendForm->AddRichEdit));
//ShowDiagnosisForm(RichEditSpec62, &(DiagnosisForm->AddRichEdit));
//ShowGroupDataForm(RichEditSpec12, &(GroupDataForm->AddRichEdit));
//ShowOrganizationsForm(RichEditSpec12, &(OrganizationsForm->AddRichEdit));

void __fastcall TProtocolForm::SpeedButton3Click(TObject *Sender)
{
	/*GroupDataForm->StartID = 102;//"    2U   "; //Категория детей
	GroupDataForm->AddRichEdit = RichEditSpec6;
	GroupDataList->SetAnchorByID(102);
	GroupDataForm->Show();  */

	/*GroupDataList->SetAnchorByID(RichEditSpec6->AnchorID);
	if (GroupDataList->Anchor != NULL)
		GroupDataForm->StartID = GroupDataList->Anchor->ID;//"    2U   "; //Категория детей

	GroupDataForm->AddRichEdit = RichEditSpec6;
	GroupDataForm->Show(); */

	ShowGroupDataForm(RichEditSpec6, &(GroupDataForm->AddRichEdit));

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton4Click(TObject *Sender)
{
	HANDLE h;
	unsigned long int fSizeH, fSizeL;

	if (OpenDialog1->Execute()) {
		h = CreateFileA(OpenDialog1->FileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		fSizeL = GetFileSize(h, &fSizeH);
		CloseHandle(h);
		if (fSizeL > 5120)	{
			MessageBoxA(ProtocolForm->Handle, "Файл превышает допустимый размер 5 кБайт. Файл не будет загружен!", "Открытие текстового файла", MB_OK);
			return;
		}
		RichEditSpec9->Lines->LoadFromFile(OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::FillChild(TChildren* Item)
{
	TParent *parent;

	RichEditSpec1->ItemID = Item->ID;
	DateTimePickerSpec2->Date = Item->Birthday;
	DateTimePickerChanged(DateTimePickerSpec2);
	ComboBoxSpec1->ItemID = Item->SexID;
	RichEditSpec7->ItemID = Item->AreaID;
	RichEditSpec2->Text = Item->Adress;
	RichEditSpec4->ItemID = Item->PlaceStudyID;
	RichEditSpec5->Text = Item->History;
	RichEditSpec8->Text = Item->ExtInfo;

	if (Item->FatherID != 0) {
		parent = Parents->ParentByID(Item->FatherID);
		if (parent != NULL)
			FillFather(parent);
	}

	if (Item->MotherID != 0) {
		parent = Parents->ParentByID(Item->MotherID);
		if (parent != NULL)
			FillMother(parent);
	}
}

void __fastcall TProtocolForm::FillFather(TParent* Item)
{
	RichEditSpec15->ItemID = Item->ID;
	ComboBoxSpec20->Text = Item->Age;
	ComboBoxSpec3->ItemID = Item->Education;
	ComboBoxSpec22->Text = Item->Work;
    ComboBoxSpec4->ItemID = Item->BadHabit;
    ComboBoxSpec5->ItemID = Item->BadStrain;
}

void __fastcall TProtocolForm::FillMother(TParent* Item)
{
	RichEditSpec14->ItemID = Item->ID;
	ComboBoxSpec13->Text = Item->Age;
	ComboBoxSpec6->ItemID = Item->Education;
	ComboBoxSpec11->Text = Item->Work;
	ComboBoxSpec7->ItemID = Item->BadHabit;
	ComboBoxSpec8->ItemID = Item->BadStrain;
}

void __fastcall TProtocolForm::ButtonClickGetChildren(TObject *Sender)
{
	TChildrensForm *f = ChildrensForm;
	int Index;

	Index = Childrens->IndexByID(RichEditSpec1->ItemID);
	if (Index != -1) {
        f->RowOnShow = Index;
	}


	/*f->FIORichEdit = RichEditSpec1;
	f->BirthdayDateTimePicker = DateTimePickerSpec2;
	f->SexComboBox = ComboBoxSpec1;
	f->AreaRichEdit = RichEditSpec7;
	f->AdressRichEdit = RichEditSpec2;
	f->WhereStudyRichEdit = RichEditSpec4;
	f->HistoryStudyRichEdit = RichEditSpec5;
	f->ExtInfoRichEdit = RichEditSpec8; */
	f->SenderProtocol = 1;

	f->Show();

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::DateTimePickerSpecSetFormat(TObject *Sender)
{
	TDateTimePickerSpec *dt = (TDateTimePickerSpec*)Sender;
	String str;

	dt->Modify = true;
	str = dt->Date.DateString();
	if (str == "30.12.1899")
		dt->Format = " ";
	else
		dt->Format = "";
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::DateTimePickerSpecKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	TDateTimePickerSpec *dt = (TDateTimePickerSpec*)Sender;

	if (Key == 46)
		dt->Format = " ";
	else
		dt->Format = "";

}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::ButtonClickGetFather(TObject *Sender)
{
	ParentsForm->FIORichEdit = RichEditSpec15;
	ParentsForm->AgeRichEdit = RichEditSpec20;
	ParentsForm->EducationComboBox = ComboBoxSpec3;
	ParentsForm->PlaceWorkRichEdit = RichEditSpec22;
	ParentsForm->BadHabitRichComboBox = ComboBoxSpec4;
	ParentsForm->BadStrainRichComboBox = ComboBoxSpec5;
	ParentsForm->SenderProtocol = 1;
	ParentsForm->Show();
}


void __fastcall TProtocolForm::ButtonClickGetMother(TObject *Sender)
{
	ParentsForm->FIORichEdit = RichEditSpec14;
	ParentsForm->AgeRichEdit = RichEditSpec13;
	ParentsForm->EducationComboBox = ComboBoxSpec6;
	ParentsForm->PlaceWorkRichEdit = RichEditSpec11;
	ParentsForm->BadHabitRichComboBox = ComboBoxSpec7;
	ParentsForm->BadStrainRichComboBox = ComboBoxSpec8;
	ParentsForm->SenderProtocol = 1;
    ParentsForm->Show();
}
//---------------------------------------------------------------------------
//ShowGroupDataForm(RichEditSpec39, &(GroupDataForm->AddRichEdit));
//ShowDiagnosisForm(RichEditSpec37, &(DiagnosisForm->AddRichEdit));

void __fastcall TProtocolForm::SpeedButton9Click(TObject *Sender)
{
	ShowDiagnosisForm(RichEditSpec37, &(DiagnosisForm->AddRichEdit));
}
//---------------------------------------------------------------------------



void __fastcall TProtocolForm::SpeedButton10Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec39, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton11Click(TObject *Sender)
{
	ShowDiagnosisForm(RichEditSpec40, &(DiagnosisForm->AddRichEdit));   //230

	/*DiagnosisForm->StartID = 230;
	DiagnosisForm->AddRichEdit = RichEditSpec40;
	DiagnosisForm->Show(); */
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton12Click(TObject *Sender)
{
	    /*
        GroupDataForm->StartID = 59;
        	GroupDataForm->AddRichEdit = RichEditSpec38;
			GroupDataForm->Show();
    */
	ShowGroupDataForm(RichEditSpec38, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton13Click(TObject *Sender)
{
/*
    	GroupDataForm->StartID = 56;
    	GroupDataForm->AddRichEdit = RichEditSpec43;
		GroupDataForm->Show();
*/
	ShowGroupDataForm(RichEditSpec43, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton14Click(TObject *Sender)
{
	    /*
        GroupDataForm->StartID = 55;
        	GroupDataForm->AddRichEdit = RichEditSpec42;
			GroupDataForm->Show();
	*/
	ShowGroupDataForm(RichEditSpec42, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton16Click(TObject *Sender)
{
/*
    	GroupDataForm->StartID = 46;
    	GroupDataForm->AddRichEdit = RichEditSpec19;
		GroupDataForm->Show();

*/
	ShowGroupDataForm(RichEditSpec19, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton15Click(TObject *Sender)
{
		/*
        GroupDataForm->StartID = 44;
        	GroupDataForm->AddRichEdit = RichEditSpec12;
			GroupDataForm->Show();
	*/
	ShowGroupDataForm(RichEditSpec12, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton17Click(TObject *Sender)
{
/*
    	GroupDataForm->AddRichEdit = RichEditSpec35;
		GroupDataForm->Show();
*/
	ShowGroupDataForm(RichEditSpec35, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton18Click(TObject *Sender)
{
		/*
        DiagnosisForm->StartID = 230;
        	DiagnosisForm->AddRichEdit = RichEditSpec62;
			DiagnosisForm->Show();
	*/

	ShowDiagnosisForm(RichEditSpec62, &(DiagnosisForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton19Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec61, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 3;
	RecommendForm->AddRichEdit = RichEditSpec61;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton20Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec60, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 3;
	RecommendForm->AddRichEdit = RichEditSpec60;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::SpeedButton24Click(TObject *Sender)
{

    ShowGroupDataForm(RichEditSpec67, &(GroupDataForm->AddRichEdit));
	/*GroupDataForm->StartID = 3;
	GroupDataForm->AddRichEdit = RichEditSpec67;
	GroupDataForm->Show(); */
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton23Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec66, &(GroupDataForm->AddRichEdit));
	/*GroupDataForm->StartID = 62;
	GroupDataForm->AddRichEdit = RichEditSpec66;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton22Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec65, &(GroupDataForm->AddRichEdit));
	
	/*GroupDataForm->StartID = 63;
	GroupDataForm->AddRichEdit = RichEditSpec65;
	GroupDataForm->Show(); */
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton28Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec71, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 41;
	GroupDataForm->AddRichEdit = RichEditSpec71;
	GroupDataForm->Show(); */
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton27Click(TObject *Sender)
{
	ShowDiagnosisForm(RichEditSpec70, &(DiagnosisForm->AddRichEdit));

	/*DiagnosisForm->StartID = 231;
	DiagnosisForm->AddRichEdit = RichEditSpec70;
	DiagnosisForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton26Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec69, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 4;
	RecommendForm->AddRichEdit = RichEditSpec69;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton25Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec68, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 4;
	RecommendForm->AddRichEdit = RichEditSpec68;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton32Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec77, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 33;
	GroupDataForm->AddRichEdit = RichEditSpec77;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton37Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec82, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 32;
	GroupDataForm->AddRichEdit = RichEditSpec82;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton36Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec81, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 30;
	GroupDataForm->AddRichEdit = RichEditSpec81;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton35Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec80, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 28;
	GroupDataForm->AddRichEdit = RichEditSpec80;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton34Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec79, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 27;
	GroupDataForm->AddRichEdit = RichEditSpec79;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton33Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec78, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 25;
	GroupDataForm->AddRichEdit = RichEditSpec78;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton38Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec83, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 23;
	GroupDataForm->AddRichEdit = RichEditSpec83;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton39Click(TObject *Sender)
{
    ShowGroupDataForm(RichEditSpec84, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 21;
	GroupDataForm->AddRichEdit = RichEditSpec84;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton40Click(TObject *Sender)
{
    ShowDiagnosisForm(RichEditSpec85, &(DiagnosisForm->AddRichEdit));

	/*DiagnosisForm->StartID = 233;
	DiagnosisForm->AddRichEdit = RichEditSpec85;
	DiagnosisForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton41Click(TObject *Sender)
{
	ShowDiagnosisForm(RichEditSpec86, &(DiagnosisForm->AddRichEdit));

	/*RecommendForm->StartID = 2;
	RecommendForm->AddRichEdit = RichEditSpec86;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton42Click(TObject *Sender)
{
	ShowDiagnosisForm(RichEditSpec87, &(DiagnosisForm->AddRichEdit));

	/*RecommendForm->StartID = 2;
	RecommendForm->AddRichEdit = RichEditSpec87;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton43Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec89, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 2;
	GroupDataForm->AddRichEdit = RichEditSpec89;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton44Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec90, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 4;
	GroupDataForm->AddRichEdit = RichEditSpec90;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton45Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec91, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 6;
	GroupDataForm->AddRichEdit = RichEditSpec91;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton46Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec92, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 0;
	GroupDataForm->AddRichEdit = RichEditSpec92;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton47Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec93, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 10;
	GroupDataForm->AddRichEdit = RichEditSpec93;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton48Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec94, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 12;
	GroupDataForm->AddRichEdit = RichEditSpec94;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton49Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec95, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 14;
	GroupDataForm->AddRichEdit = RichEditSpec95;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton50Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec96, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 16;
	GroupDataForm->AddRichEdit = RichEditSpec96;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton51Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec97, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 18;
	GroupDataForm->AddRichEdit = RichEditSpec97;
	GroupDataForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton52Click(TObject *Sender)
{
	ShowDiagnosisForm(RichEditSpec98, &(DiagnosisForm->AddRichEdit));

	/*DiagnosisForm->StartID = 234;
	DiagnosisForm->AddRichEdit = RichEditSpec98;
	DiagnosisForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton53Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec99, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 1;
	RecommendForm->AddRichEdit = RichEditSpec99;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton54Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec100, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 1;
	RecommendForm->AddRichEdit = RichEditSpec100;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------



int TProtocolForm::FieldExists(ISpecField *spec)
{
	TADOQuery *q;
	int cnt;

	q = DM->FieldExistsQuery;

	q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
	q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;

	q->Open();
	cnt = q->FieldByName("cnt")->AsInteger;
	q->Close();

	return cnt;
}


int TProtocolForm::SaveStringField(ISpecField *spec)
{
	TADOQuery *q;

	if (FieldExists(spec))	{
		if (spec->TextData.data() == NULL ||spec->TextData.Trim() == "") {//delete
			q = DM->ProtocolFieldDeleteQuery;
			q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;
			q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
			return q->ExecSQL();
		}
		q = DM->ProtocolFieldUpdateQuery;									  //Update
	}
	else	{
		if (spec->TextData.data() == NULL ||spec->TextData.Trim() == "")  //Empty
			return 1;
		q = DM->ProtocolFieldInsertQuery;                                     //Insert
	}

	q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
	q->Parameters->ParamByName("TEXTDATA")->Value = spec->TextData;
	q->Parameters->ParamByName("FIELDTYPE")->Value = spec->FieldType;
	q->Parameters->ParamByName("LISTID")->Value = 0;
	q->Parameters->ParamByName("ITEMID")->Value = 0;
	q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;

	q->ExecSQL();
	return 1;
}

int TProtocolForm::SaveNumberField(ISpecField *spec)
{
	TADOQuery *q;
	int check;

	if (FieldExists(spec))	{
		if (spec->TextData.data() == NULL ||spec->TextData.Trim() == "") {//delete
			q = DM->ProtocolFieldDeleteQuery;
			q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;
			q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
			return q->ExecSQL();
		}
		q = DM->ProtocolFieldUpdateQuery;									  //Update
	}
	else	{
		if (spec->TextData.data() == NULL ||spec->TextData.Trim() == "")  //Empty
			return 1;
		q = DM->ProtocolFieldInsertQuery;                                     //Insert
	}

	q->Parameters->ParamByName("SP26")->Value = spec->FieldName;

	check = StrToFloatDef(spec->TextData, 1);
	if (check)	{
		check = StrToFloatDef(spec->TextData, 0);
		if (!check)
			return ERROR;
	}

	q->Parameters->ParamByName("TEXTDATA")->Value = spec->TextData;
	q->Parameters->ParamByName("FIELDTYPE")->Value = spec->FieldType;
	q->Parameters->ParamByName("LISTID")->Value = 0;
	q->Parameters->ParamByName("ITEMID")->Value = 0;
	q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;

	q->ExecSQL();

	return 1;
}

int TProtocolForm::SaveRefListField(ISpecField *spec)
{
	TADOQuery *q;

	if (spec->ListID == 0)	{
		ShowMessage("Не куазан ListID");
		return ERROR;
    }	

	if (FieldExists(spec))	{
		if (spec->ItemID == 0) {
			if (spec->ListID == 0 && spec->TextData == "") {                       //delete
				q = DM->ProtocolFieldDeleteQuery;
				q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;
				q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
				return q->ExecSQL();
			}
		}
		q = DM->ProtocolFieldUpdateQuery;									  //Update
	}
	else	{
		if (spec->ListID == 0 ||spec->ItemID == 0)  						  //Empty
			return 1;
		q = DM->ProtocolFieldInsertQuery;                                     //Insert
	}

	q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
	q->Parameters->ParamByName("TEXTDATA")->Value = "";
	q->Parameters->ParamByName("FIELDTYPE")->Value = spec->FieldType;
	q->Parameters->ParamByName("LISTID")->Value = spec->ListID;
	q->Parameters->ParamByName("ITEMID")->Value = spec->ItemID;
	q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;

	q->ExecSQL();
	return 1;
}

int TProtocolForm::SaveRefBoxField(ISpecField *spec)
{
	TADOQuery *q;

	if (spec->ListID == 0)	{
		ShowMessage("Не куазан ListID");
		return ERROR;
    }

	if (FieldExists(spec))	{
		if (spec->ItemID == 0) {                       //delete
			q = DM->ProtocolFieldDeleteQuery;
			q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;
			q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
			return q->ExecSQL();
		}
		q = DM->ProtocolFieldUpdateQuery;									  //Update
	}
	else	{
		if (spec->ItemID == 0)  					  //Empty
			return 1;
		q = DM->ProtocolFieldInsertQuery;                                     //Insert
	}

	q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
	q->Parameters->ParamByName("TEXTDATA")->Value = "";
	q->Parameters->ParamByName("FIELDTYPE")->Value = spec->FieldType;
	q->Parameters->ParamByName("LISTID")->Value = spec->ListID;
	q->Parameters->ParamByName("ITEMID")->Value = spec->ItemID;
	q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;

	q->ExecSQL();
	return 1;
}

int TProtocolForm::SaveDateField(ISpecField *spec)
{
	TADOQuery *q;

	if (FieldExists(spec))	{
		if (spec->TextData == "") {                     				  //delete
			q = DM->ProtocolFieldDeleteQuery;
			q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;
			q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
			return q->ExecSQL();
		}
		q = DM->ProtocolFieldUpdateQuery;									  //Update
	}
	else	{
		if (spec->TextData == "")  					  					  //Empty
			return 1;
		q = DM->ProtocolFieldInsertQuery;                                     //Insert
	}

	q->Parameters->ParamByName("SP26")->Value = spec->FieldName;
	q->Parameters->ParamByName("TEXTDATA")->Value = spec->TextData;
	q->Parameters->ParamByName("FIELDTYPE")->Value = spec->FieldType;
	q->Parameters->ParamByName("LISTID")->Value = 0; //spec->ListID;
	q->Parameters->ParamByName("ITEMID")->Value = 0; //spec->ItemID;
	q->Parameters->ParamByName("IDDOC")->Value = prot->IDDoc;

	q->ExecSQL();
	return 1;
}

int TProtocolForm::SaveSpecComponent(ISpecField *spec)
{
	switch (spec->FieldType) {
		case ftsString:
			if (SaveStringField(spec)) return 1; break;
		case ftsNumber:
			if (SaveNumberField(spec)) return 1; break;
		case ftsDate:
			if (SaveDateField(spec)) return 1; break;
		case ftsRefList:
			if (SaveRefListField(spec)) return 1; break;
		case ftsRefBox:
			if (SaveRefBoxField(spec)) return 1; break;
		default: ShowMessage("FieldType не определён.");
	}
	return 0;

}

int TProtocolForm::CheckForNewItem(ISpecField *spec)
{
	TBaseList *list;

	if (spec->TextData == "")	{
     	spec->ItemID = 0;
		return 0;
	}
	if (spec->FieldType != 4)
		return 0;
	if (spec->ItemID != 0)
		return 0;

	list = ListList->GetByListID(spec->ListID);
	if (list == NULL)
		throw "Error!";
	if (list->ItemByID(spec->ItemID) != NULL)
		return 0;

	return 1;
}

void __fastcall TProtocolForm::DisplayErrorValue(TObject *Sender)
{
	String CName;
	TRichEditSpec *re;

	CName = Sender->ClassName();
	if (CName == "TRichEditSpec") {
		re = (TRichEditSpec*)Sender;
		ShowMessage("Не верно заполнено поле" + re->FieldName);
		re->SetFocus();
	}

}

int TProtocolForm::SaveMother()
{
	TParent *parent = NULL;
	int Flag_NewParent;

	if (RichEditSpec13->Text != "" && RichEditSpec13->Text.ToIntDef(-1) < 0)	{
		/*RichEditSpec13->SetFocusSpec();
		HighLight(RichEditSpec13);*/
		return 1;
	}

	Flag_NewParent = CheckForNewItem(RichEditSpec14);
	if (Flag_NewParent)
		parent = new TParent(0);
	else
		parent = (TParent*)Parents->ItemByID(RichEditSpec14->ItemID);
	/*if (RichEditSpec14->ItemID == 0)	{
		if (RichEditSpec14->Text != "")
			parent = new TParent(0);
		else
			return 0;
	}
	else	{
		parent = (TParent*)Parents->ItemByID(RichEditSpec14->ItemID);
		if (parent == NULL)	{
			ShowMessage("Не удалось найти предыдущую информацию о матери. \nСоздана новая запись в таблице \"Родители\".");
			parent = new TParent(0);
		}
	} */
	if (parent != NULL)	{

		parent->Descr = RichEditSpec14->Text;
		parent->Age = RichEditSpec13->Text.ToIntDef(0);
		parent->Education = ComboBoxSpec6->ItemID;
		parent->Work = RichEditSpec11->Text;
		parent->BadHabit = ComboBoxSpec7->ItemID;
		parent->BadStrain = ComboBoxSpec8->ItemID;

		parent->Save(DM->ParentGetMaxQuery, DM->ParentInsertQuery, DM->ParentUpdateQuery, NULL);
//		if (RichEditSpec14->ItemID == 0)	{
		if (Flag_NewParent)	{
			Parents->Add(parent);
			ParentsForm->FormShow(this);
		}
		RichEditSpec14->ItemID = parent->ID;
	}
	return 1;
}

int TProtocolForm::SaveFather()
{
	TParent *parent = NULL;

	if (RichEditSpec20->Text != "" && RichEditSpec20->Text.ToIntDef(-1) < 0)	{
		/*RichEditSpec20->SetFocusSpec();
		HighLight(RichEditSpec20);*/
		return 1;
	}

	if (RichEditSpec15->ItemID == 0)	{
		if (RichEditSpec15->Text != "")
			parent = new TParent(0);
		else
			return 1;
	}
	else
		parent = (TParent*)Parents->ItemByID(RichEditSpec15->ItemID);

	if (parent == NULL)
		ShowMessage("Не удалось найти предыдущую информацию об отце. \nСоздана новая запись в таблице \"Родители\".");
	else {
		parent->Descr = RichEditSpec15->Text;
		parent->Age = RichEditSpec20->Text.ToIntDef(0);
		parent->Education = ComboBoxSpec3->ItemID;
		parent->Work = RichEditSpec22->Text;
		parent->BadHabit = ComboBoxSpec4->ItemID;
		parent->BadStrain = ComboBoxSpec5->ItemID;

		parent->Save(DM->ParentGetMaxQuery, DM->ParentInsertQuery, DM->ParentUpdateQuery, NULL);
		if (RichEditSpec15->ItemID == 0)	{
			Parents->Add(parent);
            ParentsForm->FormShow(this);
		}
		RichEditSpec15->ItemID = parent->ID;
	}
	return 1;
}


int TProtocolForm::SaveChildren()
{
	int NEW_CHILD;
	TChildren *child;

	NEW_CHILD = CheckForNewItem(RichEditSpec1);
	if (NEW_CHILD)
		child = new TChildren(2, 0, 0);
	else
		child = (TChildren*)Childrens->ItemByID(RichEditSpec1->ItemID);

	if (child == NULL)	{
		/*ShowMessage("Не удалось найти предыдущую информацию о ребёнке. \nСоздана новая запись в таблице \"Дети\".");
		child = new TChildren(2, 0, 0);  */
		return 1;
	}

	child->Descr = RichEditSpec1->Text;
	child->AreaID = RichEditSpec7->ItemID;
	child->FatherID = RichEditSpec15->ItemID;
	child->MotherID = RichEditSpec14->ItemID;
	child->Adress = RichEditSpec2->Text;
	child->Birthday = DateTimePickerSpec2->DateSpec;
	child->PlaceStudyID = RichEditSpec4->ItemID;
	child->History = RichEditSpec5->Text;
	child->ExtInfo = RichEditSpec8->Text;
	child->SexID = ComboBoxSpec1->ItemID;

	child->Save(DM->ChildrenGetMaxQuery, DM->ChildrenInsertQuery, DM->ChildrenUpdateQuery, NULL);
	if (NEW_CHILD)
		Childrens->Add(child);
	RichEditSpec1->ItemID = child->ID;

	return 1;
}

int TProtocolForm::SaveAllSpecComponents()
{
	int i, temp;
	String str, s;
	ISpecField *sf;
	TComponent *c;
	TEditSpec *EditSpec;
	TRichEditSpec *RichEditSpec;
	TComboBoxSpec *ComboBoxSpec;
	TDateTimePickerSpec *DateTimePickerSpec;
	String msg = "Не удалось сохранить поле";
//	TADOQuery *q = DM->JournalChildUpdateQuery;


	/*	child = (TChildren*)Childrens->ItemByID(RichEditSpec1->ItemID);
	if (child != NULL) {
		if (child->Descr != RichEditSpec1->Text) {
			RichEditSpec1->ItemID = 0;
		}
	} */

	if (!SaveMother())
		return 0;
	if (!SaveFather())
		return 0;
	if (!SaveChildren())
		return 0;

	prot->DocNo = EditSpec1->Text.ToIntDef(0);
	prot->Date = DateTimePickerSpec1->DateSpec;
	prot->ChildID = RichEditSpec1->ItemID;
	prot->UpdateToDB();
	prot->SaveChild();

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;
		if (s == "RichEditSpec7") {
			s = s;
		}
		if (str == "TEditSpec") {
			EditSpec = (TEditSpec*)Components[i];
			sf = (ISpecField*)EditSpec;
			if (!EditSpec->Modify)
				continue;
			if (!SaveSpecComponent(sf))	{
				sf->SetFocusSpec();
				ShowMessage(msg + " \"" + sf->FieldName + "\".");
				HighLight(sf);
				return 0;
			}
		}
		if (str == "TRichEditSpec") {
			if (s == "RichEditSpec1") {
            	sf = sf;    
			}
			RichEditSpec = (TRichEditSpec*)Components[i];
			if (!RichEditSpec->Modify)
				continue;
			sf = (ISpecField*)RichEditSpec;

			if (RichEditSpec->ListID != 0 && RichEditSpec->ItemID == 0 && RichEditSpec->TextData != "") {
				RichEditSpec->SetStillItemID(ListList->SaveNewItemOfList(RichEditSpec->ListID,
						RichEditSpec->TextData, RichEditSpec->AnchorID));
			}

			if (!SaveSpecComponent(sf))	{
//				sf->SetFocusSpec();
				RichEditSpec->SetFocus();
				ShowMessage(msg + " \"" + sf->FieldName + "\".");
				HighLight(sf);
				return 0;
			}
		}
		if (str == "TComboBoxSpec") {
			ComboBoxSpec = (TComboBoxSpec*)Components[i];
			if (!ComboBoxSpec->Modify)
				continue;
			sf = (ISpecField*)ComboBoxSpec;
			if (!SaveSpecComponent(sf))	{
				sf->SetFocusSpec();
				ShowMessage(msg + " \"" + sf->FieldName + "\".");
				HighLight(sf);
				return 0;
			}
		}
		if (str == "TDateTimePickerSpec") {
			DateTimePickerSpec = (TDateTimePickerSpec*)Components[i];
			if (!DateTimePickerSpec->Modify)
				continue;
			sf = (ISpecField*)DateTimePickerSpec;
			if (!SaveSpecComponent(sf))	{
				sf->SetFocusSpec();
				ShowMessage(msg + " \"" + sf->FieldName + "\".");
				HighLight(sf);
				return 0;
			}
		}


		/*if (str == "TComboBoxSpec") {
			((TComboBoxSpec*)Components[i])->Text = "";
			((TComboBoxSpec*)Components[i])->ItemIndex = -1;
		}
		if (str == "TDateTimePickerSpec") {
			((TDateTimePickerSpec*)Components[i])->Format = " ";
		} */
	}
	JournForm->sg->Repaint();
	return 1;
}

int __fastcall TProtocolForm::Save()
{
	int r, i;
	TProtocol *p;
	TBase* Item;
	int OldAppointID = prot->AppointmentID;

	RichEditSpecExit(this);
	if (r = SaveAllSpecComponents())	{
		SetMonitorModify(true);
		SetAllSpecModify(false);
	}

	/*for (i = JournForm->sg->FixedRows; i < JournForm->sg->RowCount; i++) {
		p = (TProtocol*)JournForm->sg->Objects[0][i];
		if (p == NULL)
			continue;
		if (p->IDDoc == prot->IDDoc) {*/
		if ((i = JournForm->RowByIDDoc(prot->IDDoc)) >= 0)	{
			p = (TProtocol*)JournForm->sg->Objects[0][i];
			prot->AppointmentID = p->AppointmentID;
			delete p;
			JournForm->sg->Objects[0][i] = (TObject*)prot;
//			Item = (TBase*)AppointBox->Items->Objects[AppointBox->ItemIndex];
			prot = new TProtocol(prot, OldAppointID);
		}
/*		}
	}*/
//	JournForm->sg->Repaint();

	return r;
}

void __fastcall TProtocolForm::ToolButton1Click(TObject *Sender)
{
	/*if (prot->Closed < 2)	{
		Save();
		return;
	}

	prot->ProtocolOpen();
	if (prot->Closed < 2)
		Save();
	else
		ShowMessage("Протокол используется другим ползователем. Сохранение не возможно");*/
	Save();

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::ComboBoxSpecAfterSetItemID(TObject *Sender)
{
	TComboBoxSpec *sBox = (TComboBoxSpec*)Sender;
	TBase *item;

	sBox->Modify = true;
	
	BoxItemByID(sBox->ItemID, (TComboBox*)sBox);
	if (sBox->ItemIndex == -1) {
		item = (TBase*)OtherObjectList->ItemByID(sBox->ItemID);
		if (item != NULL)
			sBox->Text = item->Descr;
	}
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::ComboBoxSpecSelect(TObject *Sender)
{
	TComboBoxSpec *sBox = (TComboBoxSpec*)Sender;
	TNotifyEvent event;

	event = sBox->OnAfterSetItemID; //чтоб не сработало OnAfterSetItemID
	sBox->OnAfterSetItemID = NULL;

	sBox->ItemID = *((int*)sBox->Items->Objects[sBox->ItemIndex]);

	sBox->OnAfterSetItemID = event;
	ComboBoxModify(Sender);
}
//---------------------------------------------------------------------------

String __fastcall TProtocolForm::GetMonth(int num)
{
	switch (num) {
		case 1: return "Январь";
		case 2: return "Февраль";
		case 3: return "Март";
		case 4: return "Апрель";
		case 5: return "Май";
		case 6: return "Июнь";
		case 7: return "Июль";
		case 8: return "Август";
		case 9: return "Сентябрь";
		case 10: return "Октябрь";
		case 11: return "Ноябрь";
		case 12: return "Декабрь";
	}
	return "";
}

String __fastcall TProtocolForm::FIO_DatPadej(String fio)
{
	String afio[3] = {"", "", ""};
	int i, p;
	String temp = fio;

	p = 0;
	while ((i = temp.Pos(" ")) > 0)
	{
		afio[p] = temp.SubString(1, i - 1);
		p++;
		temp.Delete(1, i);
		temp.TrimLeft();
	}
	afio[p] = temp;


	return "";
}

void __fastcall TProtocolForm::Button1Click(TObject *Sender)
{
	Variant Excel,WorkBooks,Sheet,Cell;
	String FileName = ExtractFilePath(Application->ExeName) + "xlt\\zakl.xlt";
	String str;
	unsigned short int yy, MM, dd;


	try
	{
		Excel = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		Application->MessageBox("Невозможно установить соединение с Microsoft Excel.","Ошибка",MB_OK);
		return;
	}


	WorkBooks = Excel.OlePropertyGet("WorkBooks");
	WorkBooks.OleProcedure("open", FileName.c_str());
	Sheet = Excel.OlePropertyGet("WorkSheets",1);

	str = "Заключение №" + EditSpec1->Text;
	Sheet.OlePropertyGet("Cells", 1, 2).OlePropertySet("Value", str.c_str()); //РегНомер
	Sheet.OlePropertyGet("Cells", 3, 3).OlePropertySet("Value", "Народная, 10");
	Sheet.OlePropertyGet("Cells", 4, 3).OlePropertySet("Value", "276-21-51");
	Sheet.OlePropertyGet("Cells", 5, 3).OlePropertySet("Value", RichEditSpec1->Text.c_str());
	str = DateTimePickerSpec2->TextData;
	Sheet.OlePropertyGet("Cells", 6, 3).OlePropertySet("Value", str.c_str());
	if (DateTimePickerSpec1->Format == "") {
		DecodeDate(DateTimePickerSpec1->Date, yy, MM, dd);
		str = "Числа " + IntToStr(dd) + " месяца " + GetMonth(MM) + " " + IntToStr(yy) + " г.";
		Sheet.OlePropertyGet("Cells", 8, 2).OlePropertySet("Value", str.c_str());
	}
	Sheet.OlePropertyGet("Cells", 13, 2).OlePropertySet("Value", RichEditSpec98->Text.c_str());
	Sheet.OlePropertyGet("Cells", 15, 2).OlePropertySet("Value", RichEditSpec110->Text.c_str());
//--------------
	str = "Заключение №" + EditSpec1->Text;
	Sheet.OlePropertyGet("Cells", 26, 2).OlePropertySet("Value", str.c_str()); //РегНомер
	Sheet.OlePropertyGet("Cells", 28, 3).OlePropertySet("Value", RichEditSpec1->Text.c_str());
	Sheet.OlePropertyGet("Cells", 31, 2).OlePropertySet("Value", RichEditSpec102->Text.c_str());
	Sheet.OlePropertyGet("Cells", 34, 2).OlePropertySet("Value", RichEditSpec111->Text.c_str());


	Excel.OlePropertySet("Visible", true);


	//WorkBooks = Excel.OlePropertyGet("WorkBooks",1);
	//WorkBooks.OleProcedure("SaveAs",FileName.c_str());
	//WorkBooks.OleProcedure("Close");

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton58Click(TObject *Sender)
{
	LangForm->SetRichEdit = RichEditSpec44;
	LangForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton59Click(TObject *Sender)
{
	OrganizationsForm->SetRichEdit = RichEditSpec47;
	OrganizationsForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton60Click(TObject *Sender)
{
	SchoolTypeForm->SetRichEdit = RichEditSpec104;
	SchoolTypeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton61Click(TObject *Sender)
{
	GroupTypeForm->SetRichEdit = RichEditSpec108;
	GroupTypeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton62Click(TObject *Sender)
{
	KGartenForm->SetRichEdit = RichEditSpec109;
	KGartenForm->Show();
}
//---------------------------------------------------------------------------

int TProtocolForm::ShowDlg(String MsgCaption, String MsgText)
{
	if (Application->MessageBox(MsgText.c_str(), MsgCaption.c_str(), MB_YESNO) == 6)
		return 1;
	return 0;
}

void __fastcall TProtocolForm::SpeedButton55Click(TObject *Sender)
{
	String text = "Коллегиальное заключение будет удалено, а вместо него \nбудут добавлены\
 диагнозы всех специалистов. \nПродолжить?";
	String caption = "Вставка диагнозов";

	if (!ShowDlg(caption, text))
		return;

	RichEditSpec102->Text =
		RichEditSpec62->Text + "; " +
		RichEditSpec70->Text + "; " +
		RichEditSpec75->Text + "; " +
		RichEditSpec85->Text;
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton56Click(TObject *Sender)
{
	String text = "Рекомендации педагогам будут удалены, а вместо них \nбудут добавлены\
 рекомендации всех специалистов. \nПродолжить?";
	String caption = "Вставка рекомендацй";

	if (!ShowDlg(caption, text))
		return;

	RichEditSpec110->Text =
		RichEditSpec61->Text + "; " +
		RichEditSpec69->Text + "; " +
		RichEditSpec74->Text + "; " +
		RichEditSpec86->Text + "; " +
		RichEditSpec99->Text;
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::SpeedButton57Click(TObject *Sender)
{
	String text = "Рекомендации педагогам будут удалены, а вместо них \nбудут добавлены\
 рекомендации всех специалистов. \nПродолжить?";
	String caption = "Вставка рекомендацй";

	if (!ShowDlg(caption, text))
		return;

	RichEditSpec111->Text =
		RichEditSpec60->Text + "; " +
		RichEditSpec68->Text + "; " +
		RichEditSpec72->Text + "; " +
		RichEditSpec87->Text + "; " +
		RichEditSpec100->Text;
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::Button2Click(TObject *Sender)
{
	Variant Excel,WorkBooks,Sheet,Cell;
	String FileName = ExtractFilePath(Application->ExeName) + "xlt\\protocol.xlt";
	String str;
	unsigned short int yy, MM, dd;


	try
	{
		Excel = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		Application->MessageBox("Невозможно установить соединение с Microsoft Excel.","Ошибка",MB_OK);
		return;
	}


	WorkBooks = Excel.OlePropertyGet("WorkBooks");
	WorkBooks.OleProcedure("open", FileName.c_str());
	Sheet = Excel.OlePropertyGet("WorkSheets",1);

	str = "Дата обследования " + DateTimePickerSpec1->TextData + "          Регистрационный номер " +
			EditSpec1->Text;
	Sheet.OlePropertyGet("Cells", 5, 2).OlePropertySet("Value", str.c_str());
	Sheet.OlePropertyGet("Cells", 8, 3).OlePropertySet("Value", RichEditSpec1->Text.c_str());
	Sheet.OlePropertyGet("Cells", 9, 3).OlePropertySet("Value", DateTimePickerSpec2->TextData.c_str());
	Sheet.OlePropertyGet("Cells", 10, 3).OlePropertySet("Value", RichEditSpec7->Text.c_str());
	str = ComboBoxSpec2->Text;
	if (EditSpec6->Text != "")
		str += " (" + EditSpec6->Text + ")";
	str += " " + DateTimePickerSpec3->TextData + " " + RichEditSpec3->Text;
	Sheet.OlePropertyGet("Cells", 11, 3).OlePropertySet("Value", str.c_str());
	Sheet.OlePropertyGet("Cells", 14, 2).OlePropertySet("Value", RichEditSpec102->Text.c_str());
	Sheet.OlePropertyGet("Cells", 15, 3).OlePropertySet("Value", RichEditSpec98->Text.c_str());
	Sheet.OlePropertyGet("Cells", 19, 2).OlePropertySet("Value", RichEditSpec110->Text.c_str());
	Sheet.OlePropertyGet("Cells", 22, 2).OlePropertySet("Value", RichEditSpec111->Text.c_str());

	Excel.OlePropertySet("Visible", true);


	//WorkBooks = Excel.OlePropertyGet("WorkBooks",1);
	//WorkBooks.OleProcedure("SaveAs",FileName.c_str());
	//WorkBooks.OleProcedure("Close");
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::ComboBoxSpecMouseWheelUp(TObject *Sender,
	  TShiftState Shift, const TPoint &MousePos, bool &Handled)
{
	FormMouseWheelUp(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::ComboBoxSpecMouseWheelDown(TObject *Sender,
	  TShiftState Shift, const TPoint &MousePos, bool &Handled)
{
	FormMouseWheelDown(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------



void __fastcall TProtocolForm::EditSpec1Change(TObject *Sender)
{
//	TEditSpec* ed = (TEditSpec*)Sender;

	if (prot != NULL)
		prot->DocNo = StrToIntDef(EditSpec1->Text.Trim(), 0);

	EditChanged(Sender);
}
//---------------------------------------------------------------------------




void __fastcall TProtocolForm::RichEditSpecExit(TObject *Sender)
{
	TRichEditSpec* re = (TRichEditSpec*)Sender;

   /*	TChildren *NewChild;

	NewChild = Childrens->ChildrenByFIO(RichEditSpec1->Text);
	if (NewChild == child) {
		prot->chi
	}
	if (child != NULL)
		RichEditSpec1->ItemID = child->ID;
	else	{
		if (RichEditSpec1->Text != "") {
			child = new TChildren(2, 0, 0);
		}

		RichEditSpec1->ItemID = 0;
	}*/

	if (!MouseOver_lb)
		lb->Visible = false;

//	ShowMessage("Exit");
}
//---------------------------------------------------------------------------
int __fastcall TProtocolForm::CheckModifyWithDialog(String text, String caption)
{
//	String text = "Сохранить изменения?";
//	String caption = "Закрытие протокола.";


	if (CheckModify() != "")
		return Application->MessageBox(text.c_str(), caption.c_str(), MB_YESNOCANCEL);
	else
		return IDNO;
}

TCloseAction __fastcall TProtocolForm::OnFormClose()
{
	int i = 0;

	i = CheckModifyWithDialog("Сохранить изменения?", "Закрытие протокола.");
	switch (i) {
		case IDYES:
			if (!Save())
				return caNone;
			prot->ProtocolClose();
			JournForm->FillGrid();
			return caHide;
		case IDCANCEL:
			return caNone;
		case IDNO:
			prot->ProtocolClose();
			JournForm->FillGrid();
			return caHide;
	}
    return caHide;
//	prot->ProtocolClose();
//	JournForm->FillGrid();
}

void __fastcall TProtocolForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = OnFormClose();
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::RichEditSpec7KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	TRichEditSpec *r = (TRichEditSpec*)Sender;

	/*if (Key == 46) {
    	r->ItemID = 0;
	}*/	
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::lbClick(TObject *Sender)
{	
	TRichEditSpec *re;
	TBase *Item;

	if (!lb->JoinSpec)
		return;

	re = (TRichEditSpec*)lb->JoinSpec;
	Item = (TBase*)lb->Items->Objects[lb->ItemIndex];
	switch (re->FieldType) {
		case 4:
			if (re->Name == "RichEditSpec1")	{
				FillChild((TChildren*)Item);
				break;
			}
			re->ItemID = Item->ID;
			break;
		case 1:
//			re->InsertInCaret(Item->Descr);
			re->ReplaseActivePhrase(Item->Descr);
//			re->Text = Item->Descr;
			break;
	}
	lb->Close();
}

/*void TProtocolForm::FillSpecOnFontChange()
{
	int i;
	String str, s;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	TRichEditSpec *re;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;

		try {

			if (str == "TEditSpec") {
//					((TEditSpec*)Components[i])->
				}
			if (str == "TRichEditSpec") {
				((TRichEditSpec*)Components[i])->OnFontChange = RichEditSpecFontChange;
			}
			if (str == "TComboBoxSpec") {
//				((TComboBoxSpec*)Components[i])->OnContextPopup = PopupEvent;
			}
			if (str == "TDateTimePickerSpec") {
//				((TDateTimePickerSpec*)Components[i])->OnContextPopup = PopupEvent;
			}
		} catch (...) {
			ShowMessage("Error on SetFontChange! " + s);
		}
	}
} */

void __fastcall TProtocolForm::FormCreate(TObject *Sender)
{
	lbList = new TBaseEmptyList();

	prot = NULL;
	MouseOver_lb = 0;
	//FillSpecOnFontChange();
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::FormDestroy(TObject *Sender)
{
	lbList->Clear();
	if (prot!= NULL)
		prot->ProtocolClose();
	delete lbList;
}
//---------------------------------------------------------------------------



void __fastcall TProtocolForm::RichEditSpecKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	TNotifyEvent click = lb->OnClick;
	TRichEditSpec* m = (TRichEditSpec*)Sender;
	String ss;

	if (Shift.Contains(ssCtrl) && Key == 32 && ComboBox1->ItemIndex != 0) {
		if (m->Focused())	{
			CrtlPress = 1;
//			ss = GetLastWord(m->Text.SubString(1, m->SelStart));
        	ss = m->GetActivePhrase().Text;
			lbChange(m, ss, m->ListID);
//			RichEditChanged(Sender);
			lb->JoinSpec = m;
			Key = 0;
			return;
		}
	}

	if (lb->Visible == true) {
		switch (Key) {
			case 38:
				lb->OnClick = NULL;
				lb->Perform(WM_KEYDOWN, 38, 0);
				Key = 0;
				lb->OnClick = click;
				lb->Repaint();
				break;
			case 40:
				lb->OnClick = NULL;
				lb->Perform(WM_KEYDOWN, 40, 0);
				Key = 0;
				lb->OnClick = click;
				lb->Repaint();
				break;
			case 13:
				Key = 0;
				break;
		default:
			;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::ComponentMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	lb->Visible = false;		
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TProtocolForm::lbMouseEnter(TObject *Sender)
{
	MouseOver_lb = true;	
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::lbMouseLeave(TObject *Sender)
{
	MouseOver_lb = false;	
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::RichEditSpecKeyPress(TObject *Sender, char &Key)
{
//	if (Key == ' ' && GetKeyState(VK_CONTROL)) {
	if (Key == ' ' && CrtlPress) {
		Key = 0;
		return;
	}
	if (Key == 13 && lb->Visible == true && lb->ItemIndex >= 0) {
		Key = 0;
		lb->OnClick(lb);
	}
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::lbDrawTreeItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State)
{
	String s;
	String ss = lb->SubString.UpperCase();
	TTreeBase *Item;

	int i, to_ss, after_ss, width_ss, width_s;
	TCanvas *c = lb->Canvas;
	TFont *font = new TFont();

	font->Assign(c->Font);

	Item = (TTreeBase*)(lb->Items->Objects[Index]);
	s = Item->Descr.UpperCase();
	i = s.Pos(ss);
	ss = lb->SubString;
//	s = lb->Items->Strings[Index];
	s = Item->Descr;
	c->FillRect(Rect);

	if (i > 0) {
//		c->Brush->Color = clMoneyGreen;
		c->TextOut(Rect.left, Rect.Top, s.SubString(1, i - 1));
		to_ss = c->TextWidth(s.SubString(1, i - 1));
		if (to_ss != 0)
			to_ss++;
//		c->Brush->Color = clInactiveCaption;
		c->Font->Style = c->Font->Style << fsUnderline;
		c->TextOut(Rect.left + to_ss, Rect.Top, s.SubString(i, ss.Length()));
		c->Font->Style = c->Font->Style >> fsUnderline;
		width_ss = c->TextWidth(s.SubString(i, ss.Length()));
		if (width_ss != 0)
			width_ss++;
//		c->Brush->Color = clMoneyGreen;
//		c->Brush->Color = colorB;
		c->TextOut(Rect.left + to_ss + width_ss, Rect.Top, s.SubString(i + ss.Length(), s.Length() - ss.Length() - i + 1));
		width_s = c->TextWidth(s) + 1+ 5;
		if (lb->ItemIndex == Index)
			c->Font->Color = clMoneyGreen;
		else
			c->Font->Color = clTeal;
		c->TextOut(Rect.left + width_s, Rect.Top, lb->Items->Strings[Index]);
	}
	else	{
		c->TextOut(Rect.left, Rect.Top, s);
		
		if (lb->ItemIndex == Index)
			c->Font->Color = clMoneyGreen;
		else
			c->Font->Color = clTeal;

		width_s = c->TextWidth(s) + 5;
		c->TextOut(Rect.left + width_s, Rect.Top, lb->Items->Strings[Index]);
	}

	c->Font->Assign(font);
	delete font;
}

void __fastcall TProtocolForm::lbDrawItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State)
{
	String s;
	String ss = lb->SubString.UpperCase();

	int i, to_ss, after_ss, width_ss;
	TCanvas *c = lb->Canvas;
	TFont *font = new TFont();

	font->Assign(c->Font);

	s = lb->Items->Strings[Index].UpperCase();
	i = s.Pos(ss);
	ss = lb->SubString;
	s = lb->Items->Strings[Index];
	c->FillRect(Rect);

	if (i > 0) {
//		c->Brush->Color = clMoneyGreen;
		c->TextOut(Rect.left, Rect.Top, s.SubString(1, i - 1));
		to_ss = c->TextWidth(s.SubString(1, i - 1));
		if (to_ss != 0)
			to_ss++;
//		c->Brush->Color = clInactiveCaption;
		c->Font->Style = c->Font->Style << fsUnderline;
		c->TextOut(Rect.left + to_ss, Rect.Top, s.SubString(i, ss.Length()));
		c->Font->Style = c->Font->Style >> fsUnderline;
		width_ss = c->TextWidth(s.SubString(i, ss.Length()));
		if (width_ss != 0)
			width_ss++;
//		c->Brush->Color = clMoneyGreen;
//		c->Brush->Color = colorB;
		c->TextOut(Rect.left + to_ss + width_ss, Rect.Top, s.SubString(i + ss.Length(), s.Length() - ss.Length() - i + 1));
	}
	else
		c->TextOut(Rect.left, Rect.Top, s);

	c->Font->Assign(font);
	delete font;
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
		if (Key == 27)	{
			Key = 0;
			lb->Close();
		}
}
//---------------------------------------------------------------------------


void TProtocolForm::SaveINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));

	file->WriteInteger("Protocol", "Insight", ComboBox1->ItemIndex);
	if (AppointBox->ItemIndex >= 0)
		file->WriteInteger("Protocol", "Appointment", ((TBase*)(AppointBox->Items->Objects[AppointBox->ItemIndex]))->ID);

	file->Free();
}

void TProtocolForm::LoadINI()
{
	TIniFile *file = GetFileINI(ExtractFilePath(Application->ExeName));
	TStringList *list = new TStringList;

	file->ReadSectionValues("Protocol", list);
	ComboBox1->ItemIndex = file->ReadInteger("Protocol", "Insight", 2);
	AppointBox->ItemIndex = file->ReadInteger("Protocol", "Appointment", 0);

	delete file, list;
}

void __fastcall TProtocolForm::HighLight(ISpecField *Obj)
{
	hlObj = Obj;
	Tick = 1;
	Timer1->Enabled = true;
}

void __fastcall TProtocolForm::Timer1Timer(TObject *Sender)
{
/*	int i;
	TRichEditSpec* re;
	String CName;

	CName = Sender->ClassName();
	if (CName == "TRichEditSpec")
	   re = (TRichEditSpec*)Sender;
	else	{
		Timer1->Enabled = false;
		return;
	}  */

	if (hlObj == NULL) {
    	Timer1->Enabled = false;
		return;
	}

	if (Tick > 4)	{
		Tick = 1;
		hlObj->ColorSpec = clWindow;
		Timer1->Enabled = false;
		hlObj = NULL;
		return;
	}

	if ((Tick % 2) == 0) {
		hlObj->ColorSpec = clRed;
	}
	else
		hlObj->ColorSpec = clWindow;

	Tick++;
}
//---------------------------------------------------------------------------





void __fastcall TProtocolForm::SpeedButton31Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec76, &(GroupDataForm->AddRichEdit));

	/*GroupDataForm->StartID = 0;
	GroupDataForm->AddRichEdit = RichEditSpec76;
	GroupDataForm->Show(); */
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton30Click(TObject *Sender)
{
    ShowDiagnosisForm(RichEditSpec75, &(DiagnosisForm->AddRichEdit));

	/*DiagnosisForm->StartID = 0;
	DiagnosisForm->AddRichEdit = RichEditSpec75;
	DiagnosisForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton29Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec74, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 0;
	RecommendForm->AddRichEdit = RichEditSpec74;
	RecommendForm->Show();*/
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton21Click(TObject *Sender)
{
	ShowRecommendForm(RichEditSpec72, &(RecommendForm->AddRichEdit));

	/*RecommendForm->StartID = 4;
	RecommendForm->AddRichEdit = RichEditSpec72;
	RecommendForm->Show(); */
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::PageControl1Change(TObject *Sender)
{
	switch (PageControl1->TabIndex) {
		case 0: lb->Parent = ScrollBox1; break;
		case 1: lb->Parent = ScrollBox2; break;
		case 2: lb->Parent = ScrollBox4; break;
		case 3: lb->Parent = TabSheet3; break;
		case 4: lb->Parent = TabSheet4; break;
		case 5: lb->Parent = TabSheet5; break;

	default:
		;
	}

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::FillAnchors()
{
	TRichEditSpec* re;
//    TEditSpec* re;
	int i;
	String str;
	TAttrAppoint* Item;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		if (str == "TRichEditSpec") {
			re = (TRichEditSpec*)Components[i];
			Item = (TAttrAppoint*)AttrAppointList->ItemByDescr(re->FieldName);
			if (Item == NULL)
				continue;
			re->AnchorID = Item->AnchorID;
		}
	}
}
void __fastcall TProtocolForm::RichEditSpecKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
		CrtlPress = 0;
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::Button3Click(TObject *Sender)
{
	CreateReportProtocol();
}
//---------------------------------------------------------------------------



void __fastcall TProtocolForm::OnPopupGetFieldNameClick(TObject *Sender)
{
	TMenuItem* Item;
	TClipboard *buff = Clipboard();
	THandle h;
	ISpecField *sf;
	String s, str;
	int i;

//	str = Sender->ClassName();
	Item = (TMenuItem*)Sender;

	buff->Open();
	buff->AsText = Item->Caption;
	h = buff->GetAsHandle(CF_TEXT);
	SetClipboardData(CF_LOCALE, (void*)h);
	buff->Close();

	Item->OnClick = NULL;
    Item->Caption = "---";
//	i = PopupMenu1->Items->IndexOf(Item);
//	PopupMenu1->Items->Delete(i);
//	delete Item;
}

ISpecField* __fastcall TProtocolForm::GetSpecField(TObject *Sender)
{
	TEditSpec *EditSpec;
	TRichEditSpec *RichEditSpec;
	TComboBoxSpec *ComboBoxSpec;
	TDateTimePickerSpec *DateTimePickerSpec;
	String s, str;

	str = Sender->ClassName();
//	s = Obj->Name;

	if (str == "TEditSpec")
		return (ISpecField*)(TEditSpec*)Sender;
	else if (str == "TRichEditSpec")
		return (ISpecField*)(TRichEditSpec*)Sender;
	else if (str == "TComboBoxSpec")
		return (ISpecField*)(TComboBoxSpec*)Sender;
	else if (str == "TDateTimePickerSpec")
		return (ISpecField*)(TDateTimePickerSpec*)Sender;

	return NULL;
}

void __fastcall TProtocolForm::SpecContextPopup(TObject *Sender,
	  TPoint &MousePos, bool &Handled)
{
	TMenuItem* Item;
	ISpecField *sf;
	String s, str;
	int i;

	sf = GetSpecField(Sender);
//	Item = new TMenuItem(PopupMenu1);
	Item = PopupMenu1->Items->Items[0];
	Item->Caption = START_FIELDCODE + sf->FieldName + END_FIELDCODE;
	Item->OnClick = OnPopupGetFieldNameClick;
	sf->SetFocusSpec();
//	PopupMenu1->Items->Add(Item);
}

void __fastcall TProtocolForm::SetAllSpecContextPopup()
{
	int i;
	String str, s;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;
	TContextPopupEvent PopupEvent = (TContextPopupEvent)&SpecContextPopup;

//	RichEditSpec1->ItemID = 0;

	for (i = 0; i < ComponentCount; i++) {
		str = Components[i]->ClassName();
		s = Components[i]->Name;

		try {

			if (str == "TEditSpec") {
					((TEditSpec*)Components[i])->OnContextPopup = PopupEvent;
					((TEditSpec*)Components[i])->PopupMenu = PopupMenu1;
				}
			if (str == "TRichEditSpec") {
				((TRichEditSpec*)Components[i])->OnContextPopup = PopupEvent;
				((TRichEditSpec*)Components[i])->PopupMenu = PopupMenu1;
			}
			if (str == "TComboBoxSpec") {
				((TComboBoxSpec*)Components[i])->OnContextPopup = PopupEvent;
				((TComboBoxSpec*)Components[i])->PopupMenu = PopupMenu1;
			}
			if (str == "TDateTimePickerSpec") {
				((TDateTimePickerSpec*)Components[i])->OnContextPopup = PopupEvent;
				((TDateTimePickerSpec*)Components[i])->PopupMenu = PopupMenu1;
			}
		} catch (...) {
			ShowMessage("Error on SetPopup! " + s);
		}
	}
}
//---------------------------------------------------------------------------





void __fastcall TProtocolForm::SpeedButton6Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec17, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton64Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec18, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::SpeedButton65Click(TObject *Sender)
{
	ShowGroupDataForm(RichEditSpec25, &(GroupDataForm->AddRichEdit));
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::FillAppointBox()
{
	int i;
	TBase *Item;

	for (i = 0; i < AppointmentList->Count; i++) {
		Item = AppointmentList->Items[i];
		AppointBox->AddItem(Item->Descr, (TObject*)Item);
	}
	BoxItemByTBase((TBase*)AppointmentList->ItemByID(DEF_APPOINT), AppointBox);
}



void __fastcall TProtocolForm::AppointBoxSelect(TObject *Sender)
{
	int i;

	i = CheckModifyWithDialog("Сохранить изменения?", "Смена должности.");
	switch (i) {
		case IDYES:
			if (!Save())
				return;
			break;
		case IDCANCEL:
			return;
	}
	GetProtocol(prot);
}
//---------------------------------------------------------------------------


void __fastcall TProtocolForm::SetEnableControl(TControl* VControl)
{
/*	int i;
	String str, s;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;
	TComponent* control;

	for (i = 0; i < VControl->ControlCount; i++) {
		str = VControl[i]->ClassName();
		s = VControl[i]->Name;
		SetEnableControl(VControl, VClassName)
		if (str == VClassName) {
			((TEditSpec*)VControl[i])->Enabled = true;
		}
	} */ 
}

void __fastcall TProtocolForm::SetEnableSpec(int AppointID)
{
	int i;
	String str, s;
	TNotifyEvent event;
	TEditSpec *es;
	TDateTimePickerSpec *dt;
	ISpecField *sf;
	TComponent* control;
//	RichEditSpec1->ItemID = 0;

	ScrollBox2->Enabled = false;
	ScrollBox4->Enabled = false;
	TabSheet5->Enabled = false;
	CommonTab->Enabled = false;
//	ScrollBox1->Enabled = false;
	TabSheet3->Enabled = false;
	TabSheet4->Enabled = false;
	TabSheet6->Enabled = false;

	switch (AppointID) {
		case 1:
			ScrollBox2->Enabled = true;
			PageControl1->TabIndex = 1;
			break;
		case 2:
			ScrollBox4->Enabled = true;
			PageControl1->TabIndex = 2;
			break;
		case 3:
			TabSheet5->Enabled = true;
			PageControl1->TabIndex = 5;
			break;
		case 4:
//			ScrollBox1->Enabled = true;
            CommonTab->Enabled = true;
			PageControl1->TabIndex = 0;
			break;
		case 5:
			TabSheet3->Enabled = true;
			PageControl1->TabIndex = 3;
			break;
		case 6:
			TabSheet4->Enabled = true;
			PageControl1->TabIndex = 4;
			break;
		case 7:
			TabSheet6->Enabled = true;
			PageControl1->TabIndex = 6;
			break;
	default:
		return;
	}

	if (ProtocolForm->Visible == true)
		PageControl1->SetFocus();
}




void __fastcall TProtocolForm::RichEditSpecFontChange(TObject *Sender)
{
	/*TRichEditSpec *r = (TRichEditSpec*)Sender;
	r->Text = "1";*/
	RichEditAutoHeight(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::lbFontChange(TObject *Sender)
{
	THelpListBox *l = (THelpListBox*)Sender;
	l->ItemHeight = l->Font->Height*-1 + 4;
	l->Height = l->ItemHeight * 5;

}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::ScrollBoxMouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
	lb->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TProtocolForm::ChangeFont(TFont *f)
{
	int i, j;
	TGroupBox *g;
	vector<TRichEditSpec*> rEdit;
	vector<TNotifyEvent> event;
	String cName;
	TScrollBox *sb;
	TGroupBox *gb;
	TControl *c;
	TToolBar *tb;
	int test;


//	if (!FontDialog1->Execute()) {
//		return;
//	}

	//Отключаем OnChange у TRichEditSpec
	for (i = 0; i < ComponentCount; i++) {
		cName = Components[i]->ClassName();
		if (cName == "TRichEditSpec") {
			rEdit.push_back(((TRichEditSpec*)Components[i]));
			event.push_back(rEdit.back()->OnChange);
			rEdit.back()->OnChange = NULL;
		}

	}

	//Включаем ParentFont = true у TPanel
	for (i = 0; i < ComponentCount; i++)	{
		cName = Components[i]->ClassName();
		if (cName == "TGroupBox")	{
			gb = (TGroupBox*)Components[i];
			gb->ParentFont = true;
			for (j = 0; j < gb->ControlCount; j++)
				 ((TPanel*)gb->Controls[j])->ParentFont = true;
		}
	}

//	ProtocolForm->Font->Assign(FontDialog1->Font);
	ProtocolForm->Font->Assign(f);

	//Делаем авторазмер
	for (i = 0; i < ComponentCount; i++)	{
		cName = Components[i]->ClassName();
		if (cName == "TScrollBox")	{
			sb = (TScrollBox*)Components[i];
			for (j = 0; j < sb->ControlCount; j++)
				 ControlAutoSizeLevelDown(sb->Controls[j]);
		}
	}

	//Отключаем ParentFont = false у TPanel
	for (i = 0; i < ComponentCount; i++)	{
		cName = Components[i]->ClassName();
		if (cName == "TGroupBox")	{
			gb = (TGroupBox*)Components[i];
			for (j = 0; j < gb->ControlCount; j++)
				 ((TPanel*)gb->Controls[j])->ParentFont = false;
		}
	}

	for (i = 0; i < ComponentCount; i++) {
		cName = Components[i]->ClassName();
		if (cName == "TGroupBox") {
			((TGroupBox*)Components[i])->Font->Color = clNavy;
		}
	}

    //Включаем OnChange у TRichEditSpec
	while (rEdit.size())	{
		rEdit.back()->OnChange = event.back();
		rEdit.pop_back();
		event.pop_back();
	}

    //Подгоняем Toolbar
//	tb = ToolBar1;
//	for (j = 0; j < tb->ControlCount; j++) {
//		ControlAutoSizeLevelDown(tb->Controls[j]);
//	}
//	tb->Height = ComboBox1->Height;
//	tb->ButtonHeight = ComboBox1->Height;
	ToolBarAutoSizeLevelDown(ToolBar2);
	ToolBar2->Height += 6;
	ToolBarAutoSizeLevelDown(ToolBar3);
	ToolBar3->Height += 6;
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);

	

}



