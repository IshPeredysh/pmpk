//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ProtocolH
#define ProtocolH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "TEditSpec.h"
#include "TDateTimePickerSpec.h"
#include "TMemoSpec.h"
#include "TComboBoxSpec.h"
#include <Buttons.hpp>
#include "RichEditSpec.h"
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "TProtocol.h"
#include "TDrawBaseList.h"
#include "TBaseEmptyList.h"
#include "TTreeBaseEmptyList.h"
#include "THelpListBox.h"
#include "TChildren.h"
#include "TParent.h"
//---------------------------------------------------------------------------

class TProtocolForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *CommonTab;
	TScrollBox *ScrollBox1;
	TGroupBox *GroupBox1;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label1;
	TEditSpec *EditSpec1;
	TDateTimePickerSpec *DateTimePickerSpec1;
	TGroupBox *GroupBox2;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TGroupBox *GroupBox5;
	TGroupBox *GroupBox6;
	TGroupBox *GroupBox7;
	TScrollBox *ScrollBox2;
	TGroupBox *GroupBox8;
	TGroupBox *GroupBox9;
	TGroupBox *GroupBox10;
	TPanel *Panel16;
	TDateTimePickerSpec *DateTimePickerSpec2;
	TLabel *Label4;
	TPanel *Panel17;
	TComboBoxSpec *ComboBoxSpec1;
	TLabel *Label16;
	TPanel *Panel18;
	TLabel *Label6;
	TLabel *Label5;
	TPanel *Panel19;
	TLabel *Label7;
	TRichEditSpec *RichEditSpec2;
	TPanel *Panel24;
	TPanel *Panel25;
	TLabel *Label11;
	TLabel *Label12;
	TPanel *Panel26;
	TLabel *Label14;
	TSpeedButton *SpeedButton1;
	TRichEditSpec *RichEditSpec4;
	TRichEditSpec *RichEditSpec5;
	TRichEditSpec *RichEditSpec7;
	TRichEditSpec *RichEditSpec8;
	TSpeedButton *SpeedButton5;
	TPanel *Panel34;
	TLabel *Label25;
	TRichEditSpec *RichEditSpec16;
	TPanel *Panel35;
	TLabel *Label26;
	TLabel *Label69;
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TPanel *Panel38;
	TLabel *Label28;
	TPanel *Panel31;
	TLabel *Label130;
	TPanel *Panel32;
	TLabel *Label131;
	TRichEditSpec *RichEditSpec13;
	TPanel *Panel30;
	TLabel *Label10;
	TRichEditSpec *RichEditSpec11;
	TPanel *Panel33;
	TLabel *Label132;
	TRichEditSpec *RichEditSpec14;
	TPanel *Panel29;
	TLabel *Label23;
	TPanel *Panel28;
	TLabel *Label24;
	TRichEditSpec *RichEditSpec15;
	TPanel *Panel36;
	TLabel *Label27;
	TRichEditSpec *RichEditSpec20;
	TPanel *Panel37;
	TLabel *Label29;
	TPanel *Panel39;
	TLabel *Label30;
	TRichEditSpec *RichEditSpec22;
	TPanel *Panel40;
	TLabel *Label133;
	TPanel *Panel41;
	TLabel *Label134;
	TPanel *Panel50;
	TLabel *Label33;
	TRichEditSpec *RichEditSpec33;
	TPanel *Panel51;
	TLabel *Label34;
	TRichEditSpec *RichEditSpec34;
	TPanel *Panel52;
	TLabel *Label35;
	TPanel *Panel53;
	TLabel *Label36;
	TRichEditSpec *RichEditSpec36;
	TPanel *Panel54;
	TLabel *Label37;
	TRichEditSpec *RichEditSpec37;
	TPanel *Panel56;
	TLabel *Label39;
	TRichEditSpec *RichEditSpec39;
	TPanel *Panel3;
	TLabel *Label40;
	TRichEditSpec *RichEditSpec40;
	TPanel *Panel4;
	TLabel *Label41;
	TRichEditSpec *RichEditSpec41;
	TPanel *Panel5;
	TLabel *Label42;
	TRichEditSpec *RichEditSpec42;
	TPanel *Panel6;
	TLabel *Label43;
	TRichEditSpec *RichEditSpec43;
	TPanel *Panel55;
	TLabel *Label38;
	TRichEditSpec *RichEditSpec38;
	TOpenDialog *OpenDialog1;
	TSpeedButton *SpeedButton7;
	TComboBoxSpec *ComboBoxSpec3;
	TComboBoxSpec *ComboBoxSpec4;
	TComboBoxSpec *ComboBoxSpec5;
	TSpeedButton *SpeedButton8;
	TComboBoxSpec *ComboBoxSpec6;
	TComboBoxSpec *ComboBoxSpec7;
	TComboBoxSpec *ComboBoxSpec8;
	TComboBoxSpec *ComboBoxSpec9;
	TRichEditSpec *RichEditSpec10;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TPanel *Panel58;
	TLabel *Label46;
	TPanel *Panel59;
	TLabel *Label47;
	TPanel *Panel60;
	TLabel *Label48;
	TPanel *Panel61;
	TLabel *Label49;
	TPanel *Panel63;
	TLabel *Label51;
	TPanel *Panel64;
	TLabel *Label135;
	TRichEditSpec *RichEditSpec46;
	TComboBoxSpec *ComboBoxSpec10;
	TComboBoxSpec *ComboBoxSpec11;
	TComboBoxSpec *ComboBoxSpec12;
	TComboBoxSpec *ComboBoxSpec13;
	TRichEditSpec *RichEditSpec21;
	TComboBoxSpec *ComboBoxSpec14;
	TPanel *Panel65;
	TLabel *Label52;
	TComboBoxSpec *ComboBoxSpec15;
	TPanel *Panel66;
	TLabel *Label53;
	TRichEditSpec *RichEditSpec23;
	TPanel *Panel67;
	TLabel *Label54;
	TComboBoxSpec *ComboBoxSpec16;
	TRichEditSpec *RichEditSpec24;
	TPanel *Panel68;
	TLabel *Label55;
	TRichEditSpec *RichEditSpec35;
	TPanel *Panel70;
	TLabel *Label57;
	TPanel *Panel71;
	TLabel *Label58;
	TRichEditSpec *RichEditSpec48;
	TPanel *Panel72;
	TLabel *Label59;
	TRichEditSpec *RichEditSpec49;
	TPanel *Panel73;
	TLabel *Label60;
	TRichEditSpec *RichEditSpec50;
	TRichEditSpec *RichEditSpec51;
	TComboBoxSpec *ComboBoxSpec17;
	TSpeedButton *SpeedButton17;
	TPanel *Panel78;
	TLabel *Label65;
	TRichEditSpec *RichEditSpec55;
	TPanel *Panel79;
	TLabel *Label136;
	TPanel *Panel80;
	TLabel *Label137;
	TComboBoxSpec *ComboBoxSpec19;
	TComboBoxSpec *ComboBoxSpec20;
	TComboBoxSpec *ComboBoxSpec21;
	TPanel *Panel77;
	TLabel *Label64;
	TRichEditSpec *RichEditSpec54;
	TPanel *Panel76;
	TLabel *Label63;
	TRichEditSpec *RichEditSpec53;
	TPanel *Panel81;
	TLabel *Label66;
	TRichEditSpec *RichEditSpec56;
	TPanel *Panel82;
	TLabel *Label67;
	TRichEditSpec *RichEditSpec57;
	TPanel *Panel83;
	TLabel *Label68;
	TRichEditSpec *RichEditSpec58;
	TPanel *Panel84;
	TLabel *Label70;
	TRichEditSpec *RichEditSpec59;
	TPanel *Panel85;
	TLabel *Label71;
	TSpeedButton *SpeedButton20;
	TRichEditSpec *RichEditSpec60;
	TPanel *Panel86;
	TLabel *Label72;
	TSpeedButton *SpeedButton19;
	TRichEditSpec *RichEditSpec61;
	TPanel *Panel87;
	TLabel *Label73;
	TSpeedButton *SpeedButton18;
	TRichEditSpec *RichEditSpec62;
	TPanel *Panel88;
	TLabel *Label74;
	TRichEditSpec *RichEditSpec63;
	TComboBoxSpec *ComboBoxSpec24;
	TPanel *Panel89;
	TLabel *Label75;
	TComboBoxSpec *ComboBoxSpec23;
	TPanel *Panel90;
	TLabel *Label138;
	TComboBoxSpec *ComboBoxSpec22;
	TScrollBox *ScrollBox4;
	TGroupBox *GroupBox15;
	TPanel *Panel9;
	TLabel *Label77;
	TSpeedButton *SpeedButton22;
	TRichEditSpec *RichEditSpec65;
	TPanel *Panel91;
	TLabel *Label78;
	TSpeedButton *SpeedButton23;
	TRichEditSpec *RichEditSpec66;
	TPanel *Panel92;
	TLabel *Label79;
	TSpeedButton *SpeedButton24;
	TRichEditSpec *RichEditSpec67;
	TTabSheet *TabSheet6;
	TScrollBox *ScrollBox3;
	TGroupBox *GroupBox12;
	TGroupBox *GroupBox13;
	TGroupBox *GroupBox14;
	TPanel *Panel10;
	TLabel *Label80;
	TSpeedButton *SpeedButton25;
	TRichEditSpec *RichEditSpec68;
	TPanel *Panel8;
	TLabel *Label76;
	TRichEditSpec *RichEditSpec64;
	TPanel *Panel93;
	TLabel *Label81;
	TSpeedButton *SpeedButton26;
	TRichEditSpec *RichEditSpec69;
	TPanel *Panel94;
	TLabel *Label82;
	TSpeedButton *SpeedButton27;
	TRichEditSpec *RichEditSpec70;
	TPanel *Panel95;
	TSpeedButton *SpeedButton28;
	TRichEditSpec *RichEditSpec71;
	TPanel *Panel126;
	TSpeedButton *SpeedButton55;
	TRichEditSpec *RichEditSpec102;
	TPanel *Panel13;
	TRichEditSpec *RichEditSpec103;
	TRichEditSpec *RichEditSpec104;
	TLabel *Label118;
	TLabel *Label119;
	TLabel *Label120;
	TPanel *Panel127;
	TLabel *Label106;
	TRichEditSpec *RichEditSpec106;
	TPanel *Panel128;
	TLabel *Label108;
	TLabel *Label109;
	TRichEditSpec *RichEditSpec109;
	TPanel *Panel129;
	TLabel *Label115;
	TLabel *Label116;
	TPanel *Panel132;
	TLabel *Label121;
	TRichEditSpec *RichEditSpec112;
	TPanel *Panel133;
	TLabel *Label122;
	TRichEditSpec *RichEditSpec113;
	TPanel *Panel131;
	TLabel *Label117;
	TSpeedButton *SpeedButton57;
	TRichEditSpec *RichEditSpec111;
	TPanel *Panel130;
	TLabel *Label107;
	TSpeedButton *SpeedButton56;
	TRichEditSpec *RichEditSpec110;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TImageList *ImageList1;
	TLabel *Label50;
	TLabel *Label61;
	TLabel *Label62;
	TComboBoxSpec *ComboBoxSpec27;
	TComboBoxSpec *ComboBoxSpec28;
	TSpeedButton *SpeedButton60;
	TComboBoxSpec *ComboBoxSpec25;
	TSpeedButton *SpeedButton61;
	TSpeedButton *SpeedButton62;
	TComboBoxSpec *ComboBoxSpec26;
	TLabel *Label123;
	TComboBoxSpec *ComboBoxSpec29;
	TRichEditSpec *RichEditSpec108;
	TEditSpec *EditSpec2;
	TPanel *Panel14;
	TLabel *Label124;
	TSpeedButton *SpeedButton63;
	TRichEditSpec *RichEditSpec1;
	THelpListBox *lb;
	TPopupMenu *PopupMenu1;
	TGroupBox *GroupBox16;
	TPanel *Panel20;
	TLabel *Label8;
	TComboBoxSpec *ComboBoxSpec2;
	TEditSpec *EditSpec6;
	TPanel *Panel21;
	TLabel *Label9;
	TDateTimePickerSpec *DateTimePickerSpec3;
	TPanel *Panel23;
	TLabel *Label128;
	TSpeedButton *SpeedButton2;
	TRichEditSpec *RichEditSpec3;
	TPanel *Panel27;
	TLabel *Label13;
	TSpeedButton *SpeedButton3;
	TRichEditSpec *RichEditSpec6;
	TPanel *Panel22;
	TLabel *Label15;
	TSpeedButton *SpeedButton4;
	TRichEditSpec *RichEditSpec9;
	TTimer *Timer1;
	TMenuItem *N1;
	TPanel *Panel57;
	TLabel *Label45;
	TSpeedButton *SpeedButton16;
	TRichEditSpec *RichEditSpec19;
	TPanel *Panel7;
	TLabel *Label44;
	TSpeedButton *SpeedButton15;
	TRichEditSpec *RichEditSpec12;
	TScrollBox *ScrollBox5;
	TPanel *Panel119;
	TLabel *Label141;
	TSpeedButton *SpeedButton43;
	TRichEditSpec *RichEditSpec89;
	TPanel *Panel118;
	TLabel *Label104;
	TSpeedButton *SpeedButton44;
	TRichEditSpec *RichEditSpec90;
	TPanel *Panel117;
	TLabel *Label103;
	TSpeedButton *SpeedButton45;
	TRichEditSpec *RichEditSpec91;
	TPanel *Panel116;
	TLabel *Label102;
	TSpeedButton *SpeedButton46;
	TRichEditSpec *RichEditSpec92;
	TPanel *Panel115;
	TLabel *Label101;
	TSpeedButton *SpeedButton47;
	TRichEditSpec *RichEditSpec93;
	TPanel *Panel114;
	TLabel *Label100;
	TSpeedButton *SpeedButton48;
	TRichEditSpec *RichEditSpec94;
	TPanel *Panel125;
	TLabel *Label114;
	TSpeedButton *SpeedButton49;
	TRichEditSpec *RichEditSpec95;
	TPanel *Panel124;
	TLabel *Label113;
	TSpeedButton *SpeedButton50;
	TRichEditSpec *RichEditSpec96;
	TPanel *Panel123;
	TLabel *Label112;
	TSpeedButton *SpeedButton51;
	TRichEditSpec *RichEditSpec97;
	TPanel *Panel122;
	TLabel *Label111;
	TSpeedButton *SpeedButton52;
	TRichEditSpec *RichEditSpec98;
	TPanel *Panel121;
	TLabel *Label110;
	TSpeedButton *SpeedButton53;
	TRichEditSpec *RichEditSpec99;
	TPanel *Panel120;
	TLabel *Label105;
	TSpeedButton *SpeedButton54;
	TRichEditSpec *RichEditSpec100;
	TPanel *Panel12;
	TLabel *Label99;
	TRichEditSpec *RichEditSpec101;
	TGroupBox *GroupBox17;
	TPanel *Panel62;
	TLabel *Label126;
	TComboBoxSpec *ComboBoxSpec31;
	TPanel *Panel74;
	TLabel *Label125;
	TComboBoxSpec *ComboBoxSpec30;
	TPanel *Panel75;
	TLabel *Label3;
	TSpeedButton *SpeedButton6;
	TRichEditSpec *RichEditSpec17;
	TGroupBox *GroupBox18;
	TPanel *Panel134;
	TLabel *Label127;
	TComboBoxSpec *ComboBoxSpec32;
	TLabel *Label129;
	TComboBoxSpec *ComboBoxSpec33;
	TPanel *Panel135;
	TLabel *Label142;
	TRichEditSpec *RichEditSpec18;
	TPanel *Panel136;
	TLabel *Label143;
	TRichEditSpec *RichEditSpec25;
	TSpeedButton *SpeedButton64;
	TSpeedButton *SpeedButton65;
	TLabel *Label144;
	TScrollBox *ScrollBox6;
	TGroupBox *GroupBox11;
	TPanel *Panel11;
	TLabel *Label88;
	TSpeedButton *SpeedButton59;
	TRichEditSpec *RichEditSpec47;
	TPanel *Panel102;
	TLabel *Label89;
	TSpeedButton *SpeedButton32;
	TRichEditSpec *RichEditSpec77;
	TPanel *Panel113;
	TLabel *Label140;
	TRichEditSpec *RichEditSpec88;
	TPanel *Panel112;
	TLabel *Label98;
	TSpeedButton *SpeedButton42;
	TRichEditSpec *RichEditSpec87;
	TPanel *Panel111;
	TLabel *Label97;
	TSpeedButton *SpeedButton41;
	TRichEditSpec *RichEditSpec86;
	TPanel *Panel110;
	TLabel *Label96;
	TSpeedButton *SpeedButton40;
	TRichEditSpec *RichEditSpec85;
	TPanel *Panel109;
	TLabel *Label95;
	TSpeedButton *SpeedButton39;
	TRichEditSpec *RichEditSpec84;
	TPanel *Panel108;
	TLabel *Label94;
	TSpeedButton *SpeedButton38;
	TRichEditSpec *RichEditSpec83;
	TPanel *Panel103;
	TLabel *Label90;
	TSpeedButton *SpeedButton33;
	TRichEditSpec *RichEditSpec78;
	TPanel *Panel104;
	TLabel *Label91;
	TSpeedButton *SpeedButton34;
	TRichEditSpec *RichEditSpec79;
	TPanel *Panel105;
	TLabel *Label92;
	TSpeedButton *SpeedButton35;
	TRichEditSpec *RichEditSpec80;
	TPanel *Panel106;
	TLabel *Label93;
	TSpeedButton *SpeedButton36;
	TRichEditSpec *RichEditSpec81;
	TPanel *Panel101;
	TLabel *Label87;
	TSpeedButton *SpeedButton58;
	TRichEditSpec *RichEditSpec44;
	TPanel *Panel107;
	TLabel *Label139;
	TSpeedButton *SpeedButton37;
	TRichEditSpec *RichEditSpec82;
	TScrollBox *ScrollBox7;
	TPanel *Panel100;
	TSpeedButton *SpeedButton31;
	TRichEditSpec *RichEditSpec76;
	TPanel *Panel99;
	TLabel *Label86;
	TSpeedButton *SpeedButton30;
	TRichEditSpec *RichEditSpec75;
	TPanel *Panel98;
	TLabel *Label85;
	TSpeedButton *SpeedButton29;
	TRichEditSpec *RichEditSpec74;
	TPanel *Panel96;
	TLabel *Label83;
	TSpeedButton *SpeedButton21;
	TRichEditSpec *RichEditSpec72;
	TPanel *Panel97;
	TLabel *Label84;
	TRichEditSpec *RichEditSpec73;
	TMainMenu *MainMenu1;
	TPanel *Panel42;
	TLabel *Label17;
	TEditSpec *EditSpec3;
	TPanel *Panel43;
	TLabel *Label18;
	TRichEditSpec *RichEditSpec26;
	TPanel *Panel47;
	TLabel *Label22;
	TRichEditSpec *RichEditSpec30;
	TPanel *Panel46;
	TLabel *Label21;
	TRichEditSpec *RichEditSpec29;
	TPanel *Panel45;
	TLabel *Label20;
	TRichEditSpec *RichEditSpec28;
	TPanel *Panel49;
	TLabel *Label32;
	TRichEditSpec *RichEditSpec32;
	TPanel *Panel48;
	TLabel *Label31;
	TRichEditSpec *RichEditSpec31;
	TPanel *Panel44;
	TLabel *Label19;
	TRichEditSpec *RichEditSpec27;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TLabel *Label56;
	TComboBoxSpec *ComboBoxSpec18;
	TRichEditSpec *RichEditSpec45;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *Excel1;
	TPopupMenu *PopupMenu2;
	TMenuItem *N7;
	TMenuItem *Ctrl1;
	TMenuItem *N8;
	TCoolBar *CoolBar1;
	TToolBar *ToolBar2;
	TLabel *Label146;
	TComboBox *AppointBox;
	TToolBar *ToolBar3;
	TLabel *Label145;
	TComboBox *ComboBox1;
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift,
		  TPoint &MousePos, bool &Handled);
	void __fastcall MemoAutoHeight(TObject *Sender);
	void __fastcall RichEditAutoHeight(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall RichEditSpecAfterSetItemID(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall ButtonClickGetChildren(TObject *Sender);
	void __fastcall DateTimePickerSpecSetFormat(TObject *Sender);
	void __fastcall DateTimePickerSpecKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall ButtonClickGetFather(TObject *Sender);
	void __fastcall ButtonClickGetMother(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton16Click(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton19Click(TObject *Sender);
	void __fastcall SpeedButton20Click(TObject *Sender);
	void __fastcall SpeedButton24Click(TObject *Sender);
	void __fastcall SpeedButton23Click(TObject *Sender);
	void __fastcall SpeedButton22Click(TObject *Sender);
	void __fastcall SpeedButton28Click(TObject *Sender);
	void __fastcall SpeedButton27Click(TObject *Sender);
	void __fastcall SpeedButton26Click(TObject *Sender);
	void __fastcall SpeedButton25Click(TObject *Sender);
	void __fastcall SpeedButton32Click(TObject *Sender);
	void __fastcall SpeedButton37Click(TObject *Sender);
	void __fastcall SpeedButton36Click(TObject *Sender);
	void __fastcall SpeedButton35Click(TObject *Sender);
	void __fastcall SpeedButton34Click(TObject *Sender);
	void __fastcall SpeedButton33Click(TObject *Sender);
	void __fastcall SpeedButton38Click(TObject *Sender);
	void __fastcall SpeedButton39Click(TObject *Sender);
	void __fastcall SpeedButton40Click(TObject *Sender);
	void __fastcall SpeedButton41Click(TObject *Sender);
	void __fastcall SpeedButton42Click(TObject *Sender);
	void __fastcall SpeedButton43Click(TObject *Sender);
	void __fastcall SpeedButton44Click(TObject *Sender);
	void __fastcall SpeedButton45Click(TObject *Sender);
	void __fastcall SpeedButton46Click(TObject *Sender);
	void __fastcall SpeedButton47Click(TObject *Sender);
	void __fastcall SpeedButton48Click(TObject *Sender);
	void __fastcall SpeedButton49Click(TObject *Sender);
	void __fastcall SpeedButton50Click(TObject *Sender);
	void __fastcall SpeedButton51Click(TObject *Sender);
	void __fastcall SpeedButton52Click(TObject *Sender);
	void __fastcall SpeedButton53Click(TObject *Sender);
	void __fastcall SpeedButton54Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ComboBoxSpecAfterSetItemID(TObject *Sender);
	void __fastcall ComboBoxSpecSelect(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SpeedButton58Click(TObject *Sender);
	void __fastcall SpeedButton59Click(TObject *Sender);
	void __fastcall SpeedButton60Click(TObject *Sender);
	void __fastcall SpeedButton61Click(TObject *Sender);
	void __fastcall SpeedButton62Click(TObject *Sender);
	void __fastcall SpeedButton55Click(TObject *Sender);
	void __fastcall SpeedButton56Click(TObject *Sender);
	void __fastcall SpeedButton57Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ComboBoxSpecMouseWheelUp(TObject *Sender, TShiftState Shift,
          const TPoint &MousePos, bool &Handled);
	void __fastcall ComboBoxSpecMouseWheelDown(TObject *Sender, TShiftState Shift,
          const TPoint &MousePos, bool &Handled);
	void __fastcall EditSpec1Change(TObject *Sender);
	void __fastcall RichEditSpecExit(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

	void __fastcall RichEditChanged(TObject *Sender);
	void __fastcall EditChanged(TObject *Sender);
	void __fastcall ComboBoxChanged(TObject *Sender);
	void __fastcall DateTimePickerChanged(TObject *Sender);

	void __fastcall RichEditModify(TObject *Sender);
	void __fastcall RichEditSpec7KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall RichEditSpecKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall ComponentMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
	void __fastcall lbMouseEnter(TObject *Sender);
	void __fastcall lbMouseLeave(TObject *Sender);
	void __fastcall lbClick(TObject *Sender);
	void __fastcall RichEditSpecKeyPress(TObject *Sender, char &Key);
	void __fastcall lbDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall lbDrawTreeItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall SpeedButton31Click(TObject *Sender);
	void __fastcall SpeedButton30Click(TObject *Sender);
	void __fastcall SpeedButton29Click(TObject *Sender);
	void __fastcall SpeedButton21Click(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall RichEditSpecKeyUp(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall OnPopupGetFieldNameClick(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton64Click(TObject *Sender);
	void __fastcall SpeedButton65Click(TObject *Sender);
	void __fastcall AppointBoxSelect(TObject *Sender);
	void __fastcall RichEditSpecFontChange(TObject *Sender);
	void __fastcall lbFontChange(TObject *Sender);
	void __fastcall ScrollBoxMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
private:	// User declarations
protected:
	void __fastcall WndProc(Messages::TMessage &Message);
/*
		void __fastcall WMCommand(TWMCommand &msg);
		BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_COMMAND, TWMCommand, WMCommand)
		END_MESSAGE_MAP(TForm);
*/
	/*void __fastcall WMCommand(TWMCommand &msg);
	BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(WM_EXITSIZEMOVE, TWMCommand, WMCommand)
	END_MESSAGE_MAP(TForm);	*/
public:		// User declarations
    int CrtlPress;

	TProtocol *prot;
	TBaseEmptyList *lbList;
	TBaseEmptyList *lbListExt;
//	TChildren *child;

	//Timer HighLight
	int Tick;
	ISpecField* hlObj;

	__fastcall TProtocolForm(TComponent* Owner);
	TComboBoxSpec* GetSpecComboBox(String FieldName);
	void ClearSpecComponent();
	int GetProtocol(TProtocol *p);
	TEditSpec* GetSpecEdit(String FieldName);
	TRichEditSpec* GetSpecRichEdit(String FieldName);
	TDateTimePickerSpec* GetSpecTimePicker(String FieldName);
	TDateTime ToDate(String d);
	void FillAllBox();
	void FillSpecBox(TComboBoxSpec *box);
	void __fastcall GroupBoxAutoHeight(TObject *Sender);


	int FieldExists(ISpecField *spec);
	int SaveStringField(ISpecField *spec);
	int SaveNumberField(ISpecField *spec);
	int SaveDateField(ISpecField *spec);
	int SaveRefBoxField(ISpecField *spec);
	int SaveRefListField(ISpecField *spec);
	int SaveMother();
	int SaveFather();
	int SaveChildren();
	int SaveSpecComponent(ISpecField *spec);
	int SaveAllSpecComponents();
	void SetTextForSpec(TRichEditSpec *res);

	int ShowDlg(String MsgCaption, String MsgText);
	String __fastcall GetMonth(int num);
	String __fastcall FIO_DatPadej(String fio);
	void SetMonitorModify(int Value);
	String CheckModify();
	void SetAllSpecModify(int Value);

	void __fastcall DateTimePickerModify(TObject *Sender);
	void __fastcall ComboBoxModify(TObject *Sender);
	void __fastcall EditModify(TObject *Sender);

	void __fastcall lbChange(TRichEditSpec *re, String ss, int ListID);
	void __fastcall FillHelpBaseList(THelpListBox *hlb, TBaseEmptyList* list, String ss, int MaxCount);
	void __fastcall FillHelpTreeBaseList(THelpListBox *hlb, TTreeBaseEmptyList* list, String ss, int MaxCount);
	int GetTop(String ToClassName, TControl *Ctrl);
	int GetLeft(String ToClassName, TControl *Crtl);

	int MouseOver_lb;

	int CheckForNewItem(ISpecField *spec);

	void SaveINI();
	void LoadINI();

	void __fastcall FillChild(TChildren* Item);
	void __fastcall FillFather(TParent* Item);
	void __fastcall FillMother(TParent* Item);

	void __fastcall DisplayErrorValue(TObject *Sender);
	void __fastcall HighLight(ISpecField *Obj);
	
	int __fastcall Save();
	int GetLeft(TObject* ParentObj, TControl *Crtl);
	int GetTop(TObject* ParentObj, TControl *Crtl);

	void __fastcall FillAnchors();
	String __fastcall GetLastWord(String str);

	void __fastcall ShowGroupDataForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork);
	void __fastcall ShowDiagnosisForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork);
	void __fastcall ShowRecommendForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork);
	void __fastcall ShowOrganizationsForm(TRichEditSpec* RichEditDest, TRichEditSpec** RichEditWork);
	
	ISpecField* __fastcall GetSpecField(TObject *Sender);
	void __fastcall TProtocolForm::SetAllSpecContextPopup();
	void __fastcall SpecContextPopup(TObject *Sender, TPoint &MousePos,
		  bool &Handled);

	void __fastcall FillAppointBox();
	void __fastcall SetAppoint(int ID);
	void __fastcall SetEnableSpec(int AppointID);
	void __fastcall SetEnableControl(TControl* VControl);
	int __fastcall CheckModifyWithDialog(String text, String caption);
	TCloseAction __fastcall OnFormClose();

//	void FillSpecOnFontChange();
	void __fastcall ChangeFont(TFont *f);
};
//---------------------------------------------------------------------------
extern PACKAGE TProtocolForm *ProtocolForm;
//---------------------------------------------------------------------------
#endif
