/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: Node.h
 * Description: the header file of Node.cpp.
 */

#ifndef NODE_H
#define NODE_H

#include <cstdlib>

/**
 * Node of stack and queue
 */
template<class ItemType>
class Node {
private:
    /**
     * Item stored in the node
     */
    ItemType item;
    /**
     * Link of the next node
     */
    Node<ItemType> *next;

public:
    /**
     * Default Constructor
     */
    Node();

    /**
     * Constructor
     *
     * @param item item stored in the node
     */
    Node(const ItemType& item);

    /**
     * Constructor
     *
     * @param item item stored in the node
     * @param next Link of the next node
     */
    Node(const ItemType& item, Node<ItemType> *next);

    /**
     * Sets the item
     *
     * @param item item stored in the node
     */
    void setItem(const ItemType& anItem);

    /**
     * Sets the link
     *
     * @param next Link of the next node
     */
    void setNext(Node<ItemType> *nextNodePtr);

    /**
     * Returns the item
     *
     * @return item stored in the node
     */
    ItemType getItem() const;


    /**
     * Returns the link
     *
     * @return next Link of the next node
     */
    Node<ItemType> *getNext() const;
};

#include "Node.cpp"

#endif
