#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddnewUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionToSet();
	}


	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

	static int _ReadPermissionToSet()
	{
		int Permissions = 0;
		char Answer = 'y';

		cout << "\nDo you want to give full access ? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
			return clsUser::enMainMenuPermission::eAll;

		cout << "\nDo you want to give access to : " << endl;

		cout << "\nShow client list ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pListClients;


		cout << "\nAdd new client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pAddNewClients;

		cout << "\nDelete client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pDeletClients;

		cout << "\nUpdate client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pUpdateClient;

		cout << "\nFind client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pFindClient;

		cout << "\nTransaction ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pShowTransactionMenu;

		cout << "\nManage user ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pUsersManagerMenu;

		cout << "\nLog Register ? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			Permissions += clsUser::enMainMenuPermission::pLogRegiser;


		return Permissions;
	}


public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t  Add New User Screen");

		string UserName = "";

		cout << "\nPlease Enter User UserName : ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is already used , choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case  clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Addeded Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because it's Empty";
			break;

		}
		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError Usert was not saved because username is used!\n";
			break;
		}
		}
	}
};

