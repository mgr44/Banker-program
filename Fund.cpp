#include "stdafx.h"
#include "Fund.h"


Fund::Fund()
{
	balance = 0;
}
Fund::Fund(string name, int number)
{
	this->fundNumber = number;
	this->name = name;
	balance = 0;
}

Fund::~Fund()
{
}

bool Fund::Deposit(int amount)
{
	balance += amount;
	return true;
}
bool Fund::Withdraw(int amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		return true;
	}
	else
	{
		return false;
	}
}
void Fund::UpdateHistoryD(int ID, int amount, bool success)
{
	string update;
	update = ("D " + to_string(ID) + to_string(fundNumber) + " " + to_string(amount));

	if (!success)
	{
		update += " (Failed)";
	}

	history.push(update);
}
void Fund::UpdateHistoryW(int ID, int amount, bool success)
{
	string update;
	update = ("W " + to_string(ID)  + to_string(fundNumber) + " " + to_string(amount));

	if (!success)
	{
		update += " (Failed)";
	}

	history.push(update);
}
void Fund::UpdateHistoryTOut(int outID, int inID, int amount, bool success)
{
	string update;
	update = ("T " + to_string(outID) + to_string(fundNumber) + " " + to_string(amount) + " " + to_string(inID));

	if (!success)
	{
		update += " (Failed)";
	}

	history.push(update);
}
void Fund::UpdateHistoryTIn(int outID, int inID, int amount, bool success)
{
	string update;
	update = ("T " + to_string(outID) + " " + to_string(amount) + " " + to_string(inID)) + to_string(fundNumber);

	if (!success)
	{
		update += " (Failed)";
	}

	history.push(update);
}
void Fund::PrintHistory()
{
	queue<string> temp;
	if (!history.empty())
	{
		cout << name << ": $" << balance << endl;
	}

	while (!history.empty())
	{
		string front = history.front();
		cout << "  " << front << endl;
		temp.push(front);
		history.pop();
	}
	while (!temp.empty())
	{
		history.push(temp.front());
		temp.pop();
	}

}
void Fund::Display()const
{
	cout << "     " << name << ": $" << balance << endl;
}
string Fund::getName()const
{
	return this->name;
}
int Fund::getBalance()const
{
	return this->balance;
}