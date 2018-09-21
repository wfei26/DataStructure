/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: LinkedStack.cpp
 * Description: get a stack let customer line up.
 */
 
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : top(NULL) {
}


template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    // Pop all the nodes
    while (!isEmpty()) pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return top == NULL;
}


template<class ItemType>
void LinkedStack<ItemType>::push(const ItemType& item) throw (PrecondViolatedExcep) {
    top = new Node<ItemType>(item, top);
}



template<class ItemType>
void LinkedStack<ItemType>::pop() throw (PrecondViolatedExcep) {
    if (isEmpty()) throw PrecondViolatedExcep("Empty Stack");
    Node<ItemType> *temp = top;
    top = top->getNext();
    delete temp;
}


template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const throw (PrecondViolatedExcep) {
    if (isEmpty()) throw PrecondViolatedExcep("Empty Stack");
    return top->getItem();
}
