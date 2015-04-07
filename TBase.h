//---------------------------------------------------------------------------

#ifndef TBaseH
#define TBaseH
#include <Classes.hpp>
#include <ADODB.hpp>

//---------------------------------------------------------------------------

Variant IfNull(int Value);

//typedef void (TChangeDescr)(String Value);

class TBase
{
	protected:
		int FID;
		String FCode;
		String FDescr;
		String FIsMark;
		int FVerStamp;
		int FModified;

		//BackUpFields;
		String BDescr;
//		TChangeDescr *FChangeDescr;
//		int FIsTree;

		String GetID();
		int GetCode();
		String GetDescr();
		String GetIsMark();
		String GetVerStamp();
		int GetModified();
		void SetBaseUpdateParamDB(TADOQuery *q);
		void SetDescr(String Value);
		virtual int SetThisUpdateParams(TADOQuery *q) = 0;
	public:
		void SetBackUp();
		void BackUp();
    	int GetMaxID(TADOQuery *q);
		void* Clone;
		void* PParent;
		int IsDeleted;
		void GetFromDB(TADOQuery *q);
		int SetUpdateParams(TADOQuery *q);
		TBase(int MaxID); //Null
		TBase(TBase *Template); //Copy
		TBase(TADOQuery *q); //From DB
		void Save(TADOQuery *qMax, TADOQuery *qInsert, TADOQuery *qUpdate, TADOQuery *qDelete);
		int RemoveFromDB(TADOQuery *q);
		int InsertDB(TADOQuery *q);
		int UpdateDB(TADOQuery *q);
		__property int ID = {read=FID};
		__property String Descr = {read=FDescr, write=SetDescr};
		__property String IsMark = {read=FIsMark};
//		__property int IsTree; = {read=FIsTree};
};

#endif
