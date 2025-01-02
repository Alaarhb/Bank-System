#pragma once
#include "clsCurrencyObject.h"
#include "clsScreen.h"
#include <iomanip>

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrencyObject Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowCurrenciesList()
	{
		vector<clsCurrencyObject> vCurrency = clsCurrencyObject::GetCurrenciesList();
		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/1$";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (!vCurrency.size())
			cout << "\t\t\t\tNo Currencies Available In This System!";
		else
		{
			for (clsCurrencyObject C : vCurrency)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}
};

