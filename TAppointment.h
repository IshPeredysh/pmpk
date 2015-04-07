//---------------------------------------------------------------------------

#ifndef TAppointmentH
#define TAppointmentH
#include "TBaseEmpty.h"

class TAppointment: public TBaseEmpty
{
	private:
		int FActive;
	public:
		__property int Active={read=FActive};
};
//---------------------------------------------------------------------------
#endif
