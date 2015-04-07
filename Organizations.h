//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef OrganizationsFormH
#define OrganizationsFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "TDrawGridSpec.h"
#include "RichEditSpec.h"
#include "TEditSpec.h"
#include "TChildren.h"
#include "TOrganization.h"
#include "TOrganizationList.h"

//---------------------------------------------------------------------------
class TOrganizationsForm : public TForm
{
__published:	// IDE-managed Components
	TTreeView *tv;
	TSplitter *Splitter1;
	TToolBar *ToolBar1;
	TDrawGridSpec *dg;
	TToolButton *AddFolderButton;
	TToolButton *AddTextButton;
	TToolButton *DeleteButton;
	TListBox *lb;
	TToolButton *EditButton;
	TToolButton *ToolButton1;
	TToolButton *AnchorButton;
	void __fastcall dgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall tvCompare(TObject *Sender, TTreeNode *Node1, TTreeNode *Node2,
          int Data, int &Compare);
	void __fastcall dgGetEditText(TObject *Sender, int ACol, int ARow,
		  AnsiString &Value);
	void __fastcall lbExit(TObject *Sender);
	void __fastcall lbClick(TObject *Sender);
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
	void __fastcall tvDragOver(TObject *Sender, TObject *Source, int X, int Y,
          TDragState State, bool &Accept);
	void __fastcall tvDragDrop(TObject *Sender, TObject *Source, int X, int Y);
private:	// User declarations
	void __fastcall SetEditIconClick(TNotifyEvent Value);
public:		// User declarations
	__fastcall TOrganizationsForm(TComponent* Owner);
	int START_ROW;
	int StartID;
	TOrganizationList* ItemDraw;
	int SelRow;
	TRichEditSpec* AddRichEdit;
	TRichEditSpec * SetRichEdit;
	TEditSpec *SetEdit;
	TOrganization *SelItem;
	int IconClickDown;
	void FillTree(TTreeNode *ParentNode, int ParentID);
	void __fastcall AddItem(int IsFolder);
	TTreeNode* GetNodeByID(int ItemID);
	void __fastcall FillOrgDraw(TOrganization* ParentOrg);
	int __fastcall ItemSelected(int Row);
	void __fastcall EditIconClick(TObject *Sender);
    void __fastcall ChangeFont(TFont *f);

};
//---------------------------------------------------------------------------
extern PACKAGE TOrganizationsForm *OrganizationsForm;
//---------------------------------------------------------------------------
#endif
