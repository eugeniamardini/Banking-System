#include "BSTree.h"
#include "Account.h"
#include "Bank.h"
#include <iostream>
//#include <iomanip>
using namespace std;

BSTree::BSTree()
{
	root = NULL;
}
bool BSTree::Insert(Account *a)
{	
	bool inserted;
	if (root == NULL)
	{
		Node *newPtr = new Node;
		newPtr->pAcct = a;
		newPtr->left = newPtr->right = NULL;
		root = newPtr;
		//cout << "Inserted: " << *root->pAcct<< endl;
		inserted = true;
		//return inserted;
	}
	else
	{
		inserted = InsertHelper(root, a);
	}
	return inserted;
}

bool BSTree::InsertHelper (Node *root , Account *a)
{
	bool inserted;
	//cout <<"Root Num :"<<root->pAcct->getAcctNumber()<< " Ins Num : "<<a->getAcctNumber()<< endl;

		if (root->pAcct->getAcctNumber()==a->getAcctNumber())
		{
			cout <<"ERROR: Account "<< a->getAcctNumber() << " is already open. Transaction refused." << endl;
			inserted = false;
		}
		else if ((root->pAcct->getAcctNumber()) > a->getAcctNumber())
		{
			if (root->left == NULL)
			{
				Node *newPtr = new Node;
			newPtr->pAcct = a;
			newPtr->left = newPtr->right = NULL;
			root->left = newPtr;
			//cout << "Inserted: " << *root->left->pAcct<< endl;
			inserted = true;
			return inserted;
			}
			else
			{
				return InsertHelper(root->left, a);
			}
		}
		else //if ((root->pAcct->getAcctNumber()) < (a->getAcctNumber()))
		{
			if (root->right == NULL)
			{
				Node *newPtr = new Node;
			newPtr->pAcct = a;
			newPtr->left = newPtr->right = NULL;
			root->right = newPtr;
			//cout << "Inserted: " << *root->right->pAcct<< endl;
			inserted = true;
			return inserted;
			}
			else
			{
				return InsertHelper(root->right, a);
			}
		}
	return inserted;
}

// retrieve object, first parameter is object to retrieve
// second parameter holds pointer to found object, NULL if not found
bool BSTree::Retrieve(const int &a, Account * &aPtr ) const
{
	//cout << "root " << root->pAcct;
	return RetrieveHelper(root, a, aPtr);
}
bool BSTree::RetrieveHelper(Node *curRoot, const int &a, Account * &ptr) const
{
	bool retrieved = true;
	if(curRoot == NULL)
	{
		//ptr = NULL;
		retrieved = false;
		return retrieved;
	}
	else if (curRoot->pAcct->getAcctNumber() == a)
	{
		ptr = curRoot->pAcct;
		retrieved = true;
		return retrieved;
		//return true;
	}
	else 
	{
		if (curRoot->pAcct->getAcctNumber() < a)
		{
			return RetrieveHelper(curRoot->right, a, ptr);
		}
		else if(curRoot->pAcct->getAcctNumber() > a)
		{
			return RetrieveHelper(curRoot->left, a, ptr);
		}
		else 
		{
			//cerr << "Doesn't exist!" << endl;
			retrieved = false;
			return retrieved;
		}
	}
	return retrieved;
}

// displays the contents of a tree to cout
void BSTree::Display() const
{
	cout << "\nProcessing Done. Final Balances" << endl;
	DisplayHelper(root);
	
}
void BSTree::DisplayHelper(Node *root) const
{
	if (root !=NULL)
	{
		DisplayHelper(root->left);
		cout << *root->pAcct << endl;
		DisplayHelper(root->right);
	}
}

void BSTree::Empty()
{
	Empty(root);
}
void BSTree::Empty(Node * &root)
{
	if (root!=NULL)
	{
		Empty(root->left);
		Empty(root->right);
		delete root;
		root = NULL;
	}
}
bool BSTree::isEmpty() const
{
	return root==NULL;
}

BSTree::~BSTree(void)
{
}
