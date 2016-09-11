
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int val, int vecIndex) : value(val),
                      visited(false),
                      vectorIndex(vecIndex) {
}

Node::~Node() {}

/**
 * This function will set the current node
 * to "visited" which is needed when
 * we are performing our graph traversal
 * algorithms
 */
void Node::setVisited() {
   this->visited = true;
}

/**
 * delete "this" node in the list
 * by calling its destructor.
 */
void Node::deleteNode() {
   delete this;
}

/**
 * 
 * @return int
 * 
 * This function will return the value of
 * "this" node
 */
int Node::getValue() {
   return this->value;
}

/**
 * 
 * @return
 * 
 * This function will return the node's
 * index into the GraphNode vector. 
 */
int Node::getVectorIndex() {
   return this->vectorIndex;
}

/**
 * 
 * @return bool
 * 
 * This function will return the "visited" field
 * value of "this" node to communicate whether "this"
 * node has yet been visited or not. 
 */
bool Node::isVisited() {
   return this->visited;
}