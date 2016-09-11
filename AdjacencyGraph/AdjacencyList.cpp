
#include "AdjacencyList.h"
#include "Node.h"
#include "GraphNode.h"
#include "ListNode.h"

AdjacencyList::AdjacencyList() : vectorIndex(0) {}

AdjacencyList::~AdjacencyList() {}

/*
 * @param int val
 * 
 * this function will create a node
 * in our graph by creating a new
 * entry in our vector of graph nodes
 */
void AdjacencyList::addGraphNode(int val) {
   
   // each node in our graph is an index
   // into the vector of LinkedLists
   // So each node has an associated LinkedList
   // where members of the LinkedList represent
   // nodes adjacent to node i where i is a
   // vector index.
   GraphNode* newNode = new GraphNode(val, this->vectorIndex);
   this->nodes.push_back(newNode);
   this->vectorIndex++;
   cout<< "this->vectorIndex is: "<< this->vectorIndex<< endl;
}

/*
 *
 * @param int firstNode
 * @param int secondNode
 * 
 * this function will add an edge
 * between the two specified nodes.
 * the specified nodes are indices
 * into our vector of graph nodes.
 * 
 * this function will first check to see
 * if those indices (firstNode and secondNode)
 * exist and if they do, will create a node
 * in each of their respective lists of 
 * adjacent nodes.
 */
void AdjacencyList::addEdge(int firstNode, int secondNode) {
   if (firstNode < this->nodes.size() and
         secondNode < this->nodes.size()) {
      // both nodes to create an edge between exist in
      // our graph
      
      int firstVal = this->nodes.at(firstNode)->getValue();
      int secondVal = this->nodes.at(secondNode)->getValue();
      
      this->nodes.at(firstNode)->appendNode(secondVal, secondNode);
      this->nodes.at(secondNode)->appendNode(firstVal, firstNode);
   }
}

/**
 * This function will print the graph
 * in adjacency list format
 */
void AdjacencyList::printGraph() {
   for (int i = 0; i < this->nodes.size(); ++i) {
      cout<< "(val: "<< this->nodes.at(i)->getValue()<<", visited: "<<
              boolalpha<< this->nodes.at(i)->isVisited()<< "): ";
      this->nodes.at(i)->printAdjacencyList();
      cout<< endl;
   }

}

/**
 * 
 * @param breadth
 * 
 * the parameter breadth will contain
 * all visited nodes adjacent to a graph
 * node being examined.
 * 
 * This function will perform BFS on our
 * adjacency list graph.
 */
void AdjacencyList::BFS(queue<int>& breadth) {
   cout<< endl<< endl<< "**** PERFORMING BFS ****"<< endl;
   while (breadth.size() > 0) {
      int nodeIndex = breadth.front();
      breadth.pop();
      GraphNode* current = this->nodes.at(nodeIndex);       
      current->setVisited();

      // once node is marked visited, 
      // traverse its adjacency list, only
      // pushing unvisited nodes onto the queue
      stack<int> indicesToUpdate = current->traverseList(breadth);

      // update/mark the appropriate graph nodes
      // in the vector as "visited"
      while (indicesToUpdate.size() > 0) {
         int indexToUpdate = indicesToUpdate.top();
         indicesToUpdate.pop();
         this->nodes.at(indexToUpdate)->setVisited();
      }
      cout<< endl<< endl;
      this->printGraph();
   }
}


// FOR BOTH DFS AND BFS:

// since the nodes in the graph are represented in two different ways
// (ListNode and GraphNode), then while we have the correct traversals
// implemented, the nodes in an adjacency list that have already been
// visited via their corresponding GraphNode will not reflect this fact
// until they themselves are visited.
// When those ListNodes' associated GraphNodes are visited "again," they
// will immediately return because the nodes in said GraphNodes' lists
// will already be previously marked as visited.
// This can be fixed by going for a smarter adjacency list implementation,
// however the correct/working search algorithms are implemented as outlined
// in textbooks/on the Internet.


/**
 * 
 * @param node
 * 
 * This function performs DFS recursively
 * on the passed in GraphNode "node."
 */
void AdjacencyList::DFS(GraphNode* node) {
   ListNode* listHead = node->getListHead();
   ListNode* current = listHead;
   node->setVisited();
   while (current) {
      if (current->isVisited() == false) {
         current->setVisited();
         cout<< endl<< endl;
         this->printGraph();
         this->DFS(this->nodes.at(current->getVectorIndex()));
      }
      current = current->getNext();
   }
}

/**
 * 
 * @param index
 * @return
 * 
 * This function will return the graph
 * located at the specified index parameter. 
 */
GraphNode* AdjacencyList::getNode(int index) {
   return this->nodes.at(index);
}

/*
 * This function will iterate
 * through the vector (the nodes)
 * and will ensure that each of the
 * nodes' adjacency lists are properly
 * disposed of to prevent memory leaks
 */
void AdjacencyList::deleteGraph() {
   for (int i = 0; i < this->nodes.size(); ++i) {
      this->nodes.at(i)->deleteGraphNode();
   }
   delete this;
}