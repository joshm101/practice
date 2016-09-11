
/* 
 * File:   AdjacencyList.h
 * Author: Joshua
 *
 * Created on September 10, 2016, 1:47 PM
 */

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "GraphNode.h"
#include "ListNode.h"

using namespace std;

class AdjacencyList {
private:
   vector<GraphNode*> nodes;
   int vectorIndex;
public:
   AdjacencyList();
   ~AdjacencyList();
   void addGraphNode(int val);
   void addEdge(int firstNode, int secondNode);
   void printGraph();
   void deleteGraph();
   GraphNode* getNode(int index);
   void BFS(queue<int>& breadth);
   void DFS(GraphNode* node);
};


#endif /* ADJACENCYLIST_H */

