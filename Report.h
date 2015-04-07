//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ReportH
#define ReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include "TSpecFieldObject.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------

struct TListItemID	{
	int ListID;
	int ItemID;
	String Caption;
};

class TListItemMas	{
	private:
		TList* FList;
		int GetCount() {return FList->Count;};
		TListItemID* GetItem(int i) {return (TListItemID*)FList->Items[i];};
	public:
		TListItemMas();
		TListItemID* Add(int ListID, int ItemID, String Caption);
		int IndexByListItem(int ListID, int ItemID);
		__property int Count = {read=GetCount};
		__property TListItemID* Items[int i] = {read=GetItem};
};

enum TListItemEnum	{liCol, liRow};

class TListItem2D
{
	private:
		TList* FList[2];
		int ColCount, RowCount;
	public:
		TListItem2D();
		TListItemID* AddCol(int List, int Item, String Caption);
		~TListItem2D();
};



class TReportForm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TDateTimePicker *DateTimePicker1;
	TPanel *Panel2;
	TPanel *Panel3;
	TDateTimePicker *DateTimePicker2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TListBox *lb;
	TPanel *Panel1;
	TButton *Button1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TGridPanel *GridPanel1;
	TPanel *Panel4;
	TPanel *Panel5;
	TLabel *Label1;
	TListBox *ListBox1;
	TPanel *Panel6;
	TPanel *Panel7;
	TLabel *Label2;
	TListBox *ListBox2;
	TPanel *Panel8;
	TButton *Button4;
	TCheckBox *CurrentYearCheckBox;
	TButton *Button5;
	TButton *Button6;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall CurrentYearCheckBoxClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TReportForm(TComponent* Owner);
	void __fastcall CreateReport();
	void __fastcall FillList();
	String GetBoxValue(int ListID, int ItemID);
	String GetListValue(int ListID, int ItemID);
	String GetValue(TRepField *spec);
	void __fastcall CleanList(TListBox* box);
	void __fastcall FillList(TListBox* box);
	void GetSpec(TRepField *spec1, TRepField *spec2, TADOQuery *q);
	int CreateReport2();
	void GetSpec(TRepField *spec, TADOQuery *q);
	void SaveINI();
	void LoadINI();
};
//---------------------------------------------------------------------------
extern PACKAGE TReportForm *ReportForm;
//---------------------------------------------------------------------------
#endif
