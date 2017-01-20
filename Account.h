#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Fund.h"
using namespace std;
const int NUM_FUNDS = 10;
class Account
{
public:
	Account();
	Account(string firstName, string lastName, int ID);
	~Account();
	void PrintAllHistory();
	void PrintFundHistory(int fundNumber);
	void Display()const;

	bool Deposit(int amount, int fundNumber);
	bool Withdraw(int amount, int fundNumber);
	bool TransferOut(int amount, int fundNumber, int inID);
	bool TransferIn(int amount, int fundNumber, int outID, bool success);

	int getID()const;
	string getName()const;
	string getFirstName()const;
	string getLastName()const;


	bool operator==(const Account& otherAccount)const;
	bool operator!=(const Account& otherAccount)const;
	bool operator>(const Account& otherAccount)const;
	bool operator<(const Account& otherAccount)const;
private:

	int ID;
	string firstName;
	string lastName;
	Fund funds[NUM_FUNDS];

};

