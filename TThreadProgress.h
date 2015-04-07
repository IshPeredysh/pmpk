//$$---- Thread HDR ----
//---------------------------------------------------------------------------

#ifndef TThreadProgressH
#define TThreadProgressH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <SyncObjs.hpp>

typedef int (__fastcall *TProgressFunc)();
typedef void (__fastcall *TRefreshFunc)();

//---------------------------------------------------------------------------
class TThreadProgress : public TThread
{
private:

protected:
	void __fastcall Execute();
public:
	TRefreshFunc RefreshFunc;
	TProgressFunc Func;
	String MessageText;
	void __fastcall RefreshFuncT();
	__fastcall TThreadProgress(bool CreateSuspended);
	void __fastcall ShowMessageT();
};
//---------------------------------------------------------------------------
#endif
