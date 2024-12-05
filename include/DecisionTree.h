#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include <string>

#include "DecisionTreeNode.h"

using std::string;

class DecisionTree
{
private:
  DecisionTreeNode *rootPtr = nullptr;

public:
  // Accessors
  void printTree() const;
  void printTreeHelper(DecisionTreeNode *node, int level) const;

  //Constructor
  DecisionTree();

  //Destructor
  ~DecisionTree();

  // Mutators
  void addNode(DecisionTreeNode* parent, string question, bool isYesBranch); // Adds a node to the tree
  void buildTree(); //to build manually
  string classify(DecisionTreeNode *node, Movie *movie); // Recursively traverses tree to make a recommendation
};

#endif // DECISION_TREE_H