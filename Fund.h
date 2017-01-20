#pragma once
#include <string>
#include <iostream>
#include <queue>
using namespace std;
class Fund
{
public:
	Fund();
	Fund(string name, int number);
	~Fund();

	bool Deposit(int amount);
	bool Withdraw(int amount);
	void UpdateHistoryD(int ID, int amount, bool success);
	void UpdateHistoryW(int ID, int amount, bool success);
	void UpdateHistoryTIn(int outID, int inID, int amount, bool success);
	void UpdateHistoryTOut(int outID, int inID, int amount, bool success);

	void PrintHistory();
	void Display()const;

	string getName()const;
	int getBalance()const;

private:
	int fundNumber;
	int balance;
	string name;
	queue<string> history;
};

