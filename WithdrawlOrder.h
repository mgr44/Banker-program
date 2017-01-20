#pragma once
#include "BaseTransaction.h"
class WithdrawlOrder : public BaseTransaction
{
public:
	WithdrawlOrder();
	WithdrawlOrder(ifstream &fileStream);
	~WithdrawlOrder();

	void Execute(BSTree &accounts);

private:
	int amount;
	int fundNumber;
};

