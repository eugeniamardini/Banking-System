#include "Account.h"
//#include "Bank.h"
//#include "BSTree.h"
#include "Fund.h"
#include <iostream>
#include <string>
using namespace std;

Account::Account()
{ 
	//currentBalance = 0;
}

 Account::Account (int acctNum)
 {
	 acct = acctNum;
 }

Account::Account(string f, string l, int acctNum)
{
	this->clientFName = f;
	this->clientLName = l;
	this->acct = acctNum;
	//this->currentBalance = 0;
	//this->numberOfTransactions = 0;
}


int Account::getAcctNumber() const
{
	return acct;
}

void Account::setAcctNum (int n)
{
	acct = n;
}

/*int Account::getCurrentBalance() const
{
	return currentBalance;
}

void Account::setCurBal(int c)
{
	currentBalance = c;
}
*/
Fund Account::getFund (int f) const
{
	return funds[f];
}
void Account::setFund(const Fund &f, int i)
{
	funds[i].setBalance(f.getBalance());
}
void Account::insertTrans(const Transaction &t, int i)
{
	funds[i].insertRecord(t);
}

/*void Account::setNumOfTrans( int t)
{
	numberOfTransactions = t;
}*/
void Account::setFirstName(string f)
{
	clientFName = f;
}

string Account::getFirstName () const
{
	return clientFName;
}
void Account::setLastName(string l)
{
	clientLName = l;
}

string Account::getLastName () const
{
	return clientLName;
}

string Account::getFundName(const int &x) const
{
	string fundName;
	if (x==0)
	{
		fundName = "Money Market";
	}
	if(x==1) 
	{
		fundName = "Prime Money Market";
	}
	if(x==2)
	{
		fundName ="Long-Term Bond";
	}
	if (x==3)
	{
		fundName ="Short-Term Bond";
	}
	if (x==4)
	{
		fundName ="500 Index Fund";
	}
	if (x==5)
	{
		fundName ="Capital Value Fund";
	}
	if(x==6)
	{
		fundName ="Growth Equity Fund";
	}
	if( x==7)
	{
		fundName ="Growth Index Fund";
	}
	if (x==8)
	{
		fundName ="Value Fund";
	}
	if(x==9)
	{
		fundName ="Value Stock Index";
	}
	return fundName;
}

bool Account::operator<(const Account &a)const
{
	return (this->acct < a.acct);
}

bool Account::operator> (const Account &a)const
{
	return (this->acct > a.acct);
}

void Account::operator=(const Account &a)
{
	acct = a.acct;
	clientFName = a.clientFName;
	clientLName = a.clientLName;
	//currentBalance = a.currentBalance;
	//numberOfTransactions = a.numberOfTransactions;
	for (int i = 0; i < FUNDMAX; i++)
	{
		funds[i].setBalance(a.funds[i].getBalance());
	}
}
bool Account::operator== (const Account &a)
{
	return (acct==a.acct);
}
bool Account::operator!= (const Account &a)
{
	return !(*this == a);
}
/*int Account::getNumberOfTransactions() const
{
	return numberOfTransactions;
}*/

ostream& operator<<(ostream &outStream, const Account &a)
{
	outStream <<a.clientFName <<" "<< a.clientLName<< " Account ID: " << a.acct <<endl;
	for (int i = 0; i<FUNDMAX; i++)
	{
		outStream << "    "<<a.getFundName(i)<< ": $" <<a.getFund(i).getBalance()<<endl;
	}
	return outStream;
} 
Account::~Account()
{
}
