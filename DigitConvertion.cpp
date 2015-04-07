//---------------------------------------------------------------------------


#pragma hdrstop

#include "DigitConvertion.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

AnsiString DigitToCharBySize(int num, int size)
{
	String str;
	int i;

	str = IntToStr(num);
	i = str.Length();

	while (i < size)
	{
		str = " " + str;
		i++;
    }
		
	return str;
}


AnsiString DigitToChar(int num)
{
	int ost, kolSpace;
	AnsiString result;

	do
	{
		ost = num % 36;
		num= num / 36;
		if (ost >= 0 && ost <= 9)
			result = String((char)(ost + '0')) + result;

		if (ost >= 10 && ost <= 36)
			result = String((char)(ost - 10 + 'A')) + result;
	}
	while (num != 0);

	kolSpace = 6 - result.Length();
	while (kolSpace > 0)
	{
		result = " " + result;
		kolSpace--;
	}

	kolSpace = 3;
	while (kolSpace > 0)
	{
		result += " ";
		kolSpace--;
	}

	return result;
}

int StrToDigit(AnsiString str)
{
	int num, i, r;
	char s[9];

	str.Trim();
	num = 0;
	i = str.Length();
	r = 1;

	while (i > 0)
	{
		if (str[i] >= '0' && str[i] <= '9')	{
			num += (str[i] - '0') * r;
			r = r * 36;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')	{
			num += (str[i] - 'A' + 10) * r;
			r = r * 36;
		}
		i--;
	}
	return num;
}

int CharToDigit(AnsiString st)
{
	int num, i, r;
	char s[9];
	String str = st.Trim();


	num = 0;
	i = str.Length();
	r = 1;

	while (i > 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num += (str[i] - '0') * r;
		if (str[i] >= 'A' && str[i] <= 'Z')
			num += (str[i] - 'A' + 10) * r;
		r = r * 36;
		i--;
	}
	return num;
}

//----------------

int StrHexToInt(char Value[9])
{
	int num, i, r;

	num = 0;
	i = 0;
	r = 1;

	while (Value[i] != '\0')
		i++;
	i--;

	while (i >= 0)
	{
		if (Value[i] == ' ')	{
			i--;
			continue;
		}
		if (Value[i] >= '0' && Value[i] <= '9')
			num += (Value[i] - '0') * r;
		if (Value[i] >= 'a' && Value[i] <= 'f')
			num += (Value[i] - 'a' + 10) * r;
		if (Value[i] >= 'A' && Value[i] <= 'F')
			num += (Value[i] - 'A' + 10) * r;
		r = r * 16;
		i--;
	}
	return num;
}

String IntToStrHex(int digit)
{
	const kol = 9;
	int ost, i, j, k;
	int d = digit;  //digit
	char c[kol], r[kol + 1];
	String str;

	i = 0;
	for (i = 0; i < kol && d > 0; i++) {
		ost = d % 16;
		d = d / 16;
		if (ost >= 0 && ost <= 9)
			c[i] = ost + '0';
		else
			c[i]  = ost - 10 + 'a';
	}

	if (d > 0) //Îøèáêà!
		return "";

	j = 0;
	while (i > 0) {
		r[j++] = c[--i];
	}

	while (j < kol)
		r[j++] = ' ';
	r[j] = '\0';

	str.printf(r);

	return str;
}


AnsiString GetBlock(AnsiString Value)
{
	AnsiString s;
	s = Value.SubString(1, 9);
	return Value.SubString(10, StrHexToInt(s.c_str()));
}
