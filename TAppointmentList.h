//---------------------------------------------------------------------------

#ifndef TAppointmentListH
#define TAppointmentListH

#include "TBaseEmptyList.h"
#include "TAppointment.h"


class TAppointmentList: public TBaseEmptyList
{
	private:
		TAppointment* GetItem(int i) {return (TAppointment*)FList->Items[i];};
	public:
		void AddFromDB(TADOQuery *q);
		__property TAppointment* Items[int i] = {read=GetItem};
};
//---------------------------------------------------------------------------
#endif
