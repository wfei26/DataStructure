/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: Node.cpp
 * Description: get nodes of linked list to save normal customers or vip customers.
 */

/**
 * Default Constructor
 */
template<class ItemType>
Node<ItemType>::Node() : next(NULL) {
}

/**
 * Constructor
 *
 * @param item item stored in the node
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& item) : item(item), next(NULL) {
}

/**
 * Constructor
 *
 * @param item item stored in the node
 * @param next Link of the next node
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType> *next) :
item(item), next(next) {
}

/**
 * Sets the item
 *
 * @param item item stored in the node
 */
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item) {
    this->item = item;
}

/**
 * Sets the link
 *
 * @param next Link of the next node
 */
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *next) {
    this->next = next;
}

/**
 * Returns the item
 *
 * @return item stored in the node
 */
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

/**
 * Returns the link
 *
 * @return next Link of the next node
 */
template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const {
    return next;
}
