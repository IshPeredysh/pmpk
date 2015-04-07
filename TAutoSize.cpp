//---------------------------------------------------------------------------


#pragma hdrstop

#include "TAutoSize.h"
#include <Graphics.hpp>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)

int __fastcall GetTextWidth(TMyControl *c, String Text)
{
	int w, h;
	Graphics::TBitmap *bm = new Graphics::TBitmap;

	bm->Canvas->Font->Assign(c->MyFont);
	w = bm->Canvas->TextWidth(Text);
	h = bm->Canvas->TextHeight(Text);
	if (c->AlignWithMargins)
		h += 6;

//	c->Width = w + 25;

	delete bm;
	return w;
}

int __fastcall DateTimePickerAutoSize(TDateTimePicker *d)
{
	int w, h;
	char c[20] = "TTTTTTTTTT";
	Graphics::TBitmap *bm = new Graphics::TBitmap;

//	d->GetTextBuf(c, 20);
	bm->Canvas->Font->Assign(d->Font);
	w = bm->Canvas->TextWidth(String(c));
	h = bm->Canvas->TextHeight(String(c));
	if (d->AlignWithMargins)
		h += 6;

	d->Width = w + 25;

	delete bm;
	return h;
}

int __fastcall CheckBoxAutoSize(TCheckBox *d)
{
	int w, h;
	char c[20] = "TTTTTTTTTT";
	Graphics::TBitmap *bm = new Graphics::TBitmap;
    
//	d->GetTextBuf(c, 20);
	bm->Canvas->Font->Assign(d->Font);
	w = bm->Canvas->TextWidth(d->Caption);
	h = bm->Canvas->TextHeight(String(c));
	if (d->AlignWithMargins)
		h += 6;

	d->Width = w + 25;

	delete bm;
	return h;
}

int __fastcall ComboBoxGetMaxTextLen(TComboBox *d)
{
	int i, w, max;
	Graphics::TBitmap *bm = new Graphics::TBitmap;

	bm->Canvas->Font->Assign(d->Font);	max = 0;
	for (i = 0; i < d->Items->Count; i++) {
		w = bm->Canvas->TextWidth(d->Items->Strings[i]);
		if (max < w)
			max = w;
	}

	delete bm;
	return max;
}

int __fastcall ComboBoxAutoSize(TComboBox *d)
{
	int w, h;

	w = ComboBoxGetMaxTextLen(d);
	h = d->Canvas->TextHeight(d->Text);
	d->Width = w + 25;
	if (d->AlignWithMargins)
		h += 6;

	return h;
}

int __fastcall EditAutoSize(TEdit *d)
{
	int w, h;
	Graphics::TBitmap *bm = new Graphics::TBitmap;

	bm->Canvas->Font->Assign(d->Font);
	w = bm->Canvas->TextWidth(d->Text);
	h = bm->Canvas->TextHeight(d->Text);
	if (d->AlignWithMargins)
		h += 6;

//	d->Width = w + 25;

	delete bm;
	return h;
}


int __fastcall ButtonAutoSize(TButton *d)
{
	int w, h;
	Graphics::TBitmap *bm = new Graphics::TBitmap;

	bm->Canvas->Font->Assign(d->Font);
	w = bm->Canvas->TextWidth(d->Caption);
	h = bm->Canvas->TextHeight(d->Caption);
	if (d->AlignWithMargins)
		h += 6;

	d->Width = w + 6;

	delete bm;
	return h;
}

int __fastcall ToolButtonAutoSize(TToolButton *d)
{
	int w, h;
	TToolBar *tb = (TToolBar*)d->Parent;

	h = tb->Images->Height;
	w = tb->Images->Width;

	tb->ButtonWidth = w + 6;

	return h + 6;
}

int __fastcall LabelAutoSize(TLabel *d)
{
	int w, h;

	w = d->Canvas->TextWidth(d->Caption);
	h = d->Canvas->TextHeight(d->Caption);
	d->Width = w + 10;
	if (d->Tag) {
		d->Width = d->Width / d->Tag;
		h = h * (d->Tag + 1);
	}
	if (d->AlignWithMargins)
		h += 6;

	return h;
}



int __fastcall RichEditGetHeight(TRichEdit *m)
{
	int len, h, LinesCount, NewHeight;
	String lastChar;
	TPanel *p;
	TGroupBox *g;

//	len = m->Lines->Text.Length();
	LinesCount = m->Perform(EM_GETLINECOUNT, 0, 0);
	m->Perform(WM_VSCROLL, SB_TOP, 0);

//	lastChar = m->Lines->Text.SubString(len - 1, 2);

	h = (LinesCount * (m->Font->Height + (m->Font->Height + m->Font->Size)) * -1);
	if (m->AlignWithMargins)
		h += 6;

	return h;
}

int __fastcall RichEditAutoHeightLevelUp(TRichEdit *m)
{
	int h;

    h = RichEditGetHeight(m);

	if (m->Height != h)
		ControlAutoSizeLevelUp(m->Parent);

	return h;
}

int __fastcall PanelAutoSizeLevelDown(TPanel *p)
{
	int i, MaxHeight, h;
	TControl* c;
	String cName;

	MaxHeight = 0;
	for (i = 0; i < p->ControlCount; i++) {
		c = p->Controls[i];
		cName = String(c->ClassName());
		h = ControlAutoSizeLevelDown(c);
		if (MaxHeight < h)
			MaxHeight = h;
	}
	MaxHeight += 10;
	p->Height = MaxHeight;
	return MaxHeight;
}

int __fastcall PanelAutoSizeLevelUp(TPanel *p)
{
	int i, MaxHeight, h;
	TControl* c;
	String cName;

	MaxHeight = 0;
	for (i = 0; i < p->ControlCount; i++) {
		c = p->Controls[i];
		cName = String(c->ClassName());
		h = ControlAutoSizeLevelDown(c);
		if (MaxHeight < h)
			MaxHeight = h;
	}
	MaxHeight += 10;
	p->Height = MaxHeight;

	ControlAutoSizeLevelUp(p->Parent);
	return MaxHeight;
}



int __fastcall GroupBoxGetCaptionHeigh(TGroupBox *d)
{
	int w, h;
	Graphics::TBitmap *bm = new Graphics::TBitmap;
	TAlign AlignState;

	bm->Canvas->Font->Assign(d->Font);
	w = bm->Canvas->TextWidth(d->Caption);
	h = bm->Canvas->TextHeight(d->Caption);

	delete bm;
	return h;
}

int __fastcall GroupBoxAutoSizeLevelDown(TGroupBox *p)
{
	int i, SumHeight, h;
	TControl* c;
	String cName;

	SumHeight = 0;
	for (i = 0; i < p->ControlCount; i++) {
		c = p->Controls[i];
		cName = String(c->ClassName());
		SumHeight += ControlAutoSizeLevelDown(c);
	}
	SumHeight += GroupBoxGetCaptionHeigh(p) + 8;

	p->Height = SumHeight;
	return SumHeight;
}

int __fastcall GroupBoxAutoSizeLevelUp(TGroupBox *p)
{
	int i, SumHeight, h;
	TControl* c;
	String cName;

	SumHeight = 0;
	for (i = 0; i < p->ControlCount; i++) {
		c = p->Controls[i];
		cName = String(c->ClassName());
		SumHeight += ControlAutoSizeLevelDown(c);
	}
	SumHeight += GroupBoxGetCaptionHeigh(p) + 8;

	p->Height = SumHeight;

	ControlAutoSizeLevelUp(p->Parent);
	return SumHeight;
}

int __fastcall ToolBarAutoSizeLevelDown(TToolBar *t)
{
	int i, MaxHeight, h;
	TControl* c;
	String cName;

	MaxHeight = 0;
	for (i = 0; i < t->ControlCount; i++) {
		c = t->Controls[i];
		cName = String(c->ClassName());
		h = ControlAutoSizeLevelDown(c);
		if (MaxHeight < h)
			MaxHeight = h;
	}
//	MaxHeight += 10;
	t->ButtonHeight = MaxHeight;
	t->Height = MaxHeight;
	return MaxHeight;
}

void __fastcall ToolBarAutoIcon(TToolBar *tb, TImageList *l1, TImageList *l2, TImageList *l3)
{
	int h, w;
	TImageList *iList;
	TFont *f = tb->Font;

	h = tb->Canvas->TextHeight("Tp");
	if (l3->Height < ((f->Height*2 + f->Size)*(-1)) ) {
		iList = l3;
		tb->Images = iList;
		tb->ButtonHeight = iList->Height;
		tb->ButtonWidth = iList->Width;
	}
	else if (l2->Height < ((f->Height*2 + f->Size)*(-1)) )	{
		iList = l2;
		tb->Images = iList;
		tb->ButtonHeight = iList->Height;
		tb->ButtonWidth = iList->Width;
	}
	else	{
		iList = l1;
		tb->Images = iList;
		tb->ButtonHeight = iList->Height;
		tb->ButtonWidth = iList->Width;
	}
}

int __fastcall ControlAutoSizeLevelUp(TControl *c)
{
	String cName;
	int h;

	cName = String(c->ClassName());

	if (cName == "TLabel")	{
		h = LabelAutoSize((TLabel*)c);
	}
	else if (cName == "TEditSpec" || cName == "TEdit") {
		h = EditAutoSize((TEdit*)c);
	}
	else if (cName == "TButton") {
		h = ButtonAutoSize((TButton*)c);
	}
	else if (cName == "TToolButton") {
		h = ToolButtonAutoSize((TToolButton*)c);
	}
	else if (cName == "TComboBoxSpec" || cName == "TComboBox") {
		h = ComboBoxAutoSize((TComboBox*)c);
	}
	else if (cName == "TDateTimePickerSpec" || cName == "TDateTimePicker") {
		h = DateTimePickerAutoSize((TDateTimePicker*)c);
	}
	else if (cName == "TRichEditSpec" || cName == "TRichEdit") {
		h = RichEditGetHeight((TRichEdit*)c);
	}
	else if (cName == "TPanel") {
		h = PanelAutoSizeLevelUp((TPanel*)c);
	}
	else if (cName == "TGroupBox") {
		h = GroupBoxAutoSizeLevelUp((TGroupBox*)c);
	}
	return h;
}

int __fastcall ControlAutoSizeLevelDown(TControl *c)
{
	String cName;
	int h;

	h = 0;
	cName = String(c->ClassName());
	if (cName == "TLabel")	{
		h = LabelAutoSize((TLabel*)c);
	}
	else if (cName == "TCheckBox")	{
		h = CheckBoxAutoSize((TCheckBox*)c);
	}
	else if (cName == "TEditSpec" || cName == "TEdit") {
		h = EditAutoSize((TEdit*)c);
	}
	else if (cName == "TButton") {
		h = ButtonAutoSize((TButton*)c);
	}
	else if (cName == "TToolButton") {
		h = ToolButtonAutoSize((TToolButton*)c);
	}
	else if (cName == "TComboBoxSpec" || cName == "TComboBox") {
		h = ComboBoxAutoSize((TComboBox*)c);
	}
	else if (cName == "TDateTimePickerSpec" || cName == "TDateTimePicker") {
		h = DateTimePickerAutoSize((TDateTimePicker*)c);
	}
	else if (cName == "TRichEditSpec" || cName == "TRichEdit") {
		h = RichEditGetHeight((TRichEdit*)c);
	}
	else if (cName == "TPanel") {
		h = PanelAutoSizeLevelDown((TPanel*)c);
	}
	else if (cName == "TGroupBox") {
		h = GroupBoxAutoSizeLevelDown((TGroupBox*)c);
	}
	return h;
}

void __fastcall TreeViewAutoIcon(TTreeView *tv, TImageList *l1, TImageList *l2, TImageList *l3)
{
	int h, w;
	TImageList *iList;
	TFont *f = tv->Font;

	h = tv->Canvas->TextHeight("Tp");
	if (l3->Height < ((f->Height*2 + f->Size)*(-1)) ) {
		iList = l3;
		tv->Images = iList;
		tv->StateImages = iList;
	}
	else if (l2->Height < ((f->Height*2 + f->Size)*(-1)) )	{
		iList = l2;
		tv->Images = iList;
		tv->StateImages = iList;
	}
	else	{
		iList = l1;
		tv->Images = iList;
		tv->StateImages = iList;
	}
	tv->Indent = tv->Images->Width + 3;
}

void __fastcall DrawGridRowsAutoHeigth(TDrawGrid *dg, TImageList *iList)
{
	int h;

	h = (dg->Font->Height*2 + dg->Font->Size)*(-1);
//	h = dg->Canvas->TextHeight("Tp");
	if (h < iList->Height)
		h = iList->Height;
	dg->DefaultRowHeight = h + 2;
}

TImageList* __fastcall ImageListByFont(TFont *f, TImageList *l1, TImageList *l2, TImageList *l3)
{
	if (l3->Height < ((f->Height*2 + f->Size)*(-1)) ) {
		return l3;
	}
	else if (l2->Height < ((f->Height*2 + f->Size)*(-1)) )	{
		return l2;
	}
	else	{
		return l1;
	}

}
