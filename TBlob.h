//---------------------------------------------------------------------------

#ifndef TBlobH
#define TBlobH
#include "DMUnit.h"
//---------------------------------------------------------------------------

class TBlob
{
	private:
		String FFieldID;
		String FObjID;
		//int FBlockNo;
		//String FBlock;
		int FModified;
		TStringList *FList;
		AnsiString GetText();
		void SetText(AnsiString Value) {FList->Text = Value;};
	public:
		void SetModified();
		TBlob(String FieldID, String ObjID);
		~TBlob();
		void UpdateDB(TStrings* list);
		void UpdateDB(AnsiString Text);
		void UpdateBase();
		__property TStringList* List = {read=FList};
		__property AnsiString Text = {read=GetText, write=SetText};
};

#endif
