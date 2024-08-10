#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsRegisterLogins.h"
#include <iomanip>

class clsRegisterLoginScreen : protected clsScreen 
{
private : 

    static void _PrintUserRegisterRecordLine(clsRegisterLogins User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.date;
        cout << "| " << setw(25) << left << User.time;
        cout << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(20) << left << User.password;
        cout << "| " << setw(10) << left << User.permissions;
    }

public :

    static void ShowUsersList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pRegisterLogin))
        {
            return;// this will exit the function and it will not continue
        }
        vector <clsRegisterLogins> vRegisters = clsRegisterLogins::GetRegisterUsers();

        string Title = "\t  Register Logins Screen";
        string SubTitle = "\t    (" + to_string(vRegisters.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "Date";
        cout << "| " << left << setw(25) << "Time";
        cout << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vRegisters.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsRegisterLogins User : vRegisters)
            {

                _PrintUserRegisterRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};

