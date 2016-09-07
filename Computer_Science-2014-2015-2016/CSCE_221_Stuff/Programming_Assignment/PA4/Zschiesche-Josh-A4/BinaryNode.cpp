#include "BinaryNode.h"
#include <algorithm>

int BinaryNode::getSC()
{
	return search_cost;
}

BinaryNode *BinaryNode::copy( ) 
{
	BinaryNode *root = new BinaryNode(element);
	if (left != NULL)
		root->left = left->copy();

	if (right != NULL)
		root->right = right->copy();

	return root;
}

int size(const BinaryNode* n)
{
	return n ? n->size() : 0;
}
int height(const BinaryNode* n)
{
	return n ? n->height() : 0;
}
int totalCost(const BinaryNode* n)
{
	return n ? n->totalCost() : 0;
}

int BinaryNode::size() const
{
	return 1 + ::size(left) + ::size(right);
}
int BinaryNode::totalCost() const
{
	return search_cost + ::totalCost(left) + ::totalCost(right);
}
int BinaryNode::height() const
{ 
	return 1 + std::max(::height(left), ::height(right));
}

BinaryNode *BinaryNode::insert(int x)
{
	const int e = getElem();
	if(e < x)
	{
		if(left == nullptr)
			left = new BinaryNode(x, search_cost+1);
		else
			left->insert(x);
	}
	else
	{
		if(right == nullptr)
			right = new BinaryNode(x, search_cost+1);
		else
			right->insert(x);
	}
}

BinaryNode *BinaryNode::remove(int x)
{
	
	if (this == NULL)
	{
		cerr << "Item Not Found" << endl;
	}
	
	if (x < getElem())
	left = remove(x);

	else if (x > this->getElem())
	right = remove(x);

	else if (left != NULL && right != NULL) 
	{
		element = right->findMin()->getElem();
		right = right->removeMin();
	} 
	else 
	{ 
		BinaryNode *node = this;
		if(left != NULL)
		{return left;} 
		else{return right;}
		delete node;
	}
	return this;
}

BinaryNode *BinaryNode::findMin()
{
	if (this == NULL)
	{
		cerr << "This tree was empty" << endl;
		return NULL;
	}
	while (left != NULL) return left;
	return this;
}

BinaryNode *BinaryNode::removeMin()
{
	if (this == NULL)
	{
		cerr << "Item Not Found" << endl;
		return NULL;
	}
	
	if (left != NULL)
	return removeMin();

	else 
	{
		BinaryNode *node = this;
		return right;
		delete node;
	}
	return this;
}

