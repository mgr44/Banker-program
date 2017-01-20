#pragma once
#include "BaseTransaction.h"
using namespace std;
class OpenOrder: public BaseTransaction
{
public:
	OpenOrder();
	OpenOrder(ifstream &fileStream);
	~OpenOrder();

	void Execute(BSTree &accounts);

private:
	string firstName;
	string LastName;
};

