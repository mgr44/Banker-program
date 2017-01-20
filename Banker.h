#pragma once
#include "BSTree.h"
#include "BaseTransaction.h"
#include "OpenOrder.h"
#include "DepositOrder.h"
#include "WithdrawlOrder.h"
#include "TransferOrder.h"
#include "DisplayHistoryOrder.h"
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include<fstream>
using namespace std;

class Banker
{
public:
	Banker();
	~Banker();
	
	void ReadInTransactions(string fileName);
	void ProcessTransactions();

private:
	void Display()const;
	BSTree accounts;
	queue<BaseTransaction*> transactions;
};

