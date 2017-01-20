#pragma once
#include "BaseTransaction.h"
class TransferOrder : public BaseTransaction
{
public:
	TransferOrder();
	TransferOrder(ifstream &fileStream);
	~TransferOrder();

	void Execute(BSTree &accounts);

private:
	string inAccountAndFund;
	string outAccountAndFund;
	int inAccountID;
	int inFundNumber;
	int outAccountID;
	int outFundNumber;
	int amount;
};

