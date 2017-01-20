// Bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "Banker.h"
#include "BaseTransaction.h"
#include "OpenOrder.h"
#include "BSTree.h"
using namespace std;


int main()
{
	Banker jollyBanker;
	jollyBanker.ReadInTransactions("BankTransIn.txt");
	jollyBanker.ProcessTransactions();
    return 0;
}

