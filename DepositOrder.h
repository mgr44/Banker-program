#pragma once
#include "BaseTransaction.h"
class DepositOrder : public BaseTransaction
{
public:
	DepositOrder();
	DepositOrder(ifstream &fileStream);
	~DepositOrder();

	void Execute(BSTree &accounts);

private:
	int amount;
	int fundNumber;
};

