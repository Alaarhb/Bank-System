#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;

		if (SubTitle != "")
			cout << "\n\t\t\t\t\t  " << SubTitle;

		cout << "\n\t\t\t\t\t______________________________________\n\n";

		cout << "\n\t\t\t\t\t  User: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\t  Date: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRight(clsUser::enMainMenuPermission Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
			return true;
	}

	/*static void PrintDateAndUserName()
	{
		cout << "\t\t\t\t\t  User: " << CurrentUser.UserName << endl;
		clsDate Date1 = clsDate::GetSystemDate();

		cout << "\t\t\t\t\t  Date: ";
		Date1.Print();
		cout << '\n';
	}*/

};

