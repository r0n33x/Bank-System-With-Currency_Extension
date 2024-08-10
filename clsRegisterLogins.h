#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"
#include "clsUtil.h"
using namespace std;

class clsRegisterLogins
{
private:

	string _Date ;
	string _Time ;
    string _UserName;
    string _PassWord;
    int _Permissions;


    static string _ConverUserResgisterObjectToLine( clsRegisterLogins User, string Seperator = "#//#")
    {
		string Line = "";
		Line += User._Date + "-" + User._Time;
		Line += Seperator +  User._UserName;
		Line += Seperator + clsUtil::EncryptText(User._PassWord);
		Line += Seperator + to_string( User._Permissions);
		return Line;
    }

    static void _SaveUserRegisterDataToFile(vector <clsRegisterLogins> vRegUsers)
    {

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsRegisterLogins C : vRegUsers)
            {

                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserResgisterObjectToLine(C);
                    MyFile << DataLine << endl;
            }

            MyFile.close();

        }

    }

    static void _AddUserRegisterDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsRegisterLogins _ConvertLinetoRegisterLoginObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        
        vUserData = clsString::Split(Line, Seperator);

        return clsRegisterLogins(vUserData[0].substr(0, vUserData[0].find('-')), vUserData[0].substr(vUserData[0].find('-') + 1, vUserData[0].find("#//#"))
            , vUserData[1],clsUtil::DecryptText(vUserData[2]), stoi(vUserData[3]));

    }

    static  vector <clsRegisterLogins> _LoadRegisterUsersDataFromFile()
    {

        vector <clsRegisterLogins> vRegUsers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsRegisterLogins User = _ConvertLinetoRegisterLoginObject(Line);

                vRegUsers.push_back(User);
            }

            MyFile.close();

        }

        return vRegUsers;

    }

public : 


    clsRegisterLogins()
    {
        _Date = clsDate::DateToString(clsDate());
        _Time = clsDate::TimeToString(clsDate());
        _UserName = CurrentUser.UserName;
        _PassWord = CurrentUser.Password;
        _Permissions = CurrentUser.Permissions;
    }

    clsRegisterLogins(string Date , string Time , string UserName , string Password , int Permissions)
    {
        _Date = Date;
        _Time = Time;
        _UserName = UserName;
        _PassWord = Password;
        _Permissions = Permissions;
    }

    static void AddUserRegisterInfoToFile(clsRegisterLogins r)
    {
        _AddUserRegisterDataLineToFile(_ConverUserResgisterObjectToLine(r));
    }

    static vector < clsRegisterLogins >  GetRegisterUsers()
    {
        return _LoadRegisterUsersDataFromFile();
    }

    string GetDate()
    {
        return _Date;
    }

    void SetDate(string s)
    {
        _Date = s;
    }
    __declspec(property(put = SetDate, get = GetDate)) string date;

    string GetTime()
    {
        return _Time;
    }
    void SetTime(string s)
    {
        _Time = s;
    }
    __declspec(property(put = SetTime, get = GetTime)) string time;

    string GetPassword()
    {
        return _PassWord;
    }
    void SetPassword(string s)
    {
        _PassWord = s;
    }
    _declspec(property(put = SetPassword, get = GetPassword))string password;

    int GetPermission()
    {
        return _Permissions;
    }
    void SetPermission(int s)
    {
        _Permissions = s;
    }
    _declspec(property(put = SetPermission , get = GetPermission)) int permissions;

    string GetUserName()
    {
        return _UserName;
    }
    void SetUserName(string s)
    {
        _UserName = s;
    }
    _declspec(property(put = SetUserName, get = GetUserName))string UserName;
};

