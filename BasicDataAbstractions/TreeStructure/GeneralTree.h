/* Author: Wei Fei
 * KUID: 2538810
 * Date: 12/03/13
 * FileName: GeneralTree.h
 * Description: the header file of GeneralTree.cpp.
 */

#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "TreeNode.h"

template<class ItemType>
class GeneralTree {
public:
    /**
     * Default constructor
     */
    GeneralTree();

    /**
     * Destructor
     */
    ~GeneralTree();

    /**
     * Loads the tree from the file
     *
     * @param filename the input file
     */
    void loadTree(std::string filename);

    /**
     * Exports the tree to a file
     */
    void exportToFile();

    /**
     * Prints out the tree
     */
    void print();

    /**
     * Prints out all the parent nodes
     *
     * @param the child id
     */
    void printParent(int childId);

    /**
     * Prints out all the child nodes
     *
     * @param the parent id
     */
    void printChildren(int parentId);

    /**
     * Prints out all the sibling nodes
     *
     * @param the node id
     */
    void printSiblings(int nodeId);

    /**
     * Add a new child to be the first child of the given parents
     *
     * @param parentId the parent id
     * @param childId the child id
     */
    void addFirst(int parentId, int childId);

    /**
     * Add a new child to be the last child of the given parents
     *
     * @param parentId the parent id
     * @param childId the child id
     */
    void addLast(int parentId, int childId);

    /**
     * Removes all the nodes matching the given id
     *
     * @param nodeId the node id to be removed
     */
    void removeNode(int nodeId);

private:
    /**
     * Exports the tree to a file recursively
     *
     * @param out the output stream
     * @param node the current node
     */
    void exportToFile(std::ostream& out, TreeNode<ItemType> *node);

    /**
     * Finds the parent node recursively
     *
     * @param parent the current node
     * @param child the child node
     * @param parent of the child
     */
    TreeNode<ItemType> *findParent(TreeNode<ItemType> *parent,
            TreeNode<ItemType> *child);

    /**
     * Prints out the tree recursively
     *
     * @param node the current node
     * @param depth the depth of recursion
     */
    void print(TreeNode<ItemType> *node, int depth);

    /**
     * Adds a new node to be the first child of the parent node
     *
     * @param parent the current node
     * @param child the new child Id
     * @param a new created node
     */
    TreeNode<ItemType> *addFirst(TreeNode<ItemType> *node, int child);

    /**
     * Adds a new node to be the last child of the parent node
     *
     * @param parent the current node
     * @param child the new child Id
     * @param a new created node
     */
    TreeNode<ItemType> *addLast(TreeNode<ItemType> *node, int child);

    /**
     * Finds all the nodes matching the key
     *
     * @param node the current node
     * @param key the given key
     * @param vec vector of the searching results
     */
    void findAllNodes(TreeNode<ItemType> *node, ItemType key,
            std::vector<TreeNode<ItemType> *>& vec);

    /**
     * Deletes all the nodes recursively
     *
     * @param node the node to be deleted
     */
    void deleteNode(TreeNode<ItemType> *node);

    // The root node
    TreeNode<ItemType> *root;

    // The input file
    std::string filename;
};

#include "GeneralTree.cpp"

#endif
