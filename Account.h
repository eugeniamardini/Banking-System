#pragma once
//#include "Bank.h"
#include "Fund.h"
//#include "BSTree.h"
#include <string>
using namespace std;

int const ACCTMAX = 5;
int const FUNDMAX = 10;

class Account
{ 
	friend ostream& operator<<(ostream&, const Account&);
public:
	Account();
	Account (int );
	Account (string , string , int);
	int getAcctNumber () const;
	void setAcctNum (int );
	//int getCurrentBalance() const;
	//void setCurBal(int );
	//int getNumberOfTransactions() const;
	//void setNumOfTrans(int );
	Fund getFund (int ) const;
	void setFund(const Fund &, int);
	void insertTrans(const Transaction &, int );
	string getFundName(const int &) const;
	string getFirstName() const;
	string getLastName() const;
	void setFirstName(string );
	void setLastName(string );
	bool operator<(const Account & ) const;
	bool operator> (const Account &) const;
	void operator= (const Account & );
	bool operator== (const Account &);
	bool operator!= (const Account &);
	~Account(void);
private:
	int acct;
	string clientFName, clientLName;
	//int currentBalance;
	//int numberOfTransactions;
	Fund funds[FUNDMAX];
};

