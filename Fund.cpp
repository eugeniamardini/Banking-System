#include "Fund.h"
//#include "Account.h"
//#include "Bank.h"
//#include "BSTree.h"
#include <iostream>
#include <iomanip>
using namespace std;

Fund::Fund()
{
	balance = 0;
}

int Fund::getBalance() const
{
	return balance;
}

void Fund::setBalance (int amount)
{
	balance = amount;
}

void Fund::insertRecord(Transaction t )
{
	fq.push(t);
}

void Fund::displayHistory()
{
	for (int i = 0; i<fq.size(); i++)
	{
		Transaction t = fq.front();
		cout << setw(4)<< t << endl;
		fq.pop();
		fq.push(t);
	}
}

Fund::~Fund()
{
}
