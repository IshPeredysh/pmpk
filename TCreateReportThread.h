//$$---- Thread HDR ----
//---------------------------------------------------------------------------

#ifndef TCreateReportThreadH
#define TCreateReportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TCreateReportThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TCreateReportThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
