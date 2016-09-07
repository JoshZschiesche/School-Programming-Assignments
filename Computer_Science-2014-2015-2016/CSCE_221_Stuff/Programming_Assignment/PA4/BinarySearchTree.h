#include <iostream>
#include <cmath>
#include <deque>
#include "BinaryNode.h"
using namespace std;
extern int s;
extern int totalCostSearch;

class BinarySearchTree 
{ // uses the class BinaryNode
	//friend class BinaryNode;
	private:
	BinaryNode* root;
	BinaryNode* find(int x, BinaryNode* t);
	BinaryNode* findMin(BinaryNode *t);
	BinaryNode* insert(int x, BinaryNode* t);
	BinaryNode* remove(int x, BinaryNode* t);
	BinaryNode* removeMin(BinaryNode *t);
	/* void InOrder(BinaryNode*);
	void PreOrder(BinaryNode*);
	void PostOrder(BinaryNode*); */
	
	public:
	// constructor
	BinarySearchTree( ) { root = NULL; }
	~BinarySearchTree( ) { deleteTree(root); root = NULL; }
	void deleteTree(BinaryNode* t);
	int size() const { return (root==NULL) ? 0 : root->size();}
	int height() {return (root==NULL) ? 0 : root->height();}
	void insert(int x) { root = insert(x, root); }
	void remove(int x) { root = remove(x, root); }
	BinaryNode *find(int x) { return find(x, root); }
	bool isEmpty( ){ return root == NULL; }
	BinaryNode* getRoot() const { return root;}
	void removeMin() {root = root->removeMin(); }
	/* void InOrder() {InOrder(root);}
	void PreOrder() {PreOrder(root);}
	void PostOrder() {PostOrder(root);} */
	int totalCost() { return root == nullptr ? 0 : root->totalCost(); }
};

 ostream& operator<<(ostream& out_this, const BinarySearchTree& my_tree);
 

