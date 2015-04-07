//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef ImagesDMH
#define ImagesDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>


const int FOLDER_IMG = 0;
const int STRING_IMG = 1;
const int ARROWUP_IMG = 2;
const int ANCHOR_IMG = 3;


//const int NEWFOLDER_IMG = 0;
//const int NEWSTRING_IMG = 1;
//const int DELETE_IMG = 2;
//const int EDIT_IMG = 3;
//const int ANCHOR_IMG = 4;

//---------------------------------------------------------------------------
class TImages : public TDataModule
{
__published:	// IDE-managed Components
	TImageList *ImageList1;
	TImageList *ImageList2;
	TImageList *ImageList3;
	TImageList *ImageList4;
	TImageList *ImageList5;
	TImageList *ImageList6;
private:	// User declarations
public:		// User declarations
	__fastcall TImages(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TImages *Images;
//---------------------------------------------------------------------------
#endif
