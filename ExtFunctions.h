//---------------------------------------------------------------------------

#ifndef ExtFunctionsH
#define ExtFunctionsH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "TTreeBaseList.h"
#include <System.hpp>
//---------------------------------------------------------------------------
extern void BoxItemByID(int ID, TComboBox* box);
extern void BoxItemByID(int ID, TListBox* box);
extern void BoxItemByTBase(TBase* Item, TComboBox* box);
extern void BoxItemByTBaseID(int ID, TComboBox* box);
extern void FillBox(int ID, TTreeBaseList *list, TComboBox *box);
extern void FillBox(int ID, TTreeBaseList *list, TListBox *box);
#endif
