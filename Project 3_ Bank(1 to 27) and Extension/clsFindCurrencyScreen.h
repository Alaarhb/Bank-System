#pragma once
#include "clsCurrencyObject.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsFindCurrencyScreen : protected clsScreen
{
private :

	static void _PrintCurrencyCard(clsCurrencyObject Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate/1$ = : " << Currency.Rate();
		cout << "\n_____________________________\n";
	}

	static void _ShowResults(clsCurrencyObject Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :)\n";
			_PrintCurrencyCard(Currency);
		}
		else
			cout << "\nCurrency was not found :(\n";
	}

public:

	static void ShowFindCurrency()
	{
		_DrawScreenHeader("\t  Find Currency Screen ");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		cin >> Answer;

		if (Answer == 1)
		{
			cout << "\nPlease Enter Currency Code: ";
			string CurrencyCode;
			CurrencyCode = clsInputValidate::ReadString();

			clsCurrencyObject Currency = clsCurrencyObject::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else if (Answer == 2)
		{
			cout << "\nPlease Enter Country Name: ";
			string Country;
			Country = clsInputValidate::ReadString();

			clsCurrencyObject Currency = clsCurrencyObject::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}
};

