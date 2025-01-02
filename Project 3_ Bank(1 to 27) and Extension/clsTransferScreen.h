#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string message = "tranfer from ? ")
    {
        string AccountNumber = "";

        cout << "\nPlease enter account number to " << message;
        cin >> AccountNumber;

        return AccountNumber;
    }

    static long long ReadAmount(clsBankClient SourceClient)
    {
        long long Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }

        return Amount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Transfer Screen");

        string AccountNumber1 = _ReadAccountNumber();

        if (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] doesn't exist.\n";
            AccountNumber1 = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
        _PrintClient(Client1);

        string AccountNumber2 = _ReadAccountNumber("transfer to ? ");

        if (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nClient with [" << AccountNumber2 << "] doesn't exist.\n";
            AccountNumber2 = _ReadAccountNumber("transfer to ? ");
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
        _PrintClient(Client2);

        long long Amount = ReadAmount(Client1);

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Transfer(Amount,Client2,CurrentUser.UserName))
            {
                cout << "\nTranfer done successfully.\n";
            }
            else
            {
                cout << "\nTransfer Failed.\n";
            }

            _PrintClient(Client1);
            _PrintClient(Client2);
        }
        else
        {
            cout << "\nTransfer Failed.\n";
        }
    }




};

