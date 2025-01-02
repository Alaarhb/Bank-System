#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"


class clsCurrencyObject
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrencyObject _ConvertLineToCurrencyObject(string Line, string Seprator = "#//#")
	{
		vector<string> vCurrencytData;

		vCurrencytData = clsString::SplitString(Line, Seprator);

		return clsCurrencyObject(enMode::UpdateMode, vCurrencytData[0], vCurrencytData[1], vCurrencytData[2],
			 stod(vCurrencytData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrencyObject Currency, string Seprator = "#//#")
	{
		string stCurrencyData = "";
		stCurrencyData += Currency.Country() + Seprator;
		stCurrencyData += Currency.CurrencyCode() + Seprator;
		stCurrencyData += Currency.CurrencyName() + Seprator;
		stCurrencyData += to_string(Currency.Rate());

		return stCurrencyData;
	}

	static vector<clsCurrencyObject> _LoadDataFromFile()
	{
		fstream MyFile;
		vector<clsCurrencyObject> vCurrency;

		MyFile.open("Currencies.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrencyObject Currency = _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrency;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrencyObject>& vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string stDataLine;

		if (MyFile.is_open())
		{
			for (clsCurrencyObject C : vCurrency)
			{
				stDataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << stDataLine << endl;
			}

			MyFile.close();
		}
	}

    void _Update()
	{
		vector<clsCurrencyObject> vCurrency = _LoadDataFromFile();

		for (clsCurrencyObject& C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrency);
	}

	static clsCurrencyObject _GetEmptyCurrencyObject()
	{
		return clsCurrencyObject(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrencyObject(enMode Mode, string Country, string CountryCode, string CountryName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CountryCode;
		_CurrencyName = CountryName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrencyObject FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrencyObject Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}
		
		return _GetEmptyCurrencyObject();
	}

	static clsCurrencyObject FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrencyObject Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrencyObject C1 = clsCurrencyObject::FindByCode(CurrencyCode);

		return (!C1.IsEmpty());
	}

	static vector <clsCurrencyObject> GetCurrenciesList()
	{
		return _LoadDataFromFile();
	}

    float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float USDAmount, clsCurrencyObject CurrencyTo)
	{
		return USDAmount * CurrencyTo.Rate();
	}
};

