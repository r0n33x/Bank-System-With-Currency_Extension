#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsTransferLogsHistory.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumberTransferFrom()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number to Transfer From : ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    static string _ReadAccountNumberTransferTo()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number to Transfer To : ";
        cin >> AccountNumber;
        return AccountNumber;
    }

  /* static void _ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);


        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Amount <= Client1.AccountBalance)
            {
                Client1.Withdraw(Amount);
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }*/


public :

	static void TransferScreen()
	{
        _DrawScreenHeader("\t   Transfer Screen");

        string AccountNumber1 = _ReadAccountNumberTransferFrom();


        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] does not exist.\n";
            AccountNumber1 = _ReadAccountNumberTransferFrom();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
        _PrintClient(Client1);

        string AccountNumber2 = _ReadAccountNumberTransferTo();

        while (!clsBankClient::IsClientExist(AccountNumber2) || AccountNumber1 == AccountNumber2)
        {
            cout << "\nClient with [" << AccountNumber2 << "] does not exist.\n";
            AccountNumber2 = _ReadAccountNumberTransferTo();
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
        _PrintClient(Client2);


        double Amount = 0;
        cout << "Enter Transfer Amount : ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > Client1.AccountBalance)
        {
            cout << "Account Exceeds The available Balance , Enter Another Amount : ";
            Amount = clsInputValidate::ReadDblNumber();
        }

        cout << "\nAre you sure you want to perform this Transfer ? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Amount <= Client1.AccountBalance)
            {
                Client1.Withdraw(Amount);
                Client2.Deposit(Amount);
                cout << "\nTransfer done Successfully.\n";
                _PrintClient(Client1);
                _PrintClient(Client2);
                clsTransferLogsHistory::AddTransferOpreationToFile(clsTransferLogsHistory(AccountNumber1, AccountNumber2,
                    Amount, Client1.AccountBalance, Client2.AccountBalance));
            }
            else
            {
                cout << "\nCannot Transfer, Insuffecient Balance!\n";
                cout << "\nAmout to Transfer is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
	}

};

