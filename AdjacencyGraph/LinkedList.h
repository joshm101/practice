
/* 
 * File:   LinkedList.h
 * Author: Joshua
 *
 * Created on September 10, 2016, 2:07 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

class LinkedList {
private:
   ListNode* head;
   int length;
public:
   LinkedList();
   ~LinkedList();
   void appendNode(int val, int vecIndex);
   ListNode* getHead();
   void deleteList();
   void printList();
   int listLength();
};


#endif /* LINKEDLIST_H */

