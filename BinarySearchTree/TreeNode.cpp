/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/18/15
*File: TreeNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab4 - Binary Search Tree
***********************************************************/

#include "TreeNode.h"


TreeNode::TreeNode()
{
	item = 0;
	leftChild = NULL;
	rightChild = NULL;
}

TreeNode::TreeNode(int newItem)
{
	item = newItem;
	leftChild = NULL;
	rightChild = NULL;
}

TreeNode::TreeNode(int newItem, TreeNode* left, TreeNode* right)
{
	item = newItem;
	leftChild = left;
	rightChild = right;
}

TreeNode::~TreeNode()
{
}

int TreeNode::getItem()
{
	return item;
}

void TreeNode::setItem(int newItem)
{
	item = newItem;
}

TreeNode* TreeNode::getLeftChild()
{
	return leftChild;
}

void TreeNode::setLeftChild(TreeNode* leftPtr)
{
	leftChild = leftPtr;
}

TreeNode* TreeNode::getRightChild()
{
	return rightChild;
}

void TreeNode::setRightChild(TreeNode* rightPtr)
{
	rightChild = rightPtr;
}