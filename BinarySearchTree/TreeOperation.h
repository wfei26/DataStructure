/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/18/15
*File: TreeOperation.h
*Course: EECS560 - Data Structure
*Project: Lab4 - Binary Search Tree
***********************************************************/

#ifndef TREEOPERATION_H_
#define TREEOPERATION_H_
#include <iostream>
#include <string>
#include <fstream>
#include "TreeNode.h"

class TreeOperation
{
private:
	TreeNode* BinaryTreeRoot;
	TreeNode* leftNode;
	TreeNode* rightNode;
	TreeNode** queue;
	int nodeNumber;

public:
	/*
	* Constructor with the size of list and the position of node
	* @param BinaryTreeRoot    the root of tree
	* @param leftNode          left node of parent node (using in remove function)
	* @param rightNode         right node of parent node (using in remove function)
	* @param queue			   use queue to store every element in tree and traverse in level order
	* @param nodeNumber        total number of tree nodes
	*/
	TreeOperation();


	/*
	* Destructor
	*/
	~TreeOperation();


	/*
	* Read all item entries from the file and insert them into hash table by hashing algorithm
	* @return     the root of binary tree
	*/
	TreeNode* readfile();


	/*
	* Insert an element into the binary tree recursively
	* @param newItem    the value of new entry
	* @param curNode    the pointer points the current node
	* @return		    the root of the binary tree
	*/
	TreeNode* insert(const int newItem, TreeNode* curNode);


	/*
	* Delete an node of the binary tree
	* @param newItem    the value of new entry
	* @param curNode    the pointer points the current node
	* @return true		if remove success
	*         false     if remove fail
	*/
	bool remove(const int deleteItem);


	/*
	* Search an element in the binary tree recursively
	* @param newItem    the value of searching entry
	* @param curNode    the pointer points the current node
	* @return		    the parent of searching node
	*/
	TreeNode* search(const int newItem, TreeNode* curNode);


	/*
	* Delete the minimum number in the binary tree recursively
	* @param parentNode    the pointer points the parent of current node
	* @param curNode       the pointer points the current node
	* @return		       the value of minimum number in the tree
	*/
	int deletemin(TreeNode* parentNode, TreeNode* curNode);


	/*
	* Delete the maximum number in the binary tree recursively
	* @param parentNode    the pointer points the parent of current node
	* @param curNode       the pointer points the current node
	* @return		       the value of maximum number in the tree
	*/
	int deletemax(TreeNode* parentNode, TreeNode* curNode);


	/*
	* Print the whole binary tree in preorder traversal recursively
	* @param curNode       the pointer points the current node
	*/
	void preorder(TreeNode* curNode);


	/*
	* Print the whole binary tree in inorder traversal recursively
	* @param curNode       the pointer points the current node
	*/
	void inorder(TreeNode* curNode);


	/*
	* Print the whole binary tree in levelorder traversal by using queue (array-based implementation)
	* @param curNode       the pointer points the current node
	*/
	void levelorder(TreeNode* curNode);


	/*
	* Combine all functions to execute the program
	*/
	void finalOutput();
};

#endif;