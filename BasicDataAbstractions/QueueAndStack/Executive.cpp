/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: Executive.cpp
 * Description: edit the final output.
 */

#include "Executive.h"

/**
 * Constructor to load from the input stream
 *
 * @param input input stream
 */
Executive::Executive(ifstream& input) {
    // Check whether the file exists or not
    if (!input) {
        cout << "The input file does not exist" << endl;
        return;
    }

    string str;

    // Read all the words
    while (input >> str) {
        if (str == "done") {
            done();
        } else if (str == "show") {
            show();
        } else {
            add(str);
        }
    }

    // Close the file
    input.close();
}

/**
 * Person being served finishes.
 */
void Executive::done() {
    if (currentVIP != "") {
        // If a VIP is being served

        cout << ".. " << currentVIP << " is done; ";

        try {
            // If another VIP is suspended, resume him
            currentVIP = stack.peek();
            stack.pop();
            cout << currentVIP << " is resuming .." << endl;

        } catch (PrecondViolatedExcep& e) {
            // No VIP in the stack
            currentVIP = "";
            try {
                // Start to serve the person the queue
                cout << queue.peekFront() << " is starting .." << endl;

            } catch (PrecondViolatedExcep& ex) {
                // Queue is empty
                cout << "no one is waiting, Lydia rests .." << endl;
            }
        }

    } else {
        try {
            // Dequeue a person
            cout << ".. " << queue.peekFront() << " is done; ";
            queue.dequeue();

            try {
                // Serve the next person
                cout << queue.peekFront() << " is starting .." << endl;

            } catch (PrecondViolatedExcep& ex) {
                // Queue is empty
                cout << "no one is waiting, Lydia rests .." << endl;
            }

        } catch (PrecondViolatedExcep& ex) {
            // Queue is empty
            cout << ".. No one is being serverd .." << endl;
        }
    }
}

/**
 * Shows the status
 */
void Executive::show() {
    cout << "*** ";
    if (currentVIP != "") {
        cout << currentVIP << " is currently being served; ";
    }
    // Show the person waiting
    try {
        cout << queue.peekFront() << " is waiting in the queue ***" << endl;
    } catch (PrecondViolatedExcep& e) {
        cout << "No one is waiting in the queue ***" << endl;
    }
}

/**
 * A new person arrives
 *
 * @param name name of the person
 */
void Executive::add(string name) {
    if (!isVIP(name)) {
        // If not a VIP, add to the queue
        cout << name << " arrives for service." << endl;
        queue.enqueue(name);

    } else if (currentVIP != "") {
        // If a VIP is being served
        if (compareVIP(currentVIP, name)) {
            // Leave if less priority
            cout << name << " arrives; " << currentVIP << " is being served; "
                    << name << " immediately leaves." << endl;

        } else {
            // Move the VIP being served to the stack
            cout << name << " arrives; " << currentVIP << " is suspended; "
                    << name << " immediately starts getting served. " << endl;
            stack.push(currentVIP);
            currentVIP = name;
        }

    } else {
        // Add to VIP
        currentVIP = name;
        cout << name << " arrives for service and immediately starts getting served." << endl;
    }
}

/**
 * Determines whether a name is VIP
 *
 * @param name name of the person
 * @return true if it is VIP and false otherwise
 */
bool Executive::isVIP(string name) {
    return name.find("VIP") == 0;
}

bool Executive::compareVIP(string VIP1, string VIP2) {
    return VIP1[3] > VIP2[3];
}