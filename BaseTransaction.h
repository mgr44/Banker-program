#pragma once
#include "BSTree.h"
#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class BaseTransaction
{
public:
	BaseTransaction();
	~BaseTransaction();

	 virtual void Execute(BSTree &acounts);

	 bool isValid()const;

protected:
	int accountID;
	bool valid;
};

