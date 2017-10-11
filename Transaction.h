#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

class Transaction
{
friend ostream& operator<<(ostream&, const Transaction&);
public:
	Transaction();
	void setTransType (char );
	char getTransType() const;
	void setFundID(int );
	int getFundID() const;
	void setTransFundID(int );
	int getTransFundID() const;
	void setAcctNum(int );
	int getTransAcctNum()const;
	void setTransAcctNum(int );
	int getAcctNum()const;
	void setAmount(int );
	int getAmount() const;
	void setStatus(bool );
	bool getStatus() const;
	void setFName(string);
	string getFName()const;
	void setLName(string );
	string getLName()const;
	~Transaction();
private:
	char transType;
	int fundID;
	int transFundID;
	int acctNum;
	int transAcctNum;
	int amount;
	bool status;
	string fName;
	string lName;
	//queue<Transaction> tq;
};

