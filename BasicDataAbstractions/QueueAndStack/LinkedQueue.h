/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: LinkedQueue.h
 * Description: the header file of LinkedQueue.cpp.
 */

#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"
#include "Node.h"

/**
 * Queue class
 */
template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
private:
    /**
     * Pointer of the head node
     */
    Node<ItemType> *head;
    /**
     * Pointer of the tail node
     */
    Node<ItemType> *tail;

public:

    /**
     * Default constructor
     */
    LinkedQueue();

    /**
     * Destructor
     */
    ~LinkedQueue();

    /**
     * Determines whether the queue is empty or not
     *
     * @return true if the queue is empty and false otherwise
     */
    bool isEmpty() const;


    /**
     * Enqueues a new item
     *
     * @param the new item to enqueue
     */
    void enqueue(const ItemType& item) throw (PrecondViolatedExcep);

    /**
     * Dequeues an item
     */
    void dequeue() throw (PrecondViolatedExcep);

    /**
     * Returns the front node
     *
     * @return the front node
     */
    ItemType peekFront() const throw(PrecondViolatedExcep);

};

#include "LinkedQueue.cpp"
#endif
