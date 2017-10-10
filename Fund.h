#pragma once
//#include "Account.h"
//#include "Bank.h"
#include "Transaction.h"
//#include "BSTree.h"
#include <string>
#include <queue>
using namespace std;

class Fund
{
public:
	Fund();
	int getBalance() const;
	void setBalance (int );
	void insertRecord(Transaction t);//access queue
	void displayHistory();//access
	~Fund();
private:
	int balance;
	queue<Transaction> fq;
};

