#pragma once
#include <iostream> 
#include "clsScreen.h"
#include "clsTransferLogsHistory.h"
#include <iomanip>

using namespace std;

class clsTarnsferRegisterLogsScreen : protected clsScreen
{
    static void _PrintTransferLogsDataLine(clsTransferLogsHistory Data)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << Data.date;
        cout << "| " << setw(8) << left << Data.time;
        cout << "| " << setw(12) << left << Data.SenderAccount;
        cout << "| " << setw(12) << left << Data.ReceiverAccount;
        cout << "| " << setw(12) << left << Data.TransferAmount;
        cout << "| " << setw(12) << left << Data.SenderBalance;
        cout << "| " << setw(12) << left << Data.ReceiverBalance;
        cout << "| " << setw(12) << left << Data.UserName;

    }

public :

    static void ShowTransferLogs()
    {
        vector <clsTransferLogsHistory> vLogs = clsTransferLogsHistory::GetTransfreRegisterLogs();

        string Title = "  Transfer Register Logins Screen";
        string SubTitle = "\t    (" + to_string(vLogs.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "Date";
        cout << "| " << left << setw(8) << "Time";
        cout << "| " << left << setw(12) << "S.Accnt";
        cout << "| " << left << setw(12) << "R.Accnt";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "R.Balance";
        cout << "| " << left << setw(12) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;


        if (vLogs.size() == 0)
        {
            cout << "\t\t\t\tNo Users Available In the System!";
        }
        else
        {
            for (clsTransferLogsHistory User : vLogs)
            {

                _PrintTransferLogsDataLine(User);
                cout << endl;
            }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        }
    }

};

