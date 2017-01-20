#include "stdafx.h"
#include "BaseTransaction.h"


BaseTransaction::BaseTransaction()
{
}


BaseTransaction::~BaseTransaction()
{
}

void BaseTransaction::Execute(BSTree &acounts)
{
	return;
}
bool BaseTransaction::isValid()const
{
	return valid;
}