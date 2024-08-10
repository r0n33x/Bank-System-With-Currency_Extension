#pragma once
#include "clsScreen.h" 
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsUpdateCurrencyRateScreen : clsScreen 
{

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\Currency Card:";
        cout << "\n___________________";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)   = " << Currency.Rate();
        cout << "\n___________________\n";

    }

public : 

    static void ShowUpdateCurrencyScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");

        cout << "\nPlease Enter Currency Code : ";
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Not Found Please Enter Another Code : ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        
        _PrintCurrency(Currency);

        cout << "\nAre you sure do you want to update the rate of this Currency y/n ? ";
        char Ans;
        cin >> Ans;

        if (Ans == 'Y' || Ans == 'y')
        {
            cout << "\nUpdate Rate Currency : ";
            cout << "\n----------------------";
            cout << "\nEnter New Rate : "; 
            double Num;
            cin >> Num;
            Currency.UpdateRate(Num);

            cout << "\nCurrency Updated Successfully :-)";

            _PrintCurrency(Currency);

        }
    }
};

