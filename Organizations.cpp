//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "DMUnit.h"
#include "DigitConvertion.h"
#include "TTreeBaseEmptyList.h"
#include "ExtFunctions.h"
#include "Organizations.h"
#include "MouseWheelUnit.h"
#include "TAutoSize.h"
#include "ImagesDM.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"

TOrganizationsForm *OrganizationsForm;
extern TOrganizationList* Organizations;
extern TTreeBaseEmptyList *OtherObjectList;

//---------------------------------------------------------------------------
__fastcall TOrganizationsForm::TOrganizationsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TOrganizationsForm::FillTree(TTreeNode *ParentNode, int ParentID)
{
	int i;
	TTreeNode *node;
	String str;

	for (i = 0; i < Organizations->Count; i++) {
		str = Organizations->Organization[i]->ParentID;
		if (Organizations->Organization[i]->ParentID == ParentID) {
			if (Organizations->Organization[i]->IsFolder == 1) {
				node = tv->Items->AddChild(ParentNode, Organizations->Organization[i]->Descr);
				node->Data = Organizations->Organization[i];
				node->StateIndex = FOLDER_IMG;
				FillTree(node, Organizations->Organization[i]->ID);
			}
		}
	}
}



int __fastcall TOrganizationsForm::ItemSelected(int Row)
{
	if (ItemDraw != NULL)
		if (Row >= START_ROW && Row < ItemDraw->Count + START_ROW)	{
			return 1;
		}
	return 0;
}

void __fastcall TOrganizationsForm::dgDrawCell(TObject *Sender, int ACol,
	  int ARow, TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;
	TOrganization* Item;
	TImageList *Imgs;
	int cnt, Img = 1;

	Imgs = (TImageList*)tv->Images;

	if (ItemSelected(ARow))	{
		Item = ItemDraw->Organization[ARow - START_ROW];
		if (ACol == 0) {
			if (Organizations->AnchorID == Item->ID)
				Img = ANCHOR_IMG;
			else if (Item->IsFolder == 1)
				Img = FOLDER_IMG;
			else
				Img = STRING_IMG;

			Imgs->Draw(c, Rect.left + 2, Rect.top + 2, Img , true);
			c->TextOutA(Rect.left + Imgs->Width + 4, Rect.top + 2, Item->Descr);
		}
		if (ACol == 1) {
			c->TextOutA(Rect.left + 2, Rect.top + 2, Item->OrgType);
		}
	}
	else if (ARow == 1)	{
		if (ACol == 0)
			if (ItemDraw->Root->ID == 0)
				Imgs->Draw(c, Rect.left + 2, Rect.top + 2, ARROWUP_IMG, true);
			else
				Imgs->Draw(c, Rect.left + 2, Rect.top + 2, ARROWUP_IMG, true);
	}
}
//---------------------------------------------------------------------------


void __fastcall TOrganizationsForm::tvCompare(TObject *Sender, TTreeNode *Node1,
	  TTreeNode *Node2, int Data, int &Compare)
{
	TOrganization *Item1 = (TOrganization*)Node1->Data;
	TOrganization *Item2 = (TOrganization*)Node2->Data;

	if (Item1->IsFolder != Item2->IsFolder)
		if (Item1->IsFolder < Item2->IsFolder)
			Compare = 0;
		else
			Compare = 1;
	else
		Compare = CompareStr(Item1->Descr.TrimRight(), Item2->Descr.TrimRight());
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::dgGetEditText(TObject *Sender, int ACol,
	  int ARow, AnsiString &Value)
{
	if (SelItem == NULL)
		return;

	Value = SelItem->Descr;
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::lbExit(TObject *Sender)
{
	lb->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::lbClick(TObject *Sender)
{
	int OrgTypeID;



	OrgTypeID = *(int*)(lb->Items->Objects[lb->ItemIndex]);
	SelItem->OrgTypeID = OrgTypeID;
	SelItem->UpdateDB(DM->OrgUpdateQuery);

	lb->Visible = false;
	dg->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TOrganizationsForm::dgDblClick(TObject *Sender)
{
	TTreeNode *SelNode = tv->Selected;
	TTreeNode *node;
	TOrganization *Item;
	int index;

	TRect rect;

	if (dg->EditorMode == true)
		return;

	if (SelNode == NULL)	{
		//ModalResult = mrOk;
		return;
	}

	if (ItemSelected(dg->Row))	{
		Item = SelItem;
		if (Item->IsFolder == 2) {
			if (dg->Col == 1 && Item->IsFolder == 2) {
				rect = dg->CellRect(dg->Col, dg->Row);
				lb->Left = rect.left + dg->Left + 2;
				lb->Top = rect.top + (rect.Height() + 3) * 2;
				lb->Width = rect.Width();
				lb->Visible = true;
				lb->SetFocus();
				SelItem = Item;
				return;
			}

			if (SetRichEdit != NULL)	{
				SetRichEdit->ItemID = Item->ID;
				Close();
			}

			if (SetEdit != NULL) {
				SetEdit->ItemID = Item->ID;
				Close();
			}
		}
		if (Item->IsFolder == 1) {
			node = GetNodeByID(Item->ID);
			if (node != NULL) {
				tv->Select(node, KeyDataToShiftState(0));
			}
		}
	}
	else if (dg->Row == 1 && dg->Col == 0)	{
		Item = ItemDraw->Root;
		if (Item == NULL)
			return;
		node = GetNodeByID(Item->ParentID);
		if (node != NULL) {
			tv->Select(node, KeyDataToShiftState(0));
			index = ItemDraw->IndexByID(Item->ID);
			if (index != -1)
				dg->Row = index + START_ROW;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::dgExitEdit(TObject *Sender)
{
	TTreeNode *SelNode = tv->Selected;

	if (SelItem == NULL) {
        return;
	}
	SelItem->UpdateDB(DM->OrgUpdateQuery);
	dg->Options = dg->Options >> goEditing;
//	dg->Options = dg->Options << goRowSelect;
//	Organizations->SortByDescrAndIsFolder();
	tvChange(Sender, SelNode);
}


void __fastcall TOrganizationsForm::FormShow(TObject *Sender)
{
	TTreeNode *node;
	TOrganization *Item = new TOrganization(1, 0, 0);

	TADOQuery *q;

	q = DM->OrgSelectQuery;
	Organizations->RemoveItems();
	q->Open();
	Organizations->FillFromDB(q);
	q->Close();
	Organizations->SortByDescrAndIsFolder();


	if (AddRichEdit == NULL && SetRichEdit == NULL && SetEdit == NULL && SelItem == NULL)
		AnchorButton->Visible = false;
	else
    	AnchorButton->Visible = true;

	Item->Descr = "Организации";

	tv->Items->Clear();

	node = tv->Items->AddChild(NULL, Item->Descr);
	node->Data = Item;

	FillTree(node, 0);
	tv->Select(tv->Items->GetFirstNode(), KeyDataToShiftState(0));
	if (tv->Items->Count > 0)
		tvChange(Sender, tv->Items->Item[0]);
}


TTreeNode *TOrganizationsForm::GetNodeByID(int ItemID)
{
	TOrganization *Item;
	int i;

	for (i = 0; i < tv->Items->Count; i++) {
		Item = (TOrganization*)tv->Items->Item[i]->Data;
		if (Item->ID == ItemID) {
			return tv->Items->Item[i];
		}
	}
	return NULL;
}


//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::dgSetEditText(TObject *Sender, int ACol,
	  int ARow, const AnsiString Value)
{
	TTreeNode *node;

	if (SelItem == NULL) {
        return;
	}
	SelItem->Descr = Value;
	node = GetNodeByID(SelItem->ID);
	if (node != NULL)
		node->Text = Value;
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::AddItem(int IsFolder)
{

}

void __fastcall TOrganizationsForm::AddFolderButtonClick(TObject *Sender)
{
	int MaxID;
	TOrganization* ParentItem;
	TOrganization *NewItem;
	TTreeNode *node;
	int mID;

	if (tv->Selected == NULL)
		return;

	tv->Selected->Expanded = true;
	ParentItem = (TOrganization*)tv->Selected->Data;
	MaxID = Organizations->GetMaxID(DM->OrgGetMaxQuery);
	MaxID++;
	NewItem = new TOrganization(1, ParentItem->ID, MaxID);
	NewItem->InsertDB(DM->OrgInsertQuery);
	Organizations->Add(NewItem);
	ItemDraw->Add(NewItem);
	node = tv->Items->AddChild(tv->Selected, NewItem->Descr);
	node->Data = NewItem;
	node->StateIndex = FOLDER_IMG;

	if (tv->Focused()) {
		tv->Select(node, KeyDataToShiftState(0));
		tv->Selected->EditText();
	}
	if (dg->Focused()) {
		tvChange(Sender, tv->Selected);
		dg->Row = ItemDraw->IndexByID(MaxID) + START_ROW;
		dg->Col = 0;
        EditButtonClick(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::AddTextButtonClick(TObject *Sender)
{
	int MaxID;
	TOrganization* ParentItem;
	TOrganization *NewItem;
	int mID, i;

	if (tv->Selected == NULL)
		return;

	tv->Selected->Expanded = true;
	ParentItem = ItemDraw->Root;
	MaxID = Organizations->GetMaxID(DM->OrgGetMaxQuery);
	MaxID++;
	NewItem = new TOrganization(2, ParentItem->ID, MaxID);
	NewItem->InsertDB(DM->OrgInsertQuery);
	Organizations->Add(NewItem);
	ItemDraw->Add(NewItem);
	tvChange(Sender, tv->Selected);
	dg->Row = ItemDraw->IndexByID(MaxID) + START_ROW;
	dg->Col = 0;
	dg->EditorMode = true;
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::DeleteButtonClick(TObject *Sender)
{
	TOrganization *Item;
	TTreeNode *node;
	int DelRec;
	bool b;

	if (tv->Focused())	{
		Item = (TOrganization*)tv->Selected->Data;
		if (Item->GetChildCountFromDB(DM->OrgChildCountQuery) != 0) {
			ShowMessage("Перед удалением папка больжна быть пустой.");
			return;
		}
		if ((DelRec = Organizations->DeleteFromDB(Item, DM->OrgDeleteQuery)) == 1)	{
			tv->Items->Delete(tv->Selected);
		}
		else	{
			ShowMessage("Удаление завершено с ошибкой. Удалено " +
				IntToStr(DelRec) + " записей.");
		}
	}

	if (dg->Focused()) {
		if (SelItem == NULL)
			return;
		Item = SelItem;
		if (Item->GetChildCountFromDB(DM->OrgChildCountQuery) != 0) {
			ShowMessage("Перед удалением папка больжна быть пустой.");
			return;
		}
		if ((DelRec = Organizations->DeleteFromDB(Item, DM->OrgDeleteQuery)) == 1)	{
			ItemDraw->DeleteOrg(Item);
			node = GetNodeByID(Item->ID);
			if (node != NULL)
				tv->Items->Delete(node);
			tvChange(Sender, tv->Selected);
		}
		else	{
			ShowMessage("Удаление завершено с ошибкой. Удалено " +
				IntToStr(DelRec) + " записей.");
		}
		dgSelectCell(Sender, dg->Col, dg->Row, b);
	}
}
//---------------------------------------------------------------------------
void __fastcall TOrganizationsForm::FillOrgDraw(TOrganization* ParentOrg)
{
	int i;
	TOrganization* org;

	delete ItemDraw;
	ItemDraw = new TOrganizationList();


	for (i = 0; i < Organizations->Count; i++) {
		org = Organizations->Organization[i];
		if (org->ParentID == ParentOrg->ID)
			ItemDraw->Add(org);
	}

	ItemDraw->Root = ParentOrg;
	ItemDraw->SortByDescrAndIsFolder();
}


void __fastcall TOrganizationsForm::tvChange(TObject *Sender, TTreeNode *Node)
{
	TOrganization *ParentItem;

	if (Node != NULL)	{
		ParentItem = (TOrganization*)Node->Data;

		if (ParentItem->ID == 0)
			START_ROW = dg->FixedRows;
		else
			START_ROW = dg->FixedRows + 1;

		FillOrgDraw(ParentItem);

		dg->RowCount = ItemDraw->Count + START_ROW;
	}
	else
		dg->RowCount = 2;

	dg->Repaint();

	DeleteButton->Enabled = true;
	EditButton->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	AddRichEdit = NULL;
	SetRichEdit = NULL;
	SetEdit = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
   /*	int h;
	TStringGrid* g = ((TStringGrid*)(Sender));
	h = (g->RowCount - g->Height/g->DefaultRowHeight) - g->FixedRows;
	Handled = false;
	if (g->TopRow <= h) {
	g->TopRow = g->TopRow + 5;
	}
	Handled = true; */
	sgMouseWheelDownA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	/*TStringGrid* g = ((TStringGrid*)(Sender));
	Handled = false;
	if (g->TopRow > 5 + g->FixedRows)
		g->TopRow = g->TopRow - 5;
	else
		g->TopRow = 1;
	Handled = true;*/
	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::FormResize(TObject *Sender)
{
	dg->ColWidths[1] = dg->Width - dg->ColWidths[0] - GetSystemMetrics(SM_CXVSCROLL) * 2;
}
//---------------------------------------------------------------------------


void __fastcall TOrganizationsForm::EditButtonClick(TObject *Sender)
{
//	TTreeNode *SelNode = tv->Selected;
//	TTreeNode *node;
//	TOrganization *org, *ParentOrg;
//	int cnt;

//	dg->Options = dg->Options >> goRowSelect;
	if (dg->Focused()) {
		dg->Options = dg->Options << goEditing;
		dg->EditorMode = true;
	}
	if (tv->Focused()) {
        tv->Selected->EditText();
	}

}
//---------------------------------------------------------------------------


void __fastcall TOrganizationsForm::dgSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
	SelRow = ARow;
	if (ItemSelected(ARow))	{
		DeleteButton->Enabled = true;
		EditButton->Enabled = true;
		SelItem = ItemDraw->Organization[ARow - START_ROW];
    }
	else	{
		DeleteButton->Enabled = false;
		EditButton->Enabled = false;
		SelItem = NULL;
	}
//	dg->Repaint();
}
//---------------------------------------------------------------------------



void __fastcall TOrganizationsForm::dgMouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int row, col;
	TRect rect;

	if (SelItem == NULL) {
		return;
	}

	dg->MouseToCell(X, Y, col, row);
	rect = dg->CellRect(col, row);

	if (col != 0 && row < START_ROW)
		return;

	if (rect.left + 2 <= X &&  rect.left + 18 >= X && rect.top <= Y && rect.bottom >= Y)
		IconClickDown = true;
	else	{
		IconClickDown = false;
		if (SelItem->IsFolder == 2)
			dg->BeginDrag(false, 10);
	}
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::EditIconClick(TObject *Sender)
{
	EditButtonClick(Sender);
}


void __fastcall TOrganizationsForm::dgMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int row, col;
	TRect rect;
	
	if (SelItem == NULL) {
        return;
	}
	dg->MouseToCell(X, Y, col, row);
	rect = dg->CellRect(col, row);

	if (col != 0 && row < START_ROW)
		return;

	if (rect.left + 2 <= X &&  rect.left + 18 >= X && rect.top <= Y && rect.bottom >= Y)
	if (IconClickDown == true)	{
		IconClickDown = false;
		EditIconClick(Sender);

	}
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::dgEnter(TObject *Sender)
{
	bool b;
	dgSelectCell(Sender, dg->Col, dg->Row, b);
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::tvEnter(TObject *Sender)
{
	tvChange(Sender, tv->Selected);
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::tvEdited(TObject *Sender, TTreeNode *Node,
	  AnsiString &S)
{
	TOrganization *Item = (TOrganization*)(Node->Data);

	Item->Descr = S;
	Item->UpdateDB(DM->OrgUpdateQuery);
}
//---------------------------------------------------------------------------



void __fastcall TOrganizationsForm::tvDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
	if (Source == dg) {
		Accept = true;
	}

	
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::tvDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
	TOrganization* Item;
	TTreeNode *DropNode, *NewNode;
	int Img;

	if (tv->DropTarget == NULL)
		return;
	Item = (TOrganization*)tv->DropTarget->Data;
	if (Item == NULL || SelItem == NULL || Item == SelItem)
		return;

	if (Source == dg)	{
		ItemDraw->Remove(SelItem);
		if (SelItem->IsFolder == 1) {
			/*if (Organizations->ExistParent() ) {
                
			}
			DropNode = GetNodeByID(SelItem->ID);
			if (DropNode == NULL)
				throw "Error tvDragDrop!";
			Img = DropNode->StateIndex;
			if (SelItem == Organizations->Anchor)
				Img = 6;
			DropNode->MoveTo(tv->DropTarget, naAddChild);
			DropNode = GetNodeByID(SelItem->ID);
			DropNode->StateIndex = 0;
			DropNode->StateIndex = Img;
			SelItem->ParentID = Item->ID;
			tv->EndDrag(true); */
			tv->EndDrag(true);
		}
		else	{
			SelItem->ParentID = Item->ID;
			SelItem->Save(NULL, NULL, DM->OrgUpdateQuery, NULL);
			tvChange(Sender, tv->Selected);
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TOrganizationsForm::ChangeFont(TFont *f)
{
	int h, w;
	TImageList *iList;

	Font->Assign(f);
	ToolBarAutoSizeLevelDown(ToolBar1);
//	w = Canvas->TextWidth(IntToStr(Organizations->Count) + "T");

	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	TreeViewAutoIcon(tv, Images->ImageList1, Images->ImageList2, Images->ImageList3);
	DrawGridRowsAutoHeigth(dg, (TImageList*)tv->Images);

}








