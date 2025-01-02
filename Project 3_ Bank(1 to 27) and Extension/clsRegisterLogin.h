#pragma once
#pragma warning (disable :4996)
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <ctime>
#include "clsDate.h"

using namespace std;

class clsRegisterLogin 
{
private:

	string _LocalTime;
	string _Date;
	string _UserName;
	string _Password;
	int _Permissions;

	static string _ConvertRecordToLine(clsRegisterLogin Register, string Seprator = "#//#")
	{
		string stRecordLine;
		stRecordLine += Register.Date + " - ";
		stRecordLine += Register.LocalTime + Seprator;
		stRecordLine += Register.UserName + Seprator;
		stRecordLine += Register.Password + Seprator;
		stRecordLine += to_string(Register.Permissions);

		return stRecordLine;
	}

	static void  _AddDataToFile(clsRegisterLogin Register)
	{
		fstream MyFile;
		MyFile.open("Register Login.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string stDataLine;

			stDataLine = _ConvertRecordToLine(Register);

			MyFile << stDataLine << endl;
		}
	}


public:

    void SetLocalTime(string LocalTime)
	{
		_LocalTime = LocalTime;
	}

	string GetLocalTime()
	{
		return _LocalTime;
	}

	__declspec(property(get = GetLocalTime, put = SetLocalTime)) string LocalTime;

	void SetDate(string Date)
	{
		Date = clsDate::DateToString(clsDate());
		_Date = Date;
	}

	string GetDate()
	{
		return _Date;
	}

	__declspec(property(get = GetDate, put = SetDate)) string Date;

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;


	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static void RegisterLoginInLogFile(clsRegisterLogin Register)
	{
		_AddDataToFile(Register);
	}

};
