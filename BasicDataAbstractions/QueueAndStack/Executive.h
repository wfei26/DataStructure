/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: Executive.h
 * Description: the header file of Executive.cpp.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H


#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <string>
#include <fstream>
#include <iostream>

class Executive {
public:
    /**
     * Constructor to load from the input stream
     *
     * @param input input stream
     */
    Executive(ifstream& input);


private:
    /**
     * Person being served finishes.
     */
    void done();

    /**
     * Shows the status
     */
    void show();

    /**
     * A new person arrives
     *
     * @param name name of the person
     */
    void add(string name);

    /**
    * Determines whether a name is VIP
    *
    * @param name name of the person
    * @return true if it is VIP and false otherwise
    */
    bool isVIP(string name);

    /**
    * Compares two VIPs
    *
    * @param VIP1 name of the first person
    * @param VIP2 name of the second person
    * @return true VIP1 > VIP2 and false otherwise
    */
    bool compareVIP(string VIP1, string VIP2);

    /**
     * The VIP being served
     */
    string currentVIP;
    /**
     * Service queue
     */
    LinkedQueue<string> queue;
    /**
     * Stack of suspended VIPs
     */
    LinkedStack<string> stack;
};

#endif
