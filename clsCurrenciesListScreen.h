#pragma once
#include "clsCurrency.h" 
#include "clsScreen.h" 
#include <iomanip>

class clsCurrenciesListScreen : clsScreen 
{
    static void _PrintUserRecordLine(clsCurrency cur)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << cur.Country();
        cout << "| " << setw(25) << left << cur.CurrencyCode();
        cout << "| " << setw(40) << left << cur.CurrencyName();
        cout << "| " << setw(12) << left << cur.Rate();

    }

public :

    static void ShowCurrenciesList()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currencies.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Country";
        cout << "| " << left << setw(25) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                _PrintUserRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________________________\n" << endl;
    }

};

