#include "stdafx.h"
#include "DepositOrder.h"


DepositOrder::DepositOrder()
{
}
DepositOrder::DepositOrder(ifstream &fileStream)
{
	valid = true;
	string accountAndFund;
	fileStream >> accountAndFund >> amount;
	
	if (accountAndFund.length() == 5)
	{
		char temp = accountAndFund.back();
		fundNumber = temp - '0';
		accountAndFund.pop_back();
		accountID = stoi(accountAndFund);
	}
	else
	{
		cerr << "ERROR: Input " << accountAndFund << " is not valid. Transaction will not be processed." << endl;
		valid = false;
	}

}

DepositOrder::~DepositOrder()
{
}

void DepositOrder::Execute(BSTree &accounts)
{
	Account* temp;
	if (accounts.Retrieve(accountID, temp))
	{
		bool success = temp->Deposit(amount, fundNumber);
	}
	else
	{
		cerr << "ERROR: Account " << accountID << " not found. Deposit refused." << endl;
	}
}