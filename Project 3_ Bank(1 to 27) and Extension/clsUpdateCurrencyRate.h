#pragma once
#include "clsCurrencyObject.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsUpdateCurrencyRate : protected clsScreen
{
private:

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

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t  Update Currency Rate Screen");

		cout << "\nPlease Enter Currency Code ? ";
		string CurrencyCode;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrencyObject::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency not found, choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrencyObject Currency = clsCurrencyObject::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you wnat to update the rate of this currency ? y/n ? ";
		char Answer = 'y';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate: ";
			cout << "\n____________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate updated successfully :)\n";
			_PrintCurrencyCard(Currency);
		}
	}
};

