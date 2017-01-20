#include "stdafx.h"
#include "DisplayHistoryOrder.h"


DisplayHistoryOrder::DisplayHistoryOrder()
{
}
DisplayHistoryOrder::DisplayHistoryOrder(ifstream &fileStream)
{
	valid = true;
	string accountAndFund;
	fileStream >> accountAndFund;

	//check to make sure that the input is correct
	if (accountAndFund.length() == 5)
	{
		fundNumber = (accountAndFund.back() - '0');
		accountAndFund.pop_back();
		accountID = stoi(accountAndFund);
		fundOnlyDisplay = true;
	}
	else if(accountAndFund.length() == 4)
	{
		accountID = stoi(accountAndFund);
		fundOnlyDisplay = false;
	}
	else
	{
		cerr << "ERROR: Input " << accountAndFund << " is not valid. Transaction will not be processed." << endl;
		valid = false;
	}
}

DisplayHistoryOrder::~DisplayHistoryOrder()
{
}

void DisplayHistoryOrder::Execute(BSTree &accounts)
{
	Account* temp = NULL;

	if (accounts.Retrieve(accountID, temp))
	{
		if (fundOnlyDisplay)
		{
			temp->PrintFundHistory(fundNumber);
		}
		else
		{
			temp->PrintAllHistory();
		}
	}
	else
	{
		cerr << "ERROR Account " << accountID << " not found. Transaction refused." << endl;
	}
}