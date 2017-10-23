/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/12/14
*File: HashTable.h
*Course: EECS560 - Data Structure
*Project: Lab3 - Closed Hashing with Open Addressing
***********************************************************/

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

class HashTable
{
private:
	int item;
	bool flag;

public:
	/*
	* Default Constructor
	* @param item   the value of the item in hash table
	* @param flag   the current status of flag
	*               true if the bucket is emptied by deletion and searching must continue
	*               false if the bucket was empty from the beginning of the hashing process so searching terminates
	*/
	HashTable();
	

	/*
	* Destructor
	*/
	~HashTable();


	/*
	* Constructor with the value of new entry
	* @param newItem    the value of new entry
	*/
	HashTable(const int newItem);


	/*
	* Set new entry into a hash table
	* @param newItem    value of new entry
	*/
	void setItem(const int newItem);


	/*
	* Set a new updated flag into the hash table
	* @param newFlag    updated result of new flag
	*/
	void setFlag(bool newFlag);


	/*
	* Get the the value of current entry from hash table
	* @return item     the value of current entry
	*/
	int getItem();


	/*
	* Get the the result of current flag from hash table
	* @return item     the current status of the flag
	*/
	bool getFlag();
};

#endif
