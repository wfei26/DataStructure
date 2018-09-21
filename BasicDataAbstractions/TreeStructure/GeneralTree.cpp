/* Author: Wei Fei
 * KUID: 2538810
 * Date: 12/03/13
 * FileName: GeneralTree.cpp
 * Description: edit all operations of trees.
 */

//#include "GeneralTree.h"

/**
 * Default constructor
 */
template<class ItemType>
GeneralTree<ItemType>::GeneralTree() : root(NULL) {
}

/**
 * Destructor
 */
template<class ItemType>
GeneralTree<ItemType>::~GeneralTree() {
    deleteNode(root);
}

/**
 * Loads the tree from the file
 *
 * @param filename the input file
 */
template<class ItemType>
void GeneralTree<ItemType>::loadTree(std::string filename) {
    this->filename = filename;
    std::ifstream in(filename.c_str());
    if (!in) {
        std::cout << "Error: " << filename << " is not found" << std::endl;
        exit(0);
    }

    // Create a stack of nodes
    std::stack<TreeNode<ItemType> *> stack;
    char c;
    int id;
    while ((c = in.get()) != EOF) {
        if (c == '(') {
            // When a left bracket is read, read a node id
            in >> id;
            if (stack.empty()) {
                // If the stack is empty, create the root node, push it to the stack
                stack.push(root = new TreeNode<ItemType>(id));

            } else {
                // Get the top node from the stack
                TreeNode<ItemType> *parent = stack.top();
                // Create a new node to be the last child of it
                stack.push(addLast(parent, id));
            }

        } else if (c == ')') {
            // When a right bracket is read, pop a node from the stack
            stack.pop();
        }
    }

    // Close the file
    in.close();
}

/**
 * Exports the tree to a file
 */
template<class ItemType>
void GeneralTree<ItemType>::exportToFile() {
    std::ofstream out(filename.c_str());
    exportToFile(out, root);
    out.close();
}

/**
 * Prints out the tree
 */
template<class ItemType>
void GeneralTree<ItemType>::print() {
    print(root, 0);
}

/**
 * Prints out all the parent nodes
 *
 * @param the child id
 */
template<class ItemType>
void GeneralTree<ItemType>::printParent(int childId) {
    std::vector<TreeNode<ItemType> *> nodes;
    // Find all the nodes matching the given id
    findAllNodes(root, childId, nodes);
    if (nodes.size() == 0) {
        // Not found
        std::cout << "Node " << childId << " does not exist." << std::endl;

    } else {
        if (nodes.size() > 1) {
            std::cout << "Node " << childId << " appears " << nodes.size()
                    << " times:" << std::endl;
        }
        // Prints out the parent of each node
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.size() > 1) std::cout << "[" << i << "] ";
            TreeNode<ItemType> *parent = findParent(root, nodes[i]);
            if (parent == NULL) {
                std::cout << "No parent." << std::endl;
            } else {
                std::cout << parent->getItem() << std::endl;
            }
        }
    }
}

/**
 * Prints out all the child nodes
 *
 * @param the parent id
 */
template<class ItemType>
void GeneralTree<ItemType>::printChildren(int parentId) {
    std::vector<TreeNode<ItemType> *> nodes;
    // Find all the parent nodes matching the given id
    findAllNodes(root, parentId, nodes);
    if (nodes.size() == 0) {
        std::cout << "Node " << parentId << " does not exist." << std::endl;

    } else {
        if (nodes.size() > 1) {
            std::cout << "Node " << parentId << " appears " << nodes.size()
                    << " times:" << std::endl;
        }
        // Prints out the children of each node
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.size() > 1) std::cout << "[" << i << "] ";
            TreeNode<ItemType> *child = nodes[i]->getFirstChildPtr();
            if (child == NULL) {
                std::cout << "No child." << std::endl;
            } else {
                while (child != NULL) {
                    std::cout << child->getItem() << " ";
                    child = child->getSiblingPtr();
                }
                std::cout << std::endl;
            }
        }
    }
}


/**
 * Prints out all the sibling nodes
 *
 * @param the node id
 */
template<class ItemType>
void GeneralTree<ItemType>::printSiblings(int nodeId) {
    std::vector<TreeNode<ItemType> *> nodes;
    // Find all the nodes matching the given id
    findAllNodes(root, nodeId, nodes);
    if (nodes.size() == 0) {
        std::cout << "Node " << nodeId << " does not exist." << std::endl;

    } else {
        if (nodes.size() > 1) {
            std::cout << "Node " << nodeId << " appears " << nodes.size()
                    << " times:" << std::endl;
        }
        // Prints out the siblings of each node
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.size() > 1) std::cout << "[" << i << "] ";
            TreeNode<ItemType> *parent = findParent(root, nodes[i]);
            if (parent == NULL) {
                std::cout << "No sibling." << std::endl;
            } else {
                for (TreeNode<ItemType> *p = parent->getFirstChildPtr();
                     p != NULL; p = p->getSiblingPtr()) {
                    if (p != nodes[i]) {
                        std::cout << p->getItem() << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
}

/**
 * Add a new child to be the first child of the given parents
 *
 * @param parentId the parent id
 * @param childId the child id
 */
template<class ItemType>
void GeneralTree<ItemType>::addFirst(int parentId, int childId) {
    std::vector<TreeNode<ItemType> *> nodes;
    // Find all the nodes matching the given id
    findAllNodes(root, parentId, nodes);
    if (nodes.size() == 0) {
        std::cout << "Node " << parentId << " does not exist." << std::endl;
    } else {
        // Add new nodes to all the parent nodes
        for (int i = 0; i < nodes.size(); i++) {
            addFirst(nodes[i], childId);
        }
    }
}


/**
 * Add a new child to be the last child of the given parents
 *
 * @param parentId the parent id
 * @param childId the child id
 */
template<class ItemType>
void GeneralTree<ItemType>::addLast(int parentId, int childId) {
    std::vector<TreeNode<ItemType> *> nodes;
    // Find all the nodes matching the given id
    findAllNodes(root, parentId, nodes);
    if (nodes.size() == 0) {
        std::cout << "Node " << parentId << " does not exist." << std::endl;
    } else {
        // Add new nodes to all the parent nodes
        for (int i = 0; i < nodes.size(); i++) {
            addLast(nodes[i], childId);
        }
    }
}

/**
 * Removes all the nodes matching the given id
 *
 * @param nodeId the node id to be removed
 */
template<class ItemType>
void GeneralTree<ItemType>::removeNode(int nodeId) {
    std::vector<TreeNode<ItemType> *> nodes;
    // Find all the nodes matching the given id
    findAllNodes(root, nodeId, nodes);
    if (nodes.size() == 0) {
        std::cout << "Node " << nodeId << " does not exist." << std::endl;

    } else {
        if (nodes.size() > 1) {
            std::cout << "Node " << nodeId << " appears " << nodes.size()
                    << " times:" << std::endl;
        }
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.size() > 1) std::cout << "[" << i << "] ";
            if (nodes[i] == root) {
                // Remove root node
                if (nodes[i]->getFirstChildPtr() != NULL) {
                    std::cout << "Deleting the root node is "
                            "not allowable unless it has no children." << std::endl;
                } else {
                    deleteNode(root);
                    root = NULL;
                    std::cout << "Success." << std::endl;
                }

            } else {
                // Find the parent node
                TreeNode<ItemType> *parent = findParent(root, nodes[i]);
                if (parent->getFirstChildPtr() == nodes[i]) {
                    // If it is the first child of its parent
                    if (nodes[i]->getFirstChildPtr() == NULL) {
                        // If it has no child, replace it with its sibling.
                        parent->setFirstChildPtr(nodes[i]->getSiblingPtr());

                    } else {
                        // Otherwise replace it with its children
                        parent->setFirstChildPtr(nodes[i]->getFirstChildPtr());
                        TreeNode<ItemType> *sib = nodes[i];
                        while (sib->getSiblingPtr()) {
                            sib = sib->getSiblingPtr();
                        }
                        sib->setSiblingPtr(nodes[i]->getSiblingPtr());
                    }
                } else {
                    // If it is not the first child of its parent
                    TreeNode<ItemType> *sib = parent->getFirstChildPtr();
                    while (sib->getSiblingPtr() != nodes[i]) {
                        sib = sib->getSiblingPtr();
                    }

                    if (nodes[i]->getFirstChildPtr() == NULL) {
                        // If it has no child, replace it with its sibling
                        sib->setSiblingPtr(nodes[i]->getSiblingPtr());

                    } else {
                        // Replace it with  its first child
                        sib->setSiblingPtr(nodes[i]->getFirstChildPtr());
                        sib = nodes[i]->getFirstChildPtr();
                        while (sib->getSiblingPtr()) {
                            sib = sib->getSiblingPtr();
                        }
                        sib->setSiblingPtr(nodes[i]->getSiblingPtr());
                    }
                }
                delete nodes[i];
                std::cout << "Success." << std::endl;
            }
        }
    }
}

/**
 * Exports the tree to a file recursively
 *
 * @param out the output stream
 * @param node the current node
 */
template<class ItemType>
void GeneralTree<ItemType>::exportToFile(std::ostream& out, TreeNode<ItemType> *node) {
    if (node) {
        out << "(" << node->getItem();
        exportToFile(out, node->getFirstChildPtr());
        out << ")";
        exportToFile(out, node->getSiblingPtr());
    }
}

/**
 * Finds the parent node recursively
 *
 * @param parent the current node
 * @param child the child node
 * @param parent of the child
 */
template<class ItemType>
TreeNode<ItemType> *GeneralTree<ItemType>::findParent(TreeNode<ItemType> *parent,
        TreeNode<ItemType> *child) {
    if (parent) {
        TreeNode<ItemType> *childNode = parent->getFirstChildPtr();
        while (childNode != NULL) {
            if (childNode == child) return parent;
            TreeNode<ItemType> *temp = findParent(childNode, child);
            if (temp) return temp;
            childNode = childNode->getSiblingPtr();
        }
    }
    return NULL;
}

/**
 * Prints out the tree recursively
 *
 * @param node the current node
 * @param depth the depth of recursion
 */
template<class ItemType>
void GeneralTree<ItemType>::print(TreeNode<ItemType> *node, int depth) {
    if (node) {
        for (int i = 0; i < 4 * depth; i++) {
            std::cout << " ";
        }
        std::cout << node->getItem() << std::endl;
        print(node->getFirstChildPtr(), depth + 1);
        print(node->getSiblingPtr(), depth);
    }
}

/**
 * Adds a new node to be the first child of the parent node
 *
 * @param parent the current node
 * @param child the new child Id
 * @param a new created node
 */
template<class ItemType>
TreeNode<ItemType> *GeneralTree<ItemType>::addFirst(TreeNode<ItemType> *node, int child) {
    TreeNode<ItemType> *newNode = new TreeNode<ItemType>(child);
    if (node->getFirstChildPtr() == NULL) {
        node->setFirstChildPtr(newNode);
    } else {
        newNode->setSiblingPtr(node->getFirstChildPtr());
        node->setFirstChildPtr(newNode);
    }
    return newNode;
}

/**
 * Adds a new node to be the last child of the parent node
 *
 * @param parent the current node
 * @param child the new child Id
 * @param a new created node
 */
template<class ItemType>
TreeNode<ItemType> *GeneralTree<ItemType>::addLast(TreeNode<ItemType> *node, int child) {
    TreeNode<ItemType> *newNode = new TreeNode<ItemType>(child);
    if (node->getFirstChildPtr() == NULL) {
        node->setFirstChildPtr(newNode);
    } else {
        TreeNode<ItemType> *childNode = node->getFirstChildPtr();
        while (childNode->getSiblingPtr()) {
            childNode = childNode->getSiblingPtr();
        }
        childNode->setSiblingPtr(newNode);
    }
    return newNode;
}

/**
 * Finds all the nodes matching the key
 *
 * @param node the current node
 * @param key the given key
 * @param vec vector of the searching results
 */
template<class ItemType>
void GeneralTree<ItemType>::findAllNodes(TreeNode<ItemType> *node, ItemType key,
        std::vector<TreeNode<ItemType> *>& vec) {
    if (node) {
        if (node->getItem() == key) {
            vec.push_back(node);
        }
        findAllNodes(node->getFirstChildPtr(), key, vec);
        findAllNodes(node->getSiblingPtr(), key, vec);
    }
}

/**
 * Deletes all the nodes recursively
 *
 * @param node the node to be deleted
 */
template<class ItemType>
void GeneralTree<ItemType>::deleteNode(TreeNode<ItemType> *node) {
    if (node) {
        deleteNode(node->getFirstChildPtr());
        deleteNode(node->getSiblingPtr());
        delete node;
    }
}
