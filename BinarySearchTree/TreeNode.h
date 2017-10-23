/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/18/15
*File: TreeNode.h
*Course: EECS560 - Data Structure
*Project: Lab4 - Binary Search Tree
***********************************************************/

#ifndef TREENODE_H_
#define TREENODE_H_
#include <iostream>

class TreeNode
{
private:
	int item;
	TreeNode* leftChild;
	TreeNode* rightChild;

public:

	TreeNode();

	TreeNode(int newItem);

	TreeNode(int newItem, TreeNode* left, TreeNode* right);

	~TreeNode();

	int getItem();

	void setItem(int newItem);

	TreeNode* getLeftChild();

	void setLeftChild(TreeNode* leftPtr);

	TreeNode* getRightChild();

	void setRightChild(TreeNode* rightPtr);
};

#endif;

