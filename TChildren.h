//---------------------------------------------------------------------------

#ifndef TChildrenH
#define TChildrenH
#include "TTreeBase.h"
#include <systdate.h>
#include "TBlob.h"
#include "TBaseEmptyList.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------

class TChildren: public TTreeBase
{
	private:
		TDateTime FBirthday; //SP41;//дата рождения
		int FPlaceStudy; //String SP43;//место обучения PlaceStudy
		int FFather; //String SP97;//отец
		int FMother; //String SP98;//мать
		int FArea; //String SP125;//район Area
		int SP133; //String SP133;//???
		int FSex;
		String FAdress;
		String FHistory;
		String FExtInfo;
		AnsiString GetAdress();
		AnsiString GetExtInfo();
		AnsiString GetFather();
		AnsiString GetMother();
		AnsiString GetHistory();
		AnsiString GetPlaceStudy();
		AnsiString GetArea();
		void SetBirthday(TDateTime Value);
		//void SetSP133(String Value);
		void SetAdress(String Value);
		void SetHistory(String Value);
		void SetExtInfo(String Value);
		void InitChildren();
	public:
		int DeleteFromDB();
		void SetModifiedAdress();
		void SetModifiedExtInfo();
		void SetModifiedHistory();
		void SetAreaID(int Value);
		void SetFatherID(int Value);
		void SetMotherID(int Value);
		void SetPlaceStudyID(int Value);
		void SetSexID(int Value);
		String GetSex();

//		TChildren();
		TChildren(TADOQuery *q);
		TChildren(TChildren *Template);
		TChildren(int VIsFolder, int VParentID, int MaxID);

		int LoadArea(TADOQuery *q);
		int SetThisUpdateParams(TADOQuery *q);

		__property AnsiString Adress = {read=GetAdress, write=SetAdress};
		__property AnsiString Area = {read=GetArea};
		__property int AreaID = {read=FArea, write=SetAreaID};
		__property AnsiString PlaceStudy = {read=GetPlaceStudy};
		__property int PlaceStudyID = {read=FPlaceStudy, write=SetPlaceStudyID};
		__property TDateTime Birthday = {read=FBirthday, write=SetBirthday};
		__property AnsiString ExtInfo = {read=GetExtInfo, write=SetExtInfo};
		__property AnsiString History = {read=GetHistory, write=SetHistory};
		__property AnsiString Father = {read=GetFather};
		__property int FatherID = {read=FFather, write=SetFatherID};
		__property AnsiString Mother = {read=GetMother};
		__property int MotherID = {read=FMother, write=SetMotherID};
		__property int SexID = {read=FSex, write=SetSexID};
		__property String Sex = {read=GetSex};
};
#endif
