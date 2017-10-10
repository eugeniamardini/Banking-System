#include "Transaction.h"
#include "Account.h"
#include "BSTree.h"
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

Transaction::Transaction()
{
	status = false;
}
void Transaction::setTransType(char c)
{
	transType = c;
}
char Transaction::getTransType () const
{
	return transType;
}
void Transaction::setFundID(int fID)
{
	fundID = fID;
}
int Transaction::getFundID() const
{
	return fundID;
}
void Transaction::setTransFundID(int tfID)
{
	transFundID = tfID;
}
int Transaction::getTransFundID() const
{
	return transFundID;
}
void Transaction::setAcctNum(int n)
{
	acctNum = n;
}
int Transaction::getTransAcctNum()const
{
	return transAcctNum;
}
void Transaction::setTransAcctNum(int tn)
{
	transAcctNum = tn;
}
int Transaction::getAcctNum()const
{
	return acctNum;
}
void Transaction::setAmount(int a)
{
	amount = a;
}
int Transaction::getAmount() const
{
	return amount;
}
void Transaction::setStatus(bool st)
{
	status = st;
}
bool Transaction::getStatus() const
{
	return status;
}
void Transaction::setFName(string f)
{
	fName = f;
}
string Transaction::getFName()const
{
	return fName;
}
void Transaction::setLName(string l)
{
	lName = l;
}
string Transaction::getLName()const
{
	return lName;
}
ostream& operator<<(ostream &outStream, const Transaction &t)
{
	if(t.transType == 'O')
	{
	outStream<<t.transType << " " << t.lName << " " << t.lName << " "<< t.acctNum ;
	}
	else if (t.transType == 'D' || t.transType == 'W')
	{
		outStream <<t.transType << " " << t.acctNum<<t.fundID << " " << t.amount;
		if (t.status == true)
		{
			outStream<<" (Failed)";
		}
	}
	else 
	{
		outStream << t.transType << " " << t.acctNum << t.fundID<< " " << t.amount<< " " << t.transAcctNum<<t.transFundID;
	}
	return outStream;
}

Transaction::~Transaction()
{
}
