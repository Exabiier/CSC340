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
}

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


void DoublyLinkedList::insertAtTail(int key) {
    DllNode* createNode = new DllNode(key);
        if (isEmpty()) {
            head = createNode;
            tail = createNode;
        } else {
            // Now we do the oppsite because the tail is on the right of all the node
            createNode -> prev = tail;
            tail -> next = createNode;
            tail = createNode;
        }
    }

void DoublyLinkedList::printList() {
    // Had to add for test
    logToFileAndConsole("\nHere are the List contents:");

    DllNode* currentNode = head;
    while (currentNode != nullptr){
        // we are using the printNode() method then we are moving on to the next address. 
        currentNode -> printNode();
        currentNode = currentNode -> next;
    }

    logToFileAndConsole("End of List");
}

// the only difference is that now we make the currentNode into prevouse address. 
void DoublyLinkedList::reversePrintList() {
    // Had to add for test
    logToFileAndConsole("\nHere are the List contents reversed:");

    DllNode* currentNode = tail;
        while(currentNode != nullptr) {
            currentNode -> printNode();
            currentNode = currentNode -> prev;
        }

    logToFileAndConsole("End of List");
}

void DoublyLinkedList::remove(int key) {
    DllNode* current = head;

    // we loop though the whole the loop to find the key
    while ( current != nullptr) {
        if (current -> key == key){

            // --- When the point is the only node in list --- //
            if (current == head && current == tail) {
                head = nullptr;
                tail = nullptr;
            }

            // -- when the node is the head node --- //
            else if (current == head) {
                // we are making the address of the head to the right node
                head = head -> next;
                head -> prev = nullptr;
            }

            // --- when the node is at the tail --- //
            else if (current == tail) {
                // we are making the address of the tail of the left node
                tail = tail -> prev;
                tail -> next = nullptr;
            }
            
            // --- when the node is in the middle --- //
            else {
                // we are linking both the left and right node together
                DllNode* prevNode = current -> prev;
                DllNode* nextNode = current -> next;
                prevNode -> next = nextNode;
                nextNode -> prev = prevNode;
            }

            delete current;
            return;

        }
    
        current = current -> next;
    
    } 
}

void DoublyLinkedList::removeHeaderNode(){
    //need this if the node list is empty; do notheing
    if (isEmpty()){
        return;
    }

    // need address for the old head node to delete for later
    DllNode*  tempHead = head;

    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        // we are taking the head pointer the the next node. then delete the old one
        head = head -> next;
        head -> prev = nullptr;
    }

    delete tempHead;
}

void DoublyLinkedList::removeTailNode() {

    if (isEmpty()) {
        return;
    }

    DllNode* tempTail = tail;

    // same as the removeHeaderNode method but removing the tail node:
    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail -> prev;
        tail -> next = nullptr;
    }

    delete tempTail;
}

void DoublyLinkedList::moveNodeToHead(int key) {

    if (isEmpty()) {
        return;
    }

    // if the key is already at the head node
    if (head -> key == key) {
        return;
    }   

    DllNode* current = head;

    // looping through to find the current node
    while (current != nullptr) {
        if (current -> key == key) {

            // --- if the node is at the tail --- //
            if ( current == tail) {
                tail = tail -> prev;
                if (tail != nullptr) {
                    tail -> next = nullptr;
                 }
            } else {
                // we are linking both the left and right node together
                DllNode* prevNode = current -> prev;
                DllNode* nextNode = current -> next;
                prevNode -> next = nextNode;
                if (nextNode != nullptr) {
                    nextNode -> prev = prevNode;
                }
            }

            // cahnging address for the new head node:
            current -> next = head;
            current -> prev = nullptr;
            head -> prev = current;
            head = current;
            return;
        }

        current = current  -> next;
    }
}

void DoublyLinkedList::moveNodeToTail(int key) {

    if (isEmpty()) {
        return;
    }   

    DllNode* current = head;

    while (current != nullptr) {
        if (current -> key == key) {

            if (current == head){
                head = head -> next;
                // this check is needed just in case the node is the only node in the list
                if (head != nullptr) {
                    head -> prev = nullptr;
                }
            } else {
                DllNode* prevNode = current -> prev;
                DllNode* nextNode = current -> next;
                prevNode -> next = nextNode;
                // check is need just in case the node is the last node
                if (nextNode != nullptr) {
                nextNode -> prev = prevNode;
                }
            }

            current -> prev = tail;
            current -> next = nullptr;
            tail -> next = current;
            tail = current;
            return;
        }
        current = current -> next;
    }
}

void DoublyLinkedList::clear() {
    DllNode* current = head;

    // deleting the whole node list by looping from head
    while (current != nullptr){
        DllNode* nextNode = current -> next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}











// 



