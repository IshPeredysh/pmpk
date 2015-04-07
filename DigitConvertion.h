//---------------------------------------------------------------------------

#ifndef DigitConvertionH
#define DigitConvertionH
#include <Classes.hpp>
//---------------------------------------------------------------------------

extern AnsiString DigitToChar(int num);
extern AnsiString DigitToCharBySize(int num, int size);
extern int StrToDigit(AnsiString str);
extern int CharToDigit(AnsiString st);
extern int StrHexToInt(char Value[9]);
extern String IntToStrHex(int digit);

#endif
