#include "AVLTree.h"
AVLTree::AVLTree()
{
	m_root = NULL;
}
AVLTree::~AVLTree()
{
	deleteAVL(m_root);
	m_root = NULL;
}
bool AVLTree::isEmpty()
{
	return m_root == NULL;
}
void AVLTree::deleteAVL(AVLNode*& n)
{
	if (n == NULL)
		return;
	deleteAVL(n->m_left);
	deleteAVL(n->m_right);
	delete n;
}
void AVLTree::addKey(int key)
{
	return addKey(m_root, key);
}
void AVLTree::addKey(AVLNode*& n, int key)
{
	if (n == NULL)
	{
		n = new AVLNode(key);
		return;
	}
	if (key < n->m_data)
		addKey(n->m_left, key);
	else
		addKey(n->m_right, key);
	updateHeight(n);
	reBalance(n);
}
void AVLTree::LNR(AVLNode*n)
{
	if (n)
	{
		LNR(n->m_left);
		cout << n->m_data << " ";
		LNR(n->m_right);
	}
}
void AVLTree::LNR()
{
	LNR(m_root);
}
AVLNode* AVLTree::findKey(int key)
{
	return findKey(m_root, key);
}
AVLNode* AVLTree::findKey(AVLNode* n, int key)
{
	if (!n)
		return NULL;
	if(key < n->m_data)
		return findKey(n->m_left, key);
	if (key > n->m_data)
		return findKey(n->m_right, key);
	return n;
}
void AVLTree::removeKey(int key)
{
	if (findKey(key) == NULL)
		return;
	removeKey(m_root, key);
}
void AVLTree::removeKey(AVLNode*& n, int key)
{
	if (key < n->m_data)
		removeKey(n->m_left, key);
	else if (key > n->m_data)
		removeKey(n->m_right, key);
	else
		replace(n, key);
	updateHeight(n);
	reBalance(n);
}
void AVLTree::reBalance(AVLNode*& n)
{
	int balance = getBalance(n);
	if (balance > 1)
	{
		if (getBalance(n->m_left) >= 0)
			rightRotate(n);
		else
		{
			leftRotate(n->m_left);
			rightRotate(n);
		}
	}
	else if (balance < -1)
	{
		if (getBalance(n->m_right) <= 0)
			leftRotate(n);
		else
		{
			rightRotate(n->m_right);
			leftRotate(n);
		}
	}
}
void AVLTree::replace(AVLNode*& n, int key)
{
	if (!n->m_left)
	{
		AVLNode* rep = n->m_right;
		delete n;
		n = rep;
	}
	else if (!n->m_right)
	{
		AVLNode* rep = n->m_left;
		delete n;
		n = rep;
	}
	else
	{
		AVLNode* rep = findLeftMost(n->m_right);
		swap(n->m_data, rep->m_data);
		removeKey(n->m_right, key);
	}
}
AVLNode* AVLTree::findLeftMost(AVLNode* n)
{
	if (n->m_left)
		return findLeftMost(n->m_left);
	return n;
}
bool AVLTree::isAVL()
{
	return isAVL(m_root);
}
bool AVLTree::isAVL(AVLNode* n)
{
	if (!n)
		return true;
	int left = getHeight(n->m_left);
	int right = getHeight(n->m_right);
	return abs(getBalance(n)) <= 1 && isAVL(n->m_left) && isAVL(n->m_right);
}
int AVLTree::getHeight()
{
	return getHeight(m_root);
}
int AVLTree::getHeight(AVLNode* n)
{
	if (!n)
		return 0;
	int h1 = getHeight(n->m_left);
	int h2 = getHeight(n->m_right);
	return (h1 > h2 ? h1 : h2) + 1;
}
int AVLTree::getBalance(AVLNode* n)
{
	if (!n)
		return 0;
	return getHeight(n->m_left) - getHeight(n->m_right);
}
int AVLTree::countNode()
{
	return countNode(m_root);
}
int AVLTree::countNode(AVLNode* n)
{
	if (!n)
		return 0;
	return countNode(n->m_left) + countNode(n->m_right) + 1;
}
void AVLTree::leftRotate(AVLNode*& x)
{
	AVLNode* y = x->m_right;
	AVLNode* T2 = y->m_left;
	y->m_left = x;
	x->m_right = T2;
	updateHeight(x);
	updateHeight(y);
	x = y;
}
void AVLTree::rightRotate(AVLNode*& y)
{
	AVLNode* x = y->m_left;
	AVLNode* T2 = x->m_right;
	x->m_right = y;
	y->m_left = T2;
	updateHeight(y);
	updateHeight(x);
	y = x;
}
void AVLTree::updateHeight(AVLNode*& n)
{
	if (n == NULL)
		return;
	n->m_height = getBalance(n);
}
void AVLTree::removeEven()
{
	removeEven(m_root);
}
void AVLTree::removeEven(AVLNode*& n)
{
	if (n)
	{
		removeEven(n->m_left);
		removeEven(n->m_right);
		if (n->m_data % 2 == 0)
			removeKey(n, n->m_data);
	}
}
void AVLTree::printMinMax(AVLNode* n, vector<int> &v)
{
	if (!n)
		return;
	printMinMax(n->m_left, v);
	v.push_back(n->m_data);
	printMinMax(n->m_right, v);	
}
void AVLTree::printMinMax()
{
	vector<int> v;
	printMinMax(m_root, v);
	int i = 0;
	int index = v.size() - 1;
	while (i < index)
		cout << v[i++] << " " << v[index--] << " ";
	if (i == index)
		cout << v[i];
}
int AVLTree::countFind(AVLNode* n, int key, int count)
{
	count++;
	if (n == NULL)
		return count;
	if (key < n->m_data)
		return countFind(n->m_left, key, count);
	if (key > n->m_data)
		return countFind(n->m_right, key, count);
	return count;
}
int AVLTree::countFind(int key)
{
	return countFind(m_root, key, 0);
}
