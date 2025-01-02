#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsUpdateUserScreen : protected clsScreen
{
private:

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

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen");

		string UserName = "";

		cout << "\nPlease Enter User UserName : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUsername is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\n\nUpdate User Info:";
		cout << "\n____________________\n";

		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Updated Successfully :-)\n";
			_PrintUser(User);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\n error! User wasn't save becsuse it's empty.\n";
			break;
		}
		}
	}
};

