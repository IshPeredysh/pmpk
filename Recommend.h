//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef RecommendH
#define RecommendH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TDrawGridSpec.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "RichEditSpec.h"
#include "RichEditSpec.h"
#include "TTreeBaseEmptyList.h"
#include "TEditSpec.h"
//---------------------------------------------------------------------------
class TRecommendForm : public TForm
{
__published:	// IDE-managed Components
	TTreeView *tv;
	TSplitter *Splitter1;
	TDrawGridSpec *dg;
	TToolBar *ToolBar1;
	TToolButton *AddFolderButton;
	TToolButton *AddTextButton;
	TToolButton *DeleteButton;
	TToolButton *EditButton;
	TToolButton *ToolButton1;
	TToolButton *AnchorButton;
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall tvCompare(TObject *Sender, TTreeNode *Node1, TTreeNode *Node2,
          int Data, int &Compare);
	void __fastcall dgGetEditText(TObject *Sender, int ACol, int ARow,
		  AnsiString &Value);
	void __fastcall dgDblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall dgSetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
	void __fastcall dgExitEdit(TObject *Sender);
	void __fastcall AddFolderButtonClick(TObject *Sender);
	void __fastcall AddTextButtonClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall tvChange(TObject *Sender, TTreeNode *Node);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall dgMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall dgMouseWheelUp(TObject *Sender, TShiftState Shift,
		  TPoint &MousePos, bool &Handled);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall dgSelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect);
	void __fastcall dgMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
	void __fastcall dgMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall dgEnter(TObject *Sender);
	void __fastcall tvEnter(TObject *Sender);
	void __fastcall tvEdited(TObject *Sender, TTreeNode *Node, AnsiString &S);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall AnchorButtonClick(TObject *Sender);
	void __fastcall tvDragDrop(TObject *Sender, TObject *Source, int X, int Y);
	void __fastcall tvDragOver(TObject *Sender, TObject *Source, int X, int Y,
          TDragState State, bool &Accept);
private:	// User declarations
public:		// User declarations
	__fastcall TRecommendForm(TComponent* Owner);
	int StartID;
	int START_ROW;
	TTreeBaseEmptyList* ItemDraw;
	int SelRow;
	TRichEditSpec* AddRichEdit;
	TRichEditSpec * SetRichEdit;
	TEditSpec *SetEdit;
	TTreeBaseEmpty *SelItem;
	int IconClickDown;
	void FillTree(TTreeNode *ParentNode, int ParentID);
	void __fastcall AddItem(int IsFolder);
	TTreeNode* GetNodeByID(int ItemID);
	void __fastcall FillItemDraw(TTreeBaseEmpty* ParentItem);
	int __fastcall ItemSelected(int Row);
	void __fastcall EditIconClick(TObject *Sender);
	void __fastcall SetAnchor(int Value);
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TRecommendForm *RecommendForm;
//---------------------------------------------------------------------------
#endif
