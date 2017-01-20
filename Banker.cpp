#include "stdafx.h"
#include "Banker.h"


Banker::Banker()
{
}


Banker::~Banker()
{
	
}

void Banker::ReadInTransactions(string fileName)
{
	ifstream fileStream(fileName);

	string transactionType;
	char c = fileStream.get();
	fileStream.putback(c);

	while (!fileStream.eof())
	{
		fileStream >> transactionType;

		BaseTransaction* transactionPointer = NULL;

		if (transactionType == "O")
		{
			OpenOrder* temp = new OpenOrder(fileStream);
			transactionPointer = temp;
			temp = NULL;
		}
		else if (transactionType == "D")
		{
			DepositOrder* temp = new DepositOrder(fileStream);
			transactionPointer = temp;
			temp = NULL;
		}
		else if (transactionType == "W")
		{
			WithdrawlOrder* temp = new WithdrawlOrder(fileStream);
			transactionPointer = temp;
			temp = NULL;
		}
		else if (transactionType == "T")
		{
			TransferOrder* temp = new TransferOrder(fileStream);
			transactionPointer = temp;
			temp = NULL;
		}
		else if (transactionType == "H")
		{
			DisplayHistoryOrder* temp = new DisplayHistoryOrder(fileStream);
			transactionPointer = temp;
			temp = NULL;
		}
		transactions.push(transactionPointer);
	}

}
void Banker::ProcessTransactions()
{
	while (!transactions.empty())
	{
		BaseTransaction* temp = transactions.front();
		transactions.pop();

		if (temp->isValid())
		{
			temp->Execute(accounts);
		}
		delete temp;
		temp = NULL;
	}

	cout << endl << "Processing done. Final balances" << endl;
	Display();
}
void Banker::Display()const
{
	accounts.Display();
}