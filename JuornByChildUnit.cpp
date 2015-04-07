//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JuornByChildUnit.h"
#include "DMUnit.h"
#include "TProtocol.h"
#include "Protocol.h"
#include "TChildrenList.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TJournByChildForm *JournByChildForm;
extern TChildrenList* Childrens;
//---------------------------------------------------------------------------
__fastcall TJournByChildForm::TJournByChildForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

int TJournByChildForm::FillGrid(int ChildID)
{
	int r;
	TADOQuery *q = DM->JournByChildIDQuery;
	TProtocol *p;

	sg->Cells[1][0] = "Дата";
	sg->Cells[2][0] = "Номер";
	sg->Cells[3][0] = "Ребёнок";

	q->Parameters->ParamByName("ChildID")->Value = ChildID;

	q->Open();
	q->First();
	r = 1;
	while (!q->Eof)	{
		sg->Objects[0][r] = (TObject*)new TProtocol(q);
		q->Next();
		r++;
	}
	sg->RowCount = r;
	q->Close();
	return r;
}

void TJournByChildForm::ClearGrid()
{
	int i;

	try {
		for (i = 0; i < sg->RowCount; i++) {
			delete (TProtocol*)sg->Objects[0][i];
		}
	} catch (...) {
		return;
	}
}
void __fastcall TJournByChildForm::sgMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	sgMouseWheelDown(Sender,Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------
void __fastcall TJournByChildForm::sgMouseWheelUp(TObject *Sender,
	  TShiftState Shift, TPoint &MousePos, bool &Handled)
{
	sgMouseWheelUp(Sender,Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------
void __fastcall TJournByChildForm::sgDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
	TCanvas *c = sg->Canvas;
	TChildren *child;
	TProtocol *p;
	int id, Img;

	if (ARow > 0) {
		p = (TProtocol*)sg->Objects[0][ARow];
		if (sg->Objects[0][ARow] != NULL)
			switch (ACol) {
			case 0:
				/*if (p->Closed == 1)
					Img = 4;
				else*/
					Img = 2;
				ImageList1->Draw(c, Rect.left, Rect.top, Img, true);
				break;
			case 1:
				c->TextOutA(Rect.left + 2, Rect.top + 2, p->Date.DateString());
				break;
			case 2:
				c->TextOutA(Rect.left + 2, Rect.top + 2, IntToStr(p->DocNo));
				break;
			case 3:
				id = p->ChildID;
				child = (TChildren*)Childrens->ItemByID(id);
				if (child != NULL)
					c->TextOutA(Rect.left + 2, Rect.top + 2, child->Descr);
				else
					c->TextOutA(Rect.left + 2, Rect.top + 2, "Не указан");
				break;
            }
	}
}
//---------------------------------------------------------------------------
void __fastcall TJournByChildForm::sgDblClick(TObject *Sender)
{

//	ProtocolForm->prot = (TProtocol*)(sg->Objects[0][sg->Row]);
	ProtocolForm->GetProtocol((TProtocol*)(sg->Objects[0][sg->Row]));
	ProtocolForm->Show();

}
//---------------------------------------------------------------------------
