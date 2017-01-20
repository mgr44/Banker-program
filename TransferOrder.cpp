#include "stdafx.h"
#include "TransferOrder.h"


TransferOrder::TransferOrder()
{
}
TransferOrder::TransferOrder(ifstream &fileStream)
{
	valid = true;
	string inAccountAndFund;
	string outAccountAndFund;
	fileStream >> outAccountAndFund >> amount >> inAccountAndFund;

	this->inAccountAndFund = inAccountAndFund;
	this->outAccountAndFund = outAccountAndFund;

	if (inAccountAndFund.length() == 5)
	{
		if (outAccountAndFund.length() == 5)
		{
			inFundNumber = (inAccountAndFund.back() - '0');
			inAccountAndFund.pop_back();
			inAccountID = stoi(inAccountAndFund);

			outFundNumber = (outAccountAndFund.back() - '0');
			outAccountAndFund.pop_back();
			outAccountID = stoi(outAccountAndFund);
		}
		else
		{
			cerr << "ERROR: Input " << outAccountAndFund << " is not valid. Transaction will not be processed." << endl;
			valid = false;
		}
	}
	else
	{
		cerr << "ERROR: Input " << inAccountAndFund << " is not valid. Transaction will not be processed." << endl;
		valid = false;
	}
}

TransferOrder::~TransferOrder()
{
}

void TransferOrder::Execute(BSTree &accounts)
{
	Account* tempIn;
	Account* tempOut;
	bool transferIn;
	bool transferOut;

	if (accounts.Retrieve(outAccountID, tempOut))
	{
		if (accounts.Retrieve(inAccountID, tempIn))
		{

			transferOut = tempOut->TransferOut(amount, outFundNumber, stoi(inAccountAndFund));
			transferIn = tempIn->TransferIn(amount, inFundNumber, stoi(outAccountAndFund), transferOut);

			if (transferOut && !transferIn)
			{
				//the transfer out was succesfull, but the transfer in failed for some reason.
				//this will only happen if code is added that makes deposits fail under some conditions
				//if above is true, code should be added her to return funds back to the transferOut account.
			}

		}
		else
		{
			cerr << "ERROR: Account " << inAccountID << " not found. Transferal refused." << endl;
		}
	}
	else
	{
		cerr << "ERROR: Account " << outAccountID << " not found. Transferal refused." << endl;
	}
	
}