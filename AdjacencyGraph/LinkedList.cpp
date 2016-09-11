
#include <iostream>
#include "Node.h"
#include "ListNode.h"
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(), length(){}

LinkedList::~LinkedList() {}


/**
 * 
 * @param val
 * 
 * This function will append a node
 * to the current graph node's adjacency
 * list. The node being appended with value
 * val represents the existence of an edge 
 * between the current graph's node and
 * the node with value val.
 */
void LinkedList::appendNode(int val, int vecIndex) {
   ListNode* toAppend = new ListNode(val, vecIndex);
   if (this->head) {
      // if there is a non null head,
      // traverse the list until we get
      // to the end to append our new node
      ListNode* current = this->head;
      while (current->getNext()) {
         current = current->getNext();
      }
      current->setNext(toAppend);
   } else {
      // if there is no head, set the
      // head to the new node.
      this->head = toAppend;
   }
   
   this->length++;
}

/**
 * 
 * @return
 * 
 * This function will return the length
 * field of the linked list 
 */
int LinkedList::listLength() {
   return this->length;
}

/**
 * 
 * @return
 * 
 * This function will return the head of
 * the linked list. 
 */
ListNode* LinkedList::getHead() {
   return this->head;
}

/**
 * 
 * This function will iterate over the
 * adjacency list and ensure that each node
 * in the list is properly disposed of
 * (to prevent memory leaks) before the
 * list itself is deleted via the destructor
 */
void LinkedList::deleteList() {
   
   ListNode* current = this->head;
   ListNode* currentNext = current->getNext();
   while (current) {
      currentNext = current->getNext();
      current->deleteListNode();
      current = NULL;
      current = currentNext;
      --this->length;
   }
   delete this;
}

/**
 * This function will print the adjacency list
 * as follows:
 * 
 * (val: x, visited: true/false) --> (val: y, visited: true/false) --> ...
 */
void LinkedList::printList() {
   ListNode* current = this->head;
   while (current) {
      if (current->getNext()) {
         cout<< "(val: "<< current->getValue()<< ", visited: "<<
             boolalpha<< current->isVisited()<< ") --> ";
      } else {
         cout<< "(val: "<< current->getValue()<< ", visited: "<<
             boolalpha<< current->isVisited()<< ")";
      }
      current = current->getNext();
   }
   cout<< endl;
}