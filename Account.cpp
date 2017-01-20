#include "stdafx.h"
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account()
{
}
Account::Account(string firstName, string lastName, int ID)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->ID = ID;

	funds[0] = Fund("Money Market", 0);
	funds[1] = Fund("Prime Money Market", 1);
	funds[2] = Fund("Long-Term Bond", 2);
	funds[3] = Fund("Short-Term Bond", 3);
	funds[4] = Fund("500 Index Fund", 4);
	funds[5] = Fund("Capital Value Fund", 5);
	funds[6] = Fund("Growth Equity Fund", 6);
	funds[7] = Fund("Growth Index Fund", 7);
	funds[8] = Fund("Value Fund", 8);
	funds[9] = Fund("Value Stock Index", 9);
}

Account::~Account()
{
}

void Account::PrintAllHistory()
{
	cout << "Transaction history for " << firstName << " " << lastName << " by fund." << endl;
	for (int i = 0; i < NUM_FUNDS; i++)
	{
		funds[i].PrintHistory();
	}
}
void Account::PrintFundHistory(int fundNumber)
{
	cout << "Transaction history for " << firstName << " " << lastName << " " << funds[fundNumber].getName() << ": $"
		<< funds[fundNumber].getBalance() << endl;
	funds[fundNumber].PrintHistory();
}
void Account::Display()const
{
	cout << firstName << " " << lastName << " Account ID: " <<  endl;
	for (int i = 0; i < NUM_FUNDS; i++)
	{
		funds[i].Display();
	}
	cout << endl;
}
bool Account::Deposit(int amount, int fundNumber)
{

	bool success = funds[fundNumber].Deposit(amount);

	funds[fundNumber].UpdateHistoryD(ID, amount, success);

	return success;
}
bool Account::Withdraw(int amount, int fundNumber)
{
	bool success = false;
	if (funds[fundNumber].Withdraw(amount))
	{
		success = true;
		funds[fundNumber].UpdateHistoryW(ID, amount, success);
	}
	else
	{
		if (fundNumber == 0 || fundNumber == 2)
		{
			int newAmount = funds[fundNumber].getBalance();
			int remainderAmount = amount - newAmount;

			if (funds[fundNumber + 1].Withdraw(remainderAmount))
			{
				funds[fundNumber].Withdraw(newAmount);
				success = true;
				funds[fundNumber].UpdateHistoryW(ID, newAmount, success);
				funds[fundNumber + 1].UpdateHistoryW(ID, remainderAmount, success);
			}
		}
		else if (fundNumber == 1 || fundNumber == 3)
		{
			int newAmount = funds[fundNumber].getBalance();
			int remainderAmount = amount - newAmount;

			if (funds[fundNumber - 1].Withdraw(remainderAmount))
			{
				funds[fundNumber].Withdraw(newAmount);
				success = true;
				funds[fundNumber].UpdateHistoryW(ID, newAmount, success);
				funds[fundNumber - 1].UpdateHistoryW(ID, remainderAmount, success);
			}
		}
		
		if(!success)
		{
			funds[fundNumber].UpdateHistoryW(ID, amount, success);
		}
	}

	switch (success)
	{
	case true: break;
	case false: cerr  << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName << " " << lastName 
		<< " "<< funds[fundNumber].getName() << endl;
	}
	return success;
}
bool Account::TransferOut(int amount, int fundNumber, int inID)
{
	bool success = false;;
	if (funds[fundNumber].Withdraw(amount))
	{
		success = true;
		funds[fundNumber].UpdateHistoryTOut(ID, inID, amount, success);
	}
	else
	{
			if (fundNumber == 0 || fundNumber == 2)
			{
				int newAmount = funds[fundNumber].getBalance();
				int remainderAmount = amount - newAmount;

				if (funds[fundNumber + 1].Withdraw(remainderAmount))
				{
					funds[fundNumber].Withdraw(newAmount);
					success = true;
					funds[fundNumber].UpdateHistoryTOut(ID, inID, newAmount, success);
					funds[fundNumber + 1].UpdateHistoryTOut(ID, inID, remainderAmount, success);
				}
			}
			else if (fundNumber == 1 || fundNumber == 3)
			{
				int newAmount = funds[fundNumber].getBalance();
				int remainderAmount = amount - newAmount;

				if (funds[fundNumber - 1].Withdraw(remainderAmount))
				{
					funds[fundNumber].Withdraw(newAmount);
					success = true;
					funds[fundNumber].UpdateHistoryTOut(ID, inID, newAmount, success);
					funds[fundNumber - 1].UpdateHistoryTOut(ID, inID, remainderAmount, success);
				}
			}
			if (!success)
			{
				funds[fundNumber].UpdateHistoryTOut(ID, inID, amount, success);
			}

	}

	switch (success)
	{
	case true: break;
	case false: cerr << "ERROR: Not enough funds to transfer " << amount << " from " << firstName << " " << lastName
		<< " " << funds[fundNumber].getName() << " to account: " << inID << endl;
	}
	return success;
}
bool Account::TransferIn(int amount, int fundNumber, int outID, bool successfullWithdrawl)
{
	bool successFullDeposit = false;
	if (successfullWithdrawl)
	{
		successFullDeposit = funds[fundNumber].Deposit(amount);
	}

	bool successFullTransfer = (successfullWithdrawl && successFullDeposit);
	funds[fundNumber].UpdateHistoryTIn(outID, ID, amount, successFullTransfer);

	return successFullTransfer;
}

int Account::getID()const
{
	return this->ID;
}
string Account::getName()const
{
	return firstName + lastName;
}
string Account::getFirstName()const
{
	return firstName;
}
string Account::getLastName()const
{
	return lastName;
}

bool Account::operator==(const Account& otherAccount)const
{
	return (this->ID == otherAccount.ID);
}
bool Account::operator!=(const Account& otherAccount)const
{
	return !(*this == otherAccount);
}
bool Account::operator>(const Account& otherAccount)const
{
	return (this->ID > otherAccount.ID);
}
bool Account::operator<(const Account& otherAccount)const
{
	return !(*this > otherAccount);
}