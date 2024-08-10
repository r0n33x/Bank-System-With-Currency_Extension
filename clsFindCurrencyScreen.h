#pragma once
#include <iostream> 
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen : clsScreen 
{
    enum enFindTypeChoices
    {
        eByCode = 1, eByCountry = 2
    };

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

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        
        cout << "\nFind By : [1] Code / [2] Country ? ";
        enFindTypeChoices eChoice = (enFindTypeChoices) clsInputValidate::ReadIntNumberBetween(1, 2);
    
        if (eChoice == enFindTypeChoices::eByCode)
        {
            cout << "\nPlease Enter Currency Code : ";
            string Code = clsInputValidate::ReadString();
            while (!clsCurrency::IsCurrencyExist(Code))
            {
                cout << "\nCurrency Not Found Please Enter Another Code : ";
                Code = clsInputValidate::ReadString();
            }

            clsCurrency Currency = clsCurrency::FindByCode(Code);

            if (!Currency.IsEmpty())
            {
                cout << "\nUser Found :-)\n";
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }

            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nPlease Enter Currency Country Name : ";
            string CountryName = clsInputValidate::ReadString();
            while (!clsCurrency::IsCurrencyExistByCountry(CountryName))
            {
                cout << "\nCurrency Country Name Not Found Please Try Another Country Name : ";
                CountryName = clsInputValidate::ReadString();
            }

            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

            if (!Currency.IsEmpty())
            {
                cout << "\nUser Found :-)\n";
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }

            _PrintCurrency(Currency);
        }   
    }
};

