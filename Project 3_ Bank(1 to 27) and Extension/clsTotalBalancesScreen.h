#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
		cout << "|" << left << setw(40) << Client.FullName();
		cout << "|" << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalancesScreen()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(25) << left << "" << "|" << setw(15) << left << "Account Number";
		cout << "|" << setw(40) << left << "Client Name";
		cout << "|" << setw(12) << left << "Balance";
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		long long TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << ""  "\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";

	}
};

