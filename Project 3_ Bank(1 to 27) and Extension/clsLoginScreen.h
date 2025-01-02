#pragma once
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include <iomanip>
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFailed = false;
		short FailedLoginCount = 3;
		string UserName, Password;
		do
		{
			if (LoginFailed)
			{
				FailedLoginCount--;
				if (FailedLoginCount == 0)
				{
					cout << "\n  You Are Looked After 3 Failed Trials\n";

					return false;
				}

				cout << "\nInvalid UserName/ or Password!\n";

				cout << "You Have " << FailedLoginCount << " Trials To Login.\n";
			}

			cout << "\nEnter UserName? ";
			cin >> UserName;

			cout << "Enter password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::_ShowMainMenu();
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}

	
};

