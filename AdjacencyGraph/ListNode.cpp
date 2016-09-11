/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

using namespace std;

#include "ListNode.h"
#include <cstdlib>

ListNode::ListNode(int val, int vecIndex) : Node(val, vecIndex), next() {}

ListNode::~ListNode(){}

/**
 * 
 * @return ListNode* 
 * 
 * This function will return a pointer to the next node in the
 * list.
 */
ListNode* ListNode::getNext() {
   return this->next;
}

/**
 * 
 * @param next
 * 
 * This function will append a new node to the
 * list of adjacent nodes.
 */
void ListNode::setNext(ListNode* next) {
   this->next = next;
}

/**
 * This function will properly delete a node in the list
 * to prevent memory leaks
 */
void ListNode::deleteListNode() {
   delete this;
}