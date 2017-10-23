/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/18/15
*File: TreeOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab4 - Binary Search Tree
***********************************************************/

#include "TreeOperation.h"
using namespace std; 


/*
* Constructor with the size of list and the position of node
* @param BinaryTreeRoot    the root of tree
* @param leftNode          left node of parent node (using in remove function)
* @param rightNode         right node of parent node (using in remove function)
* @param queue			   use queue to store every element in tree and traverse in level order
* @param nodeNumber        total number of tree nodes
*/
TreeOperation::TreeOperation()
{
	BinaryTreeRoot = NULL;
	leftNode = NULL;
	rightNode = NULL;
	queue = NULL;
	nodeNumber = 0;
}


/*
* Destructor
*/
TreeOperation::~TreeOperation()
{
	TreeNode* myParentNode = NULL;
	for (int i = 0; i < nodeNumber; i++)
	{
		deletemin(myParentNode, BinaryTreeRoot);
	}
}


/*
* Read all item entries from the file and insert them into hash table by hashing algorithm
* @return     the root of binary tree
*/
TreeNode* TreeOperation::readfile()
{
	ifstream file;
	file.open("data.txt");
	if (!file)
	{
		cout << "Error! File does not exist." << endl;
	}
	else
	{
		int newEntry;
		//read each number and insert them into list one by one
		while (file >> newEntry)
		{
			insert(newEntry, BinaryTreeRoot);
		}
	}
	file.close();
	return BinaryTreeRoot;
}


/*
* Insert an element into the binary tree recursively
* @param newItem    the value of new entry
* @param curNode    the pointer points the current node
* @return		    the root of the binary tree
*/
TreeNode* TreeOperation::insert(const int newItem, TreeNode* curNode)
{

	if (BinaryTreeRoot == NULL)
	{
		BinaryTreeRoot = new TreeNode(newItem);
		nodeNumber++;
		return BinaryTreeRoot;
	}
	else if (curNode->getItem() > newItem)
	{
		if (curNode->getLeftChild() == NULL)
		{
			TreeNode* newNode = new TreeNode(newItem);
			curNode->setLeftChild(newNode);
			nodeNumber++;
		}
		else
		{
			insert(newItem, curNode->getLeftChild());
		}
	}
	else if (curNode->getItem() < newItem)
	{
		if (curNode->getRightChild() == NULL)
		{
			TreeNode* newNode = new TreeNode(newItem);
			curNode->setRightChild(newNode);
			nodeNumber++;
		}
		else
		{
			insert(newItem, curNode->getRightChild());
		}
	}
	return BinaryTreeRoot;
}


/*
* Delete an node of the binary tree
* @param newItem    the value of new entry
* @param curNode    the pointer points the current node
* @return true		if remove success
*         false     if remove fail
*/
bool TreeOperation::remove(const int deleteItem)
{
	if (BinaryTreeRoot == NULL)
	{
		cout << "The tree is empty, no any items can be deleted!" << endl;
		return false;
	}
	else
	{
		nodeNumber--;
		//if the item is in root
		if (BinaryTreeRoot->getItem() == deleteItem)
		{
			if ((BinaryTreeRoot->getLeftChild() != NULL) || (BinaryTreeRoot->getRightChild() != NULL))
			{
				BinaryTreeRoot->setItem(deletemin(BinaryTreeRoot, BinaryTreeRoot->getRightChild()));
			}
			else
			{
				delete BinaryTreeRoot;
				BinaryTreeRoot = NULL;
			}
		}
		//if the item is not in root
		else
		{
			TreeNode* myParentNode = search(deleteItem, BinaryTreeRoot);
			if (myParentNode->getLeftChild() != NULL)
			{
				leftNode = myParentNode->getLeftChild();
				//if the delete node has no children (leaf), delete it directly
				if ((leftNode->getLeftChild() == NULL) && (leftNode->getRightChild() == NULL))
				{
					if (leftNode->getItem() == deleteItem)
					{
						delete leftNode;
						leftNode = NULL;
						myParentNode->setLeftChild(NULL);
					}
				}
				//if the node has right child but no left child
				else if ((leftNode->getLeftChild() == NULL) && (leftNode->getItem() == deleteItem))
				{
					myParentNode->setLeftChild(leftNode->getRightChild());
				}
				//if the node has left child but no right child
				else if ((leftNode->getRightChild() == NULL) && (leftNode->getItem() == deleteItem))
				{
					myParentNode->setLeftChild(leftNode->getLeftChild());
				}
				//if the node has both of left and right child 
				else if ((leftNode->getLeftChild() != NULL) && (leftNode->getRightChild() != NULL) && (leftNode->getItem() == deleteItem))
				{
					leftNode->setItem(deletemin(leftNode, leftNode->getRightChild()));
				}
			}
			if (myParentNode->getRightChild() != NULL)
			{
				rightNode = myParentNode->getRightChild();
				//if the delete node has no children (leaf), delete it directly
				if ((rightNode->getLeftChild() == NULL) && (rightNode->getRightChild() == NULL))
				{
					if (rightNode->getItem() == deleteItem)
					{
						delete rightNode;
						rightNode = NULL;
						myParentNode->setRightChild(NULL);
					}
				}
				//if the node has right child but no left child
				else if ((rightNode->getLeftChild() == NULL) && (rightNode->getItem() == deleteItem))
				{
					myParentNode->setRightChild(rightNode->getRightChild());
				}
				//if the node has left child but no right child
				else if ((rightNode->getRightChild() == NULL) && (rightNode->getItem() == deleteItem))
				{
					myParentNode->setRightChild(rightNode->getLeftChild());
				}
				//if the node has both of left and right child 
				else if ((rightNode->getLeftChild() != NULL) && (rightNode->getRightChild() != NULL) && (rightNode->getItem() == deleteItem))
				{
					rightNode->setItem(deletemin(rightNode, rightNode->getRightChild()));
				}
			}
		}
		return true;
	}
}
			

/*
* Search an element in the binary tree recursively
* @param newItem    the value of searching entry
* @param curNode    the pointer points the current node
* @return		    the parent of searching node
*/
TreeNode* TreeOperation::search(const int newItem, TreeNode* curNode)
{
	if (curNode == NULL)
	{
		return NULL;
	}
	else if ((curNode->getLeftChild() == NULL) && (curNode->getRightChild() == NULL))
	{
		return NULL;
	}
	else
	{
		if (BinaryTreeRoot->getItem() == newItem)
		{
			return BinaryTreeRoot;
		}
		else if (((curNode->getLeftChild() != NULL) && (curNode->getLeftChild()->getItem() == newItem)) || ((curNode->getRightChild() != NULL) && (curNode->getRightChild()->getItem() == newItem)))
		{
			return curNode;
		}
		else if (curNode->getItem() > newItem)
		{
			TreeNode* nextleftNode = search(newItem, curNode->getLeftChild());
			return nextleftNode;
		}
		else if (curNode->getItem() < newItem)
		{
			TreeNode* nextRightNode = search(newItem, curNode->getRightChild());
			return nextRightNode;
		}
	}
}


/*
* Delete the minimum number in the binary tree recursively
* @param parentNode    the pointer points the parent of current node
* @param curNode       the pointer points the current node
* @return		       the value of minimum number in the tree
*/
int TreeOperation::deletemin(TreeNode* parentNode, TreeNode* curNode)
{
	if (curNode == NULL)
	{
		cout << "The tree is empty, no any items can be deleted!" << endl;
		return -1;
	}
	else if ((curNode == BinaryTreeRoot) && (BinaryTreeRoot->getLeftChild() == NULL))
	{
		int rootValue = BinaryTreeRoot->getItem();
		TreeNode* newBinaryTreeRoot = BinaryTreeRoot->getRightChild();
		delete BinaryTreeRoot;
		BinaryTreeRoot = newBinaryTreeRoot;
		nodeNumber--;
		return rootValue;
	}
	else if (curNode->getLeftChild() == NULL)
	{
		int deletedValue = 0;
		deletedValue = curNode->getItem();
		parentNode->setRightChild(curNode->getRightChild());
		delete curNode;
		curNode = NULL;
		nodeNumber--;
		return deletedValue;
	}
	else if (curNode->getLeftChild()->getLeftChild() != NULL)
	{
		return deletemin(curNode, curNode->getLeftChild());
	}
	else
	{
		int deleteValue = 0;
		deleteValue = curNode->getLeftChild()->getItem();
		TreeNode* tempNode = curNode->getLeftChild();
		//connect the right child of deleted node (minimum node) with current node
		curNode->setLeftChild(curNode->getLeftChild()->getRightChild());
		delete tempNode;
		tempNode = NULL;
		nodeNumber--;
		return deleteValue;
	}
}


/*
* Delete the maximum number in the binary tree recursively
* @param parentNode    the pointer points the parent of current node
* @param curNode       the pointer points the current node
* @return		       the value of maximum number in the tree
*/
int TreeOperation::deletemax(TreeNode* parentNode, TreeNode* curNode)
{
	if (curNode == NULL)
	{
		cout << "The tree is empty, no any items can be deleted!" << endl;
		return -2;
	}
	else if ((curNode == BinaryTreeRoot) && (curNode->getRightChild() == NULL))
	{
		int rootValue = BinaryTreeRoot->getItem();
		TreeNode* newBinaryTreeRoot = BinaryTreeRoot->getLeftChild();
		delete BinaryTreeRoot;
		BinaryTreeRoot = newBinaryTreeRoot;
		nodeNumber--;
		return rootValue;
	}
	else if (curNode->getRightChild() == NULL)
	{
		int deletedValue = 0;
		deletedValue = curNode->getItem();
		parentNode->setLeftChild(curNode->getLeftChild());
		delete curNode;
		curNode = NULL;
		nodeNumber--;
		return deletedValue;
	}
	else if (curNode->getRightChild()->getRightChild() != NULL)
	{
		return deletemax(curNode, curNode->getRightChild());
	}
	else
	{
		int deleteValue = 0;
		deleteValue = curNode->getRightChild()->getItem();
		TreeNode* tempNode = curNode->getRightChild();
		//connect the left child of deleted node (minimum node) with current node
		curNode->setRightChild(curNode->getRightChild()->getLeftChild());
		delete tempNode;
		tempNode = NULL;
		nodeNumber--;
		return deleteValue;
	}
}


/*
* Print the whole binary tree in preorder traversal recursively
* @param curNode       the pointer points the current node
*/
void TreeOperation::preorder(TreeNode* curNode)
{
	if (curNode != NULL)
	{
		cout << curNode->getItem() << " ";
		preorder(curNode->getLeftChild());
		preorder(curNode->getRightChild());
	}
}


/*
* Print the whole binary tree in inorder traversal recursively
* @param curNode       the pointer points the current node
*/
void TreeOperation::inorder(TreeNode* curNode)
{
	if (curNode != NULL)
	{
		inorder(curNode->getLeftChild());
		cout << curNode->getItem() << " ";
		inorder(curNode->getRightChild());
	}
}


/*
* Print the whole binary tree in levelorder traversal by using queue (array-based implementation)
* @param curNode       the pointer points the current node
*/
void TreeOperation::levelorder(TreeNode* curNode)
{
	if (BinaryTreeRoot != NULL)
	{
		//use array-based implementation to implement queue for traversing in level order
		TreeNode** queue = new TreeNode* [2 * nodeNumber];
		int head = 0, end= 0;
		queue[head] = BinaryTreeRoot;
	
		for (head; head <= end; head++)
		{
			if (queue[head] != NULL)
			{
				cout << queue[head]->getItem() << " ";
				queue[end + 1] = queue[head]->getLeftChild();
				queue[end + 2] = queue[head]->getRightChild();
				end = end + 2;
			}
		}
	}
}


/*
* Combine all functions to execute the program
*/
void TreeOperation::finalOutput()
{
	cout << "Welcome to use my program!\n" << endl;
	int index = 0;
	readfile();

	while (index != 8)
	{
		cout << "..............................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - remove\n3 - deletemin\n4 - deletemax\n5 - preorder\n6 - inorder\n7 - levelorder\n8 - exit\n" << endl;
		cout << "Your choice: ";
		cin >> index;

		if (index == 1)
		{
			int newInsertItem;
			cout << "Please insert the number that you want to be inserted in the tree:" << endl;
			cin >> newInsertItem;
			insert(newInsertItem, BinaryTreeRoot);
			cout << endl;
		}

		if (index == 2)
		{
			//check if the tree is empty
			if (BinaryTreeRoot == NULL)
			{
				cout << "The binary tree has no items can be deleted!\n" << endl;
			}
			else
			{
				int deleteNum;
				cout << "Which number do you like to remove from the tree:" << endl;
				cin >> deleteNum;
				TreeNode* tempNode = search(deleteNum, BinaryTreeRoot);
				if (tempNode == NULL)
				{
					cout << deleteNum << " is not in the tree.\n" << endl;
				}
				else
				{
					bool ifSuccess = remove(deleteNum);
					if (ifSuccess == false)
					{
						cout << "Remove failed!" << endl;
					}
					cout << endl;
				}
			}
		}

		if (index == 3)
		{
			TreeNode* myParentNode = NULL;
			deletemin(myParentNode, BinaryTreeRoot);
			cout << endl;
		}

		if (index == 4)
		{
			TreeNode* myParentNode = NULL;
			deletemax(myParentNode, BinaryTreeRoot);
			cout << endl;
		}

		if (index == 5)
		{
			cout << "preorder: ";
			preorder(BinaryTreeRoot);
			cout << "\n" << endl;
		}

		if (index == 6)
		{
			cout << "inorder: ";
			inorder(BinaryTreeRoot);
			cout << "\n" << endl;
		}

		if (index == 7)
		{
			cout << "levelorder: ";
			levelorder(BinaryTreeRoot);
			cout << "\n" << endl;
		}

		if ((index < 1) || (index > 8))
		{
			cout << "Ooooops, typo! Please type the number 1 to 8." << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}