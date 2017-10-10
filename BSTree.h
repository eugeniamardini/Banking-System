#pragma once
//#include "BSTree.h"
#include "Account.h"
//#include "Bank.h"
using namespace std;

class BSTree
{
public:
	BSTree();
	bool Insert(Account *a);
	//Account Search(const Account &);
	// retrieve object, first parameter is object to retrieve
	// second parameter holds pointer to found object, NULL if not found
	bool Retrieve(const int &, Account * & ) const;
	// displays the contents of a tree to cout
	void Display() const;
	void Empty();
	bool isEmpty() const;
	~BSTree();
private:
	struct Node {
		Account *pAcct;
		Node *right;
		Node *left;
	};
	Node *root;
	bool InsertHelper(Node *root, Account *);
	//Account Search (Node *, const Account &);
	void DisplayHelper (Node *root) const;
	bool RetrieveHelper(Node *, const int &, Account * &) const;
	void Empty (Node * &);
};

