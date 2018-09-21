/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: LinkedQueue.cpp
 * Description: set a queue let customer line up.
 */

#include "LinkedQueue.h"

/**
 * Default constructor
 */
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : head(NULL), tail(NULL) {
}

/**
 * Destructor
 */
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {
    // Dequeue all the nodes
    while (!isEmpty()) dequeue();
}

/**
 * Determines whether the queue is empty or not
 *
 * @return true if the queue is empty and false otherwise
 */
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    return head == NULL;
}

/**
 * Enqueues a new item
 *
 * @param the new item to enqueue
 */
template<class ItemType>
void LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
throw (PrecondViolatedExcep) {
    Node<ItemType> *newNode = new Node<ItemType>(newEntry);
    if (isEmpty())
        tail = head = newNode;
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

/**
 * Dequeues an item
 */
template<class ItemType>
void LinkedQueue<ItemType>::dequeue() throw (PrecondViolatedExcep) {
    if (isEmpty()) throw PrecondViolatedExcep("Empty Queue");
    Node<ItemType> *temp = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->getNext();
    }
    delete temp;
}

/**
 * Returns the front node
 *
 * @return the front node
 */
template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep) {
    if (isEmpty()) throw PrecondViolatedExcep("Empty Queue");
    return head->getItem();
}
