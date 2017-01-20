#include "stdafx.h"
#include "WithdrawlOrder.h"


WithdrawlOrder::WithdrawlOrder()
{
}
WithdrawlOrder::WithdrawlOrder(ifstream &fileStream)
{
	valid = true;
	string accountAndFund;
	fileStream >> accountAndFund >> amount;

	if (accountAndFund.length() == 5)
	{
		fundNumber = (accountAndFund.back() - '0');
		accountAndFund.pop_back();
		accountID = stoi(accountAndFund);
	}
	else
	{
		cerr << "ERROR: Input " << accountAndFund << " is not valid. Transaction will not be processed." << endl;
		valid = false;
	}
}

WithdrawlOrder::~WithdrawlOrder()
{
}

void WithdrawlOrder::Execute(BSTree &accounts)
{
	Account* temp;
	if (accounts.Retrieve(accountID, temp))
	{
		temp->Withdraw(amount, fundNumber);
	}
	else
	{
		cerr << "ERROR: Account " << accountID << " not found. Withdrawl refused." << endl;
	}
}