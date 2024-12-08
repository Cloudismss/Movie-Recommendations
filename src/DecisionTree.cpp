#include "DecisionTree.h"

#include <iostream>

using std::cout;

const string qACTION = "Is the genre Action?";
const string qDIRECTOR = "Is the director famous?";
const string qRATING = "Is the rating PG-13 or lower?";
const string qLONG = "Is the duration long?";
const string rYES = "Recommended";
const string rNO = "Not Recommended";

void DecisionTree::deleteTree(DecisionTreeNode* node)
{
  if(node)
  {
    deleteTree(node->yes);
    deleteTree(node->no);
    delete node;
  }
}

void DecisionTree::buildTree()
{
  rootPtr = new DecisionTreeNode(qACTION);

  rootPtr->yes = new DecisionTreeNode(qRATING);
    rootPtr->yes->yes = new DecisionTreeNode(rYES);
    rootPtr->yes->yes->recommendation = rYES;
    rootPtr->yes->no = new DecisionTreeNode(qDIRECTOR);
      rootPtr->yes->no->yes = new DecisionTreeNode(qLONG);
        rootPtr->yes->no->yes->yes = new DecisionTreeNode(rYES);
        rootPtr->yes->no->yes->yes->recommendation = rYES;
        rootPtr->yes->no->yes->no = new DecisionTreeNode(rNO);
        rootPtr->yes->no->yes->no->recommendation = rNO;
      rootPtr->yes->no->no = new DecisionTreeNode(rNO);
      rootPtr->yes->no->no->recommendation = rNO;

  rootPtr->no = new DecisionTreeNode(qDIRECTOR);
    rootPtr->no->yes = new DecisionTreeNode(qLONG);
      rootPtr->no->yes->yes = new DecisionTreeNode(rYES);
      rootPtr->no->yes->yes->recommendation = rYES;
      rootPtr->no->yes->no = new DecisionTreeNode(rNO);
      rootPtr->no->yes->no->recommendation = rNO;
    rootPtr->no->no = new DecisionTreeNode(rNO);
    rootPtr->no->no->recommendation = rNO;
}

string DecisionTree::classify(DecisionTreeNode *node, const Movie *movie) const
{
    if (!node->yes && !node->no)
        return node->recommendation; // Leaf node reached

    // Question 1
    if (node->question == qACTION)
        return (movie->getGenre() == "Action") ? classify(node->yes, movie) : classify(node->no, movie);
    
    // Question 2
    if (node->question == qRATING)
        return (movie->getRating() != "R") ? classify(node->yes, movie) : classify(node->no, movie);

    // Question 3
    if (node->question == qDIRECTOR)
        return (movie->getFamousDirector()) ? classify(node->yes, movie) : classify(node->no, movie);
    
    // Question 4
    if (node->question == qLONG)
        return (movie->getLongDuration()) ? classify(node->yes, movie) : classify(node->no, movie);

    // Default
    return rNO;
}

void DecisionTree::printTree() const
{
  if (!rootPtr)
  {
    cout << "No movies provided!\n";
    return;
  }

  printTreeHelper(rootPtr, 0);  
}

void DecisionTree::printTreeHelper(DecisionTreeNode *node, int level) const
{
  if (node)
  {
    for (int i = 0; i < level; i++)
    {
      cout << " ";
    }
    if(!node->yes && !node->no)
      cout << "Leaf: " << node->recommendation << std::endl;
    else
      cout << "Question: " << node->question << std::endl;

    printTreeHelper(node->yes, level+1);
    printTreeHelper(node->no, level+1);
  }
}