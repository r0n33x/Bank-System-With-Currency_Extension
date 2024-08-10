#pragma once
#include <iostream> 
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsCurrencyCalculatorScreen : clsScreen 
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
    static double _ConvertAmountToUSD(double Amount , clsCurrency Currency )
    {
        return Amount / Currency.Rate();
    }
    static double _ConvertAmountInUSDToAnotherCurrency(double AmountInUSD , clsCurrency Currency)
    {
        return AmountInUSD * Currency.Rate();
    }

public : 

    static void _ShowCurrencyCalculatorScreen()
    {

        _DrawScreenHeader("\tCurrency Calculator Screen");

        bool check = 1;

        do
        {
            string FirstCurrency = "";
            cout << "\nPlease Enter First Currency Code : ";
            FirstCurrency = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyExist(FirstCurrency))
            {
                cout << "\nCurrency Not Found Please Enter Another Code : ";
                FirstCurrency = clsInputValidate::ReadString();
            }

            string SecondCurrency = "";
            cout << "\nPlease Enter Second Currency Code : ";
            SecondCurrency = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyExist(SecondCurrency))
            {
                cout << "\nCurrency Not Found Please Enter Another Code : ";
                SecondCurrency = clsInputValidate::ReadString();
            }

            clsCurrency fCurrency = clsCurrency::FindByCode(FirstCurrency);
            clsCurrency sCurrency = clsCurrency::FindByCode(SecondCurrency);

            double Amount = 0;
            cout << "\nEnter Amount to Exchange : ";
            Amount = clsInputValidate::ReadDblNumber();

            if (sCurrency.CurrencyCode() == "USD")
            {
                cout << "\nConvert To : \n\n";
                _PrintCurrency(fCurrency);

                cout << "\n" << Amount << " " << fCurrency.CurrencyCode() << " = " << _ConvertAmountToUSD(Amount, fCurrency) << " USD";
            }
            else
            {
                cout << "\nConvert From : \n\n";
                _PrintCurrency(fCurrency);

                double AmountInUSD = _ConvertAmountToUSD(Amount, fCurrency);

                cout << "\n" << Amount << " " << fCurrency.CurrencyCode() << " = " << AmountInUSD << " USD";

                cout << "\nConverting From USD to : \n\n";

                _PrintCurrency(sCurrency);

                cout << "\n" << Amount << " " << fCurrency.CurrencyCode() << " = " << _ConvertAmountInUSDToAnotherCurrency(AmountInUSD, sCurrency) << " " << sCurrency.CurrencyCode();
            }
            cout << "\n\nDo you Want To perform another calculation ? y/n ";
            char Ans;
            cin >> Ans;
            if (Ans == 'Y' || Ans == 'y')
                check = true;
            else return;

        } while (check);
    }
};

