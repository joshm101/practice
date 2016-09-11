
/* 
 * File:   Node.h
 * Author: Joshua
 *
 * Created on September 10, 2016, 1:51 PM
 */

#ifndef NODE_H
#define NODE_H

class Node {
private:
   int value;
   
   // vectorIndex will allow us to keep
   // track of the nodes visited in the current
   // set of nodes for BFS to refer back to and
   // continue searching.
   int vectorIndex;
   bool visited;
public:
   Node(int val, int vecIndex);
   ~Node();
   void setVisited();
   int getValue();
   int getVectorIndex();
   bool isVisited();
   void deleteNode();
};

#endif /* NODE_H */

