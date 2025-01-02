#pragma once
#include <iostream>
#include "clsDate.h";

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Num, int From, int To)
	{
		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(float Num, float From, float To)
	{
		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From && Num <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		return (!clsDate::IsDate1BeforeDate2(Date, DateFrom) && !clsDate::IsDate1AfterDate2(Date, DateTo) ||
			(!clsDate::IsDate1BeforeDate2(Date, DateTo) && !clsDate::IsDate1AfterDate2(Date, DateFrom)));

	}

	static int ReadIntNumber(string Message = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}

		return Number;
	}

	static float ReadFloatNumber(string Message = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}

		return Number;
	}

	static double ReadDblNumber(string Message = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Message = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string Message = "Number is not within range, Enter again:\n")
	{
		short Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Message = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static string ReadString()
	{
		string S1 = "";

		getline(cin >> ws, S1);

		return S1;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidateDate(Date);
	}
};

