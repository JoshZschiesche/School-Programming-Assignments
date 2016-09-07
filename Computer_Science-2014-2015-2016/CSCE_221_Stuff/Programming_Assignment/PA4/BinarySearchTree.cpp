#ifndef BST
#define BST
#include "BinarySearchTree.h"
int s = 1;
int totalCostSearch = 0;

BinaryNode *BinarySearchTree::find(int x, BinaryNode *t) //throw(ItemNotFound )
{
	while (t != NULL) 
	{
		if (x < t->getElem()) t = t->getLeft();
		else if (x > t->getElem()) t = t->getRight();
		else return t;
	}
}

void BinarySearchTree::deleteTree(BinaryNode *root)
{
	if (root == NULL) return;
	if (root->left != NULL)
	deleteTree(root->left);
	if (root->right != NULL)
	deleteTree(root->right);
	delete root;
}

ostream& operator<<(ostream& out_this, const BinarySearchTree& my_tree)
{
	int print_restriction = pow(2.0,4.0);
	deque<BinaryNode*> q;
	int tree_size = my_tree.size();
	int line = 0;
	BinaryNode* p;
	q.push_front(my_tree.getRoot());
	int count = 0;
	
	while (tree_size > 0)
	{
		p = q.front();
		q.pop_front();
		
		if (p != NULL)
		{
			out_this << p->getElem();
			++count;
			--tree_size;
			q.push_back(p->getLeft());
			q.push_back(p->getRight());
		}
		else
		{
			out_this << "X";
			q.push_back(NULL);
			q.push_back(NULL);
			++count;
		}
		
		if (count == pow(2,line))
		{
			out_this << endl;
			++line;
			count = 0;
		}
	}
}

BinaryNode *BinarySearchTree::insert(int x, BinaryNode *t)
{
	if (t == NULL)
	{ 
		t = new BinaryNode(x);
		t->search_cost = s;
	}
	else if (x < t->element)
	{
		++s;
		t->left = insert(x, t->left);
	}
	else if (x > t->element)
	{
		++s;
		t->right = insert(x, t->right);
	}
	else
	{
		s=1;
		throw std::out_of_range ("Out Of Range");
	}
	//s=1;
	return t;
}

BinaryNode *BinarySearchTree::removeMin(BinaryNode *t)
{
	if (t == NULL) throw std::out_of_range ("Out Of Range");
	if (t->left != NULL)
		t->left = removeMin(t->left);
	else 
	{
		BinaryNode *node = t;
		t = t->right;
		//t->search_cost=((t->search_cost)-1);
		delete node;
	}
	return t;
}

BinaryNode *BinarySearchTree::remove(int x, BinaryNode *t)
{
	if (t == NULL);
	if (x < t->element)
		t->left = remove(x, t->left);
	else if (x > t->element)
		t->right = remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) 
	{
		t->element = findMin(t->right)->element;
		t->right = removeMin(t->right);
	} 
	else 
	{ 
		BinaryNode *node = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete node;
	}
	return t;
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *t)
{
	if (t == NULL);
	while (t->left != NULL) t = t->left;
	return t;
}
 #endif