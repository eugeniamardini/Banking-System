//#include "Account.h"
#include "Bank.h"
//#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
using namespace std;

int main()
{
	Bank b;
	b.readTrans("BankTrans.txt");
	b.Display();
	b.Empty();
	b.Display();
	//queue <string> q;
	//string fileName;
	//cout << "Enter name of the file to process: " << endl;
	//cin >> fileName;
	
	//t.Create(file);
	//makes sure that the file opened properly
    /*while (infile.fail())
	{ 
		cout << "The file at location " << fileName << " failed to open" << endl;
		cout << "Please enter the location of the file: ";
		cin >> fileName;
		infile.open(fileName.c_str());   
    }*/
	
	//Transaction t;
	//t.BuildTransactions(q);
	//BSTree b;
	//cout << b.isEmpty() << endl;
	//PRINT OUT TREE
	

	/*if (!infile)  { 
      cout << "File could not be opened." << endl; 
      return 1;  
	}*/

    /*string line;
    char temp[1024];
    int initialCurrentBalance;
    ifstream data4db;
    //ofstream output;

    data4db.open("BankTrans.txt");
    //output.open("output.txt");  
 
    cin >> initialCurrentBalance;

    Account Account(initialCurrentBalance);

    char * pch;
    
    while (!data4db.eof())
    {
        getline (data4db, line);
        memset(temp, 0, sizeof(temp));
        strncpy(temp, line.c_str(), sizeof(temp));
        cout << temp << std::endl;
        pch = strtok(temp, " ");
        while ( pch != NULL)
        {
            // withraw or deposit
            if (strcmp(pch, "w") == 0)
            {
                pch = strtok(NULL, " ");
                Account.Withdraw(atoi(pch));
            }
            else if (strcmp(pch, "d") == 0)
            {
                pch = strtok(NULL, " ");
                Account.Deposit(atoi(pch));
            }
            else
            {
                pch = strtok(NULL, " ");
                // do nothing
            }
        }
    }

    data4db.close();
    cout << "Current Balance is $" << Account.getCurrentBalance() << std::endl;
    cout << "Number Of Transactions is " << Account.getNumberOfTransactions() << std::endl;
    //output.close();   */
}