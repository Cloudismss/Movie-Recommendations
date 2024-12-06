#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include <string>

#include "DecisionTreeNode.h"

using std::string;

class DecisionTree
{
private:
  DecisionTreeNode *rootPtr = nullptr;

  void deleteTree(DecisionTreeNode* tmpnode);

public:
  // Accessors
  void printTree() const;
  void printTreeHelper(DecisionTreeNode *node, int level) const;
  DecisionTreeNode* getRoot() const { return rootPtr; }
  
  //Constructor
  DecisionTree();

  //Destructor
  ~DecisionTree();

  // Mutators
  void addNode(DecisionTreeNode* parent, string question, bool isYesBranch); // Adds a node to the tree
  void buildTree(); //to build manually
  string classify(DecisionTreeNode *node, const Movie *movie) const; // Recursively traverses tree to make a recommendation
};

#endif // DECISION_TREE_H