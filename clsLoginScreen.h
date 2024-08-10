#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsRegisterLogins.h"
class clsLoginScreen :protected clsScreen
{

private:




    static  void _Login()
    {
        bool LoginFaild = false;

        string Username, Password;

        do
        {

            if (LoginFaild)
            {
               cout << "\nInvlaid Username/Password!\n\n";
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            Password = clsUtil::DecryptText(Password);

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

            if (LoginFaild && Trials > 0)
            {             
                Trials--;
                cout << "You have " << Trials << " Trials to Login ." << endl;
            }

        } while (LoginFaild && Trials > 0 );

        if (Trials != 0 && !LoginFaild)
        {
            Trials = 3;
            clsRegisterLogins::AddUserRegisterInfoToFile(clsRegisterLogins());
            clsMainScreen::ShowMainMenue();
        }
        else return;

    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

