//---------------------------------------------------------------------------

#ifndef TParentH
#define TParentH
#include "TBase.h"
//---------------------------------------------------------------------------

class TParent: public TBase
{
	private:
		int FAge; //int SP85; //Age
		int FEducation; //String SP86; //Education
		int FBadHabit; //String SP88; //BadHabit
		int FBadStrain; //String SP89; //BadStrain
		String FWork;   //NewField
		void SetEducation(int Value);
		void SetBadHabit(int Value);
		void SetBadStrain(int Value);
		void SetWork(String Value);
		int SetThisUpdateParams(TADOQuery *q);
		String GetEducation();
		void SetAge(int Value);

		int BAge;
		int BEducation; 
		int BBadHabit;
		int BBadStrain; 
		String BWork;
		
	protected:

	public:
		TParent(int MaxID);
		TParent(TADOQuery *q);
		TParent(TParent *Template);
		int DeleteFromDB();
		void SetBackUp();
		void BackUp();
		__property int Age = {read=FAge, write=SetAge};
		__property int Education = {read=FEducation, write=SetEducation};
		__property int BadHabit = {read=FBadHabit, write=SetBadHabit};
		__property int BadStrain = {read=FBadStrain, write=SetBadStrain};
		__property String Work = {read=FWork, write=SetWork};
};
#endif
