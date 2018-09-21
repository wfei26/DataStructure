//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */

#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <stdlib.h>

template<class ItemType>
class TreeNode {
private:
    ItemType item;           // Data portion
    TreeNode<ItemType> *firstChildPtr;   // Pointer to left child
    TreeNode<ItemType> *siblingPtr;  // Pointer to right child

public:
    TreeNode(const ItemType& anItem) :
    item(anItem), firstChildPtr(NULL), siblingPtr(NULL) {
    }

    ItemType getItem() const {
        return item;
    }

    TreeNode<ItemType> *getFirstChildPtr() const {
        return firstChildPtr;
    }

    TreeNode<ItemType> *getSiblingPtr() const {
        return siblingPtr;
    }

    void setFirstChildPtr(TreeNode<ItemType> *leftPtr) {
        firstChildPtr = leftPtr;
    }

    void setSiblingPtr(TreeNode<ItemType> *rightPtr) {
        siblingPtr = rightPtr;
    }
}; // end BinaryNode

#endif

