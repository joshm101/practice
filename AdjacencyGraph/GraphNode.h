/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphNode.h
 * Author: Joshua
 *
 * Created on September 10, 2016, 3:50 PM
 */

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include <queue>
#include <stack>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

class GraphNode : public Node {
private:
   LinkedList* aNodes;
public:
   GraphNode(int val, int vecIndex);
   ~GraphNode();
   void appendNode(int val, int vecIndex);
   stack<int> traverseList(queue<int>& breadth);
   void printAdjacencyList();
   ListNode* getListHead();
   void deleteGraphNode();
};

#endif /* GRAPHNODE_H */

