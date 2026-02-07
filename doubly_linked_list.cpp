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

// isEmpty methid
bool DoublyLinkedList::isEmpty() {
    // We are chedking if the head is a nullptr
    bool empty = (head == nullptr);
    return empty;
}

void DoublyLinkedList::insertAtHead(int key){
    DllNode* createNode = new DllNode(key);
    // We need this just case if the node is the first node the head and tail will be the same node.
    if(isEmpty()) {
        head = createNode;
        tail = createNode;
    } else{
        // We are puting the next address as the old head address
        // then we are linking the prevous address on the left with createNode
        // the next and precous are being linked in reference to the olad head node
        createNode -> next = head;
        head -> prev = createNode;
        head  = createNode;
    }
};






// 



