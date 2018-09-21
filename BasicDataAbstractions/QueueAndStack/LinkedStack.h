/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: LinkedStack.h
 * Description: the header file of LinkedStack.cpp.
 */

#ifndef LINKED_STACK
#define LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

/**
 * Stack class
 */
template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
    /**
     * Top node of the stack
     */
    Node<ItemType> *top;

public:
    /**
     * Default constructor
     */
    LinkedStack();

    /**
     * Destructor
     */
    virtual ~LinkedStack();

    /**
     * Determines whether the stack is empty or not
     *
     * @return true if the stack is empty and false otherwise
     */
    bool isEmpty() const;

    /**
     * Pushes an item to the stack
     *
     * @param item the item to be pushed
     */
    void push(const ItemType& item) throw (PrecondViolatedExcep);

    /**
     * Pops a node from the stack
     */
    void pop() throw (PrecondViolatedExcep);

    /**
     * Returns the top item
     *
     * @return top item in the stack
     */
    ItemType peek() const throw (PrecondViolatedExcep);
};

#include "LinkedStack.cpp"

#endif
