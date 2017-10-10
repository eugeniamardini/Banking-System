#include "Bank.h"
#include "BSTree.h"
#include "Fund.h"
#include "Account.h"
#include "Transaction.h"
#include <fstream>
#include <queue>
#include <iostream>
#include <cctype>
#include <stdlib.h>
using namespace std;
Bank::Bank(void)
{
}

void Bank::readTrans(string file)
{
	ifstream infile(file);
	string thing;
	string  fName, lName, acct1,amount, acct2;
	while (!infile.eof())
	{
		infile >> thing;
		if (thing == "O" || thing == "o")
		{
			Transaction t;
			t.setTransType(thing[0]);
			infile >> lName >> fName >> acct1;
			if(acct1.size() > ACCTMAX-1)
			{
				cerr << "ERROR: Account number " << acct1<< " is invalid!" << endl;
			}
			else
			{
			t.setLName(lName);
			t.setFName(fName);
			int acct = atoi(acct1.c_str());
			if (acct < 1)
			{
				cerr << "ERROR: Account number " << acct << " is invalid!" << endl;
			}
			else
			{
			t.setAcctNum(acct);
			q.push(t);
			}
			}
		}
		else if (thing == "D" || thing == "d")
		{
			Transaction t;
			t.setTransType(thing[0]);
			infile >> acct1 >> amount;
			if(acct1.size() > ACCTMAX)
			{
				cerr << "ERROR: Account number " << acct1<< " is invalid!" << endl;
			}
			else
			{
			string acct = acct1.substr(0,4);
			int accountNum = atoi (acct.c_str());
			char x = acct1[4];
			int fundNum = x-'0';
			int amt = atoi(amount.c_str());
			if (accountNum < 1 )
			{
				cerr << "ERROR: Account number " << accountNum << " is invalid!" << endl;
			}
			else if (fundNum < 0)
			{
				cerr << "ERROR: Fund number " << fundNum << " is invalid!" << endl;
			}
			else 
			{
			t.setAcctNum(accountNum);
			t.setFundID(fundNum);
			t.setAmount(abs(amt));
			q.push(t);
			}
			}
		}
		else if (thing == "W"||thing == "w")
		{
			Transaction t;
			t.setTransType(thing[0]);
			infile >> acct1 >> amount;
			if(acct1.size() > ACCTMAX)
			{
				cerr <<"ERROR: Account number " << acct1<< " is invalid!" << endl;
			}
			else
			{
			string acct = acct1.substr(0,4);
			int accountNum = atoi (acct.c_str());
			char x = acct1[4];
			int fundNum = x-'0';
			int amt = atoi(amount.c_str());
			if (accountNum < 1 )
			{
				cerr << "ERROR: Account number " << accountNum << " is invalid!" << endl;
			}
			else if (fundNum < 0)
			{
				cerr << "ERROR: Fund number " << fundNum << " is invalid!" << endl;
			}
			else 
			{
			t.setAcctNum(accountNum);
			t.setFundID(fundNum);
			t.setAmount(abs(amt));
			q.push(t);
			}
			}
		}
		else if (thing == "T" || thing == "t")
		{
			Transaction t;
			t.setTransType(thing[0]);
			infile >> acct1 >> amount >> acct2;
			if(acct1.size() > ACCTMAX || acct2.size() > ACCTMAX)
			{
				cerr <<"ERROR: Account number " << acct1<< " is invalid!"  << endl;
			}
			else
			{
			string a1 = acct1.substr(0,4);
			int a1Num = atoi (a1.c_str());
			string a2 = acct2.substr(0,4);
			int a2Num = atoi (a2.c_str());
			char x = acct1[4];
			int fundNum1 = x-'0';
			char y = acct2[4];
			int fundNum2 = y-'0';
			int amt = atoi(amount.c_str());
			if (a1Num < 1 )
			{
				cerr << "ERROR: Account number " << a1Num << " is invalid!" << endl;
			}
			else if (a2Num < 1)
			{
				cerr << "ERROR: Account number " << a2Num << " is invalid!" << endl;
			}
			else if (fundNum1 < 0)
			{
				cerr << "ERROR: Fund number " << fundNum1 << " is invalid!" << endl;
			}
			else if (fundNum2 < 0)
			{
				cerr << "ERROR: Fund number " << fundNum2 << " is invalid!" << endl;
			}
			else 
			{
			t.setAcctNum(a1Num);
			t.setFundID(fundNum1);
			t.setTransAcctNum(a2Num);
			t.setTransFundID(fundNum2);
			t.setAmount(abs(amt));
			q.push(t);
			}
			}
		}
		else if (thing == "H" || thing == "h")
		{
			
			Transaction t;
			t.setTransType(thing[0]);
			infile >> acct1;
			if(acct1.size() > ACCTMAX)
			{
				cerr <<"ERROR: Account number " << acct1<< " is invalid!"<< endl;
			}
			else if (acct1.size() == ACCTMAX)
			{
			string acct = acct1.substr(0,4);
			int accountNum = atoi (acct.c_str());
			char x = acct1[4];
			int fundNum1 = x-'0';
			if (accountNum < 1 )
			{
				cerr << "ERROR: Account number " << accountNum << " is invalid!" << endl;
			}
			else if (fundNum1 < 0)
			{
				cerr << "ERROR: Fund number " << fundNum1 << " is invalid!" << endl;
			}
			else 
			{
			t.setAcctNum(accountNum);
			t.setFundID(fundNum1);
			}
			}
			else
			{
				int accountNum = atoi (acct1.c_str());
				if (accountNum < 1 )
				{
					cerr << "ERROR: Account number " << accountNum << " is invalid!" << endl;
				}
				else 
				{
					t.setAcctNum(accountNum);
					t.setFundID(-1);
				}
			}
			q.push(t);
		}
		else
		{
			cerr << "ERROR: File is empty!"<<endl;
		}
	}
	processTrans(q);
}

void Bank::processTrans( queue<Transaction> &q)
{
	while (!q.empty())
	{
	Transaction t = q.front();
	char type = t.getTransType();
	
	q.pop();
	if( type == 'O')
	{
		OpenAcct(t);
	}
	else if (type == 'D')
	{
		Deposit(t);
	}
	else if(type=='W')
	{
		Withdraw(t);
	}
	else if (type== 'T')
	{
	
		Transfer(t);
	}
	else if(type == 'H')
	{
		History(t);
	}
	else
		break;
	}
}
void Bank::Display()
{
	bank.Display();
}

void Bank::Empty()
{
	bank.Empty();
}
void Bank::OpenAcct(Transaction t)
{
	Account *a = new Account;
	a->setLastName(t.getLName());
	a->setFirstName(t.getFName());
	a->setAcctNum(t.getAcctNum());
	bank.Insert(a);
}

void Bank::Deposit(Transaction t)
{
		Account *pAcct = NULL;
		int acctNum = t.getAcctNum();
		bool success = bank.Retrieve(acctNum, pAcct);
		if(success)
		{
			Fund f = pAcct->getFund(t.getFundID());
			int bal = f.getBalance();
		
			bal += t.getAmount();
			f.setBalance(bal);					
			pAcct->insertTrans(t, t.getFundID());
			pAcct->setFund(f, t.getFundID());

			//int curBal = pAcct->getCurrentBalance();
			//curBal +=t.getAmount();
			//pAcct->setCurBal(curBal);
			//int numTrans = pAcct->getNumberOfTransactions();
			//numTrans ++;
			//pAcct->setNumOfTrans(numTrans);
		}
		else 
		{
			cerr << "ERROR: Account " << t.getAcctNum() << " not found. Deposit refused." << endl;
		}
}

void Bank::Withdraw(Transaction t)
{
		Account *pAcct = NULL;
		int acctNum = t.getAcctNum();
		bool success = bank.Retrieve(acctNum, pAcct);
		
		if(success)
		{
			int fund = t.getFundID();
			Fund f = pAcct->getFund(fund);
			int bal = f.getBalance();
		    int total = t.getAmount();
			if (bal < total)
			{
				//Fund f2;
				if (fund == 0 && ((pAcct->getFund(1).getBalance() + bal) >= total))
				{
					 Fund f2 = pAcct->getFund(1);
					 int bal2 = f2.getBalance();
					 int amount =(total-(total-bal));
					 bal-=amount;
					 total -= amount;
					 bal2 -= total;
					 f.setBalance(bal);
					 Transaction adjT;
					 adjT.setAmount(amount);
					 adjT.setTransType('W');
					 adjT.setAcctNum(acctNum);
					 adjT.setFundID(fund);
					pAcct->insertTrans(adjT, fund);
					pAcct->setFund(f, fund);
					f2.setBalance(bal2);
					Transaction adjT2;
					 adjT2.setAmount(total);
					 adjT2.setTransType('W');
					 adjT2.setAcctNum(acctNum);
					 adjT2.setFundID(1);
					pAcct->insertTrans(adjT2, 1);
					pAcct->setFund(f2, 1);
				}
				else if (fund == 1 && ((pAcct->getFund(0).getBalance()+bal) >= total))
				{
					Fund f2 = pAcct->getFund(0);
					 int bal2 = f2.getBalance();
					 int amount =(total-(total-bal));
					 bal-=amount;
					 total -= amount;
					 bal2 -= total;
					 f.setBalance(bal);
					Transaction adjT;
					 adjT.setAmount(amount);
					 adjT.setTransType('W');
					 adjT.setAcctNum(acctNum);
					 adjT.setFundID(fund);
					pAcct->insertTrans(adjT, fund);
					pAcct->setFund(f, fund);
					Transaction adjT2;
					 adjT2.setAmount(total);
					 adjT2.setTransType('W');
					 adjT2.setAcctNum(acctNum);
					 adjT2.setFundID(0);
					f2.setBalance(bal2);
					pAcct->insertTrans(adjT2, 0);
					pAcct->setFund(f2, 0);
				}
				else if (fund == 2 && ((pAcct->getFund(3).getBalance() + bal) >= total))
				{
					 Fund f2 = pAcct->getFund(3);
					 int bal2 = f2.getBalance();
					 int amount =(total-(total-bal));
					 bal-=amount;
					 total -= amount;
					 bal2 -= total;
					 f.setBalance(bal);
					 Transaction adjT;
					 adjT.setAmount(amount);
					 adjT.setTransType('W');
					 adjT.setAcctNum(acctNum);
					 adjT.setFundID(fund);
					pAcct->insertTrans(adjT, fund);
					pAcct->setFund(f, fund);
					f2.setBalance(bal2);
					Transaction adjT2;
					 adjT2.setAmount(total);
					 adjT2.setTransType('W');
					 adjT2.setAcctNum(acctNum);
					 adjT2.setFundID(3);
					pAcct->insertTrans(adjT2, 3);
					pAcct->setFund(f2, 3);
				}
				else if (fund == 3 && ((pAcct->getFund(2).getBalance() + bal)>= total))
				{
					Fund f2 = pAcct->getFund(2);
					 int bal2 = f2.getBalance();
					 int amount =(total-(total-bal));
					 bal-=amount;
					 total -= amount;
					 bal2 -= total;
					 f.setBalance(bal);
					 Transaction adjT;
					 adjT.setAmount(amount);
					 adjT.setTransType('W');
					 adjT.setAcctNum(acctNum);
					 adjT.setFundID(fund);
					pAcct->insertTrans(adjT, fund);
					pAcct->setFund(f, fund);
					f2.setBalance(bal2);
					Transaction adjT2;
					 adjT2.setAmount(total);
					 adjT2.setTransType('W');
					 adjT2.setAcctNum(acctNum);
					 adjT2.setFundID(2);
					pAcct->insertTrans(adjT2, 2);
					pAcct->setFund(f2, 2);
				}
				else
				{
				t.setStatus(true);
				pAcct->insertTrans(t, t.getFundID());
				cerr << "ERROR: Not enough funds to withdraw " << t.getAmount()<< " from " << t.getFName()
					<< " " << t.getLName() << pAcct->getFundName(t.getFundID())<<endl;
				}
			}
			else
			{
				bal -= t.getAmount();
				f.setBalance(bal);
				pAcct->insertTrans(t, t.getFundID());
				pAcct->setFund(f, t.getFundID());
			}
		}
		else 
		{
			cerr << "ERROR: Account " << acctNum << " not found. Withdrawal refused." << endl;
		}
	
}

void Bank::Transfer(Transaction t)
{
		Account *pAcct1 = NULL;
		Account *pAcct2 = NULL;
		int a1Num = t.getAcctNum();
		int a2Num = t.getTransAcctNum();
		bool success1 = bank.Retrieve(a1Num, pAcct1);
		
		if(success1)
		{
			Fund f1 = pAcct1->getFund(t.getFundID());
			int bal1 = f1.getBalance();
			
			if (f1.getBalance() < t.getAmount())
			{
				t.setStatus(true);
				pAcct1->insertTrans(t, t.getFundID());
				cerr << "ERROR: Not enough funds to transfer " << t.getAmount()<< " from " << t.getFName()
					<< " " << t.getLName() << " " << t.getAcctNum()<< " " << pAcct1->getFundName(t.getFundID())<<endl;
				
			}
			else
			{
				bool success2 = bank.Retrieve(a2Num, pAcct2);
				if (success2)
				{
					Fund f2 = pAcct2->getFund(t.getTransFundID());
					int bal2 = f2.getBalance();
				
					bal1 -= t.getAmount();
					f1.setBalance(bal1);
					
					pAcct1->insertTrans(t, t.getFundID());

					pAcct1->setFund(f1, t.getFundID());
					
					bal2+=t.getAmount();
					f2.setBalance(bal2);
					
					pAcct2->insertTrans(t, t.getTransFundID());
					pAcct2->setFund(f2, t.getTransFundID());
					
					/*int curBal1 = pAcct1->getCurrentBalance();
					curBal1 -=t.getAmount();
					pAcct1->setCurBal(curBal1);
					int curBal2 = pAcct2->getCurrentBalance();
					curBal2 -=t.getAmount();
					pAcct2->setCurBal(curBal2);
					int numTrans1 = pAcct1->getNumberOfTransactions();
					numTrans1 ++;
					pAcct1->setNumOfTrans(numTrans1);
					int numTrans2 = pAcct2->getNumberOfTransactions();
					numTrans2 ++;
					pAcct2->setNumOfTrans(numTrans2);*/
				}
				else 
				{
					cerr << "ERROR: Account " << a2Num << " not found. Transferral refused." << endl;
				}
			}
		}
		else
		{
			cerr << "Account " << a1Num << " not found. Transferral refused." << endl;
		}
	
}

void Bank::History(Transaction t)
{
	
	Account *pAcct = new Account;
	int acctNum = t.getAcctNum();
	int fundNum = t.getFundID();
	bool success = bank.Retrieve(acctNum, pAcct);
	if (success)
	{
		if(fundNum < 0)
		{
			cout << "Transaction History for " << pAcct->getFirstName() << " " << pAcct->getLastName() << " by fund."<< endl;
			for (int i = 0; i<FUNDMAX; i++)
			{
				Fund f = pAcct->getFund(i);
				cout << pAcct->getFundName(i) <<": $" << f.getBalance()<<endl;
				f.displayHistory();
				
			}
		}
		else 
		{
			Fund f = pAcct->getFund(fundNum);
			cout << "Transaction History for " << pAcct->getFirstName() << " " << pAcct->getLastName() << " " << pAcct->getFundName(t.getFundID())
			<< ": $" << f.getBalance()<< endl;
			f.displayHistory();
		
		}
	}
	else
	{
		cerr << "Account doesn't exist!";
	}
}

Bank::~Bank(void)
{
}
