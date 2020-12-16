#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct AVLNode
{
	int m_data;
	AVLNode* m_left;
	AVLNode* m_right;
	int m_height;
	AVLNode(int data)
	{
		m_data = data;
		m_left = NULL;
		m_right = NULL;
		m_height = 1;
	}
};
class AVLTree
{
private:
	AVLNode* m_root;

	void addKey(AVLNode*&, int);
	void LNR(AVLNode*);
	AVLNode* findKey(AVLNode*, int);
	void removeKey(AVLNode*&, int);
	void replace(AVLNode*&, int);
	AVLNode* findLeftMost(AVLNode*);
	bool isAVL(AVLNode*);
	int getHeight(AVLNode*);
	int getBalance(AVLNode*);
	int countNode(AVLNode*);
	void leftRotate(AVLNode*&);
	void rightRotate(AVLNode*&);
	void reBalance(AVLNode*&);
	void updateHeight(AVLNode*&);
	void removeEven(AVLNode*&);
	void printMinMax(AVLNode*,vector<int>&);
	int countFind(AVLNode*, int, int);
public:
	AVLTree();
	~AVLTree();
	bool isEmpty();
	void deleteAVL(AVLNode*&);
	void addKey(int);
	void LNR();
	AVLNode* findKey(int);
	void removeKey(int);
	bool isAVL();
	int getHeight();
	int countNode();
	void removeEven();
	void printMinMax();
	int countFind(int);
};

