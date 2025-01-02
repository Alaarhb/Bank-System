#pragma once
#include "clsCurrencyObject.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsCurrencyCalcScreen : protected clsScreen
{
private: 

	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount To Exhange : ";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static clsCurrencyObject _GetCurrency(string Message)
	{
		cout << "\n" << Message;
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrencyObject::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency not found, choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrencyObject Currency = clsCurrencyObject::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrencyCard(clsCurrencyObject Currency, string Title = "Currency Card:")
	{
		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate/1$ = : " << Currency.Rate();
		cout << "\n_____________________________\n";
	}

	static void _PrintCalculationResult(float Amount, clsCurrencyObject CurrencyFrom, clsCurrencyObject CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From:");
		float USDAmount = CurrencyFrom.ConvertToUSD(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << USDAmount << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting Fron USD To: \n";
		_PrintCurrencyCard(CurrencyTo, "To:");

		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(USDAmount, CurrencyTo);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInCurrency2 << " " << CurrencyTo.CurrencyCode();

	}

public:

	static void ShowCurrencyCalc()
	{
		char Answer = 'y';

		while (toupper(Answer) == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrencyObject CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrencyObject CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Answer;
		}
	}

};

