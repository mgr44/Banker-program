#include "stdafx.h"
#include "BSTree.h"


BSTree::BSTree()
{
	root = NULL;
}


BSTree::~BSTree()
{
}

bool BSTree::Insert(Account* item)
{	
	return RecursiveInsert(root, item);
}
bool BSTree::RecursiveInsert(Node* &current, Account* item)
{
	if (current == NULL)
	{
		current = new Node();
		current->pAcct = item;
		return true;
	}
	if (*(current->pAcct) == *item)
	{
		return false;
	}
	else if(*item > *(current->pAcct))
	{
		return RecursiveInsert(current->right, item);
	}
	else if (*item < *(current->pAcct))
	{
		return RecursiveInsert(current->left, item);
	}
}
bool BSTree::Retrieve(const int &ID, Account * &itemOut) const
{
	return RecursiveRetrieve(root, ID, itemOut);
}
bool BSTree::RecursiveRetrieve(Node *current, const int &ID, Account * &itemOut) const
{
	if (current == NULL)
	{
		itemOut = NULL;
		return false;
	}
	if (current->pAcct->getID() == ID)
	{
		itemOut = current->pAcct;
		return true;
	}
	else if(ID > current->pAcct->getID())
	{
		return RecursiveRetrieve(current->right, ID, itemOut);
	}
	else if (ID < current->pAcct->getID())
	{
		return RecursiveRetrieve(current->left, ID, itemOut);
	}
}
void BSTree::Display() const
{
	RecursiveDisplay(root);
}
void BSTree::RecursiveDisplay(Node* current)const
{
	if(current == NULL)
	{
		return;
	}
	else
	{
		RecursiveDisplay(current->left);
		current->pAcct->Display();
		RecursiveDisplay(current->right);
	}
}
void BSTree::Empty()
{
	if (!isEmpty())
	{
		RecursiveEmpty(root);
	}
}
void BSTree::RecursiveEmpty(Node* current)
{
	if (current->left != NULL)
	{
		RecursiveEmpty(current->left);
	}
	if (current->right != NULL)
	{
		RecursiveEmpty(current->right);
	}

	delete current;
	current = NULL;
}
bool BSTree::isEmpty() const
{
	return (root == NULL);
}