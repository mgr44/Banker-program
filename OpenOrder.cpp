#include "stdafx.h"
#include "OpenOrder.h"


OpenOrder::OpenOrder()
{
}
OpenOrder::OpenOrder(ifstream &fileStream)
{
	valid = true;
	fileStream >> LastName >> firstName >> accountID;
	
	if (to_string(accountID).length() != 4)
	{
		cerr << "ERROR: Input " << accountID << " is not valid. Transaction will not be processed." << endl;
		valid = false;
	}
}

OpenOrder::~OpenOrder()
{
}

void OpenOrder::Execute(BSTree &accountTree)
{
	Account* temp = new Account(firstName, LastName, accountID);
	if(!accountTree.Insert(temp))
	{
		cerr << "ERROR: Account " << accountID << " is already open. Transaction Refused" << endl;
	}
}