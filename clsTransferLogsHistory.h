#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsTransferLogsHistory
{
	string _Date;
	string _Time;
	string _SenderAccount;
	string _ReceiverAccount ;
	double _TransferAmount = 0;
	double _SenderBalance;
	double _ReceiverBalance;
	string _UserName;

	static string _ConverUserResgisterObjectToLine(clsTransferLogsHistory TransferData, string Seperator = "#//#")
	{
		string Line = "";
		Line += TransferData._Date + "-" + TransferData._Time;
		Line += Seperator + TransferData._SenderAccount;
		Line += Seperator + TransferData._ReceiverAccount;
		Line += Seperator + to_string(TransferData._TransferAmount);
		Line += Seperator + to_string(TransferData._SenderBalance);
		Line += Seperator + to_string(TransferData._ReceiverBalance);
		Line += Seperator + CurrentUser.UserName;
		return Line;
	}

	static void _AddUserRegisterDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("TransferLogs.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	static  vector <clsTransferLogsHistory> _LoadTransferRegisterDataFromFile()
	{

		vector <clsTransferLogsHistory> vTransferReg;

		fstream MyFile;
		MyFile.open("TransferLogs.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsTransferLogsHistory User = _ConvertLinetoTransferRegisterObject(Line);

				vTransferReg.push_back(User);
			}

			MyFile.close();

		}

		return vTransferReg;

	}

	static clsTransferLogsHistory _ConvertLinetoTransferRegisterObject(string Line, string Seperator = "#//#")
	{
		vector<string> vTransferData;

		vTransferData = clsString::Split(Line, Seperator);

		return clsTransferLogsHistory(vTransferData[0].substr(0, vTransferData[0].find('-')), vTransferData[0].substr(vTransferData[0].find('-') + 1, vTransferData[0].find("#//#"))
			, vTransferData[1], vTransferData[2], stod(vTransferData[3]) , stod(vTransferData[4])  , stod(vTransferData[5]) , vTransferData[6]);

	}

public :

	clsTransferLogsHistory( string SenderAcc, string ReceiverAccount, double TranAmount, double SenderBalance, double ReceiverBalance)
	{
		_Date = clsDate::DateToString(clsDate());
		_Time = clsDate::TimeToString(clsDate());
		_SenderAccount = SenderAcc;
		_ReceiverAccount = ReceiverAccount;
		_TransferAmount = TranAmount;
		_SenderBalance = SenderBalance;
		_ReceiverBalance = ReceiverBalance;
		_UserName = CurrentUser.UserName;
	}

	clsTransferLogsHistory(string Date, string Time, string SenderAcc, string ReceiverAccount, double TranAmount, double SenderBalance, double ReceiverBalance, string UserName)
	{
		_Date = Date;
		_Time = Time;
		_SenderAccount = SenderAcc;
		_ReceiverAccount = ReceiverAccount;
		_TransferAmount = TranAmount;
		_SenderBalance = SenderBalance;
		_ReceiverBalance = ReceiverBalance;
		_UserName = UserName;
	}
	
	static void AddTransferOpreationToFile(clsTransferLogsHistory t)
	{
		_AddUserRegisterDataLineToFile(_ConverUserResgisterObjectToLine(t));
	}
	
	static vector < clsTransferLogsHistory > GetTransfreRegisterLogs()
	{
		return _LoadTransferRegisterDataFromFile();
	}

	void SetDate(string s)
	{
		_Date = s;
	}
	string GetDate()
	{
		return _Date;
	}
	_declspec(property(put = SetDate, get = GetDate)) string date;

	void SetTime(string s)
	{
		_Time = s;
	}
	string GetTime()
	{
		return _Time;
	}
	_declspec(property(put = SetTime, get = GetTime)) string time;

	void SetSenderAccount(string s)
	{
		_SenderAccount = s;
	}
	string GetSenderAccount()
	{
		return _Time;
	}
	_declspec(property(put = SetSenderAccount, get = GetSenderAccount)) string SenderAccount;

	void SetReceiverAccount(string s)
	{
		_ReceiverAccount = s;
	}
	string GetReceiverAccount()
	{
		return _ReceiverAccount;
	}
	_declspec(property(put = SetReceiverAccount, get = GetReceiverAccount)) string ReceiverAccount;

	void SetTransferAmount(double s)
	{
		_TransferAmount = s;
	}
	double GetTransferAmount()
	{
		return _TransferAmount;
	}
	_declspec(property(put = SetTransferAmount, get = GetTransferAmount)) double TransferAmount;

	void SetSenderBalance(double s)
	{
		_SenderBalance = s;
	}
	double GetSenderBalance()
	{
		return _SenderBalance;
	}
	_declspec(property(put = SetSenderBalance, get = GetSenderBalance)) double SenderBalance;

	void SetReceiverBalance(double s)
	{
		_ReceiverBalance = s;
	}
	double GetReceiverBalance()
	{
		return _ReceiverBalance;
	}
	_declspec(property(put = SetReceiverBalance, get = GetReceiverBalance)) double ReceiverBalance;

	void SetUserName(string s)
	{
		_UserName = s;
	}
	string GetUserName()
	{
		return _UserName;
	}
	_declspec(property(put = SetUserName, get = GetUserName)) string UserName;
};

