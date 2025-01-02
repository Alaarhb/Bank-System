#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogScreen.h"
#include <iomanip>

class clsTransactionMenu : protected clsScreen
{
private:

	enum enTransactionMenuOption {
		eDeposite = 1, eWithDraw = 2,
		eTotalBalances = 3, eTransfer = 4,eTransferLog = 5, eShowMainMenu = 6
	};

	static short ReadTransactionMenuOption()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 6 ] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between 1 to 6 ? ");
		return Choice;
	}

	static void _GoBackToTransactionMenu()
	{
		cout << setw(37) << left << "\n\tPlease press any key to go back to transaction menu....";

		system("pause>0");
		ShowTransactionMenu();
	}

	static void _ShowDepositeScreen()
	{
		/*cout << "\n Deposite Screen Will Be Here...\n";*/
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithDrawScreen()
	{
		/*cout << "\n Withdrw Screen Will Be Here...\n";*/
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		/*cout << "\n Total Balances Screen Will Be Here...\n";*/
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsShowTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionMenuOption(enTransactionMenuOption TransactionOption)
	{
		switch (TransactionOption)
		{
		case enTransactionMenuOption::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionMenuOption::eWithDraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionMenuOption::eTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionMenuOption::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionMenuOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionMenuOption::eShowMainMenu:
		{
			// do nothing here th main screen will handle it 
		}
		}
	}

public:

	static void ShowTransactionMenu()
	{
		system("cls");

		if (!CheckAccessRight(clsUser::enMainMenuPermission::pShowTransactionMenu))
		{
			return; // this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenuOption((enTransactionMenuOption)ReadTransactionMenuOption());
	}
};

