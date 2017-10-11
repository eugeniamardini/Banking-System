#pragma once
#include "BSTree.h"
#include"Account.h"
#include "Transaction.h"
//#include "Fund.h"
#include <queue>
using namespace std;

class Bank
{
public:
	Bank(void);
	void readTrans(string file);
	void processTrans( queue<Transaction> & );
	void OpenAcct(Transaction );
	void Deposit (Transaction );
	void Withdraw (Transaction );
	void Transfer (Transaction );
	void History (Transaction );
	void Display();
	void Empty();
	~Bank(void);
private:
	queue<Transaction> q;
	BSTree bank;
};

