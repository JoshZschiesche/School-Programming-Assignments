#include <cstddef> // to define NULL
#include <iostream>
using namespace std;

class TreeOperation 
{
	public:
	virtual void processNode(int elem) = 0;
};

class PrintTreeNode : public TreeOperation
{
public:
void processNode(int element) {
cout << element << " ";
}
};

class BinaryNode 
{
	private:
	friend class BinarySearchTree;
	int element; //key = element
	int search_cost;
	BinaryNode *left, *right;
	
	public:
	//constructor
	BinaryNode(int el=0, int sc = 0, BinaryNode *lt=NULL,
		BinaryNode *rt=NULL) :
		element(el), left(lt), right(rt), search_cost(sc) { }
	// member functions
	BinaryNode *getLeft() { return left; }
	BinaryNode *getRight() { return right; }
	int getElem() { return element; }
	int getSC();
	int size() const;
	int height() const;
	int totalCost() const;
	BinaryNode* insert(int x);
	BinaryNode* remove(int x);
	BinaryNode *copy();
	BinaryNode* removeMin();
	BinaryNode* findMin();

	void preOrderTraversal(TreeOperation& op)
	{
		op.processNode(element);
		if (left != NULL) left->preOrderTraversal(op);
		if (right != NULL) right->preOrderTraversal(op);
	}

	void inOrderTraversal(TreeOperation& op)
	{
		if (left != NULL) left->inOrderTraversal(op);
		op.processNode(element);
		if (right != NULL) right->inOrderTraversal(op);
	}

	void postOrderTraversal(TreeOperation& op)
	{
		if (left != NULL) left->postOrderTraversal(op);
		if (right != NULL) right->postOrderTraversal(op);
		op.processNode(element);
	}
};