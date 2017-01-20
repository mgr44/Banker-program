#pragma once
#include "Account.h"
#include <iostream>
using namespace std;
class BSTree
{
public:
	BSTree();
	~BSTree();

	bool Insert(Account* item);
	// retrieve object, first parameter is the ID of the account
	// second parameter holds pointer to found object, NULL if not found
	bool Retrieve(const int &ID, Account * &itemOut) const;
	// displays the contents of a tree to cout
	void Display() const;
	void Empty();
	bool isEmpty() const;
private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};
	bool RecursiveInsert(Node* &current, Account* item);
	bool RecursiveRetrieve(Node* current, const int &ID, Account* &itemOut)const;
	void RecursiveEmpty(Node* current);
	void RecursiveDisplay(Node* current)const;
	Node *root;
};

