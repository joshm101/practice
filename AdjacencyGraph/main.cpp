/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on September 10, 2016, 1:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include "AdjacencyList.h"
#include "Node.h"
#include "LinkedList.h"
#include "GraphNode.h"
#include "ListNode.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   AdjacencyList* graph = new AdjacencyList();
   cout<< endl<< endl;
   graph->addGraphNode(3);
   graph->addGraphNode(5);
   graph->addGraphNode(19);
   graph->addGraphNode(420);
   graph->addEdge(0, 2);
   graph->addEdge(0, 3);
   graph->printGraph();
   queue<int> breadth;
   breadth.push(0);
   graph->BFS(breadth);
   //cout<< endl<< endl<< "******performing DFS******"<< endl;
   //graph->DFS(graph->getNode(0));
   cout<< endl<< endl;
   graph->printGraph();
   graph->deleteGraph();
   return 0;
}

