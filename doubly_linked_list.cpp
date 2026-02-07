/*
 * Name: Exabbier
 * Date: 02/06/2026
 * File: doubly_linked_list.cpp
 * Description: Creating a implememntation from the the doubly linked list file from the professor. 
 */

 #include "doubly_linked_list.h"
 #include "milestone1.h"

 /* Since the class was declared in the header file, all that needs to be done is the methods of the class doubly link list*/

//  constructor is initializing the head and tail pointer with nullptr. the list is empty to start
DoublyLinkedList::DoublyLinkedList() {
    // nullptr must be used in order to not have some random memory address for out pointers to be used.
    head = nullptr;
    tail = nullptr;
};

// deconstructor method 
DoublyLinkedList::~DoublyLinkedList() {
    // we get the head pointer
    DllNode* current = head;
    // this allows us the loop throught the linked list from the head to the tail
    // This in turn allows us to delete the node itself then move to the next node
    while (current != nullptr) {
        DllNode* next = current -> next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
};




