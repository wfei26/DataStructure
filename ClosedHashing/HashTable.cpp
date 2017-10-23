/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/12/14
*File: HashTable.cpp
*Course: EECS560 - Data Structure
*Project: Lab3 - Closed Hashing with Open Addressing
***********************************************************/

#include "HashTable.h"

/*
* Default Constructor
* @param item   the value of the item in hash table
* @param flag   the current status of flag 
*               true if the bucket is emptied by deletion and searching must continue
*               false if the bucket was empty from the beginning of the hashing process so searching terminates
*/
HashTable::HashTable()
{
	item = -1;
	flag = false;
}


/*
* Destructor
*/
HashTable::~HashTable()
{
}


/*
* Constructor with the value of new entry
* @param newItem    the value of new entry
*/
HashTable::HashTable(const int newItem)
{
	item = newItem;
	flag = false;
}


/*
* Set new entry into a hash table
* @param newItem    value of new entry
*/
void HashTable::setItem(const int newItem)
{
	item = newItem;
}


/*
* Set a new updated flag into the hash table
* @param newFlag    updated result of new flag
*/
void HashTable::setFlag(bool newFlag)
{
	flag = newFlag;
}


/*
* Get the the value of current entry from hash table
* @return item     the value of current entry 
*/
int HashTable::getItem()
{
	return item;
}


/*
* Get the the result of current flag from hash table
* @return item     the current status of the flag
*/
bool HashTable::getFlag()
{
	return flag;
}
