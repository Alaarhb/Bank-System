#pragma once
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsCurrencyObject.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalcScreen.h"
#include <iomanip>

class clsCurrenciesMainScreen : protected clsScreen
{
private:

	enum enCurrencyMenuOption
	{ eListCurrency = 1, eFindCurrency= 2,
		eUpdateRate = 3, eCurrencyCalc = 4, eShowMainMenu= 5
	};

	static short _ReadCurrencyMenuOption()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 5 ] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrencyMenu()
	{
		cout << setw(37) << left << "\n\tPrees any key to go back to currency menu....";

		system("pause>0");
		ShowCurrencyMenu();
	}

	static void _ShowAllCurrenciesListScreen()
	{
		/*cout << "\nList currencies list screen will be here....\n";*/
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		/*cout << "\nFind currencies screen will be here....\n";*/
		clsFindCurrencyScreen::ShowFindCurrency();
	}

	static void _ShowUpdateRateScreen()
	{
		/*cout << "\nUpdate rate screen will be here....\n";*/
		clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculator()
	{
		/*cout << "\nCurrency Calculator screen will be here....\n";*/
		clsCurrencyCalcScreen::ShowCurrencyCalc();
	}

	static void _PerformCurrencyScreenOption(enCurrencyMenuOption CurrencyMenuOption)
	{
		switch (CurrencyMenuOption)
		{
		case enCurrencyMenuOption::eListCurrency:
		{
			system("cls");
			_ShowAllCurrenciesListScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenuOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenuOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenuOption::eCurrencyCalc:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenuOption::eShowMainMenu:
		{
			// do nothing here th main screen will handle it 
		}
		}
	}

public:

	static void ShowCurrencyMenu()
	{
		system("cls");
		_DrawScreenHeader("    Currancy Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyScreenOption((enCurrencyMenuOption)_ReadCurrencyMenuOption());
	}
};

