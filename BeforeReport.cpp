//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BeforeReport.h"
#include "TObjMas.h"
#include "TChildrenList.h"
#include "TDrawBaseList.h"
#include "DrawChild.h"
#include "MouseWheelUnit.h"
#include "Report.h"
#include "ReportAgeGroups.h"

extern TChildrenList* Childrens;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBeforeReportForm *BeforeReportForm;

//------------TBeforeReportForm------------

//---------------------------------------------------------------------------
__fastcall TBeforeReportForm::TBeforeReportForm(TComponent* Owner)
	: TForm(Owner)
{
}

void TBeforeReportForm::ClearGrid()
{
	int c, r;

	try {
		for (c = 0; c < sg->ColCount; c++) {
			for (r = 0; r < sg->RowCount; r++) {
				if (sg->Objects[c][r] != NULL)
					delete (TCellObjList*)sg->Objects[c][r];
					sg->Objects[c][r] = NULL;
					sg->Cells[c][r] = "";
			}
		}
	} catch (...) {
		return;
	}
}

//---------------------------------------------------------------------------
void __fastcall TBeforeReportForm::FormShow(TObject *Sender)
{
	/*TDrawChildList *cl;
	int i;

	ClearGrid();
	cl = new TDrawChildList();

	for (i = 0; i < Childrens->Count ; i++) {
		if (Childrens->Children[i]->Descr.Length() > 0 && Childrens->Children[i]->Descr.SubString(1, 1) == 'À') {
			cl->Add(Childrens->Children[i]);
		}
	}

	sg->Cells[1][1] = "text";
	sg->Objects[1][1] = (TObject*)new TCellObjList(tlChild, cl); */
}
//---------------------------------------------------------------------------


void __fastcall TBeforeReportForm::sgDblClick(TObject *Sender)
{

	TDrawChildForm *cf;

//	cf->DrawList = (TDrawChildList*)sg->Objects[1][1];
	if (sg->Objects[sg->Col][sg->Row] != NULL) {
		cf = new TDrawChildForm(Application);
		cf->DrawList = (TDrawChildList*)((TCellObjList*)(sg->Objects[sg->Col][sg->Row]))->List;
		cf->Show();
	}
//	Application->CreateForm(ActiveMDIChild, TChildrensForm, )

}
//---------------------------------------------------------------------------

void __fastcall TBeforeReportForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	ClearGrid();
	ExportExcel = NULL;	
}
//---------------------------------------------------------------------------

void __fastcall TBeforeReportForm::sgDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
//    TCanvas *c = sg->Canvas;

	tagRECT r = Rect;
	int h, pos;
	String s = sg->Cells[ACol][ARow];
	UINT flag = 0;

	r.left = r.left + 2;
	r.top = r.top + 2;
	/*if (sg->Objects[ACol][ARow] != NULL) {
		c->Brush->Color = clMenu;
		c->FillRect(Rect);
//		c->TextOutA(Rect.Left + 1, Rect.Top + 1, sg->Cells[ACol][ARow]);
	} */
	flag = DT_WORDBREAK | DT_LEFT;   /* | DT_CALCRECT*/
	if ((pos = s.Pos("<b>")) > 0) {
		sg->Canvas->Font->Style = sg->Canvas->Font->Style << fsBold;
		s.Delete(pos, 3);
	}
	if ((pos = s.Pos("<l>")) > 0) {
		flag = flag | DT_LEFT;
		s.Delete(pos, 3);
	}
	if ((pos = s.Pos("<c>")) > 0) {
		flag = flag | DT_CENTER;
		s.Delete(pos, 3);
	}

	sg->Canvas->FillRect(Rect);
	h = DrawText(sg->Canvas->Handle, s.c_str(), s.Length(), &r, flag);
	if (sg->RowHeights[ARow] < h)
		sg->RowHeights[ARow] = h;
}
//---------------------------------------------------------------------------

void __fastcall TBeforeReportForm::sgMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	sgMouseWheelDownA(Sender, Shift, MousePos, Handled);	
}
//---------------------------------------------------------------------------

void __fastcall TBeforeReportForm::sgMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	sgMouseWheelUpA(Sender, Shift, MousePos, Handled);	
}
//---------------------------------------------------------------------------


void __fastcall TBeforeReportForm::ExeclButtonClick(TObject *Sender)
{
	if (ExportExcel) {
		ExportExcel(ReportForm->DateTimePicker1->Date, ReportForm->DateTimePicker2->Date);
	}
//	CreateReportAgeGruops(ReportForm->DateTimePicker1->Date, ReportForm->DateTimePicker2->Date);
}
//---------------------------------------------------------------------------

void __fastcall TBeforeReportForm::FormCreate(TObject *Sender)
{
	ExportExcel = NULL;		
}
//---------------------------------------------------------------------------

