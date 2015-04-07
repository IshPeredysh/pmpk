//---------------------------------------------------------------------------

#ifndef TAutoSizeH
#define TAutoSizeH
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------

class TMyControl: public TControl
{
	public:
		__property TFont *MyFont = {read=Font, write=Font};
};

int __fastcall GetTextWidth(TMyControl *c, String Text);

//void __fastcall PanelControlsAutoSize(TPanel *p);
int __fastcall DateTimePickerAutoSize(TDateTimePicker *d);
int __fastcall CheckBoxAutoSize(TCheckBox *d);

int __fastcall ComboBoxAutoSize(TComboBox *d);
int __fastcall ComboBoxGetMaxTextLen(TComboBox *d);

int __fastcall EditAutoSize(TEdit *d);
int __fastcall LabelAutoSize(TLabel *d);

int __fastcall ButtonAutoSize(TButton *d);
int __fastcall ToolButtonAutoSize(TButton *d);

int __fastcall RichEditGetHeight(TRichEdit *m);
int __fastcall RichEditAutoHeightLevelUp(TRichEdit *m);

int __fastcall PanelAutoSizeLevelDown(TPanel *p);
int __fastcall PanelAutoSizeLevelUp(TPanel *p);

int __fastcall GroupBoxAutoSizeLevelDown(TGroupBox *p);
int __fastcall GroupBoxGetCaptionHeigh(TGroupBox *d);
int __fastcall GroupBoxAutoSizeLevelUp(TGroupBox *p);

int __fastcall ToolBarAutoSizeLevelDown(TToolBar *t);
void __fastcall ToolBarAutoIcon(TToolBar *tb, TImageList *l1, TImageList *l2, TImageList *l3);

int __fastcall ControlAutoSizeLevelDown(TControl *c);
int __fastcall ControlAutoSizeLevelUp(TControl *c);

void __fastcall TreeViewAutoIcon(TTreeView *tv, TImageList *l1, TImageList *l2, TImageList *l3);

void __fastcall DrawGridRowsAutoHeigth(TDrawGrid *dg, TImageList *iList);

TImageList* __fastcall ImageListByFont(TFont *f, TImageList *l1, TImageList *l2, TImageList *l3);

#endif
