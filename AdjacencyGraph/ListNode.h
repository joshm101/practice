/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListNode.h
 * Author: Joshua
 *
 * Created on September 10, 2016, 3:46 PM
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include "Node.h"

using namespace std;

class ListNode : public Node {
private:
   ListNode* next;

public:
   ListNode(int val, int vecIndex);
   ~ListNode();
   ListNode* getNext();
   void setNext(ListNode* next);
   void deleteListNode();
};


#endif /* LISTNODE_H */

