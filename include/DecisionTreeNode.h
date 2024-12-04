#ifndef DECISION_TREE_NODE_H
#define DECISION_TREE_NODE_H

#include <string>

#include "Movie.h"

using std::string;

class DecisionTreeNode
{
private:
  string question;
  DecisionTreeNode *yes;
  DecisionTreeNode *no;
  string recommendation; // If it's a leaf node

public:
  DecisionTreeNode(string question) : question(question), yes(nullptr), no(nullptr), recommendation("") { }

public:
  void addNode(); // Adds a node to the tree
  string classify(DecisionTreeNode *node, Movie *movie); // Recursively traverses tree to make a recommendation
};

#endif // DECISION_TREE_NODE_H