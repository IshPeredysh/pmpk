//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recommend.h"
#include "DMUnit.h"
#include "DigitConvertion.h"
#include "MouseWheelUnit.h"
#include "TAttrAppointList.h"
#include "ImagesDM.h"
#include "TAutoSize.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDrawGridSpec"
#pragma resource "*.dfm"
TRecommendForm *RecommendForm;
extern TTreeBaseEmptyList *RecommendList;
extern TAttrAppointList *AttrAppointList;
//---------------------------------------------------------------------------
__fastcall TRecommendForm::TRecommendForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TRecommendForm::FillTree(TTreeNode *ParentNode, int ParentID)
{
	int i;
	TTreeNode *node;
	String str;

	for (i = 0; i < RecommendList->Count; i++) {
		str = RecommendList->Items[i]->ParentID;
		if (RecommendList->Items[i]->ParentID == ParentID) {
			if (RecommendList->Items[i]->IsFolder == 1) {
				node = tv->Items->AddChild(ParentNode, RecommendList->Items[i]->Descr);
				node->Data = RecommendList->Items[i];
				node->StateIndex = FOLDER_IMG;
				FillTree(node, RecommendList->Items[i]->ID);
			}
		}
	}
}



int __fastcall TRecommendForm::ItemSelected(int Row)
{
	if (ItemDraw != NULL)
		if (Row >= START_ROW && Row < ItemDraw->Count + START_ROW)	{
			return 1;
		}
	return 0;
}

void __fastcall TRecommendForm::dgDrawCell(TObject *Sender, int ACol,
	  int ARow, TRect &Rect, TGridDrawState State)
{
	TCanvas *c = dg->Canvas;
	TTreeBaseEmpty* Item;
	TImageList *Imgs;

	int cnt, Img = 1;

	Imgs = (TImageList*)tv->Images;
	if (ItemSelected(ARow))	{
		Item = ItemDraw->Items[ARow - START_ROW];
		if (ACol == 0) {

			if (RecommendList->AnchorID == Item->ID)
				Img = ANCHOR_IMG;
			else if (Item->IsFolder == 1)
				Img = FOLDER_IMG;
			else
				Img = STRING_IMG;

			Imgs->Draw(c, Rect.left + 2, Rect.top + 2, Img, true);
			c->TextOutA(Rect.left + Imgs->Width + 4, Rect.top + 2, Item->Descr);
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


void __fastcall TRecommendForm::tvCompare(TObject *Sender, TTreeNode *Node1,
	  TTreeNode *Node2, int Data, int &Compare)
{
	TTreeBaseEmpty *Item1 = (TTreeBaseEmpty*)Node1->Data;
	TTreeBaseEmpty *Item2 = (TTreeBaseEmpty*)Node2->Data;

	if (Item1->IsFolder != Item2->IsFolder)
		if (Item1->IsFolder < Item2->IsFolder)
			Compare = 0;
		else
			Compare = 1;
	else
		Compare = CompareStr(Item1->Descr.TrimRight(), Item2->Descr.TrimRight());
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::dgGetEditText(TObject *Sender, int ACol,
	  int ARow, AnsiString &Value)
{
	if (SelItem == NULL)
		return;

	Value = SelItem->Descr;
}
//---------------------------------------------------------------------------




void __fastcall TRecommendForm::dgDblClick(TObject *Sender)
{
	TTreeNode *SelNode = tv->Selected;
	TTreeNode *node;
	TTreeBaseEmpty *Item;
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
			if (SetRichEdit != NULL)	{
				SetRichEdit->ItemID = Item->ID;
				Close();
			}
			if (SetEdit != NULL) {
				SetEdit->ItemID = Item->ID;
				Close();
			}
			if (AddRichEdit != NULL)	{
				AddRichEdit->Text = AddRichEdit->Text + Item->Descr + "; ";
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

void __fastcall TRecommendForm::dgExitEdit(TObject *Sender)
{
	TTreeNode *SelNode = tv->Selected;

	if (SelItem == NULL) {
		return;
	}
	SelItem->UpdateDB(DM->RecomUpdateQuery);
	dg->Options = dg->Options >> goEditing;
	tvChange(Sender, SelNode);
}


void __fastcall TRecommendForm::FormShow(TObject *Sender)
{
	TTreeNode *node;
	TTreeBaseEmpty *Item = new TTreeBaseEmpty(1, 0, 0);

	TADOQuery *q;
	q = DM->RecomQuery;
	RecommendList->RemoveItems();
	q->Open();
	RecommendList->FillFromDB(q);
	q->Close();
	RecommendList->SortByDescrAndIsFolder();

	Item->Descr = "Группы данных";

	tv->Items->Clear();

	node = tv->Items->AddChild(NULL, Item->Descr);
	node->Data = Item;

	FillTree(node, 0);

	SetAnchor(RecommendList->AnchorID);

	tv->Select(GetNodeByID(StartID), KeyDataToShiftState(0));
}


TTreeNode *TRecommendForm::GetNodeByID(int ItemID)
{
	TTreeBaseEmpty *Item;
	int i;

	for (i = 0; i < tv->Items->Count; i++) {
		Item = (TTreeBaseEmpty*)tv->Items->Item[i]->Data;
		if (Item->ID == ItemID) {
			return tv->Items->Item[i];
		}
	}
	return NULL;
}


//---------------------------------------------------------------------------

void __fastcall TRecommendForm::dgSetEditText(TObject *Sender, int ACol,
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

void __fastcall TRecommendForm::AddItem(int IsFolder)
{

}

void __fastcall TRecommendForm::AddFolderButtonClick(TObject *Sender)
{
	int MaxID;
	TTreeBaseEmpty* ParentItem;
	TTreeBaseEmpty *NewItem;
	TTreeNode *node;
	int mID;

	if (tv->Selected == NULL)
		return;

	tv->Selected->Expanded = true;
	ParentItem = (TTreeBaseEmpty*)tv->Selected->Data;
	MaxID = RecommendList->GetMaxID(DM->RecomGetMaxQuery);
	MaxID++;
	NewItem = new TTreeBaseEmpty(1, ParentItem->ID, MaxID);
	NewItem->InsertDB(DM->RecomInsertQuery);
	RecommendList->Add(NewItem);
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

void __fastcall TRecommendForm::AddTextButtonClick(TObject *Sender)
{
	int MaxID;
	TTreeBaseEmpty* ParentItem;
	TTreeBaseEmpty *NewItem;
	int mID, i;

	if (tv->Selected == NULL)
		return;

	tv->Selected->Expanded = true;
	ParentItem = ItemDraw->Root;
	MaxID = RecommendList->GetMaxID(DM->RecomGetMaxQuery);
	MaxID++;
	NewItem = new TTreeBaseEmpty(2, ParentItem->ID, MaxID);
	NewItem->InsertDB(DM->RecomInsertQuery);
	RecommendList->Add(NewItem);
	ItemDraw->Add(NewItem);
	tvChange(Sender, tv->Selected);
	dg->Row = ItemDraw->IndexByID(MaxID) + START_ROW;
	dg->Col = 0;
	dg->EditorMode = true;
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::DeleteButtonClick(TObject *Sender)
{
	TTreeBaseEmpty *Item;
	TTreeNode *node;
	int DelRec;
	bool b;

	if (tv->Focused())	{
		Item = (TTreeBaseEmpty*)tv->Selected->Data;
		if (Item->GetChildCountFromDB(DM->RecomChildCountQuery) != 0) {
			ShowMessage("Перед удалением папка больжна быть пустой.");
			return;
		}
		if ((DelRec = RecommendList->DeleteFromDB(Item, DM->RecomDeleteQuery)) == 1)	{
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
		if (Item->GetChildCountFromDB(DM->RecomChildCountQuery) != 0) {
			ShowMessage("Перед удалением папка больжна быть пустой.");
			return;
		}
		if ((DelRec = RecommendList->DeleteFromDB(Item, DM->RecomDeleteQuery)) == 1)	{
			ItemDraw->DeleteItem(Item);
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
void __fastcall TRecommendForm::FillItemDraw(TTreeBaseEmpty* ParentItem)
{
	int i;
	TTreeBaseEmpty* Item;

	ItemDraw->Clear();

	for (i = 0; i < RecommendList->Count; i++) {
		Item = RecommendList->Items[i];
		if (Item->ParentID == ParentItem->ID)
			ItemDraw->Add(Item);
	}

	ItemDraw->Root = ParentItem;
	ItemDraw->SortByDescrAndIsFolder();
}


void __fastcall TRecommendForm::tvChange(TObject *Sender, TTreeNode *Node)
{
	TTreeBaseEmpty *ParentItem;
	int cnt;


	if (Node != NULL)	{
		ParentItem = (TTreeBaseEmpty*)Node->Data;

		if (ParentItem->ID == 0)
			START_ROW = dg->FixedRows;
		else
			START_ROW = dg->FixedRows + 1;

		FillItemDraw(ParentItem);

		dg->RowCount = ItemDraw->Count + START_ROW;
	}
	else
		dg->RowCount = 2;

	dg->Repaint();

	DeleteButton->Enabled = true;
	EditButton->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	AddRichEdit = NULL;
	SetRichEdit = NULL;
	SetEdit = NULL;
	RecommendList->AnchorID = 0;
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::dgMouseWheelDown(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	sgMouseWheelDownA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::dgMouseWheelUp(TObject *Sender, TShiftState Shift,
	  TPoint &MousePos, bool &Handled)
{
	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::FormResize(TObject *Sender)
{
	int scroll;

	scroll = GetSystemMetrics(SM_CXVSCROLL);
	if (dg->RowCount > dg->Height / (dg->DefaultRowHeight + 2)) {
		scroll *= 2;
	}

	dg->ColWidths[0] = dg->Width - scroll;
}
//---------------------------------------------------------------------------


void __fastcall TRecommendForm::EditButtonClick(TObject *Sender)
{
	if (dg->Focused()) {
		dg->Options = dg->Options << goEditing;
		dg->EditorMode = true;
	}
	if (tv->Focused()) {
        tv->Selected->EditText();
	}
}
//---------------------------------------------------------------------------


void __fastcall TRecommendForm::dgSelectCell(TObject *Sender, int ACol,
	  int ARow, bool &CanSelect)
{

	SelRow = ARow;
	if (ItemSelected(ARow))	{
		DeleteButton->Enabled = true;
		EditButton->Enabled = true;
		SelItem = ItemDraw->Items[ARow - START_ROW];
	}
	else	{
		DeleteButton->Enabled = false;
		EditButton->Enabled = false;
		SelItem = NULL;
	}
}
//---------------------------------------------------------------------------



void __fastcall TRecommendForm::dgMouseDown(TObject *Sender,
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

	if (rect.left + 2 <= X &&  rect.left + 18 >= X)
	if (rect.top <= Y && rect.bottom >= Y)
		IconClickDown = true;
	else	{
		IconClickDown = false;
		if (SelItem->IsFolder == 2)
			dg->BeginDrag(false, 10);
    }
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::EditIconClick(TObject *Sender)
{
	EditButtonClick(Sender);
}


void __fastcall TRecommendForm::dgMouseUp(TObject *Sender,
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

void __fastcall TRecommendForm::dgEnter(TObject *Sender)
{
	bool b;
	dgSelectCell(Sender, dg->Col, dg->Row, b);
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::tvEnter(TObject *Sender)
{
	tvChange(Sender, tv->Selected);
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::tvEdited(TObject *Sender, TTreeNode *Node,
	  AnsiString &S)
{
	TTreeBaseEmpty *Item = (TTreeBaseEmpty*)(Node->Data);

	Item->Descr = S;
	Item->UpdateDB(DM->RecomUpdateQuery);
}
//---------------------------------------------------------------------------


void __fastcall TRecommendForm::FormCreate(TObject *Sender)
{
	ItemDraw = new TTreeBaseEmptyList();
	START_ROW = 2;
}
//---------------------------------------------------------------------------


void __fastcall TRecommendForm::FormDestroy(TObject *Sender)
{
	ItemDraw->Clear();
	delete ItemDraw;	
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::SetAnchor(int Value)
{
	int i;
	TTreeBase* Data;

	for (i = 0; i < tv->Items->Count; i++) {
		Data = (TTreeBase*)(tv->Items->Item[i]->Data);
		if (tv->Items->Item[i]->StateIndex == ANCHOR_IMG)	{
			tv->Items->Item[i]->StateIndex = FOLDER_IMG;
		}
	}

	for (i = 0; i < tv->Items->Count; i++) {
		Data = (TTreeBase*)(tv->Items->Item[i]->Data);
		if (Value == Data->ID) {
			tv->Items->Item[i]->StateIndex = ANCHOR_IMG;
			return;
		}
	}
}
void __fastcall TRecommendForm::AnchorButtonClick(TObject *Sender)
{
	TAttrAppoint* aa = NULL;
	String FieldName;
	TTreeBase *Item;
	TTreeNode *node;
	TRichEditSpec* re;

	if (dg->Focused()) {
		if (SelItem == NULL && SelItem->IsFolder != 1)
			return;
		else
			Item = SelItem;
	}
	else if (tv->Focused()) {
		node = tv->Selected;
		if (node == NULL || node->Data == NULL)
			return;
		else
			Item = (TTreeBase*)node->Data;
	}
	else
    	return;

	if (AddRichEdit != NULL) {
		aa = AttrAppointList->ItemByDescr(AddRichEdit->FieldName);
		re = AddRichEdit;
	}
	else if (SetRichEdit != NULL) {
		aa = AttrAppointList->ItemByDescr(SetRichEdit->FieldName);
		re = SetRichEdit;
	}
	else
		return;

	if (aa == NULL)
		return;
	
	aa->AnchorID = Item->ID;
	aa->Save(NULL, NULL, DM->AttrAppointUpdateQuery, NULL);
	re->AnchorID = Item->ID;
	RecommendList->SetAnchorID(Item->ID);
	SetAnchor(Item->ID);
	dg->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::tvDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
	TTreeBaseEmpty* Item;
	TTreeNode *DropNode, *NewNode;
	int Img;

	if (tv->DropTarget == NULL)
		return;
	Item = (TTreeBaseEmpty*)tv->DropTarget->Data;
	if (Item == NULL || SelItem == NULL || Item == SelItem)
		return;

	if (Source == dg)	{
		ItemDraw->Remove(SelItem);
		if (SelItem->IsFolder == 1) {
			/*if (RecommendList->ExistParent() ) {
                
			}
			DropNode = GetNodeByID(SelItem->ID);
			if (DropNode == NULL)
				throw "Error tvDragDrop!";
			Img = DropNode->StateIndex;
			if (SelItem == RecommendList->Anchor)
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
			SelItem->Save(NULL, NULL, DM->RecomUpdateQuery, NULL);
			tvChange(Sender, tv->Selected);
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TRecommendForm::tvDragOver(TObject *Sender, TObject *Source,
	  int X, int Y, TDragState State, bool &Accept)
{
	if (Source == dg) {
		Accept = true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TRecommendForm::ChangeFont(TFont *f)
{
	int h, w;
	TImageList *iList;

	Font->Assign(f);
	ToolBarAutoSizeLevelDown(ToolBar1);
	ToolBarAutoIcon(ToolBar1, Images->ImageList4, Images->ImageList5, Images->ImageList6);
	TreeViewAutoIcon(tv, Images->ImageList1, Images->ImageList2, Images->ImageList3);
	DrawGridRowsAutoHeigth(dg, (TImageList*)tv->Images);
}
