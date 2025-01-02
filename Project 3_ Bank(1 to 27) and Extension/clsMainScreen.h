#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenu.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsShowRegisterLoginScreen.h"
#include "clsCurrenciesMainScreen.h"
#include "Global.h"
#include <iomanip>

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOption {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTranscationMenu = 6,
		eMangeUsers = 7, eRegisterLogin = 8,eCurrencyExhange = 9,  eExit = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 10 ] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter number between 1 to 10? ");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "\n\tPlease press any key to go back to main menu....";

		system("pause>0");
		_ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nClients List Screen Will Be Here.....\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		/*cout << "\nAdd New Client Screen Will Be Here.....\n";*/
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		/*cout << "\nDelete Client Screen Will Be Here.....\n";*/
		clsDeleteClientScreen::ShowDeletClientScreen();

	}

	static void _ShowUpdateClientScreen()
	{
		/*cout << "\nUpdate Client Screen Will Be Here.....\n";*/
		clsUpdateClientScreen::ShowUpdatClientScreen();

	}

	static void _ShowFindClientScreen()
	{
		/*cout << "\nFind Client Screen Will Be Here.....\n";*/
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		/*cout << "\nTransactions Menu Will be here...\n";*/
		clsTransactionMenu::ShowTransactionMenu();
	}

	static void _ShowManageUsersMenue()
	{
		/*cout << "\nUsers Menu Will be here...\n";*/
		clsManageUsersScreen::ShowMangeUsersMenu();

	}

	static void _ShowRegisterLoginScreen()
	{
		clsShowRegisterLoginScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExhangeScreen()
	{
		clsCurrenciesMainScreen::ShowCurrencyMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		// then it will go back to main function
	}

	static void _PerfromMainMenuOption(enMainMenuOption MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOption::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eShowTranscationMenu:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eMangeUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eRegisterLogin:
		{
			system("cls");
			_ShowRegisterLoginScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eCurrencyExhange:
		{
			system("cls");
			_ShowCurrencyExhangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

public:
	static void _ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Register Login.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenuOption((enMainMenuOption)_ReadMainMenuOption());
	}
};

