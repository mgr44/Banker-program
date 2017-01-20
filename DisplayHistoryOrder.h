#pragma once
#include "BaseTransaction.h"
class DisplayHistoryOrder : public BaseTransaction
{
public:
	DisplayHistoryOrder();
	DisplayHistoryOrder(ifstream &fileStream);

	~DisplayHistoryOrder();

	void Execute(BSTree &accounts);

private:
	int fundNumber;
	bool fundOnlyDisplay;
};

