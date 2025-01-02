#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddnewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include <iomanip>

class clsManageUsersScreen :protected clsScreen
{
private:

	enum enManageUserMenuOption {
		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eShowMainMenu = 6
	};

	static short _ReadManageUserMenuOption()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 6 ] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToManageUserMenu()
	{
		cout << setw(37) << left << "\n\tPlease press any key to go back to manage user menu....";

		system("pause>0");
		ShowMangeUsersMenu();
	}

	static void _ShowListUserScreen()
	{
		/*cout << "\nList User Screen Will Be Here...\n";*/
		clsUserListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		/*cout << "\nAdd New User Screen Will Be Here...\n";*/
		clsAddnewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		/*cout << "\nDelete User Screen Will Be Here...\n"; */
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		/*cout << "\nUpdate User Screen Will Be Here...\n";*/
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		/*cout << "\nFind User Screen Will Be Here...\n";*/
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenuOptions(enManageUserMenuOption ManageUserMenuOption)
	{
		switch (ManageUserMenuOption)
		{
		case enManageUserMenuOption::eListUser:
		{
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUserMenu();
			break;
		}
		case enManageUserMenuOption::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserMenu();
			break;
		}
		case enManageUserMenuOption::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMenu();
			break;
		}
		case enManageUserMenuOption::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMenu();
			break;
		}
		case enManageUserMenuOption::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMenu();
			break;
		}
		case enManageUserMenuOption::eShowMainMenu:
		{
			// do nothing here th main screen will handle it 
		}
		}
	}

public:

	static void ShowMangeUsersMenu()
	{
		system("cls");

		if (!CheckAccessRight(clsUser::enMainMenuPermission::pUsersManagerMenu))
		{
			return; // this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenuOptions((enManageUserMenuOption)_ReadManageUserMenuOption());
	}

};

