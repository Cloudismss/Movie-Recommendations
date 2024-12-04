#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include <string>

#include "DecisionTreeNode.h"

using std::string;

class DecisionTree
{
public:
  void addNode(); // Adds a node to the tree
  string classify(DecisionTreeNode *node, Movie *movie); // Recursively traverses tree to make a recommendation
};

#endif // DECISION_TREE_H