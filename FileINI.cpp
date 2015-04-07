//---------------------------------------------------------------------------


#pragma hdrstop

#include "FileINI.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TIniFile* GetFileINI(String ApplicationPath)
{
	TIniFile *file = new TIniFile(ApplicationPath + "config.ini");

	return file;
}
