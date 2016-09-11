/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Node.h"
#include "GraphNode.h"
#include "LinkedList.h"

GraphNode::GraphNode(int val, int vecIndex) : Node(val, vecIndex) {
   this->aNodes = new LinkedList();
}

GraphNode::~GraphNode() {}

/**
 * 
 * @param val
 * 
 * This function will create a new ListNode
 * and append it to "this" node's corresponding
 * adjacency list.
 */
void GraphNode::appendNode(int val, int vecIndex) {
   this->aNodes->appendNode(val, vecIndex);
}

/**
 * 
 * @param breadth
 * 
 * This function will traverse the list of adjacent
 * nodes associated with "this" GraphNode. Each
 * node that the function visits (that has not already
 * been visited) will be added to the breadth queue and
 * be marked as "visited."
 * 
 * The function will return a stack reference containing
 * all the nodes that were visited so that the
 * AdjacencyList vector nodes can be appropriately
 * marked as visited.
 */
stack<int> GraphNode::traverseList(queue<int>& breadth) {
   stack<int> visited;
   // breadth.pop();
   
   // get current node's adjacency list
   LinkedList* currentList = this->aNodes;
   
   // start at head of the list
   ListNode* listHead = currentList->getHead();
   ListNode* current = listHead;
   
   while (current) {
      // while we have a node in the list (not null))
      
      if (current->isVisited() == false) {
         // if the node has not already been visited,
         // push its vector index onto the stack of visited
         // nodes
         int vectorIndex = current->getVectorIndex();
         visited.push(vectorIndex);
         current->setVisited();
         
         // push the visited node onto the breadth
         // queue so that its own adjacency list
         // can be searched later on.
         breadth.push(current->getVectorIndex());
      }
      // get next node in the adjacency list
      current = current->getNext();
   }
   
   return visited;
}

/**
 * This function will print out the adjacency
 * list associated with this graph node
 */
void GraphNode::printAdjacencyList() {
   this->aNodes->printList();
}

/**
 * 
 * @return
 * 
 * This function returns the head of "this" 
 * GraphNode's adjacency list. 
 */
ListNode* GraphNode::getListHead() {
   return this->aNodes->getHead();
}

/**
 * This function will call the destructor on
 * the graph node for proper disposal (prevent memory leaks)
 */
void GraphNode::deleteGraphNode() {
   if (this->aNodes->listLength() > 0) {
      this->aNodes->deleteList();
   }
   delete this;
}

