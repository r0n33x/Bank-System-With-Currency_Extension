#pragma once
#include "clsScreen.h"
#include <iostream> 
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std; 

class clsCurrencyExchangeScreen : protected clsScreen 
{

private :

	enum enCurrencyExchangeMenueOptions
	{
		eListCurrencies = 1 , eFindCurrency = 2 , eUpdateRate = 3
		, eCurrencyCalculator = 4 , eMainMenue = 5 
	};


	static short ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _ShowListCurrencyScreen()
	{
        clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateSccreen()
	{
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
    }

	static void _ShowCurrencyCalaculatorScreen()
	{
        clsCurrencyCalculatorScreen::_ShowCurrencyCalculatorScreen(); 
	}

	static void _ShowCurrencyExchangeMenueScreen()
	{
		cout << "\n\nPress any key to go back to Cureency Exchange Menue...";
		system("pause>0");
        ShowCurrencyExchangeMenue();
	}


    static void _PerformCurrncyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
    {
        switch (CurrencyExchangeMenueOption)
        {
        case enCurrencyExchangeMenueOptions::eListCurrencies :
        {
            system("cls");
            _ShowListCurrencyScreen();
            _ShowCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencyExchangeMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _ShowCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencyExchangeMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateSccreen();
            _ShowCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalaculatorScreen();
            _ShowCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencyExchangeMenueOptions::eMainMenue:
        {

            //do nothing here the main screen will handle it :-) ;

        }
        }
    }

public : 

    static void ShowCurrencyExchangeMenue()
    {

        /*if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }*/

        system("cls");
        _DrawScreenHeader("\tCureency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrncyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
    }

};

