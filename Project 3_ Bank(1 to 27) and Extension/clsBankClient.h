#pragma once
#include <iostream>
#include <fstream>
#include "clsPerson.h";
#include "clsString.h";
#include <string>
#include <vector>

using namespace std;

class clsBankClient :public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    long long _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
    {
        vector<string>vsString;

        vsString = clsString::SplitString(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vsString[0], vsString[1], vsString[2], vsString[3], vsString[4],
            vsString[5], stoi(vsString[6]));
    }

    static string _ConvertClinetObjectToLine(clsBankClient Client, string Separtor = "#//#")
    {
        string stClientRecord;

        stClientRecord += Client.FirstName + Separtor;
        stClientRecord += Client.LastName + Separtor;
        stClientRecord += Client.Email + Separtor;
        stClientRecord += Client.Phone + Separtor;
        stClientRecord += Client._AccountNumber + Separtor;
        stClientRecord += Client.PinCode + Separtor;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    static vector<clsBankClient> _LoadClientDataFromFile()
    {
        vector<clsBankClient>vsClients;

        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                vsClients.push_back(Client);
            }

            MyFile.close();
        }

        return vsClients;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> vsClients)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::out);

        if (MyFile.is_open())
        {
            string DateLine;

            for (clsBankClient& C : vsClients)
            {
                if (C._MarkForDelete == false)
                {
                    DateLine = _ConvertClinetObjectToLine(C);
                    MyFile << DateLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> _vsClients;

        _vsClients = _LoadClientDataFromFile();

        for (clsBankClient& C : _vsClients)
        {
            if (C._AccountNumber == AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(_vsClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClinetObjectToLine(*this));
    }

    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    struct  stTransferLog;

    static stTransferLog _ConvertTransferLodLineToRecord(string Line, string Seprator = "#//#")
    {
        stTransferLog TransferLogRecord;
        vector<string> vTransferLogRecord = clsString::SplitString(Line, Seprator);

        TransferLogRecord.DateTime = vTransferLogRecord[0];
        TransferLogRecord.SrcAccountNumber = vTransferLogRecord[1];
        TransferLogRecord.DecAccountNumber = vTransferLogRecord[2];
        TransferLogRecord.Amount = stoi(vTransferLogRecord[3]);
        TransferLogRecord.SrcAccBalance = stoi(vTransferLogRecord[4]);
        TransferLogRecord.DecAccBalance = stoi(vTransferLogRecord[5]);
        TransferLogRecord.UserName = vTransferLogRecord[6];

        return TransferLogRecord;
    }

    string _PerpareTransferLogRecord(long long Amount, clsBankClient Client, string Username, string Seprator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::DateToString(clsDate()) + " - " +
            clsDate::GetLocalTime() + Seprator;
        TransferLogRecord += _AccountNumber + Seprator;
        TransferLogRecord += Client.AccountNumber() + Seprator;
        TransferLogRecord += to_string(Amount) + Seprator;
        TransferLogRecord += to_string(_AccountBalance) + Seprator;
        TransferLogRecord += to_string(Client.AccountBalance) + Seprator;
        TransferLogRecord += Username;

        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient Client, string Username)
    {
        string stRegisterLogLine = _PerpareTransferLogRecord(Amount, Client, Username);
        fstream MyFile;

        MyFile.open("Transfer Log.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stRegisterLogLine << endl;

            MyFile.close();
        }
    }

public:

    struct stTransferLog
    {
        string DateTime;
        string SrcAccountNumber;
        string DecAccountNumber;
        int Amount;
        int SrcAccBalance;
        int DecAccBalance;
        string UserName;
    };

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
        string AccountNumber, string PinCode, long long AccountBalance)
        :clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(long long AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    long long GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance))  long long AccountBalance;

    /*void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in); // read mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client1 = _ConvertLineToClientObject(Line);

                if (Client1._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client1;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in); // read mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client1 = _ConvertLineToClientObject(Line);

                if (Client1._AccountNumber == AccountNumber && Client1._PinCode == PinCode)
                {
                    MyFile.close();
                    return Client1;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResult::svFaildEmptyObject;
        }
        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResult::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResult::svFailedAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResult::svSucceeded;
            }
        }
        }
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> vsClients;

        vsClients = _LoadClientDataFromFile();

        for (clsBankClient& C : vsClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(vsClients);
        *this = _GetEmptyClientObject();

        return true;
    }

    static long long GetTotalBalances()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientList();
        long long TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {
            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }

    static vector<clsBankClient> GetClientList()
    {
        return _LoadClientDataFromFile();
    }

    void Deposite(long long Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(long long Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient, string Username)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposite(Amount);
        _RegisterTransferLog(Amount, DestinationClient, Username);
        return true;
    }

    static vector<stTransferLog> GetTransferLogList()
    {
        fstream MyFile;
        stTransferLog TransferLogRecord;
        vector< stTransferLog> vTransferLogRecord;

        MyFile.open("Transfer Log.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                TransferLogRecord = _ConvertTransferLodLineToRecord(Line);
                vTransferLogRecord.push_back(TransferLogRecord);
            }

            MyFile.close();
        }

        return vTransferLogRecord;
    }

};